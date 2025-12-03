/// @file spectre_frontend.hpp
/// @author Enrico Fraccaroli (enrico.fraccaroli@gmail.com)
/// @copyright Copyright (c) 2021 sydelity.net (info@sydelity.com)
/// Distributed under the MIT License (MIT) (See accompanying LICENSE file or
///  copy at http://opensource.org/licenses/MIT)

#pragma once

#include "antlr4-runtime.h"
#include "edacurry/structure/object.hpp"
#include "edacurry/factory.hpp"

#include <antlr4parser/SPECTREParserBaseVisitor.h>
  

namespace edacurry::frontend
{

/// @brief Converts a filepath context to a string.
/// @param ctx The filepath context.
/// @return The converted string.
std::string to_string(SPECTREParser::FilepathContext *ctx);

/// @brief Parses a terminal node representing a number with an optional SI unit suffix.
/// @param ctx The terminal node context.
/// @param factory The factory to use for creating the value.
/// @return A shared pointer to the created value.
std::shared_ptr<structure::Value> to_number(antlr4::tree::TerminalNode *ctx,   Factory &factory);

/// @brief Converts a string to an operator.
/// @param op_str The operator string.
/// @return The corresponding operator enum value.
Operator to_operator_internal(const std::string &op_str);

/// @brief Converts an expression operator context to an operator.
/// @param ctx The expression operator context.
/// @return The corresponding operator enum value.
Operator to_operator(SPECTREParser::Expression_operatorContext *ctx);

/// @brief Converts an expression unary context to an operator.
/// @param ctx The expression unary context.
/// @return The corresponding operator enum value.
Operator to_operator(SPECTREParser::Expression_unaryContext *ctx);

class SPECTREFrontend : public SPECTREParserBaseVisitor {
public:
    antlr4::CommonTokenStream &tokens;

    SPECTREFrontend(antlr4::CommonTokenStream &_tokens);

    ~SPECTREFrontend() = default;

    antlrcpp::Any visitNetlist(SPECTREParser::NetlistContext *ctx) override;

    antlrcpp::Any visitNetlist_title(SPECTREParser::Netlist_titleContext *ctx) override;

    antlrcpp::Any visitNetlist_entity(SPECTREParser::Netlist_entityContext *ctx) override;

    antlrcpp::Any visitInclude(SPECTREParser::IncludeContext *ctx) override;

    antlrcpp::Any visitStandard_include(SPECTREParser::Standard_includeContext *ctx) override;

    antlrcpp::Any visitCpp_include(SPECTREParser::Cpp_includeContext *ctx) override;

    antlrcpp::Any visitAhdl_include(SPECTREParser::Ahdl_includeContext *ctx) override;

    antlrcpp::Any visitLang(SPECTREParser::LangContext *ctx) override;

    antlrcpp::Any visitLibrary(SPECTREParser::LibraryContext *ctx) override;

    antlrcpp::Any visitLibrary_header(SPECTREParser::Library_headerContext *ctx) override;

    antlrcpp::Any visitLibrary_content(SPECTREParser::Library_contentContext *ctx) override;

    antlrcpp::Any visitLibrary_footer(SPECTREParser::Library_footerContext *ctx) override;

    antlrcpp::Any visitSection(SPECTREParser::SectionContext *ctx) override;

    antlrcpp::Any visitSection_header(SPECTREParser::Section_headerContext *ctx) override;

    antlrcpp::Any visitSection_content(SPECTREParser::Section_contentContext *ctx) override;

    antlrcpp::Any visitSection_footer(SPECTREParser::Section_footerContext *ctx) override;

    antlrcpp::Any visitAnalogmodel(SPECTREParser::AnalogmodelContext *ctx) override;

    antlrcpp::Any visitSubckt(SPECTREParser::SubcktContext *ctx) override;

    antlrcpp::Any visitSubckt_header(SPECTREParser::Subckt_headerContext *ctx) override;

    antlrcpp::Any visitSubckt_content(SPECTREParser::Subckt_contentContext *ctx) override;

    antlrcpp::Any visitSubckt_footer(SPECTREParser::Subckt_footerContext *ctx) override;

    antlrcpp::Any visitIf_statement(SPECTREParser::If_statementContext *ctx) override;

    antlrcpp::Any visitIf_alternative(SPECTREParser::If_alternativeContext *ctx) override;

    antlrcpp::Any visitIf_body(SPECTREParser::If_bodyContext *ctx) override;

    antlrcpp::Any visitAnalysis(SPECTREParser::AnalysisContext *ctx) override;

    antlrcpp::Any visitAc(SPECTREParser::AcContext *ctx) override;

    antlrcpp::Any visitAcmatch(SPECTREParser::AcmatchContext *ctx) override;

    antlrcpp::Any visitDc(SPECTREParser::DcContext *ctx) override;

    antlrcpp::Any visitDcmatch(SPECTREParser::DcmatchContext *ctx) override;

    antlrcpp::Any visitEnvlp(SPECTREParser::EnvlpContext *ctx) override;

    antlrcpp::Any visitSp(SPECTREParser::SpContext *ctx) override;

    antlrcpp::Any visitStb(SPECTREParser::StbContext *ctx) override;

    antlrcpp::Any visitSweep(SPECTREParser::SweepContext *ctx) override;

    antlrcpp::Any visitSweep_header(SPECTREParser::Sweep_headerContext *ctx) override;

    antlrcpp::Any visitSweep_content(SPECTREParser::Sweep_contentContext *ctx) override;

    antlrcpp::Any visitSweep_footer(SPECTREParser::Sweep_footerContext *ctx) override;

    antlrcpp::Any visitTdr(SPECTREParser::TdrContext *ctx) override;

    antlrcpp::Any visitTran(SPECTREParser::TranContext *ctx) override;

    antlrcpp::Any visitXf(SPECTREParser::XfContext *ctx) override;

    antlrcpp::Any visitPac(SPECTREParser::PacContext *ctx) override;

    antlrcpp::Any visitPdisto(SPECTREParser::PdistoContext *ctx) override;

    antlrcpp::Any visitPnoise(SPECTREParser::PnoiseContext *ctx) override;

    antlrcpp::Any visitPsp(SPECTREParser::PspContext *ctx) override;

    antlrcpp::Any visitPss(SPECTREParser::PssContext *ctx) override;

    antlrcpp::Any visitPxf(SPECTREParser::PxfContext *ctx) override;

    antlrcpp::Any visitPz(SPECTREParser::PzContext *ctx) override;

    antlrcpp::Any visitQpac(SPECTREParser::QpacContext *ctx) override;

    antlrcpp::Any visitQpnoise(SPECTREParser::QpnoiseContext *ctx) override;

    antlrcpp::Any visitQpsp(SPECTREParser::QpspContext *ctx) override;

    antlrcpp::Any visitQpss(SPECTREParser::QpssContext *ctx) override;

    antlrcpp::Any visitQpxf(SPECTREParser::QpxfContext *ctx) override;

    antlrcpp::Any visitSens(SPECTREParser::SensContext *ctx) override;

    antlrcpp::Any visitSens_output_variables_list(SPECTREParser::Sens_output_variables_listContext *ctx) override;

    antlrcpp::Any visitSens_design_parameters_list(SPECTREParser::Sens_design_parameters_listContext *ctx) override;

    antlrcpp::Any visitSens_analyses_list(SPECTREParser::Sens_analyses_listContext *ctx) override;

    antlrcpp::Any visitMontecarlo(SPECTREParser::MontecarloContext *ctx) override;

    antlrcpp::Any visitMontecarlo_header(SPECTREParser::Montecarlo_headerContext *ctx) override;

    antlrcpp::Any visitMontecarlo_content(SPECTREParser::Montecarlo_contentContext *ctx) override;

    antlrcpp::Any visitMontecarlo_export(SPECTREParser::Montecarlo_exportContext *ctx) override;

    antlrcpp::Any visitMontecarlo_footer(SPECTREParser::Montecarlo_footerContext *ctx) override;

    antlrcpp::Any visitNoise(SPECTREParser::NoiseContext *ctx) override;

    antlrcpp::Any visitChecklimit(SPECTREParser::ChecklimitContext *ctx) override;

    antlrcpp::Any visitGlobal(SPECTREParser::GlobalContext *ctx) override;

    antlrcpp::Any visitModel(SPECTREParser::ModelContext *ctx) override;

    antlrcpp::Any visitModel_name(SPECTREParser::Model_nameContext *ctx) override;

    antlrcpp::Any visitModel_master(SPECTREParser::Model_masterContext *ctx) override;

    antlrcpp::Any visitControl(SPECTREParser::ControlContext *ctx) override;

    antlrcpp::Any visitAlter(SPECTREParser::AlterContext *ctx) override;

    antlrcpp::Any visitAltergroup(SPECTREParser::AltergroupContext *ctx) override;

    antlrcpp::Any visitAltergroup_header(SPECTREParser::Altergroup_headerContext *ctx) override;

    antlrcpp::Any visitAltergroup_content(SPECTREParser::Altergroup_contentContext *ctx) override;

    antlrcpp::Any visitAltergroup_footer(SPECTREParser::Altergroup_footerContext *ctx) override;

    antlrcpp::Any visitAssert_statement(SPECTREParser::Assert_statementContext *ctx) override;

    antlrcpp::Any visitCheck_statement(SPECTREParser::Check_statementContext *ctx) override;

    antlrcpp::Any visitSave(SPECTREParser::SaveContext *ctx) override;

    antlrcpp::Any visitOption(SPECTREParser::OptionContext *ctx) override;

    antlrcpp::Any visitSet(SPECTREParser::SetContext *ctx) override;

    antlrcpp::Any visitShell(SPECTREParser::ShellContext *ctx) override;

    antlrcpp::Any visitInfo(SPECTREParser::InfoContext *ctx) override;

    antlrcpp::Any visitNodeset(SPECTREParser::NodesetContext *ctx) override;

    antlrcpp::Any visitIc(SPECTREParser::IcContext *ctx) override;

    antlrcpp::Any visitStatistics(SPECTREParser::StatisticsContext *ctx) override;

    antlrcpp::Any visitStatistics_header(SPECTREParser::Statistics_headerContext *ctx) override;

    antlrcpp::Any visitStatistics_content(SPECTREParser::Statistics_contentContext *ctx) override;

    antlrcpp::Any visitStatistics_footer(SPECTREParser::Statistics_footerContext *ctx) override;

    antlrcpp::Any visitProcess(SPECTREParser::ProcessContext *ctx) override;

    antlrcpp::Any visitMismatch(SPECTREParser::MismatchContext *ctx) override;

    antlrcpp::Any visitCorrelate(SPECTREParser::CorrelateContext *ctx) override;

    antlrcpp::Any visitTruncate(SPECTREParser::TruncateContext *ctx) override;

    antlrcpp::Any visitVary(SPECTREParser::VaryContext *ctx) override;

    antlrcpp::Any visitReliability(SPECTREParser::ReliabilityContext *ctx) override;

    antlrcpp::Any visitReliability_header(SPECTREParser::Reliability_headerContext *ctx) override;

    antlrcpp::Any visitReliability_content(SPECTREParser::Reliability_contentContext *ctx) override;

    antlrcpp::Any visitReliability_footer(SPECTREParser::Reliability_footerContext *ctx) override;

    antlrcpp::Any visitReliability_control(SPECTREParser::Reliability_controlContext *ctx) override;

    antlrcpp::Any visitGlobal_declarations(SPECTREParser::Global_declarationsContext *ctx) override;

    antlrcpp::Any visitComponent(SPECTREParser::ComponentContext *ctx) override;

    antlrcpp::Any visitComponent_id(SPECTREParser::Component_idContext *ctx) override;

    antlrcpp::Any visitComponent_master(SPECTREParser::Component_masterContext *ctx) override;

    antlrcpp::Any visitComponent_attribute(SPECTREParser::Component_attributeContext *ctx) override;

    antlrcpp::Any visitComponent_value(SPECTREParser::Component_valueContext *ctx) override;

    antlrcpp::Any visitComponent_value_list(SPECTREParser::Component_value_listContext *ctx) override;

    antlrcpp::Any visitComponent_analysis(SPECTREParser::Component_analysisContext *ctx) override;

    antlrcpp::Any visitNode_list(SPECTREParser::Node_listContext *ctx) override;

    antlrcpp::Any visitNode_list_item(SPECTREParser::Node_list_itemContext *ctx) override;

    antlrcpp::Any visitNode_mapping(SPECTREParser::Node_mappingContext *ctx) override;

    antlrcpp::Any visitNode_pair(SPECTREParser::Node_pairContext *ctx) override;

    antlrcpp::Any visitNode_branch(SPECTREParser::Node_branchContext *ctx) override;

    antlrcpp::Any visitNode(SPECTREParser::NodeContext *ctx) override;

    antlrcpp::Any visitExpression(SPECTREParser::ExpressionContext *ctx) override;

    antlrcpp::Any visitExpression_unary(SPECTREParser::Expression_unaryContext *ctx) override;

    antlrcpp::Any visitExpression_function_call(SPECTREParser::Expression_function_callContext *ctx) override;

    antlrcpp::Any visitExpression_pair(SPECTREParser::Expression_pairContext *ctx) override;

    antlrcpp::Any visitExpression_scope(SPECTREParser::Expression_scopeContext *ctx) override;

    antlrcpp::Any visitArray_expression(SPECTREParser::Array_expressionContext *ctx) override;

    antlrcpp::Any visitArray_item(SPECTREParser::Array_itemContext *ctx) override;

    antlrcpp::Any visitExpression_operator(SPECTREParser::Expression_operatorContext *ctx) override;

    antlrcpp::Any visitExpression_atom(SPECTREParser::Expression_atomContext *ctx) override;

    antlrcpp::Any visitParameter_list(SPECTREParser::Parameter_listContext *ctx) override;

    antlrcpp::Any visitParameter_list_item(SPECTREParser::Parameter_list_itemContext *ctx) override;

    antlrcpp::Any visitParameter_assign(SPECTREParser::Parameter_assignContext *ctx) override;

    antlrcpp::Any visitParameter_id(SPECTREParser::Parameter_idContext *ctx) override;

    antlrcpp::Any visitParameter_access(SPECTREParser::Parameter_accessContext *ctx) override;

    antlrcpp::Any visitValue_access(SPECTREParser::Value_accessContext *ctx) override;

    antlrcpp::Any visitValue_access_assign(SPECTREParser::Value_access_assignContext *ctx) override;

    antlrcpp::Any visitTime_pair(SPECTREParser::Time_pairContext *ctx) override;

    antlrcpp::Any visitTime_point(SPECTREParser::Time_pointContext *ctx) override;

    antlrcpp::Any visitFilepath(SPECTREParser::FilepathContext *ctx) override;

    antlrcpp::Any visitFilepath_element(SPECTREParser::Filepath_elementContext *ctx) override;

    antlrcpp::Any visitKeyword(SPECTREParser::KeywordContext *ctx) override;

    antlrcpp::Any visitAnalysis_type(SPECTREParser::Analysis_typeContext *ctx) override;

    antlrcpp::Any visitComponent_type(SPECTREParser::Component_typeContext *ctx) override;

    std::shared_ptr<structure::Object> getRoot() const
    {
        return _root;
    }

private:
    /// @brief Stack of objects to be visited.
    std::vector<std::shared_ptr<structure::Object> > _stack;

    /// @brief The root object of the netlist.
    std::shared_ptr<structure::Object> _root;

    /// @brief The factory used to create objects.
    Factory _factory;

    /// @brief Returns the current object on the top of the stack.
    /// @return structure::Object*
    std::shared_ptr<structure::Object> back() const;

    /// @brief Pops the current object from the stack.
    /// @param node
    /// @return structure::Object*
    void push(const std::shared_ptr<structure::Object> &node);

    /// @brief Pops the current object from the stack.
    /// @return structure::Object*
    std::shared_ptr<structure::Object> pop();

    /// @brief Adds the node to the parent. 
    /// @param node
    /// @return void
    void add_to_parent(const std::shared_ptr<structure::Object> &node);

    /// @brief Advances the visitor to the next node.
    /// @param ctx The context of the current rule.
    /// @param node The node to advance to.
    /// @return antlrcpp::Any
    antlrcpp::Any advance_visit(antlr4::ParserRuleContext *ctx, const std::shared_ptr<structure::Object> &node);

    /// @brief Infers the master name from the component type character.
    /// @param c The character representing the component type.
    /// @return The inferred master name as a string.
    static std::string infer_master(char c);
};

/// @brief Parses a SPECTRE file and returns the root object of the netlist.
/// @param path The path to the SPECTRE file.
/// @return A shared pointer to the root object of the netlist.
std::shared_ptr<edacurry::structure::Object> parse_spectre(const std::string &path);

} // namespace edacurry::frontend