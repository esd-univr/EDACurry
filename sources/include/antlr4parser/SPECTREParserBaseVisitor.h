
// Generated from g4files/SPECTREParser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "SPECTREParserVisitor.h"


namespace edacurry {

/**
 * This class provides an empty implementation of SPECTREParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  SPECTREParserBaseVisitor : public SPECTREParserVisitor {
public:

  virtual std::any visitNetlist(SPECTREParser::NetlistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNetlist_title(SPECTREParser::Netlist_titleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNetlist_entity(SPECTREParser::Netlist_entityContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInclude(SPECTREParser::IncludeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStandard_include(SPECTREParser::Standard_includeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCpp_include(SPECTREParser::Cpp_includeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAhdl_include(SPECTREParser::Ahdl_includeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLang(SPECTREParser::LangContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLibrary(SPECTREParser::LibraryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLibrary_header(SPECTREParser::Library_headerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLibrary_content(SPECTREParser::Library_contentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLibrary_footer(SPECTREParser::Library_footerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSection(SPECTREParser::SectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSection_header(SPECTREParser::Section_headerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSection_content(SPECTREParser::Section_contentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSection_footer(SPECTREParser::Section_footerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAnalogmodel(SPECTREParser::AnalogmodelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubckt(SPECTREParser::SubcktContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubckt_header(SPECTREParser::Subckt_headerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubckt_content(SPECTREParser::Subckt_contentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubckt_footer(SPECTREParser::Subckt_footerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIf_statement(SPECTREParser::If_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIf_alternative(SPECTREParser::If_alternativeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIf_body(SPECTREParser::If_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAnalysis(SPECTREParser::AnalysisContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAc(SPECTREParser::AcContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAcmatch(SPECTREParser::AcmatchContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDc(SPECTREParser::DcContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDcmatch(SPECTREParser::DcmatchContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEnvlp(SPECTREParser::EnvlpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSp(SPECTREParser::SpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStb(SPECTREParser::StbContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSweep(SPECTREParser::SweepContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSweep_header(SPECTREParser::Sweep_headerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSweep_content(SPECTREParser::Sweep_contentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSweep_footer(SPECTREParser::Sweep_footerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTdr(SPECTREParser::TdrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTran(SPECTREParser::TranContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitXf(SPECTREParser::XfContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPac(SPECTREParser::PacContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPdisto(SPECTREParser::PdistoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPnoise(SPECTREParser::PnoiseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPsp(SPECTREParser::PspContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPss(SPECTREParser::PssContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPxf(SPECTREParser::PxfContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPz(SPECTREParser::PzContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQpac(SPECTREParser::QpacContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQpnoise(SPECTREParser::QpnoiseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQpsp(SPECTREParser::QpspContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQpss(SPECTREParser::QpssContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQpxf(SPECTREParser::QpxfContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSens(SPECTREParser::SensContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSens_output_variables_list(SPECTREParser::Sens_output_variables_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSens_design_parameters_list(SPECTREParser::Sens_design_parameters_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSens_analyses_list(SPECTREParser::Sens_analyses_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMontecarlo(SPECTREParser::MontecarloContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMontecarlo_header(SPECTREParser::Montecarlo_headerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMontecarlo_content(SPECTREParser::Montecarlo_contentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMontecarlo_export(SPECTREParser::Montecarlo_exportContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMontecarlo_footer(SPECTREParser::Montecarlo_footerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNoise(SPECTREParser::NoiseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitChecklimit(SPECTREParser::ChecklimitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGlobal(SPECTREParser::GlobalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitModel(SPECTREParser::ModelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitModel_name(SPECTREParser::Model_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitModel_master(SPECTREParser::Model_masterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitControl(SPECTREParser::ControlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlter(SPECTREParser::AlterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAltergroup(SPECTREParser::AltergroupContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAltergroup_header(SPECTREParser::Altergroup_headerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAltergroup_content(SPECTREParser::Altergroup_contentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAltergroup_footer(SPECTREParser::Altergroup_footerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssert_statement(SPECTREParser::Assert_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCheck_statement(SPECTREParser::Check_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSave(SPECTREParser::SaveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOption(SPECTREParser::OptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSet(SPECTREParser::SetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShell(SPECTREParser::ShellContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInfo(SPECTREParser::InfoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNodeset(SPECTREParser::NodesetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIc(SPECTREParser::IcContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatistics(SPECTREParser::StatisticsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatistics_header(SPECTREParser::Statistics_headerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatistics_content(SPECTREParser::Statistics_contentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatistics_footer(SPECTREParser::Statistics_footerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProcess(SPECTREParser::ProcessContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMismatch(SPECTREParser::MismatchContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCorrelate(SPECTREParser::CorrelateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTruncate(SPECTREParser::TruncateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVary(SPECTREParser::VaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReliability(SPECTREParser::ReliabilityContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReliability_header(SPECTREParser::Reliability_headerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReliability_content(SPECTREParser::Reliability_contentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReliability_footer(SPECTREParser::Reliability_footerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReliability_control(SPECTREParser::Reliability_controlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGlobal_declarations(SPECTREParser::Global_declarationsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComponent(SPECTREParser::ComponentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComponent_id(SPECTREParser::Component_idContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComponent_master(SPECTREParser::Component_masterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComponent_attribute(SPECTREParser::Component_attributeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComponent_value(SPECTREParser::Component_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComponent_value_list(SPECTREParser::Component_value_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComponent_analysis(SPECTREParser::Component_analysisContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNode_list(SPECTREParser::Node_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNode_list_item(SPECTREParser::Node_list_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNode_mapping(SPECTREParser::Node_mappingContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNode_pair(SPECTREParser::Node_pairContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNode_branch(SPECTREParser::Node_branchContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNode(SPECTREParser::NodeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression(SPECTREParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression_unary(SPECTREParser::Expression_unaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression_function_call(SPECTREParser::Expression_function_callContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression_pair(SPECTREParser::Expression_pairContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression_scope(SPECTREParser::Expression_scopeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression_operator(SPECTREParser::Expression_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression_atom(SPECTREParser::Expression_atomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameter_list(SPECTREParser::Parameter_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameter_list_item(SPECTREParser::Parameter_list_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameter_assign(SPECTREParser::Parameter_assignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameter_id(SPECTREParser::Parameter_idContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameter_access(SPECTREParser::Parameter_accessContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitValue_access(SPECTREParser::Value_accessContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitValue_access_assign(SPECTREParser::Value_access_assignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTime_pair(SPECTREParser::Time_pairContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTime_point(SPECTREParser::Time_pointContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFilepath(SPECTREParser::FilepathContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFilepath_element(SPECTREParser::Filepath_elementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitKeyword(SPECTREParser::KeywordContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAnalysis_type(SPECTREParser::Analysis_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComponent_type(SPECTREParser::Component_typeContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace edacurry
