import edacurry
import sys

if len(sys.argv) != 2:
    print(f"Usage: {sys.argv[0]} <eldo_file>")
    sys.exit(1)

eldo_file = sys.argv[1]
root = edacurry.parse_eldo(eldo_file)
# Step 1: Find X1, and change the master to OPAMP1_WP.
original = edacurry.find_component(root, "X1")
original.master = "OPAMP1_WP"
# Step 2: Output result.
print(edacurry.write_eldo(root))
