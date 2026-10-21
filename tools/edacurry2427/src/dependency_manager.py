# @author: Christian Checchetti (chris22checchetti@gmail.com)
# Verify the presence of ngspice lib and return the lib path. In case library is not found, suggest how to get it

import os
import sys
import platform
import ctypes
from ctypes.util import find_library
import subprocess
import shutil
from pathlib import Path

class DependencyManager:

    _lib_path = None

    def __init__(self):
        # Check os platform
        os_type = platform.system().lower()

        # Search library in the system
        sys_lib_name = "libngspice" if os_type != "win32" else "ngspice.dll"
        if os_type == "darwin":
            # Check homebrew presence
            if not shutil.which("brew"):
                homebrew_installation_command = '/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"'
                print(f"[DependencyManager] homebrew package manager not found. Run {homebrew_installation_command} to download it\n")
                exit(1)

            # Use homebrew package manager to check ngspice presence
            try:
                self._lib_path = subprocess.run(
                    ["brew", "--prefix", sys_lib_name],
                    capture_output = True,
                    text = True,
                    check = True,
                )
                self._lib_path = Path(self._lib_path.stdout.strip())/"lib"/"libngspice.dylib"
            except subprocess.CalledProcessError:
                pass

            if not self._lib_path:
               print(f"[DependencyManager] Missing {sys_lib_name} library. Run 'brew install {sys_lib_name}' to download it\n")
               exit(1)

        elif os_type == "win32":
            # Windows doesn't have a traditional package manager, so library must be downloaded in put into edacurry2427/library dir
            self._lib_path = Path(__file__).parent.parent.resolve() / "library"
            if len(os.listdir(self._lib_path)) == 0:
                print(f"[DependencyManager] Missing {sys_lib_name} library. Download it from 'https://sourceforge.net/projects/ngspice/files/ng-spice-rework/47/ngspice-47_64.7z/download'")
                print(f"[DependencyManager] WARNING: once the download completes, move the content of the Spice64_dll directory into {library_dir}\n")

                exit(1)

        else:
            sel._lib_path = find_library("ngspice")
            if not self._lib_path:
                print(f"[DependencyManager] Missing {sys_lib_name} library. Use the package manager to download it:\n")
                print("> Debian-based distributions: 'sudo apt update && sudo apt install ngspice libngspice0 libngspice0-dev'\n")
                print("> Red Hat-like distributions: 'sudo dnf install ngspice'\n")
                print("> Arch-based distributions: 'sudo pacman -S ngspice'\n")
                print("> SUSE-based distributions: 'sudo zypper install ngspice'\n")

                exit(1)


    def get_ngspice_path(self):
        return self._lib_path
