# @author: Christian Checchetti (chris22checchetti@gmail.com)
# This module is responsible to drive the whole campaign. It analyses the system to find the number of CPU cores and \
# create a pool of process corresponding to that specific count.
# Every process instantiates a simulator engine and it takes a defect from the universe, performs the injection and run \
# the simulation, parallelizing the whole work

from .simulator_engine import SimulatorEngine
from .injector import Injector
from .models import DefectModel
import os
import shutil
import sys
import signal
import atexit
import threading
import multiprocessing as mp
from pathlib import Path
from typing import List
edacurry_exec_path = Path(__file__).resolve().parent.parent.parent.parent/"build"
sys.path.append(str(edacurry_exec_path))
import edacurry

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


# Top-level worker function to avoid pickling/spawn issues with instance methods
def _execute_simulation(slot_id: int, log_queue: mp.Queue, defect : DefectModel, ngspice_path: Path | str, circuit_path : str | Path, netlist_output_dir : str | Path, raw_circuit_filename : Path | str, entry_point_filename : str | Path, tmp_log_dir : Path | str, timeout : float, dialect : str) -> List:

    # Direct all prints in this worker execution to the UI log queue for the assigned core slot
    stream = WorkerStdoutStream(slot_id, log_queue)
    sys.stdout = stream
    sys.stderr = stream

    # Clear previous output from this UI slot before starting a new run
    log_queue.put((slot_id, "__CLEAR__"))

    # Set working directory for the worker process
    working_path = Path(entry_point_filename).parent.resolve()
    os.chdir(working_path)

    defect_id = defect.get_info()["defect_record"]["id"]
    tmp_log_file = f"{tmp_log_dir}/{defect_id}_log.txt"

    print(f"[CampaignDirector::execute_simulation] Starting defect simulation @{defect_id}...\n")

    injector = Injector(circuit_path, netlist_output_dir)
    simulator_engine = SimulatorEngine(ngspice_path, tmp_log_file, timeout)

    ngspice_netlist, warnings = injector.inject_defect(defect)
    if not ngspice_netlist:
        raise Exception("[CampaignDirector::execute_simulation] Unable to generate defected ngspice compatible netlist")

    if warnings:
        print("[CampaignDirector::execute_simulation] Warnings from EDACurry ngspice backend:\n")
        for warning in warnings:
            print(warning)
        print("\n")

    # Save the defected netlist alongside the original one to perform injection
    path_name = circuit_path
    defected_netlist = path_name.replace(raw_circuit_filename, f"@{defect_id}_{raw_circuit_filename}")
    try:
        with open (defected_netlist, "w") as file:
            print(f"[CampaignDirector::execute_simulation] Writing {defected_netlist}...")
            file.write(ngspice_netlist)
            print(f"[CampaignDirector::execute_simulation] Defected netlist has been successfully saved\n")
    except Exception as e:
        raise Exception(f"[CampaignDirector::execute_simulation] Unable to write defected ngspice compatible netlist: {e}")

    # Change entry point file by generating a new one (temp file) and including the defected file generated below
    entry_point_content = None
    try:
        with open(entry_point_filename, "r") as file:
            entry_point_content = file.readlines()
    except Exception as e:
        raise Exception(f"[CampaignDirector::execute_simulation] Unable to read {entry_point_filename}: {e}")
    if not entry_point_content:
        raise Exception(f"[CampaignDirector::execute_simulation] Unable to access entry point file content")

    index = 0
    while index < len(entry_point_content):
        line = "".join(entry_point_content[index].split())
        if f'.include"{raw_circuit_filename}"' in line or f'.inc"{raw_circuit_filename}"' in line:
            line = f'.include "{defected_netlist}"'
            entry_point_content[index] = line
            break
        index += 1

    defected_entry_point_filename = entry_point_filename
    raw_ep_filename = entry_point_filename.split("/")[-1].split(".")[0]
    defected_entry_point_filename = defected_entry_point_filename.replace(raw_ep_filename, f"@{defect_id}_{raw_ep_filename}")
    try:
        with open (defected_entry_point_filename, "w") as file:
            file.writelines(entry_point_content)
    except Exception as e:
        raise Exception(f"[CampaignDirector::execute_simulation] Unable write the new entry point for the simulation: {e}")

    try:
        simulation_result = simulator_engine.simulate(defected_entry_point_filename, dialect)
        print(f"\n[CampaignDirector::execute_simulation] Simulation @{defect_id} completed successfully\n")
        return simulation_result
    except Exception as e:
        print(f"\n\nDebug: exception in simulation: {e}\n\n")
        return f"[SIMULATION ERROR] Unable to execute simulation @{defect_id}: {e}"



class SimulationDashboard(App):
    # Textual dashboard for per-process terminal output separation
    CSS = """
    Grid {
        grid-size: 2;
        grid-gutter: 1;
        padding: 1;
    }
    RichLog {
        border: round green;
        height: 100%;
    }
    """

    def __init__(self, cpu_count: int, log_queue: mp.Queue):
        super().__init__()
        self._cpu_count = cpu_count
        self._log_queue = log_queue
        self._logs = {}

    def compose(self) -> ComposeResult:
        yield Header(show_clock=True)
        with Grid():
            for i in range(self._cpu_count):
                log_widget = RichLog(highlight=True, markup=False, wrap=True)
                log_widget.border_title = f"Worker Core #{i}"
                self._logs[i] = log_widget
                yield log_widget
        yield Footer()

    def on_mount(self) -> None:
        # Check for new messages from workers every 50ms
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


class SystemScanner:
    _cpu_count : int = None                 # CPU cores

    def __init__(self):
        self._cpu_count = os.cpu_count()
        if self._cpu_count is None:
            raise ValueError("[SystemScanner] Initialization error: unable to determine the number of CPU cores")

    def get_cpu_count(self):
        return self._cpu_count


class CampaignDirector:
    _defect_universe : List[DefectModel]
    _ngspice_path : Path | str
    _circuit_path : str | Path
    _netlist_dir : Path | str
    _raw_circuit_filename : Path | str
    _entry_point_filename : Path | str
    _tmp_log_dir : Path | str
    _cpu_count : int
    _pool : mp.Pool
    _manager : mp.Manager
    _dashboard_app : SimulationDashboard

    def __init__(self, defect_universe : List[DefectModel], ngspice_path : Path | str, circuit_path : str | Path, netlist_dir : str | Path, raw_circuit_filename : Path | str, entry_point_filename : Path | str, tmp_log_dir : Path | str):
        print("[CampaignDirector] Initializing campaign director...")
        if defect_universe is None:
            raise ValueError("[CampaignDirector] Initialization error: no defect universe has been provided")
        self._defect_universe = defect_universe
        if ngspice_path is None:
            raise ValueError("[CampaignDirector] Initialization error: no path for ngspice library has been provided")
        self._ngspice_path = ngspice_path
        if circuit_path is None:
            raise ValueError("[CampaignDirector] Initialization error: no netlist has been provided")
        self._circuit_path = circuit_path
        if netlist_dir is None:
            raise ValueError("[CampaignDirector] Initialization error: no ngspice netlist output directory has been provided")
        self._netlist_dir = netlist_dir
        if raw_circuit_filename is None:
            raise ValueError("[CampaignDirector] Initialization error: no netlist filename has been provided")
        self._raw_circuit_filename = raw_circuit_filename
        if entry_point_filename is None:
            raise ValueError("[CampaignDirector] Initialization error: no entry point filename has been provided")
        self._entry_point_filename = entry_point_filename
        if tmp_log_dir is None:
            raise ValueError("[CampaignDirector] Initialization error: no log directory for divergent simulations has been provided")
        self._tmp_log_dir = tmp_log_dir
        self._cpu_count = SystemScanner().get_cpu_count()
        if self._cpu_count is None:
            raise ValueError("[CampaignDirector] Initialization error: unable to initialize process pool")
        self._pool = None
        self._manager = None
        self._dashboard_app = None

    def _clean_tmp_files(self, remove_logs_dir):
        # Cleaning tmp files generated during the analysis
        # Every tmp file starts with @
        print("[CampaignDirector::clean_tmp_files] Cleaning up temporary files...")
        dut_dir = Path(self._tmp_log_dir).parent
        for content in os.scandir(dut_dir):
            if content.is_file() and content.name.startswith("@"):
                try:
                    os.remove(content)
                    print(f"[CampaignDirector::clean_tmp_files] {content.name} successfully removed")
                except Exception as e:
                    print(f"[CampaignDirector::clean_tmp_files] Unable to remove {content.name}: {e}\n")
        print("[CampaignDirector::clean_tmp_files] Temporary files have been removed\n")
        # Cleaning up tmp_logs dir
        try:
            if remove_logs_dir and self._tmp_log_dir.exists():
                print("[CampaignDirector::clean_tmp_files] Cleaning up temporary logs directory...")
                shutil.rmtree(self._tmp_log_dir)
                print(f"[CampaignDirector::clean_tmp_files] {self._tmp_log_dir} successfully removed")
        except Exception as e:
            print(f"[CampaignDirector::clean_tmp_files] Unable to remove {self._tmp_log_dir}: {e}\n")

    def _cleanup(self):
        # Shutdown executor and terminate all running child processes immediately
        if self._pool is not None:
            self._pool.terminate()
            self._pool.join()
        if self._manager is not None:
            self._manager.shutdown()
        # Clean tmp files
        self._clean_tmp_files(True)

    def _signal_handler(self, signum, frame):
        # Handle termination signals and force shutdown
        print(f"\n[CampaignDirector] Interrupted by signal {signum}. Terminating processes...")
        self._cleanup()
        sys.exit(1)

    def _execute_campaign_tasks(self, timeout: float, dialect : str, report_holder: list, error_holder: list, log_queue: mp.Queue):
        # Worker thread routine to handle simulation pool execution while Textual handles UI
        try:
            total_defects = len(self._defect_universe)
            completed_count = 0

            # Distribute tasks associating each defect deterministically to a slot (0 to cpu_count - 1)
            async_results = [
                (
                    defect,
                    self._pool.apply_async(
                        _execute_simulation,
                        (
                            idx % self._cpu_count,
                            log_queue,
                            defect,
                            self._ngspice_path,
                            self._circuit_path,
                            self._netlist_dir,
                            self._raw_circuit_filename,
                            self._entry_point_filename,
                            self._tmp_log_dir,
                            timeout,
                            dialect
                        ),
                    ),
                )
                for idx, defect in enumerate(self._defect_universe)
            ]

            for defect, result in async_results:
                defect_id = defect.get_info()["defect_record"]["id"]
                try:
                    # Wait for single simulation completion
                    res = {
                        "target" : defect_id,
                        "timeout_limit_exceeded" : False,
                        "simulation_result" : result.get(timeout)
                    }
                    report_holder.append(res)
                except Exception:
                    tmp_log = Path(self._tmp_log_dir) / f"{defect_id}_log.txt"
                    if tmp_log.exists():
                        try:
                            with open(tmp_log, "r", encoding="utf-8", errors="ignore") as f:
                                sim_content = f.read()
                                res = {
                                    "target" : defect_id,
                                    "timeout_limit_exceeded" : True,
                                    "simulation_result" : sim_content
                                }
                                report_holder.append(res)
                        except BaseException as e:
                            error_holder.append(Exception(f"[CampaignDirector::run_campaign] An error occurred @{defect_id}: {e}"))
                            break
                    else:
                        error_holder.append(Exception(f"[CampaignDirector::run_campaign] FATAL ERROR: tmp log for defect {defect_id} not found. Campaign aborted"))
                        break
                finally:
                    completed_count += 1
                    if self._dashboard_app:
                        self._dashboard_app.title = f"Campaign Status: {completed_count}/{total_defects} processed"

        finally:
            # Terminate Textual UI on completion
            if self._dashboard_app:
                self._dashboard_app.call_from_thread(self._dashboard_app.exit)

    def run_campaign(self, timeout : int, dialect : str):
        print("[CampaignDirector::run_campaign] Running campaign...")
        report = []
        errors = []

        # Register cleanup and signal handlers in the main execution flow
        atexit.register(self._cleanup)
        try:
            signal.signal(signal.SIGINT, self._signal_handler)
            signal.signal(signal.SIGTERM, self._signal_handler)
        except ValueError:
            # Avoid crashing if invoked in a sub-thread
            pass

        ctx = mp.get_context("spawn")
        self._manager = ctx.Manager()
        log_queue = self._manager.Queue()

        self._pool = ctx.Pool(self._cpu_count)

        self._dashboard_app = SimulationDashboard(
            cpu_count=self._cpu_count,
            log_queue=log_queue
        )
        self._dashboard_app.title = f"Campaign Status: 0/{len(self._defect_universe)} processed"

        # Run pool execution in background thread to let Textual own the main event loop
        campaign_thread = threading.Thread(
            target=self._execute_campaign_tasks,
            args=(timeout, dialect, report, errors, log_queue),
            daemon=True
        )
        campaign_thread.start()

        # Start Textual UI (blocking on main thread)
        self._dashboard_app.run()

        campaign_thread.join()

        self._pool.terminate()
        self._pool.join()
        self._manager.shutdown()

        if errors:
            print(f"[CampaignDirector::run_campaign] An error occurred during campaign: {errors[0]}")
            self._clean_tmp_files(True)
            raise errors[0]

        print("[CampaignDirector::run_campaign] Campaign completed\n")

        self._clean_tmp_files(True)

        return report


    # Execute a golden simulation to extract data from the defect-free netlist
    def run_golden_simulation(self, circuit : edacurry.Circuit, timeout : int, dialect : str):

        print("[CampaignDirector::run_golden_simulation] Running golden simulation...")

        working_path = Path(self._entry_point_filename).parent.resolve()
        os.chdir(working_path)

        ngspice_netlist, warnings = edacurry.write_ngspice(circuit)
        if not ngspice_netlist:
            raise Exception("[CampaignDirector::run_golden_simulation] Unable to generate defected ngspice compatible netlist")

        if warnings:
            print("[CampaignDirector::run_golden_simulation] Warnings from EDACurry ngspice backend:\n")
            for warning in warnings:
                print(warning)
            print("\n")

        circuit_path = self._circuit_path
        circuit_name = circuit_path.split("/")[-1].split(".")[0]
        circuit_path = circuit_path.replace(circuit_name, f"@golden_simulation_{circuit_name}")
        try:
            with open(circuit_path, "w") as f:
                f.write(ngspice_netlist)
        except Exception as e:
            raise Exception(f"[CampaignDirector::run_golden_simulation] Unable to write the entry point for the golden simulation: {e}\n")

        entry_point_content = None
        try:
            with open(self._entry_point_filename, "r") as file:
                entry_point_content = file.readlines()
        except Exception as e:
            raise Exception(f"[CampaignDirector::run_golden_simulation] Unable to read {self._entry_point_filename}: {e}")
        if not entry_point_content:
            raise Exception(f"[CampaignDirector::run_golden_simulation] Unable to access entry point file content")

        index = 0
        while index < len(entry_point_content):
            line = "".join(entry_point_content[index].split())
            if f'.include"{self._raw_circuit_filename}"' in line or f'.inc"{self._raw_circuit_filename}"' in line:
                line = f'.include "{circuit_path}"'
                entry_point_content[index] = line
                break
            index += 1

        entry_point = self._entry_point_filename
        raw_ep_filename = entry_point.split("/")[-1].split(".")[0]
        entry_point = entry_point.replace(raw_ep_filename, f"@golden_simulation_{raw_ep_filename}")
        try:
            with open(entry_point, "w") as file:
                file.writelines(entry_point_content)
        except Exception as e:
            raise Exception(f"[CampaignDirector::run_golden_simulation] Unable write the new entry point for the golden simulation: {e}")

        tmp_log_file = Path(self._tmp_log_dir) / "golden_simulation_log.txt"
        simulator = SimulatorEngine(self._ngspice_path, tmp_log_file, timeout)

        res = None

        try:
            gs_report = simulator.simulate(entry_point, dialect)
            res = {
                "target" : "golden simulation",
                "timeout_limit_exceeded": False,
                "simulation_result" : gs_report
            }

        except BaseException as e:
            print(f"[CampaignDirector::run_golden_simulation] Simulation halted: {e}")
            golden_log_file = Path(self._tmp_log_dir) / "golden_simulation_log.txt"
            if golden_log_file.exists():
                golden_log_content = None
                with open(golden_log_file, "r") as file:
                    golden_log_content = file.read()
                if golden_log_content is None:
                    raise Exception(f"[CampaignDirector::run_golden_simulation] FATAL ERROR: {golden_log_file} is empty\n")
                    res = {
                        "target": "golden simulation",
                        "timeout_limit_exceeded": True,
                        "simulation_result": golden_log_content
                    }
            else:
                raise Exception(f"[CampaignDirector::run_golden_simulation] FATAL ERROR: Unable to find golden simulation log file: {golden_log_file}\n")

        self._clean_tmp_files(False)
        return res
