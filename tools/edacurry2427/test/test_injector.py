import sys
from pathlib import Path
sys.path.append(str(Path(__file__).resolve().parent.parent))
from src import DefectModel, ShortModel, OpenModel, OpenGateModel, ParametricModel, DetectionStatus, Reverter, Injector

current_dir = Path(__file__).resolve().parent
eldo_cir_dir = current_dir.parent.parent.parent/"sources"/"test"/"eldo"/"circ_base"

import edacurry


circuit = edacurry.parse_eldo(f"{eldo_cir_dir}/opamp.cir")
reverter = Reverter(circuit)


open_model = OpenModel(circuit, "D0", "OPAMP1.xcc01", None, None, 0.75, 0, 0, None, "net12", "out")
short_model = ShortModel(circuit, "D1", "OPAMP1.xcc01", None, None, 0.75, 0, 0, None, "net12", "out")
open_gate_model = OpenGateModel(circuit, "D2", "OPAMP1.mn001", None, 1, 0.75, None, None, None, "out", "net13", "vssa", "net13_open")
parametric_model = ParametricModel(circuit, "DP3", "OPAMP1.mn001", "MIN", None, 1, None, None, None, "W", 50e-6, 33e-6)

defect_list = [open_model, short_model, open_gate_model, parametric_model]

injector = Injector(reverter)
ngspice_data = []

for defect in defect_list:
    ngspice_data.append(injector.inject_defect(defect))

for data in ngspice_data:
    print("Ngspice_netlist:\n", data[0])
    print("\n")
    print("Warnings:\n", data[1])
    print("\n\n")
