import sys
import edacurry

# Parse the ELDO file.
root = edacurry.parse_eldo("eldo/circ_base/opamp.cir")
# Search the subcircuit by name.
subckt = edacurry.find_subckt(root, "OPAMP1")
# Rename the node "xpd" to "XPD".
edacurry.rename_node(subckt, "xpd", "XPD")
# Search the component by name.
component = edacurry.find_component(subckt, "xd1")
# Search the parameter by name.
parameter = edacurry.find_parameter(component, "M")
# Change the parameter value.
parameter.right = edacurry.Double(2.42)
# Output result.
print(edacurry.write_eldo(root))
