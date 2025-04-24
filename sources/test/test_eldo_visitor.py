import sys
import edacurry

if len(sys.argv) != 3:
    print(f"Usage: {sys.argv[0]} <input_eldo_file> <output_eldo_file>")
    sys.exit(1)

input_eldo_file = sys.argv[1]
output_eldo_file = sys.argv[2]

# Parse the ELDO file.
root = edacurry.parse_eldo(input_eldo_file)
# Search the subcircuit by name.
subckt = edacurry.find_subckt(root, "OPAMP1")
# Rename the node "xpd" to "XPD".
edacurry.rename_node(subckt, "xpd", "XPD")
# Search the component by name.
component = edacurry.find_component(subckt, "xd1")
# Search the parameter by name.
parameter = edacurry.find_parameter(component, "M")
# Change the parameter value.
parameter.right = edacurry.Double(2.45)

with open(output_eldo_file, "w") as outf:
    outf.write(edacurry.write_eldo(root))
