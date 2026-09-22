# @author: Christian Checchetti (chris22checchetti@gmail.com)
# Analyzer aim is to analyze simulation reports and establish if a defect is detected or not according to the specified tolerance limit

from typing import List
from .models import DefectModel
from .utility import DetectionStatus
from pathlib import Path
import os
import json

class Analyzer:
    _defect_universe_dict : dict[str, DefectModel]
    _tolerance_limit : float
    _cmp_vars : List[str]
    _simulation_results_dir : Path | str
    _golden_report_file : Path | str

    def __init__(self, defect_universe, tolerance_limit, cmp_vars, simulation_results_dir):
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
                            else:
                                # If value in simulation report is between tolerance limits, defect is set to detected
                                self._defect_universe_dict[content["target"]].get_record().set_detection_status(DetectionStatus.DETECTED)

        print("[Analyzer::analyze] Analysis concluded")