# @author: Christian Checchetti (chris22checchetti@gmail.com
# The universe class analyses the circuit and provide the defect universe details and the defect universe

from .utility import Optimizer, ComponentCategorizer, ComponentCategory, DefectType
from .models import DefectModel, OpenModel, OpenGateModel, ShortModel, ParametricModel

import sys
from pathlib import Path
edacurry_exec_path = Path(__file__).resolve().parent.parent.parent.parent/"build"
sys.path.append(str(edacurry_exec_path))
import edacurry

from typing import List
import math


class IdGenerator:
    _defect_number : int

    def __init__(self):
        self._defect_number = -1


    def generate_id(self, defect_type : DefectType):

        if defect_type == DefectType.SHORT or defect_type == DefectType.OPEN:
            self._defect_number += 1
            return f"D{self._defect_number}"
        elif defect_type == DefectType.PARAMETRIC:
            self._defect_number += 1
            return f"DP{self._defect_number}"


class DefectEngine:

    _circuit : edacurry.Circuit
    _manifest_data : dict
    _optimizer : Optimizer
    _excluded_target : dict
    _dut : str
    _id_generator : IdGenerator
    _universe_details : List = []

    target_parameters = {
        "resistor": ["r", "value", "l", "w", "rhs"],
        "capacitor": ["c", "cap", "area", "tox", "thick"],
        "inductor": ["l"],
        "diode": ["is"],
        "mosfet": ["w", "l", "vth0", "tox", "thick"],
        "mesfet": ["vt0", "beta", "alpha", "lambda", "rd", "rs", "is"],
        "jfet": ["vto", "vt0", "beta", "lambda", "rd", "rs", "is", "cgs", "cgd"],
        "bjt": ["is", "bf", "vaf", "rb", "rc", "re", "cje", "cjc"]
    }

    def __init__(self, circuit: edacurry.Circuit, filename : Path | str, manifest_data: dict):
        if circuit is None:
            raise ValueError("[DefectEngine] Invalid circuit")
        self._circuit = circuit
        if filename is None:
            raise ValueError("[DefectEngine] Invalid filename for initial netlist")
        self._optimizer = Optimizer(self._circuit, filename, manifest_data)
        if manifest_data is None:
            raise ValueError("[DefectEngine] No manifest provided")
        self._manifest_data = manifest_data
        try:
            self._dut = manifest_data["dut"]
        except KeyError:
            raise ValueError("[DefectEngine] Missing dut target on which to perform the analysis")
        try:
            self._excluded_target = manifest_data["excluded_target"]
        except KeyError:
            raise ValueError("[DefectEngine] Missing excluded target on which to perform the analysis")
        self._id_generator = IdGenerator()
        try:
            self._universe_details = self.process_defects()
        except Exception as e:
            raise Exception(f"[DefectEngine] Unable to analyze circuit to extract defect details: {e}")


    # Analyses circuit and extract defects metadata
    def process_defects(self):
        print("[DefectEngine::process_defects] Analysing circuit to extract defect details...")
        # Get circuit structure
        structure = self._optimizer.get_structure()

        defect_universe_raw = {} # Contains raw metadata about all the injectable defects, categorized by content

        # Metadata : retrieve possible defects only for the elements precised in the manifest
        for element in structure:
            content = element[0]
            # Check if analysis must be performed
            if content.name in self._dut:
                components = element[1]
                signatures = element[2]

                comp_num = len(components)
                index = 0
                defect_metadata = []
                while index < comp_num:
                    # Get component category
                    category = ComponentCategorizer.get_category(components[index], True)[0]
                    if category is None:
                        raise ValueError(f"[DefectEngine] Unable to determine category for component {components[index]} in {content.name}")

                    # Check if component is marked as excluded in the manifest file
                    #calculate_weight = True
                    no_2427_defect = False
                    z_w_j = None
                    if components[index].name in self._excluded_target["components"][0]:
                        no_2427_defect = True
                        z_w_j = f"Component {components[index].name} is marked as excluded from analysis by the manifest file"

                    # Defect generation
                    # TWO-TERMINAL DIPOLE
                    if category == ComponentCategory.RESISTOR or category == ComponentCategory.CAPACITOR or category == ComponentCategory.INDUCTOR:

                        # Get nodes
                        nodes = signatures[index][1]
                        # Ignore bulk terminal
                        if len(nodes) > 2:
                            nodes = (nodes[0], nodes[1])

                        # Find parameters
                        parameters = signatures[index][2]
                        m_param = None
                        r_param = None
                        c_param = None
                        for parameter in parameters:
                            if parameter[0].lower() == "m":
                                m_param = parameter
                            if parameter[0].lower() == "r":
                                r_param = parameter
                            if parameter[0].lower() == "c":
                                c_param = parameter
                        if m_param is None:
                            m_param = ('M', 1)

                        # Find weight for short and open using formulas defined by IEEE 2427
                        calculate_weight = True
                        if no_2427_defect: calculate_weight = False
                        short_weight = 0
                        open_weight = 0

                        if calculate_weight:
                            if category == ComponentCategory.RESISTOR:
                                if r_param is not None:
                                    open_weight = float(r_param[1]) / 800
                                    short_weight = 800 / float(r_param[1])
                                else:
                                    # Default fallback value precised by the standard
                                    open_weight = 1
                                    short_weight = 1
                            elif category == ComponentCategory.CAPACITOR:
                                open_weight = 1
                                if c_param is not None:
                                    short_weight = float(c_param[1]) / 1e-13
                                else:
                                    short_weight = 1
                            elif category == ComponentCategory.INDUCTOR:
                                open_weight = 1
                                short_weight = 1

                        # Components merged during optimization or specified as merged in the DUT
                        merged = None
                        merged = m_param[1]

                        if not no_2427_defect:
                            # Short model between nodes
                            short_defect = {
                                "No_2427_defect" : no_2427_defect,
                                "component_category" : category.value,
                                "defect_type" : DefectType.SHORT,
                                "open_gate" : False,
                                #"circuit": self._circuit,
                                "defect_id" : self._id_generator.generate_id(DefectType.SHORT),
                                "defect_instance" : f"{content.name}.{components[index].name}",
                                "name" : "short_model",
                                "multiplier" : str(int(m_param[1])),
                                "weight" : short_weight * int(m_param[1]),
                                "collapsed" : None,     # not considered at this stage
                                "merged" : merged,
                                "z_w_j" : z_w_j,
                                "n1" : nodes[0],
                                "n2" : nodes[1],
                            }
                            defect_metadata.append(short_defect)

                            # Open model between nodes
                            open_defect = {
                                "No_2427_defect": no_2427_defect,
                                "component_category": category.value,
                                "defect_type": DefectType.OPEN,
                                "open_gate": False,
                                #"circuit": self._circuit,
                                "defect_id": self._id_generator.generate_id(DefectType.OPEN),
                                "defect_instance": f"{content.name}.{components[index].name}",
                                "name": "open_model",
                                "multiplier": str(int(m_param[1])),
                                "weight": open_weight * int(m_param[1]),
                                "collapsed": None,
                                "merged": merged,
                                "z_w_j": z_w_j,
                                "n1": nodes[0],
                                "n2": nodes[0],
                            }
                            defect_metadata.append(open_defect)

                            open_defect = {
                                "No_2427_defect": no_2427_defect,
                                "component_category": category.value,
                                "defect_type": DefectType.OPEN,
                                "open_gate": False,
                                #"circuit": self._circuit,
                                "defect_id": self._id_generator.generate_id(DefectType.OPEN),
                                "defect_instance": f"{content.name}.{components[index].name}",
                                "name": "open_model",
                                "multiplier": str(int(m_param[1])),
                                "weight": open_weight * int(m_param[1]),
                                "collapsed": None,
                                "merged": merged,
                                "z_w_j": z_w_j,
                                "n1": nodes[1],
                                "n2": nodes[1],
                            }
                            defect_metadata.append(open_defect)

                            # Parametric model
                            suitable_params = []
                            if category == ComponentCategory.RESISTOR:
                                # Check any matches between parameters and target params defined for the resistor
                                for parameter in parameters:
                                    if parameter[0].lower() in self.target_parameters["resistor"]:
                                        suitable_params.append(parameter)
                            elif category == ComponentCategory.CAPACITOR:
                                for parameter in parameters:
                                    if parameter[0].lower() in self.target_parameters["capacitor"]:
                                        suitable_params.append(parameter)
                            elif category == ComponentCategory.INDUCTOR:
                                for parameter in parameters:
                                    if parameter[0].lower() in self.target_parameters["inductor"]:
                                        suitable_params.append(parameter)

                            weight = 1.0
                            calculate_weight = True
                            for parameter in parameters:
                                # Check if parameter is marked as excluded
                                for excluded_param in self._excluded_target["parameters"]:
                                    if excluded_param["name"] is not None and parameter[0].lower() == excluded_param[
                                        "name"].lower():
                                        calculate_weight = False
                                        weight = 0
                                        z_w_j = f"Parameter {parameter[0]} is excluded from analysis by the manifest file"
                                        break

                                # Check if parameter is a parasitic element
                                if calculate_weight and parameter not in suitable_params:
                                    weight = 0
                                    if parameter[0].lower() != "m":
                                        z_w_j = "Nominal value is below the specified threshold for design-intent elements and is assumed to be a parasitic element"
                                    else:
                                        z_w_j = "Multiplier parameter"

                                # For every parameter, both deviation directions have to be defined
                                # MIN
                                if parameter[0].lower() != "m":
                                    deviation_corner, pdk_corner_value_min = ComponentCategorizer.get_pdk_corner_value(category, "MIN", float(parameter[1]), None)
                                else:
                                    deviation_corner = None
                                    pdk_corner_value_min = 0

                                if pdk_corner_value_min is not None:
                                    parametric_defect_min = {
                                        "No_2427_defect": no_2427_defect,
                                        "component_category": category.value,
                                        "defect_type": DefectType.PARAMETRIC,
                                        "open_gate": False,
                                        #"circuit": self._circuit,
                                        "defect_id" : self._id_generator.generate_id(DefectType.PARAMETRIC),
                                        "defect_instance" : f"{content.name}.{components[index].name}",
                                        "name" : "MIN",
                                        "multiplier" : str(int(m_param[1])),
                                        "weight" : weight,                      # Parametric defects have uniform weight
                                        "collapsed" : None,
                                        "merged" : merged,
                                        "z_w_j" : z_w_j,
                                        "parameter_name" : parameter[0],
                                        "typical_value" : float(parameter[1]),
                                        "deviation_corner" : deviation_corner,
                                        "pdk_corner_value" : pdk_corner_value_min
                                    }
                                    defect_metadata.append(parametric_defect_min)

                                # MAX
                                if parameter[0].lower() != "m":
                                    deviation_corner, pdk_corner_value_max = ComponentCategorizer.get_pdk_corner_value(category, "MAX", float(parameter[1]), None)
                                else:
                                    deviation_corner = None
                                    pdk_corner_value_max = 0

                                if pdk_corner_value_max is not None:
                                    parametric_defect_max = {
                                        "No_2427_defect": no_2427_defect,
                                        "component_category": category.value,
                                        "defect_type": DefectType.PARAMETRIC,
                                        #"circuit": self._circuit,
                                        "open_gate": False,
                                        "defect_id": self._id_generator.generate_id(DefectType.PARAMETRIC),
                                        "defect_instance": f"{content.name}.{components[index].name}",
                                        "name": "MAX",
                                        "multiplier": str(int(m_param[1])),
                                        "weight": weight,
                                        "collapsed": None,
                                        "merged": merged,
                                        "z_w_j": z_w_j,
                                        "parameter_name": parameter[0],
                                        "typical_value": float(parameter[1]),
                                        "deviation_corner" : deviation_corner,
                                        "pdk_corner_value": pdk_corner_value_max
                                    }
                                    defect_metadata.append(parametric_defect_max)

                        else:
                            record = {
                                "No_2427_defect": no_2427_defect,
                                "component_category": category.value,
                                "defect_instance": f"{content.name}.{components[index].name}",
                                "z_w_j": z_w_j
                            }
                            defect_metadata.append(record)

                    # MOSFETS
                    elif category == ComponentCategory.MOSFET:

                        # Get nodes
                        nodes = signatures[index][1]
                        # nodes order: D G S B
                        drain = nodes[0]
                        gate = nodes[1]
                        source = nodes[2]
                        bulk = nodes[3]

                        calculate_weight = True
                        short_weight = 0

                        # Find parameters
                        parameters = signatures[index][2]
                        m_param = None
                        w_param = None                          # Channel width
                        l_param = None                          # Channel length
                        vth0_param = None                       # Tension
                        tox_param = None                        # Thickness of the insulating oxide layer

                        for parameter in parameters:
                            if parameter[0].lower() == "m":
                                m_param = parameter
                            if parameter[0].lower() == "w":
                                w_param = parameter
                            if parameter[0].lower() == "l":
                                l_param = parameter
                            if parameter[0].lower() == "vth0":
                                vth0_param = parameter
                            if parameter[0].lower() == "tox" or parameter[0].lower() == "thick":
                                tox_param = parameter

                        if m_param is None:
                            m_param = ('M', 1)

                        if w_param is None:
                            print(f"[DefectEngine::process_defects] Channel width parameter not found for component {components[index].name}. Ignored from the defect universe\n")
                            continue

                        if l_param is None:
                            print(f"[DefectEngine::process_defects] Channel length parameter not found for component {components[index].name}. Ignored from the defect universe\n")
                            continue

                        # Get component master, if component is allowed to be analysed
                        if not no_2427_defect:
                            comp_master = signatures[index][0]
                            # Check if the component instance (throw the component master) have to be excluded in reference of the manifest
                            excluded_contents = self._excluded_target["contents"]
                            for excl_cont in excluded_contents:
                                if comp_master == excl_cont["name"]:
                                    short_weight = 0
                                    z_w_j = f"{comp_master} component is excluded by the analysis as indicated in the manifest file"
                                    break

                        if not no_2427_defect:
                            # Short
                            # All combinations of coupled-nodes must be considered, so 6 shorts will be generated
                            # DG - DS - DB - GS - GB - SB
                            coupled_nodes = ((drain, gate), (drain, source), (drain, bulk), (gate, source), (gate, bulk), (source, bulk))

                            for couple in coupled_nodes:
                                calculate_weight = True
                                short_weight = 0
                                z_w_j = None

                                # Define weights according to the couple
                                if calculate_weight and source == bulk:
                                    short_weight = 0
                                    z_w_j = "Source-bulk short has a weight of 0 because Source and Bulk terminals are nominally connected in the design"
                                    calculate_weight = False

                                if calculate_weight:
                                    if couple[1] == gate:
                                        # weight depends on the channel width
                                        short_weight = float(w_param[1])
                                    elif couple[0] == drain and couple[1] == source:
                                        # If channel is longer than 2 micrometer is statistically impossible to have a short between drain and source
                                        if l_param[1] > 2e-6:
                                            short_weight = 0
                                            z_w_j = "Source-drain shorts are assigned a weight of 0 in this design for transistors with gates longer than 2 µm, since defects larger than 1.5 µm are not considered reasonably likely"
                                        else:
                                            # weight depends on the channel's aspect ratio
                                            short_weight = (float(w_param[1]) / float(l_param[1])) * 0.35
                                    elif couple[1] == bulk:
                                        # weight is uniform
                                        short_weight = 1

                                # Components merged during optimization
                                merged = None
                                merged = m_param[1]

                                # Generate a short for couple
                                short_defect = {
                                    "No_2427_defect": no_2427_defect,
                                    "component_category": category.value,
                                    "defect_type": DefectType.SHORT,
                                    "open_gate": False,
                                    #"circuit": self._circuit,
                                    "defect_id": self._id_generator.generate_id(DefectType.SHORT),
                                    "defect_instance": f"{content.name}.{components[index].name}",
                                    "name": "short_model",
                                    "multiplier": str(int(m_param[1])),
                                    "weight": short_weight * int(m_param[1]),
                                    "collapsed": None,
                                    "merged": merged,
                                    "z_w_j": z_w_j,
                                    "n1": couple[0],
                                    "n2": couple[1],
                                }
                                defect_metadata.append(short_defect)

                            # Open
                            # Inject an open on every terminal with uniform weight. Bulk needs a reduced weight of 0.2 because it is the least likely defect.
                            # Gate open must be modeled as two separate defects (OpenModel and OpenGateModel), each with a weight of 0.5

                            # Drain
                            weight = 1.0
                            z_w_j = None

                            drain_open_defect = {
                                "No_2427_defect": no_2427_defect,
                                "component_category": category.value,
                                "defect_type": DefectType.OPEN,
                                "open_gate": False,
                                #"circuit": self._circuit,
                                "defect_id": self._id_generator.generate_id(DefectType.OPEN),
                                "defect_instance": f"{content.name}.{components[index].name}",
                                "name": "open_model",
                                "multiplier": str(int(m_param[1])),
                                "weight": weight * (int(m_param[1])),
                                "collapsed": None,
                                "merged": merged,
                                "z_w_j": z_w_j,
                                "n1": drain,
                                "n2": drain,
                            }
                            defect_metadata.append(drain_open_defect)

                            # Gate
                            weight = 0.5

                            gate_open_defect = {
                                "No_2427_defect": no_2427_defect,
                                "component_category": category.value,
                                "defect_type": DefectType.OPEN,
                                "open_gate": False,
                                #"circuit": self._circuit,
                                "defect_id": self._id_generator.generate_id(DefectType.OPEN),
                                "defect_instance": f"{content.name}.{components[index].name}",
                                "name": "open_model",
                                "multiplier": str(int(m_param[1])),
                                "weight": weight * int(m_param[1]),
                                "collapsed": None,
                                "merged": merged,
                                "z_w_j": z_w_j,
                                "n1": gate,
                                "n2": gate,
                            }
                            defect_metadata.append(gate_open_defect)

                            gate_open_gate_defect = {
                                "No_2427_defect": no_2427_defect,
                                "component_category": category.value,
                                "defect_type": DefectType.OPEN,
                                "open_gate": True,
                                #"circuit": self._circuit,
                                "defect_id": self._id_generator.generate_id(DefectType.OPEN),
                                "defect_instance": f"{content.name}.{components[index].name}",
                                "name": "open_model",
                                "multiplier": str(int(m_param[1])),
                                "weight": weight * int(m_param[1]),
                                "collapsed": None,
                                "merged": merged,
                                "z_w_j": z_w_j,
                                "d_node": drain,
                                "g_node": gate,
                                "s_node" : source,
                                "g_new_node" : f"{gate}_open"
                            }
                            defect_metadata.append(gate_open_gate_defect)

                            # Source
                            weight = 1.0

                            source_open_defect = {
                                "No_2427_defect": no_2427_defect,
                                "component_category": category.value,
                                "defect_type": DefectType.OPEN,
                                "open_gate": False,
                                #"circuit": self._circuit,
                                "defect_id": self._id_generator.generate_id(DefectType.OPEN),
                                "defect_instance": f"{content.name}.{components[index].name}",
                                "name": "open_model",
                                "multiplier": str(int(m_param[1])),
                                "weight": weight * int(m_param[1]),
                                "collapsed": None,
                                "merged": merged,
                                "z_w_j": z_w_j,
                                "n1": source,
                                "n2": source,
                            }
                            defect_metadata.append(source_open_defect)

                            # Bulk
                            weight = 0.2
                            z_w_j = None
                            if not self._manifest_data["include_bulk_opens"]:
                                weight = 0
                                z_w_j = "Since transistors share a common bulk, opens in the bulk connection are deemed reasonably unlikely and assigned a weight of 0, as indicated in the manifest file"

                            bulk_open_defect = {
                                "No_2427_defect": no_2427_defect,
                                "component_category": category.value,
                                "defect_type": DefectType.OPEN,
                                "open_gate": False,
                                #"circuit": self._circuit,
                                "defect_id": self._id_generator.generate_id(DefectType.OPEN),
                                "defect_instance": f"{content.name}.{components[index].name}",
                                "name": "open_model",
                                "multiplier": str(int(m_param[1])),
                                "weight": weight,     # Bulk is a shared elements, so its weight has not to be multiplied by M
                                "collapsed": None,
                                "merged": merged,
                                "z_w_j": z_w_j,
                                "n1": bulk,
                                "n2": bulk,
                            }
                            defect_metadata.append(bulk_open_defect)


                            # Parametric
                            parametric_defects_params = [w_param, l_param, vth0_param, tox_param]
                            suitable_params = []
                            for parameter in parameters:
                                if parameter[0].lower() in self.target_parameters["mosfet"]:
                                    suitable_params.append(parameter)

                            weight = 1.0
                            calculate_weight = True
                            for parameter in parameters:
                                # Check if parameter is marked as excluded
                                if len(self._excluded_target["parameters"]) > 0:
                                    for excluded_param in self._excluded_target["parameters"]:
                                        if excluded_param["name"] is not None and parameter[0].lower() == excluded_param["name"].lower():
                                            calculate_weight = False
                                            weight = 0
                                            z_w_j = f"Parameter {parameter[0]} is excluded from analysis by the manifest file"
                                            break

                                # Check if parameter is a parasitic element
                                if calculate_weight and parameter not in suitable_params:
                                    weight = 0
                                    if parameter[0].lower() != "m":
                                        z_w_j = "Nominal value is below the specified threshold for design-intent elements and is assumed to be a parasitic element"
                                    else:
                                        z_w_j = "Multiplier parameter"
                                # MIN
                                if parameter[0].lower() != "m":
                                    deviation_corner, pdk_corner_value_min = ComponentCategorizer.get_pdk_corner_value(category, "MIN", float(parameter[1]), parametric_defects_params)
                                else:
                                    deviation_corner = None
                                    pdk_corner_value_min = 0

                                if pdk_corner_value_min is not None:
                                    parametric_defect_min = {
                                        "No_2427_defect": no_2427_defect,
                                        "component_category": category.value,
                                        "defect_type": DefectType.PARAMETRIC,
                                        "open_gate": False,
                                        #"circuit": self._circuit,
                                        "defect_id": self._id_generator.generate_id(DefectType.PARAMETRIC),
                                        "defect_instance": f"{content.name}.{components[index].name}",
                                        "name": "MIN",
                                        "multiplier": str(int(m_param[1])),
                                        "weight": weight,
                                        "collapsed": None,
                                        "merged": merged,
                                        "z_w_j": z_w_j,
                                        "parameter_name": parameter[0],
                                        "typical_value": float(parameter[1]),
                                        "deviation_corner": deviation_corner,
                                        "pdk_corner_value": pdk_corner_value_min
                                    }
                                    defect_metadata.append(parametric_defect_min)

                                # MAX
                                if parameter[0].lower() != "m":
                                    deviation_corner, pdk_corner_value_max = ComponentCategorizer.get_pdk_corner_value(category, "MAX", float(parameter[1]), parametric_defects_params)
                                else:
                                    deviation_corner = None
                                    pdk_corner_value_max = 0

                                if pdk_corner_value_max is not None:
                                    parametric_defect_max = {
                                        "No_2427_defect": no_2427_defect,
                                        "component_category": category.value,
                                        "defect_type": DefectType.PARAMETRIC,
                                        #"circuit": self._circuit,
                                        "open_gate": False,
                                        "defect_id": self._id_generator.generate_id(DefectType.PARAMETRIC),
                                        "defect_instance": f"{content.name}.{components[index].name}",
                                        "name": "MAX",
                                        "multiplier": str(int(m_param[1])),
                                        "weight": weight,
                                        "collapsed": None,
                                        "merged": merged,
                                        "z_w_j": z_w_j,
                                        "parameter_name": parameter[0],
                                        "typical_value": float(parameter[1]),
                                        "deviation_corner": deviation_corner,
                                        "pdk_corner_value": pdk_corner_value_max
                                    }
                                    defect_metadata.append(parametric_defect_max)

                        else:
                            record = {
                                "No_2427_defect": no_2427_defect,
                                "component_category": category.value,
                                "defect_instance": f"{content.name}.{components[index].name}",
                                "z_w_j": z_w_j
                            }
                            defect_metadata.append(record)

                    elif category == ComponentCategory.DIODE:
                        # Get nodes
                        nodes = signatures[index][1]
                        # Ignore bulk terminal, if present
                        if len(nodes) > 2:
                            nodes = (nodes[0], nodes[1])

                        # Find parameters
                        parameters = signatures[index][2]
                        # Find area which is used to determine defect weight
                        area_param = None
                        m_param = None
                        for parameter in parameters:
                            if parameter[0].lower() == "area":
                                area_param = parameter
                            if parameter[0].lower() == "m":
                                m_param = parameter
                        if area_param is None:
                            print(f"[DefectEngine::process_defects] Area parameter not found for component {components[index].name}. Ignored from the defect universe\n")
                            continue
                        if m_param is None:
                            m_param = ("M", 1)

                        merged = None
                        merged = m_param[1]

                        # Short defect
                        if not no_2427_defect:
                            short_weight = math.sqrt(float(area_param[1]) / (1e-6 ** 2))
                            short_defect = {
                                "No_2427_defect": False,
                                "component_category": category.value,
                                "defect_type": DefectType.SHORT,
                                "open_gate": False,
                                #"circuit": self._circuit,
                                "defect_id": self._id_generator.generate_id(DefectType.SHORT),
                                "defect_instance": f"{content.name}.{components[index].name}",
                                "name": "short_model",
                                "multiplier": str(int(m_param[1])),
                                "weight": short_weight * int(m_param[1]),
                                "collapsed": None,
                                "merged": merged,
                                "z_w_j": z_w_j,
                                "n1": nodes[0],
                                "n2": nodes[1],
                            }
                            defect_metadata.append(short_defect)

                            # Open defect
                            open_weight = (1e-6 ** 2) / float(area_param[1])
                            open_defect = {
                                "No_2427_defect": False,
                                "component_category": category.value,
                                "defect_type": DefectType.OPEN,
                                "open_gate": False,
                                #"circuit": self._circuit,
                                "defect_id": self._id_generator.generate_id(DefectType.OPEN),
                                "defect_instance": f"{content.name}.{components[index].name}",
                                "name": "short_model",
                                "multiplier": str(int(m_param[1])),
                                "weight": short_weight * int(m_param[1]),
                                "collapsed": None,
                                "merged": merged,
                                "z_w_j": z_w_j,
                                "n1": nodes[0],
                                "n2": nodes[0],
                            }
                            defect_metadata.append(open_defect)

                            open_defect = {
                                "No_2427_defect": False,
                                "component_category": category.value,
                                "defect_type": DefectType.OPEN,
                                "open_gate": False,
                                #"circuit": self._circuit,
                                "defect_id": self._id_generator.generate_id(DefectType.OPEN),
                                "defect_instance": f"{content.name}.{components[index].name}",
                                "name": "short_model",
                                "multiplier": str(int(m_param[1])),
                                "weight": short_weight * int(m_param[1]),
                                "collapsed": None,
                                "merged": merged,
                                "z_w_j": z_w_j,
                                "n1": nodes[1],
                                "n2": nodes[1],
                            }
                            defect_metadata.append(open_defect)

                            # Parametric model
                            suitable_params = []
                            for parameter in parameters:
                                if parameter[0].lower() in self.target_parameters["diode"]:
                                    suitable_params.append(parameter)

                            weight = 1.0
                            calculate_weight = True
                            for parameter in parameters:
                                # Check if parameter is marked as excluded
                                for excluded_param in self._excluded_target["parameters"]:
                                    if excluded_param["name"] is not None and parameter[0].lower() == excluded_param[
                                        "name"].lower():
                                        calculate_weight = False
                                        weight = 0
                                        z_w_j = f"Parameter {parameter[0]} is excluded from analysis by the manifest file"
                                        break

                                # Check if parameter is a parasitic element
                                if calculate_weight and parameter not in suitable_params:
                                    weight = 0
                                    if parameter[0].lower() != "m":
                                        z_w_j = "Nominal value is below the specified threshold for design-intent elements and is assumed to be a parasitic element"
                                    else:
                                        z_w_j = "Multiplier parameter"

                                # For every parameter, both deviation directions have to be defined
                                # MIN
                                if parameter[0].lower() != "m":
                                    deviation_corner, pdk_corner_value_min = ComponentCategorizer.get_pdk_corner_value(category, "MIN", float(parameter[1]), None)
                                else:
                                    deviation_corner = None
                                    pdk_corner_value_min = 0

                                if pdk_corner_value_min is not None:
                                    parametric_defect_min = {
                                        "No_2427_defect": False,
                                        "component_category": category.value,
                                        "defect_type": DefectType.PARAMETRIC,
                                        "open_gate": False,
                                        #"circuit": self._circuit,
                                        "defect_id": self._id_generator.generate_id(DefectType.PARAMETRIC),
                                        "defect_instance": f"{content.name}.{components[index].name}",
                                        "name": "MIN",
                                        "multiplier": str(int(m_param[1])),
                                        "weight": weight,  # Parametric defects have uniform weight
                                        "collapsed": None,  # In this fase collapse is not considered
                                        "merged": merged,
                                        "z_w_j": z_w_j,
                                        "parameter_name": parameter[0],
                                        "typical_value": float(parameter[1]),
                                        "deviation_corner": deviation_corner,
                                        "pdk_corner_value": pdk_corner_value_min
                                    }
                                    defect_metadata.append(parametric_defect_min)

                                # MAX
                                if parameter[0].lower() != "m":
                                    deviation_corner, pdk_corner_value_max = ComponentCategorizer.get_pdk_corner_value(category, "MAX", float(parameter[1]), None)
                                else:
                                    deviation_corner = None
                                    pdk_corner_value_max = 0

                                if pdk_corner_value_max is not None:
                                    parametric_defect_max = {
                                        "No_2427_defect": False,
                                        "component_category": category.value,
                                        "defect_type": DefectType.PARAMETRIC,
                                        #"circuit": self._circuit,
                                        "open_gate": False,
                                        "defect_id": self._id_generator.generate_id(DefectType.PARAMETRIC),
                                        "defect_instance": f"{content.name}.{components[index].name}",
                                        "name": "MAX",
                                        "multiplier": str(int(m_param[1])),
                                        "weight": weight,
                                        "collapsed": None,
                                        "merged": merged,
                                        "z_w_j": z_w_j,
                                        "parameter_name": parameter[0],
                                        "typical_value": float(parameter[1]),
                                        "deviation_corner": deviation_corner,
                                        "pdk_corner_value": pdk_corner_value_max
                                    }
                                    defect_metadata.append(parametric_defect_max)

                        else:
                            record = {
                                "No_2427_defect": True,
                                "component_category": category.value,
                                "defect_instance": f"{content.name}.{components[index].name}",
                                # Maintaining 'z_w_j' key name for parsing reasons. 'rationale' would be more appropriate
                                "z_w_j": "Excluded from defect injection because this controlled source is an abstract mathematical modeling artifact with no physical layout realization on silicon"
                            }
                            defect_metadata.append(record)

                    elif category == ComponentCategory.VCCS or category == ComponentCategory.VCVS or category == ComponentCategory.CCVS or category == ComponentCategory.CCCS or category == ComponentCategory.CURRENT_SOURCE or category == ComponentCategory.VOLTAGE_SOURCE:
                        # Controlled sources (dependent) are considered to be a modeling artifacts and have to be marked as 'No_2427_defects'. Current source and voltage source follows the same rule since they are external components and, consequently, they are not part of the circuitry application
                        no_2427_defect = True
                        record = {
                            "No_2427_defect": no_2427_defect,
                            "component_category": category.value,
                            "defect_instance": f"{content.name}.{components[index].name}",
                            # Maintaining 'z_w_j' key name for parsing reasons. 'rationale' would be more appropriate
                            "z_w_j": "Excluded from defect injection because this controlled source is an abstract mathematical modeling artifact with no physical layout realization on silicon"
                        }
                        defect_metadata.append(record)


                    # MESFETS
                    elif category == ComponentCategory.MESFET:
                        # Get nodes
                        nodes = signatures[index][1]

                        # nodes order: D G S
                        drain = nodes[0]
                        gate = nodes[1]
                        source = nodes[2]
                        calculate_weight = True
                        short_weight = 0

                        # Find parameters
                        parameters = signatures[index][2]
                        m_param = None
                        area_param = None
                        w_param = None
                        l_param = None

                        for parameter in parameters:
                            if parameter[0].lower() == "m":
                                m_param = parameter
                            if parameter[0].lower() == "area":
                                area_param = parameter
                            if parameter[0].lower() == "w":
                                w_param = parameter
                            if parameter[0].lower() == "l":
                                l_param = parameter

                        if m_param is None:
                            m_param = ('M', 1)

                        # Get component master, if component is allowed to be analysed
                        if not no_2427_defect:
                            comp_master = signatures[index][0]
                            # Check if the component instance (through the component master) has to be excluded in reference of the manifest
                            excluded_contents = self._excluded_target["contents"]
                            for excl_cont in excluded_contents:
                                if comp_master == excl_cont["name"]:
                                    short_weight = 0
                                    z_w_j = f"{comp_master} component is excluded by the analysis as indicated in the manifest file"
                                    break

                        # Components merged during optimization
                        merged = None
                        merged = m_param[1]

                        if not no_2427_defect:

                            # Short
                            # All combinations of coupled-nodes for a 3-terminal MESFET: DG - DS - GS
                            coupled_nodes = ((drain, gate), (drain, source), (gate, source))
                            for couple in coupled_nodes:
                                calculate_weight = True
                                short_weight = 0
                                z_w_j = None

                                if calculate_weight and couple[0] == couple[1]:
                                    short_weight = 0
                                    z_w_j = "Short has a weight of 0 because terminals are nominally connected in the design"
                                    calculate_weight = False

                                if calculate_weight:
                                    if w_param is not None and l_param is not None:
                                        if couple[1] == gate or couple[0] == gate:
                                            short_weight = float(w_param[1])
                                        elif couple[0] == drain and couple[1] == source:
                                            if float(l_param[1]) > 2e-6:
                                                short_weight = 0
                                                z_w_j = "Source-drain shorts are assigned a weight of 0 in this design for transistors with gates longer than 2 µm, since defects larger than 1.5 µm are not considered reasonably likely"
                                            else:
                                                short_weight = (float(w_param[1]) / float(l_param[1])) * 0.35
                                    elif area_param is not None:
                                        short_weight = math.sqrt(float(area_param[1]) / (1e-6 ** 2))
                                    else:
                                        # Default fallback value precised by the standard
                                        short_weight = 1.0

                                short_defect = {
                                    "No_2427_defect": no_2427_defect,
                                    "component_category": category.value,
                                    "defect_type": DefectType.SHORT,
                                    "open_gate": False,
                                    # "circuit": self._circuit,
                                    "defect_id": self._id_generator.generate_id(DefectType.SHORT),
                                    "defect_instance": f"{content.name}.{components[index].name}",
                                    "name": "short_model",
                                    "multiplier": str(int(m_param[1])),
                                    "weight": short_weight * int(m_param[1]),
                                    "collapsed": None,
                                    "merged": merged,
                                    "z_w_j": z_w_j,
                                    "n1": couple[0],
                                    "n2": couple[1]
                                }
                                defect_metadata.append(short_defect)

                            # Open
                            # Inject an open on every terminal (Drain, Gate, Source) with uniform weight (MESFET has a Schottky junction gate, not an insulated oxide gate)
                            weight = 1.0
                            z_w_j = None

                            # Drain
                            drain_open_defect = {
                                "No_2427_defect": no_2427_defect,
                                "component_category": category.value,
                                "defect_type": DefectType.OPEN,
                                "open_gate": False,
                                # "circuit": self._circuit,
                                "defect_id": self._id_generator.generate_id(DefectType.OPEN),
                                "defect_instance": f"{content.name}.{components[index].name}",
                                "name": "open_model",
                                "multiplier": str(int(m_param[1])),
                                "weight": weight * int(m_param[1]),
                                "collapsed": None,
                                "merged": merged,
                                "z_w_j": z_w_j,
                                "n1": drain,
                                "n2": drain
                            }
                            defect_metadata.append(drain_open_defect)

                            # Gate
                            gate_open_defect = {
                                "No_2427_defect": no_2427_defect,
                                "component_category": category.value,
                                "defect_type": DefectType.OPEN,
                                "open_gate": False,
                                # "circuit": self._circuit,
                                "defect_id": self._id_generator.generate_id(DefectType.OPEN),
                                "defect_instance": f"{content.name}.{components[index].name}",
                                "name": "open_model",
                                "multiplier": str(int(m_param[1])),
                                "weight": weight * int(m_param[1]),
                                "collapsed": None,
                                "merged": merged,
                                "z_w_j": z_w_j,
                                "n1": gate,
                                "n2": gate
                            }
                            defect_metadata.append(gate_open_defect)

                            # Source
                            source_open_defect = {
                                "No_2427_defect": no_2427_defect,
                                "component_category": category.value,
                                "defect_type": DefectType.OPEN,
                                "open_gate": False,
                                # "circuit": self._circuit,
                                "defect_id": self._id_generator.generate_id(DefectType.OPEN),
                                "defect_instance": f"{content.name}.{components[index].name}",
                                "name": "open_model",
                                "multiplier": str(int(m_param[1])),
                                "weight": weight * int(m_param[1]),
                                "collapsed": None,
                                "merged": merged,
                                "z_w_j": z_w_j,
                                "n1": source,
                                "n2": source
                            }
                            defect_metadata.append(source_open_defect)

                            # Parametric
                            suitable_params = []
                            for parameter in parameters:
                                if parameter[0].lower() in self.target_parameters["mesfet"]:
                                    suitable_params.append(parameter)

                            weight = 1.0
                            calculate_weight = True

                            for parameter in parameters:
                                # Check if parameter is marked as excluded
                                if len(self._excluded_target["parameters"]) > 0:
                                    for excluded_param in self._excluded_target["parameters"]:
                                        if excluded_param["name"] is not None and parameter[0].lower() == \
                                                excluded_param["name"].lower():
                                            calculate_weight = False
                                            weight = 0
                                            z_w_j = f"Parameter {parameter[0]} is excluded from analysis by the manifest file"
                                            break

                                # Check if parameter is a parasitic element
                                if calculate_weight and parameter not in suitable_params:
                                    weight = 0

                                    if parameter[0].lower() != "m":
                                        z_w_j = "Nominal value is below the specified threshold for design-intent elements and is assumed to be a parasitic element"
                                    else:
                                        z_w_j = "Multiplier parameter"

                                # MIN
                                if parameter[0].lower() != "m":
                                    deviation_corner, pdk_corner_value_min = ComponentCategorizer.get_pdk_corner_value(category, "MIN", float(parameter[1]), None)
                                else:
                                    deviation_corner = None
                                    pdk_corner_value_min = 0

                                if pdk_corner_value_min is not None:
                                    parametric_defect_min = {
                                        "No_2427_defect": no_2427_defect,
                                        "component_category": category.value,
                                        "defect_type": DefectType.PARAMETRIC,
                                        "open_gate": False,
                                        # "circuit": self._circuit,
                                        "defect_id": self._id_generator.generate_id(DefectType.PARAMETRIC),
                                        "defect_instance": f"{content.name}.{components[index].name}",
                                        "name": "MIN",
                                        "multiplier": str(int(m_param[1])),
                                        "weight": weight,
                                        "collapsed": None,
                                        "merged": merged,
                                        "z_w_j": z_w_j,
                                        "parameter_name": parameter[0],
                                        "typical_value": float(parameter[1]),
                                        "deviation_corner": deviation_corner,
                                        "pdk_corner_value": pdk_corner_value_min
                                    }
                                    defect_metadata.append(parametric_defect_min)

                                # MAX
                                if parameter[0].lower() != "m":
                                    deviation_corner, pdk_corner_value_max = ComponentCategorizer.get_pdk_corner_value(category, "MAX", float(parameter[1]), None)
                                else:
                                    deviation_corner = None
                                    pdk_corner_value_max = 0

                                if pdk_corner_value_max is not None:
                                    parametric_defect_max = {
                                        "No_2427_defect": no_2427_defect,
                                        "component_category": category.value,
                                        "defect_type": DefectType.PARAMETRIC,
                                        # "circuit": self._circuit,
                                        "open_gate": False,
                                        "defect_id": self._id_generator.generate_id(DefectType.PARAMETRIC),
                                        "defect_instance": f"{content.name}.{components[index].name}",
                                        "name": "MAX",
                                        "multiplier": str(int(m_param[1])),
                                        "weight": weight,
                                        "collapsed": None,
                                        "merged": merged,
                                        "z_w_j": z_w_j,
                                        "parameter_name": parameter[0],
                                        "typical_value": float(parameter[1]),
                                        "deviation_corner": deviation_corner,
                                        "pdk_corner_value": pdk_corner_value_max
                                    }

                                    defect_metadata.append(parametric_defect_max)

                        else:
                            record = {
                                "No_2427_defect": no_2427_defect,
                                "component_category": category.value,
                                "defect_instance": f"{content.name}.{components[index].name}",
                                "z_w_j": z_w_j
                            }
                            defect_metadata.append(record)

                    # BJTS
                    elif category == ComponentCategory.BJT:
                        # Get nodes
                        nodes = signatures[index][1]

                        # nodes order: C B E [S]
                        collector = nodes[0]
                        base = nodes[1]
                        emitter = nodes[2]
                        substrate = nodes[3] if len(nodes) > 3 else None
                        calculate_weight = True
                        short_weight = 0

                        # Find parameters
                        parameters = signatures[index][2]
                        m_param = None
                        area_param = None

                        for parameter in parameters:
                            if parameter[0].lower() == "m":
                                m_param = parameter
                            if parameter[0].lower() == "area":
                                area_param = parameter

                        if m_param is None:
                            m_param = ('M', 1)

                        # Get component master, if component is allowed to be analysed
                        if not no_2427_defect:
                            comp_master = signatures[index][0]

                            # Check if the component instance (through the component master) has to be excluded in reference of the manifest
                            excluded_contents = self._excluded_target["contents"]
                            for excl_cont in excluded_contents:
                                if comp_master == excl_cont["name"]:
                                    short_weight = 0
                                    z_w_j = f"{comp_master} component is excluded by the analysis as indicated in the manifest file"
                                    break

                        # Components merged during optimization
                        merged = None
                        merged = m_param[1]

                        if not no_2427_defect:
                            # Short
                            # All combinations of coupled-nodes must be considered (3 shorts for 3-terminal BJT, 6 shorts if substrate is present)
                            if substrate is not None:
                                coupled_nodes = (
                                    (collector, base), (collector, emitter), (collector, substrate),
                                    (base, emitter), (base, substrate), (emitter, substrate)
                                )
                            else:
                                coupled_nodes = ((collector, base), (collector, emitter), (base, emitter))

                            for couple in coupled_nodes:
                                calculate_weight = True
                                short_weight = 0
                                z_w_j = None

                                if calculate_weight and couple[0] == couple[1]:
                                    short_weight = 0
                                    z_w_j = "Short has a weight of 0 because terminals are nominally connected in the design"
                                    calculate_weight = False

                                if calculate_weight:
                                    if substrate is not None and couple[1] == substrate:
                                        # Substrate short has uniform weight
                                        short_weight = 1.0
                                    elif area_param is not None:
                                        short_weight = math.sqrt(float(area_param[1]) / (1e-6 ** 2))
                                    else:
                                        # Default fallback value precised by the standard
                                        short_weight = 1.0

                                short_defect = {
                                    "No_2427_defect": no_2427_defect,
                                    "component_category": category.value,
                                    "defect_type": DefectType.SHORT,
                                    "open_gate": False,
                                    # "circuit": self._circuit,
                                    "defect_id": self._id_generator.generate_id(DefectType.SHORT),
                                    "defect_instance": f"{content.name}.{components[index].name}",
                                    "name": "short_model",
                                    "multiplier": str(int(m_param[1])),
                                    "weight": short_weight * int(m_param[1]),
                                    "collapsed": None,
                                    "merged": merged,
                                    "z_w_j": z_w_j,
                                    "n1": couple[0],
                                    "n2": couple[1]
                                }
                                defect_metadata.append(short_defect)

                            # Open
                            # Inject an open on every terminal. If area parameter is present, weight scales inversely with area, otherwise uniform weight (1.0)
                            if area_param is not None:
                                open_weight = (1e-6 ** 2) / float(area_param[1])
                            else:
                                open_weight = 1.0

                            z_w_j = None

                            # Collector
                            collector_open_defect = {
                                "No_2427_defect": no_2427_defect,
                                "component_category": category.value,
                                "defect_type": DefectType.OPEN,
                                "open_gate": False,
                                # "circuit": self._circuit,
                                "defect_id": self._id_generator.generate_id(DefectType.OPEN),
                                "defect_instance": f"{content.name}.{components[index].name}",
                                "name": "open_model",
                                "multiplier": str(int(m_param[1])),
                                "weight": open_weight * int(m_param[1]),
                                "collapsed": None,
                                "merged": merged,
                                "z_w_j": z_w_j,
                                "n1": collector,
                                "n2": collector
                            }
                            defect_metadata.append(collector_open_defect)

                            # Base
                            base_open_defect = {
                                "No_2427_defect": no_2427_defect,
                                "component_category": category.value,
                                "defect_type": DefectType.OPEN,
                                "open_gate": False,
                                # "circuit": self._circuit,
                                "defect_id": self._id_generator.generate_id(DefectType.OPEN),
                                "defect_instance": f"{content.name}.{components[index].name}",
                                "name": "open_model",
                                "multiplier": str(int(m_param[1])),
                                "weight": open_weight * int(m_param[1]),
                                "collapsed": None,
                                "merged": merged,
                                "z_w_j": z_w_j,
                                "n1": base,
                                "n2": base
                            }
                            defect_metadata.append(base_open_defect)

                            # Emitter
                            emitter_open_defect = {
                                "No_2427_defect": no_2427_defect,
                                "component_category": category.value,
                                "defect_type": DefectType.OPEN,
                                "open_gate": False,
                                # "circuit": self._circuit,
                                "defect_id": self._id_generator.generate_id(DefectType.OPEN),
                                "defect_instance": f"{content.name}.{components[index].name}",
                                "name": "open_model",
                                "multiplier": str(int(m_param[1])),
                                "weight": open_weight * int(m_param[1]),
                                "collapsed": None,
                                "merged": merged,
                                "z_w_j": z_w_j,
                                "n1": emitter,
                                "n2": emitter
                            }
                            defect_metadata.append(emitter_open_defect)

                            # Substrate (if present in the 4-terminal BJT signature)
                            if substrate is not None:
                                sub_weight = 0.2
                                z_w_j = None

                                if not self._manifest_data["include_bulk_opens"]:
                                    sub_weight = 0
                                    z_w_j = "Since transistors share a common substrate, opens in the substrate connection are deemed reasonably unlikely and assigned a weight of 0, as indicated in the manifest file"

                                substrate_open_defect = {
                                    "No_2427_defect": no_2427_defect,
                                    "component_category": category.value,
                                    "defect_type": DefectType.OPEN,
                                    "open_gate": False,
                                    # "circuit": self._circuit,
                                    "defect_id": self._id_generator.generate_id(DefectType.OPEN),
                                    "defect_instance": f"{content.name}.{components[index].name}",
                                    "name": "open_model",
                                    "multiplier": str(int(m_param[1])),
                                    "weight": sub_weight,                       # Substrate is a shared element, so its weight has not to be multiplied by M
                                    "collapsed": None,
                                    "merged": merged,
                                    "z_w_j": z_w_j,
                                    "n1": substrate,
                                    "n2": substrate
                                }
                                defect_metadata.append(substrate_open_defect)

                            # Parametric
                            suitable_params = []
                            for parameter in parameters:
                                if parameter[0].lower() in self.target_parameters["bjt"]:
                                    suitable_params.append(parameter)

                            weight = 1.0
                            calculate_weight = True

                            for parameter in parameters:
                                # Check if parameter is marked as excluded
                                if len(self._excluded_target["parameters"]) > 0:
                                    for excluded_param in self._excluded_target["parameters"]:
                                        if excluded_param["name"] is not None and parameter[0].lower() == excluded_param["name"].lower():
                                            calculate_weight = False
                                            weight = 0
                                            z_w_j = f"Parameter {parameter[0]} is excluded from analysis by the manifest file"
                                            break

                                # Check if parameter is a parasitic element
                                if calculate_weight and parameter not in suitable_params:
                                    weight = 0
                                    if parameter[0].lower() != "m":
                                        z_w_j = "Nominal value is below the specified threshold for design-intent elements and is assumed to be a parasitic element"
                                    else:
                                        z_w_j = "Multiplier parameter"

                                # MIN
                                if parameter[0].lower() != "m":
                                    deviation_corner, pdk_corner_value_min = ComponentCategorizer.get_pdk_corner_value(category, "MIN", float(parameter[1]), None)
                                else:
                                    deviation_corner = None
                                    pdk_corner_value_min = 0

                                if pdk_corner_value_min is not None:
                                    parametric_defect_min = {
                                        "No_2427_defect": no_2427_defect,
                                        "component_category": category.value,
                                        "defect_type": DefectType.PARAMETRIC,
                                        "open_gate": False,
                                        # "circuit": self._circuit,
                                        "defect_id": self._id_generator.generate_id(DefectType.PARAMETRIC),
                                        "defect_instance": f"{content.name}.{components[index].name}",
                                        "name": "MIN",
                                        "multiplier": str(int(m_param[1])),
                                        "weight": weight,
                                        "collapsed": None,
                                        "merged": merged,
                                        "z_w_j": z_w_j,
                                        "parameter_name": parameter[0],
                                        "typical_value": float(parameter[1]),
                                        "deviation_corner": deviation_corner,
                                        "pdk_corner_value": pdk_corner_value_min
                                    }
                                    defect_metadata.append(parametric_defect_min)

                                # MAX
                                if parameter[0].lower() != "m":
                                    deviation_corner, pdk_corner_value_max = ComponentCategorizer.get_pdk_corner_value(
                                        category, "MAX", float(parameter[1]), None)
                                else:
                                    deviation_corner = None
                                    pdk_corner_value_max = 0

                                if pdk_corner_value_max is not None:
                                    parametric_defect_max = {
                                        "No_2427_defect": no_2427_defect,
                                        "component_category": category.value,
                                        "defect_type": DefectType.PARAMETRIC,
                                        # "circuit": self._circuit,
                                        "open_gate": False,
                                        "defect_id": self._id_generator.generate_id(DefectType.PARAMETRIC),
                                        "defect_instance": f"{content.name}.{components[index].name}",
                                        "name": "MAX",
                                        "multiplier": str(int(m_param[1])),
                                        "weight": weight,
                                        "collapsed": None,
                                        "merged": merged,
                                        "z_w_j": z_w_j,
                                        "parameter_name": parameter[0],
                                        "typical_value": float(parameter[1]),
                                        "deviation_corner": deviation_corner,
                                        "pdk_corner_value": pdk_corner_value_max
                                    }
                                    defect_metadata.append(parametric_defect_max)

                        else:
                            record = {
                                "No_2427_defect": no_2427_defect,
                                "component_category": category.value,
                                "defect_instance": f"{content.name}.{components[index].name}",
                                "z_w_j": z_w_j
                            }

                            defect_metadata.append(record)

                    # JFETS
                    elif category == ComponentCategory.JFET:
                        # Get nodes
                        nodes = signatures[index][1]

                        # nodes order: D G S
                        drain = nodes[0]
                        gate = nodes[1]
                        source = nodes[2]

                        calculate_weight = True
                        short_weight = 0

                        # Find parameters
                        parameters = signatures[index][2]
                        m_param = None
                        area_param = None
                        w_param = None
                        l_param = None

                        for parameter in parameters:
                            if parameter[0].lower() == "m":
                                m_param = parameter
                            if parameter[0].lower() == "area":
                                area_param = parameter
                            if parameter[0].lower() == "w":
                                w_param = parameter
                            if parameter[0].lower() == "l":
                                l_param = parameter

                        if m_param is None:
                            m_param = ('M', 1)

                        # Get component master, if component is allowed to be analysed
                        if not no_2427_defect:
                            comp_master = signatures[index][0]

                            # Check if the component instance (through the component master) has to be excluded in reference of the manifest
                            excluded_contents = self._excluded_target["contents"]
                            for excl_cont in excluded_contents:
                                if comp_master == excl_cont["name"]:
                                    short_weight = 0
                                    z_w_j = f"{comp_master} component is excluded by the analysis as indicated in the manifest file"
                                    break

                        # Components merged during optimization
                        merged = None
                        merged = m_param[1]

                        if not no_2427_defect:
                            # Short
                            # All combinations of coupled-nodes for a 3-terminal JFET: DG - DS - GS
                            coupled_nodes = ((drain, gate), (drain, source), (gate, source))

                            for couple in coupled_nodes:
                                calculate_weight = True
                                short_weight = 0
                                z_w_j = None

                                if calculate_weight and couple[0] == couple[1]:
                                    short_weight = 0
                                    z_w_j = "Short has a weight of 0 because terminals are nominally connected in the design"
                                    calculate_weight = False

                                if calculate_weight:
                                    if w_param is not None and l_param is not None:
                                        if couple[1] == gate or couple[0] == gate:
                                            short_weight = float(w_param[1])
                                        elif couple[0] == drain and couple[1] == source:
                                            if float(l_param[1]) > 2e-6:
                                                short_weight = 0
                                                z_w_j = "Source-drain shorts are assigned a weight of 0 in this design for transistors with gates longer than 2 µm, since defects larger than 1.5 µm are not considered reasonably likely"
                                            else:
                                                short_weight = (float(w_param[1]) / float(l_param[1])) * 0.35
                                    elif area_param is not None:
                                        short_weight = math.sqrt(float(area_param[1]) / (1e-6 ** 2))
                                    else:
                                        # Default fallback value precised by the standard
                                        short_weight = 1.0

                                short_defect = {
                                    "No_2427_defect": no_2427_defect,
                                    "component_category": category.value,
                                    "defect_type": DefectType.SHORT,
                                    "open_gate": False,
                                    # "circuit": self._circuit,
                                    "defect_id": self._id_generator.generate_id(DefectType.SHORT),
                                    "defect_instance": f"{content.name}.{components[index].name}",
                                    "name": "short_model",
                                    "multiplier": str(int(m_param[1])),
                                    "weight": short_weight * int(m_param[1]),
                                    "collapsed": None,
                                    "merged": merged,
                                    "z_w_j": z_w_j,
                                    "n1": couple[0],
                                    "n2": couple[1]
                                }
                                defect_metadata.append(short_defect)

                            # Open
                            # Inject an open on every terminal (Drain, Gate, Source) with uniform weight (JFET has a PN-junction gate, not an insulated oxide gate)
                            weight = 1.0
                            z_w_j = None

                            # Drain
                            drain_open_defect = {
                                "No_2427_defect": no_2427_defect,
                                "component_category": category.value,
                                "defect_type": DefectType.OPEN,
                                "open_gate": False,
                                # "circuit": self._circuit,
                                "defect_id": self._id_generator.generate_id(DefectType.OPEN),
                                "defect_instance": f"{content.name}.{components[index].name}",
                                "name": "open_model",
                                "multiplier": str(int(m_param[1])),
                                "weight": weight * int(m_param[1]),
                                "collapsed": None,
                                "merged": merged,
                                "z_w_j": z_w_j,
                                "n1": drain,
                                "n2": drain
                            }
                            defect_metadata.append(drain_open_defect)

                            # Gate
                            gate_open_defect = {
                                "No_2427_defect": no_2427_defect,
                                "component_category": category.value,
                                "defect_type": DefectType.OPEN,
                                "open_gate": False,
                                # "circuit": self._circuit,
                                "defect_id": self._id_generator.generate_id(DefectType.OPEN),
                                "defect_instance": f"{content.name}.{components[index].name}",
                                "name": "open_model",
                                "multiplier": str(int(m_param[1])),
                                "weight": weight * int(m_param[1]),
                                "collapsed": None,
                                "merged": merged,
                                "z_w_j": z_w_j,
                                "n1": gate,
                                "n2": gate
                            }
                            defect_metadata.append(gate_open_defect)

                            # Source
                            source_open_defect = {
                                "No_2427_defect": no_2427_defect,
                                "component_category": category.value,
                                "defect_type": DefectType.OPEN,
                                "open_gate": False,
                                # "circuit": self._circuit,
                                "defect_id": self._id_generator.generate_id(DefectType.OPEN),
                                "defect_instance": f"{content.name}.{components[index].name}",
                                "name": "open_model",
                                "multiplier": str(int(m_param[1])),
                                "weight": weight * int(m_param[1]),
                                "collapsed": None,
                                "merged": merged,
                                "z_w_j": z_w_j,
                                "n1": source,
                                "n2": source
                            }
                            defect_metadata.append(source_open_defect)

                            # Parametric
                            suitable_params = []
                            for parameter in parameters:
                                if parameter[0].lower() in self.target_parameters["jfet"]:
                                    suitable_params.append(parameter)

                            weight = 1.0
                            calculate_weight = True

                            for parameter in parameters:
                                # Check if parameter is marked as excluded
                                if len(self._excluded_target["parameters"]) > 0:
                                    for excluded_param in self._excluded_target["parameters"]:
                                        if excluded_param["name"] is not None and parameter[0].lower() == excluded_param["name"].lower():
                                            calculate_weight = False
                                            weight = 0
                                            z_w_j = f"Parameter {parameter[0]} is excluded from analysis by the manifest file"
                                            break

                                # Check if parameter is a parasitic element
                                if calculate_weight and parameter not in suitable_params:
                                    weight = 0
                                    if parameter[0].lower() != "m":
                                        z_w_j = "Nominal value is below the specified threshold for design-intent elements and is assumed to be a parasitic element"
                                    else:
                                        z_w_j = "Multiplier parameter"

                                # MIN
                                if parameter[0].lower() != "m":
                                    deviation_corner, pdk_corner_value_min = ComponentCategorizer.get_pdk_corner_value(
                                        category, "MIN", float(parameter[1]), None)
                                else:
                                    deviation_corner = None
                                    pdk_corner_value_min = 0

                                if pdk_corner_value_min is not None:
                                    parametric_defect_min = {
                                        "No_2427_defect": no_2427_defect,
                                        "component_category": category.value,
                                        "defect_type": DefectType.PARAMETRIC,
                                        "open_gate": False,
                                        # "circuit": self._circuit,
                                        "defect_id": self._id_generator.generate_id(DefectType.PARAMETRIC),
                                        "defect_instance": f"{content.name}.{components[index].name}",
                                        "name": "MIN",
                                        "multiplier": str(int(m_param[1])),
                                        "weight": weight,
                                        "collapsed": None,
                                        "merged": merged,
                                        "z_w_j": z_w_j,
                                        "parameter_name": parameter[0],
                                        "typical_value": float(parameter[1]),
                                        "deviation_corner": deviation_corner,
                                        "pdk_corner_value": pdk_corner_value_min
                                    }
                                    defect_metadata.append(parametric_defect_min)

                                # MAX
                                if parameter[0].lower() != "m":
                                    deviation_corner, pdk_corner_value_max = ComponentCategorizer.get_pdk_corner_value(
                                        category, "MAX", float(parameter[1]), None)
                                else:
                                    deviation_corner = None
                                    pdk_corner_value_max = 0

                                if pdk_corner_value_max is not None:
                                    parametric_defect_max = {
                                        "No_2427_defect": no_2427_defect,
                                        "component_category": category.value,
                                        "defect_type": DefectType.PARAMETRIC,
                                        # "circuit": self._circuit,
                                        "open_gate": False,
                                        "defect_id": self._id_generator.generate_id(DefectType.PARAMETRIC),
                                        "defect_instance": f"{content.name}.{components[index].name}",
                                        "name": "MAX",
                                        "multiplier": str(int(m_param[1])),
                                        "weight": weight,
                                        "collapsed": None,
                                        "merged": merged,
                                        "z_w_j": z_w_j,
                                        "parameter_name": parameter[0],
                                        "typical_value": float(parameter[1]),
                                        "deviation_corner": deviation_corner,
                                        "pdk_corner_value": pdk_corner_value_max
                                    }
                                    defect_metadata.append(parametric_defect_max)

                        else:
                            record = {
                                "No_2427_defect": no_2427_defect,
                                "component_category": category.value,
                                "defect_instance": f"{content.name}.{components[index].name}",
                                "z_w_j": z_w_j
                            }
                            defect_metadata.append(record)

                    else:
                        print(f"[DefectEngine::process_defect] Category {category.value} is still under development. Component {components[index].name} has been excluded from defect injection")

                    index += 1
                defect_universe_raw[content.name] = defect_metadata

        print("[DefectEngine::process_defect] Analysis completed")
        return defect_universe_raw


    # Defect builder: generates a defect object from the defect metadata
    @classmethod
    def defect_builder(cls, defect_data : dict):
        if not defect_data["No_2427_defect"] and defect_data["weight"] > 0:
            if defect_data["defect_type"] == DefectType.SHORT:
                return ShortModel(
                    defect_data["defect_id"],
                    defect_data["component_category"],
                    defect_data["defect_instance"],
                    defect_data["name"],
                    defect_data["multiplier"],
                    defect_data["weight"],
                    defect_data["collapsed"],
                    defect_data["merged"],
                    defect_data["z_w_j"],
                    defect_data["n1"],
                    defect_data["n2"]
                )

            elif defect_data["defect_type"] == DefectType.OPEN:
                if defect_data["open_gate"]:
                    return OpenGateModel(
                        defect_data["defect_id"],
                        defect_data["component_category"],
                        defect_data["defect_instance"],
                        defect_data["name"],
                        defect_data["multiplier"],
                        defect_data["weight"],
                        defect_data["collapsed"],
                        defect_data["merged"],
                        defect_data["z_w_j"],
                        defect_data["d_node"],
                        defect_data["g_node"],
                        defect_data["s_node"],
                        defect_data["g_new_node"],
                    )

                else:
                    return OpenModel(
                        defect_data["defect_id"],
                        defect_data["component_category"],
                        defect_data["defect_instance"],
                        defect_data["name"],
                        defect_data["multiplier"],
                        defect_data["weight"],
                        defect_data["collapsed"],
                        defect_data["merged"],
                        defect_data["z_w_j"],
                        defect_data["n1"],
                        defect_data["n2"]
                    )

            elif defect_data["defect_type"] == DefectType.PARAMETRIC:
                return ParametricModel(
                    defect_data["defect_id"],
                    defect_data["component_category"],
                    defect_data["defect_instance"],
                    defect_data["name"],
                    defect_data["multiplier"],
                    defect_data["weight"],
                    defect_data["collapsed"],
                    defect_data["merged"],
                    defect_data["z_w_j"],
                    defect_data["parameter_name"],
                    defect_data["typical_value"],
                    defect_data["pdk_corner_value"]
                )


    # Generate defects object
    def generate_defect_universe(self):
        print("[DefectEngine::generate_defect_universe] Generating defect universe ...")

        defect_universe = []

        self._universe_details = self._optimizer.optimize_collapse(self._universe_details)

        for data in self._universe_details:
            for def_data in self._universe_details[data]:
                defect_obj = self.defect_builder(def_data)
                if defect_obj is not None:
                    defect_universe.append(defect_obj)

        print("[DefectEngine::generate_defect_universe] Universe generated")
        return defect_universe


    # Get universe details
    def get_universe_details(self):
        return self._universe_details
