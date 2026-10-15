# @author Christian Checchetti (chris22checchetti@gmail.com)
# Defines a Python wrapper for ngspice C functions and manage defect simulation

import os
import ctypes
from pathlib import Path
import threading
import signal

# ======================================================================================================================
# NGSPICE PYTHON WRAPPER (according to the ngspice manual)
# ======================================================================================================================

# SendChar receives ngspice output directed to the console
# Arguments: (char* output_line, int output_id, void* user_data)
SendCharCallback = ctypes.CFUNCTYPE(ctypes.c_int, ctypes.c_char_p, ctypes.c_int, ctypes.c_void_p)

# ControlledExit is called when ngspice encounters a fatal error
# Arguments: (int exit_status, bool immediate_unloading, bool quit_requested, int exit_code, void* user_data)
ControlledExitCallback = ctypes.CFUNCTYPE(ctypes.c_int, ctypes.c_int, ctypes.c_bool, ctypes.c_bool, ctypes.c_int, ctypes.c_void_p)

class SimulatorEngine:

    _ngspice = None                                     # Shared dynamic library
    _out_log = []                                       # Output buffer to save simulation results
    _tmp_log_file = None
    _timeout_limit : int
    _sendchar_callback = None
    _exit_callback = None

    def __init__(self, lib_path : Path | str, tmp_log_file : Path | str, timeout):
        print("\n[SimulatorEngine] Simulator initialization...")
        self._tmp_log_file = tmp_log_file
        try:
            self._ngspice = ctypes.CDLL(str(lib_path))
        except OSError as e:
            raise ImportError(f"[SimulatorEngine] Failed to load ngspice dynamic shared library: {e}")

        if timeout is None:
            raise ValueError(f"[SimulatorEngine] No timeout value has been provided")
        self._timeout_limit = timeout

        # ngspice C API configuration
        self._setup_c_api()

        # callback functions registration
        self._sendchar_callback = SendCharCallback(self._sendchar_handler)
        self._exit_callback = ControlledExitCallback(self._exit_handler)

        # Simulator initialization
        self._initialize()
        print("[SimulatorEngine] Simulator is ready")





    def _setup_c_api(self):
        # Define arguments type and return type for libngspice functions

        # ngSpice_Init is used to initialize ngspice
        # ngSpice_Init(SendChar*, SendStat*, ControlledExit*, SendData*, RespondToShared*, BGThreadRunning*, void*)
        self._ngspice.ngSpice_Init.argtypes = [
            SendCharCallback,                           # printf callback
            ctypes.c_void_p,                            # stat callback (null if unused)
            ControlledExitCallback,                     # exit callback
            ctypes.c_void_p,                            # data callback (null if unused)
            ctypes.c_void_p,                            # thread callback (null if unused)
            ctypes.c_void_p,                            # background running callback (null if unused)
            ctypes.c_void_p                             # user data pointer
        ]
        self._ngspice.ngSpice_Init.restype = ctypes.c_int

        # Send commands to the interactive interpreter
        # ngSpice_Command(char* command)
        self._ngspice.ngSpice_Command.argtypes = [ctypes.c_char_p]
        self._ngspice.ngSpice_Command.restype = ctypes.c_int

        # Netlist in-memory loading
        # ngSpice_Circ(char** circuit_lines)
        self._ngspice.ngSpice_Circ.argtypes = [ctypes.POINTER(ctypes.c_char_p)]
        self._ngspice.ngSpice_Circ.restype = ctypes.c_int


    def _initialize(self):
        # Initialize ngspice by passing callback functions
        if self._ngspice.ngSpice_Init(self._sendchar_callback, None, self._exit_callback, None, None, None, None) != 0:
            raise RuntimeError("[SimulatorEngine] Failed to initialize ngspice dynamic library")


    def _sendchar_handler(self, output_line, output_id, user_data) -> int:
        # Intercepts ngline output to stdout and saves it in the local output buffer
        if output_line:
            # Decoding C output
            line = output_line.decode("utf-8", errors="ignore")
            if line:
                self._out_log.append(line)
        return 0


    def _exit_handler(self, status, immediate, quit_req, exit_code, user_data) -> int:
        # Capture ngspice crashes and forced exits
        self._out_log.append(f"FATAL ERROR: ngspice encountered an error and exited with code {exit_code}")
        return 0


    # Function to be called after timeout
    def on_timeout(self):
        print(
            f"[SimulatorEngine::simulate] WARNING: {self._timeout_limit} seconds timeout limit exceeded. Partial simulation log file will be saved and simulation will be aborted...")
        current_log = "\n".join(self._out_log)
        current_log += f"\n[SIMULATOR ERROR] {self._timeout_limit} seconds timeout exceeded."
        try:
            print(f"[SimulatorEngine::simulate] Saving simulation partial log on {self._tmp_log_file}...")
            with open(self._tmp_log_file, "w", encoding="utf8") as file:
                file.write(current_log)
                file.flush()
                os.fsync(file.fileno()) # Prevent data loss caused by os_exit(1)
            print("[SimulatorEngine::simulate] Partial simulation log file saved\n")

        except Exception as e:
            print(f"[SimulatorEngine::simulate] ERROR: Unable to write log file: {e}\n")

        finally:
            os.kill(os.getpid(), signal.SIGTERM)


    # Orchestrate the simulation
    def simulate(self, entry_point : str | Path, dialect : str) -> str:
        print("[SimulatorEngine::simulate] Running ngspice simulation...")

        # Clear output log for a new simulation
        self._out_log.clear()

        # Entry point file preparation as NULL terminating strings array
        #raw_netlist = netlist.splitlines()
        raw_content = None
        try:
            with open(entry_point, "r") as file:
                raw_content = file.readlines()
        except FileNotFoundError:
            raise FileNotFoundError(f"[SimulatorEngine::simulate] {entry_point} not found. Operation aborted\n")

        if not raw_content:
            raise ValueError("[SimulatorEngine::simulate] Unable to extract contents from entry point file")

        # Reproducing the netlist as a list of C-like strings
        c_content = [ctypes.c_char_p(line.encode("utf-8")) for line in raw_content]
        c_content.append(None) # NULL terminator

        # Creating a ctypes array
        #ctypes_array = ctypes.c_char_p * len(c_netlist)
        #c_array = ctypes_array(*c_netlist)
        ctypes_array = ctypes.c_char_p * len(c_content)
        c_array = ctypes_array(*c_content)

        # Loading the circuit in memory
        self._ngspice.ngSpice_Circ(c_array)

        # Watchdog timer
        timer = threading.Timer(self._timeout_limit, self.on_timeout)
        timer.start()
        try:

            # Set compatibility mode according to DUT dialect
            if dialect.lower() == "eldo" or dialect.lower() == "hspice":
                self._ngspice.ngSpice_Command(b"set ngbehavior=hsa")
            elif dialect.lower() == "pspice" or dialect.lower() == "ltspice":
                self._ngspice.ngSpice_Command(b"set ngbehavior=ltpsa")
            elif dialect.lower() == "kicad":
                self._ngspice.ngSpice_Command(b"set ngbehavior=ki")

            # Transient limit
            self._ngspice.ngSpice_Command(b"option itl4=20") # Single point iteration

            # Run simulation
            self._ngspice.ngSpice_Command(b"run")

            # Cleaning memory to prevet leaks during the next simulation
            self._ngspice.ngSpice_Command(b"destroy all")
            self._ngspice.ngSpice_Command(b"remcirc")

            # Return simulation log produced by ngspice
            return "\n".join(self._out_log)

        except RuntimeError as e:
            raise RuntimeError(f"[SimulatorEngine::simulate] An unexpected error occurred during ngspice simulation: {e}\n")

        finally:
            # Stop timer in case simulation succeded
            timer.cancel()
            print("[SimulatorEngine::simulate] ngspice simulation completed\n")
