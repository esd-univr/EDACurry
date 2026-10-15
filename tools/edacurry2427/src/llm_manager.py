# @author: Christian Checchetti (chris22checchetti@gmail.com)
# This module is responsible for Qwen 2.5 7B-Instruct 4-K-M and llama.cpp downloading and configuration

import atexit
import json
import os
import platform
import re
import shutil
import signal
import subprocess
import tarfile
import time
import zipfile
from enum import Enum
from pathlib import Path
from typing import Optional

import psutil
import requests
from huggingface_hub import hf_hub_download, snapshot_download


class ComputeSystemTechnology(str, Enum):
    APPLE_SILICON = "AppleSilicon"
    CUDA = "CUDA"
    ROCM = "ROCm"
    GENERIC = "GenericGPU"


class DownloadManager:

    def __init__(self, github_token: str, gpu_technology: ComputeSystemTechnology, os_name: str, engine_dir: str | Path, model_dir: str | Path):
        if github_token is None:
            raise ValueError("[DownloadManager] Unable to initialize the Download Manager: missing Github Token")
        headers = {
            "Authorization": f"Bearer {github_token}",
            "Accept": "application/vnd.github.v3+json",
            "X-GitHub-Api-Version": "2022-11-28"
        }

        engine_dir = Path(engine_dir)
        model_dir = Path(model_dir)

        # Download or compile engine if not present yet
        has_engine = any(element.is_file() and element.name.startswith("llama") for element in engine_dir.iterdir())
        if not has_engine:
            self._download_engine(gpu_technology, os_name, engine_dir, headers)

        # Download model if not present yet
        if not any(model_dir.glob("Qwen*")) and not any(model_dir.glob("qwen*")):
            self._download_model(model_dir)

    # Download or compile llama.cpp
    def _download_engine(self, gpu_technology: ComputeSystemTechnology, os_name: str, engine_dir: str | Path, headers: dict):
        print(f"[DownloadManager::download_engine] Preparing llama.cpp inference engine...")
        engine_path = Path(engine_dir)

        # macOS: Pre-compiled binaries are not always published as GitHub release assets.
        # Compile locally from source to ensure native Apple Silicon Metal support.
        if os_name == "Darwin" or gpu_technology == ComputeSystemTechnology.APPLE_SILICON:
            cli_bin = engine_path / "llama-cli"
            server_bin = engine_path / "llama-server"

            if (cli_bin.exists() and os.access(cli_bin, os.X_OK)) or (server_bin.exists() and os.access(server_bin, os.X_OK)):
                print(f"[DownloadManager::download_engine] Executable already present in {engine_path}")
                return

            print("[DownloadManager::download_engine] Building llama.cpp locally for Apple Silicon (Metal enabled)...")
            src_dir = engine_path / "llama_src"
            build_dir = src_dir / "build"
            try:
                if not src_dir.exists():
                    subprocess.run(
                        ["git", "clone", "--depth", "1", "https://github.com/ggml-org/llama.cpp.git", str(src_dir)],
                        check=True
                    )

                subprocess.run(
                    [
                        "cmake",
                        "-B", str(build_dir),
                        "-DCMAKE_BUILD_TYPE=Release",

                        # Enable GGML Metal backend for Apple Silicon's GPU
                        "-DGGML_METAL=ON",

                        # Incorporate compiled Metal shades (.metallib) directly into binary file preventing CPU fallback
                        "-DGGML_METAL_EMBED_LIBRARY=ON",

                        # Optimize specific Apple Silicon architecture
                        "-DGGML_NATIVE=ON",

                        # Enable accelerated instructions on ARM dot product and FP16 on Metal
                        "-DGGML_ACCELERATE=ON"
                    ],
                    cwd=str(src_dir),
                    check=True
                )

                subprocess.run(
                    ["cmake", "--build", str(build_dir), "--config", "Release", "-j"],
                    cwd=str(src_dir),
                    check=True
                )

                # Move compiled executables directly to engine_dir
                for bin_name in ["llama-cli", "llama-server"]:
                    src_bin = build_dir / "bin" / bin_name
                    dest_bin = engine_path / bin_name
                    if src_bin.exists():
                        shutil.copy2(src_bin, dest_bin)
                        os.chmod(dest_bin, 0o755)

                print(f"[DownloadManager::download_engine] Compilation completed successfully. Binaries available at: {engine_path}\n")
                return
            except Exception as e:
                raise Exception(f"[DownloadManager::download_engine] Failed to build llama.cpp from source: {e}\n")

        # Windows and Linux: Download pre-compiled binary archives from GitHub
        url, asset_name = self._get_latest_llama_release(gpu_technology, os_name, headers)
        dest_archive = engine_path / asset_name

        try:
            response = requests.get(url, stream=True, headers=headers)
            response.raise_for_status()

            with open(dest_archive, "wb") as archive_file:
                for chunk in response.iter_content(chunk_size=8192):
                    archive_file.write(chunk)

            # Extract downloaded archive into engine_dir
            if asset_name.endswith(".zip"):
                with zipfile.ZipFile(dest_archive, "r") as zip_ref:
                    zip_ref.extractall(engine_path)
            elif asset_name.endswith((".tar.gz", ".tgz")):
                with tarfile.open(dest_archive, "r:gz") as tar_ref:
                    tar_ref.extractall(engine_path)

            dest_archive.unlink(missing_ok=True)
            print("[DownloadManager::download_engine] Extraction completed\n")
        except Exception as e:
            raise Exception(f"[DownloadManager::download_engine] An error occurred while downloading/extracting the engine: {e}\n")

    # Get the latest version of llama.cpp
    @staticmethod
    def _get_latest_llama_release(gpu_technology: ComputeSystemTechnology, os_name: str, headers: dict):
        # Fetch the latest release metadata from GitHub API
        api_url = "https://api.github.com/repos/ggml-org/llama.cpp/releases/latest?per_page=100"

        # Defining download pattern
        pattern = None
        if gpu_technology == ComputeSystemTechnology.APPLE_SILICON:
            pattern = r"(macos|osx)-arm64"
        elif gpu_technology == ComputeSystemTechnology.ROCM:
            if os_name == "win32":
                pattern = r"win-vulkan-x64"
            elif os_name == "Darwin":
                pattern = r"(macos|osx)-x64"
            elif os_name == "linux":
                pattern = r"ubuntu-.*rocm-x64"
        elif gpu_technology == ComputeSystemTechnology.CUDA:
            if os_name == "win32":
                pattern = r"win-cuda-.*-x64"
            elif os_name == "linux":
                pattern = r"ubuntu-.*-cuda-x64"

        if pattern is None:
            raise Exception("[DownloadManager::get_latest_llama_release] Unable to determine the llama.cpp version to be downloaded.\n")

        try:
            response = requests.get(api_url, headers=headers)
            response.raise_for_status()
            data = response.json()

            tag = data.get("tag_name")
            assets = data.get("assets", [])

            # Search for the asset matching the defined pattern
            cuda_assets = []
            asset_name = None
            download_url = None

            for asset in assets:
                asset_name = asset.get("name", "")
                if gpu_technology == ComputeSystemTechnology.CUDA:
                    if re.search(pattern, asset_name) and asset_name.startswith("llama"):
                        cuda_assets.append(asset)
                else:
                    if re.search(pattern, asset_name, re.IGNORECASE) and asset_name.startswith("llama"):
                        download_url = asset.get("browser_download_url")
                        break

            if cuda_assets:
                # Sort the assets to get the most recent version
                version_number = []
                for cuda_asset in cuda_assets:
                    cuda_asset_name = cuda_asset.get("name")
                    index = 0
                    version = ""
                    starting_index = None
                    while index < len(cuda_asset_name):
                        if starting_index is None and cuda_asset_name[index].isdigit() and cuda_asset_name[index - 1] == "-":
                            starting_index = index
                        if starting_index is not None and index >= starting_index:
                            if cuda_asset_name[index] != "-":
                                version += cuda_asset_name[index]
                            else:
                                break
                        index += 1
                    version_number.append(float(version))

                latest_version = max(version_number)
                best_asset = None
                cuda_asset_name = None
                for cuda_asset in cuda_assets:
                    cuda_asset_name = cuda_asset.get("name")
                    if str(latest_version) in cuda_asset_name:
                        if cuda_asset.get("name") == cuda_asset_name:
                            best_asset = cuda_asset
                print(f"[DownloadManager::get_latest_llama_release] Found release {tag}: {cuda_asset_name}")
                return best_asset["browser_download_url"], cuda_asset_name
            else:
                if download_url is not None:
                    print(f"[DownloadManager::get_latest_llama_release] Found release {tag}: {asset_name}")
                    return download_url, asset_name

            raise FileNotFoundError(f"[DownloadManager::get_latest_llama_release] Unable to find any asset matching pattern {pattern}")
        except Exception as e:
            raise Exception(f"[DownloadManager::get_latest_llama_release] An error occurred while getting the latest release: {e}\n")

    # Download Qwen
    def _download_model(self, qwen_dir: str | Path):
        print("[DownloadManager::download_model] Downloading Qwen 2.5 7B - Instruct model...")
        try:
            hf_hub_download(
                repo_id="bartowski/Qwen2.5-7B-Instruct-GGUF",
                filename="Qwen2.5-7B-Instruct-Q4_K_M.gguf",
                local_dir=qwen_dir
            )
            print("[DownloadManager::download_model] Done")
        except Exception as e:
            raise Exception(f"[DownloadManager::download_model] An error occurred while downloading Qwen model: {e}\n")

        # Search for cache files and remove them
        print("[DownloadManager::download_model] Removing cache files...")
        content = os.listdir(qwen_dir)
        for c in content:
            if "cache" in str(c).lower():
                shutil.rmtree(qwen_dir / c)
        print("[DownloadManager::download_model] Done\n")


class LlmManager:
    # System
    _os: str
    _processor_arch: str
    _processor_cores: int
    _gpu_technology: str
    _total_vram: float

    # llama.cpp
    _server_config: dict
    _engine_dir: Path
    _qwen_dir: Path
    _engine_process: Optional[subprocess.Popen]
    _parallel_execution : int

    def __init__(self, github_token):
        print("[LLM Manager] Initializing LLM Manager...")
        self._engine_process = None

        # Register exit handlers to ensure cleanup on abrupt exit, exceptions or termination signals
        atexit.register(self.stop_llama_server)
        try:
            signal.signal(signal.SIGINT, self._handle_exit_signal)
            signal.signal(signal.SIGTERM, self._handle_exit_signal)
        except (ValueError, AttributeError):
            pass

        # Creating llm data dirs
        llm_data_dir = Path(__file__).parent.parent.resolve() / "llm_data"
        self._engine_dir = llm_data_dir / "engine"
        self._qwen_dir = llm_data_dir / "model"

        try:
            if not os.path.exists(llm_data_dir):
                print(f"[LLM Manager] Creating {llm_data_dir} directory...")
                os.makedirs(llm_data_dir, exist_ok=True)
                print("[LLM Manager] Done")

            if not os.path.exists(self._engine_dir):
                print(f"[LLM Manager] Creating {self._engine_dir} directory...")
                os.makedirs(self._engine_dir, exist_ok=True)
                print("[LLM Manager] Done")

            if not os.path.exists(self._qwen_dir):
                print(f"[LLM Manager] Creating {self._qwen_dir} directory...")
                os.makedirs(self._qwen_dir, exist_ok=True)
                print("[LLM Manager] Done")
        except Exception as e:
            raise ValueError(f"[LLM Manager] Initialization error: {e}\n")

        self._scan_hw()
        download_manager = DownloadManager(github_token, self._gpu_technology, self._os, self._engine_dir, self._qwen_dir)

        # Configuring llama-server
        print("[LLM Manager] Generating llama-server configuration...")
        qwen_path = str((self._qwen_dir / "Qwen2.5-7B-Instruct-Q4_K_M.gguf").resolve())
        """
        self._parallel_execution = 1
        if self._total_vram > 8.0:
            self._parallel_execution = round((self._total_vram - 4.6) / 0.95)
        if self._parallel_execution > 4:  # Maximum value to avoid exceeding 128K context window size
            self._parallel_execution = 4
        """
        self._parallel_execution = 2
        context_w = self._parallel_execution * 32768

        self._server_config = {
            "-m": qwen_path,                      # Model path
            "-ngl": 99,                           # Loads every model layer on GPU
            "-fa" : 1,                            # Flash Attention to accelerate long prompt's elaboration
            #"-ctk": "q8_0",                       # KV Cache quantization
            "-np": self._parallel_execution,      # Parallel analyses
            "-c": context_w,                      # Context window size (max 128K)
            "-b" : 2048,                          # Logical batch size
            "-ub" : 1024,                         # Physical/micro batch size
            "--threads" : self._processor_cores,  # Physical CPU Cores
            "--host": "127.0.0.1",                # REST server IP
            "--port": 11434                       # REST server port
        }
        print("[LLM Manager] Done")

    def _handle_exit_signal(self, signum, frame):
        """Clean up child process upon receiving OS termination signals."""
        self.stop_llama_server()
        raise SystemExit(1)

    def __del__(self):
        self.stop_llama_server()

    # Start server
    def start_llama_server(self, timeout_sec: int = 45):
        server_binary = (Path(self._engine_dir) / "llama-server").resolve()
        model_file = Path(self._server_config["-m"]).resolve()

        if not server_binary.exists():
            raise FileNotFoundError(f"[LLM Manager::start_llama_server] llama-server executable not found at {server_binary}")
        if not model_file.exists():
            raise FileNotFoundError(f"[LLM Manager::start_llama_server] Model file not found at {model_file}")

        cmd = [
            str(server_binary),
            "-m", str(model_file),
            "-ngl", str(self._server_config["-ngl"]),
            "-fa", str(self._server_config["-fa"]),
            #"-ctk", str(self._server_config["-ctk"]),
            "-np", str(self._server_config["-np"]),
            "-c", str(self._server_config["-c"]),
            "-b", str(self._server_config["-b"]),
            "-ub", str(self._server_config["-ub"]),
            "--threads", str(self._server_config["--threads"]),
            "--host", str(self._server_config["--host"]),
            "--port", str(self._server_config["--port"]),
        ]

        try:
            print("[LLM Manager::start_llama_server] Starting inference engine...")
            self._engine_process = subprocess.Popen(
                cmd,
                stdout=subprocess.DEVNULL,
                stderr=subprocess.DEVNULL,
                text=True
            )
        except Exception as e:
            raise Exception(f"[LLM Manager::start_llama_server] Unable to start inference engine: {e}")

        # Polling to ensure the server starts up properly and verify its health status
        health_url = f"http://{self._server_config['--host']}:{self._server_config['--port']}/health"
        start_time = time.time()

        while time.time() - start_time < timeout_sec:
            # Check if subprocess exited prematurely
            return_code = self._engine_process.poll()
            if return_code is not None:
                _, stderr_err = self._engine_process.communicate()
                self._engine_process = None
                raise RuntimeError(
                    f"[LLM Manager::start_llama_server] llama-server crashed immediately with exit code {return_code}.\n"
                    f"Error log:\n{stderr_err}"
                )

            try:
                response = requests.get(health_url, timeout=1)
                if response.status_code == 200:
                    print(f"[LLM Manager::start_llama_server] Inference engine ready (PID: {self._engine_process.pid})\n")
                    return
            except requests.exceptions.RequestException:
                pass  # Server is still initializing memory and layers

            time.sleep(1)

        # Timeout reached: ensure process is shut down before raising
        self.stop_llama_server()
        raise TimeoutError(f"[LLM Manager::start_llama_server] Timed out waiting for llama-server to become ready after {timeout_sec}s.")

    # Stop server
    def stop_llama_server(self):
        if hasattr(self, "_engine_process") and self._engine_process is not None:
            if self._engine_process.poll() is None:
                print("[LLM Manager::stop_llama_server] Shutting down inference engine...")
                self._engine_process.terminate()
                try:
                    self._engine_process.wait(timeout=5)
                except subprocess.TimeoutExpired:
                    print("[LLM Manager::stop_llama_server] Process unresponsive, sending SIGKILL...")
                    self._engine_process.kill()
                    self._engine_process.wait()
            self._engine_process = None

    # Scan hardware to determine VRAM size
    def _scan_hw(self):
        print("[LLM Manager::scan_hw] Collecting system information...")

        # Detecting OS
        self._os = platform.system()
        if self._os is None:
            raise ValueError("[LLM Manager::scan_hw] Unrecognized Operating System")
        if self._os != "Darwin" and self._os.lower() != "win32" and self._os.lower() != "linux":
            raise ValueError(f"[LLM Manager::scan_hw] Unsupported Operating System detected: {self._os}")

        # Detecting processor architecture
        self._processor_arch = platform.machine()
        if self._processor_arch is None:
            raise ValueError("[LLM Manager::scan_hw] Unable to get processor information")

        # Detecting the number of processor's cores
        self._processor_cores = psutil.cpu_count(logical=False)
        if self._processor_cores is None:
            raise ValueError("[LLM Manager::scan_hw] Unable to get the number of processor's cores")

        # Detecting RAM
        ram = psutil.virtual_memory()
        total_ram = ram.total / (1024 ** 3)
        if total_ram is None:
            raise ValueError("[LLM Manager::scan_hw] Unable to get memory information")

        # Detecting GPU technology
        # Set to GENERIC by default
        self._gpu_technology = ComputeSystemTechnology.GENERIC

        if self._os == "Darwin" and self._processor_arch == "arm64":
            self._gpu_technology = ComputeSystemTechnology.APPLE_SILICON
        else:
            # Check the presence of an NVIDIA GPU using torch
            import torch
            is_cuda = False
            try:
                cuda_gpu = torch.cuda.get_device_name()
                if cuda_gpu is not None and len(cuda_gpu) > 0:
                    is_cuda = True
            except Exception:
                pass

            if is_cuda:
                self._gpu_technology = ComputeSystemTechnology.CUDA

            # Check the presence of an AMD GPU
            if not is_cuda:
                is_rocm = False
                # Windows
                if self._os == "win32":
                    try:
                        import wmi
                        system_info = wmi.WMI()
                        gpu = system_info.Win32_VideoController()[0]
                        caption = gpu.Caption
                        if "Advanced" in caption or "AMD" in caption:
                            is_rocm = True
                    except Exception:
                        pass
                else:
                    # Linux
                    try:
                        import amdsmi
                        amdsmi.amdsmi_init()
                        gpu = amdsmi.amdsmi_get_processor_handles()[0]
                        gpu_type = amdsmi.amdsmi_get_processor_type(gpu)
                        if gpu_type == 1:
                            is_rocm = True
                    except Exception:
                        pass

                if is_rocm:
                    self._gpu_technology = ComputeSystemTechnology.ROCM

        # Detecting VRAM information
        self._total_vram = 0.0

        if self._os == "Darwin":
            if self._gpu_technology is ComputeSystemTechnology.APPLE_SILICON:
                self._total_vram = total_ram * 0.75
                # macOS automatically allocates unified memory to the needed process
            else:
                cmd = ["system_profiler", "SPDisplaysDataType", "-json"]
                output = subprocess.check_output(cmd).decode("utf-8")
                data = json.loads(output)
                gpus = data.get("SPDisplaysDataType", [])
                gpu = gpus[0]
                self._total_vram = gpu.get("VRAM (Total)")
        elif self._os.lower() == "win32":
            try:
                import wmi
                system_info = wmi.WMI()
                gpu = system_info.Win32_VideoController()[0]
                self._total_vram = gpu.AdapterRam / (1024 ** 3)
            except Exception as e:
                print(f"[LLM Manager::scan_hw] An error occurred while getting GPU VRAM information: {e}")
        else:
            # Linux is considered
            if self._gpu_technology is ComputeSystemTechnology.CUDA:
                import torch
                device = torch.device("cuda:0")
                total_cuda_memory = torch.cuda.get_device_properties(device).total_memory
                self._total_vram = total_cuda_memory / (1024 ** 3)
            elif self._gpu_technology is ComputeSystemTechnology.ROCM:
                try:
                    import amdsmi
                    amdsmi.amdsmi_init()
                    # Get the first GPU
                    gpu = amdsmi.amdsmi_get_processor_handles()[0]
                    # Get total and used memory in MB
                    total_memory = amdsmi.amdsmi_get_gpu_vram_usage(gpu)
                    self._total_vram = total_memory / 1024
                except Exception as e:
                    print(f"[LLM Manager::scan_hw] An error occurred while getting GPU VRAM information: {e}")

        if self._total_vram == 0.0:
            raise ValueError("[LLM Manager::scan_hw] Unable to get GPU VRAM information")

        print("[LLM Manager::scan_hw] Information collected\n")


    # Get parallel execution number
    def get_parallel_workers(self):
        return self._parallel_execution
