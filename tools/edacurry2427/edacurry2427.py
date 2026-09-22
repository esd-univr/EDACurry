# @author: Christian Checchetti (chris22checchetti@gmail.com)

import json
import shutil
from pathlib import Path
import sys
import os

# Get EDACurry
edacurry_build_dir = Path(__file__).parent.parent.parent.resolve()/"build"
sys.path.append(str(edacurry_build_dir))
import edacurry

# argparse
import argparse

# Import modules
from src import Optimizer, DefectEngine, DependencyManager, CampaignDirector, Analyzer


# Cleaning temporary dirs
def clean():
    print("[EDACURRY2427] Cleaning up temporary directories...")
    try:
        if os.path.exists(tmp_log_dir):
            shutil.rmtree(tmp_log_dir)
            print("[EDACURRY2427] tmp_logs directory removed")
        if os.path.exists(simulation_results):
            shutil.rmtree(simulation_results)
            print("[EDACURRY2427] simulation results directory removed")
        print("\n")
    except Exception as e:
        print(f"[EDACURRY2427] Unable to remove temporary directory: {e}\n")



if __name__ == '__main__':
    parser = argparse.ArgumentParser(description="IEEE 2427 compliant tool to perform fault injection")
    parser.add_argument("-dut", "--dut", required=True, help="Name of the design under test on which to perform the analysis")
    parser.add_argument("-i", "--input", required=True, help="Entry point file for simulation")
    parser.add_argument("-m", "--manifest", required=True, help="Json manifest file used to configure the system")
    parser.add_argument("-t", "--timeout", required=True, help="Timeout limit in seconds for each simulation")
    args = parser.parse_args()

    # Check dependencies : ngspice
    print("[EDACURRY2427] Checking ngspice dependency...")
    dependency_manager = DependencyManager()
    ngspice_path = dependency_manager.get_ngspice_path()
    print("[EDACURRY2427] Found ngspice\n")


    print("[EDACURRY2427] Initializing...")
    dut = args.dut
    entry_point = args.input
    manifest_data = None
    try:
        with Path(args.manifest).open('r', encoding='utf-8') as f:
            manifest_data = json.load(f)
    except FileNotFoundError as e:
        raise FileNotFoundError(f"Unable to load manifest file: {e}")
    if manifest_data is None:
        raise ValueError("Unable to extract manifest data")
    print("[EDACURRY2427] Manifest has been correctly processed\n")

    # Check netlist dialect
    dialect = None
    try:
        dialect = manifest_data["dialect"]
    except KeyError:
        raise ValueError("[EDACURRY2427] Unable to extract dialect details from manifest")
    if dialect is None:
        raise ValueError("[EDACURRY2427] Unable to extract dialect details from manifest")

    # Check for Spectre dialect
    if dialect.lower() == "spectre":
        print("[EDACURRY2427] Spectre dialect is not supported\n")
        exit(1)

    # Retrieving test tolerance limits
    print("[EDACURRY2427] Retrieving tolerance limits to establish defect relevation...")
    tolerance_lim = None
    try:
        tolerance_lim = manifest_data["tolerance_limit"] # Expressed as a percentual
    except KeyError:
        raise ValueError("[EDACURRY2427] Unable to extract tolerance limit value from manifest")
    if tolerance_lim is None:
        raise ValueError("[EDACURRY2427] Unable to extract tolerance limit value from manifest")
    print(f"[EDACURRY2427] Tolerance limit set to ±{tolerance_lim}%\n")

    # Retrieving variables defined by test that have to be compared to verify defect detection
    cmp_vars = None
    try:
        cmp_vars = manifest_data["cmp_vars"]
    except KeyError:
        raise ValueError("[EDACURRY2427] Unable to extract test variables from manifest")
    if cmp_vars is None:
        raise ValueError("[EDACURRY2427] Unable to extract test variables from manifest")
    print("[EDACURRY2427] Variables in test to be compared:")
    for var in cmp_vars:
        print(f"> {var}")
    print("\n")

    # Retrieving timeout
    timeout = None
    try:
        timeout = int(args.timeout)
    except Exception as e:
        raise Exception(f"[EDACURRY2427] Unable to parse timeout value: {e}")
    if timeout is None:
        raise ValueError("[EDACURRY2427] Unable to parse timeout value")
    print(f"[EDACURRY2427] Simulation timeout set to {timeout} seconds\n")


    # Acess DUT directory inside the worskpace dir
    print("[EDACURRY2427] Retrieving DUT data...")
    workspace_dir = Path(__file__).parent.resolve()/"workspace"
    avilable_duts = os.listdir(workspace_dir)
    dut_dir = None
    for _dut in avilable_duts:
        if _dut == dut:
            dut_dir = Path(_dut)
            break
    if not dut_dir:
        raise ValueError("Unable to find the specified DUT in the workspace")
    content_dir = workspace_dir/dut_dir

    # Add temp dir for log files produced during the analysis
    print("[EDACURRY2427] Creating temporary directory for logs produced by divergent simulations...")
    tmp_log_dir = content_dir/"tmp_logs"
    os.makedirs(tmp_log_dir, exist_ok=True)
    print("[EDACURRY2427] Logs directory created")

    content = os.listdir(content_dir)
    entry_point_filename = None
    raw_circuit_filename = f"tb_{dut}"
    found_circuit_filename = False
    found_entry_point_filename = False
    for element in content:
        if not entry_point_filename and element == entry_point:
            entry_point_filename = element
            found_entry_point_filename = True
        if element.split(".")[0] == raw_circuit_filename:
            raw_circuit_filename = element
            found_circuit_filename = True

    if not found_circuit_filename:
        raise ValueError("Unable to find the specified entry point file for circuit analysis")
    if not found_entry_point_filename:
        raise ValueError("Unable to find the specified entry point file for circuit analysis")
    print("[EDACURRY2427] Data retrieved\n")

    # Add full path to circuit filename
    circuit_filename = str(content_dir/raw_circuit_filename)
    entry_point_filename = str(content_dir/entry_point_filename)

    # Load circuit as AST
    print("[EDACURRY2427] Loading circuit...")
    circuit = None
    try:
        circuit = edacurry.parse_eldo(circuit_filename)
    except ValueError as e:
        raise ValueError(f"Unable to parse circuit file: {e}")
    if circuit is None:
        raise ValueError("Unable to parse circuit file")
    print("[EDACURRY2427] Done\n")

    # Run optimizer to merge parallel equivalent components
    print("[EDACURRY2427] Running optimizer...")
    optimizer = Optimizer(circuit, circuit_filename, manifest_data)
    optimizer.optimize_merge()
    print("[EDACURRY2427] Done\n")

    # Defect universe generation
    print("[EDACURRY2427] Initializing defect universe...")
    defect_engine = DefectEngine(circuit, circuit_filename, manifest_data)
    print("[EDACURRY2427] Done\n")
    print("[EDACURRY2427] Retrieving defect universe details...")
    defect_universe_details = defect_engine.get_universe_details()
    print("[EDACURRY2427] Done\n")

    # Saving defect universe details to output directory
    output_dir = content_dir/"output"
    os.makedirs(output_dir, exist_ok=True)
    defect_universe_output = output_dir/"defect_universe_details.json"
    print(f"[EDACURRY2427] Writing {defect_universe_output}...")
    with open(defect_universe_output, "w") as f:
        json.dump(defect_universe_details, f, indent=4)
    print("[EDACURRY2427] Done\n")

    # Retrieving Defect universe
    print("[EDACURRY2427] Retrieving defect universe...")
    defect_universe = defect_engine.generate_defect_universe()
    print("[EDACURRY2427] Done\n\n")
    
    # Running simulation
    print("[EDACURRY2427] Creating temporary simulation results directory...")
    simulation_results = content_dir/"simulation_results"
    os.makedirs(simulation_results, exist_ok=True)
    print("[EDACURRY2427] Done\n")

    campaign_director = CampaignDirector(defect_universe, ngspice_path, circuit_filename, raw_circuit_filename, entry_point_filename, tmp_log_dir)
    print("[EDACURRY2427] Running golden simulation on defect-free netlist...")
    golden_report_file = simulation_results/"golden_report.json"
    if not "golden_report.json" in os.listdir(simulation_results):
        golden_report = campaign_director.run_golden_simulation(circuit, timeout, dialect)
        with open(golden_report_file, "w") as f:
            json.dump(golden_report, f, indent=4)
        print("[EDACURRY2427] Golden report retrieved and saved in JSON format\n")
    else:
        print("[EDACURRY2427] Golden report already generated\n")

    print("[EDACURRY2427] Retrieving defect simulation report...")
    simulated_elements = 0
    sim_files = os.listdir(simulation_results)
    for sim_file in sim_files:
        if sim_file.endswith(".json"):
            simulated_elements += 1
    if simulated_elements == 1:
        campaign_report = campaign_director.run_campaign(timeout, dialect)
        for cr in campaign_report:
            report_name = f"{simulation_results}/{cr["target"]}.json"
            with open(report_name, "w") as f:
                json.dump(cr, f, indent=4)
        print("[EDACURRY2427] Report acquired. Simulation results have been saved in JSON format\n")
    else:
        print("[EDACURRY2427] Report already generated\n")

    # Check data integrity
    print("[EDACURRY2427] Checking data integrity...")
    simulated_elements = 0
    sim_files = os.listdir(simulation_results)
    for sim_file in sim_files:
        if sim_file.endswith(".json"):
            simulated_elements += 1
    estimated_elements = len(defect_universe) + 1
    if simulated_elements == estimated_elements:
        print(f"[EDACURRY2427] {simulated_elements}/{estimated_elements} found. OK to proceed\n")
    else:
        print(f"[EDACURRY2427] ERROR: {simulated_elements}/{estimated_elements} found. Something went wrong during defect simulations. Operation aborted\n")
        clean()
        exit(1)

    # Running analyzer
    print("[EDACURRY2427] Loading analyzer...")
    analyzer = Analyzer(defect_universe, tolerance_lim, cmp_vars, simulation_results)
    analyzer.analyze()
    print("[EDACURRY2427] Done\n")

    # Saving detection information as a JSON file inside the output directory (defect coverage details)
    defect_coverage_output = output_dir/"defect_coverage_details.json"
    # Saving defect record using defect id as key
    defect_coverage_details = {
        defect.get_info()["defect_record"]["id"] : defect.get_info()["defect_record"] for defect in defect_universe
    }
    print(f"[EDACURRY2427] Writing {defect_coverage_output}...")
    with open(defect_coverage_output, "w") as f:
        json.dump(defect_coverage_details, f, indent=4)
    print("[EDACURRY2427] Done\n")

    choice = input("[EDACURRY2427] Do you like to remove all temporary files? [Y/N] ")
    stop = 0
    while not stop:
        if choice.lower() == "y" or choice.lower() == "yes":
            clean()
            stop = 1
        elif choice.lower() == "n" or choice.lower() == "no":
            stop = 1
        else:
            print(f"[EDACURRY2427] {choice} is not a valid option")
            choice = input("[EDACURRY2427] Do you like to remove all temporary files? [Y/N] ")
