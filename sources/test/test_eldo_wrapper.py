import edacurry
import sys

if len(sys.argv) != 2:
    print(f"Usage: {sys.argv[0]} <eldo_file>")
    sys.exit(1)

eldo_file = sys.argv[1]
root = edacurry.parse_eldo(eldo_file)
# Step 1: Find and rename OPAMP1 → OPAMP1_WP
original = edacurry.find_subckt(root, "OPAMP1")
original.name = "OPAMP1_WP"
# Step 2: Create wrapper subckt OPAMP1 with same ports.
wrapper = edacurry.Subckt("OPAMP1")
for node in original.nodes:
    wrapper.nodes.append(edacurry.Node(node.name))
# Step 3: Create a component that instantiates OPAMP1_WP.
xopamp = edacurry.Component("XOP1", "OPAMP1_WP")
for node in original.nodes:
    xopamp.nodes.append(edacurry.Node(node.name))
wrapper.content.append(xopamp)
# Step 4: Add the wrapper back to the root
root.content.append(wrapper)
# Step 5: Output result
print(edacurry.write_eldo(root))
