
// Generated from g4files/ELDOParser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "ELDOParserVisitor.h"


namespace edacurry {

/**
 * This class provides an empty implementation of ELDOParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  ELDOParserBaseVisitor : public ELDOParserVisitor {
public:

  virtual std::any visitNetlist(ELDOParser::NetlistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNetlist_title(ELDOParser::Netlist_titleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNetlist_entity(ELDOParser::Netlist_entityContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInclude(ELDOParser::IncludeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStandard_include(ELDOParser::Standard_includeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVerilog_include(ELDOParser::Verilog_includeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDspf_include(ELDOParser::Dspf_includeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLibrary(ELDOParser::LibraryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLibrary_key(ELDOParser::Library_keyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLibrary_path(ELDOParser::Library_pathContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLibrary_name(ELDOParser::Library_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLibrary_def(ELDOParser::Library_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLibrary_def_header(ELDOParser::Library_def_headerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLibrary_def_content(ELDOParser::Library_def_contentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLibrary_def_footer(ELDOParser::Library_def_footerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubckt(ELDOParser::SubcktContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubckt_header(ELDOParser::Subckt_headerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubckt_content(ELDOParser::Subckt_contentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubckt_footer(ELDOParser::Subckt_footerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAnalysis(ELDOParser::AnalysisContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAc(ELDOParser::AcContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAc_parameter_driven(ELDOParser::Ac_parameter_drivenContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAc_data_driven(ELDOParser::Ac_data_drivenContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAc_list_driven(ELDOParser::Ac_list_drivenContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAc_adaptive(ELDOParser::Ac_adaptiveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAge(ELDOParser::AgeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitChecksoa(ELDOParser::ChecksoaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDc(ELDOParser::DcContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDc_component_analysis(ELDOParser::Dc_component_analysisContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDc_source_analysis(ELDOParser::Dc_source_analysisContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDc_temperature_analysis(ELDOParser::Dc_temperature_analysisContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDc_parameter_analysis(ELDOParser::Dc_parameter_analysisContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDc_data_driven_analysis(ELDOParser::Dc_data_driven_analysisContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDchiz(ELDOParser::DchizContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDcmismatch(ELDOParser::DcmismatchContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDex(ELDOParser::DexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDsp(ELDOParser::DspContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDspmod(ELDOParser::DspmodContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFour(ELDOParser::FourContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLstb(ELDOParser::LstbContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMc(ELDOParser::McContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNoise(ELDOParser::NoiseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNoisetran(ELDOParser::NoisetranContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOp(ELDOParser::OpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOp_selective(ELDOParser::Op_selectiveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOp_time_based(ELDOParser::Op_time_basedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOp_dc_based(ELDOParser::Op_dc_basedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOptfour(ELDOParser::OptfourContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOptimize(ELDOParser::OptimizeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOptnoise(ELDOParser::OptnoiseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPz(ELDOParser::PzContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRamp(ELDOParser::RampContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSens(ELDOParser::SensContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSensac(ELDOParser::SensacContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSensparam(ELDOParser::SensparamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSnf(ELDOParser::SnfContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSolve(ELDOParser::SolveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSolve_parameter(ELDOParser::Solve_parameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSolve_object(ELDOParser::Solve_objectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSolve_component(ELDOParser::Solve_componentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTf(ELDOParser::TfContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTran(ELDOParser::TranContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTran_point_driven(ELDOParser::Tran_point_drivenContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTran_parameterized(ELDOParser::Tran_parameterizedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTran_data_driven(ELDOParser::Tran_data_drivenContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWcase(ELDOParser::WcaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExtract(ELDOParser::ExtractContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGlobal(ELDOParser::GlobalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitModel(ELDOParser::ModelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitModel_lib(ELDOParser::Model_libContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitModel_name(ELDOParser::Model_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitModel_master(ELDOParser::Model_masterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitModel_lib_type(ELDOParser::Model_lib_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitControl(ELDOParser::ControlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlter(ELDOParser::AlterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlter_definition(ELDOParser::Alter_definitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlter_header(ELDOParser::Alter_headerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlter_content(ELDOParser::Alter_contentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAlter_footer(ELDOParser::Alter_footerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSave(ELDOParser::SaveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSave_file(ELDOParser::Save_fileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSave_when(ELDOParser::Save_whenContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOption(ELDOParser::OptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNodeset(ELDOParser::NodesetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCall_tcl(ELDOParser::Call_tclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCall_tcl_when(ELDOParser::Call_tcl_whenContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUse_tcl(ELDOParser::Use_tclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDefmac(ELDOParser::DefmacContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitChrent(ELDOParser::ChrentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitChrent_behaviour(ELDOParser::Chrent_behaviourContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitChrent_point(ELDOParser::Chrent_pointContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitChrent_pair(ELDOParser::Chrent_pairContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIc(ELDOParser::IcContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIc_content(ELDOParser::Ic_contentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIc_subckt(ELDOParser::Ic_subcktContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrint(ELDOParser::PrintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPlot(ELDOParser::PlotContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFfile(ELDOParser::FfileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFfile_tabulation(ELDOParser::Ffile_tabulationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFfile_singleline(ELDOParser::Ffile_singlelineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFfile_unit(ELDOParser::Ffile_unitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFfile_storage_format(ELDOParser::Ffile_storage_formatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProbe(ELDOParser::ProbeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDefwave(ELDOParser::DefwaveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTemp(ELDOParser::TempContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMeas(ELDOParser::MeasContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMeas_info(ELDOParser::Meas_infoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMeas_vect(ELDOParser::Meas_vectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMeas_catvect(ELDOParser::Meas_catvectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMeas_label_name(ELDOParser::Meas_label_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMeas_configuration(ELDOParser::Meas_configurationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMeas_find(ELDOParser::Meas_findContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMeas_at(ELDOParser::Meas_atContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMeas_when(ELDOParser::Meas_whenContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMeas_derivative(ELDOParser::Meas_derivativeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMeas_param(ELDOParser::Meas_paramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMeas_trig(ELDOParser::Meas_trigContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMeas_targ(ELDOParser::Meas_targContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConnect(ELDOParser::ConnectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGlobal_declarations(ELDOParser::Global_declarationsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComponent(ELDOParser::ComponentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComponent_type(ELDOParser::Component_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComponent_attribute(ELDOParser::Component_attributeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComponent_value(ELDOParser::Component_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComponent_parameter_list(ELDOParser::Component_parameter_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComponent_analysis(ELDOParser::Component_analysisContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComponent_positional_keywork(ELDOParser::Component_positional_keyworkContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComponent_pin_list(ELDOParser::Component_pin_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComponent_port_list(ELDOParser::Component_port_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComponent_net_list(ELDOParser::Component_net_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComponent_coupling_list(ELDOParser::Component_coupling_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComponent_table(ELDOParser::Component_tableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComponent_value_list(ELDOParser::Component_value_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInterp_type(ELDOParser::Interp_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitResistor(ELDOParser::ResistorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCapacitor(ELDOParser::CapacitorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInductor(ELDOParser::InductorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCoupled_inductor(ELDOParser::Coupled_inductorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiffusion_resistor(ELDOParser::Diffusion_resistorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTransmission_line(ELDOParser::Transmission_lineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLossy_transmission_line(ELDOParser::Lossy_transmission_lineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLtl_w_model(ELDOParser::Ltl_w_modelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLtl_u_model(ELDOParser::Ltl_u_modelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitJunction_diode(ELDOParser::Junction_diodeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBjt(ELDOParser::BjtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitJfet(ELDOParser::JfetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMosfet(ELDOParser::MosfetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubckt_instance(ELDOParser::Subckt_instanceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIvsource(ELDOParser::IvsourceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIcsource(ELDOParser::IcsourceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVcvs(ELDOParser::VcvsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCccs(ELDOParser::CccsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVccs(ELDOParser::VccsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCcvs(ELDOParser::CcvsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNoise_function(ELDOParser::Noise_functionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSw(ELDOParser::SwContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperational_amplifier(ELDOParser::Operational_amplifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTwo_input_gate(ELDOParser::Two_input_gateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEnd(ELDOParser::EndContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression(ELDOParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression_unary(ELDOParser::Expression_unaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression_function_call(ELDOParser::Expression_function_callContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression_list(ELDOParser::Expression_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression_operator(ELDOParser::Expression_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression_atom(ELDOParser::Expression_atomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNode_list(ELDOParser::Node_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNode_list_item(ELDOParser::Node_list_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNode_mapping(ELDOParser::Node_mappingContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNode(ELDOParser::NodeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameter_list(ELDOParser::Parameter_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameter_list_item(ELDOParser::Parameter_list_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameter(ELDOParser::ParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameter_lhs(ELDOParser::Parameter_lhsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameter_rhs(ELDOParser::Parameter_rhsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFilepath(ELDOParser::FilepathContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFilepath_element(ELDOParser::Filepath_elementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEnd_of_line(ELDOParser::End_of_lineContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace edacurry
