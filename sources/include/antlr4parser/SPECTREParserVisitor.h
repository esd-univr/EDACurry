
// Generated from g4files/SPECTREParser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "SPECTREParser.h"


namespace edacurry {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by SPECTREParser.
 */
class  SPECTREParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by SPECTREParser.
   */
    virtual std::any visitNetlist(SPECTREParser::NetlistContext *context) = 0;

    virtual std::any visitNetlist_title(SPECTREParser::Netlist_titleContext *context) = 0;

    virtual std::any visitNetlist_entity(SPECTREParser::Netlist_entityContext *context) = 0;

    virtual std::any visitInclude(SPECTREParser::IncludeContext *context) = 0;

    virtual std::any visitStandard_include(SPECTREParser::Standard_includeContext *context) = 0;

    virtual std::any visitCpp_include(SPECTREParser::Cpp_includeContext *context) = 0;

    virtual std::any visitAhdl_include(SPECTREParser::Ahdl_includeContext *context) = 0;

    virtual std::any visitLang(SPECTREParser::LangContext *context) = 0;

    virtual std::any visitLibrary(SPECTREParser::LibraryContext *context) = 0;

    virtual std::any visitLibrary_header(SPECTREParser::Library_headerContext *context) = 0;

    virtual std::any visitLibrary_content(SPECTREParser::Library_contentContext *context) = 0;

    virtual std::any visitLibrary_footer(SPECTREParser::Library_footerContext *context) = 0;

    virtual std::any visitSection(SPECTREParser::SectionContext *context) = 0;

    virtual std::any visitSection_header(SPECTREParser::Section_headerContext *context) = 0;

    virtual std::any visitSection_content(SPECTREParser::Section_contentContext *context) = 0;

    virtual std::any visitSection_footer(SPECTREParser::Section_footerContext *context) = 0;

    virtual std::any visitAnalogmodel(SPECTREParser::AnalogmodelContext *context) = 0;

    virtual std::any visitSubckt(SPECTREParser::SubcktContext *context) = 0;

    virtual std::any visitSubckt_header(SPECTREParser::Subckt_headerContext *context) = 0;

    virtual std::any visitSubckt_content(SPECTREParser::Subckt_contentContext *context) = 0;

    virtual std::any visitSubckt_footer(SPECTREParser::Subckt_footerContext *context) = 0;

    virtual std::any visitIf_statement(SPECTREParser::If_statementContext *context) = 0;

    virtual std::any visitIf_alternative(SPECTREParser::If_alternativeContext *context) = 0;

    virtual std::any visitIf_body(SPECTREParser::If_bodyContext *context) = 0;

    virtual std::any visitAnalysis(SPECTREParser::AnalysisContext *context) = 0;

    virtual std::any visitAc(SPECTREParser::AcContext *context) = 0;

    virtual std::any visitAcmatch(SPECTREParser::AcmatchContext *context) = 0;

    virtual std::any visitDc(SPECTREParser::DcContext *context) = 0;

    virtual std::any visitDcmatch(SPECTREParser::DcmatchContext *context) = 0;

    virtual std::any visitEnvlp(SPECTREParser::EnvlpContext *context) = 0;

    virtual std::any visitSp(SPECTREParser::SpContext *context) = 0;

    virtual std::any visitStb(SPECTREParser::StbContext *context) = 0;

    virtual std::any visitSweep(SPECTREParser::SweepContext *context) = 0;

    virtual std::any visitSweep_header(SPECTREParser::Sweep_headerContext *context) = 0;

    virtual std::any visitSweep_content(SPECTREParser::Sweep_contentContext *context) = 0;

    virtual std::any visitSweep_footer(SPECTREParser::Sweep_footerContext *context) = 0;

    virtual std::any visitTdr(SPECTREParser::TdrContext *context) = 0;

    virtual std::any visitTran(SPECTREParser::TranContext *context) = 0;

    virtual std::any visitXf(SPECTREParser::XfContext *context) = 0;

    virtual std::any visitPac(SPECTREParser::PacContext *context) = 0;

    virtual std::any visitPdisto(SPECTREParser::PdistoContext *context) = 0;

    virtual std::any visitPnoise(SPECTREParser::PnoiseContext *context) = 0;

    virtual std::any visitPsp(SPECTREParser::PspContext *context) = 0;

    virtual std::any visitPss(SPECTREParser::PssContext *context) = 0;

    virtual std::any visitPxf(SPECTREParser::PxfContext *context) = 0;

    virtual std::any visitPz(SPECTREParser::PzContext *context) = 0;

    virtual std::any visitQpac(SPECTREParser::QpacContext *context) = 0;

    virtual std::any visitQpnoise(SPECTREParser::QpnoiseContext *context) = 0;

    virtual std::any visitQpsp(SPECTREParser::QpspContext *context) = 0;

    virtual std::any visitQpss(SPECTREParser::QpssContext *context) = 0;

    virtual std::any visitQpxf(SPECTREParser::QpxfContext *context) = 0;

    virtual std::any visitSens(SPECTREParser::SensContext *context) = 0;

    virtual std::any visitSens_output_variables_list(SPECTREParser::Sens_output_variables_listContext *context) = 0;

    virtual std::any visitSens_design_parameters_list(SPECTREParser::Sens_design_parameters_listContext *context) = 0;

    virtual std::any visitSens_analyses_list(SPECTREParser::Sens_analyses_listContext *context) = 0;

    virtual std::any visitMontecarlo(SPECTREParser::MontecarloContext *context) = 0;

    virtual std::any visitMontecarlo_header(SPECTREParser::Montecarlo_headerContext *context) = 0;

    virtual std::any visitMontecarlo_content(SPECTREParser::Montecarlo_contentContext *context) = 0;

    virtual std::any visitMontecarlo_export(SPECTREParser::Montecarlo_exportContext *context) = 0;

    virtual std::any visitMontecarlo_footer(SPECTREParser::Montecarlo_footerContext *context) = 0;

    virtual std::any visitNoise(SPECTREParser::NoiseContext *context) = 0;

    virtual std::any visitChecklimit(SPECTREParser::ChecklimitContext *context) = 0;

    virtual std::any visitGlobal(SPECTREParser::GlobalContext *context) = 0;

    virtual std::any visitModel(SPECTREParser::ModelContext *context) = 0;

    virtual std::any visitModel_name(SPECTREParser::Model_nameContext *context) = 0;

    virtual std::any visitModel_master(SPECTREParser::Model_masterContext *context) = 0;

    virtual std::any visitControl(SPECTREParser::ControlContext *context) = 0;

    virtual std::any visitAlter(SPECTREParser::AlterContext *context) = 0;

    virtual std::any visitAltergroup(SPECTREParser::AltergroupContext *context) = 0;

    virtual std::any visitAltergroup_header(SPECTREParser::Altergroup_headerContext *context) = 0;

    virtual std::any visitAltergroup_content(SPECTREParser::Altergroup_contentContext *context) = 0;

    virtual std::any visitAltergroup_footer(SPECTREParser::Altergroup_footerContext *context) = 0;

    virtual std::any visitAssert_statement(SPECTREParser::Assert_statementContext *context) = 0;

    virtual std::any visitCheck_statement(SPECTREParser::Check_statementContext *context) = 0;

    virtual std::any visitSave(SPECTREParser::SaveContext *context) = 0;

    virtual std::any visitOption(SPECTREParser::OptionContext *context) = 0;

    virtual std::any visitSet(SPECTREParser::SetContext *context) = 0;

    virtual std::any visitShell(SPECTREParser::ShellContext *context) = 0;

    virtual std::any visitInfo(SPECTREParser::InfoContext *context) = 0;

    virtual std::any visitNodeset(SPECTREParser::NodesetContext *context) = 0;

    virtual std::any visitIc(SPECTREParser::IcContext *context) = 0;

    virtual std::any visitStatistics(SPECTREParser::StatisticsContext *context) = 0;

    virtual std::any visitStatistics_header(SPECTREParser::Statistics_headerContext *context) = 0;

    virtual std::any visitStatistics_content(SPECTREParser::Statistics_contentContext *context) = 0;

    virtual std::any visitStatistics_footer(SPECTREParser::Statistics_footerContext *context) = 0;

    virtual std::any visitProcess(SPECTREParser::ProcessContext *context) = 0;

    virtual std::any visitMismatch(SPECTREParser::MismatchContext *context) = 0;

    virtual std::any visitCorrelate(SPECTREParser::CorrelateContext *context) = 0;

    virtual std::any visitTruncate(SPECTREParser::TruncateContext *context) = 0;

    virtual std::any visitVary(SPECTREParser::VaryContext *context) = 0;

    virtual std::any visitReliability(SPECTREParser::ReliabilityContext *context) = 0;

    virtual std::any visitReliability_header(SPECTREParser::Reliability_headerContext *context) = 0;

    virtual std::any visitReliability_content(SPECTREParser::Reliability_contentContext *context) = 0;

    virtual std::any visitReliability_footer(SPECTREParser::Reliability_footerContext *context) = 0;

    virtual std::any visitReliability_control(SPECTREParser::Reliability_controlContext *context) = 0;

    virtual std::any visitGlobal_declarations(SPECTREParser::Global_declarationsContext *context) = 0;

    virtual std::any visitComponent(SPECTREParser::ComponentContext *context) = 0;

    virtual std::any visitComponent_id(SPECTREParser::Component_idContext *context) = 0;

    virtual std::any visitComponent_master(SPECTREParser::Component_masterContext *context) = 0;

    virtual std::any visitComponent_attribute(SPECTREParser::Component_attributeContext *context) = 0;

    virtual std::any visitComponent_value(SPECTREParser::Component_valueContext *context) = 0;

    virtual std::any visitComponent_value_list(SPECTREParser::Component_value_listContext *context) = 0;

    virtual std::any visitComponent_analysis(SPECTREParser::Component_analysisContext *context) = 0;

    virtual std::any visitNode_list(SPECTREParser::Node_listContext *context) = 0;

    virtual std::any visitNode_list_item(SPECTREParser::Node_list_itemContext *context) = 0;

    virtual std::any visitNode_mapping(SPECTREParser::Node_mappingContext *context) = 0;

    virtual std::any visitNode_pair(SPECTREParser::Node_pairContext *context) = 0;

    virtual std::any visitNode_branch(SPECTREParser::Node_branchContext *context) = 0;

    virtual std::any visitNode(SPECTREParser::NodeContext *context) = 0;

    virtual std::any visitExpression(SPECTREParser::ExpressionContext *context) = 0;

    virtual std::any visitExpression_unary(SPECTREParser::Expression_unaryContext *context) = 0;

    virtual std::any visitExpression_function_call(SPECTREParser::Expression_function_callContext *context) = 0;

    virtual std::any visitExpression_pair(SPECTREParser::Expression_pairContext *context) = 0;

    virtual std::any visitExpression_scope(SPECTREParser::Expression_scopeContext *context) = 0;

    virtual std::any visitExpression_operator(SPECTREParser::Expression_operatorContext *context) = 0;

    virtual std::any visitExpression_atom(SPECTREParser::Expression_atomContext *context) = 0;

    virtual std::any visitParameter_list(SPECTREParser::Parameter_listContext *context) = 0;

    virtual std::any visitParameter_list_item(SPECTREParser::Parameter_list_itemContext *context) = 0;

    virtual std::any visitParameter_assign(SPECTREParser::Parameter_assignContext *context) = 0;

    virtual std::any visitParameter_id(SPECTREParser::Parameter_idContext *context) = 0;

    virtual std::any visitParameter_access(SPECTREParser::Parameter_accessContext *context) = 0;

    virtual std::any visitValue_access(SPECTREParser::Value_accessContext *context) = 0;

    virtual std::any visitValue_access_assign(SPECTREParser::Value_access_assignContext *context) = 0;

    virtual std::any visitTime_pair(SPECTREParser::Time_pairContext *context) = 0;

    virtual std::any visitTime_point(SPECTREParser::Time_pointContext *context) = 0;

    virtual std::any visitFilepath(SPECTREParser::FilepathContext *context) = 0;

    virtual std::any visitFilepath_element(SPECTREParser::Filepath_elementContext *context) = 0;

    virtual std::any visitKeyword(SPECTREParser::KeywordContext *context) = 0;

    virtual std::any visitAnalysis_type(SPECTREParser::Analysis_typeContext *context) = 0;

    virtual std::any visitComponent_type(SPECTREParser::Component_typeContext *context) = 0;


};

}  // namespace edacurry
