/// @file spectre_backend.cpp
/// @brief Backend for generating SPECTRE netlists.
/// @details This file implements the SpectreBackend class, which generates
/// Spectre netlists from the internal representation of circuits.
/// @date 2025-04-14

#include "edacurry/backend/spectre_backend.hpp"
#include "edacurry/classes.hpp"

#include <iostream>

namespace edacurry::backend
{

SpectreBackend::SpectreBackend()
    : ss(4, ' ')
{
    // Nothing to do.
}

int SpectreBackend::visitCircuit(const std::shared_ptr<structure::Circuit> &e)
{
    // If the IR labels top-level as "spectre_top", treat that as the global netlist
    if (e->getName() == "spectre_top") {
        ss << "simulator lang=spectre\n";
        // If the circuit has a title, print it at top-level
        if (!e->getTitle().empty()) {
            ss << e->getTitle() << "\n";
        }

        // If the circuit has global nodes, emit them
        if (!e->nodes.empty()) {
            ss << "global";
            for (auto &node : e->nodes) {
                ss << " " << node->getName();
            }
            ss << "\n";
        }

        // If the circuit has any parameters, emit them as "parameters …" (Spectre format)
        if (e->parameters) {
            ss << "parameters";
            for (auto &param : e->parameters) {
                ss << ' ';
                param->accept(this);
            }
            ss << "\n";
        }

        // Visit all child objects (subcircuits, components, analyses, etc.)
        for (auto &obj : e->content) {
            obj->accept(this);
        }
        return 0;
    }

    // Otherwise, treat this circuit as a Spectre subckt
    ss << "subckt " << e->getName();
    for (auto &node : e->nodes) {
        ss << ' ';
        node->accept(this);
    }
    ss << '\n';

    ss << ind_increase;
    // If the subckt has parameters, you can emit them
    if (e->parameters) {
        ss << "parameters ";
        bool first = true;
        for (auto &param : e->parameters) {
            if (!first) ss << ' ';
            param->accept(this);
            first = false;
        }
        ss << '\n';
    }

    // Subckt internals
    for (auto &obj : e->content) {
        obj->accept(this);
    }

    ss << ind_decrease;
    ss << "ends " << e->getName() << "\n";
    return 0;
}

int SpectreBackend::visitAnalysis(const std::shared_ptr<structure::Analysis> &e)
{
    // Check for special analysis types that need specific formatting
    if ((e->getName() == "ac_parameter_driven") || (e->getName() == "ac_data_driven") || (e->getName() == "ac_list_driven") || (e->getName() == "ac_adaptive")) {
        ss << ".ac";
    } else if ((e->getName() == "tran_point_driven") || (e->getName() == "tran_parameterized") || (e->getName() == "tran_data_driven")) {
        ss << ".tran";
    } else {
        // Generic Spectre analysis: name analysisType param=value ...
        // For "info" type analyses like "dcOpInfo info what=oppoint"
        ss << e->getName() << " info";
    }
    for (const auto &parameter : e->parameters) {
        ss << ' ';
        parameter->accept(this);
    }
    ss << '\n';
    return 0;
}

int SpectreBackend::visitComponent(const std::shared_ptr<structure::Component> &e)
{
    ss << e->getName(); // Component name (e.g., r1, r2)
    
    if (e->nodes) {
        ss << " ("; // Start parentheses for node connections
        for (size_t i = 0; i < e->nodes.size(); ++i) {
            if (i > 0) {
                ss << " "; // Add space between nodes
            }
            e->nodes[i]->accept(this); // Visit each node
        }
        ss << ")"; // Close parentheses
    }

    
    if (!e->getMaster().empty()) {
        ss << " " << e->getMaster(); // Add the master name if it is defined
    } 
    // Resistor handling
    else if (!e->getName().empty() && (e->getName().front() == 'r' || e->getName().front() == 'R')) {
        // If the component name starts with 'r' or 'R', treat it as a resistor
        // In this case, the master name was not specified, so we use the 
        // component name to derive the component type
        ss << " resistor";
    }
    // Capacitor handling
    else if (!e->getName().empty() && (e->getName().front() == 'c' || e->getName().front() == 'C')) {
        // If the component name starts with 'c' or 'C', treat it as a resistor
        // In this case, the master name was not specified, so we use the 
        // component name to derive the component type
        ss << " capacitor";
    }

    if (e->parameters) {
        for (const auto &parameter : e->parameters) {
            ss << ' ';
            parameter->accept(this);
        }
    }

    ss << '\n'; // End the line
    return 0;
}

int SpectreBackend::visitControlScope(const std::shared_ptr<structure::ControlScope> &e)
{
    if (e->getControlType() == ctrl_altergroup) {
        ss << ".alter " << e->getName() << "\n";
        ss << ind_increase;
        for (const auto &parameter : e->parameters) {
            ss << ".param ";
            parameter->accept(this);
            ss << '\n';
        }
        for (auto it : e->content) {
            it->accept(this);
        }
        ss << ind_decrease;
        ss << ".end\n";
    }
    return 0;
}

int SpectreBackend::visitControl(const std::shared_ptr<structure::Control> &e)
{
    if (e->getControlType() == ctrl_option) {
        // Spectre format: name options param=value ...
        if (!e->getName().empty())
            ss << e->getName() << " options";
        else
            ss << "options";
    } else if (e->getControlType() == ctrl_save) {
        ss << "save";
    } else if (e->getControlType() == ctrl_print) {
        ss << ".print";
    } else if (e->getControlType() == ctrl_plot) {
        ss << ".plot";
    } else if (e->getControlType() == ctrl_probe) {
        ss << ".probe";
    } else if (e->getControlType() == ctrl_temp) {
        ss << ".temp";
    } else if (e->getControlType() == ctrl_meas) {
        ss << ".meas";
    }

    for (const auto &parameter : e->parameters) {
        ss << ' ';
        parameter->accept(this);
    }
    ss << '\n';
    return 0;
}

int SpectreBackend::visitExpressionUnary(const std::shared_ptr<structure::ExpressionUnary> &e)
{
    ss << operator_to_string(e->getOperator());
    if (e->getValue()) {
        e->getValue()->accept(this);
    }
    return 0;
}

int SpectreBackend::visitExpression(const std::shared_ptr<structure::Expression> &e)
{
    if (e->getFirst()) {
        e->getFirst()->accept(this);
        ss << ' ';
    }
    ss << operator_to_string(e->getOperator());
    if (e->getSecond()) {
        ss << ' ';
        e->getSecond()->accept(this);
    }
    return 0;
}

int SpectreBackend::visitFunctionCall(const std::shared_ptr<structure::FunctionCall> &e)
{
    ss << e->getName() << '(';
    if (e->parameters) {
        size_t size = e->parameters.size(), i = 0;
        for (const auto &parameter : e->parameters) {
            parameter->accept(this);
            if (i++ < (size - 1))
                ss << ", ";
        }
    }
    ss << ')';
    return 0;
}

int SpectreBackend::visitIdentifier(const std::shared_ptr<structure::Identifier> &e)
{
    if (!e->getName().empty())
        ss << e->getName();
    return 0;
}

int SpectreBackend::visitInclude(const std::shared_ptr<structure::Include> &e)
{
    ss << "include \"" << e->getPath() << "\"";
    // Emit include parameters (like section=tt)
    for (const auto &param : e->parameters) {
        ss << ' ';
        param->accept(this);
    }
    ss << "\n";
    return 0;
}

int SpectreBackend::visitLibraryDef(const std::shared_ptr<structure::LibraryDef> &e)
{
    return features::BaseVisitor::visitLibraryDef(e);
}

int SpectreBackend::visitLibrary(const std::shared_ptr<structure::Library> &e)
{
    return features::BaseVisitor::visitLibrary(e);
}

int SpectreBackend::visitModel(const std::shared_ptr<structure::Model> &e)
{
    ss << "model " << e->getName() << " " << e->getMaster();
    for (const auto &parameter : e->parameters) {
        ss << ' ';
        parameter->accept(this);
    }
    ss << "\n";
    return 0;
}

int SpectreBackend::visitNode(const std::shared_ptr<structure::Node> &e)
{
    ss << e->getName();
    return 0;
}

int SpectreBackend::visitUnsigned(const std::shared_ptr<structure::Number<unsigned>> &e)
{
    ss << e->getValue();
    if (!e->getUnit().empty())
        ss << e->getUnit();
    return 0;
}

int SpectreBackend::visitInt(const std::shared_ptr<structure::Number<int>> &e)
{
    ss << e->getValue();
    if (!e->getUnit().empty())
        ss << e->getUnit();
    return 0;
}

int SpectreBackend::visitDouble(const std::shared_ptr<structure::Number<double>> &e)
{
    ss << e->getValue();
    if (!e->getUnit().empty())
        ss << e->getUnit();
    return 0;
}

int SpectreBackend::visitParameter(const std::shared_ptr<structure::Parameter> &e)
{
    if ((e->getType() == param_assign) || (e->getType() == param_arithmetic)) {
        if (e->getLeft() && !e->getHideName())
            e->getLeft()->accept(this);
        if (e->getRight()) {
            if (e->getLeft() && !e->getHideName())
                ss << '=';
            if (e->getType() == param_arithmetic)
                ss << '{';
            e->getRight()->accept(this);
            if (e->getType() == param_arithmetic)
                ss << '}';
        }
    } else if (e->getType() == param_tabular) {
        ss << "table ";
        auto table = std::dynamic_pointer_cast<const structure::ValueList>(e->getRight());
        if (table && (table->values.size() >= 2)) {
            for (size_t i = 0; i < table->values.size(); ++i) {
                table->values[i]->accept(this);
                if (i == 0)
                    ss << '=';
                else
                    ss << ' ';
            }
        }
    } else if (e->getType() == param_list) {
        if (e->getLeft())
            e->getLeft()->accept(this);
        ss << "(";
        auto table = std::dynamic_pointer_cast<const structure::ValueList>(e->getRight());
        for (size_t i = 0; table && (i < table->values.size()); ++i) {
            table->values[i]->accept(this);
            if (i < (table->values.size() - 1))
                ss << ' ';
        }
        ss << ')';
    } else if (e->getType() == param_no_equal) {
        if (e->getLeft())
            e->getLeft()->accept(this);
        if (e->getRight()) {
            if (e->getLeft())
                ss << " ";
            e->getRight()->accept(this);
        }
    }
    return 0;
}

int SpectreBackend::visitSubckt(const std::shared_ptr<structure::Subckt> &e)
{
    // “subckt” with name and node list
    ss << "subckt " << e->getName();
    for (const auto &node : e->nodes) {
        ss << ' ';
        node->accept(this);
    }
    ss << '\n';

    ss << ind_increase;

    // If the subckt has any parameters, you can emit them
    if (!e->parameters.empty()) {
        ss << "parameters ";
        bool first = true;
        for (const auto &parameter : e->parameters) {
            if (!first) ss << ' ';
            parameter->accept(this);
            first = false;
        }
        ss << '\n';
    }

    // Subckt internals
    for (const auto &entry : e->content) {
        entry->accept(this);
    }

    ss << ind_decrease;
    // “ends subcktName”
    ss << "ends " << e->getName() << '\n';
    return 0;
}

int SpectreBackend::visitString(const std::shared_ptr<structure::String> &e)
{
    // Add quotes around string values for Spectre format
    ss << '"' << e->getString() << '"';
    return 0;
}

int SpectreBackend::visitValuePair(const std::shared_ptr<structure::ValuePair> &e)
{
    if (e->getFirst()) {
        e->getFirst()->accept(this);
    }
    ss << ',';
    if (e->getSecond()) {
        e->getSecond()->accept(this);
    }
    return 0;
}

int SpectreBackend::visitValueList(const std::shared_ptr<structure::ValueList> &e)
{
    ss << delimiter_type_open_char(e->getDelimiterType());
    if (e->values) {
        size_t size = e->values.size(), i = 0;
        for (const auto &value : e->values) {
            value->accept(this);
            if (i++ < (size - 1)) {
                // In Spectre, array elements (square brackets) are space-separated
                if (e->getDelimiterType() == DelimiterType::dlm_square)
                    ss << " ";
                else
                    ss << ", ";
            }
        }
    }
    ss << delimiter_type_close_char(e->getDelimiterType());
    return 0;
}

std::string write_spectre(const std::shared_ptr<structure::Object> &object)
{
    if (!object) {
        std::cerr << "write_spectre: provided object is null (parsing failed)" << std::endl;
        return std::string("");
    }
    edacurry::backend::SpectreBackend backend;
    object->accept(&backend);
    return backend.str();
}

} // namespace edacurry::backend