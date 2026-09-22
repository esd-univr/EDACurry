# @author: Christian Checchetti (chris22checchetti@gmail.com)
# utility defines a set of enumerations and useful components

from enum import Enum, StrEnum
from typing import List, Optional
import hashlib
import re

import sys
from pathlib import Path
edacurry_exec_path = Path(__file__).resolve().parent.parent.parent.parent/"build"
sys.path.append(str(edacurry_exec_path))
import edacurry

from collections import defaultdict


class DefectType (StrEnum):
    SHORT = "short"
    OPEN = "open"
    PARAMETRIC = "parametric"


class UndetectabilityReason (Enum):
    pass

class PotentiallyUndetectabilityReason (UndetectabilityReason):
    OPEN_IN_PARALLEL = "Open in one of N in parallel"
    SHORT_IN_SERIES = "Short in one of N in series"
    REDUNDANCY = "Defect in circuit that is redundant to improve yeld"
    TEST_ACCESS = "Detection is prevented by impact of test access"
    OTHER = "Other"

    @classmethod
    def from_str(cls, value_str : str):
        try:
            return cls(value_str)
        except ValueError:
            return cls.OTHER


class StructuralUndetectabilityReason (UndetectabilityReason):
    UNUSED_OUTPUT = "Open to an unused output"
    TIE_INPUT_SHORT = "Short across a resistor that ties an input to a rail"
    REDUNDANCY = "Defect in circuit that is redundant to improve yeld"
    EQUAL_POTENTIAL_SHORT = "Short between two nodes that are logically prevented from having different voltages"
    DISALLOWED_STIMULUS = "Could only be detected by a stimulus that is not allowed"
    OTHER = "Other"

    @classmethod
    def from_str(cls, value_str: str):
        try:
            return cls(value_str)
        except ValueError:
            return cls.OTHER


class DetectionStatus(StrEnum):
    UNDETECTED = "undetected"
    DETECTED = "detected"
    UNKNOWN = "unknown"
    UNSIMULATED = "unsimulated"


class DefectRecord:

    _id: str                                                        # defect id
    _component_category: str                                        # Circuit's element type, such as Diode, Resistor, MOSFET, etc.
    _type: DefectType                                               # defect type
    _instance_name: str                                             # component full name (e.g. X1.M1)
    _node_terminals: List[str]                                      # nodes affected by the defect
    _model_name: str                                                # defect's model name (e.g. open_model,
                                                                    # MAX/MIN for parametrics)
    _multiplier: Optional[int]                                      # multiplication parameter M used when parallel
                                                                    # elements are encountered
    _weight: float                                                  # statistical weight associated to the defect
    _collapsed: Optional[int]                                       # indicates the optional total number of a collapsed
                                                                    # group of equivalent defects
    _merged: Optional[int]                                          # indicates the optional number of parallel elements
                                                                    # merged before injection
    _undetectable: bool                                             # flag to verify if a defect is potentially
                                                                    # undetectable. Default is None (pre-simulation)
    _undetectability_reason: Optional[UndetectabilityReason]        # if undetectable = True a reason of undetectability
                                                                    # must be specified
    _0_weight_justification: Optional[str]                          # the reason behind a 0 weighed element must be
                                                                    # provided
    _detection_status: DetectionStatus                              # defect detection status. Default is unsimulated




    def __init__ (self, id, component_category, type, instance_name, node_terminals, model_name, multiplier, weight, collapsed,
                  merged, zero_weight_justification):
        try:
            self._id = id
            self._component_category = component_category
            self._type = type
            self._instance_name = instance_name
            self._node_terminals = node_terminals
            self._model_name = model_name
            if multiplier:
                self._multiplier = multiplier
            else:
                self._multiplier = None
            self._weight = weight
            self._weight = weight
            if collapsed:
                self._collapsed = collapsed
            else:
                self._collapsed = None
            if merged:
                self._merged = merged
            else:
                self._merged = None
            self._undetectable = None
            self._undetectability_reason = None
            if weight == 0:
                if zero_weight_justification:
                    self._0_weight_justification = zero_weight_justification
                else:
                    raise Exception("the reason behind a zero-weighted defect must be provided\n")
            else:
                self._0_weight_justification = zero_weight_justification
            self._detection_status = DetectionStatus.UNSIMULATED
        except (Exception) as e:
            raise Exception(f"[DefectRecord] Initialization error: {e}\n")



    def set_undetectable(self, undetectable):
        self._undetectable = undetectable

    def get_undetectable(self):
        return self._undetectable


    def set_undetectability_reason(self, undet_type, reason):
        if undet_type == "PUR":
            self._undetectability_reason = PotentiallyUndetectabilityReason.from_str(reason)
        elif undet_type == "SUR":
            self._undetectability_reason = StructuralUndetectabilityReason.from_str(reason)
        else:
            raise Exception(f"[DefectRecord] Unable to set the specified undetectability reason. {str(undet_type)} is not a valid type\n")



    def set_detection_status(self, status : DetectionStatus):
        self._detection_status = status

    def get_detection_status(self):
        return self._detection_status


    def get_info(self):
        dr_dict = {
            "id": self._id,
            "component_category": self._component_category,
            "type": self._type,
            "instance_name": self._instance_name,
            "node_terminals": self._node_terminals,
            "weight": self._weight,
            "collapsed": self._collapsed,
            "merged": self._undetectable,
            "undetectable": self._undetectable,
            "undetectability_reason": self._undetectability_reason,
            "0_weight_justification": self._0_weight_justification,
            "detection_status": self._detection_status
        }
        return dr_dict


class SpiceScaleFactors(Enum):
    T = 1e12
    G = 1e9
    MEG = 1e6
    K = 1e3
    MIL = 25.4e-6
    M = 1e-3
    U = 1e-6
    N = 1e-9
    P = 1e-12
    F = 1e-15
    A = 1e-18

    @classmethod
    def from_prefix(cls, unit):
        if unit and unit.lower() == "t":
            return cls.T.value
        elif unit and  unit.lower() == "g":
            return cls.G.value
        elif unit and unit.lower() == "meg":
            return cls.MEG.value
        elif unit and unit.lower() == "k":
            return cls.K.value
        elif unit and unit.lower() == "mil":
            return cls.MIL.value
        elif unit and unit.lower() == "m":
            return cls.M.value
        elif unit and unit.lower() == "u":
            return cls.U.value
        elif unit and unit.lower() == "n":
            return cls.N.value
        elif unit and unit.lower() == "p":
            return cls.P.value
        elif unit and unit.lower() == "f":
            return cls.F.value
        elif unit and unit.lower() == "a":
            return cls.A.value
        else:
            return None


class ParamValueAnalyzer:
    @classmethod
    def get_param_info(cls, param : edacurry.Value):
        """
            - Identifier: name --> Done
            - Expression: operator, first, second
            - ExpressionUnary: operator, value
            - FunctionCall: name, parameters
            - Number: value, unit --> Done
            - String: string
            - ValueList: values, delimiter
            - ValuePair: first, second

        """
        if param:
            if type(param) == edacurry.Identifier:
                value = param.name
                # A numeric value can be parsed by EDACurry as an identifier, so it's possible to have a value like 400n
                # Verify the presence of a unit

                pattern_capture = r"^(\d+(?:\.\d+)?(?:[eE][+-]?\d+)?)([a-zA-Z]+)$"
                data = re.match(pattern_capture, value)
                unit = None

                if data:
                    value, unit = data.groups()

                # Remove unit from value
                if unit is not None:
                    value = value.replace(unit, "")

                # Cast to float if numeric
                try:
                    value = float(value)
                except ValueError:
                    pass

                unit_value = SpiceScaleFactors.from_prefix(unit)
                if unit_value:
                    value *= unit_value

                return value

            elif type(param) == edacurry.Int or type(param) == edacurry.Double:
                return param.value

        else:
            return None


class Optimizer:

    _circuit : edacurry.Circuit
    _circuit_filename : Path | str                    # Initial netlist filename
    _manifest_file : dict                             # Manifest configuration file
    _ok_to_optimize : dict                            # Flag specified in the manifest configuration file

    def __init__(self, circuit: edacurry.Circuit, filename : Path | str, manifest : dict):
        self._circuit = circuit
        if circuit is None:
            raise ValueError("[Optimizer] Initialization error: invalid circuit\n")
        if filename is None:
            raise ValueError("[Optimizer] Initialization error: invalid filename for initial netlist\n")
        self._circuit_filename = filename
        if manifest is None:
            raise ValueError("[Optimizer] Initialization error: no manifest configuration file provided\n")
        self._manifest_file = manifest
        try:
            self._ok_to_optimize = self._manifest_file["perform_optimization"]
        except KeyError:
            print("[Optimizer] Initialization error: missing 'perform_optimization' parameter in the manifest file. False assumed as default\n")
            self._ok_to_optimize["merge"] = False
            self._ok_to_optimize["collapse"] = False

    def get_structure(self):

        structure = []

        for cont in self._circuit.content:
            # Analyze only the design under test
            if cont.name in self._manifest_file["dut"]:

                signatures = []
                components = []

                # Get components
                for component in cont.content:
                    # Get component master
                    comp_master = component.master
                    # Get nodes
                    nodes = []
                    for node in component.nodes:
                        nodes.append(node.name)
                    nodes = tuple(nodes)
                    # Get parameters
                    parameters = []
                    for parameter in component.parameters:
                        # Collect parameters based on their type
                        parameters.append((ParamValueAnalyzer.get_param_info(parameter.left), ParamValueAnalyzer.get_param_info(parameter.right)))

                    parameters = tuple(parameters)
                    signatures.append((comp_master, nodes, parameters))
                    components.append(component)
                structure.append((cont, components, signatures))

        return structure


    def optimize_merge(self) -> edacurry.Circuit:

        print("[Optimizer::optimize_merge] Optimizing circuit...")

        if not self._ok_to_optimize["merge"]:
            print("[Optimizer::optimize_merge] No optimization operation has been required. Nothing to do\n")
            return

        structure = self.get_structure()
        has_been_optimized = False

        for element in structure:
            equivalent_components = {}
            element_type, components, signatures = type(element[0]), element[1], element[2]

            if "edacurry.Subckt" in str(element_type):
                # Extract subckt name
                subckt_name = element[0].name
                if subckt_name is None:
                    raise ValueError("[Optimizer::optimize_merge] Unable to retrieve subckt name\n")

                # Find subckt
                subckt = edacurry.find_subckt(self._circuit, subckt_name)
                if subckt is None:
                    raise ValueError(f"[Optimizer::optimize_merge] Unable to find subckt {subckt_name}\n")

                # Find equivalent components that can be merged
                i = 0
                while i < len(components):
                    # Avoid duplicates
                    if signatures[i] in equivalent_components:
                        i += 1
                        continue

                    j = 0
                    while j < len(signatures):
                        if i != j and signatures[i] == signatures[j]:
                            if signatures[i] not in equivalent_components:
                                equivalent_components[signatures[i]] = [components[i]]
                            equivalent_components[signatures[i]].append(components[j])
                        j += 1
                    i += 1

                # If no components can be merged, skip
                if len(equivalent_components) > 0:
                    print(f"[Optimizer::optimize_merge] Optimizing {subckt_name}...")
                    for signature in equivalent_components:
                        eq_comp = len(equivalent_components[signature])
                        i = 1
                        # Remove equivalent components
                        while i < len(equivalent_components[signature]):
                            subckt.content.remove(equivalent_components[signature][i])
                            i += 1
                        # Adjust M parameter to indicates how many components are merged
                        parameters = equivalent_components[signature][0].parameters
                        # Check the presence of M parameter
                        found_M = False
                        for parameter in parameters:
                            if parameter.type == edacurry.ParameterType.param_assign:
                                if parameter.left.name.lower() == 'm':
                                    parameter.right = edacurry.Double(eq_comp)
                                    found_M = True
                        if not found_M:
                            parameters.append(edacurry.Parameter(edacurry.Identifier("M"), edacurry.Double(eq_comp), edacurry.ParameterType.param_assign))
                    has_been_optimized = True
                    print("[Optimizer::optimize_merge] Done\n")
            else:
                print(f"[Optimizer::optimize_merge] Optimizer for {element_type} is still under development\n")

        if has_been_optimized:
            # Save the optimized netlist file
            optimized_dir = Path(__file__).resolve().parent.parent/"optimized netlists"
            Path(optimized_dir).mkdir(parents=True, exist_ok=True)
            optimized_filename = self._circuit_filename.split("/")[-1]
            optimized_filename = f"{optimized_dir}/optimized_{optimized_filename}"
            with open(optimized_filename, "w") as f:
                f.write(edacurry.write_eldo(self._circuit))

            print(f"[Optimizer::optimize_merge] Circuit has been optimized and the netlist file has been saved in {optimized_dir}\n")

        else:
            print(f"[Optimizer::optimize_merge] Nothing to do")


    # Analyses the data inside the universe details and collapse the collapsable defects
    def optimize_collapse(self, universe_details : List):
        print("[Optimizer::optimize_collapse] Collapsing equivalent defects...")
        # Check if optimization is requested
        if not self._ok_to_optimize["collapse"]:
            print("[Optimizer::optimize_collapse] No optimization operation has been required. Nothing to do\n")
            return

        for content in universe_details:
            defects_index = 0
            defects_n = len(universe_details[content])

            while defects_index < defects_n:
                instance_name = universe_details[content][defects_index]["defect_instance"]
                first_instance_index = None
                cumulative_weight = 0
                collapsed = 1

                z_w_j = "Defect has been collapsed"

                while universe_details[content][defects_index]["defect_instance"] == instance_name:

                    # Collapsing opens
                    if (universe_details[content][defects_index]["No_2427_defect"] == False and
                        (universe_details[content][defects_index]["component_category"] == ComponentCategory.RESISTOR.value or universe_details[content][defects_index]["component_category"] == ComponentCategory.INDUCTOR.value or
                        universe_details[content][defects_index]["component_category"] == ComponentCategory.CAPACITOR.value or universe_details[content][defects_index]["component_category"] == ComponentCategory.DIODE.value) and
                        universe_details[content][defects_index]["defect_type"] == DefectType.OPEN):

                        if first_instance_index is None:
                            first_instance_index = defects_index
                        if collapsed == 1:
                            collapsed += 1
                        cumulative_weight += universe_details[content][defects_index]["weight"]

                    if defects_index < defects_n - 1:
                        defects_index += 1
                    else:
                        break

                if cumulative_weight > 0:
                    universe_details[content][first_instance_index]["weight"] = cumulative_weight
                    universe_details[content][first_instance_index]["collapsed"] = collapsed

                    starting_point = first_instance_index + 1
                    while starting_point < defects_index:
                        universe_details[content][starting_point]["weight"] = 0
                        universe_details[content][starting_point]["z_w_j"] = z_w_j
                        starting_point += 1

                defects_index += 1

        print("[Optimizer::optimize_collapse] Done")
        return universe_details





class ComponentCategory(Enum):
    # Following SPICE standard
    # Passive components
    RESISTOR = "resistor"
    CAPACITOR = "capacitor"
    INDUCTOR = "inductor"
    MUTUAL_INDUCTOR = "mutual_inductor"

    # Semiconductor (both active and passive)
    MOSFET = "mosfet"
    BJT = "bjt"
    JFET = "jfet"
    MESFET = "mesfet"
    DIODE = "diode"

    # Generators and independent sources
    VOLTAGE_SOURCE = "voltage_source"
    CURRENT_SOURCE = "current_source"
    BEHAVIORAL_SOURCE = "behavioral_source"

    # Linear controlled sources
    VCVS = "vcvs"   # Voltage Controlled Voltage Source
    VCCS = "vccs"   # Voltage Controlled Current Source
    CCCS = "cccs"   # Current Controlled Current Source
    CCVS = "ccvs"   # Current Controlled Voltage Source

    # Transmission lines and Distributed nets
    TRANSMISSION_LINE_IDEAL = "transmission_line_ideal"
    TRANSMISSION_LINE_LOSSY = "transmission_line_lossy"
    CPL_LINE = "cpl_line"   # Coupled Multiconductor Line
    TXL_LINE = "txl_line"   # Single Lossy Transmission Line
    URC_LINE = "urc_line"   # Uniformly Distributed RC Line

    # Subcircuits and extended models
    SUBCIRCUIT = "subcircuit"
    XSPICE_MODEL = "xspice_model"
    VERILOG_A_MODEL = "verilog_a_model"
    VOLTAGE_SWITCH = "voltage_switch"
    CURRENT_SWITCH = "current_switch"


    @classmethod
    def from_string(cls, name : str, base_only : bool):
        # SPICE standard provides that instance component name first letter indicates the component category
        if not name:
            print("[ComponentCategory::from_string] Missing component name\n")
            return None

        target = name[0].upper()
        if target == 'R':
            return [ComponentCategory.RESISTOR, "passive"]
        elif target == 'C':
            return [ComponentCategory.CAPACITOR, "passive"]
        elif target == 'L':
            return [ComponentCategory.INDUCTOR, "passive"]
        elif target == 'K':
            return [ComponentCategory.MUTUAL_INDUCTOR, "passive"]
        elif target == 'M':
            return [ComponentCategory.MOSFET, "active"]
        elif target == 'Q':
            return [ComponentCategory.BJT, "active"]
        elif target == 'J':
            return [ComponentCategory.JFET, "active"]
        elif target == 'Z':
            return [ComponentCategory.MESFET, "active"]
        elif target == 'D':
            return [ComponentCategory.DIODE, "active"] # from a physical perspective it's passive, but treated as active by fault injection techniques
        elif target == 'V':
            return [ComponentCategory.VOLTAGE_SOURCE, "active"]
        elif target == 'I':
            return [ComponentCategory.CURRENT_SOURCE, "active"]
        elif target == 'B':
            return [ComponentCategory.BEHAVIORAL_SOURCE, "active"]
        elif target == 'E':
            return [ComponentCategory.VCVS, "active"]
        elif target == 'G':
            return [ComponentCategory.VCCS, "active"]
        elif target == 'F':
            return [ComponentCategory.CCCS, "active"]
        elif target == 'H':
            return [ComponentCategory.CCVS, "active"]
        elif target == 'T':
            return [ComponentCategory.TRANSMISSION_LINE_IDEAL, "passive"]
        elif target == 'O':
            return [ComponentCategory.TRANSMISSION_LINE_LOSSY, "passive"]
        elif target == 'P':
            return [ComponentCategory.CPL_LINE, "passive"]
        elif target == 'Y':
            return [ComponentCategory.TXL_LINE, "passive"]
        elif target == 'U':
            return [ComponentCategory.URC_LINE, "passive"]
        elif target == 'X':
            if not base_only:
                return [ComponentCategory.SUBCIRCUIT, "hybrid"]
            else:
                next_name = name[1:]
                if next_name.startswith("_") or next_name.startswith("."):
                    next_name = next_name[1:]
                return cls.from_string(next_name, base_only)
        elif target == 'A':
            if not base_only:
                return [ComponentCategory.XSPICE_MODEL, "hybrid"]
            else:
                next_name = name[1:]
                if next_name.startswith("_") or next_name.startswith("."):
                    next_name = next_name[1:]
                return cls.from_string(next_name, base_only)
        elif target == 'N':
            if not base_only:
                return [ComponentCategory.VERILOG_A_MODEL, "hybrid"]
            else:
                next_name = name[1:]
                if next_name.startswith("_") or next_name.startswith("."):
                    next_name = next_name[1:]
                return cls.from_string(next_name, base_only)
        elif target == 'S':
            return [ComponentCategory.VOLTAGE_SWITCH, "passive"]
        elif target == 'W':
            return [ComponentCategory.CURRENT_SWITCH, "passive"]


    @classmethod
    def get_corner_value(cls, category, dev_dir : str, typical_value : float, params : List[str]):

        if dev_dir is None or (dev_dir != "MIN" and dev_dir != "MAX"):
            raise ValueError(f"[ComponentCategory::get_corner_value] {dev_dir} is not a valid deviation direction. Only 'MIN' and 'MAX' are admitted\n")

        if category == ComponentCategory.RESISTOR or category == ComponentCategory.CAPACITOR or category == ComponentCategory.INDUCTOR or category == ComponentCategory.DIODE:

            deviation_corner = "±25%"
            if dev_dir == "MIN":
                return (deviation_corner, typical_value * 0.75)
            elif dev_dir == "MAX":
                return (deviation_corner, typical_value * 1.25)

        elif category == ComponentCategory.MOSFET:

            w_param = None
            l_param = None
            tox_param = None
            vth0_param = None

            for param in params:
                if param is not None:
                    if param[0].lower() == "w":
                        w_param = param
                    elif param[0].lower() == "l":
                        l_param = param
                    elif param[0].lower() == "tox":
                        tox_param = param
                    elif param[0].lower() == "vth0":
                        vth0_param = param

            # Different according to the parameter
            if w_param is None and l_param is None and tox_param is None and vth0_param is None:
                raise ValueError("[ComponentCategory::get_corner_value] Missing param values for MOSFET\n")
            if w_param is not None and l_param is not None:
                deviation_corner = "±27.5%"
                if dev_dir == "MIN":
                    return (deviation_corner, typical_value * 0.725)
                elif dev_dir == "MAX":
                    return (deviation_corner, typical_value * 1.275)
            elif vth0_param is not None:
                deviation_corner = "±13.5%"
                if dev_dir == "MIN":
                    return (deviation_corner, typical_value * 0.865)
                elif dev_dir == "MAX":
                    return (deviation_corner, typical_value * 1.135)
            elif tox_param is not None:
                deviation_corner = "±10%"
                if dev_dir == "MIN":
                    return (deviation_corner, typical_value * 0.9)
                elif dev_dir == "MAX":
                    return (deviation_corner, typical_value * 1.10)
            else:
                print(f"[ComponentCategory::get_corner_value] Support for parameter {param} is still under development\n")
                return (None, None)

        else:
            print(f"[ComponentCategory::get_corner_value] Support for category {category} is still under development\n")
            return (None, None)


class ComponentCategorizer:

    @classmethod
    def get_category(cls, component : edacurry.Component, base_only : bool = False):
        if component is None:
            print("[ComponentCategory::get_category] Missing component name\n")
            return None
        return ComponentCategory.from_string(component.name, base_only)

    @classmethod
    def get_pdk_corner_value(cls, category : ComponentCategory, dev_dir : str, typical_value : float, params : List[str]):
        return ComponentCategory.get_corner_value(category, dev_dir, typical_value, params)

