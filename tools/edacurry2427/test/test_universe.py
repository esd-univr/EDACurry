import sys
from pathlib import Path
sys.path.append(str(Path(__file__).resolve().parent.parent))
from src import DefectModel, ShortModel, OpenModel, OpenGateModel, ParametricModel, DetectionStatus, Reverter, Injector, DefectEngine

current_dir = Path(__file__).resolve().parent
eldo_cir_dir = current_dir.parent.parent.parent/"sources"/"test"/"eldo"/"circ_base"

import edacurry

circuit_filename = eldo_cir_dir/"opamp.cir"
circuit = edacurry.parse_eldo(f"{eldo_cir_dir}/opamp.cir")

manifest_data = {
    "perform_optimization" : {
        "merge" : True,
        "collapse" : True
    },
    "excluded_target" : {
        "content" : [],
        "components" : [{
            "name" : None,
            "exclusion_reason" : None
        }],
        "parameters" : [{
            "name" : None,
            "exclusion_reason" : None
        }]
    },
    "include_bulk_opens" : True
}

defect_engine = DefectEngine(circuit, circuit_filename, manifest_data)

defect_universe = defect_engine.generate_defect_universe()
print("Defect extrapolated: ", len(defect_universe))
print("Defects:")
for defect in defect_universe:
    info = defect.get_info()
    for key in info:
        if key != "defect_record":
            print(key, " : " ,info[key])
        else:
            record_info = info[key]
            print("defect_record:")
            for rk in record_info:
                print("    ",rk, " : " ,record_info[rk])
    print("\n")


universe_details = defect_engine.get_universe_details()
print("Generated universe details:", len(universe_details))
print("\n\nUniverse details:")
for detail in universe_details:
    for content in universe_details[detail]:
        for key in content:
                print(key, " : " , content[key])
        print("\n")
