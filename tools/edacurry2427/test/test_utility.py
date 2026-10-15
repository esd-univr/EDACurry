import sys
from pathlib import Path
sys.path.append(str(Path(__file__).resolve().parent.parent))
from src import (DefectRecord, DefectType, DetectionStatus, UndetectabilityReason, PotentiallyUndetectabilityReason,
                 StructuralUndetectabilityReason)


# Defect instantiation

defect_id = "_d1"
defect_type = DefectType.SHORT
instance_name = "Amplifier"
node_terminals = ["T1", "T2"]
model_name = "short_model"
multiplier = None
weight = 0.73
collapsed = 3
merged = None
zero_weighted_justification = None

defect_d1 = DefectRecord(defect_id, defect_type, instance_name, node_terminals, model_name, multiplier,
                         weight, collapsed, merged, zero_weighted_justification)



# Get defect details

print("Defect details:\n")
defect_info = defect_d1.get_info()
for info in defect_info:
    print(info, ": ", defect_info[info])


# Set undetectable
print("\n\nSetting undetectable parameter to True:\n")
defect_d1.set_undetectable(True)
defect_info = defect_d1.get_info()
for info in defect_info:
    print(info, ": ", defect_info[info])


# Set undetectability Reason
print("\n\nSetting undetectability reason")
undetectability_type = "PUR"
reason = "Short in one of N in series"
defect_d1.set_undetectability_reason(undetectability_type, reason)
defect_info = defect_d1.get_info()
for info in defect_info:
    print(info, ": ", defect_info[info])


# Set detection status to Detected
print("\n\nSetting detected status to DETECTED:\n")
defect_d1.set_detection_status(DetectionStatus.DETECTED)
defect_info = defect_d1.get_info()
for info in defect_info:
    print(info, ": ", defect_info[info])

