import sys
from pathlib import Path

currentDir = Path(__file__).parent.resolve()
sourcesDir = currentDir.parent
EDACurryDir = sourcesDir.parent


buildDir = str(EDACurryDir) + "/build"
sys.path.append(buildDir)
import edacurry

fully_compatible = 0
compatible_circuits = []
modified_with_warnings = 0
modified_with_warnings_circuits = {}

print("TESTING NGSPICE BACKEND:\n")
eldo_circ_baseDir = currentDir.joinpath("eldo", "circ_base")
for file in eldo_circ_baseDir.iterdir():
    filename = str(file).split("/")[-1]
    print("Analysing " + filename + ":\n")

    print("Parsing eldo circuit...")
    complete_filename = str(file)
    circuit = edacurry.parse_eldo(complete_filename)
    eldo_circuit = edacurry.write_eldo(circuit)
    print("Eldo circuit:\n")
    print(eldo_circuit)
    print("\n\n")

    print("Generating ngpice compatible version...")
    ngspice_cir, warnings = edacurry.write_ngspice(circuit)
    print("Ngspice compatible circuit:\n")
    print(ngspice_cir)
    print("\n\n")

    if warnings:
        modified_with_warnings += 1
        modified_with_warnings_circuits[filename] = warnings
    else:
        fully_compatible += 1
        compatible_circuits.append(filename)

    print("==============================================================\n")


print("STATISTICS:\n")
print("Fully compatible circuits: " + str(fully_compatible))
print("Compatible circuits:")
for circ in compatible_circuits:
    print(circ)
print("\n\nPartially compatible with warnings: " + str(modified_with_warnings))
print("Partially compatible circuits:")
for circ in modified_with_warnings_circuits:
    print(circ + "\n")
    for warning in modified_with_warnings_circuits[circ]:
        print("> " + warning)
    print("\n")
