# @author: Christian Checchetti (chris22checchetti@gmail.com)
# Analyzer aim is to analyze simulation reports and establish if a defect is detected or not according to the specified tolerance limit

from typing import List
from .models import DefectModel
from .utility import DetectionStatus
from .injector import Injector
from pathlib import Path
import os
import json
import time
from google import genai
from google.genai import types, errors

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

        # Initialize ai agent
        self._ai_agent = genai.Client(api_key = str(self._llm_api_key))


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

        # Find cmp_vars value in golden report file
        gs_file_content = gs_file.read()
        for var in self._cmp_vars:
            if var in gs_file_content:
                index = gs_file_content.index(var)
                tmp_value = ""
                while index < len(gs_file_content):
                    if not gs_file_content[index].isdigit():
                        index += 1
                    else:
                        break
                while gs_file_content[index].isdigit() or gs_file_content[index] in ["+", "-", "e", ".", ","]:
                    tmp_value += gs_file_content[index]
                    index += 1
                cmp_dict[var]["value"] = float(tmp_value)

                # Set lower and upper limits
                cmp_dict[var]["lower_limit"] = cmp_dict[var]["value"] - (cmp_dict[var]["value"] * (self._tolerance_limit / 100))
                cmp_dict[var]["upper_limit"] = cmp_dict[var]["value"] + (cmp_dict[var]["value"] * (self._tolerance_limit / 100))

        # Check cmp_vars in defected reports and verify if a defect is detected
        for simulation_file in simulation_files:
            file_path = self._simulation_results_dir / simulation_file
            with open(file_path, "r") as f:
                content = json.load(f)
                text_res = content["simulation_result"]
                if content["timeout_limit_exceeded"]:
                    # If simulation has been halted after timeout limit exceeded, detection status for defect is set to unknown
                    self._defect_universe_dict[content["target"]].get_record().set_detection_status(DetectionStatus.UNKNOWN)
                    # TODO: Integrate LLM intervention
                    self._llm_triage(content["target"], gs_file_content, text_res)
                else:
                    for var in self._cmp_vars:
                        if var in text_res:
                            index = text_res.index(var)
                            tmp_value = ""
                            while index < len(text_res):
                                if not text_res[index].isdigit():
                                    index += 1
                                else:
                                    break
                            while text_res[index].isdigit() or text_res[index] in ["+", "-", "e", ".", ","]:
                                tmp_value += text_res[index]
                                index += 1
                            f_value = float(tmp_value)
                            if f_value >= cmp_dict[var]["lower_limit"] and f_value <= cmp_dict[var]["upper_limit"]:
                                # If value in simulation report is between tolerance limits, defect is set to undetected
                                self._defect_universe_dict[content["target"]].get_record().set_detection_status(DetectionStatus.UNDETECTED)
                                # TODO: Call llm
                                self._llm_triage(content["target"], gs_file_content, text_res)
                            else:
                                # If value in simulation report is between tolerance limits, defect is set to detected
                                self._defect_universe_dict[content["target"]].get_record().set_detection_status(DetectionStatus.DETECTED)

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

        triage_prompt = f"""
        You are an expert in analog circuit design, SPICE simulation engines, and the IEEE Std 2427 fault/defect modeling standard.
        Your objective is to diagnose why an injected defect was NOT detected by the testbench, or why the simulation failed to yield a valid measurement.
        You know simulations have been performed via the open-source simulator ngspice.

        --- CIRCUIT TOPOLOGY & TESTBENCH ---
        Simulator's entry point file content:
        {self._entry_point_content}
            
        Testbench file content:
        {testbench_netlist}

        --- DEFECT METADATA ---
        {defect.get_info()}

        --- GOLDEN SIMULATION LOG (Nominal Run) ---
        {golden_simulation}

        --- DEFECTIVE SIMULATION LOG (Fault Injection Run) ---
        {defect_simulation}

        --- DIAGNOSTIC INSTRUCTIONS ---
        1. Execution Failures (Simulation Timeout, Convergence Failure, or Tool Crash):
            Classify the root cause per IEEE Std 2427 Annex C guidelines:
            - "simulator_issue": Numerical convergence issues (e.g., non-convergence at DC operating point, timestep too small, Gmin/ITL1/ITL4 limits exceeded).
            - "computer_issue": CPU wall-clock timeout, out-of-memory (OOM), or execution killed by OS/resource limits.
            - "test_issue": SPICE measurement failure (e.g., .MEAS evaluation error, missing triggers, uninitialized vectors).

        2. Completed Runs with Undetected Defect (Measurements Within Acceptance Tolerances):
            - Provide a rigorous topological and physical explanation showing why the defect does not perturb the output metric beyond the defined thresholds.
            - Classify into one of the following IEEE 2427 undetectable / test escape categories:
                * "structurally_undetectable": Mechanically redundant branches, equipotential nodes, open dummy devices, inactive ESD/clamp structures in the current operational mode.
                * "potentially_undetectable": Masked by strong negative feedback, common-mode rejection, or high-gain stage saturation.
                * "within_tolerance": Defect alters operating point slightly, but the delta remains inside nominal design specification / test acceptance bands.

        --- OUTPUT FORMAT ---
        Respond EXCLUSIVELY with a valid JSON object. Do not include markdown code block backticks (```json), greetings, or extraneous commentary.

        Structure:
        {{
            "defect_id": "{defect_id}",
            "diagnosis_type": "unknown_triage" | "undetected_analysis",
            "category": "simulator_issue" | "computer_issue" | "test_issue" | "structurally_undetectable" | "potentially_undetectable" | "within_tolerance",
            "technical_reason": "<Concise, behavior, breakdown circuit deviation, explanation node numerical of or precise solver technically the voltage/current>",
            "suggested_remediation": "<Actionable .options, SPICE additional alternative e.g., modified next observation or pin step: stimulus test tighter tolerance, vector,>"
        }}
        """

        """"
        config = types.GenerateContentConfig(
            response_mime_type="application/json",
            temperature=0.1,
            tools=None
        )
        """

        # Handle model unavailability
        max_retries = 5
        base_delay = 3
        llm_response = None

        agent = getattr(self, "_ai_agent", None) or genai.Client(api_key=str(self._llm_api_key))

        for attempt in range(max_retries):
            try:
                response = agent.interactions.create(
                    model="gemini-3.8-flash",
                    input=triage_prompt,
                    #config=config
                )
                llm_response = response.text
                break
            except (errors.ServerError, errors.APIError) as e:
                # Intercept 503 (Unavailable) or 429 (Rate limit)
                if ("503" in str(e)) and attempt < max_retries - 1:
                    sleep_time = base_delay * (2 ** attempt)
                    print(f"[Analyzer::llm_triage] Attempt {attempt + 1}/{max_retries} failed: API temporarily unavailable. Retrying in {sleep_time}s...")
                    time.sleep(sleep_time)
                elif ("429" in str(e)) and attempt < max_retries - 1:
                    print(f"[Analyzer::llm_triage] Rate limit exceeded: {e}\n")
                    break
                else:
                    print(f"[Analyzer::llm_triage] An error occurred while asking the llm model: {e}\n")
                    break

        if llm_response:
            print("[Analyzer::llm_triage] Diagnosis formulated\n")
            print(llm_response, "\n\n")
            # TODO: process the response in a proper way
