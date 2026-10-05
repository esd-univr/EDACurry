# @author: Christian Checchetti (chris22checchetti@gmail.com)
# Analyzer aim is to analyze simulation reports and establish if a defect is detected or not according to the specified tolerance limit

from typing import List, Optional
from .models import DefectModel
from .utility import DetectionStatus
from .injector import Injector
from pathlib import Path
import os
import re
import json
import time
import shutil
import textwrap

class Analyzer:
    _defect_universe_dict : dict[str, DefectModel]
    _tolerance_limit : float
    _cmp_vars : List[str]
    _simulation_results_dir : Path | str
    _golden_report_file : Path | str
    _llm_api_key : str
    _circuit_path : str | Path
    _entry_point_content : str
    _netlist_dir : str | Path

    def __init__(self, defect_universe, tolerance_limit, cmp_vars, simulation_results_dir, llm_api_key, circuit_path, entry_point_path, netlist_dir):
        if defect_universe is None:
            raise ValueError("[Analyzer] Initalization error: no defect universe has been provided")
        self._defect_universe_dict = {
            defect.get_info()["defect_record"]["id"] : defect for defect in defect_universe
        }
        if tolerance_limit is None:
            raise ValueError("[Analyzer] Initalization error: no tolerance limit has been provided")
        self._tolerance_limit = tolerance_limit
        if cmp_vars is None:
            raise ValueError("[Analyzer] Initalization error: no variables has been provided for comparison between defect-free netlist and defected ones")
        self._cmp_vars = cmp_vars
        if simulation_results_dir is None:
            raise ValueError("[Analyzer] Initalization error: no simulation results directory has been provided")
        self._simulation_results_dir = simulation_results_dir
        self._golden_report_file = simulation_results_dir / "golden_report.json"
        if llm_api_key is None:
            raise ValueError("[Analyzer] Initalization error: no LLM API key has been provided")
        self._llm_api_key = llm_api_key
        if circuit_path is None:
            raise ValueError("[Analyzer] Initalization error: no circuit path has been provided")
        self._circuit_path = circuit_path
        if entry_point_path is None:
            raise ValueError("[Analyzer] Initalization error: no entry point path has been provided")
        with open(entry_point_path, "r") as f:
            self._entry_point_content = f.read()
        if self._entry_point_content is None:
            raise ValueError("[Analyzer] Initalization error: Unable to extract entry point file data")
        if netlist_dir is None:
            raise ValueError("[Analyzer] Initalization error: Missing netlist_dir directory")
        self._netlist_dir = netlist_dir

        # Initialize ai agent (Note: planned for replacement/removal with local reasoning)
        self._ai_agent = genai.Client(api_key = str(self._llm_api_key))


    # Helper to extract scalar values matching a variable name from ngspice stdout/stderr output
    def _extract_metric_value(self, log_content: str, var_name: str) -> Optional[float]:
        # Matches: var_name followed by '=' or spaces, then an optional sign (+/-), mantissa, and optional exponent (e.g. 1.40288e+00)
        pattern = rf"{re.escape(var_name)}\s*(?:=|\s)\s*([+-]?\d+(?:\.\d+)?(?:[eE][+-]?\d+)?)"
        match = re.search(pattern, log_content)
        if match:
            return float(match.group(1))
        return None


    def analyze(self):
        print("[Analyzer::analyze] Analyzing JSON files...")
        simulation_files = []
        for simulation in os.listdir(self._simulation_results_dir):
            if simulation.endswith(".json") and simulation != "golden_report.json":
                simulation_files.append(simulation)

        cmp_dict = {}
        for var in self._cmp_vars:
            cmp_dict[var] = {
                "value" : None
            }

        gs_file = None
        try:
            gs_file = open(self._golden_report_file, "r")
        except Exception as e:
            raise Exception(f"[Analyzer::analyze] Unable to access golden report file: {e}")
        if gs_file is None:
            raise Exception("[Analyzer::analyze] Unable to access golden report file")

        # Find cmp_vars value in golden report file and determine acceptance tolerances
        gs_file_content = gs_file.read()
        gs_file.close()

        for var in self._cmp_vars:
            extracted_val = self._extract_metric_value(gs_file_content, var)
            if extracted_val is not None:
                cmp_dict[var]["value"] = extracted_val

                # Calculate symmetric absolute delta using abs() to guarantee lower_limit <= upper_limit on negative quantities
                # Fallback to an absolute epsilon if the nominal value is exactly zero to prevent range collapse [0, 0]
                delta = abs(extracted_val) * (self._tolerance_limit / 100.0)
                if delta == 0.0:
                    delta = 1e-12

                cmp_dict[var]["lower_limit"] = extracted_val - delta
                cmp_dict[var]["upper_limit"] = extracted_val + delta
            else:
                print(f"[Analyzer::analyze] Warning: metric '{var}' was not found in nominal golden simulation output")

        # Check cmp_vars in defected reports and verify if a defect is detected
        for simulation_file in simulation_files:
            file_path = self._simulation_results_dir / simulation_file
            with open(file_path, "r") as f:
                content = json.load(f)
                text_res = content.get("simulation_result", "")
                target_defect = content["target"]

                if content.get("timeout_limit_exceeded", False):
                    # If simulation has been halted after timeout limit exceeded, detection status for defect is set to unknown
                    self._defect_universe_dict[target_defect].get_record().set_detection_status(DetectionStatus.UNKNOWN)
                    self._llm_triage(target_defect, gs_file_content, text_res)
                else:
                    # Multi-variable evaluation per IEEE Std 2427:
                    # A defect is flagged as DETECTED if ANY comparison variable shifts outside acceptance bounds.
                    is_detected = False
                    evaluated_any_metric = False

                    for var in self._cmp_vars:
                        if cmp_dict[var]["value"] is None:
                            continue

                        f_value = self._extract_metric_value(text_res, var)
                        if f_value is not None:
                            evaluated_any_metric = True
                            if f_value < cmp_dict[var]["lower_limit"] or f_value > cmp_dict[var]["upper_limit"]:
                                is_detected = True
                                break

                    if is_detected:
                        self._defect_universe_dict[target_defect].get_record().set_detection_status(DetectionStatus.DETECTED)
                    else:
                        # If all monitored outputs stay within tolerance (or no valid output was measured), status is set to UNDETECTED
                        self._defect_universe_dict[target_defect].get_record().set_detection_status(DetectionStatus.UNDETECTED)
                        # Perform triage on undetectable defect runs
                        self._llm_triage(target_defect, gs_file_content, text_res)

        print("[Analyzer::analyze] Analysis concluded")


    # Explains defect's undetectability reasons via LLM using Google AI Studio API
    def _llm_triage(self, target, golden_simulation, defect_simulation):

        defect = self._defect_universe_dict[target]

        defect_id = defect.get_info()["defect_record"]["id"]
        print(f"[Analyzer::llm_triage] Defect {defect_id} has not been detected. Starting llm triage to diagnose a possible cause. This may take a while...")

        testbench_netlist_path = None
        net_files = os.listdir(self._netlist_dir)
        for file in net_files:
            if target in file:
                testbench_netlist_path = self._netlist_dir / file
                break
        if testbench_netlist_path is None:
            raise FileNotFoundError(f"[Analyzer::llm_triage] Unable to find netlist for defect {defect_id}")

        testbench_netlist = None
        with open(testbench_netlist_path, "r") as f:
            testbench_netlist = f.read()
        if testbench_netlist is None:
            raise Exception(f"[Analyzer::llm_triage] Unable to extract netlist file content for defect {defect_id}")

        system_content = """You are an expert in analog IC design, SPICE simulation engines (ngspice), and the IEEE Std 2427-2025 defect modeling standard.
        Your role is to diagnose why an injected circuit defect was not detected by a testbench or why the simulation failed.

        STRICT INSTRUCTIONS:
        1. Output Format:
           - Output EXCLUSIVELY a single valid JSON object.
           - Do NOT wrap in markdown code blocks (no ```json or ```).
           - Do NOT output any introductory text, explanation, or conversational closing.
           - Text Encoding: Use raw plain ASCII text only. NEVER use LaTeX math mode, subscripts, superscripts, backslashes, or Unicode formatting for variable/node names (e.g., always write "v_bg_val" or "xi79.net011", never $v_{bg\_val}$).

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

        user_content = f"""Diagnose the following injected defect run.

        --- CIRCUIT TOPOLOGY & TESTBENCH ---
        Simulator entry point:
        {self._entry_point_content}

        Testbench netlist:
        {testbench_netlist}

        --- DEFECT METADATA ---
        {defect.get_info()}

        --- GOLDEN SIMULATION LOG (Nominal Run) ---
        {golden_simulation}

        --- DEFECTIVE SIMULATION LOG (Fault Injection Run) ---
        {defect_simulation}

        --- DIAGNOSTIC WORKFLOW ---
        1. Trace the affected device's terminal voltages during the .MEAS measurement window (check gate, drain, source, and control signals like disable/enable).
        2. Determine if the instance is actively conducting or cut off / disabled.
        3. Select the IEEE Std 2427-2025 category accordingly.

        --- JSON SCHEMA ---
        {{
            "defect_id": "{defect_id}",
            "diagnosis_type": "unknown_triage" | "undetected_analysis",
            "circuit_state_analysis": "<Brief deduction: verify terminal voltages/currents during the .MEAS window and confirm if instance is conducting or cut off/inactive>",
            "category": "simulator_issue" | "computer_issue" | "test_issue" | "structurally_undetectable" | "potentially_undetectable" | "within_tolerance",
            "technical_reason": "<Concise physical breakdown explaining why simulation halted or why output metric remained within tolerance>",
            "suggested_remediation": "<Actionable circuit or testbench remediation adhering to system prompt rules>"
        }}"""

        # Native ChatML template for Qwen models
        triage_prompt = f"""<|im_start|>system
        {system_content}<|im_end|>
        <|im_start|>user
        {user_content}<|im_end|>
        <|im_start|>assistant
        """

        print(triage_prompt)


        # TODO: Introduce an llm manager module to download and prepare llama.cpp engine and Qwen 2.5-Instruct 7B 4-K-M model

