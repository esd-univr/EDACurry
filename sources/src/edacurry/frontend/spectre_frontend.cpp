#include <iostream>
#include "edacurry/frontend/spectre_frontend.hpp"
#include "edacurry/utility/logging.hpp"
#include "edacurry/utility/utility.hpp"
#include "edacurry/classes.hpp"
#include "edacurry/enums.hpp"
#include <cctype>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <unistd.h>

#include "antlr4parser/SPECTREParser.h"
#include "antlr4parser/SPECTRELexer.h"

using antlrcpp::Any;
using namespace std;

#define TRACE_VISIT(name) std::cerr << "[TRACE] Visiting " << name << " : " << (ctx ? ctx->getText().substr(0, 50) : "null") << std::endl;

namespace edacurry::frontend {

/// @brief Strips quotes from the beginning and end of a string.
std::string strip_quotes(const std::string &s)
{
    if (s.length() >= 2) {
        if ((s.front() == '"' && s.back() == '"') || (s.front() == '\'' && s.back() == '\''))
            return s.substr(1, s.length() - 2);
    }
    return s;
}

/// @brief Converts a filepath context to a string.
std::string to_string(SPECTREParser::FilepathContext *ctx)
{
    if (ctx == nullptr) return "";
    return strip_quotes(ctx->getText());
}

/// @brief Parses a terminal node representing a number with an optional SI unit suffix.
std::shared_ptr<structure::Value> to_number(antlr4::tree::TerminalNode *ctx, Factory &factory)
{
    if (!ctx) return nullptr;
    std::string s = ctx->getText();
    if (s.empty()) return nullptr;

    try {
        size_t processed_chars = 0;
        double value = std::stod(s, &processed_chars);
        
        if (processed_chars < s.length()) {
            std::string suffix = s.substr(processed_chars);
            if (utility::to_lower(suffix) == "meg") {
                value *= 1e6;
            } else if (!suffix.empty()) {
                char prefix = suffix[0];
                if (prefix == 'm') {
                    value *= 1e-3;
                } else if (prefix == 'M') {
                    value *= 1e6;
                } else {
                    switch (std::toupper(prefix)) {
                        case 'T': value *= 1e12; break;
                        case 'G': value *= 1e9; break;
                        case 'K': value *= 1e3; break;
                        case 'U': value *= 1e-6; break;
                        case 'N': value *= 1e-9; break;
                        case 'P': value *= 1e-12; break;
                        case 'F': value *= 1e-15; break;
                    }
                }
            }
        }
        return factory.number<double>(value);
    } catch (...) {
        return nullptr;
    }
}

/// @brief Converts an operator string to its corresponding Operator enum.
Operator to_operator_internal(const std::string &op_str)
{
    static const std::map<std::string, Operator> op_map = {
        { "+", Operator::op_plus }, { "-", Operator::op_minus },
        { "*", Operator::op_mult }, { "/", Operator::op_div },
        { "%", Operator::op_mod }, { "==", Operator::op_eq },
        { "!=", Operator::op_neq }, { "<", Operator::op_lt },
        { "<=", Operator::op_le }, { ">", Operator::op_gt },
        { ">=", Operator::op_ge }, { "&&", Operator::op_and },
        { "||", Operator::op_or }, { "!", Operator::op_not },
        { "&", Operator::op_band }, { "|", Operator::op_bor },
        { "^", Operator::op_xor }, { "<<", Operator::op_bsl }, 
        { ">>", Operator::op_bsr }
    };
    auto it = op_map.find(op_str);
    if (it != op_map.end()) {
        return it->second;
    }
    std::string lower_op = utility::to_lower(op_str);
    if (lower_op == "and") return Operator::op_and;
    if (lower_op == "or") return Operator::op_or;
    if (lower_op == "not") return Operator::op_not;
    throw std::runtime_error("Unknown operator: " + op_str);
}

/// @brief Converts a binary operator context to an Operator enum.
Operator to_operator(SPECTREParser::Expression_operatorContext *ctx)
{
    return to_operator_internal(ctx->getText());
}

/// @brief Converts a unary operator context to an Operator enum.
Operator to_operator(SPECTREParser::Expression_unaryContext *ctx)
{
    return to_operator_internal(ctx->children[0]->getText());
}

SPECTREFrontend::SPECTREFrontend(antlr4::CommonTokenStream &_tokens)
    : tokens(_tokens), _stack(), _root(), _factory() {}

/// === Top-level netlist and hierarchy ===
Any SPECTREFrontend::visitNetlist(SPECTREParser::NetlistContext *ctx) {
    auto circuit = _factory.circuit("spectre_top", "");
    _root = circuit;
    this->push(circuit);
    visitChildren(ctx);
    this->pop();
    return circuit;
}

Any SPECTREFrontend::visitNetlist_title(SPECTREParser::Netlist_titleContext *ctx) {
    if (auto circuit = utility::to<structure::Circuit>(back()))
        circuit->setTitle(ctx->getText());
    return Any();
}

Any SPECTREFrontend::visitNetlist_entity(SPECTREParser::Netlist_entityContext *ctx) { return visitChildren(ctx); }

/// === Include ===
Any SPECTREFrontend::visitInclude(SPECTREParser::IncludeContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitStandard_include(SPECTREParser::Standard_includeContext *ctx) {
    return this->advance_visit(ctx, _factory.include(IncludeType::inc_standard, to_string(ctx->filepath())));
}
Any SPECTREFrontend::visitCpp_include(SPECTREParser::Cpp_includeContext *ctx) {
    return this->advance_visit(ctx, _factory.include(IncludeType::inc_cpp, to_string(ctx->filepath())));
}

Any SPECTREFrontend::visitAhdl_include(SPECTREParser::Ahdl_includeContext *ctx) {
    return this->advance_visit(ctx, _factory.include(IncludeType::inc_ahdl, to_string(ctx->filepath())));
}

/// === Language ===
Any SPECTREFrontend::visitLang(SPECTREParser::LangContext *ctx) {
    if (!ctx->ID()) {
        // Gracefully skip or handle "simulator lang=..." if the grammar didn't match
        return visitChildren(ctx);
    }
    // Otherwise proceed as before
    return this->advance_visit(ctx, _factory.control(ctx->ID()->getText(), ControlType::ctrl_none));
}

/// === Library ===
Any SPECTREFrontend::visitLibrary(SPECTREParser::LibraryContext *ctx) {
    std::string name = ctx->library_header()->ID()->getText();
    return this->advance_visit(ctx, _factory.library(name, ""));
}

Any SPECTREFrontend::visitLibrary_header(SPECTREParser::Library_headerContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitLibrary_content(SPECTREParser::Library_contentContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitLibrary_footer(SPECTREParser::Library_footerContext *ctx) { return visitChildren(ctx); }

/// === Subcircuit ===
Any SPECTREFrontend::visitSubckt(SPECTREParser::SubcktContext *ctx) {
    std::string name = ctx->subckt_header()->ID()->getText();
    return this->advance_visit(ctx, _factory.circuit(name, "subckt"));
}

Any SPECTREFrontend::visitSubckt_header(SPECTREParser::Subckt_headerContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitSubckt_content(SPECTREParser::Subckt_contentContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitSubckt_footer(SPECTREParser::Subckt_footerContext *ctx) { return visitChildren(ctx); }

/// === Model ===
Any SPECTREFrontend::visitModel(SPECTREParser::ModelContext *ctx)
{
    // model name master [param=val …]
    auto name       = ctx->model_name()->getText();
    auto masterText = ctx->model_master()->getText();
    // Call the 4-arg model(name, master, library, library_type)
    auto modelNode  = _factory.model(name, masterText, /*lib=*/"", /*libtype=*/"");

    // Insert into AST and descend
    add_to_parent(modelNode);
    push(modelNode);

    // Only visit the parameter_assign children
    for (auto paCtx : ctx->parameter_assign()) {
        visit(paCtx);
    }

    pop();
    return modelNode;
}

Any SPECTREFrontend::visitModel_name(SPECTREParser::Model_nameContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitModel_master(SPECTREParser::Model_masterContext *ctx) { return visitChildren(ctx); }

/// === Analysis ===
Any SPECTREFrontend::visitAnalysis(SPECTREParser::AnalysisContext *ctx) {
    return visitChildren(ctx);
}

Any SPECTREFrontend::visitAnalysis_type(SPECTREParser::Analysis_typeContext *ctx) { return visitChildren(ctx); }

/// === Component ===
Any SPECTREFrontend::visitComponent(SPECTREParser::ComponentContext* ctx) {
    std::string id = ctx->component_id()->getText();
    std::string master;
    if (ctx->component_master()) {
        master = ctx->component_master()->getText();
    } else {
        switch (std::toupper(id.front())) {
            case 'R': master = "resistor";  break;
            case 'C': master = "capacitor"; break;
            case 'L': master = "inductor";  break;
            case 'V': master = "vsource";   break;
            case 'I': master = "isource";   break;
            case 'D': master = "diode";     break;
            case 'Q': master = "bjt";       break;
            case 'M': master = "mos";       break;
            default:  master = "device";    break;
        }
    }
    return this->advance_visit(ctx, _factory.component(id, master));
}

Any SPECTREFrontend::visitComponent_id(SPECTREParser::Component_idContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitComponent_master(SPECTREParser::Component_masterContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitComponent_type(SPECTREParser::Component_typeContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitComponent_value(SPECTREParser::Component_valueContext *ctx) {
    auto value = visit(ctx->expression()).as<std::shared_ptr<structure::Value>>();
    // The value is already added to the parent by visitExpression -> visitExpression_atom
    // this->add_to_parent(value);
    return value;
}

Any SPECTREFrontend::visitComponent_value_list(SPECTREParser::Component_value_listContext *ctx) {
    auto value_list = _factory.valueList(DelimiterType::dlm_none);
    this->add_to_parent(value_list);
    this->push(value_list);
    for (auto expr_ctx : ctx->expression()) {
        visit(expr_ctx);
    }
    this->pop();
    return value_list;
}

Any SPECTREFrontend::visitComponent_analysis(SPECTREParser::Component_analysisContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitComponent_attribute(SPECTREParser::Component_attributeContext *ctx) { return visitChildren(ctx); }

/// === Parameter, Option, Global, Nodes, etc. ===
Any SPECTREFrontend::visitParameter_assign(SPECTREParser::Parameter_assignContext *ctx) {
    // 1) Build the LHS identifier
    auto idVal = _factory.identifier(ctx->parameter_id()->getText());
    // 2) Create and attach the empty Parameter
    auto param = _factory.parameter(idVal, nullptr, param_assign, false);
    add_to_parent(param);
    // 3) Push it so all child Values go under this Parameter
    push(param);
    // 4) Evaluate RHS
    std::shared_ptr<structure::Value> val;
    if (ctx->expression()) {
        visit(ctx->expression());
        // Value should already be assigned to the Parameter by add_to_parent
        val = param->getRight();
    } else if (ctx->filepath()) {
        auto txt = ctx->filepath()->getText();
        val = _factory.string(strip_quotes(txt));
        add_to_parent(val);
    }
    // 5) Pop back to the Model (or Analysis, etc.)
    pop();
    return param;
}

Any SPECTREFrontend::visitParameter_access(SPECTREParser::Parameter_accessContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitParameter_id(SPECTREParser::Parameter_idContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitParameter_list(SPECTREParser::Parameter_listContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitParameter_list_item(SPECTREParser::Parameter_list_itemContext *ctx)
{
    TRACE_VISIT("Parameter_list_item");
    // 1) Build the LHS identifier
    auto idVal = _factory.identifier(ctx->parameter_id()->getText());
    // 2) Create and attach the empty Parameter
    auto param = _factory.parameter(idVal, nullptr, param_assign, false);
    add_to_parent(param);
    push(param);
    
    // 3) Evaluate RHS if present
    if (ctx->array_expression()) {
        visit(ctx->array_expression());
    } else if (ctx->expression()) {
        visit(ctx->expression());
    } else if (ctx->filepath()) {
        auto txt = ctx->filepath()->getText();
        auto val = _factory.string(strip_quotes(txt));
        add_to_parent(val);
    }
    
    pop();
    return param;
}

Any SPECTREFrontend::visitOption(SPECTREParser::OptionContext *ctx) { 
    TRACE_VISIT("Option");
    std::string name = ctx->ID() ? ctx->ID()->getText() : "";
    auto control = _factory.control(name, ctrl_option);
    return this->advance_visit(ctx, control);
}

Any SPECTREFrontend::visitGlobal(SPECTREParser::GlobalContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitGlobal_declarations(SPECTREParser::Global_declarationsContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitNodeset(SPECTREParser::NodesetContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitNode(SPECTREParser::NodeContext *ctx) {
    return this->advance_visit(ctx, _factory.node(ctx->getText()));
}

Any SPECTREFrontend::visitNode_branch(SPECTREParser::Node_branchContext *ctx) {
    return this->advance_visit(ctx, _factory.node(ctx->getText()));
}

Any SPECTREFrontend::visitNode_list(SPECTREParser::Node_listContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitNode_list_item(SPECTREParser::Node_list_itemContext *ctx) {
    auto node = _factory.node(ctx->getText());
    this->add_to_parent(node);
    return node;
}

Any SPECTREFrontend::visitNode_mapping(SPECTREParser::Node_mappingContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitNode_pair(SPECTREParser::Node_pairContext *ctx) { return visitChildren(ctx); }

/// === Filepaths, expressions, numbers, etc. ===
Any SPECTREFrontend::visitFilepath(SPECTREParser::FilepathContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitFilepath_element(SPECTREParser::Filepath_elementContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitExpression(SPECTREParser::ExpressionContext *ctx) {
    // TRACE_VISIT("Expression");
    // Binary expression: expression operator expression
    if (ctx->expression().size() == 2) {
        auto op = to_operator(ctx->expression_operator());
        auto expr = _factory.expression(op, nullptr, nullptr);
        this->add_to_parent(expr);
        this->push(expr);
        visit(ctx->expression(0));
        visit(ctx->expression(1));
        this->pop();
        return expr;
    }
    // For Unary, Function, Atom, Scope, etc.
    return visitChildren(ctx);
}

Any SPECTREFrontend::visitExpression_atom(SPECTREParser::Expression_atomContext *ctx) {
    if (ctx->NUMBER()) {
        auto num_val = to_number(ctx->NUMBER(), _factory);
        if (!num_val) 
            return Any();
        this->add_to_parent(num_val);
        return num_val;
    }
    if (ctx->ID()) {
        auto id = _factory.identifier(ctx->ID()->getText());
        this->add_to_parent(id);
        return id;
    }
    if (ctx->STRING()) {
        auto str = _factory.string(strip_quotes(ctx->STRING()->getText()));
        this->add_to_parent(str);
        return str;
    }
    // Handle keyword, analysis_type, component_type, and PERCENTAGE as identifiers
    if (ctx->keyword() || ctx->analysis_type() || ctx->component_type() || ctx->PERCENTAGE()) {
        auto id = _factory.identifier(ctx->getText());
        this->add_to_parent(id);
        return id;
    }
    std::cerr << "visitExpression_atom: Unhandled atom: " << ctx->getText() << std::endl;
    return Any();
}

Any SPECTREFrontend::visitExpression_pair(SPECTREParser::Expression_pairContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitExpression_function_call(SPECTREParser::Expression_function_callContext *ctx) {
    auto func_call = _factory.functionCall(ctx->ID()->getText());
    this->add_to_parent(func_call);
    this->push(func_call);
    for(auto expr_ctx : ctx->expression()) {
        visit(expr_ctx);
    }
    this->pop();
    return func_call;
}

Any SPECTREFrontend::visitExpression_operator(SPECTREParser::Expression_operatorContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitExpression_scope(SPECTREParser::Expression_scopeContext *ctx) {
    if (ctx->expression().size() == 1) {
        return visit(ctx->expression(0));
    }
    // Multiple expressions - create a ValueList
    DelimiterType delimiter = DelimiterType::dlm_none;
    if (ctx->OPEN_ROUND()) {
        delimiter = DelimiterType::dlm_round;
    } else if (ctx->OPEN_CURLY()) {
        delimiter = DelimiterType::dlm_curly;
    } else if (ctx->APEX().size() > 0) {
        delimiter = DelimiterType::dlm_apex;
    }
    auto valueList = _factory.valueList(delimiter);
    this->add_to_parent(valueList);
    this->push(valueList);
    visitChildren(ctx);
    this->pop();
    return valueList;
}

Any SPECTREFrontend::visitArray_expression(SPECTREParser::Array_expressionContext *ctx) {
    // Create a ValueList with square bracket delimiter
    auto valueList = _factory.valueList(DelimiterType::dlm_square);
    this->add_to_parent(valueList);
    this->push(valueList);
    visitChildren(ctx);
    this->pop();
    return valueList;
}

Any SPECTREFrontend::visitArray_item(SPECTREParser::Array_itemContext *ctx) {
    if (ctx->NUMBER()) {
        auto num_val = to_number(ctx->NUMBER(), _factory);
        if (!num_val) 
            return Any();
        this->add_to_parent(num_val);
        return num_val;
    }
    if (ctx->ID()) {
        auto id = _factory.identifier(ctx->ID()->getText());
        this->add_to_parent(id);
        return id;
    }
    if (ctx->STRING()) {
        auto str = _factory.string(strip_quotes(ctx->STRING()->getText()));
        this->add_to_parent(str);
        return str;
    }
    // Handle keyword, analysis_type, component_type, and PERCENTAGE as identifiers
    if (ctx->keyword() || ctx->analysis_type() || ctx->component_type() || ctx->PERCENTAGE()) {
        auto id = _factory.identifier(ctx->getText());
        this->add_to_parent(id);
        return id;
    }
    return Any();
}

Any SPECTREFrontend::visitExpression_unary(SPECTREParser::Expression_unaryContext *ctx) {
    auto op = to_operator(ctx);
    auto expr = _factory.expressionUnary(op, nullptr);
    this->add_to_parent(expr);
    this->push(expr);
    visit(ctx->expression());
    this->pop();
    return expr;
}

Any SPECTREFrontend::visitTime_point(SPECTREParser::Time_pointContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitTime_pair(SPECTREParser::Time_pairContext *ctx) { return visitChildren(ctx); }

/// === Control, sweep, analysis types, statistics, etc. ===
Any SPECTREFrontend::visitAc(SPECTREParser::AcContext *ctx) { return this->advance_visit(ctx, _factory.analysis("ac")); }

Any SPECTREFrontend::visitAcmatch(SPECTREParser::AcmatchContext *ctx) { return this->advance_visit(ctx, _factory.analysis("acmatch")); }

Any SPECTREFrontend::visitAlter(SPECTREParser::AlterContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitAltergroup(SPECTREParser::AltergroupContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitAltergroup_content(SPECTREParser::Altergroup_contentContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitAltergroup_footer(SPECTREParser::Altergroup_footerContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitAltergroup_header(SPECTREParser::Altergroup_headerContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitAnalogmodel(SPECTREParser::AnalogmodelContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitAssert_statement(SPECTREParser::Assert_statementContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitCheck_statement(SPECTREParser::Check_statementContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitChecklimit(SPECTREParser::ChecklimitContext *ctx) { return this->advance_visit(ctx, _factory.analysis("checklimit")); }

Any SPECTREFrontend::visitControl(SPECTREParser::ControlContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitCorrelate(SPECTREParser::CorrelateContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitDc(SPECTREParser::DcContext *ctx) {
    std::string name = ctx->ID() ? ctx->ID()->getText() : "dc";
    auto component = _factory.component(name, "dc");
    return this->advance_visit(ctx, component);
}

Any SPECTREFrontend::visitDcmatch(SPECTREParser::DcmatchContext *ctx) { return this->advance_visit(ctx, _factory.analysis("dcmatch")); }

Any SPECTREFrontend::visitEnvlp(SPECTREParser::EnvlpContext *ctx) { return this->advance_visit(ctx, _factory.analysis("envlp")); }

Any SPECTREFrontend::visitIc(SPECTREParser::IcContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitIf_alternative(SPECTREParser::If_alternativeContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitIf_body(SPECTREParser::If_bodyContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitIf_statement(SPECTREParser::If_statementContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitInfo(SPECTREParser::InfoContext *ctx) { 
    std::string name = ctx->ID() ? ctx->ID()->getText() : "";
    return this->advance_visit(ctx, _factory.analysis(name));
}

Any SPECTREFrontend::visitKeyword(SPECTREParser::KeywordContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitMismatch(SPECTREParser::MismatchContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitMontecarlo(SPECTREParser::MontecarloContext *ctx) { return this->advance_visit(ctx, _factory.analysis("montecarlo")); }

Any SPECTREFrontend::visitMontecarlo_content(SPECTREParser::Montecarlo_contentContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitMontecarlo_export(SPECTREParser::Montecarlo_exportContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitMontecarlo_footer(SPECTREParser::Montecarlo_footerContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitMontecarlo_header(SPECTREParser::Montecarlo_headerContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitNoise(SPECTREParser::NoiseContext *ctx) { return this->advance_visit(ctx, _factory.analysis("noise")); }

Any SPECTREFrontend::visitPac(SPECTREParser::PacContext *ctx) { return this->advance_visit(ctx, _factory.analysis("pac")); }

Any SPECTREFrontend::visitPdisto(SPECTREParser::PdistoContext *ctx) { return this->advance_visit(ctx, _factory.analysis("pdisto")); }

Any SPECTREFrontend::visitPnoise(SPECTREParser::PnoiseContext *ctx) { return this->advance_visit(ctx, _factory.analysis("pnoise")); }

Any SPECTREFrontend::visitProcess(SPECTREParser::ProcessContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitPsp(SPECTREParser::PspContext *ctx) { return this->advance_visit(ctx, _factory.analysis("psp")); }

Any SPECTREFrontend::visitPss(SPECTREParser::PssContext *ctx) { return this->advance_visit(ctx, _factory.analysis("pss")); }

Any SPECTREFrontend::visitPxf(SPECTREParser::PxfContext *ctx) { return this->advance_visit(ctx, _factory.analysis("pxf")); }

Any SPECTREFrontend::visitPz(SPECTREParser::PzContext *ctx) { return this->advance_visit(ctx, _factory.analysis("pz")); }

Any SPECTREFrontend::visitQpac(SPECTREParser::QpacContext *ctx) { return this->advance_visit(ctx, _factory.analysis("qpac")); }

Any SPECTREFrontend::visitQpnoise(SPECTREParser::QpnoiseContext *ctx) { return this->advance_visit(ctx, _factory.analysis("qpnoise")); }

Any SPECTREFrontend::visitQpsp(SPECTREParser::QpspContext *ctx) { return this->advance_visit(ctx, _factory.analysis("qpsp")); }

Any SPECTREFrontend::visitQpss(SPECTREParser::QpssContext *ctx) { return this->advance_visit(ctx, _factory.analysis("qpss")); }

Any SPECTREFrontend::visitQpxf(SPECTREParser::QpxfContext *ctx) { return this->advance_visit(ctx, _factory.analysis("qpxf")); }

Any SPECTREFrontend::visitReliability(SPECTREParser::ReliabilityContext *ctx) { return this->advance_visit(ctx, _factory.analysis("reliability")); }

Any SPECTREFrontend::visitReliability_content(SPECTREParser::Reliability_contentContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitReliability_control(SPECTREParser::Reliability_controlContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitReliability_footer(SPECTREParser::Reliability_footerContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitReliability_header(SPECTREParser::Reliability_headerContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitSave(SPECTREParser::SaveContext *ctx) { 
    // First ID after SAVE is saved signals, not a name
    auto control = _factory.control("", ctrl_save);
    this->add_to_parent(control);
    this->push(control);
    // Add the ID as a parameter (the signal name to save)
    if (ctx->ID()) {
        auto id = _factory.identifier(ctx->ID()->getText());
        auto param = _factory.parameter(id, nullptr, param_assign, false);  // Don't hide the name
        control->parameters.push_back(param);
    }
    // Visit the rest (parameter_list if any)
    if (ctx->parameter_list()) {
        visit(ctx->parameter_list());
    }
    this->pop();
    return control;
}

Any SPECTREFrontend::visitSection(SPECTREParser::SectionContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitSection_content(SPECTREParser::Section_contentContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitSection_footer(SPECTREParser::Section_footerContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitSection_header(SPECTREParser::Section_headerContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitSens(SPECTREParser::SensContext *ctx) { return this->advance_visit(ctx, _factory.analysis("sens")); }

Any SPECTREFrontend::visitSens_analyses_list(SPECTREParser::Sens_analyses_listContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitSens_design_parameters_list(SPECTREParser::Sens_design_parameters_listContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitSens_output_variables_list(SPECTREParser::Sens_output_variables_listContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitSet(SPECTREParser::SetContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitShell(SPECTREParser::ShellContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitSp(SPECTREParser::SpContext *ctx) {
    std::string name = ctx->ID() ? ctx->ID()->getText() : "sp";
    auto component = _factory.component(name, "sp");
    return this->advance_visit(ctx, component);
}

Any SPECTREFrontend::visitStatistics(SPECTREParser::StatisticsContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitStatistics_content(SPECTREParser::Statistics_contentContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitStatistics_footer(SPECTREParser::Statistics_footerContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitStatistics_header(SPECTREParser::Statistics_headerContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitStb(SPECTREParser::StbContext *ctx) { return this->advance_visit(ctx, _factory.analysis("stb")); }

Any SPECTREFrontend::visitSweep(SPECTREParser::SweepContext *ctx) { return this->advance_visit(ctx, _factory.analysis("sweep")); }

Any SPECTREFrontend::visitSweep_content(SPECTREParser::Sweep_contentContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitSweep_footer(SPECTREParser::Sweep_footerContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitSweep_header(SPECTREParser::Sweep_headerContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitTdr(SPECTREParser::TdrContext *ctx) { return this->advance_visit(ctx, _factory.analysis("tdr")); }

Any SPECTREFrontend::visitTran(SPECTREParser::TranContext *ctx) {
    std::string name = ctx->ID() ? ctx->ID()->getText() : "tran";
    auto component = _factory.component(name, "tran");
    return this->advance_visit(ctx, component);
}

Any SPECTREFrontend::visitTruncate(SPECTREParser::TruncateContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitValue_access(SPECTREParser::Value_accessContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitValue_access_assign(SPECTREParser::Value_access_assignContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitVary(SPECTREParser::VaryContext *ctx) { return visitChildren(ctx); }

Any SPECTREFrontend::visitXf(SPECTREParser::XfContext *ctx) { return this->advance_visit(ctx, _factory.analysis("xf")); }

// ============================================================================
std::shared_ptr<structure::Object> SPECTREFrontend::back() const
{
    if (_stack.empty())
        return nullptr;
    return _stack.back();
}

void SPECTREFrontend::push(const std::shared_ptr<structure::Object> &node)
{
    if (node == nullptr)
        _error("Executing push and receiving a NULL node!");
    _stack.emplace_back(node);
}

std::shared_ptr<structure::Object> SPECTREFrontend::pop()
{
    auto node = this->back();
    if (node == nullptr)
        _error("Executing pop and receiving a NULL node!");
    _stack.pop_back();
    return node;
}

void SPECTREFrontend::add_to_parent(const std::shared_ptr<structure::Object> &node)
{
    auto parent = this->back();
    if (parent) {
        // std::cout << "Adding " << (node ? "Node" : "NULL") << " to " << "Parent" << std::endl;
    }
    if (parent == nullptr) {
        _root = node;
        return;
    }
    if (auto analysis = utility::to<structure::Analysis>(parent)) {
        if (auto param = utility::to<structure::Parameter>(node)) {
            analysis->parameters.push_back(param);
        } else if (auto value = utility::to<structure::Value>(node)) {
            analysis->parameters.push_back(_factory.parameter(nullptr, value, param_assign, false));
        } else {
            _error("Wrong item added to Analysis: %s", node->toString().c_str());
        }
    } else if (auto circuit = utility::to<structure::Circuit>(parent)) {
        if (auto circuit_node = utility::to<structure::Node>(node)) {
            circuit->nodes.push_back(circuit_node);
        } else if (auto param = utility::to<structure::Parameter>(node)) {
            circuit->parameters.push_back(param);
        } else {
            circuit->content.push_back(node);
        }
    } else if (auto component = utility::to<structure::Component>(parent)) {
        if (auto comp_node = utility::to<structure::Node>(node)) {
            component->nodes.push_back(comp_node);
        } else if (auto param = utility::to<structure::Parameter>(node)) {
            component->parameters.push_back(param);
        } else if (auto value = utility::to<structure::Value>(node)) {
            component->parameters.push_back(_factory.parameter(nullptr, value, param_assign, false));
        } else {
            _error("Wrong item added to Component: %s", node->toString().c_str());
        }
    } else if (auto control_scope = utility::to<structure::ControlScope>(parent)) {
        if (auto cs_node = utility::to<structure::Node>(node)) {
            control_scope->nodes.push_back(cs_node);
        } else if (auto param = utility::to<structure::Parameter>(node)) {
            control_scope->parameters.push_back(param);
        } else {
            control_scope->content.push_back(node);
        }
    } else if (auto control = utility::to<structure::Control>(parent)) {
        if (auto param = utility::to<structure::Parameter>(node)) {
            control->parameters.push_back(param);
        } else {
            _error("Wrong item added to Control: %s", node->toString().c_str());
        }
    } else if (auto value_list = utility::to<structure::ValueList>(parent)) {
        value_list->values.push_back(utility::to_check<structure::Value>(node));
    } else if (auto value_pair = utility::to<structure::ValuePair>(parent)) {
        if (!value_pair->getFirst())
            value_pair->setFirst(utility::to<structure::Value>(node));
        else if (!value_pair->getSecond())
            value_pair->setSecond(utility::to<structure::Value>(node));
        else
            _error("ValuePair parent has no space for node: %s", node->toString().c_str());
    } else if (auto expr_unary = utility::to<structure::ExpressionUnary>(parent)) {
        if (!expr_unary->getValue())
            expr_unary->setValue(utility::to<structure::Value>(node));
        else
            _error("ExpressionUnary parent has no space for node: %s", node->toString().c_str());
    } else if (auto expression = utility::to<structure::Expression>(parent)) {
        if (!expression->getFirst())
            expression->setFirst(utility::to<structure::Value>(node));
        else if (!expression->getSecond())
            expression->setSecond(utility::to<structure::Value>(node));
        else
            _error("Expression parent has no space for node: %s", node->toString().c_str());
    } else if (auto func_call = utility::to<structure::FunctionCall>(parent)) {
        if (auto param = utility::to<structure::Parameter>(node)) {
            func_call->parameters.push_back(param);
        } else if (auto value = utility::to<structure::Value>(node)) {
            func_call->parameters.push_back(_factory.parameter(nullptr, value, param_assign, false));
        } else {
            _error("Wrong item added to FunctionCall: %s", node->toString().c_str());
        }
    } else if (auto include = utility::to<structure::Include>(parent)) {
        if (auto param = utility::to<structure::Parameter>(node))
            include->parameters.push_back(param);
        else
            _error("Wrong item added to Include: %s", node->toString().c_str());
    } else if (auto library_def = utility::to<structure::LibraryDef>(parent)) {
        library_def->content.push_back(node);
    } else if (auto model = utility::to<structure::Model>(parent)) {
        if (auto param = utility::to<structure::Parameter>(node)) {
            model->parameters.push_back(param);
        } else {
            _error("Wrong item added to Model: %s", node->toString().c_str());
        }
    } else if (auto parameter = utility::to<structure::Parameter>(parent)) {
        if (!parameter->getLeft())
            parameter->setLeft(utility::to<structure::Value>(node));
        else if (!parameter->getRight())
            parameter->setRight(utility::to<structure::Value>(node));
        else
            _error("Parameter parent has no space for node: %s", node->toString().c_str());
    } else if (auto subckt = utility::to<structure::Subckt>(parent)) {
        if (auto subckt_node = utility::to<structure::Node>(node)) {
            subckt->nodes.push_back(subckt_node);
        } else if (auto param = utility::to<structure::Parameter>(node)) {
            subckt->parameters.push_back(param);
        } else {
            subckt->content.push_back(node);
        }
    }
}

antlrcpp::Any SPECTREFrontend::advance_visit(antlr4::ParserRuleContext *ctx, const std::shared_ptr<structure::Object> &node)
{
    this->add_to_parent(node);
    this->push(node);
    auto result = visitChildren(ctx);
    this->pop();
    return result;
}

std::shared_ptr<edacurry::structure::Object> parse_spectre(const std::string &path)
{    
    std::cerr << "Starting parse_spectre for " << path << std::endl;
    std::ifstream fileStream(path);
    if (!fileStream.is_open()) {
        std::cerr << "ERROR: Cannot open file " << path << std::endl;
        return nullptr;
    }
    antlr4::ANTLRInputStream input(fileStream);
    edacurry::SPECTRELexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    tokens.fill();
    edacurry::SPECTREParser parser(&tokens);
    edacurry::frontend::SPECTREFrontend frontend(tokens);
    std::cerr << "Invoking accept" << std::endl;
    parser.netlist()->accept(&frontend);
    std::cerr << "Finished accept" << std::endl;
    return frontend.getRoot();
}

} // namespace edacurry::frontend