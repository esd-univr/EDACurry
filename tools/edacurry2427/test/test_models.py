import sys
from pathlib import Path
sys.path.append(str(Path(__file__).resolve().parent.parent))
from src import DefectModel, ShortModel, OpenModel, OpenGateModel, ParametricModel, DetectionStatus, Reverter

current_dir = Path(__file__).resolve().parent
eldo_cir_dir = current_dir.parent.parent.parent/"sources"/"test"/"eldo"/"circ_base"

import edacurry


circuit = edacurry.parse_eldo(f"{eldo_cir_dir}/opamp.cir")
reverter = Reverter(circuit)

# OPEN MODEL
open_model = OpenModel(circuit, "D0", "Capacitor", "OPAMP1.xcc01", "open_model", None, 0.75, 0, 0, None, "net12", "net12")

# Get model info
print("Open model info:\n")

om_info = open_model.get_info()
for info in om_info:
    print(info, " : ", om_info[info])
print("\n\n")


# Modify defect record data
print("Modify open model defect record detection status:\n")

om_defect_record = open_model.get_record()
om_defect_record.set_detection_status(DetectionStatus.DETECTED)
om_dr_info = om_defect_record.get_info()
for info in om_dr_info:
    print(info, " : ", om_dr_info[info])
print("\n\n")

# Subckt generation
print("Subckt info:\n")
subckt = open_model.generate_subckt()
print(subckt)
print("\n\n")

# defect injection
print(edacurry.write_eldo(circuit))
print("\n\n")
open_model.inject(reverter)
print(edacurry.write_eldo(circuit))
print("\n\n")

# Reverter status
print("Reverter status:\n")
print(reverter.get_status())
print("\n\n")

reverter.revert_ast()


print("testing Short Model:\n")
short_model = ShortModel(circuit, "D1", "Capacitor", "OPAMP1.xcc01", "short_model", None, 0.75, 0, 0, None, "net12", "out")
print(short_model.get_info())
print("\n\n")

#Subckt generation
print("Subckt info:\n")
subckt = short_model.generate_subckt()
print(subckt)
print("\n\n")

# Defect injection
print(edacurry.write_eldo(circuit))
print("\n\n")
short_model.inject(reverter)
print(edacurry.write_eldo(circuit))
print("\n\n")

# Reverter status
print("Reverter status:\n")
print(reverter.get_status())
print("\n\n")

reverter.revert_ast()


# OPEN GATE MODEL
print("Testing Open Gate Model:\n")

open_gate_model = OpenGateModel(circuit, "D2", "MOSFET", "OPAMP1.mn001", "open_model", 1, 0.75, None, None, None, "out", "net13", "vssa", "net13_open")
print(open_gate_model.get_info())
print("\n\n")

# Subckt generation
print("Subckt info:\n")
subckt = open_gate_model.generate_subckt()
print(subckt)
print("\n\n")

# Injection test
print(edacurry.write_eldo(circuit))
print("\n\n")
open_gate_model.inject(reverter)
print(edacurry.write_eldo(circuit))
print("\n\n")

# Reverter status
print("Reverter status:\n")
print(reverter.get_status())
print("\n\n")

reverter.revert_ast()


# PARAMETRIC MODEL
print("Testing Parametric Model:\n")
parametric_model = ParametricModel(circuit, "DP3", "MOSFET", "OPAMP1.mn001", "MIN", None, 1, None, None, None, "W", 50e-6, 33e-6)
print(parametric_model.get_info())
print("\n\n")

# Injection test
print("Injection test:\n")
print(edacurry.write_eldo(circuit))
print("\n\n")
parametric_model.inject(reverter)
print(edacurry.write_eldo(circuit))
print("\n\n")

# Reverter status
print("Reverter status:\n")
print(reverter.get_status())
print("\n\n")

reverter.revert_ast()

print(edacurry.write_eldo(circuit))
