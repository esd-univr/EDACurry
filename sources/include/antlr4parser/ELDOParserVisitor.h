
// Generated from g4files/ELDOParser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "ELDOParser.h"


namespace edacurry {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by ELDOParser.
 */
class  ELDOParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by ELDOParser.
   */
    virtual std::any visitNetlist(ELDOParser::NetlistContext *context) = 0;

    virtual std::any visitNetlist_title(ELDOParser::Netlist_titleContext *context) = 0;

    virtual std::any visitNetlist_entity(ELDOParser::Netlist_entityContext *context) = 0;

    virtual std::any visitInclude(ELDOParser::IncludeContext *context) = 0;

    virtual std::any visitStandard_include(ELDOParser::Standard_includeContext *context) = 0;

    virtual std::any visitVerilog_include(ELDOParser::Verilog_includeContext *context) = 0;

    virtual std::any visitDspf_include(ELDOParser::Dspf_includeContext *context) = 0;

    virtual std::any visitLibrary(ELDOParser::LibraryContext *context) = 0;

    virtual std::any visitLibrary_key(ELDOParser::Library_keyContext *context) = 0;

    virtual std::any visitLibrary_path(ELDOParser::Library_pathContext *context) = 0;

    virtual std::any visitLibrary_name(ELDOParser::Library_nameContext *context) = 0;

    virtual std::any visitLibrary_def(ELDOParser::Library_defContext *context) = 0;

    virtual std::any visitLibrary_def_header(ELDOParser::Library_def_headerContext *context) = 0;

    virtual std::any visitLibrary_def_content(ELDOParser::Library_def_contentContext *context) = 0;

    virtual std::any visitLibrary_def_footer(ELDOParser::Library_def_footerContext *context) = 0;

    virtual std::any visitSubckt(ELDOParser::SubcktContext *context) = 0;

    virtual std::any visitSubckt_header(ELDOParser::Subckt_headerContext *context) = 0;

    virtual std::any visitSubckt_content(ELDOParser::Subckt_contentContext *context) = 0;

    virtual std::any visitSubckt_footer(ELDOParser::Subckt_footerContext *context) = 0;

    virtual std::any visitAnalysis(ELDOParser::AnalysisContext *context) = 0;

    virtual std::any visitAc(ELDOParser::AcContext *context) = 0;

    virtual std::any visitAc_parameter_driven(ELDOParser::Ac_parameter_drivenContext *context) = 0;

    virtual std::any visitAc_data_driven(ELDOParser::Ac_data_drivenContext *context) = 0;

    virtual std::any visitAc_list_driven(ELDOParser::Ac_list_drivenContext *context) = 0;

    virtual std::any visitAc_adaptive(ELDOParser::Ac_adaptiveContext *context) = 0;

    virtual std::any visitAge(ELDOParser::AgeContext *context) = 0;

    virtual std::any visitChecksoa(ELDOParser::ChecksoaContext *context) = 0;

    virtual std::any visitDc(ELDOParser::DcContext *context) = 0;

    virtual std::any visitDc_component_analysis(ELDOParser::Dc_component_analysisContext *context) = 0;

    virtual std::any visitDc_source_analysis(ELDOParser::Dc_source_analysisContext *context) = 0;

    virtual std::any visitDc_temperature_analysis(ELDOParser::Dc_temperature_analysisContext *context) = 0;

    virtual std::any visitDc_parameter_analysis(ELDOParser::Dc_parameter_analysisContext *context) = 0;

    virtual std::any visitDc_data_driven_analysis(ELDOParser::Dc_data_driven_analysisContext *context) = 0;

    virtual std::any visitDchiz(ELDOParser::DchizContext *context) = 0;

    virtual std::any visitDcmismatch(ELDOParser::DcmismatchContext *context) = 0;

    virtual std::any visitDex(ELDOParser::DexContext *context) = 0;

    virtual std::any visitDsp(ELDOParser::DspContext *context) = 0;

    virtual std::any visitDspmod(ELDOParser::DspmodContext *context) = 0;

    virtual std::any visitFour(ELDOParser::FourContext *context) = 0;

    virtual std::any visitLstb(ELDOParser::LstbContext *context) = 0;

    virtual std::any visitMc(ELDOParser::McContext *context) = 0;

    virtual std::any visitNoise(ELDOParser::NoiseContext *context) = 0;

    virtual std::any visitNoisetran(ELDOParser::NoisetranContext *context) = 0;

    virtual std::any visitOp(ELDOParser::OpContext *context) = 0;

    virtual std::any visitOp_selective(ELDOParser::Op_selectiveContext *context) = 0;

    virtual std::any visitOp_time_based(ELDOParser::Op_time_basedContext *context) = 0;

    virtual std::any visitOp_dc_based(ELDOParser::Op_dc_basedContext *context) = 0;

    virtual std::any visitOptfour(ELDOParser::OptfourContext *context) = 0;

    virtual std::any visitOptimize(ELDOParser::OptimizeContext *context) = 0;

    virtual std::any visitOptnoise(ELDOParser::OptnoiseContext *context) = 0;

    virtual std::any visitPz(ELDOParser::PzContext *context) = 0;

    virtual std::any visitRamp(ELDOParser::RampContext *context) = 0;

    virtual std::any visitSens(ELDOParser::SensContext *context) = 0;

    virtual std::any visitSensac(ELDOParser::SensacContext *context) = 0;

    virtual std::any visitSensparam(ELDOParser::SensparamContext *context) = 0;

    virtual std::any visitSnf(ELDOParser::SnfContext *context) = 0;

    virtual std::any visitSolve(ELDOParser::SolveContext *context) = 0;

    virtual std::any visitSolve_parameter(ELDOParser::Solve_parameterContext *context) = 0;

    virtual std::any visitSolve_object(ELDOParser::Solve_objectContext *context) = 0;

    virtual std::any visitSolve_component(ELDOParser::Solve_componentContext *context) = 0;

    virtual std::any visitTf(ELDOParser::TfContext *context) = 0;

    virtual std::any visitTran(ELDOParser::TranContext *context) = 0;

    virtual std::any visitTran_point_driven(ELDOParser::Tran_point_drivenContext *context) = 0;

    virtual std::any visitTran_parameterized(ELDOParser::Tran_parameterizedContext *context) = 0;

    virtual std::any visitTran_data_driven(ELDOParser::Tran_data_drivenContext *context) = 0;

    virtual std::any visitWcase(ELDOParser::WcaseContext *context) = 0;

    virtual std::any visitExtract(ELDOParser::ExtractContext *context) = 0;

    virtual std::any visitGlobal(ELDOParser::GlobalContext *context) = 0;

    virtual std::any visitModel(ELDOParser::ModelContext *context) = 0;

    virtual std::any visitModel_lib(ELDOParser::Model_libContext *context) = 0;

    virtual std::any visitModel_name(ELDOParser::Model_nameContext *context) = 0;

    virtual std::any visitModel_master(ELDOParser::Model_masterContext *context) = 0;

    virtual std::any visitModel_lib_type(ELDOParser::Model_lib_typeContext *context) = 0;

    virtual std::any visitControl(ELDOParser::ControlContext *context) = 0;

    virtual std::any visitAlter(ELDOParser::AlterContext *context) = 0;

    virtual std::any visitAlter_definition(ELDOParser::Alter_definitionContext *context) = 0;

    virtual std::any visitAlter_header(ELDOParser::Alter_headerContext *context) = 0;

    virtual std::any visitAlter_content(ELDOParser::Alter_contentContext *context) = 0;

    virtual std::any visitAlter_footer(ELDOParser::Alter_footerContext *context) = 0;

    virtual std::any visitSave(ELDOParser::SaveContext *context) = 0;

    virtual std::any visitSave_file(ELDOParser::Save_fileContext *context) = 0;

    virtual std::any visitSave_when(ELDOParser::Save_whenContext *context) = 0;

    virtual std::any visitOption(ELDOParser::OptionContext *context) = 0;

    virtual std::any visitNodeset(ELDOParser::NodesetContext *context) = 0;

    virtual std::any visitCall_tcl(ELDOParser::Call_tclContext *context) = 0;

    virtual std::any visitCall_tcl_when(ELDOParser::Call_tcl_whenContext *context) = 0;

    virtual std::any visitUse_tcl(ELDOParser::Use_tclContext *context) = 0;

    virtual std::any visitDefmac(ELDOParser::DefmacContext *context) = 0;

    virtual std::any visitChrent(ELDOParser::ChrentContext *context) = 0;

    virtual std::any visitChrent_behaviour(ELDOParser::Chrent_behaviourContext *context) = 0;

    virtual std::any visitChrent_point(ELDOParser::Chrent_pointContext *context) = 0;

    virtual std::any visitChrent_pair(ELDOParser::Chrent_pairContext *context) = 0;

    virtual std::any visitIc(ELDOParser::IcContext *context) = 0;

    virtual std::any visitIc_content(ELDOParser::Ic_contentContext *context) = 0;

    virtual std::any visitIc_subckt(ELDOParser::Ic_subcktContext *context) = 0;

    virtual std::any visitPrint(ELDOParser::PrintContext *context) = 0;

    virtual std::any visitPlot(ELDOParser::PlotContext *context) = 0;

    virtual std::any visitFfile(ELDOParser::FfileContext *context) = 0;

    virtual std::any visitFfile_tabulation(ELDOParser::Ffile_tabulationContext *context) = 0;

    virtual std::any visitFfile_singleline(ELDOParser::Ffile_singlelineContext *context) = 0;

    virtual std::any visitFfile_unit(ELDOParser::Ffile_unitContext *context) = 0;

    virtual std::any visitFfile_storage_format(ELDOParser::Ffile_storage_formatContext *context) = 0;

    virtual std::any visitProbe(ELDOParser::ProbeContext *context) = 0;

    virtual std::any visitDefwave(ELDOParser::DefwaveContext *context) = 0;

    virtual std::any visitTemp(ELDOParser::TempContext *context) = 0;

    virtual std::any visitMeas(ELDOParser::MeasContext *context) = 0;

    virtual std::any visitMeas_info(ELDOParser::Meas_infoContext *context) = 0;

    virtual std::any visitMeas_vect(ELDOParser::Meas_vectContext *context) = 0;

    virtual std::any visitMeas_catvect(ELDOParser::Meas_catvectContext *context) = 0;

    virtual std::any visitMeas_label_name(ELDOParser::Meas_label_nameContext *context) = 0;

    virtual std::any visitMeas_configuration(ELDOParser::Meas_configurationContext *context) = 0;

    virtual std::any visitMeas_find(ELDOParser::Meas_findContext *context) = 0;

    virtual std::any visitMeas_at(ELDOParser::Meas_atContext *context) = 0;

    virtual std::any visitMeas_when(ELDOParser::Meas_whenContext *context) = 0;

    virtual std::any visitMeas_derivative(ELDOParser::Meas_derivativeContext *context) = 0;

    virtual std::any visitMeas_param(ELDOParser::Meas_paramContext *context) = 0;

    virtual std::any visitMeas_trig(ELDOParser::Meas_trigContext *context) = 0;

    virtual std::any visitMeas_targ(ELDOParser::Meas_targContext *context) = 0;

    virtual std::any visitConnect(ELDOParser::ConnectContext *context) = 0;

    virtual std::any visitGlobal_declarations(ELDOParser::Global_declarationsContext *context) = 0;

    virtual std::any visitComponent(ELDOParser::ComponentContext *context) = 0;

    virtual std::any visitComponent_type(ELDOParser::Component_typeContext *context) = 0;

    virtual std::any visitComponent_attribute(ELDOParser::Component_attributeContext *context) = 0;

    virtual std::any visitComponent_value(ELDOParser::Component_valueContext *context) = 0;

    virtual std::any visitComponent_parameter_list(ELDOParser::Component_parameter_listContext *context) = 0;

    virtual std::any visitComponent_analysis(ELDOParser::Component_analysisContext *context) = 0;

    virtual std::any visitComponent_positional_keywork(ELDOParser::Component_positional_keyworkContext *context) = 0;

    virtual std::any visitComponent_pin_list(ELDOParser::Component_pin_listContext *context) = 0;

    virtual std::any visitComponent_port_list(ELDOParser::Component_port_listContext *context) = 0;

    virtual std::any visitComponent_net_list(ELDOParser::Component_net_listContext *context) = 0;

    virtual std::any visitComponent_coupling_list(ELDOParser::Component_coupling_listContext *context) = 0;

    virtual std::any visitComponent_table(ELDOParser::Component_tableContext *context) = 0;

    virtual std::any visitComponent_value_list(ELDOParser::Component_value_listContext *context) = 0;

    virtual std::any visitInterp_type(ELDOParser::Interp_typeContext *context) = 0;

    virtual std::any visitResistor(ELDOParser::ResistorContext *context) = 0;

    virtual std::any visitCapacitor(ELDOParser::CapacitorContext *context) = 0;

    virtual std::any visitInductor(ELDOParser::InductorContext *context) = 0;

    virtual std::any visitCoupled_inductor(ELDOParser::Coupled_inductorContext *context) = 0;

    virtual std::any visitDiffusion_resistor(ELDOParser::Diffusion_resistorContext *context) = 0;

    virtual std::any visitTransmission_line(ELDOParser::Transmission_lineContext *context) = 0;

    virtual std::any visitLossy_transmission_line(ELDOParser::Lossy_transmission_lineContext *context) = 0;

    virtual std::any visitLtl_w_model(ELDOParser::Ltl_w_modelContext *context) = 0;

    virtual std::any visitLtl_u_model(ELDOParser::Ltl_u_modelContext *context) = 0;

    virtual std::any visitJunction_diode(ELDOParser::Junction_diodeContext *context) = 0;

    virtual std::any visitBjt(ELDOParser::BjtContext *context) = 0;

    virtual std::any visitJfet(ELDOParser::JfetContext *context) = 0;

    virtual std::any visitMosfet(ELDOParser::MosfetContext *context) = 0;

    virtual std::any visitSubckt_instance(ELDOParser::Subckt_instanceContext *context) = 0;

    virtual std::any visitIvsource(ELDOParser::IvsourceContext *context) = 0;

    virtual std::any visitIcsource(ELDOParser::IcsourceContext *context) = 0;

    virtual std::any visitVcvs(ELDOParser::VcvsContext *context) = 0;

    virtual std::any visitCccs(ELDOParser::CccsContext *context) = 0;

    virtual std::any visitVccs(ELDOParser::VccsContext *context) = 0;

    virtual std::any visitCcvs(ELDOParser::CcvsContext *context) = 0;

    virtual std::any visitNoise_function(ELDOParser::Noise_functionContext *context) = 0;

    virtual std::any visitSw(ELDOParser::SwContext *context) = 0;

    virtual std::any visitOperational_amplifier(ELDOParser::Operational_amplifierContext *context) = 0;

    virtual std::any visitTwo_input_gate(ELDOParser::Two_input_gateContext *context) = 0;

    virtual std::any visitEnd(ELDOParser::EndContext *context) = 0;

    virtual std::any visitExpression(ELDOParser::ExpressionContext *context) = 0;

    virtual std::any visitExpression_unary(ELDOParser::Expression_unaryContext *context) = 0;

    virtual std::any visitExpression_function_call(ELDOParser::Expression_function_callContext *context) = 0;

    virtual std::any visitExpression_list(ELDOParser::Expression_listContext *context) = 0;

    virtual std::any visitExpression_operator(ELDOParser::Expression_operatorContext *context) = 0;

    virtual std::any visitExpression_atom(ELDOParser::Expression_atomContext *context) = 0;

    virtual std::any visitNode_list(ELDOParser::Node_listContext *context) = 0;

    virtual std::any visitNode_list_item(ELDOParser::Node_list_itemContext *context) = 0;

    virtual std::any visitNode_mapping(ELDOParser::Node_mappingContext *context) = 0;

    virtual std::any visitNode(ELDOParser::NodeContext *context) = 0;

    virtual std::any visitParameter_list(ELDOParser::Parameter_listContext *context) = 0;

    virtual std::any visitParameter_list_item(ELDOParser::Parameter_list_itemContext *context) = 0;

    virtual std::any visitParameter(ELDOParser::ParameterContext *context) = 0;

    virtual std::any visitParameter_lhs(ELDOParser::Parameter_lhsContext *context) = 0;

    virtual std::any visitParameter_rhs(ELDOParser::Parameter_rhsContext *context) = 0;

    virtual std::any visitFilepath(ELDOParser::FilepathContext *context) = 0;

    virtual std::any visitFilepath_element(ELDOParser::Filepath_elementContext *context) = 0;

    virtual std::any visitEnd_of_line(ELDOParser::End_of_lineContext *context) = 0;


};

}  // namespace edacurry
