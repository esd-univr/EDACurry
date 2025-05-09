import numpy as np
import edacurry
import sys
import os

# If the output directory does not exist, create it.
if not os.path.exists("eldo_result"):
    os.mkdir("eldo_result")
# Parse the ELDO file.
root = edacurry.parse_eldo("eldo/circ_base/opamp.cir")
# Define sweep parameters, widths from 1μm to 5μm, 5 points.
width_values = np.linspace(1.0, 5.0, 5)  # 
# For each width value...
for width in width_values:
    # Update each NMOS width.
    for nmos in edacurry.find_components_by_master(root, "nmos1"):
        # Find the parameter "W".
        w_param = edacurry.find_parameter(nmos, "W")
        # Update the parameter value.
        w_param.right = edacurry.Double(width)
    # Output each variant netlist
    filename = f"eldo_result/variant_w_{width:.1f}.cir"
    with open(filename, "w") as f:
        f.write(edacurry.write_eldo(root))
