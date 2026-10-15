# @author: Christian Checchetti (chris22checchetti@gmail.com)
# Analyzer aim is to analyze simulation reports and establish if a defect is detected or not according to the specified tolerance limit

from typing import List, Optional, Dict, Any
from .models import DefectModel
from .utility import DetectionStatus
from .injector import Injector
from .llm_manager import LlmManager
from pathlib import Path
import os
import re
import json
import time
import shutil
import textwrap
import signal
import atexit
import threading
import multiprocessing as mp
import requests
import sys
from textual.app import App, ComposeResult
from textual.containers import Grid
from textual.widgets import Header, Footer, RichLog


class WorkerStdoutStream:
    # Custom stream replacing sys.stdout to redirect worker print() outputs to the assigned Textual slot
    def __init__(self, slot_id: int, log_queue: mp.Queue):
        self._slot_id = slot_id
        self._log_queue = log_queue
        self._buffer = ""

    def write(self, text: str):
        if not text:
            return
        self._buffer += text
        while "\n" in self._buffer:
            line, self._buffer = self._buffer.split("\n", 1)
            self._log_queue.put((self._slot_id, line.rstrip("\r")))

    def flush(self):
        if self._buffer:
            self._log_queue.put((self._slot_id, self._buffer.rstrip("\r")))
            self._buffer = ""


class TriageDashboard(App):
    # Textual dashboard mirroring CampaignDirector style for parallel LLM triage
    CSS = """
    Grid {
        grid-size: 2;
        grid-gutter: 1;
        padding: 1;
    }
    RichLog {
        border: round cyan;
        height: 100%;
    }
    """

    def __init__(self, workers_count: int, log_queue: mp.Queue):
        super().__init__()
        self._workers_count = workers_count
        self._log_queue = log_queue
        self._logs = {}

    def compose(self) -> ComposeResult:
        yield Header(show_clock=True)
        with Grid():
            for i in range(self._workers_count):
                log_widget = RichLog(highlight=True, markup=False, wrap=True)
                log_widget.border_title = f"LLM Worker #{i}"
                self._logs[i] = log_widget
                yield log_widget
        yield Footer()

    def on_mount(self) -> None:
        self.set_interval(0.05, self._drain_queue)

    def _drain_queue(self) -> None:
        while not self._log_queue.empty():
            try:
                slot_id, message = self._log_queue.get_nowait()
                if slot_id in self._logs:
                    if message == "__CLEAR__":
                        self._logs[slot_id].clear()
                    else:
                        self._logs[slot_id].write(message)
            except Exception:
                break


def _execute_triage_worker(
        slot_id: int,
        log_queue: mp.Queue,
        target: str,
        defect_info: dict,
        golden_simulation: str,
        defect_simulation: str,
        circuit_netlist_content: str,
        entry_point_content: str,
        triage_output_dir: str | Path,
        llama_server_url: str
    ) -> None:
    # Redirect worker stdout and stderr to the dedicated Textual UI panel
    stream = WorkerStdoutStream(slot_id, log_queue)
    sys.stdout = stream
    sys.stderr = stream

    #log_queue.put((slot_id, "__CLEAR__"))
    defect_id = defect_info["defect_record"]["id"]
    print(f"[Analyzer::llm_triage] Starting diagnostic workflow for defect @{defect_id}...\n")

    try:
        # Prompt structure: System instructions specifying role, constraints and output schema
        system_content = """You are an expert in analog IC design, SPICE simulation engines (ngspice), and the IEEE Std 2427-2025 defect modeling standard.
    Your role is to diagnose why an injected circuit defect was not detected by a testbench or why the simulation failed.

    STRICT INSTRUCTIONS:
    1. Output Format:
        - Output EXCLUSIVELY a single valid JSON object.
        - Do NOT wrap in markdown code blocks (no ```json or ```).
        - Do NOT output any introductory text, explanation, or conversational closing.
        - Text Encoding: Use raw plain ASCII text only. NEVER use LaTeX math mode, subscripts, superscripts, backslashes, or Unicode formatting for variable/node names (e.g., always write "v_bg_val" or "xi79.net011", never $v_{bg\\_val}$).

    2. IEEE Std 2427-2025 Classification Rules:
        - "simulator_issue": ngspice numerical solver convergence failures (e.g., non-convergence at DC op, singular matrix, timestep too small).
        - "computer_issue": Platform/infrastructure failures (e.g., wall-clock timeout exceeded, memory exhaustion / OOM, process SIGKILL).
        - "test_issue": SPICE measurement failure (e.g., .MEAS directive failed to find trigger/target threshold, uninitialized output vector).
        - "structurally_undetectable": Device/branch is cut off, permanently OFF, unpowered, or functionally inactive during the measurement window (e.g., power-down, sleep, reset, or clamp transistors during active functional test).
        - "potentially_undetectable": Device is actively conducting and on the functional path, but its defect effect is masked by strong negative feedback, common-mode rejection, or operational amplifier saturation.
        - "within_tolerance": Device is actively conducting and perturba branch currents, but the resulting numerical delta at the monitored output remains strictly inside nominal tolerance bounds.

    3. Remediation Constraints:
        - For completed simulations where defect is undetected, DO NOT suggest SPICE solver options tuning (e.g., gmin stepping, itl1, itl4, reltol, abstol, or transient timestep reduction).
        - If a defect is "structurally_undetectable" due to an inactive mode, the remediation MUST propose modifying test stimuli to exercise that state (e.g., toggling power-down/disable pins).
        - If "within_tolerance" or "potentially_undetectable", propose tighter limits, IDDQ / quiescent current monitoring, or probing internal bias nodes."""

        # Prompt user content: providing Circuit Topology, Top Entry Point, Defect Metadata, Golden Run & Defect Run
        user_content = f"""Compare and diagnose the following analog circuit defect run.

    --- SIMULATOR ENTRY POINT (TOP-LEVEL TESTBENCH) ---
    {entry_point_content}

    --- CIRCUIT NETLIST TOPOLOGY ---
    {circuit_netlist_content}

    --- DEFECT METADATA (IEEE STD 2427) ---
    {json.dumps(defect_info, indent=2)}

    --- NOMINAL GOLDEN SIMULATION LOG ---
    {golden_simulation}

    --- DEFECTIVE SIMULATION LOG ---
    {defect_simulation}

    --- DIAGNOSTIC WORKFLOW ---
    1. Trace the affected device's terminal voltages during the .MEAS measurement window (check gate, drain, source, and control signals like disable/enable).
    2. Determine if the instance is actively conducting or cut off / disabled.
    3. Select the IEEE Std 2427-2025 category accordingly.

    --- REQUIRED JSON OUTPUT SCHEMA ---
    {{
        "defect_id": "{defect_id}",
        "diagnosis_type": "unknown_triage" | "undetected_analysis",
        "circuit_state_analysis": "<Brief deduction: verify terminal voltages/currents during the .MEAS window and confirm if instance is conducting or cut off/inactive>",
        "category": "simulator_issue" | "computer_issue" | "test_issue" | "structurally_undetectable" | "potentially_undetectable" | "within_tolerance",
        "technical_reason": "<Concise physical breakdown explaining why simulation halted or why output metric remained within tolerance>",
        "suggested_remediation": "<Actionable circuit or testbench remediation adhering to system prompt rules>"
    }}"""

        triage_prompt = f"""<|im_start|>system
        {system_content}<|im_end|>
        <|im_start|>user
        {user_content}<|im_end|>
        <|im_start|>assistant
        """


        print(f"[Analyzer::llm_triage] Sending prompt for defect @{defect_id} to llama-server {llama_server_url}...")

        payload = {
            "prompt": triage_prompt,
            "n_predict": 2048,
            "temperature": 0.0,
            "stream": False,
            "stop": ["<|im_end|>", "<|endoftext|>"]
        }

        res = requests.post(llama_server_url, json=payload, timeout=300)
        res.raise_for_status()

        response_raw = res.json().get("content", "")
        print(f"[Analyzer::llm_triage] Response received for defect @{defect_id}.")

        # Strip accidental Markdown code blocks if emitted
        cleaned_res = response_raw.strip()
        if cleaned_res.startswith("```json"):
            cleaned_res = cleaned_res[7:]
        elif cleaned_res.startswith("```"):
            cleaned_res = cleaned_res[3:]
        if cleaned_res.endswith("```"):
            cleaned_res = cleaned_res[:-3]
        cleaned_res = cleaned_res.strip()

        parsed_json = None
        try:
            parsed_json = json.loads(cleaned_res)
            print(f"[Analyzer::llm_triage] Successfully parsed JSON diagnosis for @{defect_id}:\n")
            triage_output = json.dumps(parsed_json, indent=4)
            print(triage_output, "\n")

            # Save triage output into triage output folder
            filename = f"{triage_output_dir}/triage@{defect_id}.json"
            print(f"[Analyzer::execute_triage_worker] Writing {filename}...")
            try:
                with open(filename, "w", encoding="utf-8") as f:
                    f.write(triage_output)
                print(f"[Analyzer::execute_triage_worker] Done\n\n\n")

            except Exception as e:
                print(f"[Analyzer::execute_triage_worker] Unable to write {filename}: {e}\n")

        except Exception as e:
            print(f"[Analyzer::llm_triage] Warning: JSON parsing failed for @{defect_id}: {e}\n")

    except Exception as e:
        print(f"[Analyzer::llm_triage] Error during triage execution for @{defect_id}: {e}\n")


class Analyzer:
    _defect_universe_dict: dict[str, DefectModel]
    _tolerance_limit: float
    _cmp_vars: List[str]
    _simulation_results_dir: Path | str
    _golden_report_file: Path | str
    _circuit_path: str | Path
    _entry_point_content: str
    _circuit_netlist_content: str
    _netlist_dir: str | Path
    _triage_output_dir: Path | str
    _llm_manager: LlmManager
    _pool: Optional[mp.Pool]
    _manager: Optional[mp.Manager]
    _dashboard_app: Optional[TriageDashboard]

    def __init__(self, defect_universe, tolerance_limit, cmp_vars, simulation_results_dir, github_token, circuit_path,
                 entry_point_path, netlist_dir, output_dir):
        if defect_universe is None:
            raise ValueError("[Analyzer] Initialization error: no defect universe has been provided")
        self._defect_universe_dict = {
            defect.get_info()["defect_record"]["id"]: defect for defect in defect_universe
        }
        if tolerance_limit is None:
            raise ValueError("[Analyzer] Initialization error: no tolerance limit has been provided")
        self._tolerance_limit = tolerance_limit
        if cmp_vars is None:
            raise ValueError("[Analyzer] Initialization error: no variables has been provided for comparison between defect-free netlist and defected ones")
        self._cmp_vars = cmp_vars
        if simulation_results_dir is None:
            raise ValueError("[Analyzer] Initialization error: no simulation results directory has been provided")
        self._simulation_results_dir = Path(simulation_results_dir)
        self._golden_report_file = self._simulation_results_dir / "golden_report.json"

        if circuit_path is None:
            raise ValueError("[Analyzer] Initialization error: no circuit path has been provided")
        self._circuit_path = Path(circuit_path)
        with open(self._circuit_path, "r", encoding="utf-8", errors="ignore") as f:
            self._circuit_netlist_content = f.read()

        if entry_point_path is None:
            raise ValueError("[Analyzer] Initialization error: no entry point path has been provided")
        with open(entry_point_path, "r", encoding="utf-8", errors="ignore") as f:
            self._entry_point_content = f.read()

        if netlist_dir is None:
            raise ValueError("[Analyzer] Initialization error: Missing netlist_dir directory")
        self._netlist_dir = Path(netlist_dir)

        if output_dir is None:
            raise ValueError("[Analyzer] Initialization error: Missing output_dir directory")
        self._triage_output_dir = Path(output_dir)/"llm_triage"
        print("[Analyzer] Creating llm triage output directory...")
        os.makedirs(self._triage_output_dir, exist_ok=True)
        print("[Analyzer] Done\n")

        # Initialize LLM manager
        self._llm_manager = LlmManager(github_token)

        self._pool = None
        self._manager = None
        self._dashboard_app = None

    def _extract_metric_value(self, log_content: str, var_name: str) -> Optional[float]:
        pattern = rf"{re.escape(var_name)}\s*(?:=|\s)\s*([+-]?\d+(?:\.\d+)?(?:[eE][+-]?\d+)?)"
        match = re.search(pattern, log_content)
        if match:
            return float(match.group(1))
        return None

    def _cleanup(self):
        if self._pool is not None:
            self._pool.terminate()
            self._pool.join()
        if self._manager is not None:
            self._manager.shutdown()

    def _signal_handler(self, signum, frame):
        print(f"\n[Analyzer] Interrupted by signal {signum}. Terminating processes...")
        self._cleanup()
        sys.exit(1)

    def _execute_triage_tasks(self, undetected_defects: list, workers_num: int, llama_server_url: str, log_queue: mp.Queue):
        try:
            total_items = len(undetected_defects)
            completed_count = 0

            async_results = [
                (
                    target,
                    self._pool.apply_async(
                        _execute_triage_worker,
                        (
                            idx % workers_num,
                            log_queue,
                            target,
                            self._defect_universe_dict[target].get_info(),
                            golden_log,
                            defect_log,
                            self._circuit_netlist_content,
                            self._entry_point_content,
                            self._triage_output_dir,
                            llama_server_url
                        ),
                    ),
                )
                for idx, (target, golden_log, defect_log) in enumerate(undetected_defects)
            ]

            for target, async_res in async_results:
                try:
                    async_res.get()
                except Exception as e:
                    log_queue.put(f"[Analyzer] Un error occurred while analyzing {target}: {e}")
                finally:
                    completed_count += 1
                    if self._dashboard_app:
                        self._dashboard_app.title = f"LLM Triage Status: {completed_count}/{total_items} processed"

        finally:
            if self._dashboard_app:
                self._dashboard_app.call_from_thread(self._dashboard_app.exit)

    def _run_parallel_triage(self, undetected_defects: list, workers_num: int, llama_server_url: str) -> None:
        print(f"[Analyzer::analyze] Starting parallel triage across {workers_num} workers...")
        triage_reports = []

        atexit.register(self._cleanup)
        try:
            signal.signal(signal.SIGINT, self._signal_handler)
            signal.signal(signal.SIGTERM, self._signal_handler)
        except ValueError:
            pass

        ctx = mp.get_context("spawn")
        self._manager = ctx.Manager()
        log_queue = self._manager.Queue()

        self._pool = ctx.Pool(workers_num)

        self._dashboard_app = TriageDashboard(
            workers_count=workers_num,
            log_queue=log_queue
        )
        self._dashboard_app.title = f"LLM Triage Status: 0/{len(undetected_defects)} processed"

        triage_thread = threading.Thread(
            target=self._execute_triage_tasks,
            args=(undetected_defects, workers_num, llama_server_url, log_queue),
            daemon=True
        )
        triage_thread.start()

        # Start Textual UI (blocking on main thread)
        self._dashboard_app.run()

        triage_thread.join()

        self._pool.terminate()
        self._pool.join()
        self._manager.shutdown()

    def analyze(self):
        print("[Analyzer::analyze] Analyzing JSON files...")

        undetected_defects = []

        simulation_files = [f for f in os.listdir(self._simulation_results_dir) if f.endswith(".json") and f != "golden_report.json"]

        cmp_dict = {var: {"value": None} for var in self._cmp_vars}

        try:
            with open(self._golden_report_file, "r") as gs_file:
                gs_file_content = gs_file.read()
        except Exception as e:
            raise Exception(f"[Analyzer::analyze] Unable to access golden report file: {e}")

        for var in self._cmp_vars:
            extracted_val = self._extract_metric_value(gs_file_content, var)
            if extracted_val is not None:
                cmp_dict[var]["value"] = extracted_val
                delta = abs(extracted_val) * (self._tolerance_limit / 100.0)
                if delta == 0.0:
                    delta = 1e-12

                cmp_dict[var]["lower_limit"] = extracted_val - delta
                cmp_dict[var]["upper_limit"] = extracted_val + delta
            else:
                print(f"[Analyzer::analyze] Warning: metric '{var}' was not found in nominal golden simulation output and has been ignored")

        for simulation_file in simulation_files:
            file_path = self._simulation_results_dir / simulation_file
            with open(file_path, "r") as f:
                content = json.load(f)
                text_res = content.get("simulation_result", "")
                target_defect = content["target"]

                if content.get("timeout_limit_exceeded", False):
                    self._defect_universe_dict[target_defect].get_record().set_detection_status(DetectionStatus.UNKNOWN)
                    undetected_defects.append((target_defect, gs_file_content, text_res))
                else:
                    is_detected = False
                    for var in self._cmp_vars:
                        if cmp_dict[var]["value"] is None:
                            continue

                        f_value = self._extract_metric_value(text_res, var)
                        if f_value is not None:
                            if f_value < cmp_dict[var]["lower_limit"] or f_value > cmp_dict[var]["upper_limit"]:
                                is_detected = True
                                break

                    if is_detected:
                        self._defect_universe_dict[target_defect].get_record().set_detection_status(DetectionStatus.DETECTED)
                    else:
                        self._defect_universe_dict[target_defect].get_record().set_detection_status(DetectionStatus.UNDETECTED)
                        undetected_defects.append((target_defect, gs_file_content, text_res))

        # Check if some undetected defect has already been processed by llm triage in a previous run and omit it
        to_be_processed = []
        processed_elements = []
        for file in os.listdir(self._triage_output_dir):
            if file.endswith(".json"):
                id = file.split("@")[1].split(".")[0]
                processed_elements.append(id)

        # Converting processed_elements list in a set for a more efficient comparison
        processed_elements_set = set(processed_elements)
        for defect in undetected_defects:
            if defect[0] not in processed_elements_set:
                to_be_processed.append(defect)

        # Start parallel LLM triage on undetected / unknown runs
        if len(to_be_processed) > 0:
            print(
                f"[Analyzer::analyze] Found {len(to_be_processed)} undetected/unknown defects. Preparing parallel triage...")
            self._llm_manager.start_llama_server()
            workers_num = self._llm_manager.get_parallel_workers()
            server_url = "http://127.0.0.1:11434/completion"

            try:
                self._run_parallel_triage(to_be_processed, workers_num, server_url)
            finally:
                self._llm_manager.stop_llama_server()

        # Adjust record info
        success_triage_index = 0
        for file in os.listdir(self._triage_output_dir):
            if file.endswith(".json"):
                # Update check index
                success_triage_index += 1

                # Update defect record info
                json_data = json.load(open(self._triage_output_dir / file))
                self._defect_universe_dict[json_data["defect_id"]].get_record().set_undetectability_reason(json_data["category"])
                self._defect_universe_dict[json_data["defect_id"]].get_record().set_technical_reason(json_data["technical_reason"])
                self._defect_universe_dict[json_data["defect_id"]].get_record().set_suggested_remediation(json_data["suggested_remediation"])

        undet_def_qt = len(undetected_defects)
        if success_triage_index != undet_def_qt:
            print(f"\n[Analyzer::analyze] Warning: LLM triage failed for {undet_def_qt - success_triage_index} undetected defects\n")

        print("[Analyzer::analyze] Analysis concluded")
