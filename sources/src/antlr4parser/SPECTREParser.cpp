
// Generated from g4files/SPECTREParser.g4 by ANTLR 4.7.1


#include "SPECTREParserListener.h"
#include "SPECTREParserVisitor.h"

#include "SPECTREParser.h"


using namespace antlrcpp;
using namespace edacurry;
using namespace antlr4;

SPECTREParser::SPECTREParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

SPECTREParser::~SPECTREParser() {
  delete _interpreter;
}

std::string SPECTREParser::getGrammarFileName() const {
  return "SPECTREParser.g4";
}

const std::vector<std::string>& SPECTREParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& SPECTREParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- NetlistContext ------------------------------------------------------------------

SPECTREParser::NetlistContext::NetlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::NetlistContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

std::vector<tree::TerminalNode *> SPECTREParser::NetlistContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::NetlistContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}

SPECTREParser::LangContext* SPECTREParser::NetlistContext::lang() {
  return getRuleContext<SPECTREParser::LangContext>(0);
}

std::vector<SPECTREParser::Netlist_entityContext *> SPECTREParser::NetlistContext::netlist_entity() {
  return getRuleContexts<SPECTREParser::Netlist_entityContext>();
}

SPECTREParser::Netlist_entityContext* SPECTREParser::NetlistContext::netlist_entity(size_t i) {
  return getRuleContext<SPECTREParser::Netlist_entityContext>(i);
}


size_t SPECTREParser::NetlistContext::getRuleIndex() const {
  return SPECTREParser::RuleNetlist;
}

void SPECTREParser::NetlistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNetlist(this);
}

void SPECTREParser::NetlistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNetlist(this);
}


antlrcpp::Any SPECTREParser::NetlistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitNetlist(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::NetlistContext* SPECTREParser::netlist() {
  NetlistContext *_localctx = _tracker.createInstance<NetlistContext>(_ctx, getState());
  enterRule(_localctx, 0, SPECTREParser::RuleNetlist);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(267);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SPECTREParser::NL) {
      setState(264);
      match(SPECTREParser::NL);
      setState(269);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(276);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SPECTREParser::SIMULATOR) {
      setState(270);
      lang();
      setState(272); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(271);
        match(SPECTREParser::NL);
        setState(274); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == SPECTREParser::NL);
    }
    setState(287);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SPECTREParser::GLOBAL)
      | (1ULL << SPECTREParser::INCLUDE)
      | (1ULL << SPECTREParser::CPP_INCLUDE)
      | (1ULL << SPECTREParser::AHDL_INCLUDE)
      | (1ULL << SPECTREParser::LIBRARY)
      | (1ULL << SPECTREParser::SECTION)
      | (1ULL << SPECTREParser::SUBCKT)
      | (1ULL << SPECTREParser::INLINE_SUBCKT)
      | (1ULL << SPECTREParser::MODEL)
      | (1ULL << SPECTREParser::SAVE)
      | (1ULL << SPECTREParser::NODESET)
      | (1ULL << SPECTREParser::IC)
      | (1ULL << SPECTREParser::PARAMETERS)
      | (1ULL << SPECTREParser::STATISTICS)
      | (1ULL << SPECTREParser::AC)
      | (1ULL << SPECTREParser::ACMATCH)
      | (1ULL << SPECTREParser::DC)
      | (1ULL << SPECTREParser::DCMATCH)
      | (1ULL << SPECTREParser::ENVLP)
      | (1ULL << SPECTREParser::SP)
      | (1ULL << SPECTREParser::STB)
      | (1ULL << SPECTREParser::SWEEP)
      | (1ULL << SPECTREParser::TDR)
      | (1ULL << SPECTREParser::TRAN)
      | (1ULL << SPECTREParser::XF)
      | (1ULL << SPECTREParser::PAC)
      | (1ULL << SPECTREParser::PDISTO))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (SPECTREParser::PNOISE - 64))
      | (1ULL << (SPECTREParser::PSP - 64))
      | (1ULL << (SPECTREParser::PSS - 64))
      | (1ULL << (SPECTREParser::PXF - 64))
      | (1ULL << (SPECTREParser::PZ - 64))
      | (1ULL << (SPECTREParser::QPAC - 64))
      | (1ULL << (SPECTREParser::QPNOISE - 64))
      | (1ULL << (SPECTREParser::QPSP - 64))
      | (1ULL << (SPECTREParser::QPSS - 64))
      | (1ULL << (SPECTREParser::QPXF - 64))
      | (1ULL << (SPECTREParser::SENS - 64)))) != 0) || ((((_la - 191) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 191)) & ((1ULL << (SPECTREParser::OPEN_ROUND - 191))
      | (1ULL << (SPECTREParser::NUMBER - 191))
      | (1ULL << (SPECTREParser::ID - 191)))) != 0)) {
      setState(278);
      netlist_entity();
      setState(282);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SPECTREParser::NL) {
        setState(279);
        match(SPECTREParser::NL);
        setState(284);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(289);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(290);
    match(SPECTREParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Netlist_titleContext ------------------------------------------------------------------

SPECTREParser::Netlist_titleContext::Netlist_titleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Netlist_titleContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

std::vector<tree::TerminalNode *> SPECTREParser::Netlist_titleContext::ID() {
  return getTokens(SPECTREParser::ID);
}

tree::TerminalNode* SPECTREParser::Netlist_titleContext::ID(size_t i) {
  return getToken(SPECTREParser::ID, i);
}

std::vector<tree::TerminalNode *> SPECTREParser::Netlist_titleContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::Netlist_titleContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::Netlist_titleContext::getRuleIndex() const {
  return SPECTREParser::RuleNetlist_title;
}

void SPECTREParser::Netlist_titleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNetlist_title(this);
}

void SPECTREParser::Netlist_titleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNetlist_title(this);
}


antlrcpp::Any SPECTREParser::Netlist_titleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitNetlist_title(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Netlist_titleContext* SPECTREParser::netlist_title() {
  Netlist_titleContext *_localctx = _tracker.createInstance<Netlist_titleContext>(_ctx, getState());
  enterRule(_localctx, 2, SPECTREParser::RuleNetlist_title);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(293); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(292);
      match(SPECTREParser::ID);
      setState(295); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == SPECTREParser::ID);
    setState(304);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      setState(300);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SPECTREParser::NL) {
        setState(297);
        match(SPECTREParser::NL);
        setState(302);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 2: {
      setState(303);
      match(SPECTREParser::EOF);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Netlist_entityContext ------------------------------------------------------------------

SPECTREParser::Netlist_entityContext::Netlist_entityContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SPECTREParser::IncludeContext* SPECTREParser::Netlist_entityContext::include() {
  return getRuleContext<SPECTREParser::IncludeContext>(0);
}

SPECTREParser::LibraryContext* SPECTREParser::Netlist_entityContext::library() {
  return getRuleContext<SPECTREParser::LibraryContext>(0);
}

SPECTREParser::SubcktContext* SPECTREParser::Netlist_entityContext::subckt() {
  return getRuleContext<SPECTREParser::SubcktContext>(0);
}

SPECTREParser::AnalysisContext* SPECTREParser::Netlist_entityContext::analysis() {
  return getRuleContext<SPECTREParser::AnalysisContext>(0);
}

SPECTREParser::GlobalContext* SPECTREParser::Netlist_entityContext::global() {
  return getRuleContext<SPECTREParser::GlobalContext>(0);
}

SPECTREParser::ModelContext* SPECTREParser::Netlist_entityContext::model() {
  return getRuleContext<SPECTREParser::ModelContext>(0);
}

SPECTREParser::Global_declarationsContext* SPECTREParser::Netlist_entityContext::global_declarations() {
  return getRuleContext<SPECTREParser::Global_declarationsContext>(0);
}

SPECTREParser::ControlContext* SPECTREParser::Netlist_entityContext::control() {
  return getRuleContext<SPECTREParser::ControlContext>(0);
}

SPECTREParser::ComponentContext* SPECTREParser::Netlist_entityContext::component() {
  return getRuleContext<SPECTREParser::ComponentContext>(0);
}

SPECTREParser::SectionContext* SPECTREParser::Netlist_entityContext::section() {
  return getRuleContext<SPECTREParser::SectionContext>(0);
}

SPECTREParser::AnalogmodelContext* SPECTREParser::Netlist_entityContext::analogmodel() {
  return getRuleContext<SPECTREParser::AnalogmodelContext>(0);
}

SPECTREParser::StatisticsContext* SPECTREParser::Netlist_entityContext::statistics() {
  return getRuleContext<SPECTREParser::StatisticsContext>(0);
}


size_t SPECTREParser::Netlist_entityContext::getRuleIndex() const {
  return SPECTREParser::RuleNetlist_entity;
}

void SPECTREParser::Netlist_entityContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNetlist_entity(this);
}

void SPECTREParser::Netlist_entityContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNetlist_entity(this);
}


antlrcpp::Any SPECTREParser::Netlist_entityContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitNetlist_entity(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Netlist_entityContext* SPECTREParser::netlist_entity() {
  Netlist_entityContext *_localctx = _tracker.createInstance<Netlist_entityContext>(_ctx, getState());
  enterRule(_localctx, 4, SPECTREParser::RuleNetlist_entity);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(318);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(306);
      include();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(307);
      library();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(308);
      subckt();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(309);
      analysis();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(310);
      global();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(311);
      model();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(312);
      global_declarations();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(313);
      control();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(314);
      component();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(315);
      section();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(316);
      analogmodel();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(317);
      statistics();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IncludeContext ------------------------------------------------------------------

SPECTREParser::IncludeContext::IncludeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SPECTREParser::Standard_includeContext* SPECTREParser::IncludeContext::standard_include() {
  return getRuleContext<SPECTREParser::Standard_includeContext>(0);
}

SPECTREParser::Cpp_includeContext* SPECTREParser::IncludeContext::cpp_include() {
  return getRuleContext<SPECTREParser::Cpp_includeContext>(0);
}

SPECTREParser::Ahdl_includeContext* SPECTREParser::IncludeContext::ahdl_include() {
  return getRuleContext<SPECTREParser::Ahdl_includeContext>(0);
}


size_t SPECTREParser::IncludeContext::getRuleIndex() const {
  return SPECTREParser::RuleInclude;
}

void SPECTREParser::IncludeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInclude(this);
}

void SPECTREParser::IncludeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInclude(this);
}


antlrcpp::Any SPECTREParser::IncludeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitInclude(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::IncludeContext* SPECTREParser::include() {
  IncludeContext *_localctx = _tracker.createInstance<IncludeContext>(_ctx, getState());
  enterRule(_localctx, 6, SPECTREParser::RuleInclude);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(323);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SPECTREParser::INCLUDE: {
        enterOuterAlt(_localctx, 1);
        setState(320);
        standard_include();
        break;
      }

      case SPECTREParser::CPP_INCLUDE: {
        enterOuterAlt(_localctx, 2);
        setState(321);
        cpp_include();
        break;
      }

      case SPECTREParser::AHDL_INCLUDE: {
        enterOuterAlt(_localctx, 3);
        setState(322);
        ahdl_include();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Standard_includeContext ------------------------------------------------------------------

SPECTREParser::Standard_includeContext::Standard_includeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Standard_includeContext::INCLUDE() {
  return getToken(SPECTREParser::INCLUDE, 0);
}

SPECTREParser::FilepathContext* SPECTREParser::Standard_includeContext::filepath() {
  return getRuleContext<SPECTREParser::FilepathContext>(0);
}

tree::TerminalNode* SPECTREParser::Standard_includeContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

SPECTREParser::Parameter_assignContext* SPECTREParser::Standard_includeContext::parameter_assign() {
  return getRuleContext<SPECTREParser::Parameter_assignContext>(0);
}

std::vector<tree::TerminalNode *> SPECTREParser::Standard_includeContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::Standard_includeContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::Standard_includeContext::getRuleIndex() const {
  return SPECTREParser::RuleStandard_include;
}

void SPECTREParser::Standard_includeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStandard_include(this);
}

void SPECTREParser::Standard_includeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStandard_include(this);
}


antlrcpp::Any SPECTREParser::Standard_includeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitStandard_include(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Standard_includeContext* SPECTREParser::standard_include() {
  Standard_includeContext *_localctx = _tracker.createInstance<Standard_includeContext>(_ctx, getState());
  enterRule(_localctx, 8, SPECTREParser::RuleStandard_include);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(325);
    match(SPECTREParser::INCLUDE);
    setState(326);
    filepath();
    setState(328);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      setState(327);
      parameter_assign();
      break;
    }

    }
    setState(337);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      setState(333);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(330);
          match(SPECTREParser::NL); 
        }
        setState(335);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
      }
      break;
    }

    case 2: {
      setState(336);
      match(SPECTREParser::EOF);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Cpp_includeContext ------------------------------------------------------------------

SPECTREParser::Cpp_includeContext::Cpp_includeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Cpp_includeContext::CPP_INCLUDE() {
  return getToken(SPECTREParser::CPP_INCLUDE, 0);
}

SPECTREParser::FilepathContext* SPECTREParser::Cpp_includeContext::filepath() {
  return getRuleContext<SPECTREParser::FilepathContext>(0);
}

tree::TerminalNode* SPECTREParser::Cpp_includeContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

std::vector<tree::TerminalNode *> SPECTREParser::Cpp_includeContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::Cpp_includeContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::Cpp_includeContext::getRuleIndex() const {
  return SPECTREParser::RuleCpp_include;
}

void SPECTREParser::Cpp_includeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCpp_include(this);
}

void SPECTREParser::Cpp_includeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCpp_include(this);
}


antlrcpp::Any SPECTREParser::Cpp_includeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitCpp_include(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Cpp_includeContext* SPECTREParser::cpp_include() {
  Cpp_includeContext *_localctx = _tracker.createInstance<Cpp_includeContext>(_ctx, getState());
  enterRule(_localctx, 10, SPECTREParser::RuleCpp_include);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(339);
    match(SPECTREParser::CPP_INCLUDE);
    setState(340);
    filepath();
    setState(348);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      setState(344);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(341);
          match(SPECTREParser::NL); 
        }
        setState(346);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
      }
      break;
    }

    case 2: {
      setState(347);
      match(SPECTREParser::EOF);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Ahdl_includeContext ------------------------------------------------------------------

SPECTREParser::Ahdl_includeContext::Ahdl_includeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Ahdl_includeContext::AHDL_INCLUDE() {
  return getToken(SPECTREParser::AHDL_INCLUDE, 0);
}

SPECTREParser::FilepathContext* SPECTREParser::Ahdl_includeContext::filepath() {
  return getRuleContext<SPECTREParser::FilepathContext>(0);
}

tree::TerminalNode* SPECTREParser::Ahdl_includeContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

tree::TerminalNode* SPECTREParser::Ahdl_includeContext::MINUS() {
  return getToken(SPECTREParser::MINUS, 0);
}

tree::TerminalNode* SPECTREParser::Ahdl_includeContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

std::vector<tree::TerminalNode *> SPECTREParser::Ahdl_includeContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::Ahdl_includeContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::Ahdl_includeContext::getRuleIndex() const {
  return SPECTREParser::RuleAhdl_include;
}

void SPECTREParser::Ahdl_includeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAhdl_include(this);
}

void SPECTREParser::Ahdl_includeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAhdl_include(this);
}


antlrcpp::Any SPECTREParser::Ahdl_includeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitAhdl_include(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Ahdl_includeContext* SPECTREParser::ahdl_include() {
  Ahdl_includeContext *_localctx = _tracker.createInstance<Ahdl_includeContext>(_ctx, getState());
  enterRule(_localctx, 12, SPECTREParser::RuleAhdl_include);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(350);
    match(SPECTREParser::AHDL_INCLUDE);
    setState(351);
    filepath();
    setState(353);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SPECTREParser::MINUS) {
      setState(352);
      match(SPECTREParser::MINUS);
    }
    setState(356);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      setState(355);
      match(SPECTREParser::ID);
      break;
    }

    }
    setState(365);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      setState(361);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(358);
          match(SPECTREParser::NL); 
        }
        setState(363);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
      }
      break;
    }

    case 2: {
      setState(364);
      match(SPECTREParser::EOF);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LangContext ------------------------------------------------------------------

SPECTREParser::LangContext::LangContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::LangContext::SIMULATOR() {
  return getToken(SPECTREParser::SIMULATOR, 0);
}

tree::TerminalNode* SPECTREParser::LangContext::LANGUAGE() {
  return getToken(SPECTREParser::LANGUAGE, 0);
}

std::vector<tree::TerminalNode *> SPECTREParser::LangContext::EQUAL() {
  return getTokens(SPECTREParser::EQUAL);
}

tree::TerminalNode* SPECTREParser::LangContext::EQUAL(size_t i) {
  return getToken(SPECTREParser::EQUAL, i);
}

tree::TerminalNode* SPECTREParser::LangContext::SPICE() {
  return getToken(SPECTREParser::SPICE, 0);
}

tree::TerminalNode* SPECTREParser::LangContext::SPECTRE() {
  return getToken(SPECTREParser::SPECTRE, 0);
}

tree::TerminalNode* SPECTREParser::LangContext::INSENSITIVE() {
  return getToken(SPECTREParser::INSENSITIVE, 0);
}

tree::TerminalNode* SPECTREParser::LangContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}


size_t SPECTREParser::LangContext::getRuleIndex() const {
  return SPECTREParser::RuleLang;
}

void SPECTREParser::LangContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLang(this);
}

void SPECTREParser::LangContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLang(this);
}


antlrcpp::Any SPECTREParser::LangContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitLang(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::LangContext* SPECTREParser::lang() {
  LangContext *_localctx = _tracker.createInstance<LangContext>(_ctx, getState());
  enterRule(_localctx, 14, SPECTREParser::RuleLang);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(380);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(367);
      match(SPECTREParser::SIMULATOR);
      setState(368);
      match(SPECTREParser::LANGUAGE);
      setState(369);
      match(SPECTREParser::EQUAL);
      setState(370);
      match(SPECTREParser::SPICE);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(371);
      match(SPECTREParser::SIMULATOR);
      setState(372);
      match(SPECTREParser::LANGUAGE);
      setState(373);
      match(SPECTREParser::EQUAL);
      setState(374);
      match(SPECTREParser::SPECTRE);
      setState(378);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SPECTREParser::INSENSITIVE) {
        setState(375);
        match(SPECTREParser::INSENSITIVE);
        setState(376);
        match(SPECTREParser::EQUAL);
        setState(377);
        match(SPECTREParser::ID);
      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LibraryContext ------------------------------------------------------------------

SPECTREParser::LibraryContext::LibraryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SPECTREParser::Library_headerContext* SPECTREParser::LibraryContext::library_header() {
  return getRuleContext<SPECTREParser::Library_headerContext>(0);
}

SPECTREParser::Library_footerContext* SPECTREParser::LibraryContext::library_footer() {
  return getRuleContext<SPECTREParser::Library_footerContext>(0);
}

std::vector<SPECTREParser::Library_contentContext *> SPECTREParser::LibraryContext::library_content() {
  return getRuleContexts<SPECTREParser::Library_contentContext>();
}

SPECTREParser::Library_contentContext* SPECTREParser::LibraryContext::library_content(size_t i) {
  return getRuleContext<SPECTREParser::Library_contentContext>(i);
}


size_t SPECTREParser::LibraryContext::getRuleIndex() const {
  return SPECTREParser::RuleLibrary;
}

void SPECTREParser::LibraryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLibrary(this);
}

void SPECTREParser::LibraryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLibrary(this);
}


antlrcpp::Any SPECTREParser::LibraryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitLibrary(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::LibraryContext* SPECTREParser::library() {
  LibraryContext *_localctx = _tracker.createInstance<LibraryContext>(_ctx, getState());
  enterRule(_localctx, 16, SPECTREParser::RuleLibrary);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(382);
    library_header();
    setState(384); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(383);
      library_content();
      setState(386); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SPECTREParser::GLOBAL)
      | (1ULL << SPECTREParser::INCLUDE)
      | (1ULL << SPECTREParser::CPP_INCLUDE)
      | (1ULL << SPECTREParser::AHDL_INCLUDE)
      | (1ULL << SPECTREParser::LIBRARY)
      | (1ULL << SPECTREParser::SECTION)
      | (1ULL << SPECTREParser::SUBCKT)
      | (1ULL << SPECTREParser::INLINE_SUBCKT)
      | (1ULL << SPECTREParser::MODEL)
      | (1ULL << SPECTREParser::SAVE)
      | (1ULL << SPECTREParser::NODESET)
      | (1ULL << SPECTREParser::IC)
      | (1ULL << SPECTREParser::PARAMETERS)
      | (1ULL << SPECTREParser::STATISTICS)
      | (1ULL << SPECTREParser::AC)
      | (1ULL << SPECTREParser::ACMATCH)
      | (1ULL << SPECTREParser::DC)
      | (1ULL << SPECTREParser::DCMATCH)
      | (1ULL << SPECTREParser::ENVLP)
      | (1ULL << SPECTREParser::SP)
      | (1ULL << SPECTREParser::STB)
      | (1ULL << SPECTREParser::SWEEP)
      | (1ULL << SPECTREParser::TDR)
      | (1ULL << SPECTREParser::TRAN)
      | (1ULL << SPECTREParser::XF)
      | (1ULL << SPECTREParser::PAC)
      | (1ULL << SPECTREParser::PDISTO))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (SPECTREParser::PNOISE - 64))
      | (1ULL << (SPECTREParser::PSP - 64))
      | (1ULL << (SPECTREParser::PSS - 64))
      | (1ULL << (SPECTREParser::PXF - 64))
      | (1ULL << (SPECTREParser::PZ - 64))
      | (1ULL << (SPECTREParser::QPAC - 64))
      | (1ULL << (SPECTREParser::QPNOISE - 64))
      | (1ULL << (SPECTREParser::QPSP - 64))
      | (1ULL << (SPECTREParser::QPSS - 64))
      | (1ULL << (SPECTREParser::QPXF - 64))
      | (1ULL << (SPECTREParser::SENS - 64)))) != 0) || ((((_la - 191) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 191)) & ((1ULL << (SPECTREParser::OPEN_ROUND - 191))
      | (1ULL << (SPECTREParser::NUMBER - 191))
      | (1ULL << (SPECTREParser::ID - 191)))) != 0));
    setState(388);
    library_footer();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Library_headerContext ------------------------------------------------------------------

SPECTREParser::Library_headerContext::Library_headerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Library_headerContext::LIBRARY() {
  return getToken(SPECTREParser::LIBRARY, 0);
}

tree::TerminalNode* SPECTREParser::Library_headerContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

tree::TerminalNode* SPECTREParser::Library_headerContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

std::vector<tree::TerminalNode *> SPECTREParser::Library_headerContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::Library_headerContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::Library_headerContext::getRuleIndex() const {
  return SPECTREParser::RuleLibrary_header;
}

void SPECTREParser::Library_headerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLibrary_header(this);
}

void SPECTREParser::Library_headerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLibrary_header(this);
}


antlrcpp::Any SPECTREParser::Library_headerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitLibrary_header(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Library_headerContext* SPECTREParser::library_header() {
  Library_headerContext *_localctx = _tracker.createInstance<Library_headerContext>(_ctx, getState());
  enterRule(_localctx, 18, SPECTREParser::RuleLibrary_header);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(390);
    match(SPECTREParser::LIBRARY);
    setState(391);
    match(SPECTREParser::ID);
    setState(399);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SPECTREParser::GLOBAL:
      case SPECTREParser::INCLUDE:
      case SPECTREParser::CPP_INCLUDE:
      case SPECTREParser::AHDL_INCLUDE:
      case SPECTREParser::LIBRARY:
      case SPECTREParser::SECTION:
      case SPECTREParser::SUBCKT:
      case SPECTREParser::INLINE_SUBCKT:
      case SPECTREParser::MODEL:
      case SPECTREParser::SAVE:
      case SPECTREParser::NODESET:
      case SPECTREParser::IC:
      case SPECTREParser::PARAMETERS:
      case SPECTREParser::STATISTICS:
      case SPECTREParser::AC:
      case SPECTREParser::ACMATCH:
      case SPECTREParser::DC:
      case SPECTREParser::DCMATCH:
      case SPECTREParser::ENVLP:
      case SPECTREParser::SP:
      case SPECTREParser::STB:
      case SPECTREParser::SWEEP:
      case SPECTREParser::TDR:
      case SPECTREParser::TRAN:
      case SPECTREParser::XF:
      case SPECTREParser::PAC:
      case SPECTREParser::PDISTO:
      case SPECTREParser::PNOISE:
      case SPECTREParser::PSP:
      case SPECTREParser::PSS:
      case SPECTREParser::PXF:
      case SPECTREParser::PZ:
      case SPECTREParser::QPAC:
      case SPECTREParser::QPNOISE:
      case SPECTREParser::QPSP:
      case SPECTREParser::QPSS:
      case SPECTREParser::QPXF:
      case SPECTREParser::SENS:
      case SPECTREParser::OPEN_ROUND:
      case SPECTREParser::NUMBER:
      case SPECTREParser::ID:
      case SPECTREParser::NL: {
        setState(395);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SPECTREParser::NL) {
          setState(392);
          match(SPECTREParser::NL);
          setState(397);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case SPECTREParser::EOF: {
        setState(398);
        match(SPECTREParser::EOF);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Library_contentContext ------------------------------------------------------------------

SPECTREParser::Library_contentContext::Library_contentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SPECTREParser::Netlist_entityContext* SPECTREParser::Library_contentContext::netlist_entity() {
  return getRuleContext<SPECTREParser::Netlist_entityContext>(0);
}


size_t SPECTREParser::Library_contentContext::getRuleIndex() const {
  return SPECTREParser::RuleLibrary_content;
}

void SPECTREParser::Library_contentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLibrary_content(this);
}

void SPECTREParser::Library_contentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLibrary_content(this);
}


antlrcpp::Any SPECTREParser::Library_contentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitLibrary_content(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Library_contentContext* SPECTREParser::library_content() {
  Library_contentContext *_localctx = _tracker.createInstance<Library_contentContext>(_ctx, getState());
  enterRule(_localctx, 20, SPECTREParser::RuleLibrary_content);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(401);
    netlist_entity();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Library_footerContext ------------------------------------------------------------------

SPECTREParser::Library_footerContext::Library_footerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Library_footerContext::LIBRARY_END() {
  return getToken(SPECTREParser::LIBRARY_END, 0);
}

tree::TerminalNode* SPECTREParser::Library_footerContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

tree::TerminalNode* SPECTREParser::Library_footerContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

std::vector<tree::TerminalNode *> SPECTREParser::Library_footerContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::Library_footerContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::Library_footerContext::getRuleIndex() const {
  return SPECTREParser::RuleLibrary_footer;
}

void SPECTREParser::Library_footerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLibrary_footer(this);
}

void SPECTREParser::Library_footerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLibrary_footer(this);
}


antlrcpp::Any SPECTREParser::Library_footerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitLibrary_footer(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Library_footerContext* SPECTREParser::library_footer() {
  Library_footerContext *_localctx = _tracker.createInstance<Library_footerContext>(_ctx, getState());
  enterRule(_localctx, 22, SPECTREParser::RuleLibrary_footer);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(403);
    match(SPECTREParser::LIBRARY_END);
    setState(405);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      setState(404);
      match(SPECTREParser::ID);
      break;
    }

    }
    setState(414);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
    case 1: {
      setState(410);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(407);
          match(SPECTREParser::NL); 
        }
        setState(412);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
      }
      break;
    }

    case 2: {
      setState(413);
      match(SPECTREParser::EOF);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SectionContext ------------------------------------------------------------------

SPECTREParser::SectionContext::SectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SPECTREParser::Section_headerContext* SPECTREParser::SectionContext::section_header() {
  return getRuleContext<SPECTREParser::Section_headerContext>(0);
}

SPECTREParser::Section_footerContext* SPECTREParser::SectionContext::section_footer() {
  return getRuleContext<SPECTREParser::Section_footerContext>(0);
}

std::vector<SPECTREParser::Section_contentContext *> SPECTREParser::SectionContext::section_content() {
  return getRuleContexts<SPECTREParser::Section_contentContext>();
}

SPECTREParser::Section_contentContext* SPECTREParser::SectionContext::section_content(size_t i) {
  return getRuleContext<SPECTREParser::Section_contentContext>(i);
}


size_t SPECTREParser::SectionContext::getRuleIndex() const {
  return SPECTREParser::RuleSection;
}

void SPECTREParser::SectionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSection(this);
}

void SPECTREParser::SectionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSection(this);
}


antlrcpp::Any SPECTREParser::SectionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitSection(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::SectionContext* SPECTREParser::section() {
  SectionContext *_localctx = _tracker.createInstance<SectionContext>(_ctx, getState());
  enterRule(_localctx, 24, SPECTREParser::RuleSection);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(416);
    section_header();
    setState(418); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(417);
      section_content();
      setState(420); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SPECTREParser::GLOBAL)
      | (1ULL << SPECTREParser::INCLUDE)
      | (1ULL << SPECTREParser::CPP_INCLUDE)
      | (1ULL << SPECTREParser::AHDL_INCLUDE)
      | (1ULL << SPECTREParser::LIBRARY)
      | (1ULL << SPECTREParser::SECTION)
      | (1ULL << SPECTREParser::SUBCKT)
      | (1ULL << SPECTREParser::INLINE_SUBCKT)
      | (1ULL << SPECTREParser::MODEL)
      | (1ULL << SPECTREParser::SAVE)
      | (1ULL << SPECTREParser::NODESET)
      | (1ULL << SPECTREParser::IC)
      | (1ULL << SPECTREParser::PARAMETERS)
      | (1ULL << SPECTREParser::STATISTICS)
      | (1ULL << SPECTREParser::AC)
      | (1ULL << SPECTREParser::ACMATCH)
      | (1ULL << SPECTREParser::DC)
      | (1ULL << SPECTREParser::DCMATCH)
      | (1ULL << SPECTREParser::ENVLP)
      | (1ULL << SPECTREParser::SP)
      | (1ULL << SPECTREParser::STB)
      | (1ULL << SPECTREParser::SWEEP)
      | (1ULL << SPECTREParser::TDR)
      | (1ULL << SPECTREParser::TRAN)
      | (1ULL << SPECTREParser::XF)
      | (1ULL << SPECTREParser::PAC)
      | (1ULL << SPECTREParser::PDISTO))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (SPECTREParser::PNOISE - 64))
      | (1ULL << (SPECTREParser::PSP - 64))
      | (1ULL << (SPECTREParser::PSS - 64))
      | (1ULL << (SPECTREParser::PXF - 64))
      | (1ULL << (SPECTREParser::PZ - 64))
      | (1ULL << (SPECTREParser::QPAC - 64))
      | (1ULL << (SPECTREParser::QPNOISE - 64))
      | (1ULL << (SPECTREParser::QPSP - 64))
      | (1ULL << (SPECTREParser::QPSS - 64))
      | (1ULL << (SPECTREParser::QPXF - 64))
      | (1ULL << (SPECTREParser::SENS - 64)))) != 0) || ((((_la - 191) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 191)) & ((1ULL << (SPECTREParser::OPEN_ROUND - 191))
      | (1ULL << (SPECTREParser::NUMBER - 191))
      | (1ULL << (SPECTREParser::ID - 191)))) != 0));
    setState(422);
    section_footer();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Section_headerContext ------------------------------------------------------------------

SPECTREParser::Section_headerContext::Section_headerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Section_headerContext::SECTION() {
  return getToken(SPECTREParser::SECTION, 0);
}

tree::TerminalNode* SPECTREParser::Section_headerContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

tree::TerminalNode* SPECTREParser::Section_headerContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

std::vector<tree::TerminalNode *> SPECTREParser::Section_headerContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::Section_headerContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::Section_headerContext::getRuleIndex() const {
  return SPECTREParser::RuleSection_header;
}

void SPECTREParser::Section_headerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSection_header(this);
}

void SPECTREParser::Section_headerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSection_header(this);
}


antlrcpp::Any SPECTREParser::Section_headerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitSection_header(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Section_headerContext* SPECTREParser::section_header() {
  Section_headerContext *_localctx = _tracker.createInstance<Section_headerContext>(_ctx, getState());
  enterRule(_localctx, 26, SPECTREParser::RuleSection_header);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(424);
    match(SPECTREParser::SECTION);
    setState(425);
    match(SPECTREParser::ID);
    setState(433);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SPECTREParser::GLOBAL:
      case SPECTREParser::INCLUDE:
      case SPECTREParser::CPP_INCLUDE:
      case SPECTREParser::AHDL_INCLUDE:
      case SPECTREParser::LIBRARY:
      case SPECTREParser::SECTION:
      case SPECTREParser::SUBCKT:
      case SPECTREParser::INLINE_SUBCKT:
      case SPECTREParser::MODEL:
      case SPECTREParser::SAVE:
      case SPECTREParser::NODESET:
      case SPECTREParser::IC:
      case SPECTREParser::PARAMETERS:
      case SPECTREParser::STATISTICS:
      case SPECTREParser::AC:
      case SPECTREParser::ACMATCH:
      case SPECTREParser::DC:
      case SPECTREParser::DCMATCH:
      case SPECTREParser::ENVLP:
      case SPECTREParser::SP:
      case SPECTREParser::STB:
      case SPECTREParser::SWEEP:
      case SPECTREParser::TDR:
      case SPECTREParser::TRAN:
      case SPECTREParser::XF:
      case SPECTREParser::PAC:
      case SPECTREParser::PDISTO:
      case SPECTREParser::PNOISE:
      case SPECTREParser::PSP:
      case SPECTREParser::PSS:
      case SPECTREParser::PXF:
      case SPECTREParser::PZ:
      case SPECTREParser::QPAC:
      case SPECTREParser::QPNOISE:
      case SPECTREParser::QPSP:
      case SPECTREParser::QPSS:
      case SPECTREParser::QPXF:
      case SPECTREParser::SENS:
      case SPECTREParser::OPEN_ROUND:
      case SPECTREParser::NUMBER:
      case SPECTREParser::ID:
      case SPECTREParser::NL: {
        setState(429);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SPECTREParser::NL) {
          setState(426);
          match(SPECTREParser::NL);
          setState(431);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case SPECTREParser::EOF: {
        setState(432);
        match(SPECTREParser::EOF);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Section_contentContext ------------------------------------------------------------------

SPECTREParser::Section_contentContext::Section_contentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SPECTREParser::Netlist_entityContext* SPECTREParser::Section_contentContext::netlist_entity() {
  return getRuleContext<SPECTREParser::Netlist_entityContext>(0);
}


size_t SPECTREParser::Section_contentContext::getRuleIndex() const {
  return SPECTREParser::RuleSection_content;
}

void SPECTREParser::Section_contentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSection_content(this);
}

void SPECTREParser::Section_contentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSection_content(this);
}


antlrcpp::Any SPECTREParser::Section_contentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitSection_content(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Section_contentContext* SPECTREParser::section_content() {
  Section_contentContext *_localctx = _tracker.createInstance<Section_contentContext>(_ctx, getState());
  enterRule(_localctx, 28, SPECTREParser::RuleSection_content);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(435);
    netlist_entity();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Section_footerContext ------------------------------------------------------------------

SPECTREParser::Section_footerContext::Section_footerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Section_footerContext::SECTION_END() {
  return getToken(SPECTREParser::SECTION_END, 0);
}

tree::TerminalNode* SPECTREParser::Section_footerContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

tree::TerminalNode* SPECTREParser::Section_footerContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

std::vector<tree::TerminalNode *> SPECTREParser::Section_footerContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::Section_footerContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::Section_footerContext::getRuleIndex() const {
  return SPECTREParser::RuleSection_footer;
}

void SPECTREParser::Section_footerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSection_footer(this);
}

void SPECTREParser::Section_footerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSection_footer(this);
}


antlrcpp::Any SPECTREParser::Section_footerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitSection_footer(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Section_footerContext* SPECTREParser::section_footer() {
  Section_footerContext *_localctx = _tracker.createInstance<Section_footerContext>(_ctx, getState());
  enterRule(_localctx, 30, SPECTREParser::RuleSection_footer);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(437);
    match(SPECTREParser::SECTION_END);
    setState(439);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      setState(438);
      match(SPECTREParser::ID);
      break;
    }

    }
    setState(448);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      setState(444);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(441);
          match(SPECTREParser::NL); 
        }
        setState(446);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
      }
      break;
    }

    case 2: {
      setState(447);
      match(SPECTREParser::EOF);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AnalogmodelContext ------------------------------------------------------------------

SPECTREParser::AnalogmodelContext::AnalogmodelContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::AnalogmodelContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

SPECTREParser::Node_listContext* SPECTREParser::AnalogmodelContext::node_list() {
  return getRuleContext<SPECTREParser::Node_listContext>(0);
}

tree::TerminalNode* SPECTREParser::AnalogmodelContext::ANALOGMODEL() {
  return getToken(SPECTREParser::ANALOGMODEL, 0);
}

SPECTREParser::Parameter_listContext* SPECTREParser::AnalogmodelContext::parameter_list() {
  return getRuleContext<SPECTREParser::Parameter_listContext>(0);
}

tree::TerminalNode* SPECTREParser::AnalogmodelContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

std::vector<tree::TerminalNode *> SPECTREParser::AnalogmodelContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::AnalogmodelContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::AnalogmodelContext::getRuleIndex() const {
  return SPECTREParser::RuleAnalogmodel;
}

void SPECTREParser::AnalogmodelContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnalogmodel(this);
}

void SPECTREParser::AnalogmodelContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnalogmodel(this);
}


antlrcpp::Any SPECTREParser::AnalogmodelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitAnalogmodel(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::AnalogmodelContext* SPECTREParser::analogmodel() {
  AnalogmodelContext *_localctx = _tracker.createInstance<AnalogmodelContext>(_ctx, getState());
  enterRule(_localctx, 32, SPECTREParser::RuleAnalogmodel);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(475);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(450);
      match(SPECTREParser::ID);
      setState(451);
      node_list();
      setState(452);
      match(SPECTREParser::ANALOGMODEL);
      setState(453);
      parameter_list();
      setState(461);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
      case 1: {
        setState(457);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(454);
            match(SPECTREParser::NL); 
          }
          setState(459);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
        }
        break;
      }

      case 2: {
        setState(460);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(463);
      match(SPECTREParser::ID);
      setState(464);
      node_list();
      setState(465);
      match(SPECTREParser::ANALOGMODEL);
      setState(473);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
      case 1: {
        setState(469);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(466);
            match(SPECTREParser::NL); 
          }
          setState(471);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
        }
        break;
      }

      case 2: {
        setState(472);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SubcktContext ------------------------------------------------------------------

SPECTREParser::SubcktContext::SubcktContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SPECTREParser::Subckt_headerContext* SPECTREParser::SubcktContext::subckt_header() {
  return getRuleContext<SPECTREParser::Subckt_headerContext>(0);
}

SPECTREParser::Subckt_footerContext* SPECTREParser::SubcktContext::subckt_footer() {
  return getRuleContext<SPECTREParser::Subckt_footerContext>(0);
}

std::vector<SPECTREParser::Subckt_contentContext *> SPECTREParser::SubcktContext::subckt_content() {
  return getRuleContexts<SPECTREParser::Subckt_contentContext>();
}

SPECTREParser::Subckt_contentContext* SPECTREParser::SubcktContext::subckt_content(size_t i) {
  return getRuleContext<SPECTREParser::Subckt_contentContext>(i);
}


size_t SPECTREParser::SubcktContext::getRuleIndex() const {
  return SPECTREParser::RuleSubckt;
}

void SPECTREParser::SubcktContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubckt(this);
}

void SPECTREParser::SubcktContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubckt(this);
}


antlrcpp::Any SPECTREParser::SubcktContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitSubckt(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::SubcktContext* SPECTREParser::subckt() {
  SubcktContext *_localctx = _tracker.createInstance<SubcktContext>(_ctx, getState());
  enterRule(_localctx, 34, SPECTREParser::RuleSubckt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(477);
    subckt_header();
    setState(479); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(478);
      subckt_content();
      setState(481); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SPECTREParser::GLOBAL)
      | (1ULL << SPECTREParser::INCLUDE)
      | (1ULL << SPECTREParser::CPP_INCLUDE)
      | (1ULL << SPECTREParser::AHDL_INCLUDE)
      | (1ULL << SPECTREParser::LIBRARY)
      | (1ULL << SPECTREParser::SECTION)
      | (1ULL << SPECTREParser::SUBCKT)
      | (1ULL << SPECTREParser::INLINE_SUBCKT)
      | (1ULL << SPECTREParser::MODEL)
      | (1ULL << SPECTREParser::SAVE)
      | (1ULL << SPECTREParser::NODESET)
      | (1ULL << SPECTREParser::IC)
      | (1ULL << SPECTREParser::PARAMETERS)
      | (1ULL << SPECTREParser::STATISTICS)
      | (1ULL << SPECTREParser::AC)
      | (1ULL << SPECTREParser::ACMATCH)
      | (1ULL << SPECTREParser::DC)
      | (1ULL << SPECTREParser::DCMATCH)
      | (1ULL << SPECTREParser::ENVLP)
      | (1ULL << SPECTREParser::SP)
      | (1ULL << SPECTREParser::STB)
      | (1ULL << SPECTREParser::SWEEP)
      | (1ULL << SPECTREParser::TDR)
      | (1ULL << SPECTREParser::TRAN)
      | (1ULL << SPECTREParser::XF)
      | (1ULL << SPECTREParser::PAC)
      | (1ULL << SPECTREParser::PDISTO))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (SPECTREParser::PNOISE - 64))
      | (1ULL << (SPECTREParser::PSP - 64))
      | (1ULL << (SPECTREParser::PSS - 64))
      | (1ULL << (SPECTREParser::PXF - 64))
      | (1ULL << (SPECTREParser::PZ - 64))
      | (1ULL << (SPECTREParser::QPAC - 64))
      | (1ULL << (SPECTREParser::QPNOISE - 64))
      | (1ULL << (SPECTREParser::QPSP - 64))
      | (1ULL << (SPECTREParser::QPSS - 64))
      | (1ULL << (SPECTREParser::QPXF - 64))
      | (1ULL << (SPECTREParser::SENS - 64)))) != 0) || ((((_la - 191) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 191)) & ((1ULL << (SPECTREParser::OPEN_ROUND - 191))
      | (1ULL << (SPECTREParser::NUMBER - 191))
      | (1ULL << (SPECTREParser::ID - 191)))) != 0));
    setState(483);
    subckt_footer();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Subckt_headerContext ------------------------------------------------------------------

SPECTREParser::Subckt_headerContext::Subckt_headerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Subckt_headerContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

tree::TerminalNode* SPECTREParser::Subckt_headerContext::INLINE_SUBCKT() {
  return getToken(SPECTREParser::INLINE_SUBCKT, 0);
}

tree::TerminalNode* SPECTREParser::Subckt_headerContext::SUBCKT() {
  return getToken(SPECTREParser::SUBCKT, 0);
}

SPECTREParser::Node_listContext* SPECTREParser::Subckt_headerContext::node_list() {
  return getRuleContext<SPECTREParser::Node_listContext>(0);
}

std::vector<tree::TerminalNode *> SPECTREParser::Subckt_headerContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::Subckt_headerContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::Subckt_headerContext::getRuleIndex() const {
  return SPECTREParser::RuleSubckt_header;
}

void SPECTREParser::Subckt_headerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubckt_header(this);
}

void SPECTREParser::Subckt_headerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubckt_header(this);
}


antlrcpp::Any SPECTREParser::Subckt_headerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitSubckt_header(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Subckt_headerContext* SPECTREParser::subckt_header() {
  Subckt_headerContext *_localctx = _tracker.createInstance<Subckt_headerContext>(_ctx, getState());
  enterRule(_localctx, 36, SPECTREParser::RuleSubckt_header);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(485);
    _la = _input->LA(1);
    if (!(_la == SPECTREParser::SUBCKT

    || _la == SPECTREParser::INLINE_SUBCKT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(486);
    match(SPECTREParser::ID);
    setState(488);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 191) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 191)) & ((1ULL << (SPECTREParser::OPEN_ROUND - 191))
      | (1ULL << (SPECTREParser::NUMBER - 191))
      | (1ULL << (SPECTREParser::ID - 191)))) != 0)) {
      setState(487);
      node_list();
    }
    setState(491); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(490);
      match(SPECTREParser::NL);
      setState(493); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == SPECTREParser::NL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Subckt_contentContext ------------------------------------------------------------------

SPECTREParser::Subckt_contentContext::Subckt_contentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SPECTREParser::Netlist_entityContext* SPECTREParser::Subckt_contentContext::netlist_entity() {
  return getRuleContext<SPECTREParser::Netlist_entityContext>(0);
}


size_t SPECTREParser::Subckt_contentContext::getRuleIndex() const {
  return SPECTREParser::RuleSubckt_content;
}

void SPECTREParser::Subckt_contentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubckt_content(this);
}

void SPECTREParser::Subckt_contentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubckt_content(this);
}


antlrcpp::Any SPECTREParser::Subckt_contentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitSubckt_content(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Subckt_contentContext* SPECTREParser::subckt_content() {
  Subckt_contentContext *_localctx = _tracker.createInstance<Subckt_contentContext>(_ctx, getState());
  enterRule(_localctx, 38, SPECTREParser::RuleSubckt_content);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(495);
    netlist_entity();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Subckt_footerContext ------------------------------------------------------------------

SPECTREParser::Subckt_footerContext::Subckt_footerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Subckt_footerContext::SUBCKT_END() {
  return getToken(SPECTREParser::SUBCKT_END, 0);
}

tree::TerminalNode* SPECTREParser::Subckt_footerContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

tree::TerminalNode* SPECTREParser::Subckt_footerContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

std::vector<tree::TerminalNode *> SPECTREParser::Subckt_footerContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::Subckt_footerContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::Subckt_footerContext::getRuleIndex() const {
  return SPECTREParser::RuleSubckt_footer;
}

void SPECTREParser::Subckt_footerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubckt_footer(this);
}

void SPECTREParser::Subckt_footerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubckt_footer(this);
}


antlrcpp::Any SPECTREParser::Subckt_footerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitSubckt_footer(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Subckt_footerContext* SPECTREParser::subckt_footer() {
  Subckt_footerContext *_localctx = _tracker.createInstance<Subckt_footerContext>(_ctx, getState());
  enterRule(_localctx, 40, SPECTREParser::RuleSubckt_footer);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(497);
    match(SPECTREParser::SUBCKT_END);
    setState(499);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
    case 1: {
      setState(498);
      match(SPECTREParser::ID);
      break;
    }

    }
    setState(508);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx)) {
    case 1: {
      setState(504);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(501);
          match(SPECTREParser::NL); 
        }
        setState(506);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
      }
      break;
    }

    case 2: {
      setState(507);
      match(SPECTREParser::EOF);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_statementContext ------------------------------------------------------------------

SPECTREParser::If_statementContext::If_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::If_statementContext::IF() {
  return getToken(SPECTREParser::IF, 0);
}

SPECTREParser::ExpressionContext* SPECTREParser::If_statementContext::expression() {
  return getRuleContext<SPECTREParser::ExpressionContext>(0);
}

SPECTREParser::If_bodyContext* SPECTREParser::If_statementContext::if_body() {
  return getRuleContext<SPECTREParser::If_bodyContext>(0);
}

SPECTREParser::If_alternativeContext* SPECTREParser::If_statementContext::if_alternative() {
  return getRuleContext<SPECTREParser::If_alternativeContext>(0);
}


size_t SPECTREParser::If_statementContext::getRuleIndex() const {
  return SPECTREParser::RuleIf_statement;
}

void SPECTREParser::If_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf_statement(this);
}

void SPECTREParser::If_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf_statement(this);
}


antlrcpp::Any SPECTREParser::If_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitIf_statement(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::If_statementContext* SPECTREParser::if_statement() {
  If_statementContext *_localctx = _tracker.createInstance<If_statementContext>(_ctx, getState());
  enterRule(_localctx, 42, SPECTREParser::RuleIf_statement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(510);
    match(SPECTREParser::IF);
    setState(511);
    expression(0);
    setState(512);
    if_body();
    setState(514);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx)) {
    case 1: {
      setState(513);
      if_alternative();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_alternativeContext ------------------------------------------------------------------

SPECTREParser::If_alternativeContext::If_alternativeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::If_alternativeContext::ELSE() {
  return getToken(SPECTREParser::ELSE, 0);
}

SPECTREParser::If_bodyContext* SPECTREParser::If_alternativeContext::if_body() {
  return getRuleContext<SPECTREParser::If_bodyContext>(0);
}


size_t SPECTREParser::If_alternativeContext::getRuleIndex() const {
  return SPECTREParser::RuleIf_alternative;
}

void SPECTREParser::If_alternativeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf_alternative(this);
}

void SPECTREParser::If_alternativeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf_alternative(this);
}


antlrcpp::Any SPECTREParser::If_alternativeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitIf_alternative(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::If_alternativeContext* SPECTREParser::if_alternative() {
  If_alternativeContext *_localctx = _tracker.createInstance<If_alternativeContext>(_ctx, getState());
  enterRule(_localctx, 44, SPECTREParser::RuleIf_alternative);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(516);
    match(SPECTREParser::ELSE);
    setState(517);
    if_body();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_bodyContext ------------------------------------------------------------------

SPECTREParser::If_bodyContext::If_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::If_bodyContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

tree::TerminalNode* SPECTREParser::If_bodyContext::OPEN_CURLY() {
  return getToken(SPECTREParser::OPEN_CURLY, 0);
}

std::vector<SPECTREParser::ComponentContext *> SPECTREParser::If_bodyContext::component() {
  return getRuleContexts<SPECTREParser::ComponentContext>();
}

SPECTREParser::ComponentContext* SPECTREParser::If_bodyContext::component(size_t i) {
  return getRuleContext<SPECTREParser::ComponentContext>(i);
}

std::vector<SPECTREParser::AnalysisContext *> SPECTREParser::If_bodyContext::analysis() {
  return getRuleContexts<SPECTREParser::AnalysisContext>();
}

SPECTREParser::AnalysisContext* SPECTREParser::If_bodyContext::analysis(size_t i) {
  return getRuleContext<SPECTREParser::AnalysisContext>(i);
}

std::vector<SPECTREParser::ControlContext *> SPECTREParser::If_bodyContext::control() {
  return getRuleContexts<SPECTREParser::ControlContext>();
}

SPECTREParser::ControlContext* SPECTREParser::If_bodyContext::control(size_t i) {
  return getRuleContext<SPECTREParser::ControlContext>(i);
}

std::vector<SPECTREParser::If_statementContext *> SPECTREParser::If_bodyContext::if_statement() {
  return getRuleContexts<SPECTREParser::If_statementContext>();
}

SPECTREParser::If_statementContext* SPECTREParser::If_bodyContext::if_statement(size_t i) {
  return getRuleContext<SPECTREParser::If_statementContext>(i);
}

std::vector<tree::TerminalNode *> SPECTREParser::If_bodyContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::If_bodyContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}

tree::TerminalNode* SPECTREParser::If_bodyContext::CLOSE_CURLY() {
  return getToken(SPECTREParser::CLOSE_CURLY, 0);
}


size_t SPECTREParser::If_bodyContext::getRuleIndex() const {
  return SPECTREParser::RuleIf_body;
}

void SPECTREParser::If_bodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf_body(this);
}

void SPECTREParser::If_bodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf_body(this);
}


antlrcpp::Any SPECTREParser::If_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitIf_body(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::If_bodyContext* SPECTREParser::if_body() {
  If_bodyContext *_localctx = _tracker.createInstance<If_bodyContext>(_ctx, getState());
  enterRule(_localctx, 46, SPECTREParser::RuleIf_body);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(532);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx)) {
    case 1: {
      setState(522);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SPECTREParser::NL) {
        setState(519);
        match(SPECTREParser::NL);
        setState(524);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(525);
      match(SPECTREParser::OPEN_CURLY);
      setState(529);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(526);
          match(SPECTREParser::NL); 
        }
        setState(531);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx);
      }
      break;
    }

    }
    setState(539); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(539);
              _errHandler->sync(this);
              switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx)) {
              case 1: {
                setState(534);
                component();
                break;
              }

              case 2: {
                setState(535);
                analysis();
                break;
              }

              case 3: {
                setState(536);
                control();
                break;
              }

              case 4: {
                setState(537);
                if_statement();
                break;
              }

              case 5: {
                setState(538);
                match(SPECTREParser::NL);
                break;
              }

              }
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(541); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
    setState(550);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx)) {
    case 1: {
      setState(546);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SPECTREParser::NL) {
        setState(543);
        match(SPECTREParser::NL);
        setState(548);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(549);
      match(SPECTREParser::CLOSE_CURLY);
      break;
    }

    }
    setState(559);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx)) {
    case 1: {
      setState(555);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(552);
          match(SPECTREParser::NL); 
        }
        setState(557);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx);
      }
      break;
    }

    case 2: {
      setState(558);
      match(SPECTREParser::EOF);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AnalysisContext ------------------------------------------------------------------

SPECTREParser::AnalysisContext::AnalysisContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SPECTREParser::AcContext* SPECTREParser::AnalysisContext::ac() {
  return getRuleContext<SPECTREParser::AcContext>(0);
}

SPECTREParser::AcmatchContext* SPECTREParser::AnalysisContext::acmatch() {
  return getRuleContext<SPECTREParser::AcmatchContext>(0);
}

SPECTREParser::DcContext* SPECTREParser::AnalysisContext::dc() {
  return getRuleContext<SPECTREParser::DcContext>(0);
}

SPECTREParser::DcmatchContext* SPECTREParser::AnalysisContext::dcmatch() {
  return getRuleContext<SPECTREParser::DcmatchContext>(0);
}

SPECTREParser::EnvlpContext* SPECTREParser::AnalysisContext::envlp() {
  return getRuleContext<SPECTREParser::EnvlpContext>(0);
}

SPECTREParser::SpContext* SPECTREParser::AnalysisContext::sp() {
  return getRuleContext<SPECTREParser::SpContext>(0);
}

SPECTREParser::StbContext* SPECTREParser::AnalysisContext::stb() {
  return getRuleContext<SPECTREParser::StbContext>(0);
}

SPECTREParser::SweepContext* SPECTREParser::AnalysisContext::sweep() {
  return getRuleContext<SPECTREParser::SweepContext>(0);
}

SPECTREParser::TdrContext* SPECTREParser::AnalysisContext::tdr() {
  return getRuleContext<SPECTREParser::TdrContext>(0);
}

SPECTREParser::TranContext* SPECTREParser::AnalysisContext::tran() {
  return getRuleContext<SPECTREParser::TranContext>(0);
}

SPECTREParser::XfContext* SPECTREParser::AnalysisContext::xf() {
  return getRuleContext<SPECTREParser::XfContext>(0);
}

SPECTREParser::PacContext* SPECTREParser::AnalysisContext::pac() {
  return getRuleContext<SPECTREParser::PacContext>(0);
}

SPECTREParser::PdistoContext* SPECTREParser::AnalysisContext::pdisto() {
  return getRuleContext<SPECTREParser::PdistoContext>(0);
}

SPECTREParser::PnoiseContext* SPECTREParser::AnalysisContext::pnoise() {
  return getRuleContext<SPECTREParser::PnoiseContext>(0);
}

SPECTREParser::PspContext* SPECTREParser::AnalysisContext::psp() {
  return getRuleContext<SPECTREParser::PspContext>(0);
}

SPECTREParser::PssContext* SPECTREParser::AnalysisContext::pss() {
  return getRuleContext<SPECTREParser::PssContext>(0);
}

SPECTREParser::PxfContext* SPECTREParser::AnalysisContext::pxf() {
  return getRuleContext<SPECTREParser::PxfContext>(0);
}

SPECTREParser::PzContext* SPECTREParser::AnalysisContext::pz() {
  return getRuleContext<SPECTREParser::PzContext>(0);
}

SPECTREParser::QpacContext* SPECTREParser::AnalysisContext::qpac() {
  return getRuleContext<SPECTREParser::QpacContext>(0);
}

SPECTREParser::QpnoiseContext* SPECTREParser::AnalysisContext::qpnoise() {
  return getRuleContext<SPECTREParser::QpnoiseContext>(0);
}

SPECTREParser::QpspContext* SPECTREParser::AnalysisContext::qpsp() {
  return getRuleContext<SPECTREParser::QpspContext>(0);
}

SPECTREParser::QpssContext* SPECTREParser::AnalysisContext::qpss() {
  return getRuleContext<SPECTREParser::QpssContext>(0);
}

SPECTREParser::QpxfContext* SPECTREParser::AnalysisContext::qpxf() {
  return getRuleContext<SPECTREParser::QpxfContext>(0);
}

SPECTREParser::SensContext* SPECTREParser::AnalysisContext::sens() {
  return getRuleContext<SPECTREParser::SensContext>(0);
}

SPECTREParser::MontecarloContext* SPECTREParser::AnalysisContext::montecarlo() {
  return getRuleContext<SPECTREParser::MontecarloContext>(0);
}

SPECTREParser::NoiseContext* SPECTREParser::AnalysisContext::noise() {
  return getRuleContext<SPECTREParser::NoiseContext>(0);
}

SPECTREParser::ChecklimitContext* SPECTREParser::AnalysisContext::checklimit() {
  return getRuleContext<SPECTREParser::ChecklimitContext>(0);
}

SPECTREParser::ReliabilityContext* SPECTREParser::AnalysisContext::reliability() {
  return getRuleContext<SPECTREParser::ReliabilityContext>(0);
}


size_t SPECTREParser::AnalysisContext::getRuleIndex() const {
  return SPECTREParser::RuleAnalysis;
}

void SPECTREParser::AnalysisContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnalysis(this);
}

void SPECTREParser::AnalysisContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnalysis(this);
}


antlrcpp::Any SPECTREParser::AnalysisContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitAnalysis(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::AnalysisContext* SPECTREParser::analysis() {
  AnalysisContext *_localctx = _tracker.createInstance<AnalysisContext>(_ctx, getState());
  enterRule(_localctx, 48, SPECTREParser::RuleAnalysis);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(589);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(561);
      ac();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(562);
      acmatch();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(563);
      dc();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(564);
      dcmatch();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(565);
      envlp();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(566);
      sp();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(567);
      stb();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(568);
      sweep();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(569);
      tdr();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(570);
      tran();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(571);
      xf();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(572);
      pac();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(573);
      pdisto();
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(574);
      pnoise();
      break;
    }

    case 15: {
      enterOuterAlt(_localctx, 15);
      setState(575);
      psp();
      break;
    }

    case 16: {
      enterOuterAlt(_localctx, 16);
      setState(576);
      pss();
      break;
    }

    case 17: {
      enterOuterAlt(_localctx, 17);
      setState(577);
      pxf();
      break;
    }

    case 18: {
      enterOuterAlt(_localctx, 18);
      setState(578);
      pz();
      break;
    }

    case 19: {
      enterOuterAlt(_localctx, 19);
      setState(579);
      qpac();
      break;
    }

    case 20: {
      enterOuterAlt(_localctx, 20);
      setState(580);
      qpnoise();
      break;
    }

    case 21: {
      enterOuterAlt(_localctx, 21);
      setState(581);
      qpsp();
      break;
    }

    case 22: {
      enterOuterAlt(_localctx, 22);
      setState(582);
      qpss();
      break;
    }

    case 23: {
      enterOuterAlt(_localctx, 23);
      setState(583);
      qpxf();
      break;
    }

    case 24: {
      enterOuterAlt(_localctx, 24);
      setState(584);
      sens();
      break;
    }

    case 25: {
      enterOuterAlt(_localctx, 25);
      setState(585);
      montecarlo();
      break;
    }

    case 26: {
      enterOuterAlt(_localctx, 26);
      setState(586);
      noise();
      break;
    }

    case 27: {
      enterOuterAlt(_localctx, 27);
      setState(587);
      checklimit();
      break;
    }

    case 28: {
      enterOuterAlt(_localctx, 28);
      setState(588);
      reliability();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AcContext ------------------------------------------------------------------

SPECTREParser::AcContext::AcContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::AcContext::AC() {
  return getToken(SPECTREParser::AC, 0);
}

tree::TerminalNode* SPECTREParser::AcContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

tree::TerminalNode* SPECTREParser::AcContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

SPECTREParser::Parameter_listContext* SPECTREParser::AcContext::parameter_list() {
  return getRuleContext<SPECTREParser::Parameter_listContext>(0);
}

std::vector<tree::TerminalNode *> SPECTREParser::AcContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::AcContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::AcContext::getRuleIndex() const {
  return SPECTREParser::RuleAc;
}

void SPECTREParser::AcContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAc(this);
}

void SPECTREParser::AcContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAc(this);
}


antlrcpp::Any SPECTREParser::AcContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitAc(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::AcContext* SPECTREParser::ac() {
  AcContext *_localctx = _tracker.createInstance<AcContext>(_ctx, getState());
  enterRule(_localctx, 50, SPECTREParser::RuleAc);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(620);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 62, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(592);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SPECTREParser::ID) {
        setState(591);
        match(SPECTREParser::ID);
      }
      setState(594);
      match(SPECTREParser::AC);
      setState(596);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx)) {
      case 1: {
        setState(595);
        parameter_list();
        break;
      }

      }
      setState(605);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx)) {
      case 1: {
        setState(601);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(598);
            match(SPECTREParser::NL); 
          }
          setState(603);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx);
        }
        break;
      }

      case 2: {
        setState(604);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(608);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SPECTREParser::ID) {
        setState(607);
        match(SPECTREParser::ID);
      }
      setState(610);
      match(SPECTREParser::AC);
      setState(618);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 61, _ctx)) {
      case 1: {
        setState(614);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(611);
            match(SPECTREParser::NL); 
          }
          setState(616);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx);
        }
        break;
      }

      case 2: {
        setState(617);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AcmatchContext ------------------------------------------------------------------

SPECTREParser::AcmatchContext::AcmatchContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::AcmatchContext::ACMATCH() {
  return getToken(SPECTREParser::ACMATCH, 0);
}

tree::TerminalNode* SPECTREParser::AcmatchContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

tree::TerminalNode* SPECTREParser::AcmatchContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

SPECTREParser::Node_listContext* SPECTREParser::AcmatchContext::node_list() {
  return getRuleContext<SPECTREParser::Node_listContext>(0);
}

SPECTREParser::Parameter_listContext* SPECTREParser::AcmatchContext::parameter_list() {
  return getRuleContext<SPECTREParser::Parameter_listContext>(0);
}

std::vector<tree::TerminalNode *> SPECTREParser::AcmatchContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::AcmatchContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::AcmatchContext::getRuleIndex() const {
  return SPECTREParser::RuleAcmatch;
}

void SPECTREParser::AcmatchContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAcmatch(this);
}

void SPECTREParser::AcmatchContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAcmatch(this);
}


antlrcpp::Any SPECTREParser::AcmatchContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitAcmatch(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::AcmatchContext* SPECTREParser::acmatch() {
  AcmatchContext *_localctx = _tracker.createInstance<AcmatchContext>(_ctx, getState());
  enterRule(_localctx, 52, SPECTREParser::RuleAcmatch);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(657);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 72, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(623);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SPECTREParser::ID) {
        setState(622);
        match(SPECTREParser::ID);
      }
      setState(625);
      match(SPECTREParser::ACMATCH);
      setState(627);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 64, _ctx)) {
      case 1: {
        setState(626);
        node_list();
        break;
      }

      }
      setState(630);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx)) {
      case 1: {
        setState(629);
        parameter_list();
        break;
      }

      }
      setState(639);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx)) {
      case 1: {
        setState(635);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 66, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(632);
            match(SPECTREParser::NL); 
          }
          setState(637);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 66, _ctx);
        }
        break;
      }

      case 2: {
        setState(638);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(642);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SPECTREParser::ID) {
        setState(641);
        match(SPECTREParser::ID);
      }
      setState(644);
      match(SPECTREParser::ACMATCH);
      setState(646);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 69, _ctx)) {
      case 1: {
        setState(645);
        node_list();
        break;
      }

      }
      setState(655);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx)) {
      case 1: {
        setState(651);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(648);
            match(SPECTREParser::NL); 
          }
          setState(653);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx);
        }
        break;
      }

      case 2: {
        setState(654);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DcContext ------------------------------------------------------------------

SPECTREParser::DcContext::DcContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::DcContext::DC() {
  return getToken(SPECTREParser::DC, 0);
}

tree::TerminalNode* SPECTREParser::DcContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

tree::TerminalNode* SPECTREParser::DcContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

SPECTREParser::Parameter_listContext* SPECTREParser::DcContext::parameter_list() {
  return getRuleContext<SPECTREParser::Parameter_listContext>(0);
}

std::vector<tree::TerminalNode *> SPECTREParser::DcContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::DcContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::DcContext::getRuleIndex() const {
  return SPECTREParser::RuleDc;
}

void SPECTREParser::DcContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDc(this);
}

void SPECTREParser::DcContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDc(this);
}


antlrcpp::Any SPECTREParser::DcContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitDc(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::DcContext* SPECTREParser::dc() {
  DcContext *_localctx = _tracker.createInstance<DcContext>(_ctx, getState());
  enterRule(_localctx, 54, SPECTREParser::RuleDc);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(688);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 80, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(660);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SPECTREParser::ID) {
        setState(659);
        match(SPECTREParser::ID);
      }
      setState(662);
      match(SPECTREParser::DC);
      setState(664);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx)) {
      case 1: {
        setState(663);
        parameter_list();
        break;
      }

      }
      setState(673);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 76, _ctx)) {
      case 1: {
        setState(669);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 75, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(666);
            match(SPECTREParser::NL); 
          }
          setState(671);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 75, _ctx);
        }
        break;
      }

      case 2: {
        setState(672);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(676);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SPECTREParser::ID) {
        setState(675);
        match(SPECTREParser::ID);
      }
      setState(678);
      match(SPECTREParser::DC);
      setState(686);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 79, _ctx)) {
      case 1: {
        setState(682);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 78, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(679);
            match(SPECTREParser::NL); 
          }
          setState(684);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 78, _ctx);
        }
        break;
      }

      case 2: {
        setState(685);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DcmatchContext ------------------------------------------------------------------

SPECTREParser::DcmatchContext::DcmatchContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::DcmatchContext::DCMATCH() {
  return getToken(SPECTREParser::DCMATCH, 0);
}

tree::TerminalNode* SPECTREParser::DcmatchContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

tree::TerminalNode* SPECTREParser::DcmatchContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

SPECTREParser::Node_listContext* SPECTREParser::DcmatchContext::node_list() {
  return getRuleContext<SPECTREParser::Node_listContext>(0);
}

SPECTREParser::Parameter_listContext* SPECTREParser::DcmatchContext::parameter_list() {
  return getRuleContext<SPECTREParser::Parameter_listContext>(0);
}

std::vector<tree::TerminalNode *> SPECTREParser::DcmatchContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::DcmatchContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::DcmatchContext::getRuleIndex() const {
  return SPECTREParser::RuleDcmatch;
}

void SPECTREParser::DcmatchContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDcmatch(this);
}

void SPECTREParser::DcmatchContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDcmatch(this);
}


antlrcpp::Any SPECTREParser::DcmatchContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitDcmatch(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::DcmatchContext* SPECTREParser::dcmatch() {
  DcmatchContext *_localctx = _tracker.createInstance<DcmatchContext>(_ctx, getState());
  enterRule(_localctx, 56, SPECTREParser::RuleDcmatch);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(725);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 90, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(691);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 81, _ctx)) {
      case 1: {
        setState(690);
        match(SPECTREParser::ID);
        break;
      }

      }
      setState(694);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 191) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 191)) & ((1ULL << (SPECTREParser::OPEN_ROUND - 191))
        | (1ULL << (SPECTREParser::NUMBER - 191))
        | (1ULL << (SPECTREParser::ID - 191)))) != 0)) {
        setState(693);
        node_list();
      }
      setState(696);
      match(SPECTREParser::DCMATCH);
      setState(698);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 83, _ctx)) {
      case 1: {
        setState(697);
        parameter_list();
        break;
      }

      }
      setState(707);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 85, _ctx)) {
      case 1: {
        setState(703);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 84, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(700);
            match(SPECTREParser::NL); 
          }
          setState(705);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 84, _ctx);
        }
        break;
      }

      case 2: {
        setState(706);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(710);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 86, _ctx)) {
      case 1: {
        setState(709);
        match(SPECTREParser::ID);
        break;
      }

      }
      setState(713);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 191) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 191)) & ((1ULL << (SPECTREParser::OPEN_ROUND - 191))
        | (1ULL << (SPECTREParser::NUMBER - 191))
        | (1ULL << (SPECTREParser::ID - 191)))) != 0)) {
        setState(712);
        node_list();
      }
      setState(715);
      match(SPECTREParser::DCMATCH);
      setState(723);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 89, _ctx)) {
      case 1: {
        setState(719);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 88, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(716);
            match(SPECTREParser::NL); 
          }
          setState(721);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 88, _ctx);
        }
        break;
      }

      case 2: {
        setState(722);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnvlpContext ------------------------------------------------------------------

SPECTREParser::EnvlpContext::EnvlpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::EnvlpContext::ENVLP() {
  return getToken(SPECTREParser::ENVLP, 0);
}

tree::TerminalNode* SPECTREParser::EnvlpContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

tree::TerminalNode* SPECTREParser::EnvlpContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

SPECTREParser::Node_listContext* SPECTREParser::EnvlpContext::node_list() {
  return getRuleContext<SPECTREParser::Node_listContext>(0);
}

SPECTREParser::Parameter_listContext* SPECTREParser::EnvlpContext::parameter_list() {
  return getRuleContext<SPECTREParser::Parameter_listContext>(0);
}

std::vector<tree::TerminalNode *> SPECTREParser::EnvlpContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::EnvlpContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::EnvlpContext::getRuleIndex() const {
  return SPECTREParser::RuleEnvlp;
}

void SPECTREParser::EnvlpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnvlp(this);
}

void SPECTREParser::EnvlpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnvlp(this);
}


antlrcpp::Any SPECTREParser::EnvlpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitEnvlp(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::EnvlpContext* SPECTREParser::envlp() {
  EnvlpContext *_localctx = _tracker.createInstance<EnvlpContext>(_ctx, getState());
  enterRule(_localctx, 58, SPECTREParser::RuleEnvlp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(762);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 100, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(728);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 91, _ctx)) {
      case 1: {
        setState(727);
        match(SPECTREParser::ID);
        break;
      }

      }
      setState(731);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 191) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 191)) & ((1ULL << (SPECTREParser::OPEN_ROUND - 191))
        | (1ULL << (SPECTREParser::NUMBER - 191))
        | (1ULL << (SPECTREParser::ID - 191)))) != 0)) {
        setState(730);
        node_list();
      }
      setState(733);
      match(SPECTREParser::ENVLP);
      setState(735);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 93, _ctx)) {
      case 1: {
        setState(734);
        parameter_list();
        break;
      }

      }
      setState(744);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 95, _ctx)) {
      case 1: {
        setState(740);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 94, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(737);
            match(SPECTREParser::NL); 
          }
          setState(742);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 94, _ctx);
        }
        break;
      }

      case 2: {
        setState(743);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(747);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 96, _ctx)) {
      case 1: {
        setState(746);
        match(SPECTREParser::ID);
        break;
      }

      }
      setState(750);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 191) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 191)) & ((1ULL << (SPECTREParser::OPEN_ROUND - 191))
        | (1ULL << (SPECTREParser::NUMBER - 191))
        | (1ULL << (SPECTREParser::ID - 191)))) != 0)) {
        setState(749);
        node_list();
      }
      setState(752);
      match(SPECTREParser::ENVLP);
      setState(760);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 99, _ctx)) {
      case 1: {
        setState(756);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 98, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(753);
            match(SPECTREParser::NL); 
          }
          setState(758);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 98, _ctx);
        }
        break;
      }

      case 2: {
        setState(759);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SpContext ------------------------------------------------------------------

SPECTREParser::SpContext::SpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::SpContext::SP() {
  return getToken(SPECTREParser::SP, 0);
}

tree::TerminalNode* SPECTREParser::SpContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

tree::TerminalNode* SPECTREParser::SpContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

SPECTREParser::Parameter_listContext* SPECTREParser::SpContext::parameter_list() {
  return getRuleContext<SPECTREParser::Parameter_listContext>(0);
}

std::vector<tree::TerminalNode *> SPECTREParser::SpContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::SpContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::SpContext::getRuleIndex() const {
  return SPECTREParser::RuleSp;
}

void SPECTREParser::SpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSp(this);
}

void SPECTREParser::SpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSp(this);
}


antlrcpp::Any SPECTREParser::SpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitSp(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::SpContext* SPECTREParser::sp() {
  SpContext *_localctx = _tracker.createInstance<SpContext>(_ctx, getState());
  enterRule(_localctx, 60, SPECTREParser::RuleSp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(793);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 108, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(765);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SPECTREParser::ID) {
        setState(764);
        match(SPECTREParser::ID);
      }
      setState(767);
      match(SPECTREParser::SP);
      setState(769);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 102, _ctx)) {
      case 1: {
        setState(768);
        parameter_list();
        break;
      }

      }
      setState(778);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 104, _ctx)) {
      case 1: {
        setState(774);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 103, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(771);
            match(SPECTREParser::NL); 
          }
          setState(776);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 103, _ctx);
        }
        break;
      }

      case 2: {
        setState(777);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(781);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SPECTREParser::ID) {
        setState(780);
        match(SPECTREParser::ID);
      }
      setState(783);
      match(SPECTREParser::SP);
      setState(791);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 107, _ctx)) {
      case 1: {
        setState(787);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 106, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(784);
            match(SPECTREParser::NL); 
          }
          setState(789);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 106, _ctx);
        }
        break;
      }

      case 2: {
        setState(790);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StbContext ------------------------------------------------------------------

SPECTREParser::StbContext::StbContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::StbContext::STB() {
  return getToken(SPECTREParser::STB, 0);
}

tree::TerminalNode* SPECTREParser::StbContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

tree::TerminalNode* SPECTREParser::StbContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

SPECTREParser::Parameter_listContext* SPECTREParser::StbContext::parameter_list() {
  return getRuleContext<SPECTREParser::Parameter_listContext>(0);
}

std::vector<tree::TerminalNode *> SPECTREParser::StbContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::StbContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::StbContext::getRuleIndex() const {
  return SPECTREParser::RuleStb;
}

void SPECTREParser::StbContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStb(this);
}

void SPECTREParser::StbContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStb(this);
}


antlrcpp::Any SPECTREParser::StbContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitStb(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::StbContext* SPECTREParser::stb() {
  StbContext *_localctx = _tracker.createInstance<StbContext>(_ctx, getState());
  enterRule(_localctx, 62, SPECTREParser::RuleStb);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(824);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 116, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(796);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SPECTREParser::ID) {
        setState(795);
        match(SPECTREParser::ID);
      }
      setState(798);
      match(SPECTREParser::STB);
      setState(800);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 110, _ctx)) {
      case 1: {
        setState(799);
        parameter_list();
        break;
      }

      }
      setState(809);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 112, _ctx)) {
      case 1: {
        setState(805);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 111, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(802);
            match(SPECTREParser::NL); 
          }
          setState(807);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 111, _ctx);
        }
        break;
      }

      case 2: {
        setState(808);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(812);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SPECTREParser::ID) {
        setState(811);
        match(SPECTREParser::ID);
      }
      setState(814);
      match(SPECTREParser::STB);
      setState(822);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 115, _ctx)) {
      case 1: {
        setState(818);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 114, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(815);
            match(SPECTREParser::NL); 
          }
          setState(820);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 114, _ctx);
        }
        break;
      }

      case 2: {
        setState(821);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SweepContext ------------------------------------------------------------------

SPECTREParser::SweepContext::SweepContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SPECTREParser::Sweep_headerContext* SPECTREParser::SweepContext::sweep_header() {
  return getRuleContext<SPECTREParser::Sweep_headerContext>(0);
}

SPECTREParser::Sweep_footerContext* SPECTREParser::SweepContext::sweep_footer() {
  return getRuleContext<SPECTREParser::Sweep_footerContext>(0);
}

std::vector<SPECTREParser::Sweep_contentContext *> SPECTREParser::SweepContext::sweep_content() {
  return getRuleContexts<SPECTREParser::Sweep_contentContext>();
}

SPECTREParser::Sweep_contentContext* SPECTREParser::SweepContext::sweep_content(size_t i) {
  return getRuleContext<SPECTREParser::Sweep_contentContext>(i);
}


size_t SPECTREParser::SweepContext::getRuleIndex() const {
  return SPECTREParser::RuleSweep;
}

void SPECTREParser::SweepContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSweep(this);
}

void SPECTREParser::SweepContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSweep(this);
}


antlrcpp::Any SPECTREParser::SweepContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitSweep(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::SweepContext* SPECTREParser::sweep() {
  SweepContext *_localctx = _tracker.createInstance<SweepContext>(_ctx, getState());
  enterRule(_localctx, 64, SPECTREParser::RuleSweep);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(826);
    sweep_header();
    setState(828); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(827);
      sweep_content();
      setState(830); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SPECTREParser::GLOBAL)
      | (1ULL << SPECTREParser::INCLUDE)
      | (1ULL << SPECTREParser::CPP_INCLUDE)
      | (1ULL << SPECTREParser::AHDL_INCLUDE)
      | (1ULL << SPECTREParser::LIBRARY)
      | (1ULL << SPECTREParser::SECTION)
      | (1ULL << SPECTREParser::SUBCKT)
      | (1ULL << SPECTREParser::INLINE_SUBCKT)
      | (1ULL << SPECTREParser::MODEL)
      | (1ULL << SPECTREParser::SAVE)
      | (1ULL << SPECTREParser::NODESET)
      | (1ULL << SPECTREParser::IC)
      | (1ULL << SPECTREParser::PARAMETERS)
      | (1ULL << SPECTREParser::STATISTICS)
      | (1ULL << SPECTREParser::AC)
      | (1ULL << SPECTREParser::ACMATCH)
      | (1ULL << SPECTREParser::DC)
      | (1ULL << SPECTREParser::DCMATCH)
      | (1ULL << SPECTREParser::ENVLP)
      | (1ULL << SPECTREParser::SP)
      | (1ULL << SPECTREParser::STB)
      | (1ULL << SPECTREParser::SWEEP)
      | (1ULL << SPECTREParser::TDR)
      | (1ULL << SPECTREParser::TRAN)
      | (1ULL << SPECTREParser::XF)
      | (1ULL << SPECTREParser::PAC)
      | (1ULL << SPECTREParser::PDISTO))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (SPECTREParser::PNOISE - 64))
      | (1ULL << (SPECTREParser::PSP - 64))
      | (1ULL << (SPECTREParser::PSS - 64))
      | (1ULL << (SPECTREParser::PXF - 64))
      | (1ULL << (SPECTREParser::PZ - 64))
      | (1ULL << (SPECTREParser::QPAC - 64))
      | (1ULL << (SPECTREParser::QPNOISE - 64))
      | (1ULL << (SPECTREParser::QPSP - 64))
      | (1ULL << (SPECTREParser::QPSS - 64))
      | (1ULL << (SPECTREParser::QPXF - 64))
      | (1ULL << (SPECTREParser::SENS - 64)))) != 0) || ((((_la - 191) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 191)) & ((1ULL << (SPECTREParser::OPEN_ROUND - 191))
      | (1ULL << (SPECTREParser::NUMBER - 191))
      | (1ULL << (SPECTREParser::ID - 191)))) != 0));
    setState(832);
    sweep_footer();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sweep_headerContext ------------------------------------------------------------------

SPECTREParser::Sweep_headerContext::Sweep_headerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Sweep_headerContext::SWEEP() {
  return getToken(SPECTREParser::SWEEP, 0);
}

tree::TerminalNode* SPECTREParser::Sweep_headerContext::OPEN_CURLY() {
  return getToken(SPECTREParser::OPEN_CURLY, 0);
}

tree::TerminalNode* SPECTREParser::Sweep_headerContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

tree::TerminalNode* SPECTREParser::Sweep_headerContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

std::vector<tree::TerminalNode *> SPECTREParser::Sweep_headerContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::Sweep_headerContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}

std::vector<SPECTREParser::Parameter_listContext *> SPECTREParser::Sweep_headerContext::parameter_list() {
  return getRuleContexts<SPECTREParser::Parameter_listContext>();
}

SPECTREParser::Parameter_listContext* SPECTREParser::Sweep_headerContext::parameter_list(size_t i) {
  return getRuleContext<SPECTREParser::Parameter_listContext>(i);
}


size_t SPECTREParser::Sweep_headerContext::getRuleIndex() const {
  return SPECTREParser::RuleSweep_header;
}

void SPECTREParser::Sweep_headerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSweep_header(this);
}

void SPECTREParser::Sweep_headerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSweep_header(this);
}


antlrcpp::Any SPECTREParser::Sweep_headerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitSweep_header(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Sweep_headerContext* SPECTREParser::sweep_header() {
  Sweep_headerContext *_localctx = _tracker.createInstance<Sweep_headerContext>(_ctx, getState());
  enterRule(_localctx, 66, SPECTREParser::RuleSweep_header);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(835);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SPECTREParser::ID) {
      setState(834);
      match(SPECTREParser::ID);
    }
    setState(837);
    match(SPECTREParser::SWEEP);
    setState(841);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SPECTREParser::NL) {
      setState(838);
      match(SPECTREParser::NL);
      setState(843);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(847);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SPECTREParser::SECTION)
      | (1ULL << SPECTREParser::SAVE)
      | (1ULL << SPECTREParser::PORTS)
      | (1ULL << SPECTREParser::DC))) != 0) || _la == SPECTREParser::DELAY || _la == SPECTREParser::ID) {
      setState(844);
      parameter_list();
      setState(849);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(850);
    match(SPECTREParser::OPEN_CURLY);
    setState(858);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SPECTREParser::GLOBAL:
      case SPECTREParser::INCLUDE:
      case SPECTREParser::CPP_INCLUDE:
      case SPECTREParser::AHDL_INCLUDE:
      case SPECTREParser::LIBRARY:
      case SPECTREParser::SECTION:
      case SPECTREParser::SUBCKT:
      case SPECTREParser::INLINE_SUBCKT:
      case SPECTREParser::MODEL:
      case SPECTREParser::SAVE:
      case SPECTREParser::NODESET:
      case SPECTREParser::IC:
      case SPECTREParser::PARAMETERS:
      case SPECTREParser::STATISTICS:
      case SPECTREParser::AC:
      case SPECTREParser::ACMATCH:
      case SPECTREParser::DC:
      case SPECTREParser::DCMATCH:
      case SPECTREParser::ENVLP:
      case SPECTREParser::SP:
      case SPECTREParser::STB:
      case SPECTREParser::SWEEP:
      case SPECTREParser::TDR:
      case SPECTREParser::TRAN:
      case SPECTREParser::XF:
      case SPECTREParser::PAC:
      case SPECTREParser::PDISTO:
      case SPECTREParser::PNOISE:
      case SPECTREParser::PSP:
      case SPECTREParser::PSS:
      case SPECTREParser::PXF:
      case SPECTREParser::PZ:
      case SPECTREParser::QPAC:
      case SPECTREParser::QPNOISE:
      case SPECTREParser::QPSP:
      case SPECTREParser::QPSS:
      case SPECTREParser::QPXF:
      case SPECTREParser::SENS:
      case SPECTREParser::OPEN_ROUND:
      case SPECTREParser::NUMBER:
      case SPECTREParser::ID:
      case SPECTREParser::NL: {
        setState(854);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SPECTREParser::NL) {
          setState(851);
          match(SPECTREParser::NL);
          setState(856);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case SPECTREParser::EOF: {
        setState(857);
        match(SPECTREParser::EOF);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sweep_contentContext ------------------------------------------------------------------

SPECTREParser::Sweep_contentContext::Sweep_contentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SPECTREParser::Netlist_entityContext* SPECTREParser::Sweep_contentContext::netlist_entity() {
  return getRuleContext<SPECTREParser::Netlist_entityContext>(0);
}


size_t SPECTREParser::Sweep_contentContext::getRuleIndex() const {
  return SPECTREParser::RuleSweep_content;
}

void SPECTREParser::Sweep_contentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSweep_content(this);
}

void SPECTREParser::Sweep_contentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSweep_content(this);
}


antlrcpp::Any SPECTREParser::Sweep_contentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitSweep_content(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Sweep_contentContext* SPECTREParser::sweep_content() {
  Sweep_contentContext *_localctx = _tracker.createInstance<Sweep_contentContext>(_ctx, getState());
  enterRule(_localctx, 68, SPECTREParser::RuleSweep_content);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(860);
    netlist_entity();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sweep_footerContext ------------------------------------------------------------------

SPECTREParser::Sweep_footerContext::Sweep_footerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Sweep_footerContext::CLOSE_CURLY() {
  return getToken(SPECTREParser::CLOSE_CURLY, 0);
}

tree::TerminalNode* SPECTREParser::Sweep_footerContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

std::vector<tree::TerminalNode *> SPECTREParser::Sweep_footerContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::Sweep_footerContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::Sweep_footerContext::getRuleIndex() const {
  return SPECTREParser::RuleSweep_footer;
}

void SPECTREParser::Sweep_footerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSweep_footer(this);
}

void SPECTREParser::Sweep_footerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSweep_footer(this);
}


antlrcpp::Any SPECTREParser::Sweep_footerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitSweep_footer(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Sweep_footerContext* SPECTREParser::sweep_footer() {
  Sweep_footerContext *_localctx = _tracker.createInstance<Sweep_footerContext>(_ctx, getState());
  enterRule(_localctx, 70, SPECTREParser::RuleSweep_footer);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(862);
    match(SPECTREParser::CLOSE_CURLY);
    setState(870);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 124, _ctx)) {
    case 1: {
      setState(866);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 123, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(863);
          match(SPECTREParser::NL); 
        }
        setState(868);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 123, _ctx);
      }
      break;
    }

    case 2: {
      setState(869);
      match(SPECTREParser::EOF);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TdrContext ------------------------------------------------------------------

SPECTREParser::TdrContext::TdrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::TdrContext::TDR() {
  return getToken(SPECTREParser::TDR, 0);
}

tree::TerminalNode* SPECTREParser::TdrContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

tree::TerminalNode* SPECTREParser::TdrContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

SPECTREParser::Parameter_listContext* SPECTREParser::TdrContext::parameter_list() {
  return getRuleContext<SPECTREParser::Parameter_listContext>(0);
}

std::vector<tree::TerminalNode *> SPECTREParser::TdrContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::TdrContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::TdrContext::getRuleIndex() const {
  return SPECTREParser::RuleTdr;
}

void SPECTREParser::TdrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTdr(this);
}

void SPECTREParser::TdrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTdr(this);
}


antlrcpp::Any SPECTREParser::TdrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitTdr(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::TdrContext* SPECTREParser::tdr() {
  TdrContext *_localctx = _tracker.createInstance<TdrContext>(_ctx, getState());
  enterRule(_localctx, 72, SPECTREParser::RuleTdr);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(901);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 132, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(873);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SPECTREParser::ID) {
        setState(872);
        match(SPECTREParser::ID);
      }
      setState(875);
      match(SPECTREParser::TDR);
      setState(877);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 126, _ctx)) {
      case 1: {
        setState(876);
        parameter_list();
        break;
      }

      }
      setState(886);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 128, _ctx)) {
      case 1: {
        setState(882);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 127, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(879);
            match(SPECTREParser::NL); 
          }
          setState(884);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 127, _ctx);
        }
        break;
      }

      case 2: {
        setState(885);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(889);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SPECTREParser::ID) {
        setState(888);
        match(SPECTREParser::ID);
      }
      setState(891);
      match(SPECTREParser::TDR);
      setState(899);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 131, _ctx)) {
      case 1: {
        setState(895);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 130, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(892);
            match(SPECTREParser::NL); 
          }
          setState(897);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 130, _ctx);
        }
        break;
      }

      case 2: {
        setState(898);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TranContext ------------------------------------------------------------------

SPECTREParser::TranContext::TranContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::TranContext::TRAN() {
  return getToken(SPECTREParser::TRAN, 0);
}

tree::TerminalNode* SPECTREParser::TranContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

tree::TerminalNode* SPECTREParser::TranContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

SPECTREParser::Parameter_listContext* SPECTREParser::TranContext::parameter_list() {
  return getRuleContext<SPECTREParser::Parameter_listContext>(0);
}

std::vector<tree::TerminalNode *> SPECTREParser::TranContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::TranContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::TranContext::getRuleIndex() const {
  return SPECTREParser::RuleTran;
}

void SPECTREParser::TranContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTran(this);
}

void SPECTREParser::TranContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTran(this);
}


antlrcpp::Any SPECTREParser::TranContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitTran(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::TranContext* SPECTREParser::tran() {
  TranContext *_localctx = _tracker.createInstance<TranContext>(_ctx, getState());
  enterRule(_localctx, 74, SPECTREParser::RuleTran);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(932);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 140, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(904);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SPECTREParser::ID) {
        setState(903);
        match(SPECTREParser::ID);
      }
      setState(906);
      match(SPECTREParser::TRAN);
      setState(908);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 134, _ctx)) {
      case 1: {
        setState(907);
        parameter_list();
        break;
      }

      }
      setState(917);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 136, _ctx)) {
      case 1: {
        setState(913);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 135, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(910);
            match(SPECTREParser::NL); 
          }
          setState(915);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 135, _ctx);
        }
        break;
      }

      case 2: {
        setState(916);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(920);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SPECTREParser::ID) {
        setState(919);
        match(SPECTREParser::ID);
      }
      setState(922);
      match(SPECTREParser::TRAN);
      setState(930);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 139, _ctx)) {
      case 1: {
        setState(926);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 138, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(923);
            match(SPECTREParser::NL); 
          }
          setState(928);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 138, _ctx);
        }
        break;
      }

      case 2: {
        setState(929);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- XfContext ------------------------------------------------------------------

SPECTREParser::XfContext::XfContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::XfContext::XF() {
  return getToken(SPECTREParser::XF, 0);
}

tree::TerminalNode* SPECTREParser::XfContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

tree::TerminalNode* SPECTREParser::XfContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

SPECTREParser::Node_listContext* SPECTREParser::XfContext::node_list() {
  return getRuleContext<SPECTREParser::Node_listContext>(0);
}

SPECTREParser::Parameter_listContext* SPECTREParser::XfContext::parameter_list() {
  return getRuleContext<SPECTREParser::Parameter_listContext>(0);
}

std::vector<tree::TerminalNode *> SPECTREParser::XfContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::XfContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::XfContext::getRuleIndex() const {
  return SPECTREParser::RuleXf;
}

void SPECTREParser::XfContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterXf(this);
}

void SPECTREParser::XfContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitXf(this);
}


antlrcpp::Any SPECTREParser::XfContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitXf(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::XfContext* SPECTREParser::xf() {
  XfContext *_localctx = _tracker.createInstance<XfContext>(_ctx, getState());
  enterRule(_localctx, 76, SPECTREParser::RuleXf);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(969);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 150, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(935);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 141, _ctx)) {
      case 1: {
        setState(934);
        match(SPECTREParser::ID);
        break;
      }

      }
      setState(938);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 191) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 191)) & ((1ULL << (SPECTREParser::OPEN_ROUND - 191))
        | (1ULL << (SPECTREParser::NUMBER - 191))
        | (1ULL << (SPECTREParser::ID - 191)))) != 0)) {
        setState(937);
        node_list();
      }
      setState(940);
      match(SPECTREParser::XF);
      setState(942);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 143, _ctx)) {
      case 1: {
        setState(941);
        parameter_list();
        break;
      }

      }
      setState(951);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 145, _ctx)) {
      case 1: {
        setState(947);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 144, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(944);
            match(SPECTREParser::NL); 
          }
          setState(949);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 144, _ctx);
        }
        break;
      }

      case 2: {
        setState(950);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(954);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 146, _ctx)) {
      case 1: {
        setState(953);
        match(SPECTREParser::ID);
        break;
      }

      }
      setState(957);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 191) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 191)) & ((1ULL << (SPECTREParser::OPEN_ROUND - 191))
        | (1ULL << (SPECTREParser::NUMBER - 191))
        | (1ULL << (SPECTREParser::ID - 191)))) != 0)) {
        setState(956);
        node_list();
      }
      setState(959);
      match(SPECTREParser::XF);
      setState(967);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 149, _ctx)) {
      case 1: {
        setState(963);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 148, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(960);
            match(SPECTREParser::NL); 
          }
          setState(965);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 148, _ctx);
        }
        break;
      }

      case 2: {
        setState(966);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PacContext ------------------------------------------------------------------

SPECTREParser::PacContext::PacContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::PacContext::PAC() {
  return getToken(SPECTREParser::PAC, 0);
}

tree::TerminalNode* SPECTREParser::PacContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

tree::TerminalNode* SPECTREParser::PacContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

SPECTREParser::Node_listContext* SPECTREParser::PacContext::node_list() {
  return getRuleContext<SPECTREParser::Node_listContext>(0);
}

SPECTREParser::Parameter_listContext* SPECTREParser::PacContext::parameter_list() {
  return getRuleContext<SPECTREParser::Parameter_listContext>(0);
}

std::vector<tree::TerminalNode *> SPECTREParser::PacContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::PacContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::PacContext::getRuleIndex() const {
  return SPECTREParser::RulePac;
}

void SPECTREParser::PacContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPac(this);
}

void SPECTREParser::PacContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPac(this);
}


antlrcpp::Any SPECTREParser::PacContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitPac(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::PacContext* SPECTREParser::pac() {
  PacContext *_localctx = _tracker.createInstance<PacContext>(_ctx, getState());
  enterRule(_localctx, 78, SPECTREParser::RulePac);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(1006);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 160, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(972);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 151, _ctx)) {
      case 1: {
        setState(971);
        match(SPECTREParser::ID);
        break;
      }

      }
      setState(975);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 191) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 191)) & ((1ULL << (SPECTREParser::OPEN_ROUND - 191))
        | (1ULL << (SPECTREParser::NUMBER - 191))
        | (1ULL << (SPECTREParser::ID - 191)))) != 0)) {
        setState(974);
        node_list();
      }
      setState(977);
      match(SPECTREParser::PAC);
      setState(979);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 153, _ctx)) {
      case 1: {
        setState(978);
        parameter_list();
        break;
      }

      }
      setState(988);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 155, _ctx)) {
      case 1: {
        setState(984);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 154, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(981);
            match(SPECTREParser::NL); 
          }
          setState(986);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 154, _ctx);
        }
        break;
      }

      case 2: {
        setState(987);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(991);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 156, _ctx)) {
      case 1: {
        setState(990);
        match(SPECTREParser::ID);
        break;
      }

      }
      setState(994);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 191) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 191)) & ((1ULL << (SPECTREParser::OPEN_ROUND - 191))
        | (1ULL << (SPECTREParser::NUMBER - 191))
        | (1ULL << (SPECTREParser::ID - 191)))) != 0)) {
        setState(993);
        node_list();
      }
      setState(996);
      match(SPECTREParser::PAC);
      setState(1004);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 159, _ctx)) {
      case 1: {
        setState(1000);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 158, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(997);
            match(SPECTREParser::NL); 
          }
          setState(1002);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 158, _ctx);
        }
        break;
      }

      case 2: {
        setState(1003);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PdistoContext ------------------------------------------------------------------

SPECTREParser::PdistoContext::PdistoContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::PdistoContext::PDISTO() {
  return getToken(SPECTREParser::PDISTO, 0);
}

tree::TerminalNode* SPECTREParser::PdistoContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

tree::TerminalNode* SPECTREParser::PdistoContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

SPECTREParser::Node_listContext* SPECTREParser::PdistoContext::node_list() {
  return getRuleContext<SPECTREParser::Node_listContext>(0);
}

SPECTREParser::Parameter_listContext* SPECTREParser::PdistoContext::parameter_list() {
  return getRuleContext<SPECTREParser::Parameter_listContext>(0);
}

std::vector<tree::TerminalNode *> SPECTREParser::PdistoContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::PdistoContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::PdistoContext::getRuleIndex() const {
  return SPECTREParser::RulePdisto;
}

void SPECTREParser::PdistoContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPdisto(this);
}

void SPECTREParser::PdistoContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPdisto(this);
}


antlrcpp::Any SPECTREParser::PdistoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitPdisto(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::PdistoContext* SPECTREParser::pdisto() {
  PdistoContext *_localctx = _tracker.createInstance<PdistoContext>(_ctx, getState());
  enterRule(_localctx, 80, SPECTREParser::RulePdisto);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(1043);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 170, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1009);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 161, _ctx)) {
      case 1: {
        setState(1008);
        match(SPECTREParser::ID);
        break;
      }

      }
      setState(1012);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 191) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 191)) & ((1ULL << (SPECTREParser::OPEN_ROUND - 191))
        | (1ULL << (SPECTREParser::NUMBER - 191))
        | (1ULL << (SPECTREParser::ID - 191)))) != 0)) {
        setState(1011);
        node_list();
      }
      setState(1014);
      match(SPECTREParser::PDISTO);
      setState(1016);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 163, _ctx)) {
      case 1: {
        setState(1015);
        parameter_list();
        break;
      }

      }
      setState(1025);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 165, _ctx)) {
      case 1: {
        setState(1021);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 164, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1018);
            match(SPECTREParser::NL); 
          }
          setState(1023);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 164, _ctx);
        }
        break;
      }

      case 2: {
        setState(1024);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1028);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 166, _ctx)) {
      case 1: {
        setState(1027);
        match(SPECTREParser::ID);
        break;
      }

      }
      setState(1031);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 191) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 191)) & ((1ULL << (SPECTREParser::OPEN_ROUND - 191))
        | (1ULL << (SPECTREParser::NUMBER - 191))
        | (1ULL << (SPECTREParser::ID - 191)))) != 0)) {
        setState(1030);
        node_list();
      }
      setState(1033);
      match(SPECTREParser::PDISTO);
      setState(1041);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 169, _ctx)) {
      case 1: {
        setState(1037);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 168, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1034);
            match(SPECTREParser::NL); 
          }
          setState(1039);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 168, _ctx);
        }
        break;
      }

      case 2: {
        setState(1040);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PnoiseContext ------------------------------------------------------------------

SPECTREParser::PnoiseContext::PnoiseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::PnoiseContext::PNOISE() {
  return getToken(SPECTREParser::PNOISE, 0);
}

tree::TerminalNode* SPECTREParser::PnoiseContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

tree::TerminalNode* SPECTREParser::PnoiseContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

SPECTREParser::Node_listContext* SPECTREParser::PnoiseContext::node_list() {
  return getRuleContext<SPECTREParser::Node_listContext>(0);
}

SPECTREParser::Parameter_listContext* SPECTREParser::PnoiseContext::parameter_list() {
  return getRuleContext<SPECTREParser::Parameter_listContext>(0);
}

std::vector<tree::TerminalNode *> SPECTREParser::PnoiseContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::PnoiseContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::PnoiseContext::getRuleIndex() const {
  return SPECTREParser::RulePnoise;
}

void SPECTREParser::PnoiseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPnoise(this);
}

void SPECTREParser::PnoiseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPnoise(this);
}


antlrcpp::Any SPECTREParser::PnoiseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitPnoise(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::PnoiseContext* SPECTREParser::pnoise() {
  PnoiseContext *_localctx = _tracker.createInstance<PnoiseContext>(_ctx, getState());
  enterRule(_localctx, 82, SPECTREParser::RulePnoise);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(1080);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 180, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1046);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 171, _ctx)) {
      case 1: {
        setState(1045);
        match(SPECTREParser::ID);
        break;
      }

      }
      setState(1049);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 191) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 191)) & ((1ULL << (SPECTREParser::OPEN_ROUND - 191))
        | (1ULL << (SPECTREParser::NUMBER - 191))
        | (1ULL << (SPECTREParser::ID - 191)))) != 0)) {
        setState(1048);
        node_list();
      }
      setState(1051);
      match(SPECTREParser::PNOISE);
      setState(1053);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 173, _ctx)) {
      case 1: {
        setState(1052);
        parameter_list();
        break;
      }

      }
      setState(1062);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 175, _ctx)) {
      case 1: {
        setState(1058);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 174, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1055);
            match(SPECTREParser::NL); 
          }
          setState(1060);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 174, _ctx);
        }
        break;
      }

      case 2: {
        setState(1061);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1065);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 176, _ctx)) {
      case 1: {
        setState(1064);
        match(SPECTREParser::ID);
        break;
      }

      }
      setState(1068);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 191) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 191)) & ((1ULL << (SPECTREParser::OPEN_ROUND - 191))
        | (1ULL << (SPECTREParser::NUMBER - 191))
        | (1ULL << (SPECTREParser::ID - 191)))) != 0)) {
        setState(1067);
        node_list();
      }
      setState(1070);
      match(SPECTREParser::PNOISE);
      setState(1078);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 179, _ctx)) {
      case 1: {
        setState(1074);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 178, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1071);
            match(SPECTREParser::NL); 
          }
          setState(1076);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 178, _ctx);
        }
        break;
      }

      case 2: {
        setState(1077);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PspContext ------------------------------------------------------------------

SPECTREParser::PspContext::PspContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::PspContext::PSP() {
  return getToken(SPECTREParser::PSP, 0);
}

tree::TerminalNode* SPECTREParser::PspContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

tree::TerminalNode* SPECTREParser::PspContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

SPECTREParser::Parameter_listContext* SPECTREParser::PspContext::parameter_list() {
  return getRuleContext<SPECTREParser::Parameter_listContext>(0);
}

std::vector<tree::TerminalNode *> SPECTREParser::PspContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::PspContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::PspContext::getRuleIndex() const {
  return SPECTREParser::RulePsp;
}

void SPECTREParser::PspContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPsp(this);
}

void SPECTREParser::PspContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPsp(this);
}


antlrcpp::Any SPECTREParser::PspContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitPsp(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::PspContext* SPECTREParser::psp() {
  PspContext *_localctx = _tracker.createInstance<PspContext>(_ctx, getState());
  enterRule(_localctx, 84, SPECTREParser::RulePsp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(1111);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 188, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1083);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SPECTREParser::ID) {
        setState(1082);
        match(SPECTREParser::ID);
      }
      setState(1085);
      match(SPECTREParser::PSP);
      setState(1087);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 182, _ctx)) {
      case 1: {
        setState(1086);
        parameter_list();
        break;
      }

      }
      setState(1096);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 184, _ctx)) {
      case 1: {
        setState(1092);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 183, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1089);
            match(SPECTREParser::NL); 
          }
          setState(1094);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 183, _ctx);
        }
        break;
      }

      case 2: {
        setState(1095);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1099);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SPECTREParser::ID) {
        setState(1098);
        match(SPECTREParser::ID);
      }
      setState(1101);
      match(SPECTREParser::PSP);
      setState(1109);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 187, _ctx)) {
      case 1: {
        setState(1105);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 186, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1102);
            match(SPECTREParser::NL); 
          }
          setState(1107);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 186, _ctx);
        }
        break;
      }

      case 2: {
        setState(1108);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PssContext ------------------------------------------------------------------

SPECTREParser::PssContext::PssContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::PssContext::PSS() {
  return getToken(SPECTREParser::PSS, 0);
}

tree::TerminalNode* SPECTREParser::PssContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

tree::TerminalNode* SPECTREParser::PssContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

SPECTREParser::Node_listContext* SPECTREParser::PssContext::node_list() {
  return getRuleContext<SPECTREParser::Node_listContext>(0);
}

SPECTREParser::Parameter_listContext* SPECTREParser::PssContext::parameter_list() {
  return getRuleContext<SPECTREParser::Parameter_listContext>(0);
}

std::vector<tree::TerminalNode *> SPECTREParser::PssContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::PssContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::PssContext::getRuleIndex() const {
  return SPECTREParser::RulePss;
}

void SPECTREParser::PssContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPss(this);
}

void SPECTREParser::PssContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPss(this);
}


antlrcpp::Any SPECTREParser::PssContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitPss(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::PssContext* SPECTREParser::pss() {
  PssContext *_localctx = _tracker.createInstance<PssContext>(_ctx, getState());
  enterRule(_localctx, 86, SPECTREParser::RulePss);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(1148);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 198, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1114);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 189, _ctx)) {
      case 1: {
        setState(1113);
        match(SPECTREParser::ID);
        break;
      }

      }
      setState(1117);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 191) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 191)) & ((1ULL << (SPECTREParser::OPEN_ROUND - 191))
        | (1ULL << (SPECTREParser::NUMBER - 191))
        | (1ULL << (SPECTREParser::ID - 191)))) != 0)) {
        setState(1116);
        node_list();
      }
      setState(1119);
      match(SPECTREParser::PSS);
      setState(1121);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 191, _ctx)) {
      case 1: {
        setState(1120);
        parameter_list();
        break;
      }

      }
      setState(1130);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 193, _ctx)) {
      case 1: {
        setState(1126);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 192, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1123);
            match(SPECTREParser::NL); 
          }
          setState(1128);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 192, _ctx);
        }
        break;
      }

      case 2: {
        setState(1129);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1133);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 194, _ctx)) {
      case 1: {
        setState(1132);
        match(SPECTREParser::ID);
        break;
      }

      }
      setState(1136);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 191) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 191)) & ((1ULL << (SPECTREParser::OPEN_ROUND - 191))
        | (1ULL << (SPECTREParser::NUMBER - 191))
        | (1ULL << (SPECTREParser::ID - 191)))) != 0)) {
        setState(1135);
        node_list();
      }
      setState(1138);
      match(SPECTREParser::PSS);
      setState(1146);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 197, _ctx)) {
      case 1: {
        setState(1142);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 196, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1139);
            match(SPECTREParser::NL); 
          }
          setState(1144);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 196, _ctx);
        }
        break;
      }

      case 2: {
        setState(1145);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PxfContext ------------------------------------------------------------------

SPECTREParser::PxfContext::PxfContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::PxfContext::PXF() {
  return getToken(SPECTREParser::PXF, 0);
}

tree::TerminalNode* SPECTREParser::PxfContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

tree::TerminalNode* SPECTREParser::PxfContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

SPECTREParser::Node_listContext* SPECTREParser::PxfContext::node_list() {
  return getRuleContext<SPECTREParser::Node_listContext>(0);
}

SPECTREParser::Parameter_listContext* SPECTREParser::PxfContext::parameter_list() {
  return getRuleContext<SPECTREParser::Parameter_listContext>(0);
}

std::vector<tree::TerminalNode *> SPECTREParser::PxfContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::PxfContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::PxfContext::getRuleIndex() const {
  return SPECTREParser::RulePxf;
}

void SPECTREParser::PxfContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPxf(this);
}

void SPECTREParser::PxfContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPxf(this);
}


antlrcpp::Any SPECTREParser::PxfContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitPxf(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::PxfContext* SPECTREParser::pxf() {
  PxfContext *_localctx = _tracker.createInstance<PxfContext>(_ctx, getState());
  enterRule(_localctx, 88, SPECTREParser::RulePxf);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(1185);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 208, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1151);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 199, _ctx)) {
      case 1: {
        setState(1150);
        match(SPECTREParser::ID);
        break;
      }

      }
      setState(1154);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 191) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 191)) & ((1ULL << (SPECTREParser::OPEN_ROUND - 191))
        | (1ULL << (SPECTREParser::NUMBER - 191))
        | (1ULL << (SPECTREParser::ID - 191)))) != 0)) {
        setState(1153);
        node_list();
      }
      setState(1156);
      match(SPECTREParser::PXF);
      setState(1158);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 201, _ctx)) {
      case 1: {
        setState(1157);
        parameter_list();
        break;
      }

      }
      setState(1167);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 203, _ctx)) {
      case 1: {
        setState(1163);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 202, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1160);
            match(SPECTREParser::NL); 
          }
          setState(1165);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 202, _ctx);
        }
        break;
      }

      case 2: {
        setState(1166);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1170);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 204, _ctx)) {
      case 1: {
        setState(1169);
        match(SPECTREParser::ID);
        break;
      }

      }
      setState(1173);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 191) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 191)) & ((1ULL << (SPECTREParser::OPEN_ROUND - 191))
        | (1ULL << (SPECTREParser::NUMBER - 191))
        | (1ULL << (SPECTREParser::ID - 191)))) != 0)) {
        setState(1172);
        node_list();
      }
      setState(1175);
      match(SPECTREParser::PXF);
      setState(1183);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 207, _ctx)) {
      case 1: {
        setState(1179);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 206, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1176);
            match(SPECTREParser::NL); 
          }
          setState(1181);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 206, _ctx);
        }
        break;
      }

      case 2: {
        setState(1182);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PzContext ------------------------------------------------------------------

SPECTREParser::PzContext::PzContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::PzContext::PZ() {
  return getToken(SPECTREParser::PZ, 0);
}

tree::TerminalNode* SPECTREParser::PzContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

tree::TerminalNode* SPECTREParser::PzContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

SPECTREParser::Node_listContext* SPECTREParser::PzContext::node_list() {
  return getRuleContext<SPECTREParser::Node_listContext>(0);
}

SPECTREParser::Parameter_listContext* SPECTREParser::PzContext::parameter_list() {
  return getRuleContext<SPECTREParser::Parameter_listContext>(0);
}

std::vector<tree::TerminalNode *> SPECTREParser::PzContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::PzContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::PzContext::getRuleIndex() const {
  return SPECTREParser::RulePz;
}

void SPECTREParser::PzContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPz(this);
}

void SPECTREParser::PzContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPz(this);
}


antlrcpp::Any SPECTREParser::PzContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitPz(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::PzContext* SPECTREParser::pz() {
  PzContext *_localctx = _tracker.createInstance<PzContext>(_ctx, getState());
  enterRule(_localctx, 90, SPECTREParser::RulePz);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(1222);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 218, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1188);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 209, _ctx)) {
      case 1: {
        setState(1187);
        match(SPECTREParser::ID);
        break;
      }

      }
      setState(1191);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 191) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 191)) & ((1ULL << (SPECTREParser::OPEN_ROUND - 191))
        | (1ULL << (SPECTREParser::NUMBER - 191))
        | (1ULL << (SPECTREParser::ID - 191)))) != 0)) {
        setState(1190);
        node_list();
      }
      setState(1193);
      match(SPECTREParser::PZ);
      setState(1195);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 211, _ctx)) {
      case 1: {
        setState(1194);
        parameter_list();
        break;
      }

      }
      setState(1204);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 213, _ctx)) {
      case 1: {
        setState(1200);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 212, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1197);
            match(SPECTREParser::NL); 
          }
          setState(1202);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 212, _ctx);
        }
        break;
      }

      case 2: {
        setState(1203);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1207);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 214, _ctx)) {
      case 1: {
        setState(1206);
        match(SPECTREParser::ID);
        break;
      }

      }
      setState(1210);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 191) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 191)) & ((1ULL << (SPECTREParser::OPEN_ROUND - 191))
        | (1ULL << (SPECTREParser::NUMBER - 191))
        | (1ULL << (SPECTREParser::ID - 191)))) != 0)) {
        setState(1209);
        node_list();
      }
      setState(1212);
      match(SPECTREParser::PZ);
      setState(1220);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 217, _ctx)) {
      case 1: {
        setState(1216);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 216, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1213);
            match(SPECTREParser::NL); 
          }
          setState(1218);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 216, _ctx);
        }
        break;
      }

      case 2: {
        setState(1219);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QpacContext ------------------------------------------------------------------

SPECTREParser::QpacContext::QpacContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::QpacContext::QPAC() {
  return getToken(SPECTREParser::QPAC, 0);
}

tree::TerminalNode* SPECTREParser::QpacContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

tree::TerminalNode* SPECTREParser::QpacContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

SPECTREParser::Parameter_listContext* SPECTREParser::QpacContext::parameter_list() {
  return getRuleContext<SPECTREParser::Parameter_listContext>(0);
}

std::vector<tree::TerminalNode *> SPECTREParser::QpacContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::QpacContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::QpacContext::getRuleIndex() const {
  return SPECTREParser::RuleQpac;
}

void SPECTREParser::QpacContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQpac(this);
}

void SPECTREParser::QpacContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQpac(this);
}


antlrcpp::Any SPECTREParser::QpacContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitQpac(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::QpacContext* SPECTREParser::qpac() {
  QpacContext *_localctx = _tracker.createInstance<QpacContext>(_ctx, getState());
  enterRule(_localctx, 92, SPECTREParser::RuleQpac);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(1253);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 226, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1225);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SPECTREParser::ID) {
        setState(1224);
        match(SPECTREParser::ID);
      }
      setState(1227);
      match(SPECTREParser::QPAC);
      setState(1229);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 220, _ctx)) {
      case 1: {
        setState(1228);
        parameter_list();
        break;
      }

      }
      setState(1238);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 222, _ctx)) {
      case 1: {
        setState(1234);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 221, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1231);
            match(SPECTREParser::NL); 
          }
          setState(1236);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 221, _ctx);
        }
        break;
      }

      case 2: {
        setState(1237);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1241);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SPECTREParser::ID) {
        setState(1240);
        match(SPECTREParser::ID);
      }
      setState(1243);
      match(SPECTREParser::QPAC);
      setState(1251);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 225, _ctx)) {
      case 1: {
        setState(1247);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 224, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1244);
            match(SPECTREParser::NL); 
          }
          setState(1249);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 224, _ctx);
        }
        break;
      }

      case 2: {
        setState(1250);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QpnoiseContext ------------------------------------------------------------------

SPECTREParser::QpnoiseContext::QpnoiseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::QpnoiseContext::QPNOISE() {
  return getToken(SPECTREParser::QPNOISE, 0);
}

tree::TerminalNode* SPECTREParser::QpnoiseContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

tree::TerminalNode* SPECTREParser::QpnoiseContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

SPECTREParser::Node_listContext* SPECTREParser::QpnoiseContext::node_list() {
  return getRuleContext<SPECTREParser::Node_listContext>(0);
}

SPECTREParser::Parameter_listContext* SPECTREParser::QpnoiseContext::parameter_list() {
  return getRuleContext<SPECTREParser::Parameter_listContext>(0);
}

std::vector<tree::TerminalNode *> SPECTREParser::QpnoiseContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::QpnoiseContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::QpnoiseContext::getRuleIndex() const {
  return SPECTREParser::RuleQpnoise;
}

void SPECTREParser::QpnoiseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQpnoise(this);
}

void SPECTREParser::QpnoiseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQpnoise(this);
}


antlrcpp::Any SPECTREParser::QpnoiseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitQpnoise(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::QpnoiseContext* SPECTREParser::qpnoise() {
  QpnoiseContext *_localctx = _tracker.createInstance<QpnoiseContext>(_ctx, getState());
  enterRule(_localctx, 94, SPECTREParser::RuleQpnoise);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(1290);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 236, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1256);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 227, _ctx)) {
      case 1: {
        setState(1255);
        match(SPECTREParser::ID);
        break;
      }

      }
      setState(1259);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 191) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 191)) & ((1ULL << (SPECTREParser::OPEN_ROUND - 191))
        | (1ULL << (SPECTREParser::NUMBER - 191))
        | (1ULL << (SPECTREParser::ID - 191)))) != 0)) {
        setState(1258);
        node_list();
      }
      setState(1261);
      match(SPECTREParser::QPNOISE);
      setState(1263);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 229, _ctx)) {
      case 1: {
        setState(1262);
        parameter_list();
        break;
      }

      }
      setState(1272);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 231, _ctx)) {
      case 1: {
        setState(1268);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 230, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1265);
            match(SPECTREParser::NL); 
          }
          setState(1270);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 230, _ctx);
        }
        break;
      }

      case 2: {
        setState(1271);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1275);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 232, _ctx)) {
      case 1: {
        setState(1274);
        match(SPECTREParser::ID);
        break;
      }

      }
      setState(1278);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 191) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 191)) & ((1ULL << (SPECTREParser::OPEN_ROUND - 191))
        | (1ULL << (SPECTREParser::NUMBER - 191))
        | (1ULL << (SPECTREParser::ID - 191)))) != 0)) {
        setState(1277);
        node_list();
      }
      setState(1280);
      match(SPECTREParser::QPNOISE);
      setState(1288);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 235, _ctx)) {
      case 1: {
        setState(1284);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 234, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1281);
            match(SPECTREParser::NL); 
          }
          setState(1286);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 234, _ctx);
        }
        break;
      }

      case 2: {
        setState(1287);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QpspContext ------------------------------------------------------------------

SPECTREParser::QpspContext::QpspContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::QpspContext::QPSP() {
  return getToken(SPECTREParser::QPSP, 0);
}

tree::TerminalNode* SPECTREParser::QpspContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

tree::TerminalNode* SPECTREParser::QpspContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

SPECTREParser::Parameter_listContext* SPECTREParser::QpspContext::parameter_list() {
  return getRuleContext<SPECTREParser::Parameter_listContext>(0);
}

std::vector<tree::TerminalNode *> SPECTREParser::QpspContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::QpspContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::QpspContext::getRuleIndex() const {
  return SPECTREParser::RuleQpsp;
}

void SPECTREParser::QpspContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQpsp(this);
}

void SPECTREParser::QpspContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQpsp(this);
}


antlrcpp::Any SPECTREParser::QpspContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitQpsp(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::QpspContext* SPECTREParser::qpsp() {
  QpspContext *_localctx = _tracker.createInstance<QpspContext>(_ctx, getState());
  enterRule(_localctx, 96, SPECTREParser::RuleQpsp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(1321);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 244, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1293);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SPECTREParser::ID) {
        setState(1292);
        match(SPECTREParser::ID);
      }
      setState(1295);
      match(SPECTREParser::QPSP);
      setState(1297);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 238, _ctx)) {
      case 1: {
        setState(1296);
        parameter_list();
        break;
      }

      }
      setState(1306);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 240, _ctx)) {
      case 1: {
        setState(1302);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 239, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1299);
            match(SPECTREParser::NL); 
          }
          setState(1304);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 239, _ctx);
        }
        break;
      }

      case 2: {
        setState(1305);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1309);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SPECTREParser::ID) {
        setState(1308);
        match(SPECTREParser::ID);
      }
      setState(1311);
      match(SPECTREParser::QPSP);
      setState(1319);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 243, _ctx)) {
      case 1: {
        setState(1315);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 242, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1312);
            match(SPECTREParser::NL); 
          }
          setState(1317);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 242, _ctx);
        }
        break;
      }

      case 2: {
        setState(1318);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QpssContext ------------------------------------------------------------------

SPECTREParser::QpssContext::QpssContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::QpssContext::QPSS() {
  return getToken(SPECTREParser::QPSS, 0);
}

tree::TerminalNode* SPECTREParser::QpssContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

tree::TerminalNode* SPECTREParser::QpssContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

SPECTREParser::Node_listContext* SPECTREParser::QpssContext::node_list() {
  return getRuleContext<SPECTREParser::Node_listContext>(0);
}

SPECTREParser::Parameter_listContext* SPECTREParser::QpssContext::parameter_list() {
  return getRuleContext<SPECTREParser::Parameter_listContext>(0);
}

std::vector<tree::TerminalNode *> SPECTREParser::QpssContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::QpssContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::QpssContext::getRuleIndex() const {
  return SPECTREParser::RuleQpss;
}

void SPECTREParser::QpssContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQpss(this);
}

void SPECTREParser::QpssContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQpss(this);
}


antlrcpp::Any SPECTREParser::QpssContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitQpss(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::QpssContext* SPECTREParser::qpss() {
  QpssContext *_localctx = _tracker.createInstance<QpssContext>(_ctx, getState());
  enterRule(_localctx, 98, SPECTREParser::RuleQpss);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(1358);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 254, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1324);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 245, _ctx)) {
      case 1: {
        setState(1323);
        match(SPECTREParser::ID);
        break;
      }

      }
      setState(1327);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 191) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 191)) & ((1ULL << (SPECTREParser::OPEN_ROUND - 191))
        | (1ULL << (SPECTREParser::NUMBER - 191))
        | (1ULL << (SPECTREParser::ID - 191)))) != 0)) {
        setState(1326);
        node_list();
      }
      setState(1329);
      match(SPECTREParser::QPSS);
      setState(1331);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 247, _ctx)) {
      case 1: {
        setState(1330);
        parameter_list();
        break;
      }

      }
      setState(1340);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 249, _ctx)) {
      case 1: {
        setState(1336);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 248, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1333);
            match(SPECTREParser::NL); 
          }
          setState(1338);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 248, _ctx);
        }
        break;
      }

      case 2: {
        setState(1339);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1343);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 250, _ctx)) {
      case 1: {
        setState(1342);
        match(SPECTREParser::ID);
        break;
      }

      }
      setState(1346);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 191) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 191)) & ((1ULL << (SPECTREParser::OPEN_ROUND - 191))
        | (1ULL << (SPECTREParser::NUMBER - 191))
        | (1ULL << (SPECTREParser::ID - 191)))) != 0)) {
        setState(1345);
        node_list();
      }
      setState(1348);
      match(SPECTREParser::QPSS);
      setState(1356);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 253, _ctx)) {
      case 1: {
        setState(1352);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 252, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1349);
            match(SPECTREParser::NL); 
          }
          setState(1354);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 252, _ctx);
        }
        break;
      }

      case 2: {
        setState(1355);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QpxfContext ------------------------------------------------------------------

SPECTREParser::QpxfContext::QpxfContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::QpxfContext::QPXF() {
  return getToken(SPECTREParser::QPXF, 0);
}

tree::TerminalNode* SPECTREParser::QpxfContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

tree::TerminalNode* SPECTREParser::QpxfContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

SPECTREParser::Node_listContext* SPECTREParser::QpxfContext::node_list() {
  return getRuleContext<SPECTREParser::Node_listContext>(0);
}

SPECTREParser::Parameter_listContext* SPECTREParser::QpxfContext::parameter_list() {
  return getRuleContext<SPECTREParser::Parameter_listContext>(0);
}

std::vector<tree::TerminalNode *> SPECTREParser::QpxfContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::QpxfContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::QpxfContext::getRuleIndex() const {
  return SPECTREParser::RuleQpxf;
}

void SPECTREParser::QpxfContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQpxf(this);
}

void SPECTREParser::QpxfContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQpxf(this);
}


antlrcpp::Any SPECTREParser::QpxfContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitQpxf(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::QpxfContext* SPECTREParser::qpxf() {
  QpxfContext *_localctx = _tracker.createInstance<QpxfContext>(_ctx, getState());
  enterRule(_localctx, 100, SPECTREParser::RuleQpxf);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(1395);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 264, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1361);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 255, _ctx)) {
      case 1: {
        setState(1360);
        match(SPECTREParser::ID);
        break;
      }

      }
      setState(1364);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 191) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 191)) & ((1ULL << (SPECTREParser::OPEN_ROUND - 191))
        | (1ULL << (SPECTREParser::NUMBER - 191))
        | (1ULL << (SPECTREParser::ID - 191)))) != 0)) {
        setState(1363);
        node_list();
      }
      setState(1366);
      match(SPECTREParser::QPXF);
      setState(1368);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 257, _ctx)) {
      case 1: {
        setState(1367);
        parameter_list();
        break;
      }

      }
      setState(1377);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 259, _ctx)) {
      case 1: {
        setState(1373);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 258, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1370);
            match(SPECTREParser::NL); 
          }
          setState(1375);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 258, _ctx);
        }
        break;
      }

      case 2: {
        setState(1376);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1380);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 260, _ctx)) {
      case 1: {
        setState(1379);
        match(SPECTREParser::ID);
        break;
      }

      }
      setState(1383);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 191) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 191)) & ((1ULL << (SPECTREParser::OPEN_ROUND - 191))
        | (1ULL << (SPECTREParser::NUMBER - 191))
        | (1ULL << (SPECTREParser::ID - 191)))) != 0)) {
        setState(1382);
        node_list();
      }
      setState(1385);
      match(SPECTREParser::QPXF);
      setState(1393);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 263, _ctx)) {
      case 1: {
        setState(1389);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 262, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1386);
            match(SPECTREParser::NL); 
          }
          setState(1391);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 262, _ctx);
        }
        break;
      }

      case 2: {
        setState(1392);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SensContext ------------------------------------------------------------------

SPECTREParser::SensContext::SensContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::SensContext::SENS() {
  return getToken(SPECTREParser::SENS, 0);
}

tree::TerminalNode* SPECTREParser::SensContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

SPECTREParser::Sens_output_variables_listContext* SPECTREParser::SensContext::sens_output_variables_list() {
  return getRuleContext<SPECTREParser::Sens_output_variables_listContext>(0);
}

std::vector<tree::TerminalNode *> SPECTREParser::SensContext::ID() {
  return getTokens(SPECTREParser::ID);
}

tree::TerminalNode* SPECTREParser::SensContext::ID(size_t i) {
  return getToken(SPECTREParser::ID, i);
}

std::vector<SPECTREParser::Sens_design_parameters_listContext *> SPECTREParser::SensContext::sens_design_parameters_list() {
  return getRuleContexts<SPECTREParser::Sens_design_parameters_listContext>();
}

SPECTREParser::Sens_design_parameters_listContext* SPECTREParser::SensContext::sens_design_parameters_list(size_t i) {
  return getRuleContext<SPECTREParser::Sens_design_parameters_listContext>(i);
}

std::vector<tree::TerminalNode *> SPECTREParser::SensContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::SensContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::SensContext::getRuleIndex() const {
  return SPECTREParser::RuleSens;
}

void SPECTREParser::SensContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSens(this);
}

void SPECTREParser::SensContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSens(this);
}


antlrcpp::Any SPECTREParser::SensContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitSens(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::SensContext* SPECTREParser::sens() {
  SensContext *_localctx = _tracker.createInstance<SensContext>(_ctx, getState());
  enterRule(_localctx, 102, SPECTREParser::RuleSens);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1397);
    match(SPECTREParser::SENS);
    setState(1399);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 265, _ctx)) {
    case 1: {
      setState(1398);
      sens_output_variables_list();
      break;
    }

    }
    setState(1403);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 266, _ctx)) {
    case 1: {
      setState(1401);
      match(SPECTREParser::ID);
      setState(1402);
      sens_design_parameters_list();
      break;
    }

    }
    setState(1407);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 267, _ctx)) {
    case 1: {
      setState(1405);
      match(SPECTREParser::ID);
      setState(1406);
      sens_design_parameters_list();
      break;
    }

    }
    setState(1416);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 269, _ctx)) {
    case 1: {
      setState(1412);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 268, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(1409);
          match(SPECTREParser::NL); 
        }
        setState(1414);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 268, _ctx);
      }
      break;
    }

    case 2: {
      setState(1415);
      match(SPECTREParser::EOF);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sens_output_variables_listContext ------------------------------------------------------------------

SPECTREParser::Sens_output_variables_listContext::Sens_output_variables_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Sens_output_variables_listContext::OPEN_ROUND() {
  return getToken(SPECTREParser::OPEN_ROUND, 0);
}

tree::TerminalNode* SPECTREParser::Sens_output_variables_listContext::CLOSE_ROUND() {
  return getToken(SPECTREParser::CLOSE_ROUND, 0);
}

std::vector<SPECTREParser::Node_listContext *> SPECTREParser::Sens_output_variables_listContext::node_list() {
  return getRuleContexts<SPECTREParser::Node_listContext>();
}

SPECTREParser::Node_listContext* SPECTREParser::Sens_output_variables_listContext::node_list(size_t i) {
  return getRuleContext<SPECTREParser::Node_listContext>(i);
}


size_t SPECTREParser::Sens_output_variables_listContext::getRuleIndex() const {
  return SPECTREParser::RuleSens_output_variables_list;
}

void SPECTREParser::Sens_output_variables_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSens_output_variables_list(this);
}

void SPECTREParser::Sens_output_variables_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSens_output_variables_list(this);
}


antlrcpp::Any SPECTREParser::Sens_output_variables_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitSens_output_variables_list(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Sens_output_variables_listContext* SPECTREParser::sens_output_variables_list() {
  Sens_output_variables_listContext *_localctx = _tracker.createInstance<Sens_output_variables_listContext>(_ctx, getState());
  enterRule(_localctx, 104, SPECTREParser::RuleSens_output_variables_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1418);
    match(SPECTREParser::OPEN_ROUND);
    setState(1420); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(1419);
      node_list();
      setState(1422); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (((((_la - 191) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 191)) & ((1ULL << (SPECTREParser::OPEN_ROUND - 191))
      | (1ULL << (SPECTREParser::NUMBER - 191))
      | (1ULL << (SPECTREParser::ID - 191)))) != 0));
    setState(1424);
    match(SPECTREParser::CLOSE_ROUND);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sens_design_parameters_listContext ------------------------------------------------------------------

SPECTREParser::Sens_design_parameters_listContext::Sens_design_parameters_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Sens_design_parameters_listContext::OPEN_ROUND() {
  return getToken(SPECTREParser::OPEN_ROUND, 0);
}

tree::TerminalNode* SPECTREParser::Sens_design_parameters_listContext::CLOSE_ROUND() {
  return getToken(SPECTREParser::CLOSE_ROUND, 0);
}

std::vector<SPECTREParser::Node_listContext *> SPECTREParser::Sens_design_parameters_listContext::node_list() {
  return getRuleContexts<SPECTREParser::Node_listContext>();
}

SPECTREParser::Node_listContext* SPECTREParser::Sens_design_parameters_listContext::node_list(size_t i) {
  return getRuleContext<SPECTREParser::Node_listContext>(i);
}


size_t SPECTREParser::Sens_design_parameters_listContext::getRuleIndex() const {
  return SPECTREParser::RuleSens_design_parameters_list;
}

void SPECTREParser::Sens_design_parameters_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSens_design_parameters_list(this);
}

void SPECTREParser::Sens_design_parameters_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSens_design_parameters_list(this);
}


antlrcpp::Any SPECTREParser::Sens_design_parameters_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitSens_design_parameters_list(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Sens_design_parameters_listContext* SPECTREParser::sens_design_parameters_list() {
  Sens_design_parameters_listContext *_localctx = _tracker.createInstance<Sens_design_parameters_listContext>(_ctx, getState());
  enterRule(_localctx, 106, SPECTREParser::RuleSens_design_parameters_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1426);
    match(SPECTREParser::OPEN_ROUND);
    setState(1428); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(1427);
      node_list();
      setState(1430); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (((((_la - 191) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 191)) & ((1ULL << (SPECTREParser::OPEN_ROUND - 191))
      | (1ULL << (SPECTREParser::NUMBER - 191))
      | (1ULL << (SPECTREParser::ID - 191)))) != 0));
    setState(1432);
    match(SPECTREParser::CLOSE_ROUND);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sens_analyses_listContext ------------------------------------------------------------------

SPECTREParser::Sens_analyses_listContext::Sens_analyses_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Sens_analyses_listContext::OPEN_ROUND() {
  return getToken(SPECTREParser::OPEN_ROUND, 0);
}

tree::TerminalNode* SPECTREParser::Sens_analyses_listContext::CLOSE_ROUND() {
  return getToken(SPECTREParser::CLOSE_ROUND, 0);
}

std::vector<SPECTREParser::Node_listContext *> SPECTREParser::Sens_analyses_listContext::node_list() {
  return getRuleContexts<SPECTREParser::Node_listContext>();
}

SPECTREParser::Node_listContext* SPECTREParser::Sens_analyses_listContext::node_list(size_t i) {
  return getRuleContext<SPECTREParser::Node_listContext>(i);
}


size_t SPECTREParser::Sens_analyses_listContext::getRuleIndex() const {
  return SPECTREParser::RuleSens_analyses_list;
}

void SPECTREParser::Sens_analyses_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSens_analyses_list(this);
}

void SPECTREParser::Sens_analyses_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSens_analyses_list(this);
}


antlrcpp::Any SPECTREParser::Sens_analyses_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitSens_analyses_list(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Sens_analyses_listContext* SPECTREParser::sens_analyses_list() {
  Sens_analyses_listContext *_localctx = _tracker.createInstance<Sens_analyses_listContext>(_ctx, getState());
  enterRule(_localctx, 108, SPECTREParser::RuleSens_analyses_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1434);
    match(SPECTREParser::OPEN_ROUND);
    setState(1436); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(1435);
      node_list();
      setState(1438); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (((((_la - 191) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 191)) & ((1ULL << (SPECTREParser::OPEN_ROUND - 191))
      | (1ULL << (SPECTREParser::NUMBER - 191))
      | (1ULL << (SPECTREParser::ID - 191)))) != 0));
    setState(1440);
    match(SPECTREParser::CLOSE_ROUND);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MontecarloContext ------------------------------------------------------------------

SPECTREParser::MontecarloContext::MontecarloContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SPECTREParser::Montecarlo_headerContext* SPECTREParser::MontecarloContext::montecarlo_header() {
  return getRuleContext<SPECTREParser::Montecarlo_headerContext>(0);
}

SPECTREParser::Montecarlo_exportContext* SPECTREParser::MontecarloContext::montecarlo_export() {
  return getRuleContext<SPECTREParser::Montecarlo_exportContext>(0);
}

SPECTREParser::Montecarlo_footerContext* SPECTREParser::MontecarloContext::montecarlo_footer() {
  return getRuleContext<SPECTREParser::Montecarlo_footerContext>(0);
}

std::vector<SPECTREParser::Montecarlo_contentContext *> SPECTREParser::MontecarloContext::montecarlo_content() {
  return getRuleContexts<SPECTREParser::Montecarlo_contentContext>();
}

SPECTREParser::Montecarlo_contentContext* SPECTREParser::MontecarloContext::montecarlo_content(size_t i) {
  return getRuleContext<SPECTREParser::Montecarlo_contentContext>(i);
}


size_t SPECTREParser::MontecarloContext::getRuleIndex() const {
  return SPECTREParser::RuleMontecarlo;
}

void SPECTREParser::MontecarloContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMontecarlo(this);
}

void SPECTREParser::MontecarloContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMontecarlo(this);
}


antlrcpp::Any SPECTREParser::MontecarloContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitMontecarlo(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::MontecarloContext* SPECTREParser::montecarlo() {
  MontecarloContext *_localctx = _tracker.createInstance<MontecarloContext>(_ctx, getState());
  enterRule(_localctx, 110, SPECTREParser::RuleMontecarlo);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1442);
    montecarlo_header();
    setState(1444); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(1443);
      montecarlo_content();
      setState(1446); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SPECTREParser::GLOBAL)
      | (1ULL << SPECTREParser::INCLUDE)
      | (1ULL << SPECTREParser::CPP_INCLUDE)
      | (1ULL << SPECTREParser::AHDL_INCLUDE)
      | (1ULL << SPECTREParser::LIBRARY)
      | (1ULL << SPECTREParser::SECTION)
      | (1ULL << SPECTREParser::SUBCKT)
      | (1ULL << SPECTREParser::INLINE_SUBCKT)
      | (1ULL << SPECTREParser::MODEL)
      | (1ULL << SPECTREParser::SAVE)
      | (1ULL << SPECTREParser::NODESET)
      | (1ULL << SPECTREParser::IC)
      | (1ULL << SPECTREParser::PARAMETERS)
      | (1ULL << SPECTREParser::STATISTICS)
      | (1ULL << SPECTREParser::AC)
      | (1ULL << SPECTREParser::ACMATCH)
      | (1ULL << SPECTREParser::DC)
      | (1ULL << SPECTREParser::DCMATCH)
      | (1ULL << SPECTREParser::ENVLP)
      | (1ULL << SPECTREParser::SP)
      | (1ULL << SPECTREParser::STB)
      | (1ULL << SPECTREParser::SWEEP)
      | (1ULL << SPECTREParser::TDR)
      | (1ULL << SPECTREParser::TRAN)
      | (1ULL << SPECTREParser::XF)
      | (1ULL << SPECTREParser::PAC)
      | (1ULL << SPECTREParser::PDISTO))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (SPECTREParser::PNOISE - 64))
      | (1ULL << (SPECTREParser::PSP - 64))
      | (1ULL << (SPECTREParser::PSS - 64))
      | (1ULL << (SPECTREParser::PXF - 64))
      | (1ULL << (SPECTREParser::PZ - 64))
      | (1ULL << (SPECTREParser::QPAC - 64))
      | (1ULL << (SPECTREParser::QPNOISE - 64))
      | (1ULL << (SPECTREParser::QPSP - 64))
      | (1ULL << (SPECTREParser::QPSS - 64))
      | (1ULL << (SPECTREParser::QPXF - 64))
      | (1ULL << (SPECTREParser::SENS - 64)))) != 0) || ((((_la - 191) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 191)) & ((1ULL << (SPECTREParser::OPEN_ROUND - 191))
      | (1ULL << (SPECTREParser::NUMBER - 191))
      | (1ULL << (SPECTREParser::ID - 191)))) != 0));
    setState(1448);
    montecarlo_export();
    setState(1449);
    montecarlo_footer();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Montecarlo_headerContext ------------------------------------------------------------------

SPECTREParser::Montecarlo_headerContext::Montecarlo_headerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Montecarlo_headerContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

tree::TerminalNode* SPECTREParser::Montecarlo_headerContext::MONTECARLO() {
  return getToken(SPECTREParser::MONTECARLO, 0);
}

tree::TerminalNode* SPECTREParser::Montecarlo_headerContext::OPEN_CURLY() {
  return getToken(SPECTREParser::OPEN_CURLY, 0);
}

tree::TerminalNode* SPECTREParser::Montecarlo_headerContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

std::vector<tree::TerminalNode *> SPECTREParser::Montecarlo_headerContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::Montecarlo_headerContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}

std::vector<SPECTREParser::Parameter_listContext *> SPECTREParser::Montecarlo_headerContext::parameter_list() {
  return getRuleContexts<SPECTREParser::Parameter_listContext>();
}

SPECTREParser::Parameter_listContext* SPECTREParser::Montecarlo_headerContext::parameter_list(size_t i) {
  return getRuleContext<SPECTREParser::Parameter_listContext>(i);
}


size_t SPECTREParser::Montecarlo_headerContext::getRuleIndex() const {
  return SPECTREParser::RuleMontecarlo_header;
}

void SPECTREParser::Montecarlo_headerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMontecarlo_header(this);
}

void SPECTREParser::Montecarlo_headerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMontecarlo_header(this);
}


antlrcpp::Any SPECTREParser::Montecarlo_headerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitMontecarlo_header(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Montecarlo_headerContext* SPECTREParser::montecarlo_header() {
  Montecarlo_headerContext *_localctx = _tracker.createInstance<Montecarlo_headerContext>(_ctx, getState());
  enterRule(_localctx, 112, SPECTREParser::RuleMontecarlo_header);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1451);
    match(SPECTREParser::ID);
    setState(1452);
    match(SPECTREParser::MONTECARLO);
    setState(1456);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SPECTREParser::NL) {
      setState(1453);
      match(SPECTREParser::NL);
      setState(1458);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1462);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SPECTREParser::SECTION)
      | (1ULL << SPECTREParser::SAVE)
      | (1ULL << SPECTREParser::PORTS)
      | (1ULL << SPECTREParser::DC))) != 0) || _la == SPECTREParser::DELAY || _la == SPECTREParser::ID) {
      setState(1459);
      parameter_list();
      setState(1464);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1465);
    match(SPECTREParser::OPEN_CURLY);
    setState(1473);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SPECTREParser::GLOBAL:
      case SPECTREParser::INCLUDE:
      case SPECTREParser::CPP_INCLUDE:
      case SPECTREParser::AHDL_INCLUDE:
      case SPECTREParser::LIBRARY:
      case SPECTREParser::SECTION:
      case SPECTREParser::SUBCKT:
      case SPECTREParser::INLINE_SUBCKT:
      case SPECTREParser::MODEL:
      case SPECTREParser::SAVE:
      case SPECTREParser::NODESET:
      case SPECTREParser::IC:
      case SPECTREParser::PARAMETERS:
      case SPECTREParser::STATISTICS:
      case SPECTREParser::AC:
      case SPECTREParser::ACMATCH:
      case SPECTREParser::DC:
      case SPECTREParser::DCMATCH:
      case SPECTREParser::ENVLP:
      case SPECTREParser::SP:
      case SPECTREParser::STB:
      case SPECTREParser::SWEEP:
      case SPECTREParser::TDR:
      case SPECTREParser::TRAN:
      case SPECTREParser::XF:
      case SPECTREParser::PAC:
      case SPECTREParser::PDISTO:
      case SPECTREParser::PNOISE:
      case SPECTREParser::PSP:
      case SPECTREParser::PSS:
      case SPECTREParser::PXF:
      case SPECTREParser::PZ:
      case SPECTREParser::QPAC:
      case SPECTREParser::QPNOISE:
      case SPECTREParser::QPSP:
      case SPECTREParser::QPSS:
      case SPECTREParser::QPXF:
      case SPECTREParser::SENS:
      case SPECTREParser::OPEN_ROUND:
      case SPECTREParser::NUMBER:
      case SPECTREParser::ID:
      case SPECTREParser::NL: {
        setState(1469);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SPECTREParser::NL) {
          setState(1466);
          match(SPECTREParser::NL);
          setState(1471);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case SPECTREParser::EOF: {
        setState(1472);
        match(SPECTREParser::EOF);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Montecarlo_contentContext ------------------------------------------------------------------

SPECTREParser::Montecarlo_contentContext::Montecarlo_contentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SPECTREParser::Netlist_entityContext* SPECTREParser::Montecarlo_contentContext::netlist_entity() {
  return getRuleContext<SPECTREParser::Netlist_entityContext>(0);
}


size_t SPECTREParser::Montecarlo_contentContext::getRuleIndex() const {
  return SPECTREParser::RuleMontecarlo_content;
}

void SPECTREParser::Montecarlo_contentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMontecarlo_content(this);
}

void SPECTREParser::Montecarlo_contentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMontecarlo_content(this);
}


antlrcpp::Any SPECTREParser::Montecarlo_contentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitMontecarlo_content(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Montecarlo_contentContext* SPECTREParser::montecarlo_content() {
  Montecarlo_contentContext *_localctx = _tracker.createInstance<Montecarlo_contentContext>(_ctx, getState());
  enterRule(_localctx, 114, SPECTREParser::RuleMontecarlo_content);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1475);
    netlist_entity();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Montecarlo_exportContext ------------------------------------------------------------------

SPECTREParser::Montecarlo_exportContext::Montecarlo_exportContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Montecarlo_exportContext::EXPORT() {
  return getToken(SPECTREParser::EXPORT, 0);
}

SPECTREParser::Parameter_listContext* SPECTREParser::Montecarlo_exportContext::parameter_list() {
  return getRuleContext<SPECTREParser::Parameter_listContext>(0);
}

tree::TerminalNode* SPECTREParser::Montecarlo_exportContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

std::vector<tree::TerminalNode *> SPECTREParser::Montecarlo_exportContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::Montecarlo_exportContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::Montecarlo_exportContext::getRuleIndex() const {
  return SPECTREParser::RuleMontecarlo_export;
}

void SPECTREParser::Montecarlo_exportContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMontecarlo_export(this);
}

void SPECTREParser::Montecarlo_exportContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMontecarlo_export(this);
}


antlrcpp::Any SPECTREParser::Montecarlo_exportContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitMontecarlo_export(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Montecarlo_exportContext* SPECTREParser::montecarlo_export() {
  Montecarlo_exportContext *_localctx = _tracker.createInstance<Montecarlo_exportContext>(_ctx, getState());
  enterRule(_localctx, 116, SPECTREParser::RuleMontecarlo_export);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1477);
    match(SPECTREParser::EXPORT);
    setState(1478);
    parameter_list();
    setState(1486);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SPECTREParser::CLOSE_CURLY:
      case SPECTREParser::NL: {
        setState(1482);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SPECTREParser::NL) {
          setState(1479);
          match(SPECTREParser::NL);
          setState(1484);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case SPECTREParser::EOF: {
        setState(1485);
        match(SPECTREParser::EOF);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Montecarlo_footerContext ------------------------------------------------------------------

SPECTREParser::Montecarlo_footerContext::Montecarlo_footerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Montecarlo_footerContext::CLOSE_CURLY() {
  return getToken(SPECTREParser::CLOSE_CURLY, 0);
}

tree::TerminalNode* SPECTREParser::Montecarlo_footerContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

std::vector<tree::TerminalNode *> SPECTREParser::Montecarlo_footerContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::Montecarlo_footerContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::Montecarlo_footerContext::getRuleIndex() const {
  return SPECTREParser::RuleMontecarlo_footer;
}

void SPECTREParser::Montecarlo_footerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMontecarlo_footer(this);
}

void SPECTREParser::Montecarlo_footerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMontecarlo_footer(this);
}


antlrcpp::Any SPECTREParser::Montecarlo_footerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitMontecarlo_footer(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Montecarlo_footerContext* SPECTREParser::montecarlo_footer() {
  Montecarlo_footerContext *_localctx = _tracker.createInstance<Montecarlo_footerContext>(_ctx, getState());
  enterRule(_localctx, 118, SPECTREParser::RuleMontecarlo_footer);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1488);
    match(SPECTREParser::CLOSE_CURLY);
    setState(1496);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 281, _ctx)) {
    case 1: {
      setState(1492);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 280, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(1489);
          match(SPECTREParser::NL); 
        }
        setState(1494);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 280, _ctx);
      }
      break;
    }

    case 2: {
      setState(1495);
      match(SPECTREParser::EOF);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NoiseContext ------------------------------------------------------------------

SPECTREParser::NoiseContext::NoiseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::NoiseContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

tree::TerminalNode* SPECTREParser::NoiseContext::NOISE() {
  return getToken(SPECTREParser::NOISE, 0);
}

tree::TerminalNode* SPECTREParser::NoiseContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

SPECTREParser::Node_listContext* SPECTREParser::NoiseContext::node_list() {
  return getRuleContext<SPECTREParser::Node_listContext>(0);
}

SPECTREParser::Parameter_listContext* SPECTREParser::NoiseContext::parameter_list() {
  return getRuleContext<SPECTREParser::Parameter_listContext>(0);
}

std::vector<tree::TerminalNode *> SPECTREParser::NoiseContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::NoiseContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::NoiseContext::getRuleIndex() const {
  return SPECTREParser::RuleNoise;
}

void SPECTREParser::NoiseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNoise(this);
}

void SPECTREParser::NoiseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNoise(this);
}


antlrcpp::Any SPECTREParser::NoiseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitNoise(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::NoiseContext* SPECTREParser::noise() {
  NoiseContext *_localctx = _tracker.createInstance<NoiseContext>(_ctx, getState());
  enterRule(_localctx, 120, SPECTREParser::RuleNoise);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(1529);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 289, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1498);
      match(SPECTREParser::ID);
      setState(1500);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 191) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 191)) & ((1ULL << (SPECTREParser::OPEN_ROUND - 191))
        | (1ULL << (SPECTREParser::NUMBER - 191))
        | (1ULL << (SPECTREParser::ID - 191)))) != 0)) {
        setState(1499);
        node_list();
      }
      setState(1502);
      match(SPECTREParser::NOISE);
      setState(1504);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 283, _ctx)) {
      case 1: {
        setState(1503);
        parameter_list();
        break;
      }

      }
      setState(1513);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 285, _ctx)) {
      case 1: {
        setState(1509);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 284, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1506);
            match(SPECTREParser::NL); 
          }
          setState(1511);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 284, _ctx);
        }
        break;
      }

      case 2: {
        setState(1512);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1515);
      match(SPECTREParser::ID);
      setState(1517);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 191) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 191)) & ((1ULL << (SPECTREParser::OPEN_ROUND - 191))
        | (1ULL << (SPECTREParser::NUMBER - 191))
        | (1ULL << (SPECTREParser::ID - 191)))) != 0)) {
        setState(1516);
        node_list();
      }
      setState(1519);
      match(SPECTREParser::NOISE);
      setState(1527);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 288, _ctx)) {
      case 1: {
        setState(1523);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 287, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1520);
            match(SPECTREParser::NL); 
          }
          setState(1525);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 287, _ctx);
        }
        break;
      }

      case 2: {
        setState(1526);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ChecklimitContext ------------------------------------------------------------------

SPECTREParser::ChecklimitContext::ChecklimitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::ChecklimitContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

tree::TerminalNode* SPECTREParser::ChecklimitContext::CHECKLIMIT() {
  return getToken(SPECTREParser::CHECKLIMIT, 0);
}

tree::TerminalNode* SPECTREParser::ChecklimitContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

SPECTREParser::Parameter_listContext* SPECTREParser::ChecklimitContext::parameter_list() {
  return getRuleContext<SPECTREParser::Parameter_listContext>(0);
}

std::vector<tree::TerminalNode *> SPECTREParser::ChecklimitContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::ChecklimitContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::ChecklimitContext::getRuleIndex() const {
  return SPECTREParser::RuleChecklimit;
}

void SPECTREParser::ChecklimitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterChecklimit(this);
}

void SPECTREParser::ChecklimitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitChecklimit(this);
}


antlrcpp::Any SPECTREParser::ChecklimitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitChecklimit(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::ChecklimitContext* SPECTREParser::checklimit() {
  ChecklimitContext *_localctx = _tracker.createInstance<ChecklimitContext>(_ctx, getState());
  enterRule(_localctx, 122, SPECTREParser::RuleChecklimit);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(1556);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 295, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1531);
      match(SPECTREParser::ID);
      setState(1532);
      match(SPECTREParser::CHECKLIMIT);
      setState(1534);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 290, _ctx)) {
      case 1: {
        setState(1533);
        parameter_list();
        break;
      }

      }
      setState(1543);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 292, _ctx)) {
      case 1: {
        setState(1539);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 291, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1536);
            match(SPECTREParser::NL); 
          }
          setState(1541);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 291, _ctx);
        }
        break;
      }

      case 2: {
        setState(1542);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1545);
      match(SPECTREParser::ID);
      setState(1546);
      match(SPECTREParser::CHECKLIMIT);
      setState(1554);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 294, _ctx)) {
      case 1: {
        setState(1550);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 293, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1547);
            match(SPECTREParser::NL); 
          }
          setState(1552);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 293, _ctx);
        }
        break;
      }

      case 2: {
        setState(1553);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GlobalContext ------------------------------------------------------------------

SPECTREParser::GlobalContext::GlobalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::GlobalContext::GLOBAL() {
  return getToken(SPECTREParser::GLOBAL, 0);
}

SPECTREParser::Node_listContext* SPECTREParser::GlobalContext::node_list() {
  return getRuleContext<SPECTREParser::Node_listContext>(0);
}

tree::TerminalNode* SPECTREParser::GlobalContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

std::vector<tree::TerminalNode *> SPECTREParser::GlobalContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::GlobalContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::GlobalContext::getRuleIndex() const {
  return SPECTREParser::RuleGlobal;
}

void SPECTREParser::GlobalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGlobal(this);
}

void SPECTREParser::GlobalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGlobal(this);
}


antlrcpp::Any SPECTREParser::GlobalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitGlobal(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::GlobalContext* SPECTREParser::global() {
  GlobalContext *_localctx = _tracker.createInstance<GlobalContext>(_ctx, getState());
  enterRule(_localctx, 124, SPECTREParser::RuleGlobal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1558);
    match(SPECTREParser::GLOBAL);
    setState(1559);
    node_list();
    setState(1567);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 297, _ctx)) {
    case 1: {
      setState(1563);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 296, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(1560);
          match(SPECTREParser::NL); 
        }
        setState(1565);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 296, _ctx);
      }
      break;
    }

    case 2: {
      setState(1566);
      match(SPECTREParser::EOF);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ModelContext ------------------------------------------------------------------

SPECTREParser::ModelContext::ModelContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::ModelContext::MODEL() {
  return getToken(SPECTREParser::MODEL, 0);
}

SPECTREParser::Model_nameContext* SPECTREParser::ModelContext::model_name() {
  return getRuleContext<SPECTREParser::Model_nameContext>(0);
}

SPECTREParser::Model_masterContext* SPECTREParser::ModelContext::model_master() {
  return getRuleContext<SPECTREParser::Model_masterContext>(0);
}

tree::TerminalNode* SPECTREParser::ModelContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

std::vector<SPECTREParser::Parameter_assignContext *> SPECTREParser::ModelContext::parameter_assign() {
  return getRuleContexts<SPECTREParser::Parameter_assignContext>();
}

SPECTREParser::Parameter_assignContext* SPECTREParser::ModelContext::parameter_assign(size_t i) {
  return getRuleContext<SPECTREParser::Parameter_assignContext>(i);
}

std::vector<tree::TerminalNode *> SPECTREParser::ModelContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::ModelContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::ModelContext::getRuleIndex() const {
  return SPECTREParser::RuleModel;
}

void SPECTREParser::ModelContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterModel(this);
}

void SPECTREParser::ModelContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitModel(this);
}


antlrcpp::Any SPECTREParser::ModelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitModel(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::ModelContext* SPECTREParser::model() {
  ModelContext *_localctx = _tracker.createInstance<ModelContext>(_ctx, getState());
  enterRule(_localctx, 126, SPECTREParser::RuleModel);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1569);
    match(SPECTREParser::MODEL);
    setState(1570);
    model_name();
    setState(1571);
    model_master();
    setState(1575);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 298, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(1572);
        parameter_assign(); 
      }
      setState(1577);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 298, _ctx);
    }
    setState(1585);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 300, _ctx)) {
    case 1: {
      setState(1581);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 299, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(1578);
          match(SPECTREParser::NL); 
        }
        setState(1583);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 299, _ctx);
      }
      break;
    }

    case 2: {
      setState(1584);
      match(SPECTREParser::EOF);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Model_nameContext ------------------------------------------------------------------

SPECTREParser::Model_nameContext::Model_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Model_nameContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}


size_t SPECTREParser::Model_nameContext::getRuleIndex() const {
  return SPECTREParser::RuleModel_name;
}

void SPECTREParser::Model_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterModel_name(this);
}

void SPECTREParser::Model_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitModel_name(this);
}


antlrcpp::Any SPECTREParser::Model_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitModel_name(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Model_nameContext* SPECTREParser::model_name() {
  Model_nameContext *_localctx = _tracker.createInstance<Model_nameContext>(_ctx, getState());
  enterRule(_localctx, 128, SPECTREParser::RuleModel_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1587);
    match(SPECTREParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Model_masterContext ------------------------------------------------------------------

SPECTREParser::Model_masterContext::Model_masterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Model_masterContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

SPECTREParser::Component_typeContext* SPECTREParser::Model_masterContext::component_type() {
  return getRuleContext<SPECTREParser::Component_typeContext>(0);
}


size_t SPECTREParser::Model_masterContext::getRuleIndex() const {
  return SPECTREParser::RuleModel_master;
}

void SPECTREParser::Model_masterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterModel_master(this);
}

void SPECTREParser::Model_masterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitModel_master(this);
}


antlrcpp::Any SPECTREParser::Model_masterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitModel_master(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Model_masterContext* SPECTREParser::model_master() {
  Model_masterContext *_localctx = _tracker.createInstance<Model_masterContext>(_ctx, getState());
  enterRule(_localctx, 130, SPECTREParser::RuleModel_master);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1591);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SPECTREParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(1589);
        match(SPECTREParser::ID);
        break;
      }

      case SPECTREParser::A2D:
      case SPECTREParser::B3SOIPD:
      case SPECTREParser::BJT:
      case SPECTREParser::BJT301:
      case SPECTREParser::BJT500:
      case SPECTREParser::BJT503:
      case SPECTREParser::BJT504:
      case SPECTREParser::BJT504T:
      case SPECTREParser::BSIM1:
      case SPECTREParser::BSIM2:
      case SPECTREParser::BSIM3:
      case SPECTREParser::BSIM3V3:
      case SPECTREParser::BSIM4:
      case SPECTREParser::BSIMSOI:
      case SPECTREParser::BTASOI:
      case SPECTREParser::CAPACITOR:
      case SPECTREParser::CCCS:
      case SPECTREParser::CCVS:
      case SPECTREParser::CKTROM:
      case SPECTREParser::CORE:
      case SPECTREParser::D2A:
      case SPECTREParser::DELAY:
      case SPECTREParser::DIO500:
      case SPECTREParser::DIODE:
      case SPECTREParser::EKV:
      case SPECTREParser::FOURIER:
      case SPECTREParser::GAAS:
      case SPECTREParser::HBT:
      case SPECTREParser::HISIM:
      case SPECTREParser::HVMOS:
      case SPECTREParser::INDUCTOR:
      case SPECTREParser::INTCAP:
      case SPECTREParser::IPROBE:
      case SPECTREParser::ISOURCE:
      case SPECTREParser::JFET:
      case SPECTREParser::JUNCAP:
      case SPECTREParser::MISNAN:
      case SPECTREParser::MOS11011:
      case SPECTREParser::MOS11010:
      case SPECTREParser::MOS3002:
      case SPECTREParser::MOS3100:
      case SPECTREParser::MOS1000:
      case SPECTREParser::MOS1100:
      case SPECTREParser::MUTUAL_INDUCTOR:
      case SPECTREParser::MSLINE:
      case SPECTREParser::MTLINE:
      case SPECTREParser::MOS705:
      case SPECTREParser::MOS902:
      case SPECTREParser::MOS903:
      case SPECTREParser::MOS30:
      case SPECTREParser::MOS40:
      case SPECTREParser::MOS15:
      case SPECTREParser::MOS0:
      case SPECTREParser::MOS1:
      case SPECTREParser::MOS2:
      case SPECTREParser::MOS3:
      case SPECTREParser::NODCAP:
      case SPECTREParser::NODE:
      case SPECTREParser::NPORT:
      case SPECTREParser::PARAMTEST:
      case SPECTREParser::PCCCS:
      case SPECTREParser::PCCVS:
      case SPECTREParser::PHY_RES:
      case SPECTREParser::PORT:
      case SPECTREParser::PSITFT:
      case SPECTREParser::PVCCS:
      case SPECTREParser::PVCVS:
      case SPECTREParser::QUANTITY:
      case SPECTREParser::RDIFF:
      case SPECTREParser::RELAY:
      case SPECTREParser::RESISTOR:
      case SPECTREParser::SCCCS:
      case SPECTREParser::SCCVS:
      case SPECTREParser::SVCCS:
      case SPECTREParser::SVCVS:
      case SPECTREParser::SWITCH:
      case SPECTREParser::TLINE:
      case SPECTREParser::TOM2:
      case SPECTREParser::TOM3:
      case SPECTREParser::TRANSFORMER:
      case SPECTREParser::VBIC:
      case SPECTREParser::VCCS:
      case SPECTREParser::VCVS:
      case SPECTREParser::VSOURCE:
      case SPECTREParser::WINDING:
      case SPECTREParser::ZCCCS:
      case SPECTREParser::ZCCVS:
      case SPECTREParser::ZVCCS:
      case SPECTREParser::ZVCVS:
      case SPECTREParser::BSOURCE: {
        enterOuterAlt(_localctx, 2);
        setState(1590);
        component_type();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ControlContext ------------------------------------------------------------------

SPECTREParser::ControlContext::ControlContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SPECTREParser::AlterContext* SPECTREParser::ControlContext::alter() {
  return getRuleContext<SPECTREParser::AlterContext>(0);
}

SPECTREParser::AltergroupContext* SPECTREParser::ControlContext::altergroup() {
  return getRuleContext<SPECTREParser::AltergroupContext>(0);
}

SPECTREParser::Assert_statementContext* SPECTREParser::ControlContext::assert_statement() {
  return getRuleContext<SPECTREParser::Assert_statementContext>(0);
}

SPECTREParser::Check_statementContext* SPECTREParser::ControlContext::check_statement() {
  return getRuleContext<SPECTREParser::Check_statementContext>(0);
}

SPECTREParser::SaveContext* SPECTREParser::ControlContext::save() {
  return getRuleContext<SPECTREParser::SaveContext>(0);
}

SPECTREParser::OptionContext* SPECTREParser::ControlContext::option() {
  return getRuleContext<SPECTREParser::OptionContext>(0);
}

SPECTREParser::SetContext* SPECTREParser::ControlContext::set() {
  return getRuleContext<SPECTREParser::SetContext>(0);
}

SPECTREParser::ShellContext* SPECTREParser::ControlContext::shell() {
  return getRuleContext<SPECTREParser::ShellContext>(0);
}

SPECTREParser::InfoContext* SPECTREParser::ControlContext::info() {
  return getRuleContext<SPECTREParser::InfoContext>(0);
}

SPECTREParser::NodesetContext* SPECTREParser::ControlContext::nodeset() {
  return getRuleContext<SPECTREParser::NodesetContext>(0);
}

SPECTREParser::IcContext* SPECTREParser::ControlContext::ic() {
  return getRuleContext<SPECTREParser::IcContext>(0);
}


size_t SPECTREParser::ControlContext::getRuleIndex() const {
  return SPECTREParser::RuleControl;
}

void SPECTREParser::ControlContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterControl(this);
}

void SPECTREParser::ControlContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitControl(this);
}


antlrcpp::Any SPECTREParser::ControlContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitControl(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::ControlContext* SPECTREParser::control() {
  ControlContext *_localctx = _tracker.createInstance<ControlContext>(_ctx, getState());
  enterRule(_localctx, 132, SPECTREParser::RuleControl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1604);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 302, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1593);
      alter();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1594);
      altergroup();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1595);
      assert_statement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1596);
      check_statement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(1597);
      save();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(1598);
      option();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(1599);
      set();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(1600);
      shell();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(1601);
      info();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(1602);
      nodeset();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(1603);
      ic();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AlterContext ------------------------------------------------------------------

SPECTREParser::AlterContext::AlterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::AlterContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

tree::TerminalNode* SPECTREParser::AlterContext::ALTER() {
  return getToken(SPECTREParser::ALTER, 0);
}

SPECTREParser::Parameter_listContext* SPECTREParser::AlterContext::parameter_list() {
  return getRuleContext<SPECTREParser::Parameter_listContext>(0);
}

tree::TerminalNode* SPECTREParser::AlterContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

std::vector<tree::TerminalNode *> SPECTREParser::AlterContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::AlterContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::AlterContext::getRuleIndex() const {
  return SPECTREParser::RuleAlter;
}

void SPECTREParser::AlterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAlter(this);
}

void SPECTREParser::AlterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAlter(this);
}


antlrcpp::Any SPECTREParser::AlterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitAlter(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::AlterContext* SPECTREParser::alter() {
  AlterContext *_localctx = _tracker.createInstance<AlterContext>(_ctx, getState());
  enterRule(_localctx, 134, SPECTREParser::RuleAlter);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(1629);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 307, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1606);
      match(SPECTREParser::ID);
      setState(1607);
      match(SPECTREParser::ALTER);
      setState(1608);
      parameter_list();
      setState(1616);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 304, _ctx)) {
      case 1: {
        setState(1612);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 303, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1609);
            match(SPECTREParser::NL); 
          }
          setState(1614);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 303, _ctx);
        }
        break;
      }

      case 2: {
        setState(1615);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1618);
      match(SPECTREParser::ID);
      setState(1619);
      match(SPECTREParser::ALTER);
      setState(1627);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 306, _ctx)) {
      case 1: {
        setState(1623);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 305, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1620);
            match(SPECTREParser::NL); 
          }
          setState(1625);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 305, _ctx);
        }
        break;
      }

      case 2: {
        setState(1626);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AltergroupContext ------------------------------------------------------------------

SPECTREParser::AltergroupContext::AltergroupContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SPECTREParser::Altergroup_headerContext* SPECTREParser::AltergroupContext::altergroup_header() {
  return getRuleContext<SPECTREParser::Altergroup_headerContext>(0);
}

SPECTREParser::Global_declarationsContext* SPECTREParser::AltergroupContext::global_declarations() {
  return getRuleContext<SPECTREParser::Global_declarationsContext>(0);
}

SPECTREParser::Altergroup_footerContext* SPECTREParser::AltergroupContext::altergroup_footer() {
  return getRuleContext<SPECTREParser::Altergroup_footerContext>(0);
}

std::vector<SPECTREParser::Altergroup_contentContext *> SPECTREParser::AltergroupContext::altergroup_content() {
  return getRuleContexts<SPECTREParser::Altergroup_contentContext>();
}

SPECTREParser::Altergroup_contentContext* SPECTREParser::AltergroupContext::altergroup_content(size_t i) {
  return getRuleContext<SPECTREParser::Altergroup_contentContext>(i);
}


size_t SPECTREParser::AltergroupContext::getRuleIndex() const {
  return SPECTREParser::RuleAltergroup;
}

void SPECTREParser::AltergroupContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAltergroup(this);
}

void SPECTREParser::AltergroupContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAltergroup(this);
}


antlrcpp::Any SPECTREParser::AltergroupContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitAltergroup(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::AltergroupContext* SPECTREParser::altergroup() {
  AltergroupContext *_localctx = _tracker.createInstance<AltergroupContext>(_ctx, getState());
  enterRule(_localctx, 136, SPECTREParser::RuleAltergroup);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1631);
    altergroup_header();
    setState(1632);
    global_declarations();
    setState(1634); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(1633);
      altergroup_content();
      setState(1636); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SPECTREParser::GLOBAL)
      | (1ULL << SPECTREParser::INCLUDE)
      | (1ULL << SPECTREParser::CPP_INCLUDE)
      | (1ULL << SPECTREParser::AHDL_INCLUDE)
      | (1ULL << SPECTREParser::LIBRARY)
      | (1ULL << SPECTREParser::SECTION)
      | (1ULL << SPECTREParser::SUBCKT)
      | (1ULL << SPECTREParser::INLINE_SUBCKT)
      | (1ULL << SPECTREParser::MODEL)
      | (1ULL << SPECTREParser::SAVE)
      | (1ULL << SPECTREParser::NODESET)
      | (1ULL << SPECTREParser::IC)
      | (1ULL << SPECTREParser::PARAMETERS)
      | (1ULL << SPECTREParser::STATISTICS)
      | (1ULL << SPECTREParser::AC)
      | (1ULL << SPECTREParser::ACMATCH)
      | (1ULL << SPECTREParser::DC)
      | (1ULL << SPECTREParser::DCMATCH)
      | (1ULL << SPECTREParser::ENVLP)
      | (1ULL << SPECTREParser::SP)
      | (1ULL << SPECTREParser::STB)
      | (1ULL << SPECTREParser::SWEEP)
      | (1ULL << SPECTREParser::TDR)
      | (1ULL << SPECTREParser::TRAN)
      | (1ULL << SPECTREParser::XF)
      | (1ULL << SPECTREParser::PAC)
      | (1ULL << SPECTREParser::PDISTO))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (SPECTREParser::PNOISE - 64))
      | (1ULL << (SPECTREParser::PSP - 64))
      | (1ULL << (SPECTREParser::PSS - 64))
      | (1ULL << (SPECTREParser::PXF - 64))
      | (1ULL << (SPECTREParser::PZ - 64))
      | (1ULL << (SPECTREParser::QPAC - 64))
      | (1ULL << (SPECTREParser::QPNOISE - 64))
      | (1ULL << (SPECTREParser::QPSP - 64))
      | (1ULL << (SPECTREParser::QPSS - 64))
      | (1ULL << (SPECTREParser::QPXF - 64))
      | (1ULL << (SPECTREParser::SENS - 64)))) != 0) || ((((_la - 191) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 191)) & ((1ULL << (SPECTREParser::OPEN_ROUND - 191))
      | (1ULL << (SPECTREParser::NUMBER - 191))
      | (1ULL << (SPECTREParser::ID - 191)))) != 0));
    setState(1638);
    altergroup_footer();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Altergroup_headerContext ------------------------------------------------------------------

SPECTREParser::Altergroup_headerContext::Altergroup_headerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Altergroup_headerContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

tree::TerminalNode* SPECTREParser::Altergroup_headerContext::ALTERGROUP() {
  return getToken(SPECTREParser::ALTERGROUP, 0);
}

tree::TerminalNode* SPECTREParser::Altergroup_headerContext::OPEN_CURLY() {
  return getToken(SPECTREParser::OPEN_CURLY, 0);
}

tree::TerminalNode* SPECTREParser::Altergroup_headerContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

std::vector<tree::TerminalNode *> SPECTREParser::Altergroup_headerContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::Altergroup_headerContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::Altergroup_headerContext::getRuleIndex() const {
  return SPECTREParser::RuleAltergroup_header;
}

void SPECTREParser::Altergroup_headerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAltergroup_header(this);
}

void SPECTREParser::Altergroup_headerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAltergroup_header(this);
}


antlrcpp::Any SPECTREParser::Altergroup_headerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitAltergroup_header(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Altergroup_headerContext* SPECTREParser::altergroup_header() {
  Altergroup_headerContext *_localctx = _tracker.createInstance<Altergroup_headerContext>(_ctx, getState());
  enterRule(_localctx, 138, SPECTREParser::RuleAltergroup_header);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1640);
    match(SPECTREParser::ID);
    setState(1641);
    match(SPECTREParser::ALTERGROUP);
    setState(1645);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SPECTREParser::NL) {
      setState(1642);
      match(SPECTREParser::NL);
      setState(1647);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1648);
    match(SPECTREParser::OPEN_CURLY);
    setState(1656);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SPECTREParser::PARAMETERS:
      case SPECTREParser::NL: {
        setState(1652);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SPECTREParser::NL) {
          setState(1649);
          match(SPECTREParser::NL);
          setState(1654);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case SPECTREParser::EOF: {
        setState(1655);
        match(SPECTREParser::EOF);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Altergroup_contentContext ------------------------------------------------------------------

SPECTREParser::Altergroup_contentContext::Altergroup_contentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SPECTREParser::Netlist_entityContext* SPECTREParser::Altergroup_contentContext::netlist_entity() {
  return getRuleContext<SPECTREParser::Netlist_entityContext>(0);
}


size_t SPECTREParser::Altergroup_contentContext::getRuleIndex() const {
  return SPECTREParser::RuleAltergroup_content;
}

void SPECTREParser::Altergroup_contentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAltergroup_content(this);
}

void SPECTREParser::Altergroup_contentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAltergroup_content(this);
}


antlrcpp::Any SPECTREParser::Altergroup_contentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitAltergroup_content(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Altergroup_contentContext* SPECTREParser::altergroup_content() {
  Altergroup_contentContext *_localctx = _tracker.createInstance<Altergroup_contentContext>(_ctx, getState());
  enterRule(_localctx, 140, SPECTREParser::RuleAltergroup_content);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1658);
    netlist_entity();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Altergroup_footerContext ------------------------------------------------------------------

SPECTREParser::Altergroup_footerContext::Altergroup_footerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Altergroup_footerContext::CLOSE_CURLY() {
  return getToken(SPECTREParser::CLOSE_CURLY, 0);
}

tree::TerminalNode* SPECTREParser::Altergroup_footerContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

std::vector<tree::TerminalNode *> SPECTREParser::Altergroup_footerContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::Altergroup_footerContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::Altergroup_footerContext::getRuleIndex() const {
  return SPECTREParser::RuleAltergroup_footer;
}

void SPECTREParser::Altergroup_footerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAltergroup_footer(this);
}

void SPECTREParser::Altergroup_footerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAltergroup_footer(this);
}


antlrcpp::Any SPECTREParser::Altergroup_footerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitAltergroup_footer(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Altergroup_footerContext* SPECTREParser::altergroup_footer() {
  Altergroup_footerContext *_localctx = _tracker.createInstance<Altergroup_footerContext>(_ctx, getState());
  enterRule(_localctx, 142, SPECTREParser::RuleAltergroup_footer);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1660);
    match(SPECTREParser::CLOSE_CURLY);
    setState(1668);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 313, _ctx)) {
    case 1: {
      setState(1664);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 312, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(1661);
          match(SPECTREParser::NL); 
        }
        setState(1666);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 312, _ctx);
      }
      break;
    }

    case 2: {
      setState(1667);
      match(SPECTREParser::EOF);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Assert_statementContext ------------------------------------------------------------------

SPECTREParser::Assert_statementContext::Assert_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Assert_statementContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

tree::TerminalNode* SPECTREParser::Assert_statementContext::ASSERT() {
  return getToken(SPECTREParser::ASSERT, 0);
}

SPECTREParser::Parameter_assignContext* SPECTREParser::Assert_statementContext::parameter_assign() {
  return getRuleContext<SPECTREParser::Parameter_assignContext>(0);
}

SPECTREParser::Parameter_listContext* SPECTREParser::Assert_statementContext::parameter_list() {
  return getRuleContext<SPECTREParser::Parameter_listContext>(0);
}

tree::TerminalNode* SPECTREParser::Assert_statementContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

std::vector<tree::TerminalNode *> SPECTREParser::Assert_statementContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::Assert_statementContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::Assert_statementContext::getRuleIndex() const {
  return SPECTREParser::RuleAssert_statement;
}

void SPECTREParser::Assert_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssert_statement(this);
}

void SPECTREParser::Assert_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssert_statement(this);
}


antlrcpp::Any SPECTREParser::Assert_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitAssert_statement(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Assert_statementContext* SPECTREParser::assert_statement() {
  Assert_statementContext *_localctx = _tracker.createInstance<Assert_statementContext>(_ctx, getState());
  enterRule(_localctx, 144, SPECTREParser::RuleAssert_statement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(1695);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 318, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1670);
      match(SPECTREParser::ID);
      setState(1671);
      match(SPECTREParser::ASSERT);
      setState(1672);
      parameter_assign();
      setState(1673);
      parameter_list();
      setState(1681);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 315, _ctx)) {
      case 1: {
        setState(1677);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 314, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1674);
            match(SPECTREParser::NL); 
          }
          setState(1679);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 314, _ctx);
        }
        break;
      }

      case 2: {
        setState(1680);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1683);
      match(SPECTREParser::ID);
      setState(1684);
      match(SPECTREParser::ASSERT);
      setState(1685);
      parameter_assign();
      setState(1693);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 317, _ctx)) {
      case 1: {
        setState(1689);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 316, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1686);
            match(SPECTREParser::NL); 
          }
          setState(1691);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 316, _ctx);
        }
        break;
      }

      case 2: {
        setState(1692);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Check_statementContext ------------------------------------------------------------------

SPECTREParser::Check_statementContext::Check_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Check_statementContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

tree::TerminalNode* SPECTREParser::Check_statementContext::CHECK() {
  return getToken(SPECTREParser::CHECK, 0);
}

SPECTREParser::Parameter_assignContext* SPECTREParser::Check_statementContext::parameter_assign() {
  return getRuleContext<SPECTREParser::Parameter_assignContext>(0);
}

tree::TerminalNode* SPECTREParser::Check_statementContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

std::vector<tree::TerminalNode *> SPECTREParser::Check_statementContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::Check_statementContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::Check_statementContext::getRuleIndex() const {
  return SPECTREParser::RuleCheck_statement;
}

void SPECTREParser::Check_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCheck_statement(this);
}

void SPECTREParser::Check_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCheck_statement(this);
}


antlrcpp::Any SPECTREParser::Check_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitCheck_statement(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Check_statementContext* SPECTREParser::check_statement() {
  Check_statementContext *_localctx = _tracker.createInstance<Check_statementContext>(_ctx, getState());
  enterRule(_localctx, 146, SPECTREParser::RuleCheck_statement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1697);
    match(SPECTREParser::ID);
    setState(1698);
    match(SPECTREParser::CHECK);
    setState(1699);
    parameter_assign();
    setState(1707);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 320, _ctx)) {
    case 1: {
      setState(1703);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 319, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(1700);
          match(SPECTREParser::NL); 
        }
        setState(1705);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 319, _ctx);
      }
      break;
    }

    case 2: {
      setState(1706);
      match(SPECTREParser::EOF);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SaveContext ------------------------------------------------------------------

SPECTREParser::SaveContext::SaveContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::SaveContext::SAVE() {
  return getToken(SPECTREParser::SAVE, 0);
}

tree::TerminalNode* SPECTREParser::SaveContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

SPECTREParser::Parameter_listContext* SPECTREParser::SaveContext::parameter_list() {
  return getRuleContext<SPECTREParser::Parameter_listContext>(0);
}

tree::TerminalNode* SPECTREParser::SaveContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

std::vector<tree::TerminalNode *> SPECTREParser::SaveContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::SaveContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::SaveContext::getRuleIndex() const {
  return SPECTREParser::RuleSave;
}

void SPECTREParser::SaveContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSave(this);
}

void SPECTREParser::SaveContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSave(this);
}


antlrcpp::Any SPECTREParser::SaveContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitSave(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::SaveContext* SPECTREParser::save() {
  SaveContext *_localctx = _tracker.createInstance<SaveContext>(_ctx, getState());
  enterRule(_localctx, 148, SPECTREParser::RuleSave);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(1732);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 325, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1709);
      match(SPECTREParser::SAVE);
      setState(1710);
      match(SPECTREParser::ID);
      setState(1711);
      parameter_list();
      setState(1719);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 322, _ctx)) {
      case 1: {
        setState(1715);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 321, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1712);
            match(SPECTREParser::NL); 
          }
          setState(1717);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 321, _ctx);
        }
        break;
      }

      case 2: {
        setState(1718);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1721);
      match(SPECTREParser::SAVE);
      setState(1722);
      match(SPECTREParser::ID);
      setState(1730);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 324, _ctx)) {
      case 1: {
        setState(1726);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 323, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1723);
            match(SPECTREParser::NL); 
          }
          setState(1728);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 323, _ctx);
        }
        break;
      }

      case 2: {
        setState(1729);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OptionContext ------------------------------------------------------------------

SPECTREParser::OptionContext::OptionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::OptionContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

tree::TerminalNode* SPECTREParser::OptionContext::OPTIONS() {
  return getToken(SPECTREParser::OPTIONS, 0);
}

SPECTREParser::Parameter_listContext* SPECTREParser::OptionContext::parameter_list() {
  return getRuleContext<SPECTREParser::Parameter_listContext>(0);
}

tree::TerminalNode* SPECTREParser::OptionContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

std::vector<tree::TerminalNode *> SPECTREParser::OptionContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::OptionContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::OptionContext::getRuleIndex() const {
  return SPECTREParser::RuleOption;
}

void SPECTREParser::OptionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOption(this);
}

void SPECTREParser::OptionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOption(this);
}


antlrcpp::Any SPECTREParser::OptionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitOption(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::OptionContext* SPECTREParser::option() {
  OptionContext *_localctx = _tracker.createInstance<OptionContext>(_ctx, getState());
  enterRule(_localctx, 150, SPECTREParser::RuleOption);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(1757);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 330, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1734);
      match(SPECTREParser::ID);
      setState(1735);
      match(SPECTREParser::OPTIONS);
      setState(1736);
      parameter_list();
      setState(1744);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 327, _ctx)) {
      case 1: {
        setState(1740);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 326, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1737);
            match(SPECTREParser::NL); 
          }
          setState(1742);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 326, _ctx);
        }
        break;
      }

      case 2: {
        setState(1743);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1746);
      match(SPECTREParser::ID);
      setState(1747);
      match(SPECTREParser::OPTIONS);
      setState(1755);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 329, _ctx)) {
      case 1: {
        setState(1751);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 328, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1748);
            match(SPECTREParser::NL); 
          }
          setState(1753);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 328, _ctx);
        }
        break;
      }

      case 2: {
        setState(1754);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SetContext ------------------------------------------------------------------

SPECTREParser::SetContext::SetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::SetContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

tree::TerminalNode* SPECTREParser::SetContext::SET() {
  return getToken(SPECTREParser::SET, 0);
}

SPECTREParser::Parameter_listContext* SPECTREParser::SetContext::parameter_list() {
  return getRuleContext<SPECTREParser::Parameter_listContext>(0);
}

tree::TerminalNode* SPECTREParser::SetContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

std::vector<tree::TerminalNode *> SPECTREParser::SetContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::SetContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::SetContext::getRuleIndex() const {
  return SPECTREParser::RuleSet;
}

void SPECTREParser::SetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSet(this);
}

void SPECTREParser::SetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSet(this);
}


antlrcpp::Any SPECTREParser::SetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitSet(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::SetContext* SPECTREParser::set() {
  SetContext *_localctx = _tracker.createInstance<SetContext>(_ctx, getState());
  enterRule(_localctx, 152, SPECTREParser::RuleSet);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(1782);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 335, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1759);
      match(SPECTREParser::ID);
      setState(1760);
      match(SPECTREParser::SET);
      setState(1761);
      parameter_list();
      setState(1769);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 332, _ctx)) {
      case 1: {
        setState(1765);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 331, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1762);
            match(SPECTREParser::NL); 
          }
          setState(1767);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 331, _ctx);
        }
        break;
      }

      case 2: {
        setState(1768);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1771);
      match(SPECTREParser::ID);
      setState(1772);
      match(SPECTREParser::SET);
      setState(1780);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 334, _ctx)) {
      case 1: {
        setState(1776);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 333, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1773);
            match(SPECTREParser::NL); 
          }
          setState(1778);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 333, _ctx);
        }
        break;
      }

      case 2: {
        setState(1779);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ShellContext ------------------------------------------------------------------

SPECTREParser::ShellContext::ShellContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::ShellContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

tree::TerminalNode* SPECTREParser::ShellContext::SHELL() {
  return getToken(SPECTREParser::SHELL, 0);
}

SPECTREParser::Parameter_listContext* SPECTREParser::ShellContext::parameter_list() {
  return getRuleContext<SPECTREParser::Parameter_listContext>(0);
}

tree::TerminalNode* SPECTREParser::ShellContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

std::vector<tree::TerminalNode *> SPECTREParser::ShellContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::ShellContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::ShellContext::getRuleIndex() const {
  return SPECTREParser::RuleShell;
}

void SPECTREParser::ShellContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShell(this);
}

void SPECTREParser::ShellContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShell(this);
}


antlrcpp::Any SPECTREParser::ShellContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitShell(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::ShellContext* SPECTREParser::shell() {
  ShellContext *_localctx = _tracker.createInstance<ShellContext>(_ctx, getState());
  enterRule(_localctx, 154, SPECTREParser::RuleShell);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(1807);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 340, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1784);
      match(SPECTREParser::ID);
      setState(1785);
      match(SPECTREParser::SHELL);
      setState(1786);
      parameter_list();
      setState(1794);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 337, _ctx)) {
      case 1: {
        setState(1790);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 336, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1787);
            match(SPECTREParser::NL); 
          }
          setState(1792);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 336, _ctx);
        }
        break;
      }

      case 2: {
        setState(1793);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1796);
      match(SPECTREParser::ID);
      setState(1797);
      match(SPECTREParser::SHELL);
      setState(1805);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 339, _ctx)) {
      case 1: {
        setState(1801);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 338, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1798);
            match(SPECTREParser::NL); 
          }
          setState(1803);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 338, _ctx);
        }
        break;
      }

      case 2: {
        setState(1804);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InfoContext ------------------------------------------------------------------

SPECTREParser::InfoContext::InfoContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::InfoContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

tree::TerminalNode* SPECTREParser::InfoContext::INFO() {
  return getToken(SPECTREParser::INFO, 0);
}

SPECTREParser::Parameter_listContext* SPECTREParser::InfoContext::parameter_list() {
  return getRuleContext<SPECTREParser::Parameter_listContext>(0);
}

tree::TerminalNode* SPECTREParser::InfoContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

std::vector<tree::TerminalNode *> SPECTREParser::InfoContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::InfoContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::InfoContext::getRuleIndex() const {
  return SPECTREParser::RuleInfo;
}

void SPECTREParser::InfoContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInfo(this);
}

void SPECTREParser::InfoContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInfo(this);
}


antlrcpp::Any SPECTREParser::InfoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitInfo(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::InfoContext* SPECTREParser::info() {
  InfoContext *_localctx = _tracker.createInstance<InfoContext>(_ctx, getState());
  enterRule(_localctx, 156, SPECTREParser::RuleInfo);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(1832);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 345, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1809);
      match(SPECTREParser::ID);
      setState(1810);
      match(SPECTREParser::INFO);
      setState(1811);
      parameter_list();
      setState(1819);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 342, _ctx)) {
      case 1: {
        setState(1815);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 341, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1812);
            match(SPECTREParser::NL); 
          }
          setState(1817);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 341, _ctx);
        }
        break;
      }

      case 2: {
        setState(1818);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1821);
      match(SPECTREParser::ID);
      setState(1822);
      match(SPECTREParser::INFO);
      setState(1830);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 344, _ctx)) {
      case 1: {
        setState(1826);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 343, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1823);
            match(SPECTREParser::NL); 
          }
          setState(1828);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 343, _ctx);
        }
        break;
      }

      case 2: {
        setState(1829);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NodesetContext ------------------------------------------------------------------

SPECTREParser::NodesetContext::NodesetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::NodesetContext::NODESET() {
  return getToken(SPECTREParser::NODESET, 0);
}

tree::TerminalNode* SPECTREParser::NodesetContext::EQUAL() {
  return getToken(SPECTREParser::EQUAL, 0);
}

SPECTREParser::ExpressionContext* SPECTREParser::NodesetContext::expression() {
  return getRuleContext<SPECTREParser::ExpressionContext>(0);
}

tree::TerminalNode* SPECTREParser::NodesetContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

SPECTREParser::Parameter_accessContext* SPECTREParser::NodesetContext::parameter_access() {
  return getRuleContext<SPECTREParser::Parameter_accessContext>(0);
}

std::vector<tree::TerminalNode *> SPECTREParser::NodesetContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::NodesetContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::NodesetContext::getRuleIndex() const {
  return SPECTREParser::RuleNodeset;
}

void SPECTREParser::NodesetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNodeset(this);
}

void SPECTREParser::NodesetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNodeset(this);
}


antlrcpp::Any SPECTREParser::NodesetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitNodeset(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::NodesetContext* SPECTREParser::nodeset() {
  NodesetContext *_localctx = _tracker.createInstance<NodesetContext>(_ctx, getState());
  enterRule(_localctx, 158, SPECTREParser::RuleNodeset);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1834);
    match(SPECTREParser::NODESET);
    setState(1836);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SPECTREParser::COLON) {
      setState(1835);
      parameter_access();
    }
    setState(1838);
    match(SPECTREParser::EQUAL);
    setState(1839);
    expression(0);
    setState(1847);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 348, _ctx)) {
    case 1: {
      setState(1843);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 347, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(1840);
          match(SPECTREParser::NL); 
        }
        setState(1845);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 347, _ctx);
      }
      break;
    }

    case 2: {
      setState(1846);
      match(SPECTREParser::EOF);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IcContext ------------------------------------------------------------------

SPECTREParser::IcContext::IcContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::IcContext::IC() {
  return getToken(SPECTREParser::IC, 0);
}

SPECTREParser::Parameter_listContext* SPECTREParser::IcContext::parameter_list() {
  return getRuleContext<SPECTREParser::Parameter_listContext>(0);
}

tree::TerminalNode* SPECTREParser::IcContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

std::vector<tree::TerminalNode *> SPECTREParser::IcContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::IcContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::IcContext::getRuleIndex() const {
  return SPECTREParser::RuleIc;
}

void SPECTREParser::IcContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIc(this);
}

void SPECTREParser::IcContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIc(this);
}


antlrcpp::Any SPECTREParser::IcContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitIc(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::IcContext* SPECTREParser::ic() {
  IcContext *_localctx = _tracker.createInstance<IcContext>(_ctx, getState());
  enterRule(_localctx, 160, SPECTREParser::RuleIc);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(1870);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 353, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1849);
      match(SPECTREParser::IC);
      setState(1850);
      parameter_list();
      setState(1858);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 350, _ctx)) {
      case 1: {
        setState(1854);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 349, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1851);
            match(SPECTREParser::NL); 
          }
          setState(1856);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 349, _ctx);
        }
        break;
      }

      case 2: {
        setState(1857);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1860);
      match(SPECTREParser::IC);
      setState(1868);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 352, _ctx)) {
      case 1: {
        setState(1864);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 351, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(1861);
            match(SPECTREParser::NL); 
          }
          setState(1866);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 351, _ctx);
        }
        break;
      }

      case 2: {
        setState(1867);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatisticsContext ------------------------------------------------------------------

SPECTREParser::StatisticsContext::StatisticsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SPECTREParser::Statistics_headerContext* SPECTREParser::StatisticsContext::statistics_header() {
  return getRuleContext<SPECTREParser::Statistics_headerContext>(0);
}

SPECTREParser::Statistics_footerContext* SPECTREParser::StatisticsContext::statistics_footer() {
  return getRuleContext<SPECTREParser::Statistics_footerContext>(0);
}

std::vector<SPECTREParser::Statistics_contentContext *> SPECTREParser::StatisticsContext::statistics_content() {
  return getRuleContexts<SPECTREParser::Statistics_contentContext>();
}

SPECTREParser::Statistics_contentContext* SPECTREParser::StatisticsContext::statistics_content(size_t i) {
  return getRuleContext<SPECTREParser::Statistics_contentContext>(i);
}


size_t SPECTREParser::StatisticsContext::getRuleIndex() const {
  return SPECTREParser::RuleStatistics;
}

void SPECTREParser::StatisticsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatistics(this);
}

void SPECTREParser::StatisticsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatistics(this);
}


antlrcpp::Any SPECTREParser::StatisticsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitStatistics(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::StatisticsContext* SPECTREParser::statistics() {
  StatisticsContext *_localctx = _tracker.createInstance<StatisticsContext>(_ctx, getState());
  enterRule(_localctx, 162, SPECTREParser::RuleStatistics);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1872);
    statistics_header();
    setState(1874); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(1873);
      statistics_content();
      setState(1876); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SPECTREParser::PROCESS)
      | (1ULL << SPECTREParser::CORRELATE)
      | (1ULL << SPECTREParser::TRUNCATE)
      | (1ULL << SPECTREParser::MISMATCH)
      | (1ULL << SPECTREParser::VARY))) != 0));
    setState(1878);
    statistics_footer();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Statistics_headerContext ------------------------------------------------------------------

SPECTREParser::Statistics_headerContext::Statistics_headerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Statistics_headerContext::STATISTICS() {
  return getToken(SPECTREParser::STATISTICS, 0);
}

tree::TerminalNode* SPECTREParser::Statistics_headerContext::OPEN_CURLY() {
  return getToken(SPECTREParser::OPEN_CURLY, 0);
}

std::vector<tree::TerminalNode *> SPECTREParser::Statistics_headerContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::Statistics_headerContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::Statistics_headerContext::getRuleIndex() const {
  return SPECTREParser::RuleStatistics_header;
}

void SPECTREParser::Statistics_headerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatistics_header(this);
}

void SPECTREParser::Statistics_headerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatistics_header(this);
}


antlrcpp::Any SPECTREParser::Statistics_headerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitStatistics_header(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Statistics_headerContext* SPECTREParser::statistics_header() {
  Statistics_headerContext *_localctx = _tracker.createInstance<Statistics_headerContext>(_ctx, getState());
  enterRule(_localctx, 164, SPECTREParser::RuleStatistics_header);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1880);
    match(SPECTREParser::STATISTICS);
    setState(1884);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SPECTREParser::NL) {
      setState(1881);
      match(SPECTREParser::NL);
      setState(1886);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1887);
    match(SPECTREParser::OPEN_CURLY);
    setState(1891);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SPECTREParser::NL) {
      setState(1888);
      match(SPECTREParser::NL);
      setState(1893);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Statistics_contentContext ------------------------------------------------------------------

SPECTREParser::Statistics_contentContext::Statistics_contentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SPECTREParser::ProcessContext* SPECTREParser::Statistics_contentContext::process() {
  return getRuleContext<SPECTREParser::ProcessContext>(0);
}

SPECTREParser::MismatchContext* SPECTREParser::Statistics_contentContext::mismatch() {
  return getRuleContext<SPECTREParser::MismatchContext>(0);
}

SPECTREParser::VaryContext* SPECTREParser::Statistics_contentContext::vary() {
  return getRuleContext<SPECTREParser::VaryContext>(0);
}

SPECTREParser::CorrelateContext* SPECTREParser::Statistics_contentContext::correlate() {
  return getRuleContext<SPECTREParser::CorrelateContext>(0);
}

SPECTREParser::TruncateContext* SPECTREParser::Statistics_contentContext::truncate() {
  return getRuleContext<SPECTREParser::TruncateContext>(0);
}


size_t SPECTREParser::Statistics_contentContext::getRuleIndex() const {
  return SPECTREParser::RuleStatistics_content;
}

void SPECTREParser::Statistics_contentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatistics_content(this);
}

void SPECTREParser::Statistics_contentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatistics_content(this);
}


antlrcpp::Any SPECTREParser::Statistics_contentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitStatistics_content(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Statistics_contentContext* SPECTREParser::statistics_content() {
  Statistics_contentContext *_localctx = _tracker.createInstance<Statistics_contentContext>(_ctx, getState());
  enterRule(_localctx, 166, SPECTREParser::RuleStatistics_content);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1899);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SPECTREParser::PROCESS: {
        enterOuterAlt(_localctx, 1);
        setState(1894);
        process();
        break;
      }

      case SPECTREParser::MISMATCH: {
        enterOuterAlt(_localctx, 2);
        setState(1895);
        mismatch();
        break;
      }

      case SPECTREParser::VARY: {
        enterOuterAlt(_localctx, 3);
        setState(1896);
        vary();
        break;
      }

      case SPECTREParser::CORRELATE: {
        enterOuterAlt(_localctx, 4);
        setState(1897);
        correlate();
        break;
      }

      case SPECTREParser::TRUNCATE: {
        enterOuterAlt(_localctx, 5);
        setState(1898);
        truncate();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Statistics_footerContext ------------------------------------------------------------------

SPECTREParser::Statistics_footerContext::Statistics_footerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Statistics_footerContext::CLOSE_CURLY() {
  return getToken(SPECTREParser::CLOSE_CURLY, 0);
}

tree::TerminalNode* SPECTREParser::Statistics_footerContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

std::vector<tree::TerminalNode *> SPECTREParser::Statistics_footerContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::Statistics_footerContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::Statistics_footerContext::getRuleIndex() const {
  return SPECTREParser::RuleStatistics_footer;
}

void SPECTREParser::Statistics_footerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatistics_footer(this);
}

void SPECTREParser::Statistics_footerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatistics_footer(this);
}


antlrcpp::Any SPECTREParser::Statistics_footerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitStatistics_footer(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Statistics_footerContext* SPECTREParser::statistics_footer() {
  Statistics_footerContext *_localctx = _tracker.createInstance<Statistics_footerContext>(_ctx, getState());
  enterRule(_localctx, 168, SPECTREParser::RuleStatistics_footer);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1901);
    match(SPECTREParser::CLOSE_CURLY);
    setState(1909);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 359, _ctx)) {
    case 1: {
      setState(1905);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 358, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(1902);
          match(SPECTREParser::NL); 
        }
        setState(1907);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 358, _ctx);
      }
      break;
    }

    case 2: {
      setState(1908);
      match(SPECTREParser::EOF);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcessContext ------------------------------------------------------------------

SPECTREParser::ProcessContext::ProcessContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::ProcessContext::PROCESS() {
  return getToken(SPECTREParser::PROCESS, 0);
}

tree::TerminalNode* SPECTREParser::ProcessContext::OPEN_CURLY() {
  return getToken(SPECTREParser::OPEN_CURLY, 0);
}

tree::TerminalNode* SPECTREParser::ProcessContext::CLOSE_CURLY() {
  return getToken(SPECTREParser::CLOSE_CURLY, 0);
}

tree::TerminalNode* SPECTREParser::ProcessContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

std::vector<tree::TerminalNode *> SPECTREParser::ProcessContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::ProcessContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}

std::vector<SPECTREParser::Statistics_contentContext *> SPECTREParser::ProcessContext::statistics_content() {
  return getRuleContexts<SPECTREParser::Statistics_contentContext>();
}

SPECTREParser::Statistics_contentContext* SPECTREParser::ProcessContext::statistics_content(size_t i) {
  return getRuleContext<SPECTREParser::Statistics_contentContext>(i);
}


size_t SPECTREParser::ProcessContext::getRuleIndex() const {
  return SPECTREParser::RuleProcess;
}

void SPECTREParser::ProcessContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProcess(this);
}

void SPECTREParser::ProcessContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProcess(this);
}


antlrcpp::Any SPECTREParser::ProcessContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitProcess(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::ProcessContext* SPECTREParser::process() {
  ProcessContext *_localctx = _tracker.createInstance<ProcessContext>(_ctx, getState());
  enterRule(_localctx, 170, SPECTREParser::RuleProcess);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1911);
    match(SPECTREParser::PROCESS);
    setState(1915);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SPECTREParser::NL) {
      setState(1912);
      match(SPECTREParser::NL);
      setState(1917);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1918);
    match(SPECTREParser::OPEN_CURLY);
    setState(1922);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SPECTREParser::NL) {
      setState(1919);
      match(SPECTREParser::NL);
      setState(1924);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1926); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(1925);
      statistics_content();
      setState(1928); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SPECTREParser::PROCESS)
      | (1ULL << SPECTREParser::CORRELATE)
      | (1ULL << SPECTREParser::TRUNCATE)
      | (1ULL << SPECTREParser::MISMATCH)
      | (1ULL << SPECTREParser::VARY))) != 0));
    setState(1930);
    match(SPECTREParser::CLOSE_CURLY);
    setState(1938);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SPECTREParser::PROCESS:
      case SPECTREParser::CORRELATE:
      case SPECTREParser::TRUNCATE:
      case SPECTREParser::MISMATCH:
      case SPECTREParser::VARY:
      case SPECTREParser::CLOSE_CURLY:
      case SPECTREParser::NL: {
        setState(1934);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SPECTREParser::NL) {
          setState(1931);
          match(SPECTREParser::NL);
          setState(1936);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case SPECTREParser::EOF: {
        setState(1937);
        match(SPECTREParser::EOF);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MismatchContext ------------------------------------------------------------------

SPECTREParser::MismatchContext::MismatchContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::MismatchContext::MISMATCH() {
  return getToken(SPECTREParser::MISMATCH, 0);
}

tree::TerminalNode* SPECTREParser::MismatchContext::OPEN_CURLY() {
  return getToken(SPECTREParser::OPEN_CURLY, 0);
}

tree::TerminalNode* SPECTREParser::MismatchContext::CLOSE_CURLY() {
  return getToken(SPECTREParser::CLOSE_CURLY, 0);
}

tree::TerminalNode* SPECTREParser::MismatchContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

std::vector<tree::TerminalNode *> SPECTREParser::MismatchContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::MismatchContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}

std::vector<SPECTREParser::Statistics_contentContext *> SPECTREParser::MismatchContext::statistics_content() {
  return getRuleContexts<SPECTREParser::Statistics_contentContext>();
}

SPECTREParser::Statistics_contentContext* SPECTREParser::MismatchContext::statistics_content(size_t i) {
  return getRuleContext<SPECTREParser::Statistics_contentContext>(i);
}


size_t SPECTREParser::MismatchContext::getRuleIndex() const {
  return SPECTREParser::RuleMismatch;
}

void SPECTREParser::MismatchContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMismatch(this);
}

void SPECTREParser::MismatchContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMismatch(this);
}


antlrcpp::Any SPECTREParser::MismatchContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitMismatch(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::MismatchContext* SPECTREParser::mismatch() {
  MismatchContext *_localctx = _tracker.createInstance<MismatchContext>(_ctx, getState());
  enterRule(_localctx, 172, SPECTREParser::RuleMismatch);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1940);
    match(SPECTREParser::MISMATCH);
    setState(1944);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SPECTREParser::NL) {
      setState(1941);
      match(SPECTREParser::NL);
      setState(1946);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1947);
    match(SPECTREParser::OPEN_CURLY);
    setState(1951);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SPECTREParser::NL) {
      setState(1948);
      match(SPECTREParser::NL);
      setState(1953);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1955); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(1954);
      statistics_content();
      setState(1957); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SPECTREParser::PROCESS)
      | (1ULL << SPECTREParser::CORRELATE)
      | (1ULL << SPECTREParser::TRUNCATE)
      | (1ULL << SPECTREParser::MISMATCH)
      | (1ULL << SPECTREParser::VARY))) != 0));
    setState(1959);
    match(SPECTREParser::CLOSE_CURLY);
    setState(1967);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SPECTREParser::PROCESS:
      case SPECTREParser::CORRELATE:
      case SPECTREParser::TRUNCATE:
      case SPECTREParser::MISMATCH:
      case SPECTREParser::VARY:
      case SPECTREParser::CLOSE_CURLY:
      case SPECTREParser::NL: {
        setState(1963);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SPECTREParser::NL) {
          setState(1960);
          match(SPECTREParser::NL);
          setState(1965);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case SPECTREParser::EOF: {
        setState(1966);
        match(SPECTREParser::EOF);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CorrelateContext ------------------------------------------------------------------

SPECTREParser::CorrelateContext::CorrelateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::CorrelateContext::CORRELATE() {
  return getToken(SPECTREParser::CORRELATE, 0);
}

std::vector<tree::TerminalNode *> SPECTREParser::CorrelateContext::ID() {
  return getTokens(SPECTREParser::ID);
}

tree::TerminalNode* SPECTREParser::CorrelateContext::ID(size_t i) {
  return getToken(SPECTREParser::ID, i);
}

std::vector<tree::TerminalNode *> SPECTREParser::CorrelateContext::EQUAL() {
  return getTokens(SPECTREParser::EQUAL);
}

tree::TerminalNode* SPECTREParser::CorrelateContext::EQUAL(size_t i) {
  return getToken(SPECTREParser::EQUAL, i);
}

std::vector<tree::TerminalNode *> SPECTREParser::CorrelateContext::OPEN_SQUARE() {
  return getTokens(SPECTREParser::OPEN_SQUARE);
}

tree::TerminalNode* SPECTREParser::CorrelateContext::OPEN_SQUARE(size_t i) {
  return getToken(SPECTREParser::OPEN_SQUARE, i);
}

std::vector<tree::TerminalNode *> SPECTREParser::CorrelateContext::CLOSE_SQUARE() {
  return getTokens(SPECTREParser::CLOSE_SQUARE);
}

tree::TerminalNode* SPECTREParser::CorrelateContext::CLOSE_SQUARE(size_t i) {
  return getToken(SPECTREParser::CLOSE_SQUARE, i);
}

tree::TerminalNode* SPECTREParser::CorrelateContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

std::vector<SPECTREParser::Parameter_idContext *> SPECTREParser::CorrelateContext::parameter_id() {
  return getRuleContexts<SPECTREParser::Parameter_idContext>();
}

SPECTREParser::Parameter_idContext* SPECTREParser::CorrelateContext::parameter_id(size_t i) {
  return getRuleContext<SPECTREParser::Parameter_idContext>(i);
}

std::vector<tree::TerminalNode *> SPECTREParser::CorrelateContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::CorrelateContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}

SPECTREParser::Parameter_assignContext* SPECTREParser::CorrelateContext::parameter_assign() {
  return getRuleContext<SPECTREParser::Parameter_assignContext>(0);
}


size_t SPECTREParser::CorrelateContext::getRuleIndex() const {
  return SPECTREParser::RuleCorrelate;
}

void SPECTREParser::CorrelateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCorrelate(this);
}

void SPECTREParser::CorrelateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCorrelate(this);
}


antlrcpp::Any SPECTREParser::CorrelateContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitCorrelate(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::CorrelateContext* SPECTREParser::correlate() {
  CorrelateContext *_localctx = _tracker.createInstance<CorrelateContext>(_ctx, getState());
  enterRule(_localctx, 174, SPECTREParser::RuleCorrelate);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(2013);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 377, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1969);
      match(SPECTREParser::CORRELATE);
      setState(1970);
      match(SPECTREParser::ID);
      setState(1971);
      match(SPECTREParser::EQUAL);
      setState(1972);
      match(SPECTREParser::OPEN_SQUARE);
      setState(1974); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(1973);
        parameter_id();
        setState(1976); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SPECTREParser::SECTION)
        | (1ULL << SPECTREParser::SAVE)
        | (1ULL << SPECTREParser::PORTS)
        | (1ULL << SPECTREParser::DC))) != 0) || _la == SPECTREParser::DELAY || _la == SPECTREParser::ID);
      setState(1978);
      match(SPECTREParser::CLOSE_SQUARE);
      setState(1986);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case SPECTREParser::PROCESS:
        case SPECTREParser::CORRELATE:
        case SPECTREParser::TRUNCATE:
        case SPECTREParser::MISMATCH:
        case SPECTREParser::VARY:
        case SPECTREParser::CLOSE_CURLY:
        case SPECTREParser::NL: {
          setState(1982);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == SPECTREParser::NL) {
            setState(1979);
            match(SPECTREParser::NL);
            setState(1984);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          break;
        }

        case SPECTREParser::EOF: {
          setState(1985);
          match(SPECTREParser::EOF);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1988);
      match(SPECTREParser::CORRELATE);
      setState(1999); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(1989);
                match(SPECTREParser::ID);
                setState(1990);
                match(SPECTREParser::EQUAL);
                setState(1991);
                match(SPECTREParser::OPEN_SQUARE);
                setState(1993); 
                _errHandler->sync(this);
                _la = _input->LA(1);
                do {
                  setState(1992);
                  parameter_id();
                  setState(1995); 
                  _errHandler->sync(this);
                  _la = _input->LA(1);
                } while ((((_la & ~ 0x3fULL) == 0) &&
                  ((1ULL << _la) & ((1ULL << SPECTREParser::SECTION)
                  | (1ULL << SPECTREParser::SAVE)
                  | (1ULL << SPECTREParser::PORTS)
                  | (1ULL << SPECTREParser::DC))) != 0) || _la == SPECTREParser::DELAY || _la == SPECTREParser::ID);
                setState(1997);
                match(SPECTREParser::CLOSE_SQUARE);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(2001); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 374, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(2003);
      parameter_assign();
      setState(2011);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case SPECTREParser::PROCESS:
        case SPECTREParser::CORRELATE:
        case SPECTREParser::TRUNCATE:
        case SPECTREParser::MISMATCH:
        case SPECTREParser::VARY:
        case SPECTREParser::CLOSE_CURLY:
        case SPECTREParser::NL: {
          setState(2007);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == SPECTREParser::NL) {
            setState(2004);
            match(SPECTREParser::NL);
            setState(2009);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          break;
        }

        case SPECTREParser::EOF: {
          setState(2010);
          match(SPECTREParser::EOF);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TruncateContext ------------------------------------------------------------------

SPECTREParser::TruncateContext::TruncateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::TruncateContext::TRUNCATE() {
  return getToken(SPECTREParser::TRUNCATE, 0);
}

SPECTREParser::Parameter_assignContext* SPECTREParser::TruncateContext::parameter_assign() {
  return getRuleContext<SPECTREParser::Parameter_assignContext>(0);
}

tree::TerminalNode* SPECTREParser::TruncateContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

std::vector<tree::TerminalNode *> SPECTREParser::TruncateContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::TruncateContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::TruncateContext::getRuleIndex() const {
  return SPECTREParser::RuleTruncate;
}

void SPECTREParser::TruncateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTruncate(this);
}

void SPECTREParser::TruncateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTruncate(this);
}


antlrcpp::Any SPECTREParser::TruncateContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitTruncate(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::TruncateContext* SPECTREParser::truncate() {
  TruncateContext *_localctx = _tracker.createInstance<TruncateContext>(_ctx, getState());
  enterRule(_localctx, 176, SPECTREParser::RuleTruncate);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2015);
    match(SPECTREParser::TRUNCATE);
    setState(2016);
    parameter_assign();
    setState(2024);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SPECTREParser::PROCESS:
      case SPECTREParser::CORRELATE:
      case SPECTREParser::TRUNCATE:
      case SPECTREParser::MISMATCH:
      case SPECTREParser::VARY:
      case SPECTREParser::CLOSE_CURLY:
      case SPECTREParser::NL: {
        setState(2020);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SPECTREParser::NL) {
          setState(2017);
          match(SPECTREParser::NL);
          setState(2022);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case SPECTREParser::EOF: {
        setState(2023);
        match(SPECTREParser::EOF);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VaryContext ------------------------------------------------------------------

SPECTREParser::VaryContext::VaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::VaryContext::VARY() {
  return getToken(SPECTREParser::VARY, 0);
}

tree::TerminalNode* SPECTREParser::VaryContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

SPECTREParser::Parameter_listContext* SPECTREParser::VaryContext::parameter_list() {
  return getRuleContext<SPECTREParser::Parameter_listContext>(0);
}

tree::TerminalNode* SPECTREParser::VaryContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

std::vector<tree::TerminalNode *> SPECTREParser::VaryContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::VaryContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::VaryContext::getRuleIndex() const {
  return SPECTREParser::RuleVary;
}

void SPECTREParser::VaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVary(this);
}

void SPECTREParser::VaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVary(this);
}


antlrcpp::Any SPECTREParser::VaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitVary(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::VaryContext* SPECTREParser::vary() {
  VaryContext *_localctx = _tracker.createInstance<VaryContext>(_ctx, getState());
  enterRule(_localctx, 178, SPECTREParser::RuleVary);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(2049);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 384, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(2026);
      match(SPECTREParser::VARY);
      setState(2027);
      match(SPECTREParser::ID);
      setState(2028);
      parameter_list();
      setState(2036);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case SPECTREParser::PROCESS:
        case SPECTREParser::CORRELATE:
        case SPECTREParser::TRUNCATE:
        case SPECTREParser::MISMATCH:
        case SPECTREParser::VARY:
        case SPECTREParser::CLOSE_CURLY:
        case SPECTREParser::NL: {
          setState(2032);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == SPECTREParser::NL) {
            setState(2029);
            match(SPECTREParser::NL);
            setState(2034);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          break;
        }

        case SPECTREParser::EOF: {
          setState(2035);
          match(SPECTREParser::EOF);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(2038);
      match(SPECTREParser::VARY);
      setState(2039);
      match(SPECTREParser::ID);
      setState(2047);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case SPECTREParser::PROCESS:
        case SPECTREParser::CORRELATE:
        case SPECTREParser::TRUNCATE:
        case SPECTREParser::MISMATCH:
        case SPECTREParser::VARY:
        case SPECTREParser::CLOSE_CURLY:
        case SPECTREParser::NL: {
          setState(2043);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == SPECTREParser::NL) {
            setState(2040);
            match(SPECTREParser::NL);
            setState(2045);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          break;
        }

        case SPECTREParser::EOF: {
          setState(2046);
          match(SPECTREParser::EOF);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReliabilityContext ------------------------------------------------------------------

SPECTREParser::ReliabilityContext::ReliabilityContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SPECTREParser::Reliability_headerContext* SPECTREParser::ReliabilityContext::reliability_header() {
  return getRuleContext<SPECTREParser::Reliability_headerContext>(0);
}

SPECTREParser::Reliability_footerContext* SPECTREParser::ReliabilityContext::reliability_footer() {
  return getRuleContext<SPECTREParser::Reliability_footerContext>(0);
}

std::vector<SPECTREParser::Reliability_contentContext *> SPECTREParser::ReliabilityContext::reliability_content() {
  return getRuleContexts<SPECTREParser::Reliability_contentContext>();
}

SPECTREParser::Reliability_contentContext* SPECTREParser::ReliabilityContext::reliability_content(size_t i) {
  return getRuleContext<SPECTREParser::Reliability_contentContext>(i);
}


size_t SPECTREParser::ReliabilityContext::getRuleIndex() const {
  return SPECTREParser::RuleReliability;
}

void SPECTREParser::ReliabilityContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReliability(this);
}

void SPECTREParser::ReliabilityContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReliability(this);
}


antlrcpp::Any SPECTREParser::ReliabilityContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitReliability(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::ReliabilityContext* SPECTREParser::reliability() {
  ReliabilityContext *_localctx = _tracker.createInstance<ReliabilityContext>(_ctx, getState());
  enterRule(_localctx, 180, SPECTREParser::RuleReliability);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2051);
    reliability_header();
    setState(2053); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(2052);
      reliability_content();
      setState(2055); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SPECTREParser::GLOBAL)
      | (1ULL << SPECTREParser::INCLUDE)
      | (1ULL << SPECTREParser::CPP_INCLUDE)
      | (1ULL << SPECTREParser::AHDL_INCLUDE)
      | (1ULL << SPECTREParser::LIBRARY)
      | (1ULL << SPECTREParser::SECTION)
      | (1ULL << SPECTREParser::SUBCKT)
      | (1ULL << SPECTREParser::INLINE_SUBCKT)
      | (1ULL << SPECTREParser::MODEL)
      | (1ULL << SPECTREParser::SAVE)
      | (1ULL << SPECTREParser::NODESET)
      | (1ULL << SPECTREParser::IC)
      | (1ULL << SPECTREParser::PARAMETERS)
      | (1ULL << SPECTREParser::STATISTICS)
      | (1ULL << SPECTREParser::AC)
      | (1ULL << SPECTREParser::ACMATCH)
      | (1ULL << SPECTREParser::DC)
      | (1ULL << SPECTREParser::DCMATCH)
      | (1ULL << SPECTREParser::ENVLP)
      | (1ULL << SPECTREParser::SP)
      | (1ULL << SPECTREParser::STB)
      | (1ULL << SPECTREParser::SWEEP)
      | (1ULL << SPECTREParser::TDR)
      | (1ULL << SPECTREParser::TRAN)
      | (1ULL << SPECTREParser::XF)
      | (1ULL << SPECTREParser::PAC)
      | (1ULL << SPECTREParser::PDISTO))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (SPECTREParser::PNOISE - 64))
      | (1ULL << (SPECTREParser::PSP - 64))
      | (1ULL << (SPECTREParser::PSS - 64))
      | (1ULL << (SPECTREParser::PXF - 64))
      | (1ULL << (SPECTREParser::PZ - 64))
      | (1ULL << (SPECTREParser::QPAC - 64))
      | (1ULL << (SPECTREParser::QPNOISE - 64))
      | (1ULL << (SPECTREParser::QPSP - 64))
      | (1ULL << (SPECTREParser::QPSS - 64))
      | (1ULL << (SPECTREParser::QPXF - 64))
      | (1ULL << (SPECTREParser::SENS - 64)))) != 0) || ((((_la - 191) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 191)) & ((1ULL << (SPECTREParser::OPEN_ROUND - 191))
      | (1ULL << (SPECTREParser::NUMBER - 191))
      | (1ULL << (SPECTREParser::ID - 191)))) != 0));
    setState(2057);
    reliability_footer();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Reliability_headerContext ------------------------------------------------------------------

SPECTREParser::Reliability_headerContext::Reliability_headerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Reliability_headerContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

tree::TerminalNode* SPECTREParser::Reliability_headerContext::RELIABILITY() {
  return getToken(SPECTREParser::RELIABILITY, 0);
}

tree::TerminalNode* SPECTREParser::Reliability_headerContext::OPEN_CURLY() {
  return getToken(SPECTREParser::OPEN_CURLY, 0);
}

SPECTREParser::Parameter_listContext* SPECTREParser::Reliability_headerContext::parameter_list() {
  return getRuleContext<SPECTREParser::Parameter_listContext>(0);
}

std::vector<tree::TerminalNode *> SPECTREParser::Reliability_headerContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::Reliability_headerContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::Reliability_headerContext::getRuleIndex() const {
  return SPECTREParser::RuleReliability_header;
}

void SPECTREParser::Reliability_headerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReliability_header(this);
}

void SPECTREParser::Reliability_headerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReliability_header(this);
}


antlrcpp::Any SPECTREParser::Reliability_headerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitReliability_header(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Reliability_headerContext* SPECTREParser::reliability_header() {
  Reliability_headerContext *_localctx = _tracker.createInstance<Reliability_headerContext>(_ctx, getState());
  enterRule(_localctx, 182, SPECTREParser::RuleReliability_header);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2059);
    match(SPECTREParser::ID);
    setState(2060);
    match(SPECTREParser::RELIABILITY);
    setState(2062);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SPECTREParser::SECTION)
      | (1ULL << SPECTREParser::SAVE)
      | (1ULL << SPECTREParser::PORTS)
      | (1ULL << SPECTREParser::DC))) != 0) || _la == SPECTREParser::DELAY || _la == SPECTREParser::ID) {
      setState(2061);
      parameter_list();
    }
    setState(2067);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SPECTREParser::NL) {
      setState(2064);
      match(SPECTREParser::NL);
      setState(2069);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(2070);
    match(SPECTREParser::OPEN_CURLY);
    setState(2074);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SPECTREParser::NL) {
      setState(2071);
      match(SPECTREParser::NL);
      setState(2076);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Reliability_contentContext ------------------------------------------------------------------

SPECTREParser::Reliability_contentContext::Reliability_contentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SPECTREParser::Reliability_controlContext* SPECTREParser::Reliability_contentContext::reliability_control() {
  return getRuleContext<SPECTREParser::Reliability_controlContext>(0);
}

SPECTREParser::Netlist_entityContext* SPECTREParser::Reliability_contentContext::netlist_entity() {
  return getRuleContext<SPECTREParser::Netlist_entityContext>(0);
}


size_t SPECTREParser::Reliability_contentContext::getRuleIndex() const {
  return SPECTREParser::RuleReliability_content;
}

void SPECTREParser::Reliability_contentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReliability_content(this);
}

void SPECTREParser::Reliability_contentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReliability_content(this);
}


antlrcpp::Any SPECTREParser::Reliability_contentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitReliability_content(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Reliability_contentContext* SPECTREParser::reliability_content() {
  Reliability_contentContext *_localctx = _tracker.createInstance<Reliability_contentContext>(_ctx, getState());
  enterRule(_localctx, 184, SPECTREParser::RuleReliability_content);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(2079);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 389, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(2077);
      reliability_control();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(2078);
      netlist_entity();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Reliability_footerContext ------------------------------------------------------------------

SPECTREParser::Reliability_footerContext::Reliability_footerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Reliability_footerContext::CLOSE_CURLY() {
  return getToken(SPECTREParser::CLOSE_CURLY, 0);
}

tree::TerminalNode* SPECTREParser::Reliability_footerContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

std::vector<tree::TerminalNode *> SPECTREParser::Reliability_footerContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::Reliability_footerContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::Reliability_footerContext::getRuleIndex() const {
  return SPECTREParser::RuleReliability_footer;
}

void SPECTREParser::Reliability_footerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReliability_footer(this);
}

void SPECTREParser::Reliability_footerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReliability_footer(this);
}


antlrcpp::Any SPECTREParser::Reliability_footerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitReliability_footer(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Reliability_footerContext* SPECTREParser::reliability_footer() {
  Reliability_footerContext *_localctx = _tracker.createInstance<Reliability_footerContext>(_ctx, getState());
  enterRule(_localctx, 186, SPECTREParser::RuleReliability_footer);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(2081);
    match(SPECTREParser::CLOSE_CURLY);
    setState(2089);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 391, _ctx)) {
    case 1: {
      setState(2085);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 390, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(2082);
          match(SPECTREParser::NL); 
        }
        setState(2087);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 390, _ctx);
      }
      break;
    }

    case 2: {
      setState(2088);
      match(SPECTREParser::EOF);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Reliability_controlContext ------------------------------------------------------------------

SPECTREParser::Reliability_controlContext::Reliability_controlContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Reliability_controlContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

SPECTREParser::Parameter_listContext* SPECTREParser::Reliability_controlContext::parameter_list() {
  return getRuleContext<SPECTREParser::Parameter_listContext>(0);
}

tree::TerminalNode* SPECTREParser::Reliability_controlContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

std::vector<tree::TerminalNode *> SPECTREParser::Reliability_controlContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::Reliability_controlContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::Reliability_controlContext::getRuleIndex() const {
  return SPECTREParser::RuleReliability_control;
}

void SPECTREParser::Reliability_controlContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReliability_control(this);
}

void SPECTREParser::Reliability_controlContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReliability_control(this);
}


antlrcpp::Any SPECTREParser::Reliability_controlContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitReliability_control(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Reliability_controlContext* SPECTREParser::reliability_control() {
  Reliability_controlContext *_localctx = _tracker.createInstance<Reliability_controlContext>(_ctx, getState());
  enterRule(_localctx, 188, SPECTREParser::RuleReliability_control);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2091);
    match(SPECTREParser::ID);
    setState(2092);
    parameter_list();
    setState(2100);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SPECTREParser::GLOBAL:
      case SPECTREParser::INCLUDE:
      case SPECTREParser::CPP_INCLUDE:
      case SPECTREParser::AHDL_INCLUDE:
      case SPECTREParser::LIBRARY:
      case SPECTREParser::SECTION:
      case SPECTREParser::SUBCKT:
      case SPECTREParser::INLINE_SUBCKT:
      case SPECTREParser::MODEL:
      case SPECTREParser::SAVE:
      case SPECTREParser::NODESET:
      case SPECTREParser::IC:
      case SPECTREParser::PARAMETERS:
      case SPECTREParser::STATISTICS:
      case SPECTREParser::AC:
      case SPECTREParser::ACMATCH:
      case SPECTREParser::DC:
      case SPECTREParser::DCMATCH:
      case SPECTREParser::ENVLP:
      case SPECTREParser::SP:
      case SPECTREParser::STB:
      case SPECTREParser::SWEEP:
      case SPECTREParser::TDR:
      case SPECTREParser::TRAN:
      case SPECTREParser::XF:
      case SPECTREParser::PAC:
      case SPECTREParser::PDISTO:
      case SPECTREParser::PNOISE:
      case SPECTREParser::PSP:
      case SPECTREParser::PSS:
      case SPECTREParser::PXF:
      case SPECTREParser::PZ:
      case SPECTREParser::QPAC:
      case SPECTREParser::QPNOISE:
      case SPECTREParser::QPSP:
      case SPECTREParser::QPSS:
      case SPECTREParser::QPXF:
      case SPECTREParser::SENS:
      case SPECTREParser::OPEN_ROUND:
      case SPECTREParser::CLOSE_CURLY:
      case SPECTREParser::NUMBER:
      case SPECTREParser::ID:
      case SPECTREParser::NL: {
        setState(2096);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SPECTREParser::NL) {
          setState(2093);
          match(SPECTREParser::NL);
          setState(2098);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case SPECTREParser::EOF: {
        setState(2099);
        match(SPECTREParser::EOF);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Global_declarationsContext ------------------------------------------------------------------

SPECTREParser::Global_declarationsContext::Global_declarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Global_declarationsContext::PARAMETERS() {
  return getToken(SPECTREParser::PARAMETERS, 0);
}

tree::TerminalNode* SPECTREParser::Global_declarationsContext::OPEN_ROUND() {
  return getToken(SPECTREParser::OPEN_ROUND, 0);
}

tree::TerminalNode* SPECTREParser::Global_declarationsContext::CLOSE_ROUND() {
  return getToken(SPECTREParser::CLOSE_ROUND, 0);
}

tree::TerminalNode* SPECTREParser::Global_declarationsContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

std::vector<SPECTREParser::Parameter_list_itemContext *> SPECTREParser::Global_declarationsContext::parameter_list_item() {
  return getRuleContexts<SPECTREParser::Parameter_list_itemContext>();
}

SPECTREParser::Parameter_list_itemContext* SPECTREParser::Global_declarationsContext::parameter_list_item(size_t i) {
  return getRuleContext<SPECTREParser::Parameter_list_itemContext>(i);
}

std::vector<tree::TerminalNode *> SPECTREParser::Global_declarationsContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::Global_declarationsContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::Global_declarationsContext::getRuleIndex() const {
  return SPECTREParser::RuleGlobal_declarations;
}

void SPECTREParser::Global_declarationsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGlobal_declarations(this);
}

void SPECTREParser::Global_declarationsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGlobal_declarations(this);
}


antlrcpp::Any SPECTREParser::Global_declarationsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitGlobal_declarations(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Global_declarationsContext* SPECTREParser::global_declarations() {
  Global_declarationsContext *_localctx = _tracker.createInstance<Global_declarationsContext>(_ctx, getState());
  enterRule(_localctx, 190, SPECTREParser::RuleGlobal_declarations);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(2134);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 400, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(2102);
      match(SPECTREParser::PARAMETERS);
      setState(2103);
      match(SPECTREParser::OPEN_ROUND);
      setState(2105); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(2104);
        parameter_list_item();
        setState(2107); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SPECTREParser::SECTION)
        | (1ULL << SPECTREParser::SAVE)
        | (1ULL << SPECTREParser::PORTS)
        | (1ULL << SPECTREParser::DC))) != 0) || _la == SPECTREParser::DELAY || _la == SPECTREParser::ID);
      setState(2109);
      match(SPECTREParser::CLOSE_ROUND);
      setState(2117);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 396, _ctx)) {
      case 1: {
        setState(2113);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 395, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(2110);
            match(SPECTREParser::NL); 
          }
          setState(2115);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 395, _ctx);
        }
        break;
      }

      case 2: {
        setState(2116);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(2119);
      match(SPECTREParser::PARAMETERS);
      setState(2121); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(2120);
                parameter_list_item();
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(2123); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 397, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(2132);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 399, _ctx)) {
      case 1: {
        setState(2128);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 398, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(2125);
            match(SPECTREParser::NL); 
          }
          setState(2130);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 398, _ctx);
        }
        break;
      }

      case 2: {
        setState(2131);
        match(SPECTREParser::EOF);
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ComponentContext ------------------------------------------------------------------

SPECTREParser::ComponentContext::ComponentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SPECTREParser::Component_idContext* SPECTREParser::ComponentContext::component_id() {
  return getRuleContext<SPECTREParser::Component_idContext>(0);
}

tree::TerminalNode* SPECTREParser::ComponentContext::EOF() {
  return getToken(SPECTREParser::EOF, 0);
}

SPECTREParser::Node_listContext* SPECTREParser::ComponentContext::node_list() {
  return getRuleContext<SPECTREParser::Node_listContext>(0);
}

SPECTREParser::Component_masterContext* SPECTREParser::ComponentContext::component_master() {
  return getRuleContext<SPECTREParser::Component_masterContext>(0);
}

std::vector<SPECTREParser::Component_attributeContext *> SPECTREParser::ComponentContext::component_attribute() {
  return getRuleContexts<SPECTREParser::Component_attributeContext>();
}

SPECTREParser::Component_attributeContext* SPECTREParser::ComponentContext::component_attribute(size_t i) {
  return getRuleContext<SPECTREParser::Component_attributeContext>(i);
}

std::vector<tree::TerminalNode *> SPECTREParser::ComponentContext::NL() {
  return getTokens(SPECTREParser::NL);
}

tree::TerminalNode* SPECTREParser::ComponentContext::NL(size_t i) {
  return getToken(SPECTREParser::NL, i);
}


size_t SPECTREParser::ComponentContext::getRuleIndex() const {
  return SPECTREParser::RuleComponent;
}

void SPECTREParser::ComponentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponent(this);
}

void SPECTREParser::ComponentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponent(this);
}


antlrcpp::Any SPECTREParser::ComponentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitComponent(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::ComponentContext* SPECTREParser::component() {
  ComponentContext *_localctx = _tracker.createInstance<ComponentContext>(_ctx, getState());
  enterRule(_localctx, 192, SPECTREParser::RuleComponent);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(2136);
    component_id();
    setState(2138);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 401, _ctx)) {
    case 1: {
      setState(2137);
      node_list();
      break;
    }

    }
    setState(2141);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 402, _ctx)) {
    case 1: {
      setState(2140);
      component_master();
      break;
    }

    }
    setState(2146);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 403, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(2143);
        component_attribute(); 
      }
      setState(2148);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 403, _ctx);
    }
    setState(2156);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 405, _ctx)) {
    case 1: {
      setState(2152);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 404, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(2149);
          match(SPECTREParser::NL); 
        }
        setState(2154);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 404, _ctx);
      }
      break;
    }

    case 2: {
      setState(2155);
      match(SPECTREParser::EOF);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Component_idContext ------------------------------------------------------------------

SPECTREParser::Component_idContext::Component_idContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Component_idContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}


size_t SPECTREParser::Component_idContext::getRuleIndex() const {
  return SPECTREParser::RuleComponent_id;
}

void SPECTREParser::Component_idContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponent_id(this);
}

void SPECTREParser::Component_idContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponent_id(this);
}


antlrcpp::Any SPECTREParser::Component_idContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitComponent_id(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Component_idContext* SPECTREParser::component_id() {
  Component_idContext *_localctx = _tracker.createInstance<Component_idContext>(_ctx, getState());
  enterRule(_localctx, 194, SPECTREParser::RuleComponent_id);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2158);
    match(SPECTREParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Component_masterContext ------------------------------------------------------------------

SPECTREParser::Component_masterContext::Component_masterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Component_masterContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

SPECTREParser::Component_typeContext* SPECTREParser::Component_masterContext::component_type() {
  return getRuleContext<SPECTREParser::Component_typeContext>(0);
}


size_t SPECTREParser::Component_masterContext::getRuleIndex() const {
  return SPECTREParser::RuleComponent_master;
}

void SPECTREParser::Component_masterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponent_master(this);
}

void SPECTREParser::Component_masterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponent_master(this);
}


antlrcpp::Any SPECTREParser::Component_masterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitComponent_master(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Component_masterContext* SPECTREParser::component_master() {
  Component_masterContext *_localctx = _tracker.createInstance<Component_masterContext>(_ctx, getState());
  enterRule(_localctx, 196, SPECTREParser::RuleComponent_master);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(2162);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SPECTREParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(2160);
        match(SPECTREParser::ID);
        break;
      }

      case SPECTREParser::A2D:
      case SPECTREParser::B3SOIPD:
      case SPECTREParser::BJT:
      case SPECTREParser::BJT301:
      case SPECTREParser::BJT500:
      case SPECTREParser::BJT503:
      case SPECTREParser::BJT504:
      case SPECTREParser::BJT504T:
      case SPECTREParser::BSIM1:
      case SPECTREParser::BSIM2:
      case SPECTREParser::BSIM3:
      case SPECTREParser::BSIM3V3:
      case SPECTREParser::BSIM4:
      case SPECTREParser::BSIMSOI:
      case SPECTREParser::BTASOI:
      case SPECTREParser::CAPACITOR:
      case SPECTREParser::CCCS:
      case SPECTREParser::CCVS:
      case SPECTREParser::CKTROM:
      case SPECTREParser::CORE:
      case SPECTREParser::D2A:
      case SPECTREParser::DELAY:
      case SPECTREParser::DIO500:
      case SPECTREParser::DIODE:
      case SPECTREParser::EKV:
      case SPECTREParser::FOURIER:
      case SPECTREParser::GAAS:
      case SPECTREParser::HBT:
      case SPECTREParser::HISIM:
      case SPECTREParser::HVMOS:
      case SPECTREParser::INDUCTOR:
      case SPECTREParser::INTCAP:
      case SPECTREParser::IPROBE:
      case SPECTREParser::ISOURCE:
      case SPECTREParser::JFET:
      case SPECTREParser::JUNCAP:
      case SPECTREParser::MISNAN:
      case SPECTREParser::MOS11011:
      case SPECTREParser::MOS11010:
      case SPECTREParser::MOS3002:
      case SPECTREParser::MOS3100:
      case SPECTREParser::MOS1000:
      case SPECTREParser::MOS1100:
      case SPECTREParser::MUTUAL_INDUCTOR:
      case SPECTREParser::MSLINE:
      case SPECTREParser::MTLINE:
      case SPECTREParser::MOS705:
      case SPECTREParser::MOS902:
      case SPECTREParser::MOS903:
      case SPECTREParser::MOS30:
      case SPECTREParser::MOS40:
      case SPECTREParser::MOS15:
      case SPECTREParser::MOS0:
      case SPECTREParser::MOS1:
      case SPECTREParser::MOS2:
      case SPECTREParser::MOS3:
      case SPECTREParser::NODCAP:
      case SPECTREParser::NODE:
      case SPECTREParser::NPORT:
      case SPECTREParser::PARAMTEST:
      case SPECTREParser::PCCCS:
      case SPECTREParser::PCCVS:
      case SPECTREParser::PHY_RES:
      case SPECTREParser::PORT:
      case SPECTREParser::PSITFT:
      case SPECTREParser::PVCCS:
      case SPECTREParser::PVCVS:
      case SPECTREParser::QUANTITY:
      case SPECTREParser::RDIFF:
      case SPECTREParser::RELAY:
      case SPECTREParser::RESISTOR:
      case SPECTREParser::SCCCS:
      case SPECTREParser::SCCVS:
      case SPECTREParser::SVCCS:
      case SPECTREParser::SVCVS:
      case SPECTREParser::SWITCH:
      case SPECTREParser::TLINE:
      case SPECTREParser::TOM2:
      case SPECTREParser::TOM3:
      case SPECTREParser::TRANSFORMER:
      case SPECTREParser::VBIC:
      case SPECTREParser::VCCS:
      case SPECTREParser::VCVS:
      case SPECTREParser::VSOURCE:
      case SPECTREParser::WINDING:
      case SPECTREParser::ZCCCS:
      case SPECTREParser::ZCCVS:
      case SPECTREParser::ZVCCS:
      case SPECTREParser::ZVCVS:
      case SPECTREParser::BSOURCE: {
        enterOuterAlt(_localctx, 2);
        setState(2161);
        component_type();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Component_attributeContext ------------------------------------------------------------------

SPECTREParser::Component_attributeContext::Component_attributeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SPECTREParser::Parameter_assignContext *> SPECTREParser::Component_attributeContext::parameter_assign() {
  return getRuleContexts<SPECTREParser::Parameter_assignContext>();
}

SPECTREParser::Parameter_assignContext* SPECTREParser::Component_attributeContext::parameter_assign(size_t i) {
  return getRuleContext<SPECTREParser::Parameter_assignContext>(i);
}

std::vector<SPECTREParser::Component_analysisContext *> SPECTREParser::Component_attributeContext::component_analysis() {
  return getRuleContexts<SPECTREParser::Component_analysisContext>();
}

SPECTREParser::Component_analysisContext* SPECTREParser::Component_attributeContext::component_analysis(size_t i) {
  return getRuleContext<SPECTREParser::Component_analysisContext>(i);
}

std::vector<SPECTREParser::Component_value_listContext *> SPECTREParser::Component_attributeContext::component_value_list() {
  return getRuleContexts<SPECTREParser::Component_value_listContext>();
}

SPECTREParser::Component_value_listContext* SPECTREParser::Component_attributeContext::component_value_list(size_t i) {
  return getRuleContext<SPECTREParser::Component_value_listContext>(i);
}

std::vector<SPECTREParser::Component_valueContext *> SPECTREParser::Component_attributeContext::component_value() {
  return getRuleContexts<SPECTREParser::Component_valueContext>();
}

SPECTREParser::Component_valueContext* SPECTREParser::Component_attributeContext::component_value(size_t i) {
  return getRuleContext<SPECTREParser::Component_valueContext>(i);
}


size_t SPECTREParser::Component_attributeContext::getRuleIndex() const {
  return SPECTREParser::RuleComponent_attribute;
}

void SPECTREParser::Component_attributeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponent_attribute(this);
}

void SPECTREParser::Component_attributeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponent_attribute(this);
}


antlrcpp::Any SPECTREParser::Component_attributeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitComponent_attribute(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Component_attributeContext* SPECTREParser::component_attribute() {
  Component_attributeContext *_localctx = _tracker.createInstance<Component_attributeContext>(_ctx, getState());
  enterRule(_localctx, 198, SPECTREParser::RuleComponent_attribute);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(2168); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(2168);
              _errHandler->sync(this);
              switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 407, _ctx)) {
              case 1: {
                setState(2164);
                parameter_assign();
                break;
              }

              case 2: {
                setState(2165);
                component_analysis();
                break;
              }

              case 3: {
                setState(2166);
                component_value_list();
                break;
              }

              case 4: {
                setState(2167);
                component_value();
                break;
              }

              }
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(2170); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 408, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Component_valueContext ------------------------------------------------------------------

SPECTREParser::Component_valueContext::Component_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Component_valueContext::STRING() {
  return getToken(SPECTREParser::STRING, 0);
}

SPECTREParser::ExpressionContext* SPECTREParser::Component_valueContext::expression() {
  return getRuleContext<SPECTREParser::ExpressionContext>(0);
}

tree::TerminalNode* SPECTREParser::Component_valueContext::OPEN_CURLY() {
  return getToken(SPECTREParser::OPEN_CURLY, 0);
}

tree::TerminalNode* SPECTREParser::Component_valueContext::CLOSE_CURLY() {
  return getToken(SPECTREParser::CLOSE_CURLY, 0);
}


size_t SPECTREParser::Component_valueContext::getRuleIndex() const {
  return SPECTREParser::RuleComponent_value;
}

void SPECTREParser::Component_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponent_value(this);
}

void SPECTREParser::Component_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponent_value(this);
}


antlrcpp::Any SPECTREParser::Component_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitComponent_value(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Component_valueContext* SPECTREParser::component_value() {
  Component_valueContext *_localctx = _tracker.createInstance<Component_valueContext>(_ctx, getState());
  enterRule(_localctx, 200, SPECTREParser::RuleComponent_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2173);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 409, _ctx)) {
    case 1: {
      setState(2172);
      match(SPECTREParser::OPEN_CURLY);
      break;
    }

    }
    setState(2177);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 410, _ctx)) {
    case 1: {
      setState(2175);
      match(SPECTREParser::STRING);
      break;
    }

    case 2: {
      setState(2176);
      expression(0);
      break;
    }

    }
    setState(2180);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 411, _ctx)) {
    case 1: {
      setState(2179);
      match(SPECTREParser::CLOSE_CURLY);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Component_value_listContext ------------------------------------------------------------------

SPECTREParser::Component_value_listContext::Component_value_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Component_value_listContext::OPEN_ROUND() {
  return getToken(SPECTREParser::OPEN_ROUND, 0);
}

tree::TerminalNode* SPECTREParser::Component_value_listContext::CLOSE_ROUND() {
  return getToken(SPECTREParser::CLOSE_ROUND, 0);
}

tree::TerminalNode* SPECTREParser::Component_value_listContext::PWL() {
  return getToken(SPECTREParser::PWL, 0);
}

tree::TerminalNode* SPECTREParser::Component_value_listContext::SIN() {
  return getToken(SPECTREParser::SIN, 0);
}

tree::TerminalNode* SPECTREParser::Component_value_listContext::SFFM() {
  return getToken(SPECTREParser::SFFM, 0);
}

tree::TerminalNode* SPECTREParser::Component_value_listContext::PULSE() {
  return getToken(SPECTREParser::PULSE, 0);
}

tree::TerminalNode* SPECTREParser::Component_value_listContext::WAVE() {
  return getToken(SPECTREParser::WAVE, 0);
}

tree::TerminalNode* SPECTREParser::Component_value_listContext::COEFFS() {
  return getToken(SPECTREParser::COEFFS, 0);
}

tree::TerminalNode* SPECTREParser::Component_value_listContext::EQUAL() {
  return getToken(SPECTREParser::EQUAL, 0);
}

std::vector<SPECTREParser::Time_pairContext *> SPECTREParser::Component_value_listContext::time_pair() {
  return getRuleContexts<SPECTREParser::Time_pairContext>();
}

SPECTREParser::Time_pairContext* SPECTREParser::Component_value_listContext::time_pair(size_t i) {
  return getRuleContext<SPECTREParser::Time_pairContext>(i);
}

std::vector<SPECTREParser::ExpressionContext *> SPECTREParser::Component_value_listContext::expression() {
  return getRuleContexts<SPECTREParser::ExpressionContext>();
}

SPECTREParser::ExpressionContext* SPECTREParser::Component_value_listContext::expression(size_t i) {
  return getRuleContext<SPECTREParser::ExpressionContext>(i);
}

tree::TerminalNode* SPECTREParser::Component_value_listContext::OPEN_SQUARE() {
  return getToken(SPECTREParser::OPEN_SQUARE, 0);
}

tree::TerminalNode* SPECTREParser::Component_value_listContext::CLOSE_SQUARE() {
  return getToken(SPECTREParser::CLOSE_SQUARE, 0);
}

std::vector<tree::TerminalNode *> SPECTREParser::Component_value_listContext::OPEN_CURLY() {
  return getTokens(SPECTREParser::OPEN_CURLY);
}

tree::TerminalNode* SPECTREParser::Component_value_listContext::OPEN_CURLY(size_t i) {
  return getToken(SPECTREParser::OPEN_CURLY, i);
}


size_t SPECTREParser::Component_value_listContext::getRuleIndex() const {
  return SPECTREParser::RuleComponent_value_list;
}

void SPECTREParser::Component_value_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponent_value_list(this);
}

void SPECTREParser::Component_value_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponent_value_list(this);
}


antlrcpp::Any SPECTREParser::Component_value_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitComponent_value_list(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Component_value_listContext* SPECTREParser::component_value_list() {
  Component_value_listContext *_localctx = _tracker.createInstance<Component_value_listContext>(_ctx, getState());
  enterRule(_localctx, 202, SPECTREParser::RuleComponent_value_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(2239);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 424, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(2182);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SPECTREParser::WAVE)
        | (1ULL << SPECTREParser::PWL)
        | (1ULL << SPECTREParser::SIN)
        | (1ULL << SPECTREParser::SFFM)
        | (1ULL << SPECTREParser::PULSE)
        | (1ULL << SPECTREParser::COEFFS))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(2184);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SPECTREParser::EQUAL) {
        setState(2183);
        match(SPECTREParser::EQUAL);
      }
      setState(2186);
      match(SPECTREParser::OPEN_ROUND);
      setState(2197);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 415, _ctx)) {
      case 1: {
        setState(2188); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(2187);
          time_pair();
          setState(2190); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << SPECTREParser::ALTER)
          | (1ULL << SPECTREParser::ALTERGROUP)
          | (1ULL << SPECTREParser::OPTIONS)
          | (1ULL << SPECTREParser::SET)
          | (1ULL << SPECTREParser::SHELL)
          | (1ULL << SPECTREParser::INFO)
          | (1ULL << SPECTREParser::NODESET)
          | (1ULL << SPECTREParser::IC)
          | (1ULL << SPECTREParser::ASSERT)
          | (1ULL << SPECTREParser::CHECK)
          | (1ULL << SPECTREParser::LANGUAGE)
          | (1ULL << SPECTREParser::PORTS)
          | (1ULL << SPECTREParser::WAVE)
          | (1ULL << SPECTREParser::PWL)
          | (1ULL << SPECTREParser::SIN)
          | (1ULL << SPECTREParser::SFFM)
          | (1ULL << SPECTREParser::PULSE)
          | (1ULL << SPECTREParser::COEFFS)
          | (1ULL << SPECTREParser::INSENSITIVE)
          | (1ULL << SPECTREParser::IF)
          | (1ULL << SPECTREParser::ELSE)
          | (1ULL << SPECTREParser::PARAMETERS)
          | (1ULL << SPECTREParser::ANALOGMODEL)
          | (1ULL << SPECTREParser::CHECKPOINT)
          | (1ULL << SPECTREParser::SPECTRE)
          | (1ULL << SPECTREParser::SPICE)
          | (1ULL << SPECTREParser::STATISTICS)
          | (1ULL << SPECTREParser::PROCESS)
          | (1ULL << SPECTREParser::CORRELATE)
          | (1ULL << SPECTREParser::TRUNCATE)
          | (1ULL << SPECTREParser::MISMATCH)
          | (1ULL << SPECTREParser::VARY)
          | (1ULL << SPECTREParser::RELIABILITY)
          | (1ULL << SPECTREParser::AC)
          | (1ULL << SPECTREParser::ACMATCH)
          | (1ULL << SPECTREParser::DC)
          | (1ULL << SPECTREParser::DCMATCH)
          | (1ULL << SPECTREParser::ENVLP)
          | (1ULL << SPECTREParser::SP)
          | (1ULL << SPECTREParser::STB)
          | (1ULL << SPECTREParser::SWEEP)
          | (1ULL << SPECTREParser::TDR)
          | (1ULL << SPECTREParser::TRAN)
          | (1ULL << SPECTREParser::XF)
          | (1ULL << SPECTREParser::PAC)
          | (1ULL << SPECTREParser::PDISTO))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 64)) & ((1ULL << (SPECTREParser::PNOISE - 64))
          | (1ULL << (SPECTREParser::PSP - 64))
          | (1ULL << (SPECTREParser::PSS - 64))
          | (1ULL << (SPECTREParser::PXF - 64))
          | (1ULL << (SPECTREParser::PZ - 64))
          | (1ULL << (SPECTREParser::QPAC - 64))
          | (1ULL << (SPECTREParser::QPNOISE - 64))
          | (1ULL << (SPECTREParser::QPSP - 64))
          | (1ULL << (SPECTREParser::QPSS - 64))
          | (1ULL << (SPECTREParser::QPXF - 64))
          | (1ULL << (SPECTREParser::SENS - 64))
          | (1ULL << (SPECTREParser::MONTECARLO - 64))
          | (1ULL << (SPECTREParser::NOISE - 64))
          | (1ULL << (SPECTREParser::CHECKLIMIT - 64))
          | (1ULL << (SPECTREParser::A2D - 64))
          | (1ULL << (SPECTREParser::B3SOIPD - 64))
          | (1ULL << (SPECTREParser::BJT - 64))
          | (1ULL << (SPECTREParser::BJT301 - 64))
          | (1ULL << (SPECTREParser::BJT500 - 64))
          | (1ULL << (SPECTREParser::BJT503 - 64))
          | (1ULL << (SPECTREParser::BJT504 - 64))
          | (1ULL << (SPECTREParser::BJT504T - 64))
          | (1ULL << (SPECTREParser::BSIM1 - 64))
          | (1ULL << (SPECTREParser::BSIM2 - 64))
          | (1ULL << (SPECTREParser::BSIM3 - 64))
          | (1ULL << (SPECTREParser::BSIM3V3 - 64))
          | (1ULL << (SPECTREParser::BSIM4 - 64))
          | (1ULL << (SPECTREParser::BSIMSOI - 64))
          | (1ULL << (SPECTREParser::BTASOI - 64))
          | (1ULL << (SPECTREParser::CAPACITOR - 64))
          | (1ULL << (SPECTREParser::CCCS - 64))
          | (1ULL << (SPECTREParser::CCVS - 64))
          | (1ULL << (SPECTREParser::CKTROM - 64))
          | (1ULL << (SPECTREParser::CORE - 64))
          | (1ULL << (SPECTREParser::D2A - 64))
          | (1ULL << (SPECTREParser::DELAY - 64))
          | (1ULL << (SPECTREParser::DIO500 - 64))
          | (1ULL << (SPECTREParser::DIODE - 64))
          | (1ULL << (SPECTREParser::EKV - 64))
          | (1ULL << (SPECTREParser::FOURIER - 64))
          | (1ULL << (SPECTREParser::GAAS - 64))
          | (1ULL << (SPECTREParser::HBT - 64))
          | (1ULL << (SPECTREParser::HISIM - 64))
          | (1ULL << (SPECTREParser::HVMOS - 64))
          | (1ULL << (SPECTREParser::INDUCTOR - 64))
          | (1ULL << (SPECTREParser::INTCAP - 64))
          | (1ULL << (SPECTREParser::IPROBE - 64))
          | (1ULL << (SPECTREParser::ISOURCE - 64))
          | (1ULL << (SPECTREParser::JFET - 64))
          | (1ULL << (SPECTREParser::JUNCAP - 64))
          | (1ULL << (SPECTREParser::MISNAN - 64))
          | (1ULL << (SPECTREParser::MOS11011 - 64))
          | (1ULL << (SPECTREParser::MOS11010 - 64))
          | (1ULL << (SPECTREParser::MOS3002 - 64))
          | (1ULL << (SPECTREParser::MOS3100 - 64))
          | (1ULL << (SPECTREParser::MOS1000 - 64))
          | (1ULL << (SPECTREParser::MOS1100 - 64))
          | (1ULL << (SPECTREParser::MUTUAL_INDUCTOR - 64))
          | (1ULL << (SPECTREParser::MSLINE - 64))
          | (1ULL << (SPECTREParser::MTLINE - 64))
          | (1ULL << (SPECTREParser::MOS705 - 64))
          | (1ULL << (SPECTREParser::MOS902 - 64))
          | (1ULL << (SPECTREParser::MOS903 - 64))
          | (1ULL << (SPECTREParser::MOS30 - 64)))) != 0) || ((((_la - 128) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 128)) & ((1ULL << (SPECTREParser::MOS40 - 128))
          | (1ULL << (SPECTREParser::MOS15 - 128))
          | (1ULL << (SPECTREParser::MOS0 - 128))
          | (1ULL << (SPECTREParser::MOS1 - 128))
          | (1ULL << (SPECTREParser::MOS2 - 128))
          | (1ULL << (SPECTREParser::MOS3 - 128))
          | (1ULL << (SPECTREParser::NODCAP - 128))
          | (1ULL << (SPECTREParser::NODE - 128))
          | (1ULL << (SPECTREParser::NPORT - 128))
          | (1ULL << (SPECTREParser::PARAMTEST - 128))
          | (1ULL << (SPECTREParser::PCCCS - 128))
          | (1ULL << (SPECTREParser::PCCVS - 128))
          | (1ULL << (SPECTREParser::PHY_RES - 128))
          | (1ULL << (SPECTREParser::PORT - 128))
          | (1ULL << (SPECTREParser::PSITFT - 128))
          | (1ULL << (SPECTREParser::PVCCS - 128))
          | (1ULL << (SPECTREParser::PVCVS - 128))
          | (1ULL << (SPECTREParser::QUANTITY - 128))
          | (1ULL << (SPECTREParser::RDIFF - 128))
          | (1ULL << (SPECTREParser::RELAY - 128))
          | (1ULL << (SPECTREParser::RESISTOR - 128))
          | (1ULL << (SPECTREParser::SCCCS - 128))
          | (1ULL << (SPECTREParser::SCCVS - 128))
          | (1ULL << (SPECTREParser::SVCCS - 128))
          | (1ULL << (SPECTREParser::SVCVS - 128))
          | (1ULL << (SPECTREParser::SWITCH - 128))
          | (1ULL << (SPECTREParser::TLINE - 128))
          | (1ULL << (SPECTREParser::TOM2 - 128))
          | (1ULL << (SPECTREParser::TOM3 - 128))
          | (1ULL << (SPECTREParser::TRANSFORMER - 128))
          | (1ULL << (SPECTREParser::VBIC - 128))
          | (1ULL << (SPECTREParser::VCCS - 128))
          | (1ULL << (SPECTREParser::VCVS - 128))
          | (1ULL << (SPECTREParser::VSOURCE - 128))
          | (1ULL << (SPECTREParser::WINDING - 128))
          | (1ULL << (SPECTREParser::ZCCCS - 128))
          | (1ULL << (SPECTREParser::ZCCVS - 128))
          | (1ULL << (SPECTREParser::ZVCCS - 128))
          | (1ULL << (SPECTREParser::ZVCVS - 128))
          | (1ULL << (SPECTREParser::BSOURCE - 128))
          | (1ULL << (SPECTREParser::PLUS - 128))
          | (1ULL << (SPECTREParser::MINUS - 128))
          | (1ULL << (SPECTREParser::OPEN_ROUND - 128)))) != 0) || ((((_la - 195) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 195)) & ((1ULL << (SPECTREParser::OPEN_CURLY - 195))
          | (1ULL << (SPECTREParser::APEX - 195))
          | (1ULL << (SPECTREParser::NUMBER - 195))
          | (1ULL << (SPECTREParser::ID - 195))
          | (1ULL << (SPECTREParser::STRING - 195))
          | (1ULL << (SPECTREParser::PERCENTAGE - 195)))) != 0));
        break;
      }

      case 2: {
        setState(2193); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(2192);
          expression(0);
          setState(2195); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << SPECTREParser::ALTER)
          | (1ULL << SPECTREParser::ALTERGROUP)
          | (1ULL << SPECTREParser::OPTIONS)
          | (1ULL << SPECTREParser::SET)
          | (1ULL << SPECTREParser::SHELL)
          | (1ULL << SPECTREParser::INFO)
          | (1ULL << SPECTREParser::NODESET)
          | (1ULL << SPECTREParser::IC)
          | (1ULL << SPECTREParser::ASSERT)
          | (1ULL << SPECTREParser::CHECK)
          | (1ULL << SPECTREParser::LANGUAGE)
          | (1ULL << SPECTREParser::PORTS)
          | (1ULL << SPECTREParser::WAVE)
          | (1ULL << SPECTREParser::PWL)
          | (1ULL << SPECTREParser::SIN)
          | (1ULL << SPECTREParser::SFFM)
          | (1ULL << SPECTREParser::PULSE)
          | (1ULL << SPECTREParser::COEFFS)
          | (1ULL << SPECTREParser::INSENSITIVE)
          | (1ULL << SPECTREParser::IF)
          | (1ULL << SPECTREParser::ELSE)
          | (1ULL << SPECTREParser::PARAMETERS)
          | (1ULL << SPECTREParser::ANALOGMODEL)
          | (1ULL << SPECTREParser::CHECKPOINT)
          | (1ULL << SPECTREParser::SPECTRE)
          | (1ULL << SPECTREParser::SPICE)
          | (1ULL << SPECTREParser::STATISTICS)
          | (1ULL << SPECTREParser::PROCESS)
          | (1ULL << SPECTREParser::CORRELATE)
          | (1ULL << SPECTREParser::TRUNCATE)
          | (1ULL << SPECTREParser::MISMATCH)
          | (1ULL << SPECTREParser::VARY)
          | (1ULL << SPECTREParser::RELIABILITY)
          | (1ULL << SPECTREParser::AC)
          | (1ULL << SPECTREParser::ACMATCH)
          | (1ULL << SPECTREParser::DC)
          | (1ULL << SPECTREParser::DCMATCH)
          | (1ULL << SPECTREParser::ENVLP)
          | (1ULL << SPECTREParser::SP)
          | (1ULL << SPECTREParser::STB)
          | (1ULL << SPECTREParser::SWEEP)
          | (1ULL << SPECTREParser::TDR)
          | (1ULL << SPECTREParser::TRAN)
          | (1ULL << SPECTREParser::XF)
          | (1ULL << SPECTREParser::PAC)
          | (1ULL << SPECTREParser::PDISTO))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 64)) & ((1ULL << (SPECTREParser::PNOISE - 64))
          | (1ULL << (SPECTREParser::PSP - 64))
          | (1ULL << (SPECTREParser::PSS - 64))
          | (1ULL << (SPECTREParser::PXF - 64))
          | (1ULL << (SPECTREParser::PZ - 64))
          | (1ULL << (SPECTREParser::QPAC - 64))
          | (1ULL << (SPECTREParser::QPNOISE - 64))
          | (1ULL << (SPECTREParser::QPSP - 64))
          | (1ULL << (SPECTREParser::QPSS - 64))
          | (1ULL << (SPECTREParser::QPXF - 64))
          | (1ULL << (SPECTREParser::SENS - 64))
          | (1ULL << (SPECTREParser::MONTECARLO - 64))
          | (1ULL << (SPECTREParser::NOISE - 64))
          | (1ULL << (SPECTREParser::CHECKLIMIT - 64))
          | (1ULL << (SPECTREParser::A2D - 64))
          | (1ULL << (SPECTREParser::B3SOIPD - 64))
          | (1ULL << (SPECTREParser::BJT - 64))
          | (1ULL << (SPECTREParser::BJT301 - 64))
          | (1ULL << (SPECTREParser::BJT500 - 64))
          | (1ULL << (SPECTREParser::BJT503 - 64))
          | (1ULL << (SPECTREParser::BJT504 - 64))
          | (1ULL << (SPECTREParser::BJT504T - 64))
          | (1ULL << (SPECTREParser::BSIM1 - 64))
          | (1ULL << (SPECTREParser::BSIM2 - 64))
          | (1ULL << (SPECTREParser::BSIM3 - 64))
          | (1ULL << (SPECTREParser::BSIM3V3 - 64))
          | (1ULL << (SPECTREParser::BSIM4 - 64))
          | (1ULL << (SPECTREParser::BSIMSOI - 64))
          | (1ULL << (SPECTREParser::BTASOI - 64))
          | (1ULL << (SPECTREParser::CAPACITOR - 64))
          | (1ULL << (SPECTREParser::CCCS - 64))
          | (1ULL << (SPECTREParser::CCVS - 64))
          | (1ULL << (SPECTREParser::CKTROM - 64))
          | (1ULL << (SPECTREParser::CORE - 64))
          | (1ULL << (SPECTREParser::D2A - 64))
          | (1ULL << (SPECTREParser::DELAY - 64))
          | (1ULL << (SPECTREParser::DIO500 - 64))
          | (1ULL << (SPECTREParser::DIODE - 64))
          | (1ULL << (SPECTREParser::EKV - 64))
          | (1ULL << (SPECTREParser::FOURIER - 64))
          | (1ULL << (SPECTREParser::GAAS - 64))
          | (1ULL << (SPECTREParser::HBT - 64))
          | (1ULL << (SPECTREParser::HISIM - 64))
          | (1ULL << (SPECTREParser::HVMOS - 64))
          | (1ULL << (SPECTREParser::INDUCTOR - 64))
          | (1ULL << (SPECTREParser::INTCAP - 64))
          | (1ULL << (SPECTREParser::IPROBE - 64))
          | (1ULL << (SPECTREParser::ISOURCE - 64))
          | (1ULL << (SPECTREParser::JFET - 64))
          | (1ULL << (SPECTREParser::JUNCAP - 64))
          | (1ULL << (SPECTREParser::MISNAN - 64))
          | (1ULL << (SPECTREParser::MOS11011 - 64))
          | (1ULL << (SPECTREParser::MOS11010 - 64))
          | (1ULL << (SPECTREParser::MOS3002 - 64))
          | (1ULL << (SPECTREParser::MOS3100 - 64))
          | (1ULL << (SPECTREParser::MOS1000 - 64))
          | (1ULL << (SPECTREParser::MOS1100 - 64))
          | (1ULL << (SPECTREParser::MUTUAL_INDUCTOR - 64))
          | (1ULL << (SPECTREParser::MSLINE - 64))
          | (1ULL << (SPECTREParser::MTLINE - 64))
          | (1ULL << (SPECTREParser::MOS705 - 64))
          | (1ULL << (SPECTREParser::MOS902 - 64))
          | (1ULL << (SPECTREParser::MOS903 - 64))
          | (1ULL << (SPECTREParser::MOS30 - 64)))) != 0) || ((((_la - 128) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 128)) & ((1ULL << (SPECTREParser::MOS40 - 128))
          | (1ULL << (SPECTREParser::MOS15 - 128))
          | (1ULL << (SPECTREParser::MOS0 - 128))
          | (1ULL << (SPECTREParser::MOS1 - 128))
          | (1ULL << (SPECTREParser::MOS2 - 128))
          | (1ULL << (SPECTREParser::MOS3 - 128))
          | (1ULL << (SPECTREParser::NODCAP - 128))
          | (1ULL << (SPECTREParser::NODE - 128))
          | (1ULL << (SPECTREParser::NPORT - 128))
          | (1ULL << (SPECTREParser::PARAMTEST - 128))
          | (1ULL << (SPECTREParser::PCCCS - 128))
          | (1ULL << (SPECTREParser::PCCVS - 128))
          | (1ULL << (SPECTREParser::PHY_RES - 128))
          | (1ULL << (SPECTREParser::PORT - 128))
          | (1ULL << (SPECTREParser::PSITFT - 128))
          | (1ULL << (SPECTREParser::PVCCS - 128))
          | (1ULL << (SPECTREParser::PVCVS - 128))
          | (1ULL << (SPECTREParser::QUANTITY - 128))
          | (1ULL << (SPECTREParser::RDIFF - 128))
          | (1ULL << (SPECTREParser::RELAY - 128))
          | (1ULL << (SPECTREParser::RESISTOR - 128))
          | (1ULL << (SPECTREParser::SCCCS - 128))
          | (1ULL << (SPECTREParser::SCCVS - 128))
          | (1ULL << (SPECTREParser::SVCCS - 128))
          | (1ULL << (SPECTREParser::SVCVS - 128))
          | (1ULL << (SPECTREParser::SWITCH - 128))
          | (1ULL << (SPECTREParser::TLINE - 128))
          | (1ULL << (SPECTREParser::TOM2 - 128))
          | (1ULL << (SPECTREParser::TOM3 - 128))
          | (1ULL << (SPECTREParser::TRANSFORMER - 128))
          | (1ULL << (SPECTREParser::VBIC - 128))
          | (1ULL << (SPECTREParser::VCCS - 128))
          | (1ULL << (SPECTREParser::VCVS - 128))
          | (1ULL << (SPECTREParser::VSOURCE - 128))
          | (1ULL << (SPECTREParser::WINDING - 128))
          | (1ULL << (SPECTREParser::ZCCCS - 128))
          | (1ULL << (SPECTREParser::ZCCVS - 128))
          | (1ULL << (SPECTREParser::ZVCCS - 128))
          | (1ULL << (SPECTREParser::ZVCVS - 128))
          | (1ULL << (SPECTREParser::BSOURCE - 128))
          | (1ULL << (SPECTREParser::PLUS - 128))
          | (1ULL << (SPECTREParser::MINUS - 128))
          | (1ULL << (SPECTREParser::OPEN_ROUND - 128)))) != 0) || ((((_la - 195) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 195)) & ((1ULL << (SPECTREParser::OPEN_CURLY - 195))
          | (1ULL << (SPECTREParser::APEX - 195))
          | (1ULL << (SPECTREParser::NUMBER - 195))
          | (1ULL << (SPECTREParser::ID - 195))
          | (1ULL << (SPECTREParser::STRING - 195))
          | (1ULL << (SPECTREParser::PERCENTAGE - 195)))) != 0));
        break;
      }

      }
      setState(2199);
      match(SPECTREParser::CLOSE_ROUND);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(2201);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SPECTREParser::WAVE)
        | (1ULL << SPECTREParser::PWL)
        | (1ULL << SPECTREParser::SIN)
        | (1ULL << SPECTREParser::SFFM)
        | (1ULL << SPECTREParser::PULSE)
        | (1ULL << SPECTREParser::COEFFS))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(2203);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SPECTREParser::EQUAL) {
        setState(2202);
        match(SPECTREParser::EQUAL);
      }
      setState(2205);
      match(SPECTREParser::OPEN_SQUARE);
      setState(2216);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 419, _ctx)) {
      case 1: {
        setState(2207); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(2206);
          time_pair();
          setState(2209); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << SPECTREParser::ALTER)
          | (1ULL << SPECTREParser::ALTERGROUP)
          | (1ULL << SPECTREParser::OPTIONS)
          | (1ULL << SPECTREParser::SET)
          | (1ULL << SPECTREParser::SHELL)
          | (1ULL << SPECTREParser::INFO)
          | (1ULL << SPECTREParser::NODESET)
          | (1ULL << SPECTREParser::IC)
          | (1ULL << SPECTREParser::ASSERT)
          | (1ULL << SPECTREParser::CHECK)
          | (1ULL << SPECTREParser::LANGUAGE)
          | (1ULL << SPECTREParser::PORTS)
          | (1ULL << SPECTREParser::WAVE)
          | (1ULL << SPECTREParser::PWL)
          | (1ULL << SPECTREParser::SIN)
          | (1ULL << SPECTREParser::SFFM)
          | (1ULL << SPECTREParser::PULSE)
          | (1ULL << SPECTREParser::COEFFS)
          | (1ULL << SPECTREParser::INSENSITIVE)
          | (1ULL << SPECTREParser::IF)
          | (1ULL << SPECTREParser::ELSE)
          | (1ULL << SPECTREParser::PARAMETERS)
          | (1ULL << SPECTREParser::ANALOGMODEL)
          | (1ULL << SPECTREParser::CHECKPOINT)
          | (1ULL << SPECTREParser::SPECTRE)
          | (1ULL << SPECTREParser::SPICE)
          | (1ULL << SPECTREParser::STATISTICS)
          | (1ULL << SPECTREParser::PROCESS)
          | (1ULL << SPECTREParser::CORRELATE)
          | (1ULL << SPECTREParser::TRUNCATE)
          | (1ULL << SPECTREParser::MISMATCH)
          | (1ULL << SPECTREParser::VARY)
          | (1ULL << SPECTREParser::RELIABILITY)
          | (1ULL << SPECTREParser::AC)
          | (1ULL << SPECTREParser::ACMATCH)
          | (1ULL << SPECTREParser::DC)
          | (1ULL << SPECTREParser::DCMATCH)
          | (1ULL << SPECTREParser::ENVLP)
          | (1ULL << SPECTREParser::SP)
          | (1ULL << SPECTREParser::STB)
          | (1ULL << SPECTREParser::SWEEP)
          | (1ULL << SPECTREParser::TDR)
          | (1ULL << SPECTREParser::TRAN)
          | (1ULL << SPECTREParser::XF)
          | (1ULL << SPECTREParser::PAC)
          | (1ULL << SPECTREParser::PDISTO))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 64)) & ((1ULL << (SPECTREParser::PNOISE - 64))
          | (1ULL << (SPECTREParser::PSP - 64))
          | (1ULL << (SPECTREParser::PSS - 64))
          | (1ULL << (SPECTREParser::PXF - 64))
          | (1ULL << (SPECTREParser::PZ - 64))
          | (1ULL << (SPECTREParser::QPAC - 64))
          | (1ULL << (SPECTREParser::QPNOISE - 64))
          | (1ULL << (SPECTREParser::QPSP - 64))
          | (1ULL << (SPECTREParser::QPSS - 64))
          | (1ULL << (SPECTREParser::QPXF - 64))
          | (1ULL << (SPECTREParser::SENS - 64))
          | (1ULL << (SPECTREParser::MONTECARLO - 64))
          | (1ULL << (SPECTREParser::NOISE - 64))
          | (1ULL << (SPECTREParser::CHECKLIMIT - 64))
          | (1ULL << (SPECTREParser::A2D - 64))
          | (1ULL << (SPECTREParser::B3SOIPD - 64))
          | (1ULL << (SPECTREParser::BJT - 64))
          | (1ULL << (SPECTREParser::BJT301 - 64))
          | (1ULL << (SPECTREParser::BJT500 - 64))
          | (1ULL << (SPECTREParser::BJT503 - 64))
          | (1ULL << (SPECTREParser::BJT504 - 64))
          | (1ULL << (SPECTREParser::BJT504T - 64))
          | (1ULL << (SPECTREParser::BSIM1 - 64))
          | (1ULL << (SPECTREParser::BSIM2 - 64))
          | (1ULL << (SPECTREParser::BSIM3 - 64))
          | (1ULL << (SPECTREParser::BSIM3V3 - 64))
          | (1ULL << (SPECTREParser::BSIM4 - 64))
          | (1ULL << (SPECTREParser::BSIMSOI - 64))
          | (1ULL << (SPECTREParser::BTASOI - 64))
          | (1ULL << (SPECTREParser::CAPACITOR - 64))
          | (1ULL << (SPECTREParser::CCCS - 64))
          | (1ULL << (SPECTREParser::CCVS - 64))
          | (1ULL << (SPECTREParser::CKTROM - 64))
          | (1ULL << (SPECTREParser::CORE - 64))
          | (1ULL << (SPECTREParser::D2A - 64))
          | (1ULL << (SPECTREParser::DELAY - 64))
          | (1ULL << (SPECTREParser::DIO500 - 64))
          | (1ULL << (SPECTREParser::DIODE - 64))
          | (1ULL << (SPECTREParser::EKV - 64))
          | (1ULL << (SPECTREParser::FOURIER - 64))
          | (1ULL << (SPECTREParser::GAAS - 64))
          | (1ULL << (SPECTREParser::HBT - 64))
          | (1ULL << (SPECTREParser::HISIM - 64))
          | (1ULL << (SPECTREParser::HVMOS - 64))
          | (1ULL << (SPECTREParser::INDUCTOR - 64))
          | (1ULL << (SPECTREParser::INTCAP - 64))
          | (1ULL << (SPECTREParser::IPROBE - 64))
          | (1ULL << (SPECTREParser::ISOURCE - 64))
          | (1ULL << (SPECTREParser::JFET - 64))
          | (1ULL << (SPECTREParser::JUNCAP - 64))
          | (1ULL << (SPECTREParser::MISNAN - 64))
          | (1ULL << (SPECTREParser::MOS11011 - 64))
          | (1ULL << (SPECTREParser::MOS11010 - 64))
          | (1ULL << (SPECTREParser::MOS3002 - 64))
          | (1ULL << (SPECTREParser::MOS3100 - 64))
          | (1ULL << (SPECTREParser::MOS1000 - 64))
          | (1ULL << (SPECTREParser::MOS1100 - 64))
          | (1ULL << (SPECTREParser::MUTUAL_INDUCTOR - 64))
          | (1ULL << (SPECTREParser::MSLINE - 64))
          | (1ULL << (SPECTREParser::MTLINE - 64))
          | (1ULL << (SPECTREParser::MOS705 - 64))
          | (1ULL << (SPECTREParser::MOS902 - 64))
          | (1ULL << (SPECTREParser::MOS903 - 64))
          | (1ULL << (SPECTREParser::MOS30 - 64)))) != 0) || ((((_la - 128) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 128)) & ((1ULL << (SPECTREParser::MOS40 - 128))
          | (1ULL << (SPECTREParser::MOS15 - 128))
          | (1ULL << (SPECTREParser::MOS0 - 128))
          | (1ULL << (SPECTREParser::MOS1 - 128))
          | (1ULL << (SPECTREParser::MOS2 - 128))
          | (1ULL << (SPECTREParser::MOS3 - 128))
          | (1ULL << (SPECTREParser::NODCAP - 128))
          | (1ULL << (SPECTREParser::NODE - 128))
          | (1ULL << (SPECTREParser::NPORT - 128))
          | (1ULL << (SPECTREParser::PARAMTEST - 128))
          | (1ULL << (SPECTREParser::PCCCS - 128))
          | (1ULL << (SPECTREParser::PCCVS - 128))
          | (1ULL << (SPECTREParser::PHY_RES - 128))
          | (1ULL << (SPECTREParser::PORT - 128))
          | (1ULL << (SPECTREParser::PSITFT - 128))
          | (1ULL << (SPECTREParser::PVCCS - 128))
          | (1ULL << (SPECTREParser::PVCVS - 128))
          | (1ULL << (SPECTREParser::QUANTITY - 128))
          | (1ULL << (SPECTREParser::RDIFF - 128))
          | (1ULL << (SPECTREParser::RELAY - 128))
          | (1ULL << (SPECTREParser::RESISTOR - 128))
          | (1ULL << (SPECTREParser::SCCCS - 128))
          | (1ULL << (SPECTREParser::SCCVS - 128))
          | (1ULL << (SPECTREParser::SVCCS - 128))
          | (1ULL << (SPECTREParser::SVCVS - 128))
          | (1ULL << (SPECTREParser::SWITCH - 128))
          | (1ULL << (SPECTREParser::TLINE - 128))
          | (1ULL << (SPECTREParser::TOM2 - 128))
          | (1ULL << (SPECTREParser::TOM3 - 128))
          | (1ULL << (SPECTREParser::TRANSFORMER - 128))
          | (1ULL << (SPECTREParser::VBIC - 128))
          | (1ULL << (SPECTREParser::VCCS - 128))
          | (1ULL << (SPECTREParser::VCVS - 128))
          | (1ULL << (SPECTREParser::VSOURCE - 128))
          | (1ULL << (SPECTREParser::WINDING - 128))
          | (1ULL << (SPECTREParser::ZCCCS - 128))
          | (1ULL << (SPECTREParser::ZCCVS - 128))
          | (1ULL << (SPECTREParser::ZVCCS - 128))
          | (1ULL << (SPECTREParser::ZVCVS - 128))
          | (1ULL << (SPECTREParser::BSOURCE - 128))
          | (1ULL << (SPECTREParser::PLUS - 128))
          | (1ULL << (SPECTREParser::MINUS - 128))
          | (1ULL << (SPECTREParser::OPEN_ROUND - 128)))) != 0) || ((((_la - 195) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 195)) & ((1ULL << (SPECTREParser::OPEN_CURLY - 195))
          | (1ULL << (SPECTREParser::APEX - 195))
          | (1ULL << (SPECTREParser::NUMBER - 195))
          | (1ULL << (SPECTREParser::ID - 195))
          | (1ULL << (SPECTREParser::STRING - 195))
          | (1ULL << (SPECTREParser::PERCENTAGE - 195)))) != 0));
        break;
      }

      case 2: {
        setState(2212); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(2211);
          expression(0);
          setState(2214); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << SPECTREParser::ALTER)
          | (1ULL << SPECTREParser::ALTERGROUP)
          | (1ULL << SPECTREParser::OPTIONS)
          | (1ULL << SPECTREParser::SET)
          | (1ULL << SPECTREParser::SHELL)
          | (1ULL << SPECTREParser::INFO)
          | (1ULL << SPECTREParser::NODESET)
          | (1ULL << SPECTREParser::IC)
          | (1ULL << SPECTREParser::ASSERT)
          | (1ULL << SPECTREParser::CHECK)
          | (1ULL << SPECTREParser::LANGUAGE)
          | (1ULL << SPECTREParser::PORTS)
          | (1ULL << SPECTREParser::WAVE)
          | (1ULL << SPECTREParser::PWL)
          | (1ULL << SPECTREParser::SIN)
          | (1ULL << SPECTREParser::SFFM)
          | (1ULL << SPECTREParser::PULSE)
          | (1ULL << SPECTREParser::COEFFS)
          | (1ULL << SPECTREParser::INSENSITIVE)
          | (1ULL << SPECTREParser::IF)
          | (1ULL << SPECTREParser::ELSE)
          | (1ULL << SPECTREParser::PARAMETERS)
          | (1ULL << SPECTREParser::ANALOGMODEL)
          | (1ULL << SPECTREParser::CHECKPOINT)
          | (1ULL << SPECTREParser::SPECTRE)
          | (1ULL << SPECTREParser::SPICE)
          | (1ULL << SPECTREParser::STATISTICS)
          | (1ULL << SPECTREParser::PROCESS)
          | (1ULL << SPECTREParser::CORRELATE)
          | (1ULL << SPECTREParser::TRUNCATE)
          | (1ULL << SPECTREParser::MISMATCH)
          | (1ULL << SPECTREParser::VARY)
          | (1ULL << SPECTREParser::RELIABILITY)
          | (1ULL << SPECTREParser::AC)
          | (1ULL << SPECTREParser::ACMATCH)
          | (1ULL << SPECTREParser::DC)
          | (1ULL << SPECTREParser::DCMATCH)
          | (1ULL << SPECTREParser::ENVLP)
          | (1ULL << SPECTREParser::SP)
          | (1ULL << SPECTREParser::STB)
          | (1ULL << SPECTREParser::SWEEP)
          | (1ULL << SPECTREParser::TDR)
          | (1ULL << SPECTREParser::TRAN)
          | (1ULL << SPECTREParser::XF)
          | (1ULL << SPECTREParser::PAC)
          | (1ULL << SPECTREParser::PDISTO))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 64)) & ((1ULL << (SPECTREParser::PNOISE - 64))
          | (1ULL << (SPECTREParser::PSP - 64))
          | (1ULL << (SPECTREParser::PSS - 64))
          | (1ULL << (SPECTREParser::PXF - 64))
          | (1ULL << (SPECTREParser::PZ - 64))
          | (1ULL << (SPECTREParser::QPAC - 64))
          | (1ULL << (SPECTREParser::QPNOISE - 64))
          | (1ULL << (SPECTREParser::QPSP - 64))
          | (1ULL << (SPECTREParser::QPSS - 64))
          | (1ULL << (SPECTREParser::QPXF - 64))
          | (1ULL << (SPECTREParser::SENS - 64))
          | (1ULL << (SPECTREParser::MONTECARLO - 64))
          | (1ULL << (SPECTREParser::NOISE - 64))
          | (1ULL << (SPECTREParser::CHECKLIMIT - 64))
          | (1ULL << (SPECTREParser::A2D - 64))
          | (1ULL << (SPECTREParser::B3SOIPD - 64))
          | (1ULL << (SPECTREParser::BJT - 64))
          | (1ULL << (SPECTREParser::BJT301 - 64))
          | (1ULL << (SPECTREParser::BJT500 - 64))
          | (1ULL << (SPECTREParser::BJT503 - 64))
          | (1ULL << (SPECTREParser::BJT504 - 64))
          | (1ULL << (SPECTREParser::BJT504T - 64))
          | (1ULL << (SPECTREParser::BSIM1 - 64))
          | (1ULL << (SPECTREParser::BSIM2 - 64))
          | (1ULL << (SPECTREParser::BSIM3 - 64))
          | (1ULL << (SPECTREParser::BSIM3V3 - 64))
          | (1ULL << (SPECTREParser::BSIM4 - 64))
          | (1ULL << (SPECTREParser::BSIMSOI - 64))
          | (1ULL << (SPECTREParser::BTASOI - 64))
          | (1ULL << (SPECTREParser::CAPACITOR - 64))
          | (1ULL << (SPECTREParser::CCCS - 64))
          | (1ULL << (SPECTREParser::CCVS - 64))
          | (1ULL << (SPECTREParser::CKTROM - 64))
          | (1ULL << (SPECTREParser::CORE - 64))
          | (1ULL << (SPECTREParser::D2A - 64))
          | (1ULL << (SPECTREParser::DELAY - 64))
          | (1ULL << (SPECTREParser::DIO500 - 64))
          | (1ULL << (SPECTREParser::DIODE - 64))
          | (1ULL << (SPECTREParser::EKV - 64))
          | (1ULL << (SPECTREParser::FOURIER - 64))
          | (1ULL << (SPECTREParser::GAAS - 64))
          | (1ULL << (SPECTREParser::HBT - 64))
          | (1ULL << (SPECTREParser::HISIM - 64))
          | (1ULL << (SPECTREParser::HVMOS - 64))
          | (1ULL << (SPECTREParser::INDUCTOR - 64))
          | (1ULL << (SPECTREParser::INTCAP - 64))
          | (1ULL << (SPECTREParser::IPROBE - 64))
          | (1ULL << (SPECTREParser::ISOURCE - 64))
          | (1ULL << (SPECTREParser::JFET - 64))
          | (1ULL << (SPECTREParser::JUNCAP - 64))
          | (1ULL << (SPECTREParser::MISNAN - 64))
          | (1ULL << (SPECTREParser::MOS11011 - 64))
          | (1ULL << (SPECTREParser::MOS11010 - 64))
          | (1ULL << (SPECTREParser::MOS3002 - 64))
          | (1ULL << (SPECTREParser::MOS3100 - 64))
          | (1ULL << (SPECTREParser::MOS1000 - 64))
          | (1ULL << (SPECTREParser::MOS1100 - 64))
          | (1ULL << (SPECTREParser::MUTUAL_INDUCTOR - 64))
          | (1ULL << (SPECTREParser::MSLINE - 64))
          | (1ULL << (SPECTREParser::MTLINE - 64))
          | (1ULL << (SPECTREParser::MOS705 - 64))
          | (1ULL << (SPECTREParser::MOS902 - 64))
          | (1ULL << (SPECTREParser::MOS903 - 64))
          | (1ULL << (SPECTREParser::MOS30 - 64)))) != 0) || ((((_la - 128) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 128)) & ((1ULL << (SPECTREParser::MOS40 - 128))
          | (1ULL << (SPECTREParser::MOS15 - 128))
          | (1ULL << (SPECTREParser::MOS0 - 128))
          | (1ULL << (SPECTREParser::MOS1 - 128))
          | (1ULL << (SPECTREParser::MOS2 - 128))
          | (1ULL << (SPECTREParser::MOS3 - 128))
          | (1ULL << (SPECTREParser::NODCAP - 128))
          | (1ULL << (SPECTREParser::NODE - 128))
          | (1ULL << (SPECTREParser::NPORT - 128))
          | (1ULL << (SPECTREParser::PARAMTEST - 128))
          | (1ULL << (SPECTREParser::PCCCS - 128))
          | (1ULL << (SPECTREParser::PCCVS - 128))
          | (1ULL << (SPECTREParser::PHY_RES - 128))
          | (1ULL << (SPECTREParser::PORT - 128))
          | (1ULL << (SPECTREParser::PSITFT - 128))
          | (1ULL << (SPECTREParser::PVCCS - 128))
          | (1ULL << (SPECTREParser::PVCVS - 128))
          | (1ULL << (SPECTREParser::QUANTITY - 128))
          | (1ULL << (SPECTREParser::RDIFF - 128))
          | (1ULL << (SPECTREParser::RELAY - 128))
          | (1ULL << (SPECTREParser::RESISTOR - 128))
          | (1ULL << (SPECTREParser::SCCCS - 128))
          | (1ULL << (SPECTREParser::SCCVS - 128))
          | (1ULL << (SPECTREParser::SVCCS - 128))
          | (1ULL << (SPECTREParser::SVCVS - 128))
          | (1ULL << (SPECTREParser::SWITCH - 128))
          | (1ULL << (SPECTREParser::TLINE - 128))
          | (1ULL << (SPECTREParser::TOM2 - 128))
          | (1ULL << (SPECTREParser::TOM3 - 128))
          | (1ULL << (SPECTREParser::TRANSFORMER - 128))
          | (1ULL << (SPECTREParser::VBIC - 128))
          | (1ULL << (SPECTREParser::VCCS - 128))
          | (1ULL << (SPECTREParser::VCVS - 128))
          | (1ULL << (SPECTREParser::VSOURCE - 128))
          | (1ULL << (SPECTREParser::WINDING - 128))
          | (1ULL << (SPECTREParser::ZCCCS - 128))
          | (1ULL << (SPECTREParser::ZCCVS - 128))
          | (1ULL << (SPECTREParser::ZVCCS - 128))
          | (1ULL << (SPECTREParser::ZVCVS - 128))
          | (1ULL << (SPECTREParser::BSOURCE - 128))
          | (1ULL << (SPECTREParser::PLUS - 128))
          | (1ULL << (SPECTREParser::MINUS - 128))
          | (1ULL << (SPECTREParser::OPEN_ROUND - 128)))) != 0) || ((((_la - 195) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 195)) & ((1ULL << (SPECTREParser::OPEN_CURLY - 195))
          | (1ULL << (SPECTREParser::APEX - 195))
          | (1ULL << (SPECTREParser::NUMBER - 195))
          | (1ULL << (SPECTREParser::ID - 195))
          | (1ULL << (SPECTREParser::STRING - 195))
          | (1ULL << (SPECTREParser::PERCENTAGE - 195)))) != 0));
        break;
      }

      }
      setState(2218);
      match(SPECTREParser::CLOSE_SQUARE);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(2220);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SPECTREParser::WAVE)
        | (1ULL << SPECTREParser::PWL)
        | (1ULL << SPECTREParser::SIN)
        | (1ULL << SPECTREParser::SFFM)
        | (1ULL << SPECTREParser::PULSE)
        | (1ULL << SPECTREParser::COEFFS))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(2222);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SPECTREParser::EQUAL) {
        setState(2221);
        match(SPECTREParser::EQUAL);
      }
      setState(2224);
      match(SPECTREParser::OPEN_CURLY);
      setState(2235);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 423, _ctx)) {
      case 1: {
        setState(2226); 
        _errHandler->sync(this);
        alt = 1;
        do {
          switch (alt) {
            case 1: {
                  setState(2225);
                  time_pair();
                  break;
                }

          default:
            throw NoViableAltException(this);
          }
          setState(2228); 
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 421, _ctx);
        } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
        break;
      }

      case 2: {
        setState(2231); 
        _errHandler->sync(this);
        alt = 1;
        do {
          switch (alt) {
            case 1: {
                  setState(2230);
                  expression(0);
                  break;
                }

          default:
            throw NoViableAltException(this);
          }
          setState(2233); 
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 422, _ctx);
        } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
        break;
      }

      }
      setState(2237);
      match(SPECTREParser::OPEN_CURLY);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Component_analysisContext ------------------------------------------------------------------

SPECTREParser::Component_analysisContext::Component_analysisContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Component_analysisContext::OPEN_CURLY() {
  return getToken(SPECTREParser::OPEN_CURLY, 0);
}

tree::TerminalNode* SPECTREParser::Component_analysisContext::CLOSE_CURLY() {
  return getToken(SPECTREParser::CLOSE_CURLY, 0);
}

tree::TerminalNode* SPECTREParser::Component_analysisContext::AC() {
  return getToken(SPECTREParser::AC, 0);
}

tree::TerminalNode* SPECTREParser::Component_analysisContext::DC() {
  return getToken(SPECTREParser::DC, 0);
}

SPECTREParser::ExpressionContext* SPECTREParser::Component_analysisContext::expression() {
  return getRuleContext<SPECTREParser::ExpressionContext>(0);
}


size_t SPECTREParser::Component_analysisContext::getRuleIndex() const {
  return SPECTREParser::RuleComponent_analysis;
}

void SPECTREParser::Component_analysisContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponent_analysis(this);
}

void SPECTREParser::Component_analysisContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponent_analysis(this);
}


antlrcpp::Any SPECTREParser::Component_analysisContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitComponent_analysis(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Component_analysisContext* SPECTREParser::component_analysis() {
  Component_analysisContext *_localctx = _tracker.createInstance<Component_analysisContext>(_ctx, getState());
  enterRule(_localctx, 204, SPECTREParser::RuleComponent_analysis);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(2251);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 427, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(2241);
      _la = _input->LA(1);
      if (!(_la == SPECTREParser::AC

      || _la == SPECTREParser::DC)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(2242);
      match(SPECTREParser::OPEN_CURLY);
      setState(2244);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SPECTREParser::ALTER)
        | (1ULL << SPECTREParser::ALTERGROUP)
        | (1ULL << SPECTREParser::OPTIONS)
        | (1ULL << SPECTREParser::SET)
        | (1ULL << SPECTREParser::SHELL)
        | (1ULL << SPECTREParser::INFO)
        | (1ULL << SPECTREParser::NODESET)
        | (1ULL << SPECTREParser::IC)
        | (1ULL << SPECTREParser::ASSERT)
        | (1ULL << SPECTREParser::CHECK)
        | (1ULL << SPECTREParser::LANGUAGE)
        | (1ULL << SPECTREParser::PORTS)
        | (1ULL << SPECTREParser::WAVE)
        | (1ULL << SPECTREParser::PWL)
        | (1ULL << SPECTREParser::SIN)
        | (1ULL << SPECTREParser::SFFM)
        | (1ULL << SPECTREParser::PULSE)
        | (1ULL << SPECTREParser::COEFFS)
        | (1ULL << SPECTREParser::INSENSITIVE)
        | (1ULL << SPECTREParser::IF)
        | (1ULL << SPECTREParser::ELSE)
        | (1ULL << SPECTREParser::PARAMETERS)
        | (1ULL << SPECTREParser::ANALOGMODEL)
        | (1ULL << SPECTREParser::CHECKPOINT)
        | (1ULL << SPECTREParser::SPECTRE)
        | (1ULL << SPECTREParser::SPICE)
        | (1ULL << SPECTREParser::STATISTICS)
        | (1ULL << SPECTREParser::PROCESS)
        | (1ULL << SPECTREParser::CORRELATE)
        | (1ULL << SPECTREParser::TRUNCATE)
        | (1ULL << SPECTREParser::MISMATCH)
        | (1ULL << SPECTREParser::VARY)
        | (1ULL << SPECTREParser::RELIABILITY)
        | (1ULL << SPECTREParser::AC)
        | (1ULL << SPECTREParser::ACMATCH)
        | (1ULL << SPECTREParser::DC)
        | (1ULL << SPECTREParser::DCMATCH)
        | (1ULL << SPECTREParser::ENVLP)
        | (1ULL << SPECTREParser::SP)
        | (1ULL << SPECTREParser::STB)
        | (1ULL << SPECTREParser::SWEEP)
        | (1ULL << SPECTREParser::TDR)
        | (1ULL << SPECTREParser::TRAN)
        | (1ULL << SPECTREParser::XF)
        | (1ULL << SPECTREParser::PAC)
        | (1ULL << SPECTREParser::PDISTO))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (SPECTREParser::PNOISE - 64))
        | (1ULL << (SPECTREParser::PSP - 64))
        | (1ULL << (SPECTREParser::PSS - 64))
        | (1ULL << (SPECTREParser::PXF - 64))
        | (1ULL << (SPECTREParser::PZ - 64))
        | (1ULL << (SPECTREParser::QPAC - 64))
        | (1ULL << (SPECTREParser::QPNOISE - 64))
        | (1ULL << (SPECTREParser::QPSP - 64))
        | (1ULL << (SPECTREParser::QPSS - 64))
        | (1ULL << (SPECTREParser::QPXF - 64))
        | (1ULL << (SPECTREParser::SENS - 64))
        | (1ULL << (SPECTREParser::MONTECARLO - 64))
        | (1ULL << (SPECTREParser::NOISE - 64))
        | (1ULL << (SPECTREParser::CHECKLIMIT - 64))
        | (1ULL << (SPECTREParser::A2D - 64))
        | (1ULL << (SPECTREParser::B3SOIPD - 64))
        | (1ULL << (SPECTREParser::BJT - 64))
        | (1ULL << (SPECTREParser::BJT301 - 64))
        | (1ULL << (SPECTREParser::BJT500 - 64))
        | (1ULL << (SPECTREParser::BJT503 - 64))
        | (1ULL << (SPECTREParser::BJT504 - 64))
        | (1ULL << (SPECTREParser::BJT504T - 64))
        | (1ULL << (SPECTREParser::BSIM1 - 64))
        | (1ULL << (SPECTREParser::BSIM2 - 64))
        | (1ULL << (SPECTREParser::BSIM3 - 64))
        | (1ULL << (SPECTREParser::BSIM3V3 - 64))
        | (1ULL << (SPECTREParser::BSIM4 - 64))
        | (1ULL << (SPECTREParser::BSIMSOI - 64))
        | (1ULL << (SPECTREParser::BTASOI - 64))
        | (1ULL << (SPECTREParser::CAPACITOR - 64))
        | (1ULL << (SPECTREParser::CCCS - 64))
        | (1ULL << (SPECTREParser::CCVS - 64))
        | (1ULL << (SPECTREParser::CKTROM - 64))
        | (1ULL << (SPECTREParser::CORE - 64))
        | (1ULL << (SPECTREParser::D2A - 64))
        | (1ULL << (SPECTREParser::DELAY - 64))
        | (1ULL << (SPECTREParser::DIO500 - 64))
        | (1ULL << (SPECTREParser::DIODE - 64))
        | (1ULL << (SPECTREParser::EKV - 64))
        | (1ULL << (SPECTREParser::FOURIER - 64))
        | (1ULL << (SPECTREParser::GAAS - 64))
        | (1ULL << (SPECTREParser::HBT - 64))
        | (1ULL << (SPECTREParser::HISIM - 64))
        | (1ULL << (SPECTREParser::HVMOS - 64))
        | (1ULL << (SPECTREParser::INDUCTOR - 64))
        | (1ULL << (SPECTREParser::INTCAP - 64))
        | (1ULL << (SPECTREParser::IPROBE - 64))
        | (1ULL << (SPECTREParser::ISOURCE - 64))
        | (1ULL << (SPECTREParser::JFET - 64))
        | (1ULL << (SPECTREParser::JUNCAP - 64))
        | (1ULL << (SPECTREParser::MISNAN - 64))
        | (1ULL << (SPECTREParser::MOS11011 - 64))
        | (1ULL << (SPECTREParser::MOS11010 - 64))
        | (1ULL << (SPECTREParser::MOS3002 - 64))
        | (1ULL << (SPECTREParser::MOS3100 - 64))
        | (1ULL << (SPECTREParser::MOS1000 - 64))
        | (1ULL << (SPECTREParser::MOS1100 - 64))
        | (1ULL << (SPECTREParser::MUTUAL_INDUCTOR - 64))
        | (1ULL << (SPECTREParser::MSLINE - 64))
        | (1ULL << (SPECTREParser::MTLINE - 64))
        | (1ULL << (SPECTREParser::MOS705 - 64))
        | (1ULL << (SPECTREParser::MOS902 - 64))
        | (1ULL << (SPECTREParser::MOS903 - 64))
        | (1ULL << (SPECTREParser::MOS30 - 64)))) != 0) || ((((_la - 128) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 128)) & ((1ULL << (SPECTREParser::MOS40 - 128))
        | (1ULL << (SPECTREParser::MOS15 - 128))
        | (1ULL << (SPECTREParser::MOS0 - 128))
        | (1ULL << (SPECTREParser::MOS1 - 128))
        | (1ULL << (SPECTREParser::MOS2 - 128))
        | (1ULL << (SPECTREParser::MOS3 - 128))
        | (1ULL << (SPECTREParser::NODCAP - 128))
        | (1ULL << (SPECTREParser::NODE - 128))
        | (1ULL << (SPECTREParser::NPORT - 128))
        | (1ULL << (SPECTREParser::PARAMTEST - 128))
        | (1ULL << (SPECTREParser::PCCCS - 128))
        | (1ULL << (SPECTREParser::PCCVS - 128))
        | (1ULL << (SPECTREParser::PHY_RES - 128))
        | (1ULL << (SPECTREParser::PORT - 128))
        | (1ULL << (SPECTREParser::PSITFT - 128))
        | (1ULL << (SPECTREParser::PVCCS - 128))
        | (1ULL << (SPECTREParser::PVCVS - 128))
        | (1ULL << (SPECTREParser::QUANTITY - 128))
        | (1ULL << (SPECTREParser::RDIFF - 128))
        | (1ULL << (SPECTREParser::RELAY - 128))
        | (1ULL << (SPECTREParser::RESISTOR - 128))
        | (1ULL << (SPECTREParser::SCCCS - 128))
        | (1ULL << (SPECTREParser::SCCVS - 128))
        | (1ULL << (SPECTREParser::SVCCS - 128))
        | (1ULL << (SPECTREParser::SVCVS - 128))
        | (1ULL << (SPECTREParser::SWITCH - 128))
        | (1ULL << (SPECTREParser::TLINE - 128))
        | (1ULL << (SPECTREParser::TOM2 - 128))
        | (1ULL << (SPECTREParser::TOM3 - 128))
        | (1ULL << (SPECTREParser::TRANSFORMER - 128))
        | (1ULL << (SPECTREParser::VBIC - 128))
        | (1ULL << (SPECTREParser::VCCS - 128))
        | (1ULL << (SPECTREParser::VCVS - 128))
        | (1ULL << (SPECTREParser::VSOURCE - 128))
        | (1ULL << (SPECTREParser::WINDING - 128))
        | (1ULL << (SPECTREParser::ZCCCS - 128))
        | (1ULL << (SPECTREParser::ZCCVS - 128))
        | (1ULL << (SPECTREParser::ZVCCS - 128))
        | (1ULL << (SPECTREParser::ZVCVS - 128))
        | (1ULL << (SPECTREParser::BSOURCE - 128))
        | (1ULL << (SPECTREParser::PLUS - 128))
        | (1ULL << (SPECTREParser::MINUS - 128))
        | (1ULL << (SPECTREParser::OPEN_ROUND - 128)))) != 0) || ((((_la - 195) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 195)) & ((1ULL << (SPECTREParser::OPEN_CURLY - 195))
        | (1ULL << (SPECTREParser::APEX - 195))
        | (1ULL << (SPECTREParser::NUMBER - 195))
        | (1ULL << (SPECTREParser::ID - 195))
        | (1ULL << (SPECTREParser::STRING - 195))
        | (1ULL << (SPECTREParser::PERCENTAGE - 195)))) != 0)) {
        setState(2243);
        expression(0);
      }
      setState(2246);
      match(SPECTREParser::CLOSE_CURLY);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(2247);
      _la = _input->LA(1);
      if (!(_la == SPECTREParser::AC

      || _la == SPECTREParser::DC)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(2249);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 426, _ctx)) {
      case 1: {
        setState(2248);
        expression(0);
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Node_listContext ------------------------------------------------------------------

SPECTREParser::Node_listContext::Node_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SPECTREParser::Node_list_itemContext *> SPECTREParser::Node_listContext::node_list_item() {
  return getRuleContexts<SPECTREParser::Node_list_itemContext>();
}

SPECTREParser::Node_list_itemContext* SPECTREParser::Node_listContext::node_list_item(size_t i) {
  return getRuleContext<SPECTREParser::Node_list_itemContext>(i);
}

tree::TerminalNode* SPECTREParser::Node_listContext::OPEN_ROUND() {
  return getToken(SPECTREParser::OPEN_ROUND, 0);
}

tree::TerminalNode* SPECTREParser::Node_listContext::CLOSE_ROUND() {
  return getToken(SPECTREParser::CLOSE_ROUND, 0);
}


size_t SPECTREParser::Node_listContext::getRuleIndex() const {
  return SPECTREParser::RuleNode_list;
}

void SPECTREParser::Node_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNode_list(this);
}

void SPECTREParser::Node_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNode_list(this);
}


antlrcpp::Any SPECTREParser::Node_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitNode_list(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Node_listContext* SPECTREParser::node_list() {
  Node_listContext *_localctx = _tracker.createInstance<Node_listContext>(_ctx, getState());
  enterRule(_localctx, 206, SPECTREParser::RuleNode_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(2266);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SPECTREParser::NUMBER:
      case SPECTREParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(2254); 
        _errHandler->sync(this);
        alt = 1;
        do {
          switch (alt) {
            case 1: {
                  setState(2253);
                  node_list_item();
                  break;
                }

          default:
            throw NoViableAltException(this);
          }
          setState(2256); 
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 428, _ctx);
        } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
        break;
      }

      case SPECTREParser::OPEN_ROUND: {
        enterOuterAlt(_localctx, 2);
        setState(2258);
        match(SPECTREParser::OPEN_ROUND);
        setState(2260); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(2259);
          node_list_item();
          setState(2262); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == SPECTREParser::NUMBER

        || _la == SPECTREParser::ID);
        setState(2264);
        match(SPECTREParser::CLOSE_ROUND);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Node_list_itemContext ------------------------------------------------------------------

SPECTREParser::Node_list_itemContext::Node_list_itemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SPECTREParser::NodeContext* SPECTREParser::Node_list_itemContext::node() {
  return getRuleContext<SPECTREParser::NodeContext>(0);
}

SPECTREParser::Node_mappingContext* SPECTREParser::Node_list_itemContext::node_mapping() {
  return getRuleContext<SPECTREParser::Node_mappingContext>(0);
}

SPECTREParser::Node_branchContext* SPECTREParser::Node_list_itemContext::node_branch() {
  return getRuleContext<SPECTREParser::Node_branchContext>(0);
}


size_t SPECTREParser::Node_list_itemContext::getRuleIndex() const {
  return SPECTREParser::RuleNode_list_item;
}

void SPECTREParser::Node_list_itemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNode_list_item(this);
}

void SPECTREParser::Node_list_itemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNode_list_item(this);
}


antlrcpp::Any SPECTREParser::Node_list_itemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitNode_list_item(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Node_list_itemContext* SPECTREParser::node_list_item() {
  Node_list_itemContext *_localctx = _tracker.createInstance<Node_list_itemContext>(_ctx, getState());
  enterRule(_localctx, 208, SPECTREParser::RuleNode_list_item);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(2271);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 431, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(2268);
      node();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(2269);
      node_mapping();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(2270);
      node_branch();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Node_mappingContext ------------------------------------------------------------------

SPECTREParser::Node_mappingContext::Node_mappingContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SPECTREParser::NodeContext *> SPECTREParser::Node_mappingContext::node() {
  return getRuleContexts<SPECTREParser::NodeContext>();
}

SPECTREParser::NodeContext* SPECTREParser::Node_mappingContext::node(size_t i) {
  return getRuleContext<SPECTREParser::NodeContext>(i);
}

tree::TerminalNode* SPECTREParser::Node_mappingContext::EQUAL() {
  return getToken(SPECTREParser::EQUAL, 0);
}


size_t SPECTREParser::Node_mappingContext::getRuleIndex() const {
  return SPECTREParser::RuleNode_mapping;
}

void SPECTREParser::Node_mappingContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNode_mapping(this);
}

void SPECTREParser::Node_mappingContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNode_mapping(this);
}


antlrcpp::Any SPECTREParser::Node_mappingContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitNode_mapping(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Node_mappingContext* SPECTREParser::node_mapping() {
  Node_mappingContext *_localctx = _tracker.createInstance<Node_mappingContext>(_ctx, getState());
  enterRule(_localctx, 210, SPECTREParser::RuleNode_mapping);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2273);
    node();
    setState(2274);
    match(SPECTREParser::EQUAL);
    setState(2275);
    node();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Node_pairContext ------------------------------------------------------------------

SPECTREParser::Node_pairContext::Node_pairContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SPECTREParser::NodeContext *> SPECTREParser::Node_pairContext::node() {
  return getRuleContexts<SPECTREParser::NodeContext>();
}

SPECTREParser::NodeContext* SPECTREParser::Node_pairContext::node(size_t i) {
  return getRuleContext<SPECTREParser::NodeContext>(i);
}

tree::TerminalNode* SPECTREParser::Node_pairContext::COMMA() {
  return getToken(SPECTREParser::COMMA, 0);
}


size_t SPECTREParser::Node_pairContext::getRuleIndex() const {
  return SPECTREParser::RuleNode_pair;
}

void SPECTREParser::Node_pairContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNode_pair(this);
}

void SPECTREParser::Node_pairContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNode_pair(this);
}


antlrcpp::Any SPECTREParser::Node_pairContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitNode_pair(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Node_pairContext* SPECTREParser::node_pair() {
  Node_pairContext *_localctx = _tracker.createInstance<Node_pairContext>(_ctx, getState());
  enterRule(_localctx, 212, SPECTREParser::RuleNode_pair);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2277);
    node();
    setState(2278);
    match(SPECTREParser::COMMA);
    setState(2279);
    node();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Node_branchContext ------------------------------------------------------------------

SPECTREParser::Node_branchContext::Node_branchContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SPECTREParser::NodeContext *> SPECTREParser::Node_branchContext::node() {
  return getRuleContexts<SPECTREParser::NodeContext>();
}

SPECTREParser::NodeContext* SPECTREParser::Node_branchContext::node(size_t i) {
  return getRuleContext<SPECTREParser::NodeContext>(i);
}

tree::TerminalNode* SPECTREParser::Node_branchContext::COLON() {
  return getToken(SPECTREParser::COLON, 0);
}


size_t SPECTREParser::Node_branchContext::getRuleIndex() const {
  return SPECTREParser::RuleNode_branch;
}

void SPECTREParser::Node_branchContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNode_branch(this);
}

void SPECTREParser::Node_branchContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNode_branch(this);
}


antlrcpp::Any SPECTREParser::Node_branchContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitNode_branch(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Node_branchContext* SPECTREParser::node_branch() {
  Node_branchContext *_localctx = _tracker.createInstance<Node_branchContext>(_ctx, getState());
  enterRule(_localctx, 214, SPECTREParser::RuleNode_branch);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2281);
    node();
    setState(2282);
    match(SPECTREParser::COLON);
    setState(2283);
    node();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NodeContext ------------------------------------------------------------------

SPECTREParser::NodeContext::NodeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::NodeContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

tree::TerminalNode* SPECTREParser::NodeContext::NUMBER() {
  return getToken(SPECTREParser::NUMBER, 0);
}

tree::TerminalNode* SPECTREParser::NodeContext::DOT() {
  return getToken(SPECTREParser::DOT, 0);
}

SPECTREParser::NodeContext* SPECTREParser::NodeContext::node() {
  return getRuleContext<SPECTREParser::NodeContext>(0);
}


size_t SPECTREParser::NodeContext::getRuleIndex() const {
  return SPECTREParser::RuleNode;
}

void SPECTREParser::NodeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNode(this);
}

void SPECTREParser::NodeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNode(this);
}


antlrcpp::Any SPECTREParser::NodeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitNode(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::NodeContext* SPECTREParser::node() {
  NodeContext *_localctx = _tracker.createInstance<NodeContext>(_ctx, getState());
  enterRule(_localctx, 216, SPECTREParser::RuleNode);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2285);
    _la = _input->LA(1);
    if (!(_la == SPECTREParser::NUMBER

    || _la == SPECTREParser::ID)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(2288);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SPECTREParser::DOT) {
      setState(2286);
      match(SPECTREParser::DOT);
      setState(2287);
      node();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

SPECTREParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SPECTREParser::Expression_unaryContext* SPECTREParser::ExpressionContext::expression_unary() {
  return getRuleContext<SPECTREParser::Expression_unaryContext>(0);
}

SPECTREParser::Expression_function_callContext* SPECTREParser::ExpressionContext::expression_function_call() {
  return getRuleContext<SPECTREParser::Expression_function_callContext>(0);
}

SPECTREParser::Expression_scopeContext* SPECTREParser::ExpressionContext::expression_scope() {
  return getRuleContext<SPECTREParser::Expression_scopeContext>(0);
}

SPECTREParser::Expression_atomContext* SPECTREParser::ExpressionContext::expression_atom() {
  return getRuleContext<SPECTREParser::Expression_atomContext>(0);
}

SPECTREParser::Expression_pairContext* SPECTREParser::ExpressionContext::expression_pair() {
  return getRuleContext<SPECTREParser::Expression_pairContext>(0);
}

std::vector<SPECTREParser::ExpressionContext *> SPECTREParser::ExpressionContext::expression() {
  return getRuleContexts<SPECTREParser::ExpressionContext>();
}

SPECTREParser::ExpressionContext* SPECTREParser::ExpressionContext::expression(size_t i) {
  return getRuleContext<SPECTREParser::ExpressionContext>(i);
}

tree::TerminalNode* SPECTREParser::ExpressionContext::QUESTION_MARK() {
  return getToken(SPECTREParser::QUESTION_MARK, 0);
}

tree::TerminalNode* SPECTREParser::ExpressionContext::COLON() {
  return getToken(SPECTREParser::COLON, 0);
}

SPECTREParser::Expression_operatorContext* SPECTREParser::ExpressionContext::expression_operator() {
  return getRuleContext<SPECTREParser::Expression_operatorContext>(0);
}


size_t SPECTREParser::ExpressionContext::getRuleIndex() const {
  return SPECTREParser::RuleExpression;
}

void SPECTREParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void SPECTREParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


antlrcpp::Any SPECTREParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}


SPECTREParser::ExpressionContext* SPECTREParser::expression() {
   return expression(0);
}

SPECTREParser::ExpressionContext* SPECTREParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SPECTREParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  SPECTREParser::ExpressionContext *previousContext = _localctx;
  size_t startState = 218;
  enterRecursionRule(_localctx, 218, SPECTREParser::RuleExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(2296);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 433, _ctx)) {
    case 1: {
      setState(2291);
      expression_unary();
      break;
    }

    case 2: {
      setState(2292);
      expression_function_call();
      break;
    }

    case 3: {
      setState(2293);
      expression_scope();
      break;
    }

    case 4: {
      setState(2294);
      expression_atom();
      break;
    }

    case 5: {
      setState(2295);
      expression_pair();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(2311);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 436, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(2309);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 435, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(2298);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(2299);
          match(SPECTREParser::QUESTION_MARK);
          setState(2300);
          expression(0);
          setState(2301);
          match(SPECTREParser::COLON);
          setState(2302);
          expression(2);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(2304);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(2305);
          expression_operator();
          setState(2307);
          _errHandler->sync(this);

          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 434, _ctx)) {
          case 1: {
            setState(2306);
            expression(0);
            break;
          }

          }
          break;
        }

        } 
      }
      setState(2313);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 436, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Expression_unaryContext ------------------------------------------------------------------

SPECTREParser::Expression_unaryContext::Expression_unaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SPECTREParser::ExpressionContext* SPECTREParser::Expression_unaryContext::expression() {
  return getRuleContext<SPECTREParser::ExpressionContext>(0);
}

tree::TerminalNode* SPECTREParser::Expression_unaryContext::PLUS() {
  return getToken(SPECTREParser::PLUS, 0);
}

tree::TerminalNode* SPECTREParser::Expression_unaryContext::MINUS() {
  return getToken(SPECTREParser::MINUS, 0);
}


size_t SPECTREParser::Expression_unaryContext::getRuleIndex() const {
  return SPECTREParser::RuleExpression_unary;
}

void SPECTREParser::Expression_unaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_unary(this);
}

void SPECTREParser::Expression_unaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_unary(this);
}


antlrcpp::Any SPECTREParser::Expression_unaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitExpression_unary(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Expression_unaryContext* SPECTREParser::expression_unary() {
  Expression_unaryContext *_localctx = _tracker.createInstance<Expression_unaryContext>(_ctx, getState());
  enterRule(_localctx, 220, SPECTREParser::RuleExpression_unary);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2314);
    _la = _input->LA(1);
    if (!(_la == SPECTREParser::PLUS

    || _la == SPECTREParser::MINUS)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(2315);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression_function_callContext ------------------------------------------------------------------

SPECTREParser::Expression_function_callContext::Expression_function_callContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Expression_function_callContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

tree::TerminalNode* SPECTREParser::Expression_function_callContext::OPEN_ROUND() {
  return getToken(SPECTREParser::OPEN_ROUND, 0);
}

tree::TerminalNode* SPECTREParser::Expression_function_callContext::CLOSE_ROUND() {
  return getToken(SPECTREParser::CLOSE_ROUND, 0);
}

std::vector<SPECTREParser::ExpressionContext *> SPECTREParser::Expression_function_callContext::expression() {
  return getRuleContexts<SPECTREParser::ExpressionContext>();
}

SPECTREParser::ExpressionContext* SPECTREParser::Expression_function_callContext::expression(size_t i) {
  return getRuleContext<SPECTREParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> SPECTREParser::Expression_function_callContext::COMMA() {
  return getTokens(SPECTREParser::COMMA);
}

tree::TerminalNode* SPECTREParser::Expression_function_callContext::COMMA(size_t i) {
  return getToken(SPECTREParser::COMMA, i);
}


size_t SPECTREParser::Expression_function_callContext::getRuleIndex() const {
  return SPECTREParser::RuleExpression_function_call;
}

void SPECTREParser::Expression_function_callContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_function_call(this);
}

void SPECTREParser::Expression_function_callContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_function_call(this);
}


antlrcpp::Any SPECTREParser::Expression_function_callContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitExpression_function_call(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Expression_function_callContext* SPECTREParser::expression_function_call() {
  Expression_function_callContext *_localctx = _tracker.createInstance<Expression_function_callContext>(_ctx, getState());
  enterRule(_localctx, 222, SPECTREParser::RuleExpression_function_call);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2317);
    match(SPECTREParser::ID);
    setState(2318);
    match(SPECTREParser::OPEN_ROUND);
    setState(2323); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(2319);
      expression(0);
      setState(2321);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SPECTREParser::COMMA) {
        setState(2320);
        match(SPECTREParser::COMMA);
      }
      setState(2325); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SPECTREParser::ALTER)
      | (1ULL << SPECTREParser::ALTERGROUP)
      | (1ULL << SPECTREParser::OPTIONS)
      | (1ULL << SPECTREParser::SET)
      | (1ULL << SPECTREParser::SHELL)
      | (1ULL << SPECTREParser::INFO)
      | (1ULL << SPECTREParser::NODESET)
      | (1ULL << SPECTREParser::IC)
      | (1ULL << SPECTREParser::ASSERT)
      | (1ULL << SPECTREParser::CHECK)
      | (1ULL << SPECTREParser::LANGUAGE)
      | (1ULL << SPECTREParser::PORTS)
      | (1ULL << SPECTREParser::WAVE)
      | (1ULL << SPECTREParser::PWL)
      | (1ULL << SPECTREParser::SIN)
      | (1ULL << SPECTREParser::SFFM)
      | (1ULL << SPECTREParser::PULSE)
      | (1ULL << SPECTREParser::COEFFS)
      | (1ULL << SPECTREParser::INSENSITIVE)
      | (1ULL << SPECTREParser::IF)
      | (1ULL << SPECTREParser::ELSE)
      | (1ULL << SPECTREParser::PARAMETERS)
      | (1ULL << SPECTREParser::ANALOGMODEL)
      | (1ULL << SPECTREParser::CHECKPOINT)
      | (1ULL << SPECTREParser::SPECTRE)
      | (1ULL << SPECTREParser::SPICE)
      | (1ULL << SPECTREParser::STATISTICS)
      | (1ULL << SPECTREParser::PROCESS)
      | (1ULL << SPECTREParser::CORRELATE)
      | (1ULL << SPECTREParser::TRUNCATE)
      | (1ULL << SPECTREParser::MISMATCH)
      | (1ULL << SPECTREParser::VARY)
      | (1ULL << SPECTREParser::RELIABILITY)
      | (1ULL << SPECTREParser::AC)
      | (1ULL << SPECTREParser::ACMATCH)
      | (1ULL << SPECTREParser::DC)
      | (1ULL << SPECTREParser::DCMATCH)
      | (1ULL << SPECTREParser::ENVLP)
      | (1ULL << SPECTREParser::SP)
      | (1ULL << SPECTREParser::STB)
      | (1ULL << SPECTREParser::SWEEP)
      | (1ULL << SPECTREParser::TDR)
      | (1ULL << SPECTREParser::TRAN)
      | (1ULL << SPECTREParser::XF)
      | (1ULL << SPECTREParser::PAC)
      | (1ULL << SPECTREParser::PDISTO))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (SPECTREParser::PNOISE - 64))
      | (1ULL << (SPECTREParser::PSP - 64))
      | (1ULL << (SPECTREParser::PSS - 64))
      | (1ULL << (SPECTREParser::PXF - 64))
      | (1ULL << (SPECTREParser::PZ - 64))
      | (1ULL << (SPECTREParser::QPAC - 64))
      | (1ULL << (SPECTREParser::QPNOISE - 64))
      | (1ULL << (SPECTREParser::QPSP - 64))
      | (1ULL << (SPECTREParser::QPSS - 64))
      | (1ULL << (SPECTREParser::QPXF - 64))
      | (1ULL << (SPECTREParser::SENS - 64))
      | (1ULL << (SPECTREParser::MONTECARLO - 64))
      | (1ULL << (SPECTREParser::NOISE - 64))
      | (1ULL << (SPECTREParser::CHECKLIMIT - 64))
      | (1ULL << (SPECTREParser::A2D - 64))
      | (1ULL << (SPECTREParser::B3SOIPD - 64))
      | (1ULL << (SPECTREParser::BJT - 64))
      | (1ULL << (SPECTREParser::BJT301 - 64))
      | (1ULL << (SPECTREParser::BJT500 - 64))
      | (1ULL << (SPECTREParser::BJT503 - 64))
      | (1ULL << (SPECTREParser::BJT504 - 64))
      | (1ULL << (SPECTREParser::BJT504T - 64))
      | (1ULL << (SPECTREParser::BSIM1 - 64))
      | (1ULL << (SPECTREParser::BSIM2 - 64))
      | (1ULL << (SPECTREParser::BSIM3 - 64))
      | (1ULL << (SPECTREParser::BSIM3V3 - 64))
      | (1ULL << (SPECTREParser::BSIM4 - 64))
      | (1ULL << (SPECTREParser::BSIMSOI - 64))
      | (1ULL << (SPECTREParser::BTASOI - 64))
      | (1ULL << (SPECTREParser::CAPACITOR - 64))
      | (1ULL << (SPECTREParser::CCCS - 64))
      | (1ULL << (SPECTREParser::CCVS - 64))
      | (1ULL << (SPECTREParser::CKTROM - 64))
      | (1ULL << (SPECTREParser::CORE - 64))
      | (1ULL << (SPECTREParser::D2A - 64))
      | (1ULL << (SPECTREParser::DELAY - 64))
      | (1ULL << (SPECTREParser::DIO500 - 64))
      | (1ULL << (SPECTREParser::DIODE - 64))
      | (1ULL << (SPECTREParser::EKV - 64))
      | (1ULL << (SPECTREParser::FOURIER - 64))
      | (1ULL << (SPECTREParser::GAAS - 64))
      | (1ULL << (SPECTREParser::HBT - 64))
      | (1ULL << (SPECTREParser::HISIM - 64))
      | (1ULL << (SPECTREParser::HVMOS - 64))
      | (1ULL << (SPECTREParser::INDUCTOR - 64))
      | (1ULL << (SPECTREParser::INTCAP - 64))
      | (1ULL << (SPECTREParser::IPROBE - 64))
      | (1ULL << (SPECTREParser::ISOURCE - 64))
      | (1ULL << (SPECTREParser::JFET - 64))
      | (1ULL << (SPECTREParser::JUNCAP - 64))
      | (1ULL << (SPECTREParser::MISNAN - 64))
      | (1ULL << (SPECTREParser::MOS11011 - 64))
      | (1ULL << (SPECTREParser::MOS11010 - 64))
      | (1ULL << (SPECTREParser::MOS3002 - 64))
      | (1ULL << (SPECTREParser::MOS3100 - 64))
      | (1ULL << (SPECTREParser::MOS1000 - 64))
      | (1ULL << (SPECTREParser::MOS1100 - 64))
      | (1ULL << (SPECTREParser::MUTUAL_INDUCTOR - 64))
      | (1ULL << (SPECTREParser::MSLINE - 64))
      | (1ULL << (SPECTREParser::MTLINE - 64))
      | (1ULL << (SPECTREParser::MOS705 - 64))
      | (1ULL << (SPECTREParser::MOS902 - 64))
      | (1ULL << (SPECTREParser::MOS903 - 64))
      | (1ULL << (SPECTREParser::MOS30 - 64)))) != 0) || ((((_la - 128) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 128)) & ((1ULL << (SPECTREParser::MOS40 - 128))
      | (1ULL << (SPECTREParser::MOS15 - 128))
      | (1ULL << (SPECTREParser::MOS0 - 128))
      | (1ULL << (SPECTREParser::MOS1 - 128))
      | (1ULL << (SPECTREParser::MOS2 - 128))
      | (1ULL << (SPECTREParser::MOS3 - 128))
      | (1ULL << (SPECTREParser::NODCAP - 128))
      | (1ULL << (SPECTREParser::NODE - 128))
      | (1ULL << (SPECTREParser::NPORT - 128))
      | (1ULL << (SPECTREParser::PARAMTEST - 128))
      | (1ULL << (SPECTREParser::PCCCS - 128))
      | (1ULL << (SPECTREParser::PCCVS - 128))
      | (1ULL << (SPECTREParser::PHY_RES - 128))
      | (1ULL << (SPECTREParser::PORT - 128))
      | (1ULL << (SPECTREParser::PSITFT - 128))
      | (1ULL << (SPECTREParser::PVCCS - 128))
      | (1ULL << (SPECTREParser::PVCVS - 128))
      | (1ULL << (SPECTREParser::QUANTITY - 128))
      | (1ULL << (SPECTREParser::RDIFF - 128))
      | (1ULL << (SPECTREParser::RELAY - 128))
      | (1ULL << (SPECTREParser::RESISTOR - 128))
      | (1ULL << (SPECTREParser::SCCCS - 128))
      | (1ULL << (SPECTREParser::SCCVS - 128))
      | (1ULL << (SPECTREParser::SVCCS - 128))
      | (1ULL << (SPECTREParser::SVCVS - 128))
      | (1ULL << (SPECTREParser::SWITCH - 128))
      | (1ULL << (SPECTREParser::TLINE - 128))
      | (1ULL << (SPECTREParser::TOM2 - 128))
      | (1ULL << (SPECTREParser::TOM3 - 128))
      | (1ULL << (SPECTREParser::TRANSFORMER - 128))
      | (1ULL << (SPECTREParser::VBIC - 128))
      | (1ULL << (SPECTREParser::VCCS - 128))
      | (1ULL << (SPECTREParser::VCVS - 128))
      | (1ULL << (SPECTREParser::VSOURCE - 128))
      | (1ULL << (SPECTREParser::WINDING - 128))
      | (1ULL << (SPECTREParser::ZCCCS - 128))
      | (1ULL << (SPECTREParser::ZCCVS - 128))
      | (1ULL << (SPECTREParser::ZVCCS - 128))
      | (1ULL << (SPECTREParser::ZVCVS - 128))
      | (1ULL << (SPECTREParser::BSOURCE - 128))
      | (1ULL << (SPECTREParser::PLUS - 128))
      | (1ULL << (SPECTREParser::MINUS - 128))
      | (1ULL << (SPECTREParser::OPEN_ROUND - 128)))) != 0) || ((((_la - 195) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 195)) & ((1ULL << (SPECTREParser::OPEN_CURLY - 195))
      | (1ULL << (SPECTREParser::APEX - 195))
      | (1ULL << (SPECTREParser::NUMBER - 195))
      | (1ULL << (SPECTREParser::ID - 195))
      | (1ULL << (SPECTREParser::STRING - 195))
      | (1ULL << (SPECTREParser::PERCENTAGE - 195)))) != 0));
    setState(2327);
    match(SPECTREParser::CLOSE_ROUND);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression_pairContext ------------------------------------------------------------------

SPECTREParser::Expression_pairContext::Expression_pairContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SPECTREParser::Expression_atomContext *> SPECTREParser::Expression_pairContext::expression_atom() {
  return getRuleContexts<SPECTREParser::Expression_atomContext>();
}

SPECTREParser::Expression_atomContext* SPECTREParser::Expression_pairContext::expression_atom(size_t i) {
  return getRuleContext<SPECTREParser::Expression_atomContext>(i);
}

tree::TerminalNode* SPECTREParser::Expression_pairContext::COMMA() {
  return getToken(SPECTREParser::COMMA, 0);
}


size_t SPECTREParser::Expression_pairContext::getRuleIndex() const {
  return SPECTREParser::RuleExpression_pair;
}

void SPECTREParser::Expression_pairContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_pair(this);
}

void SPECTREParser::Expression_pairContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_pair(this);
}


antlrcpp::Any SPECTREParser::Expression_pairContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitExpression_pair(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Expression_pairContext* SPECTREParser::expression_pair() {
  Expression_pairContext *_localctx = _tracker.createInstance<Expression_pairContext>(_ctx, getState());
  enterRule(_localctx, 224, SPECTREParser::RuleExpression_pair);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2329);
    expression_atom();
    setState(2330);
    match(SPECTREParser::COMMA);
    setState(2331);
    expression_atom();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression_scopeContext ------------------------------------------------------------------

SPECTREParser::Expression_scopeContext::Expression_scopeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Expression_scopeContext::OPEN_ROUND() {
  return getToken(SPECTREParser::OPEN_ROUND, 0);
}

tree::TerminalNode* SPECTREParser::Expression_scopeContext::OPEN_CURLY() {
  return getToken(SPECTREParser::OPEN_CURLY, 0);
}

std::vector<tree::TerminalNode *> SPECTREParser::Expression_scopeContext::APEX() {
  return getTokens(SPECTREParser::APEX);
}

tree::TerminalNode* SPECTREParser::Expression_scopeContext::APEX(size_t i) {
  return getToken(SPECTREParser::APEX, i);
}

tree::TerminalNode* SPECTREParser::Expression_scopeContext::CLOSE_ROUND() {
  return getToken(SPECTREParser::CLOSE_ROUND, 0);
}

tree::TerminalNode* SPECTREParser::Expression_scopeContext::CLOSE_CURLY() {
  return getToken(SPECTREParser::CLOSE_CURLY, 0);
}

std::vector<SPECTREParser::ExpressionContext *> SPECTREParser::Expression_scopeContext::expression() {
  return getRuleContexts<SPECTREParser::ExpressionContext>();
}

SPECTREParser::ExpressionContext* SPECTREParser::Expression_scopeContext::expression(size_t i) {
  return getRuleContext<SPECTREParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> SPECTREParser::Expression_scopeContext::COMMA() {
  return getTokens(SPECTREParser::COMMA);
}

tree::TerminalNode* SPECTREParser::Expression_scopeContext::COMMA(size_t i) {
  return getToken(SPECTREParser::COMMA, i);
}


size_t SPECTREParser::Expression_scopeContext::getRuleIndex() const {
  return SPECTREParser::RuleExpression_scope;
}

void SPECTREParser::Expression_scopeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_scope(this);
}

void SPECTREParser::Expression_scopeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_scope(this);
}


antlrcpp::Any SPECTREParser::Expression_scopeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitExpression_scope(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Expression_scopeContext* SPECTREParser::expression_scope() {
  Expression_scopeContext *_localctx = _tracker.createInstance<Expression_scopeContext>(_ctx, getState());
  enterRule(_localctx, 226, SPECTREParser::RuleExpression_scope);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(2333);
    _la = _input->LA(1);
    if (!(((((_la - 191) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 191)) & ((1ULL << (SPECTREParser::OPEN_ROUND - 191))
      | (1ULL << (SPECTREParser::OPEN_CURLY - 191))
      | (1ULL << (SPECTREParser::APEX - 191)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(2338); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(2334);
              expression(0);
              setState(2336);
              _errHandler->sync(this);

              _la = _input->LA(1);
              if (_la == SPECTREParser::COMMA) {
                setState(2335);
                match(SPECTREParser::COMMA);
              }
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(2340); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 440, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
    setState(2342);
    _la = _input->LA(1);
    if (!(((((_la - 192) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 192)) & ((1ULL << (SPECTREParser::CLOSE_ROUND - 192))
      | (1ULL << (SPECTREParser::CLOSE_CURLY - 192))
      | (1ULL << (SPECTREParser::APEX - 192)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression_operatorContext ------------------------------------------------------------------

SPECTREParser::Expression_operatorContext::Expression_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Expression_operatorContext::PLUS() {
  return getToken(SPECTREParser::PLUS, 0);
}

tree::TerminalNode* SPECTREParser::Expression_operatorContext::MINUS() {
  return getToken(SPECTREParser::MINUS, 0);
}

tree::TerminalNode* SPECTREParser::Expression_operatorContext::STAR() {
  return getToken(SPECTREParser::STAR, 0);
}

tree::TerminalNode* SPECTREParser::Expression_operatorContext::SLASH() {
  return getToken(SPECTREParser::SLASH, 0);
}

tree::TerminalNode* SPECTREParser::Expression_operatorContext::LOGIC_AND() {
  return getToken(SPECTREParser::LOGIC_AND, 0);
}

tree::TerminalNode* SPECTREParser::Expression_operatorContext::LOGIC_BITWISE_AND() {
  return getToken(SPECTREParser::LOGIC_BITWISE_AND, 0);
}

tree::TerminalNode* SPECTREParser::Expression_operatorContext::LOGIC_OR() {
  return getToken(SPECTREParser::LOGIC_OR, 0);
}

tree::TerminalNode* SPECTREParser::Expression_operatorContext::LOGIC_BITWISE_OR() {
  return getToken(SPECTREParser::LOGIC_BITWISE_OR, 0);
}

tree::TerminalNode* SPECTREParser::Expression_operatorContext::LOGIC_EQUAL() {
  return getToken(SPECTREParser::LOGIC_EQUAL, 0);
}

tree::TerminalNode* SPECTREParser::Expression_operatorContext::LOGIC_NOT_EQUAL() {
  return getToken(SPECTREParser::LOGIC_NOT_EQUAL, 0);
}

tree::TerminalNode* SPECTREParser::Expression_operatorContext::LOGIC_XOR() {
  return getToken(SPECTREParser::LOGIC_XOR, 0);
}

tree::TerminalNode* SPECTREParser::Expression_operatorContext::LESS_THAN() {
  return getToken(SPECTREParser::LESS_THAN, 0);
}

tree::TerminalNode* SPECTREParser::Expression_operatorContext::LESS_THAN_EQUAL() {
  return getToken(SPECTREParser::LESS_THAN_EQUAL, 0);
}

tree::TerminalNode* SPECTREParser::Expression_operatorContext::GREATER_THAN() {
  return getToken(SPECTREParser::GREATER_THAN, 0);
}

tree::TerminalNode* SPECTREParser::Expression_operatorContext::GREATER_THAN_EQUAL() {
  return getToken(SPECTREParser::GREATER_THAN_EQUAL, 0);
}

tree::TerminalNode* SPECTREParser::Expression_operatorContext::EXCLAMATION_MARK() {
  return getToken(SPECTREParser::EXCLAMATION_MARK, 0);
}

tree::TerminalNode* SPECTREParser::Expression_operatorContext::BITWISE_SHIFT_LEFT() {
  return getToken(SPECTREParser::BITWISE_SHIFT_LEFT, 0);
}

tree::TerminalNode* SPECTREParser::Expression_operatorContext::BITWISE_SHIFT_RIGHT() {
  return getToken(SPECTREParser::BITWISE_SHIFT_RIGHT, 0);
}

tree::TerminalNode* SPECTREParser::Expression_operatorContext::POWER_OPERATOR() {
  return getToken(SPECTREParser::POWER_OPERATOR, 0);
}

tree::TerminalNode* SPECTREParser::Expression_operatorContext::CARET() {
  return getToken(SPECTREParser::CARET, 0);
}

tree::TerminalNode* SPECTREParser::Expression_operatorContext::PERCENT() {
  return getToken(SPECTREParser::PERCENT, 0);
}


size_t SPECTREParser::Expression_operatorContext::getRuleIndex() const {
  return SPECTREParser::RuleExpression_operator;
}

void SPECTREParser::Expression_operatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_operator(this);
}

void SPECTREParser::Expression_operatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_operator(this);
}


antlrcpp::Any SPECTREParser::Expression_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitExpression_operator(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Expression_operatorContext* SPECTREParser::expression_operator() {
  Expression_operatorContext *_localctx = _tracker.createInstance<Expression_operatorContext>(_ctx, getState());
  enterRule(_localctx, 228, SPECTREParser::RuleExpression_operator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2344);
    _la = _input->LA(1);
    if (!(((((_la - 169) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 169)) & ((1ULL << (SPECTREParser::EXCLAMATION_MARK - 169))
      | (1ULL << (SPECTREParser::LESS_THAN - 169))
      | (1ULL << (SPECTREParser::GREATER_THAN - 169))
      | (1ULL << (SPECTREParser::LESS_THAN_EQUAL - 169))
      | (1ULL << (SPECTREParser::GREATER_THAN_EQUAL - 169))
      | (1ULL << (SPECTREParser::LOGIC_EQUAL - 169))
      | (1ULL << (SPECTREParser::LOGIC_NOT_EQUAL - 169))
      | (1ULL << (SPECTREParser::LOGIC_AND - 169))
      | (1ULL << (SPECTREParser::LOGIC_OR - 169))
      | (1ULL << (SPECTREParser::LOGIC_BITWISE_AND - 169))
      | (1ULL << (SPECTREParser::LOGIC_BITWISE_OR - 169))
      | (1ULL << (SPECTREParser::LOGIC_XOR - 169))
      | (1ULL << (SPECTREParser::BITWISE_SHIFT_LEFT - 169))
      | (1ULL << (SPECTREParser::BITWISE_SHIFT_RIGHT - 169))
      | (1ULL << (SPECTREParser::POWER_OPERATOR - 169))
      | (1ULL << (SPECTREParser::PLUS - 169))
      | (1ULL << (SPECTREParser::MINUS - 169))
      | (1ULL << (SPECTREParser::STAR - 169))
      | (1ULL << (SPECTREParser::SLASH - 169))
      | (1ULL << (SPECTREParser::PERCENT - 169))
      | (1ULL << (SPECTREParser::CARET - 169)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression_atomContext ------------------------------------------------------------------

SPECTREParser::Expression_atomContext::Expression_atomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Expression_atomContext::NUMBER() {
  return getToken(SPECTREParser::NUMBER, 0);
}

tree::TerminalNode* SPECTREParser::Expression_atomContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

tree::TerminalNode* SPECTREParser::Expression_atomContext::STRING() {
  return getToken(SPECTREParser::STRING, 0);
}

tree::TerminalNode* SPECTREParser::Expression_atomContext::PERCENTAGE() {
  return getToken(SPECTREParser::PERCENTAGE, 0);
}

SPECTREParser::KeywordContext* SPECTREParser::Expression_atomContext::keyword() {
  return getRuleContext<SPECTREParser::KeywordContext>(0);
}

SPECTREParser::Analysis_typeContext* SPECTREParser::Expression_atomContext::analysis_type() {
  return getRuleContext<SPECTREParser::Analysis_typeContext>(0);
}

SPECTREParser::Component_typeContext* SPECTREParser::Expression_atomContext::component_type() {
  return getRuleContext<SPECTREParser::Component_typeContext>(0);
}


size_t SPECTREParser::Expression_atomContext::getRuleIndex() const {
  return SPECTREParser::RuleExpression_atom;
}

void SPECTREParser::Expression_atomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_atom(this);
}

void SPECTREParser::Expression_atomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_atom(this);
}


antlrcpp::Any SPECTREParser::Expression_atomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitExpression_atom(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Expression_atomContext* SPECTREParser::expression_atom() {
  Expression_atomContext *_localctx = _tracker.createInstance<Expression_atomContext>(_ctx, getState());
  enterRule(_localctx, 230, SPECTREParser::RuleExpression_atom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(2353);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SPECTREParser::NUMBER: {
        enterOuterAlt(_localctx, 1);
        setState(2346);
        match(SPECTREParser::NUMBER);
        break;
      }

      case SPECTREParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(2347);
        match(SPECTREParser::ID);
        break;
      }

      case SPECTREParser::STRING: {
        enterOuterAlt(_localctx, 3);
        setState(2348);
        match(SPECTREParser::STRING);
        break;
      }

      case SPECTREParser::PERCENTAGE: {
        enterOuterAlt(_localctx, 4);
        setState(2349);
        match(SPECTREParser::PERCENTAGE);
        break;
      }

      case SPECTREParser::ALTER:
      case SPECTREParser::ALTERGROUP:
      case SPECTREParser::OPTIONS:
      case SPECTREParser::SET:
      case SPECTREParser::SHELL:
      case SPECTREParser::INFO:
      case SPECTREParser::NODESET:
      case SPECTREParser::IC:
      case SPECTREParser::ASSERT:
      case SPECTREParser::CHECK:
      case SPECTREParser::LANGUAGE:
      case SPECTREParser::PORTS:
      case SPECTREParser::WAVE:
      case SPECTREParser::PWL:
      case SPECTREParser::SIN:
      case SPECTREParser::SFFM:
      case SPECTREParser::PULSE:
      case SPECTREParser::COEFFS:
      case SPECTREParser::INSENSITIVE:
      case SPECTREParser::IF:
      case SPECTREParser::ELSE:
      case SPECTREParser::PARAMETERS:
      case SPECTREParser::ANALOGMODEL:
      case SPECTREParser::CHECKPOINT:
      case SPECTREParser::SPECTRE:
      case SPECTREParser::SPICE:
      case SPECTREParser::STATISTICS:
      case SPECTREParser::PROCESS:
      case SPECTREParser::CORRELATE:
      case SPECTREParser::TRUNCATE:
      case SPECTREParser::MISMATCH:
      case SPECTREParser::VARY:
      case SPECTREParser::RELIABILITY: {
        enterOuterAlt(_localctx, 5);
        setState(2350);
        keyword();
        break;
      }

      case SPECTREParser::AC:
      case SPECTREParser::ACMATCH:
      case SPECTREParser::DC:
      case SPECTREParser::DCMATCH:
      case SPECTREParser::ENVLP:
      case SPECTREParser::SP:
      case SPECTREParser::STB:
      case SPECTREParser::SWEEP:
      case SPECTREParser::TDR:
      case SPECTREParser::TRAN:
      case SPECTREParser::XF:
      case SPECTREParser::PAC:
      case SPECTREParser::PDISTO:
      case SPECTREParser::PNOISE:
      case SPECTREParser::PSP:
      case SPECTREParser::PSS:
      case SPECTREParser::PXF:
      case SPECTREParser::PZ:
      case SPECTREParser::QPAC:
      case SPECTREParser::QPNOISE:
      case SPECTREParser::QPSP:
      case SPECTREParser::QPSS:
      case SPECTREParser::QPXF:
      case SPECTREParser::SENS:
      case SPECTREParser::MONTECARLO:
      case SPECTREParser::NOISE:
      case SPECTREParser::CHECKLIMIT: {
        enterOuterAlt(_localctx, 6);
        setState(2351);
        analysis_type();
        break;
      }

      case SPECTREParser::A2D:
      case SPECTREParser::B3SOIPD:
      case SPECTREParser::BJT:
      case SPECTREParser::BJT301:
      case SPECTREParser::BJT500:
      case SPECTREParser::BJT503:
      case SPECTREParser::BJT504:
      case SPECTREParser::BJT504T:
      case SPECTREParser::BSIM1:
      case SPECTREParser::BSIM2:
      case SPECTREParser::BSIM3:
      case SPECTREParser::BSIM3V3:
      case SPECTREParser::BSIM4:
      case SPECTREParser::BSIMSOI:
      case SPECTREParser::BTASOI:
      case SPECTREParser::CAPACITOR:
      case SPECTREParser::CCCS:
      case SPECTREParser::CCVS:
      case SPECTREParser::CKTROM:
      case SPECTREParser::CORE:
      case SPECTREParser::D2A:
      case SPECTREParser::DELAY:
      case SPECTREParser::DIO500:
      case SPECTREParser::DIODE:
      case SPECTREParser::EKV:
      case SPECTREParser::FOURIER:
      case SPECTREParser::GAAS:
      case SPECTREParser::HBT:
      case SPECTREParser::HISIM:
      case SPECTREParser::HVMOS:
      case SPECTREParser::INDUCTOR:
      case SPECTREParser::INTCAP:
      case SPECTREParser::IPROBE:
      case SPECTREParser::ISOURCE:
      case SPECTREParser::JFET:
      case SPECTREParser::JUNCAP:
      case SPECTREParser::MISNAN:
      case SPECTREParser::MOS11011:
      case SPECTREParser::MOS11010:
      case SPECTREParser::MOS3002:
      case SPECTREParser::MOS3100:
      case SPECTREParser::MOS1000:
      case SPECTREParser::MOS1100:
      case SPECTREParser::MUTUAL_INDUCTOR:
      case SPECTREParser::MSLINE:
      case SPECTREParser::MTLINE:
      case SPECTREParser::MOS705:
      case SPECTREParser::MOS902:
      case SPECTREParser::MOS903:
      case SPECTREParser::MOS30:
      case SPECTREParser::MOS40:
      case SPECTREParser::MOS15:
      case SPECTREParser::MOS0:
      case SPECTREParser::MOS1:
      case SPECTREParser::MOS2:
      case SPECTREParser::MOS3:
      case SPECTREParser::NODCAP:
      case SPECTREParser::NODE:
      case SPECTREParser::NPORT:
      case SPECTREParser::PARAMTEST:
      case SPECTREParser::PCCCS:
      case SPECTREParser::PCCVS:
      case SPECTREParser::PHY_RES:
      case SPECTREParser::PORT:
      case SPECTREParser::PSITFT:
      case SPECTREParser::PVCCS:
      case SPECTREParser::PVCVS:
      case SPECTREParser::QUANTITY:
      case SPECTREParser::RDIFF:
      case SPECTREParser::RELAY:
      case SPECTREParser::RESISTOR:
      case SPECTREParser::SCCCS:
      case SPECTREParser::SCCVS:
      case SPECTREParser::SVCCS:
      case SPECTREParser::SVCVS:
      case SPECTREParser::SWITCH:
      case SPECTREParser::TLINE:
      case SPECTREParser::TOM2:
      case SPECTREParser::TOM3:
      case SPECTREParser::TRANSFORMER:
      case SPECTREParser::VBIC:
      case SPECTREParser::VCCS:
      case SPECTREParser::VCVS:
      case SPECTREParser::VSOURCE:
      case SPECTREParser::WINDING:
      case SPECTREParser::ZCCCS:
      case SPECTREParser::ZCCVS:
      case SPECTREParser::ZVCCS:
      case SPECTREParser::ZVCVS:
      case SPECTREParser::BSOURCE: {
        enterOuterAlt(_localctx, 7);
        setState(2352);
        component_type();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parameter_listContext ------------------------------------------------------------------

SPECTREParser::Parameter_listContext::Parameter_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SPECTREParser::Parameter_list_itemContext *> SPECTREParser::Parameter_listContext::parameter_list_item() {
  return getRuleContexts<SPECTREParser::Parameter_list_itemContext>();
}

SPECTREParser::Parameter_list_itemContext* SPECTREParser::Parameter_listContext::parameter_list_item(size_t i) {
  return getRuleContext<SPECTREParser::Parameter_list_itemContext>(i);
}


size_t SPECTREParser::Parameter_listContext::getRuleIndex() const {
  return SPECTREParser::RuleParameter_list;
}

void SPECTREParser::Parameter_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter_list(this);
}

void SPECTREParser::Parameter_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter_list(this);
}


antlrcpp::Any SPECTREParser::Parameter_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitParameter_list(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Parameter_listContext* SPECTREParser::parameter_list() {
  Parameter_listContext *_localctx = _tracker.createInstance<Parameter_listContext>(_ctx, getState());
  enterRule(_localctx, 232, SPECTREParser::RuleParameter_list);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(2356); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(2355);
              parameter_list_item();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(2358); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 442, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parameter_list_itemContext ------------------------------------------------------------------

SPECTREParser::Parameter_list_itemContext::Parameter_list_itemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SPECTREParser::Parameter_idContext* SPECTREParser::Parameter_list_itemContext::parameter_id() {
  return getRuleContext<SPECTREParser::Parameter_idContext>(0);
}

tree::TerminalNode* SPECTREParser::Parameter_list_itemContext::EQUAL() {
  return getToken(SPECTREParser::EQUAL, 0);
}

SPECTREParser::Array_expressionContext* SPECTREParser::Parameter_list_itemContext::array_expression() {
  return getRuleContext<SPECTREParser::Array_expressionContext>(0);
}

SPECTREParser::ExpressionContext* SPECTREParser::Parameter_list_itemContext::expression() {
  return getRuleContext<SPECTREParser::ExpressionContext>(0);
}

SPECTREParser::FilepathContext* SPECTREParser::Parameter_list_itemContext::filepath() {
  return getRuleContext<SPECTREParser::FilepathContext>(0);
}


size_t SPECTREParser::Parameter_list_itemContext::getRuleIndex() const {
  return SPECTREParser::RuleParameter_list_item;
}

void SPECTREParser::Parameter_list_itemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter_list_item(this);
}

void SPECTREParser::Parameter_list_itemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter_list_item(this);
}


antlrcpp::Any SPECTREParser::Parameter_list_itemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitParameter_list_item(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Parameter_list_itemContext* SPECTREParser::parameter_list_item() {
  Parameter_list_itemContext *_localctx = _tracker.createInstance<Parameter_list_itemContext>(_ctx, getState());
  enterRule(_localctx, 234, SPECTREParser::RuleParameter_list_item);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(2373);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 443, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(2360);
      parameter_id();
      setState(2361);
      match(SPECTREParser::EQUAL);
      setState(2362);
      array_expression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(2364);
      parameter_id();
      setState(2365);
      match(SPECTREParser::EQUAL);
      setState(2366);
      expression(0);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(2368);
      parameter_id();
      setState(2369);
      match(SPECTREParser::EQUAL);
      setState(2370);
      filepath();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(2372);
      parameter_id();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Array_expressionContext ------------------------------------------------------------------

SPECTREParser::Array_expressionContext::Array_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Array_expressionContext::OPEN_SQUARE() {
  return getToken(SPECTREParser::OPEN_SQUARE, 0);
}

tree::TerminalNode* SPECTREParser::Array_expressionContext::CLOSE_SQUARE() {
  return getToken(SPECTREParser::CLOSE_SQUARE, 0);
}

std::vector<SPECTREParser::Array_itemContext *> SPECTREParser::Array_expressionContext::array_item() {
  return getRuleContexts<SPECTREParser::Array_itemContext>();
}

SPECTREParser::Array_itemContext* SPECTREParser::Array_expressionContext::array_item(size_t i) {
  return getRuleContext<SPECTREParser::Array_itemContext>(i);
}


size_t SPECTREParser::Array_expressionContext::getRuleIndex() const {
  return SPECTREParser::RuleArray_expression;
}

void SPECTREParser::Array_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArray_expression(this);
}

void SPECTREParser::Array_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArray_expression(this);
}


antlrcpp::Any SPECTREParser::Array_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitArray_expression(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Array_expressionContext* SPECTREParser::array_expression() {
  Array_expressionContext *_localctx = _tracker.createInstance<Array_expressionContext>(_ctx, getState());
  enterRule(_localctx, 236, SPECTREParser::RuleArray_expression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2375);
    match(SPECTREParser::OPEN_SQUARE);
    setState(2379);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SPECTREParser::ALTER)
      | (1ULL << SPECTREParser::ALTERGROUP)
      | (1ULL << SPECTREParser::OPTIONS)
      | (1ULL << SPECTREParser::SET)
      | (1ULL << SPECTREParser::SHELL)
      | (1ULL << SPECTREParser::INFO)
      | (1ULL << SPECTREParser::NODESET)
      | (1ULL << SPECTREParser::IC)
      | (1ULL << SPECTREParser::ASSERT)
      | (1ULL << SPECTREParser::CHECK)
      | (1ULL << SPECTREParser::LANGUAGE)
      | (1ULL << SPECTREParser::PORTS)
      | (1ULL << SPECTREParser::WAVE)
      | (1ULL << SPECTREParser::PWL)
      | (1ULL << SPECTREParser::SIN)
      | (1ULL << SPECTREParser::SFFM)
      | (1ULL << SPECTREParser::PULSE)
      | (1ULL << SPECTREParser::COEFFS)
      | (1ULL << SPECTREParser::INSENSITIVE)
      | (1ULL << SPECTREParser::IF)
      | (1ULL << SPECTREParser::ELSE)
      | (1ULL << SPECTREParser::PARAMETERS)
      | (1ULL << SPECTREParser::ANALOGMODEL)
      | (1ULL << SPECTREParser::CHECKPOINT)
      | (1ULL << SPECTREParser::SPECTRE)
      | (1ULL << SPECTREParser::SPICE)
      | (1ULL << SPECTREParser::STATISTICS)
      | (1ULL << SPECTREParser::PROCESS)
      | (1ULL << SPECTREParser::CORRELATE)
      | (1ULL << SPECTREParser::TRUNCATE)
      | (1ULL << SPECTREParser::MISMATCH)
      | (1ULL << SPECTREParser::VARY)
      | (1ULL << SPECTREParser::RELIABILITY)
      | (1ULL << SPECTREParser::AC)
      | (1ULL << SPECTREParser::ACMATCH)
      | (1ULL << SPECTREParser::DC)
      | (1ULL << SPECTREParser::DCMATCH)
      | (1ULL << SPECTREParser::ENVLP)
      | (1ULL << SPECTREParser::SP)
      | (1ULL << SPECTREParser::STB)
      | (1ULL << SPECTREParser::SWEEP)
      | (1ULL << SPECTREParser::TDR)
      | (1ULL << SPECTREParser::TRAN)
      | (1ULL << SPECTREParser::XF)
      | (1ULL << SPECTREParser::PAC)
      | (1ULL << SPECTREParser::PDISTO))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (SPECTREParser::PNOISE - 64))
      | (1ULL << (SPECTREParser::PSP - 64))
      | (1ULL << (SPECTREParser::PSS - 64))
      | (1ULL << (SPECTREParser::PXF - 64))
      | (1ULL << (SPECTREParser::PZ - 64))
      | (1ULL << (SPECTREParser::QPAC - 64))
      | (1ULL << (SPECTREParser::QPNOISE - 64))
      | (1ULL << (SPECTREParser::QPSP - 64))
      | (1ULL << (SPECTREParser::QPSS - 64))
      | (1ULL << (SPECTREParser::QPXF - 64))
      | (1ULL << (SPECTREParser::SENS - 64))
      | (1ULL << (SPECTREParser::MONTECARLO - 64))
      | (1ULL << (SPECTREParser::NOISE - 64))
      | (1ULL << (SPECTREParser::CHECKLIMIT - 64))
      | (1ULL << (SPECTREParser::A2D - 64))
      | (1ULL << (SPECTREParser::B3SOIPD - 64))
      | (1ULL << (SPECTREParser::BJT - 64))
      | (1ULL << (SPECTREParser::BJT301 - 64))
      | (1ULL << (SPECTREParser::BJT500 - 64))
      | (1ULL << (SPECTREParser::BJT503 - 64))
      | (1ULL << (SPECTREParser::BJT504 - 64))
      | (1ULL << (SPECTREParser::BJT504T - 64))
      | (1ULL << (SPECTREParser::BSIM1 - 64))
      | (1ULL << (SPECTREParser::BSIM2 - 64))
      | (1ULL << (SPECTREParser::BSIM3 - 64))
      | (1ULL << (SPECTREParser::BSIM3V3 - 64))
      | (1ULL << (SPECTREParser::BSIM4 - 64))
      | (1ULL << (SPECTREParser::BSIMSOI - 64))
      | (1ULL << (SPECTREParser::BTASOI - 64))
      | (1ULL << (SPECTREParser::CAPACITOR - 64))
      | (1ULL << (SPECTREParser::CCCS - 64))
      | (1ULL << (SPECTREParser::CCVS - 64))
      | (1ULL << (SPECTREParser::CKTROM - 64))
      | (1ULL << (SPECTREParser::CORE - 64))
      | (1ULL << (SPECTREParser::D2A - 64))
      | (1ULL << (SPECTREParser::DELAY - 64))
      | (1ULL << (SPECTREParser::DIO500 - 64))
      | (1ULL << (SPECTREParser::DIODE - 64))
      | (1ULL << (SPECTREParser::EKV - 64))
      | (1ULL << (SPECTREParser::FOURIER - 64))
      | (1ULL << (SPECTREParser::GAAS - 64))
      | (1ULL << (SPECTREParser::HBT - 64))
      | (1ULL << (SPECTREParser::HISIM - 64))
      | (1ULL << (SPECTREParser::HVMOS - 64))
      | (1ULL << (SPECTREParser::INDUCTOR - 64))
      | (1ULL << (SPECTREParser::INTCAP - 64))
      | (1ULL << (SPECTREParser::IPROBE - 64))
      | (1ULL << (SPECTREParser::ISOURCE - 64))
      | (1ULL << (SPECTREParser::JFET - 64))
      | (1ULL << (SPECTREParser::JUNCAP - 64))
      | (1ULL << (SPECTREParser::MISNAN - 64))
      | (1ULL << (SPECTREParser::MOS11011 - 64))
      | (1ULL << (SPECTREParser::MOS11010 - 64))
      | (1ULL << (SPECTREParser::MOS3002 - 64))
      | (1ULL << (SPECTREParser::MOS3100 - 64))
      | (1ULL << (SPECTREParser::MOS1000 - 64))
      | (1ULL << (SPECTREParser::MOS1100 - 64))
      | (1ULL << (SPECTREParser::MUTUAL_INDUCTOR - 64))
      | (1ULL << (SPECTREParser::MSLINE - 64))
      | (1ULL << (SPECTREParser::MTLINE - 64))
      | (1ULL << (SPECTREParser::MOS705 - 64))
      | (1ULL << (SPECTREParser::MOS902 - 64))
      | (1ULL << (SPECTREParser::MOS903 - 64))
      | (1ULL << (SPECTREParser::MOS30 - 64)))) != 0) || ((((_la - 128) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 128)) & ((1ULL << (SPECTREParser::MOS40 - 128))
      | (1ULL << (SPECTREParser::MOS15 - 128))
      | (1ULL << (SPECTREParser::MOS0 - 128))
      | (1ULL << (SPECTREParser::MOS1 - 128))
      | (1ULL << (SPECTREParser::MOS2 - 128))
      | (1ULL << (SPECTREParser::MOS3 - 128))
      | (1ULL << (SPECTREParser::NODCAP - 128))
      | (1ULL << (SPECTREParser::NODE - 128))
      | (1ULL << (SPECTREParser::NPORT - 128))
      | (1ULL << (SPECTREParser::PARAMTEST - 128))
      | (1ULL << (SPECTREParser::PCCCS - 128))
      | (1ULL << (SPECTREParser::PCCVS - 128))
      | (1ULL << (SPECTREParser::PHY_RES - 128))
      | (1ULL << (SPECTREParser::PORT - 128))
      | (1ULL << (SPECTREParser::PSITFT - 128))
      | (1ULL << (SPECTREParser::PVCCS - 128))
      | (1ULL << (SPECTREParser::PVCVS - 128))
      | (1ULL << (SPECTREParser::QUANTITY - 128))
      | (1ULL << (SPECTREParser::RDIFF - 128))
      | (1ULL << (SPECTREParser::RELAY - 128))
      | (1ULL << (SPECTREParser::RESISTOR - 128))
      | (1ULL << (SPECTREParser::SCCCS - 128))
      | (1ULL << (SPECTREParser::SCCVS - 128))
      | (1ULL << (SPECTREParser::SVCCS - 128))
      | (1ULL << (SPECTREParser::SVCVS - 128))
      | (1ULL << (SPECTREParser::SWITCH - 128))
      | (1ULL << (SPECTREParser::TLINE - 128))
      | (1ULL << (SPECTREParser::TOM2 - 128))
      | (1ULL << (SPECTREParser::TOM3 - 128))
      | (1ULL << (SPECTREParser::TRANSFORMER - 128))
      | (1ULL << (SPECTREParser::VBIC - 128))
      | (1ULL << (SPECTREParser::VCCS - 128))
      | (1ULL << (SPECTREParser::VCVS - 128))
      | (1ULL << (SPECTREParser::VSOURCE - 128))
      | (1ULL << (SPECTREParser::WINDING - 128))
      | (1ULL << (SPECTREParser::ZCCCS - 128))
      | (1ULL << (SPECTREParser::ZCCVS - 128))
      | (1ULL << (SPECTREParser::ZVCCS - 128))
      | (1ULL << (SPECTREParser::ZVCVS - 128))
      | (1ULL << (SPECTREParser::BSOURCE - 128)))) != 0) || ((((_la - 214) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 214)) & ((1ULL << (SPECTREParser::NUMBER - 214))
      | (1ULL << (SPECTREParser::ID - 214))
      | (1ULL << (SPECTREParser::STRING - 214))
      | (1ULL << (SPECTREParser::PERCENTAGE - 214)))) != 0)) {
      setState(2376);
      array_item();
      setState(2381);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(2382);
    match(SPECTREParser::CLOSE_SQUARE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Array_itemContext ------------------------------------------------------------------

SPECTREParser::Array_itemContext::Array_itemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Array_itemContext::NUMBER() {
  return getToken(SPECTREParser::NUMBER, 0);
}

tree::TerminalNode* SPECTREParser::Array_itemContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

tree::TerminalNode* SPECTREParser::Array_itemContext::STRING() {
  return getToken(SPECTREParser::STRING, 0);
}

tree::TerminalNode* SPECTREParser::Array_itemContext::PERCENTAGE() {
  return getToken(SPECTREParser::PERCENTAGE, 0);
}

SPECTREParser::KeywordContext* SPECTREParser::Array_itemContext::keyword() {
  return getRuleContext<SPECTREParser::KeywordContext>(0);
}

SPECTREParser::Analysis_typeContext* SPECTREParser::Array_itemContext::analysis_type() {
  return getRuleContext<SPECTREParser::Analysis_typeContext>(0);
}

SPECTREParser::Component_typeContext* SPECTREParser::Array_itemContext::component_type() {
  return getRuleContext<SPECTREParser::Component_typeContext>(0);
}


size_t SPECTREParser::Array_itemContext::getRuleIndex() const {
  return SPECTREParser::RuleArray_item;
}

void SPECTREParser::Array_itemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArray_item(this);
}

void SPECTREParser::Array_itemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArray_item(this);
}


antlrcpp::Any SPECTREParser::Array_itemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitArray_item(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Array_itemContext* SPECTREParser::array_item() {
  Array_itemContext *_localctx = _tracker.createInstance<Array_itemContext>(_ctx, getState());
  enterRule(_localctx, 238, SPECTREParser::RuleArray_item);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(2391);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SPECTREParser::NUMBER: {
        enterOuterAlt(_localctx, 1);
        setState(2384);
        match(SPECTREParser::NUMBER);
        break;
      }

      case SPECTREParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(2385);
        match(SPECTREParser::ID);
        break;
      }

      case SPECTREParser::STRING: {
        enterOuterAlt(_localctx, 3);
        setState(2386);
        match(SPECTREParser::STRING);
        break;
      }

      case SPECTREParser::PERCENTAGE: {
        enterOuterAlt(_localctx, 4);
        setState(2387);
        match(SPECTREParser::PERCENTAGE);
        break;
      }

      case SPECTREParser::ALTER:
      case SPECTREParser::ALTERGROUP:
      case SPECTREParser::OPTIONS:
      case SPECTREParser::SET:
      case SPECTREParser::SHELL:
      case SPECTREParser::INFO:
      case SPECTREParser::NODESET:
      case SPECTREParser::IC:
      case SPECTREParser::ASSERT:
      case SPECTREParser::CHECK:
      case SPECTREParser::LANGUAGE:
      case SPECTREParser::PORTS:
      case SPECTREParser::WAVE:
      case SPECTREParser::PWL:
      case SPECTREParser::SIN:
      case SPECTREParser::SFFM:
      case SPECTREParser::PULSE:
      case SPECTREParser::COEFFS:
      case SPECTREParser::INSENSITIVE:
      case SPECTREParser::IF:
      case SPECTREParser::ELSE:
      case SPECTREParser::PARAMETERS:
      case SPECTREParser::ANALOGMODEL:
      case SPECTREParser::CHECKPOINT:
      case SPECTREParser::SPECTRE:
      case SPECTREParser::SPICE:
      case SPECTREParser::STATISTICS:
      case SPECTREParser::PROCESS:
      case SPECTREParser::CORRELATE:
      case SPECTREParser::TRUNCATE:
      case SPECTREParser::MISMATCH:
      case SPECTREParser::VARY:
      case SPECTREParser::RELIABILITY: {
        enterOuterAlt(_localctx, 5);
        setState(2388);
        keyword();
        break;
      }

      case SPECTREParser::AC:
      case SPECTREParser::ACMATCH:
      case SPECTREParser::DC:
      case SPECTREParser::DCMATCH:
      case SPECTREParser::ENVLP:
      case SPECTREParser::SP:
      case SPECTREParser::STB:
      case SPECTREParser::SWEEP:
      case SPECTREParser::TDR:
      case SPECTREParser::TRAN:
      case SPECTREParser::XF:
      case SPECTREParser::PAC:
      case SPECTREParser::PDISTO:
      case SPECTREParser::PNOISE:
      case SPECTREParser::PSP:
      case SPECTREParser::PSS:
      case SPECTREParser::PXF:
      case SPECTREParser::PZ:
      case SPECTREParser::QPAC:
      case SPECTREParser::QPNOISE:
      case SPECTREParser::QPSP:
      case SPECTREParser::QPSS:
      case SPECTREParser::QPXF:
      case SPECTREParser::SENS:
      case SPECTREParser::MONTECARLO:
      case SPECTREParser::NOISE:
      case SPECTREParser::CHECKLIMIT: {
        enterOuterAlt(_localctx, 6);
        setState(2389);
        analysis_type();
        break;
      }

      case SPECTREParser::A2D:
      case SPECTREParser::B3SOIPD:
      case SPECTREParser::BJT:
      case SPECTREParser::BJT301:
      case SPECTREParser::BJT500:
      case SPECTREParser::BJT503:
      case SPECTREParser::BJT504:
      case SPECTREParser::BJT504T:
      case SPECTREParser::BSIM1:
      case SPECTREParser::BSIM2:
      case SPECTREParser::BSIM3:
      case SPECTREParser::BSIM3V3:
      case SPECTREParser::BSIM4:
      case SPECTREParser::BSIMSOI:
      case SPECTREParser::BTASOI:
      case SPECTREParser::CAPACITOR:
      case SPECTREParser::CCCS:
      case SPECTREParser::CCVS:
      case SPECTREParser::CKTROM:
      case SPECTREParser::CORE:
      case SPECTREParser::D2A:
      case SPECTREParser::DELAY:
      case SPECTREParser::DIO500:
      case SPECTREParser::DIODE:
      case SPECTREParser::EKV:
      case SPECTREParser::FOURIER:
      case SPECTREParser::GAAS:
      case SPECTREParser::HBT:
      case SPECTREParser::HISIM:
      case SPECTREParser::HVMOS:
      case SPECTREParser::INDUCTOR:
      case SPECTREParser::INTCAP:
      case SPECTREParser::IPROBE:
      case SPECTREParser::ISOURCE:
      case SPECTREParser::JFET:
      case SPECTREParser::JUNCAP:
      case SPECTREParser::MISNAN:
      case SPECTREParser::MOS11011:
      case SPECTREParser::MOS11010:
      case SPECTREParser::MOS3002:
      case SPECTREParser::MOS3100:
      case SPECTREParser::MOS1000:
      case SPECTREParser::MOS1100:
      case SPECTREParser::MUTUAL_INDUCTOR:
      case SPECTREParser::MSLINE:
      case SPECTREParser::MTLINE:
      case SPECTREParser::MOS705:
      case SPECTREParser::MOS902:
      case SPECTREParser::MOS903:
      case SPECTREParser::MOS30:
      case SPECTREParser::MOS40:
      case SPECTREParser::MOS15:
      case SPECTREParser::MOS0:
      case SPECTREParser::MOS1:
      case SPECTREParser::MOS2:
      case SPECTREParser::MOS3:
      case SPECTREParser::NODCAP:
      case SPECTREParser::NODE:
      case SPECTREParser::NPORT:
      case SPECTREParser::PARAMTEST:
      case SPECTREParser::PCCCS:
      case SPECTREParser::PCCVS:
      case SPECTREParser::PHY_RES:
      case SPECTREParser::PORT:
      case SPECTREParser::PSITFT:
      case SPECTREParser::PVCCS:
      case SPECTREParser::PVCVS:
      case SPECTREParser::QUANTITY:
      case SPECTREParser::RDIFF:
      case SPECTREParser::RELAY:
      case SPECTREParser::RESISTOR:
      case SPECTREParser::SCCCS:
      case SPECTREParser::SCCVS:
      case SPECTREParser::SVCCS:
      case SPECTREParser::SVCVS:
      case SPECTREParser::SWITCH:
      case SPECTREParser::TLINE:
      case SPECTREParser::TOM2:
      case SPECTREParser::TOM3:
      case SPECTREParser::TRANSFORMER:
      case SPECTREParser::VBIC:
      case SPECTREParser::VCCS:
      case SPECTREParser::VCVS:
      case SPECTREParser::VSOURCE:
      case SPECTREParser::WINDING:
      case SPECTREParser::ZCCCS:
      case SPECTREParser::ZCCVS:
      case SPECTREParser::ZVCCS:
      case SPECTREParser::ZVCVS:
      case SPECTREParser::BSOURCE: {
        enterOuterAlt(_localctx, 7);
        setState(2390);
        component_type();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parameter_assignContext ------------------------------------------------------------------

SPECTREParser::Parameter_assignContext::Parameter_assignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SPECTREParser::Parameter_idContext* SPECTREParser::Parameter_assignContext::parameter_id() {
  return getRuleContext<SPECTREParser::Parameter_idContext>(0);
}

tree::TerminalNode* SPECTREParser::Parameter_assignContext::EQUAL() {
  return getToken(SPECTREParser::EQUAL, 0);
}

SPECTREParser::ExpressionContext* SPECTREParser::Parameter_assignContext::expression() {
  return getRuleContext<SPECTREParser::ExpressionContext>(0);
}

SPECTREParser::FilepathContext* SPECTREParser::Parameter_assignContext::filepath() {
  return getRuleContext<SPECTREParser::FilepathContext>(0);
}


size_t SPECTREParser::Parameter_assignContext::getRuleIndex() const {
  return SPECTREParser::RuleParameter_assign;
}

void SPECTREParser::Parameter_assignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter_assign(this);
}

void SPECTREParser::Parameter_assignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter_assign(this);
}


antlrcpp::Any SPECTREParser::Parameter_assignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitParameter_assign(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Parameter_assignContext* SPECTREParser::parameter_assign() {
  Parameter_assignContext *_localctx = _tracker.createInstance<Parameter_assignContext>(_ctx, getState());
  enterRule(_localctx, 240, SPECTREParser::RuleParameter_assign);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(2401);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 446, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(2393);
      parameter_id();
      setState(2394);
      match(SPECTREParser::EQUAL);
      setState(2395);
      expression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(2397);
      parameter_id();
      setState(2398);
      match(SPECTREParser::EQUAL);
      setState(2399);
      filepath();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parameter_idContext ------------------------------------------------------------------

SPECTREParser::Parameter_idContext::Parameter_idContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> SPECTREParser::Parameter_idContext::ID() {
  return getTokens(SPECTREParser::ID);
}

tree::TerminalNode* SPECTREParser::Parameter_idContext::ID(size_t i) {
  return getToken(SPECTREParser::ID, i);
}

tree::TerminalNode* SPECTREParser::Parameter_idContext::SECTION() {
  return getToken(SPECTREParser::SECTION, 0);
}

tree::TerminalNode* SPECTREParser::Parameter_idContext::DC() {
  return getToken(SPECTREParser::DC, 0);
}

tree::TerminalNode* SPECTREParser::Parameter_idContext::SAVE() {
  return getToken(SPECTREParser::SAVE, 0);
}

tree::TerminalNode* SPECTREParser::Parameter_idContext::DELAY() {
  return getToken(SPECTREParser::DELAY, 0);
}

tree::TerminalNode* SPECTREParser::Parameter_idContext::PORTS() {
  return getToken(SPECTREParser::PORTS, 0);
}

std::vector<tree::TerminalNode *> SPECTREParser::Parameter_idContext::COLON() {
  return getTokens(SPECTREParser::COLON);
}

tree::TerminalNode* SPECTREParser::Parameter_idContext::COLON(size_t i) {
  return getToken(SPECTREParser::COLON, i);
}


size_t SPECTREParser::Parameter_idContext::getRuleIndex() const {
  return SPECTREParser::RuleParameter_id;
}

void SPECTREParser::Parameter_idContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter_id(this);
}

void SPECTREParser::Parameter_idContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter_id(this);
}


antlrcpp::Any SPECTREParser::Parameter_idContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitParameter_id(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Parameter_idContext* SPECTREParser::parameter_id() {
  Parameter_idContext *_localctx = _tracker.createInstance<Parameter_idContext>(_ctx, getState());
  enterRule(_localctx, 242, SPECTREParser::RuleParameter_id);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2403);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SPECTREParser::SECTION)
      | (1ULL << SPECTREParser::SAVE)
      | (1ULL << SPECTREParser::PORTS)
      | (1ULL << SPECTREParser::DC))) != 0) || _la == SPECTREParser::DELAY || _la == SPECTREParser::ID)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(2408);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SPECTREParser::COLON) {
      setState(2404);
      match(SPECTREParser::COLON);
      setState(2405);
      match(SPECTREParser::ID);
      setState(2410);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parameter_accessContext ------------------------------------------------------------------

SPECTREParser::Parameter_accessContext::Parameter_accessContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Parameter_accessContext::COLON() {
  return getToken(SPECTREParser::COLON, 0);
}

tree::TerminalNode* SPECTREParser::Parameter_accessContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

tree::TerminalNode* SPECTREParser::Parameter_accessContext::NUMBER() {
  return getToken(SPECTREParser::NUMBER, 0);
}


size_t SPECTREParser::Parameter_accessContext::getRuleIndex() const {
  return SPECTREParser::RuleParameter_access;
}

void SPECTREParser::Parameter_accessContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter_access(this);
}

void SPECTREParser::Parameter_accessContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter_access(this);
}


antlrcpp::Any SPECTREParser::Parameter_accessContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitParameter_access(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Parameter_accessContext* SPECTREParser::parameter_access() {
  Parameter_accessContext *_localctx = _tracker.createInstance<Parameter_accessContext>(_ctx, getState());
  enterRule(_localctx, 244, SPECTREParser::RuleParameter_access);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2411);
    match(SPECTREParser::COLON);
    setState(2412);
    _la = _input->LA(1);
    if (!(_la == SPECTREParser::NUMBER

    || _la == SPECTREParser::ID)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Value_accessContext ------------------------------------------------------------------

SPECTREParser::Value_accessContext::Value_accessContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Value_accessContext::OPEN_ROUND() {
  return getToken(SPECTREParser::OPEN_ROUND, 0);
}

tree::TerminalNode* SPECTREParser::Value_accessContext::CLOSE_ROUND() {
  return getToken(SPECTREParser::CLOSE_ROUND, 0);
}

SPECTREParser::ExpressionContext* SPECTREParser::Value_accessContext::expression() {
  return getRuleContext<SPECTREParser::ExpressionContext>(0);
}

SPECTREParser::Node_pairContext* SPECTREParser::Value_accessContext::node_pair() {
  return getRuleContext<SPECTREParser::Node_pairContext>(0);
}

SPECTREParser::NodeContext* SPECTREParser::Value_accessContext::node() {
  return getRuleContext<SPECTREParser::NodeContext>(0);
}

tree::TerminalNode* SPECTREParser::Value_accessContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}


size_t SPECTREParser::Value_accessContext::getRuleIndex() const {
  return SPECTREParser::RuleValue_access;
}

void SPECTREParser::Value_accessContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValue_access(this);
}

void SPECTREParser::Value_accessContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValue_access(this);
}


antlrcpp::Any SPECTREParser::Value_accessContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitValue_access(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Value_accessContext* SPECTREParser::value_access() {
  Value_accessContext *_localctx = _tracker.createInstance<Value_accessContext>(_ctx, getState());
  enterRule(_localctx, 246, SPECTREParser::RuleValue_access);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2415);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SPECTREParser::ID) {
      setState(2414);
      match(SPECTREParser::ID);
    }
    setState(2417);
    match(SPECTREParser::OPEN_ROUND);
    setState(2421);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 449, _ctx)) {
    case 1: {
      setState(2418);
      expression(0);
      break;
    }

    case 2: {
      setState(2419);
      node_pair();
      break;
    }

    case 3: {
      setState(2420);
      node();
      break;
    }

    }
    setState(2423);
    match(SPECTREParser::CLOSE_ROUND);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Value_access_assignContext ------------------------------------------------------------------

SPECTREParser::Value_access_assignContext::Value_access_assignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SPECTREParser::Value_accessContext* SPECTREParser::Value_access_assignContext::value_access() {
  return getRuleContext<SPECTREParser::Value_accessContext>(0);
}

tree::TerminalNode* SPECTREParser::Value_access_assignContext::EQUAL() {
  return getToken(SPECTREParser::EQUAL, 0);
}

SPECTREParser::ExpressionContext* SPECTREParser::Value_access_assignContext::expression() {
  return getRuleContext<SPECTREParser::ExpressionContext>(0);
}


size_t SPECTREParser::Value_access_assignContext::getRuleIndex() const {
  return SPECTREParser::RuleValue_access_assign;
}

void SPECTREParser::Value_access_assignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValue_access_assign(this);
}

void SPECTREParser::Value_access_assignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValue_access_assign(this);
}


antlrcpp::Any SPECTREParser::Value_access_assignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitValue_access_assign(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Value_access_assignContext* SPECTREParser::value_access_assign() {
  Value_access_assignContext *_localctx = _tracker.createInstance<Value_access_assignContext>(_ctx, getState());
  enterRule(_localctx, 248, SPECTREParser::RuleValue_access_assign);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2425);
    value_access();
    setState(2426);
    match(SPECTREParser::EQUAL);
    setState(2427);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Time_pairContext ------------------------------------------------------------------

SPECTREParser::Time_pairContext::Time_pairContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SPECTREParser::Time_pointContext* SPECTREParser::Time_pairContext::time_point() {
  return getRuleContext<SPECTREParser::Time_pointContext>(0);
}

SPECTREParser::ExpressionContext* SPECTREParser::Time_pairContext::expression() {
  return getRuleContext<SPECTREParser::ExpressionContext>(0);
}

tree::TerminalNode* SPECTREParser::Time_pairContext::OPEN_CURLY() {
  return getToken(SPECTREParser::OPEN_CURLY, 0);
}

tree::TerminalNode* SPECTREParser::Time_pairContext::CLOSE_CURLY() {
  return getToken(SPECTREParser::CLOSE_CURLY, 0);
}


size_t SPECTREParser::Time_pairContext::getRuleIndex() const {
  return SPECTREParser::RuleTime_pair;
}

void SPECTREParser::Time_pairContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTime_pair(this);
}

void SPECTREParser::Time_pairContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTime_pair(this);
}


antlrcpp::Any SPECTREParser::Time_pairContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitTime_pair(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Time_pairContext* SPECTREParser::time_pair() {
  Time_pairContext *_localctx = _tracker.createInstance<Time_pairContext>(_ctx, getState());
  enterRule(_localctx, 250, SPECTREParser::RuleTime_pair);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(2437);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 450, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(2429);
      time_point();
      setState(2430);
      expression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(2432);
      time_point();
      setState(2433);
      match(SPECTREParser::OPEN_CURLY);
      setState(2434);
      expression(0);
      setState(2435);
      match(SPECTREParser::CLOSE_CURLY);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Time_pointContext ------------------------------------------------------------------

SPECTREParser::Time_pointContext::Time_pointContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SPECTREParser::ExpressionContext* SPECTREParser::Time_pointContext::expression() {
  return getRuleContext<SPECTREParser::ExpressionContext>(0);
}


size_t SPECTREParser::Time_pointContext::getRuleIndex() const {
  return SPECTREParser::RuleTime_point;
}

void SPECTREParser::Time_pointContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTime_point(this);
}

void SPECTREParser::Time_pointContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTime_point(this);
}


antlrcpp::Any SPECTREParser::Time_pointContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitTime_point(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Time_pointContext* SPECTREParser::time_point() {
  Time_pointContext *_localctx = _tracker.createInstance<Time_pointContext>(_ctx, getState());
  enterRule(_localctx, 252, SPECTREParser::RuleTime_point);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2439);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FilepathContext ------------------------------------------------------------------

SPECTREParser::FilepathContext::FilepathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SPECTREParser::Filepath_elementContext* SPECTREParser::FilepathContext::filepath_element() {
  return getRuleContext<SPECTREParser::Filepath_elementContext>(0);
}


size_t SPECTREParser::FilepathContext::getRuleIndex() const {
  return SPECTREParser::RuleFilepath;
}

void SPECTREParser::FilepathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFilepath(this);
}

void SPECTREParser::FilepathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFilepath(this);
}


antlrcpp::Any SPECTREParser::FilepathContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitFilepath(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::FilepathContext* SPECTREParser::filepath() {
  FilepathContext *_localctx = _tracker.createInstance<FilepathContext>(_ctx, getState());
  enterRule(_localctx, 254, SPECTREParser::RuleFilepath);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2441);
    filepath_element();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Filepath_elementContext ------------------------------------------------------------------

SPECTREParser::Filepath_elementContext::Filepath_elementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Filepath_elementContext::ID() {
  return getToken(SPECTREParser::ID, 0);
}

tree::TerminalNode* SPECTREParser::Filepath_elementContext::STRING() {
  return getToken(SPECTREParser::STRING, 0);
}

SPECTREParser::Filepath_elementContext* SPECTREParser::Filepath_elementContext::filepath_element() {
  return getRuleContext<SPECTREParser::Filepath_elementContext>(0);
}

std::vector<tree::TerminalNode *> SPECTREParser::Filepath_elementContext::APEX() {
  return getTokens(SPECTREParser::APEX);
}

tree::TerminalNode* SPECTREParser::Filepath_elementContext::APEX(size_t i) {
  return getToken(SPECTREParser::APEX, i);
}

tree::TerminalNode* SPECTREParser::Filepath_elementContext::SLASH() {
  return getToken(SPECTREParser::SLASH, 0);
}

tree::TerminalNode* SPECTREParser::Filepath_elementContext::DOT() {
  return getToken(SPECTREParser::DOT, 0);
}

tree::TerminalNode* SPECTREParser::Filepath_elementContext::MINUS() {
  return getToken(SPECTREParser::MINUS, 0);
}

tree::TerminalNode* SPECTREParser::Filepath_elementContext::DOLLAR() {
  return getToken(SPECTREParser::DOLLAR, 0);
}


size_t SPECTREParser::Filepath_elementContext::getRuleIndex() const {
  return SPECTREParser::RuleFilepath_element;
}

void SPECTREParser::Filepath_elementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFilepath_element(this);
}

void SPECTREParser::Filepath_elementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFilepath_element(this);
}


antlrcpp::Any SPECTREParser::Filepath_elementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitFilepath_element(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Filepath_elementContext* SPECTREParser::filepath_element() {
  Filepath_elementContext *_localctx = _tracker.createInstance<Filepath_elementContext>(_ctx, getState());
  enterRule(_localctx, 256, SPECTREParser::RuleFilepath_element);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(2459);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 451, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(2443);
      match(SPECTREParser::ID);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(2444);
      match(SPECTREParser::STRING);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(2445);
      match(SPECTREParser::ID);
      setState(2446);
      filepath_element();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(2447);
      match(SPECTREParser::APEX);
      setState(2448);
      filepath_element();
      setState(2449);
      match(SPECTREParser::APEX);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(2451);
      match(SPECTREParser::SLASH);
      setState(2452);
      filepath_element();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(2453);
      match(SPECTREParser::DOT);
      setState(2454);
      filepath_element();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(2455);
      match(SPECTREParser::MINUS);
      setState(2456);
      filepath_element();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(2457);
      match(SPECTREParser::DOLLAR);
      setState(2458);
      filepath_element();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- KeywordContext ------------------------------------------------------------------

SPECTREParser::KeywordContext::KeywordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::KeywordContext::ALTER() {
  return getToken(SPECTREParser::ALTER, 0);
}

tree::TerminalNode* SPECTREParser::KeywordContext::ALTERGROUP() {
  return getToken(SPECTREParser::ALTERGROUP, 0);
}

tree::TerminalNode* SPECTREParser::KeywordContext::OPTIONS() {
  return getToken(SPECTREParser::OPTIONS, 0);
}

tree::TerminalNode* SPECTREParser::KeywordContext::SET() {
  return getToken(SPECTREParser::SET, 0);
}

tree::TerminalNode* SPECTREParser::KeywordContext::SHELL() {
  return getToken(SPECTREParser::SHELL, 0);
}

tree::TerminalNode* SPECTREParser::KeywordContext::INFO() {
  return getToken(SPECTREParser::INFO, 0);
}

tree::TerminalNode* SPECTREParser::KeywordContext::NODESET() {
  return getToken(SPECTREParser::NODESET, 0);
}

tree::TerminalNode* SPECTREParser::KeywordContext::IC() {
  return getToken(SPECTREParser::IC, 0);
}

tree::TerminalNode* SPECTREParser::KeywordContext::ASSERT() {
  return getToken(SPECTREParser::ASSERT, 0);
}

tree::TerminalNode* SPECTREParser::KeywordContext::CHECK() {
  return getToken(SPECTREParser::CHECK, 0);
}

tree::TerminalNode* SPECTREParser::KeywordContext::LANGUAGE() {
  return getToken(SPECTREParser::LANGUAGE, 0);
}

tree::TerminalNode* SPECTREParser::KeywordContext::PORTS() {
  return getToken(SPECTREParser::PORTS, 0);
}

tree::TerminalNode* SPECTREParser::KeywordContext::WAVE() {
  return getToken(SPECTREParser::WAVE, 0);
}

tree::TerminalNode* SPECTREParser::KeywordContext::PWL() {
  return getToken(SPECTREParser::PWL, 0);
}

tree::TerminalNode* SPECTREParser::KeywordContext::SIN() {
  return getToken(SPECTREParser::SIN, 0);
}

tree::TerminalNode* SPECTREParser::KeywordContext::SFFM() {
  return getToken(SPECTREParser::SFFM, 0);
}

tree::TerminalNode* SPECTREParser::KeywordContext::PULSE() {
  return getToken(SPECTREParser::PULSE, 0);
}

tree::TerminalNode* SPECTREParser::KeywordContext::COEFFS() {
  return getToken(SPECTREParser::COEFFS, 0);
}

tree::TerminalNode* SPECTREParser::KeywordContext::INSENSITIVE() {
  return getToken(SPECTREParser::INSENSITIVE, 0);
}

tree::TerminalNode* SPECTREParser::KeywordContext::IF() {
  return getToken(SPECTREParser::IF, 0);
}

tree::TerminalNode* SPECTREParser::KeywordContext::ELSE() {
  return getToken(SPECTREParser::ELSE, 0);
}

tree::TerminalNode* SPECTREParser::KeywordContext::PARAMETERS() {
  return getToken(SPECTREParser::PARAMETERS, 0);
}

tree::TerminalNode* SPECTREParser::KeywordContext::ANALOGMODEL() {
  return getToken(SPECTREParser::ANALOGMODEL, 0);
}

tree::TerminalNode* SPECTREParser::KeywordContext::CHECKPOINT() {
  return getToken(SPECTREParser::CHECKPOINT, 0);
}

tree::TerminalNode* SPECTREParser::KeywordContext::SPECTRE() {
  return getToken(SPECTREParser::SPECTRE, 0);
}

tree::TerminalNode* SPECTREParser::KeywordContext::SPICE() {
  return getToken(SPECTREParser::SPICE, 0);
}

tree::TerminalNode* SPECTREParser::KeywordContext::STATISTICS() {
  return getToken(SPECTREParser::STATISTICS, 0);
}

tree::TerminalNode* SPECTREParser::KeywordContext::PROCESS() {
  return getToken(SPECTREParser::PROCESS, 0);
}

tree::TerminalNode* SPECTREParser::KeywordContext::CORRELATE() {
  return getToken(SPECTREParser::CORRELATE, 0);
}

tree::TerminalNode* SPECTREParser::KeywordContext::TRUNCATE() {
  return getToken(SPECTREParser::TRUNCATE, 0);
}

tree::TerminalNode* SPECTREParser::KeywordContext::MISMATCH() {
  return getToken(SPECTREParser::MISMATCH, 0);
}

tree::TerminalNode* SPECTREParser::KeywordContext::VARY() {
  return getToken(SPECTREParser::VARY, 0);
}

tree::TerminalNode* SPECTREParser::KeywordContext::RELIABILITY() {
  return getToken(SPECTREParser::RELIABILITY, 0);
}


size_t SPECTREParser::KeywordContext::getRuleIndex() const {
  return SPECTREParser::RuleKeyword;
}

void SPECTREParser::KeywordContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKeyword(this);
}

void SPECTREParser::KeywordContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKeyword(this);
}


antlrcpp::Any SPECTREParser::KeywordContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitKeyword(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::KeywordContext* SPECTREParser::keyword() {
  KeywordContext *_localctx = _tracker.createInstance<KeywordContext>(_ctx, getState());
  enterRule(_localctx, 258, SPECTREParser::RuleKeyword);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2461);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SPECTREParser::ALTER)
      | (1ULL << SPECTREParser::ALTERGROUP)
      | (1ULL << SPECTREParser::OPTIONS)
      | (1ULL << SPECTREParser::SET)
      | (1ULL << SPECTREParser::SHELL)
      | (1ULL << SPECTREParser::INFO)
      | (1ULL << SPECTREParser::NODESET)
      | (1ULL << SPECTREParser::IC)
      | (1ULL << SPECTREParser::ASSERT)
      | (1ULL << SPECTREParser::CHECK)
      | (1ULL << SPECTREParser::LANGUAGE)
      | (1ULL << SPECTREParser::PORTS)
      | (1ULL << SPECTREParser::WAVE)
      | (1ULL << SPECTREParser::PWL)
      | (1ULL << SPECTREParser::SIN)
      | (1ULL << SPECTREParser::SFFM)
      | (1ULL << SPECTREParser::PULSE)
      | (1ULL << SPECTREParser::COEFFS)
      | (1ULL << SPECTREParser::INSENSITIVE)
      | (1ULL << SPECTREParser::IF)
      | (1ULL << SPECTREParser::ELSE)
      | (1ULL << SPECTREParser::PARAMETERS)
      | (1ULL << SPECTREParser::ANALOGMODEL)
      | (1ULL << SPECTREParser::CHECKPOINT)
      | (1ULL << SPECTREParser::SPECTRE)
      | (1ULL << SPECTREParser::SPICE)
      | (1ULL << SPECTREParser::STATISTICS)
      | (1ULL << SPECTREParser::PROCESS)
      | (1ULL << SPECTREParser::CORRELATE)
      | (1ULL << SPECTREParser::TRUNCATE)
      | (1ULL << SPECTREParser::MISMATCH)
      | (1ULL << SPECTREParser::VARY)
      | (1ULL << SPECTREParser::RELIABILITY))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Analysis_typeContext ------------------------------------------------------------------

SPECTREParser::Analysis_typeContext::Analysis_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Analysis_typeContext::AC() {
  return getToken(SPECTREParser::AC, 0);
}

tree::TerminalNode* SPECTREParser::Analysis_typeContext::ACMATCH() {
  return getToken(SPECTREParser::ACMATCH, 0);
}

tree::TerminalNode* SPECTREParser::Analysis_typeContext::DC() {
  return getToken(SPECTREParser::DC, 0);
}

tree::TerminalNode* SPECTREParser::Analysis_typeContext::DCMATCH() {
  return getToken(SPECTREParser::DCMATCH, 0);
}

tree::TerminalNode* SPECTREParser::Analysis_typeContext::ENVLP() {
  return getToken(SPECTREParser::ENVLP, 0);
}

tree::TerminalNode* SPECTREParser::Analysis_typeContext::SP() {
  return getToken(SPECTREParser::SP, 0);
}

tree::TerminalNode* SPECTREParser::Analysis_typeContext::STB() {
  return getToken(SPECTREParser::STB, 0);
}

tree::TerminalNode* SPECTREParser::Analysis_typeContext::SWEEP() {
  return getToken(SPECTREParser::SWEEP, 0);
}

tree::TerminalNode* SPECTREParser::Analysis_typeContext::TDR() {
  return getToken(SPECTREParser::TDR, 0);
}

tree::TerminalNode* SPECTREParser::Analysis_typeContext::TRAN() {
  return getToken(SPECTREParser::TRAN, 0);
}

tree::TerminalNode* SPECTREParser::Analysis_typeContext::XF() {
  return getToken(SPECTREParser::XF, 0);
}

tree::TerminalNode* SPECTREParser::Analysis_typeContext::PAC() {
  return getToken(SPECTREParser::PAC, 0);
}

tree::TerminalNode* SPECTREParser::Analysis_typeContext::PDISTO() {
  return getToken(SPECTREParser::PDISTO, 0);
}

tree::TerminalNode* SPECTREParser::Analysis_typeContext::PNOISE() {
  return getToken(SPECTREParser::PNOISE, 0);
}

tree::TerminalNode* SPECTREParser::Analysis_typeContext::PSP() {
  return getToken(SPECTREParser::PSP, 0);
}

tree::TerminalNode* SPECTREParser::Analysis_typeContext::PSS() {
  return getToken(SPECTREParser::PSS, 0);
}

tree::TerminalNode* SPECTREParser::Analysis_typeContext::PXF() {
  return getToken(SPECTREParser::PXF, 0);
}

tree::TerminalNode* SPECTREParser::Analysis_typeContext::PZ() {
  return getToken(SPECTREParser::PZ, 0);
}

tree::TerminalNode* SPECTREParser::Analysis_typeContext::QPAC() {
  return getToken(SPECTREParser::QPAC, 0);
}

tree::TerminalNode* SPECTREParser::Analysis_typeContext::QPNOISE() {
  return getToken(SPECTREParser::QPNOISE, 0);
}

tree::TerminalNode* SPECTREParser::Analysis_typeContext::QPSP() {
  return getToken(SPECTREParser::QPSP, 0);
}

tree::TerminalNode* SPECTREParser::Analysis_typeContext::QPSS() {
  return getToken(SPECTREParser::QPSS, 0);
}

tree::TerminalNode* SPECTREParser::Analysis_typeContext::QPXF() {
  return getToken(SPECTREParser::QPXF, 0);
}

tree::TerminalNode* SPECTREParser::Analysis_typeContext::SENS() {
  return getToken(SPECTREParser::SENS, 0);
}

tree::TerminalNode* SPECTREParser::Analysis_typeContext::MONTECARLO() {
  return getToken(SPECTREParser::MONTECARLO, 0);
}

tree::TerminalNode* SPECTREParser::Analysis_typeContext::NOISE() {
  return getToken(SPECTREParser::NOISE, 0);
}

tree::TerminalNode* SPECTREParser::Analysis_typeContext::CHECKLIMIT() {
  return getToken(SPECTREParser::CHECKLIMIT, 0);
}


size_t SPECTREParser::Analysis_typeContext::getRuleIndex() const {
  return SPECTREParser::RuleAnalysis_type;
}

void SPECTREParser::Analysis_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnalysis_type(this);
}

void SPECTREParser::Analysis_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnalysis_type(this);
}


antlrcpp::Any SPECTREParser::Analysis_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitAnalysis_type(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Analysis_typeContext* SPECTREParser::analysis_type() {
  Analysis_typeContext *_localctx = _tracker.createInstance<Analysis_typeContext>(_ctx, getState());
  enterRule(_localctx, 260, SPECTREParser::RuleAnalysis_type);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2463);
    _la = _input->LA(1);
    if (!(((((_la - 51) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 51)) & ((1ULL << (SPECTREParser::AC - 51))
      | (1ULL << (SPECTREParser::ACMATCH - 51))
      | (1ULL << (SPECTREParser::DC - 51))
      | (1ULL << (SPECTREParser::DCMATCH - 51))
      | (1ULL << (SPECTREParser::ENVLP - 51))
      | (1ULL << (SPECTREParser::SP - 51))
      | (1ULL << (SPECTREParser::STB - 51))
      | (1ULL << (SPECTREParser::SWEEP - 51))
      | (1ULL << (SPECTREParser::TDR - 51))
      | (1ULL << (SPECTREParser::TRAN - 51))
      | (1ULL << (SPECTREParser::XF - 51))
      | (1ULL << (SPECTREParser::PAC - 51))
      | (1ULL << (SPECTREParser::PDISTO - 51))
      | (1ULL << (SPECTREParser::PNOISE - 51))
      | (1ULL << (SPECTREParser::PSP - 51))
      | (1ULL << (SPECTREParser::PSS - 51))
      | (1ULL << (SPECTREParser::PXF - 51))
      | (1ULL << (SPECTREParser::PZ - 51))
      | (1ULL << (SPECTREParser::QPAC - 51))
      | (1ULL << (SPECTREParser::QPNOISE - 51))
      | (1ULL << (SPECTREParser::QPSP - 51))
      | (1ULL << (SPECTREParser::QPSS - 51))
      | (1ULL << (SPECTREParser::QPXF - 51))
      | (1ULL << (SPECTREParser::SENS - 51))
      | (1ULL << (SPECTREParser::MONTECARLO - 51))
      | (1ULL << (SPECTREParser::NOISE - 51))
      | (1ULL << (SPECTREParser::CHECKLIMIT - 51)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Component_typeContext ------------------------------------------------------------------

SPECTREParser::Component_typeContext::Component_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SPECTREParser::Component_typeContext::A2D() {
  return getToken(SPECTREParser::A2D, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::B3SOIPD() {
  return getToken(SPECTREParser::B3SOIPD, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::BJT() {
  return getToken(SPECTREParser::BJT, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::BJT301() {
  return getToken(SPECTREParser::BJT301, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::BJT500() {
  return getToken(SPECTREParser::BJT500, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::BJT503() {
  return getToken(SPECTREParser::BJT503, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::BJT504() {
  return getToken(SPECTREParser::BJT504, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::BJT504T() {
  return getToken(SPECTREParser::BJT504T, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::BSIM1() {
  return getToken(SPECTREParser::BSIM1, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::BSIM2() {
  return getToken(SPECTREParser::BSIM2, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::BSIM3() {
  return getToken(SPECTREParser::BSIM3, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::BSIM3V3() {
  return getToken(SPECTREParser::BSIM3V3, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::BSIM4() {
  return getToken(SPECTREParser::BSIM4, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::BSIMSOI() {
  return getToken(SPECTREParser::BSIMSOI, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::BTASOI() {
  return getToken(SPECTREParser::BTASOI, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::CAPACITOR() {
  return getToken(SPECTREParser::CAPACITOR, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::CCCS() {
  return getToken(SPECTREParser::CCCS, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::CCVS() {
  return getToken(SPECTREParser::CCVS, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::CKTROM() {
  return getToken(SPECTREParser::CKTROM, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::CORE() {
  return getToken(SPECTREParser::CORE, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::D2A() {
  return getToken(SPECTREParser::D2A, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::DELAY() {
  return getToken(SPECTREParser::DELAY, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::DIO500() {
  return getToken(SPECTREParser::DIO500, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::DIODE() {
  return getToken(SPECTREParser::DIODE, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::EKV() {
  return getToken(SPECTREParser::EKV, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::FOURIER() {
  return getToken(SPECTREParser::FOURIER, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::GAAS() {
  return getToken(SPECTREParser::GAAS, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::HBT() {
  return getToken(SPECTREParser::HBT, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::HISIM() {
  return getToken(SPECTREParser::HISIM, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::HVMOS() {
  return getToken(SPECTREParser::HVMOS, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::INDUCTOR() {
  return getToken(SPECTREParser::INDUCTOR, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::INTCAP() {
  return getToken(SPECTREParser::INTCAP, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::IPROBE() {
  return getToken(SPECTREParser::IPROBE, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::ISOURCE() {
  return getToken(SPECTREParser::ISOURCE, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::JFET() {
  return getToken(SPECTREParser::JFET, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::JUNCAP() {
  return getToken(SPECTREParser::JUNCAP, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::MISNAN() {
  return getToken(SPECTREParser::MISNAN, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::MOS0() {
  return getToken(SPECTREParser::MOS0, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::MOS1() {
  return getToken(SPECTREParser::MOS1, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::MOS1000() {
  return getToken(SPECTREParser::MOS1000, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::MOS1100() {
  return getToken(SPECTREParser::MOS1100, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::MOS11010() {
  return getToken(SPECTREParser::MOS11010, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::MOS11011() {
  return getToken(SPECTREParser::MOS11011, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::MOS15() {
  return getToken(SPECTREParser::MOS15, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::MOS2() {
  return getToken(SPECTREParser::MOS2, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::MOS3() {
  return getToken(SPECTREParser::MOS3, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::MOS30() {
  return getToken(SPECTREParser::MOS30, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::MOS3002() {
  return getToken(SPECTREParser::MOS3002, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::MOS3100() {
  return getToken(SPECTREParser::MOS3100, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::MOS40() {
  return getToken(SPECTREParser::MOS40, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::MOS705() {
  return getToken(SPECTREParser::MOS705, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::MOS902() {
  return getToken(SPECTREParser::MOS902, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::MOS903() {
  return getToken(SPECTREParser::MOS903, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::MSLINE() {
  return getToken(SPECTREParser::MSLINE, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::MTLINE() {
  return getToken(SPECTREParser::MTLINE, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::MUTUAL_INDUCTOR() {
  return getToken(SPECTREParser::MUTUAL_INDUCTOR, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::NODCAP() {
  return getToken(SPECTREParser::NODCAP, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::NODE() {
  return getToken(SPECTREParser::NODE, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::NPORT() {
  return getToken(SPECTREParser::NPORT, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::PARAMTEST() {
  return getToken(SPECTREParser::PARAMTEST, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::PCCCS() {
  return getToken(SPECTREParser::PCCCS, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::PCCVS() {
  return getToken(SPECTREParser::PCCVS, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::PHY_RES() {
  return getToken(SPECTREParser::PHY_RES, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::PORT() {
  return getToken(SPECTREParser::PORT, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::PSITFT() {
  return getToken(SPECTREParser::PSITFT, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::PVCCS() {
  return getToken(SPECTREParser::PVCCS, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::PVCVS() {
  return getToken(SPECTREParser::PVCVS, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::QUANTITY() {
  return getToken(SPECTREParser::QUANTITY, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::RDIFF() {
  return getToken(SPECTREParser::RDIFF, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::RELAY() {
  return getToken(SPECTREParser::RELAY, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::RESISTOR() {
  return getToken(SPECTREParser::RESISTOR, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::SCCCS() {
  return getToken(SPECTREParser::SCCCS, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::SCCVS() {
  return getToken(SPECTREParser::SCCVS, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::SVCCS() {
  return getToken(SPECTREParser::SVCCS, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::SVCVS() {
  return getToken(SPECTREParser::SVCVS, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::SWITCH() {
  return getToken(SPECTREParser::SWITCH, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::TLINE() {
  return getToken(SPECTREParser::TLINE, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::TOM2() {
  return getToken(SPECTREParser::TOM2, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::TOM3() {
  return getToken(SPECTREParser::TOM3, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::TRANSFORMER() {
  return getToken(SPECTREParser::TRANSFORMER, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::VBIC() {
  return getToken(SPECTREParser::VBIC, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::VCCS() {
  return getToken(SPECTREParser::VCCS, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::VCVS() {
  return getToken(SPECTREParser::VCVS, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::VSOURCE() {
  return getToken(SPECTREParser::VSOURCE, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::WINDING() {
  return getToken(SPECTREParser::WINDING, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::ZCCCS() {
  return getToken(SPECTREParser::ZCCCS, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::ZCCVS() {
  return getToken(SPECTREParser::ZCCVS, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::ZVCCS() {
  return getToken(SPECTREParser::ZVCCS, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::ZVCVS() {
  return getToken(SPECTREParser::ZVCVS, 0);
}

tree::TerminalNode* SPECTREParser::Component_typeContext::BSOURCE() {
  return getToken(SPECTREParser::BSOURCE, 0);
}


size_t SPECTREParser::Component_typeContext::getRuleIndex() const {
  return SPECTREParser::RuleComponent_type;
}

void SPECTREParser::Component_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComponent_type(this);
}

void SPECTREParser::Component_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SPECTREParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComponent_type(this);
}


antlrcpp::Any SPECTREParser::Component_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SPECTREParserVisitor*>(visitor))
    return parserVisitor->visitComponent_type(this);
  else
    return visitor->visitChildren(this);
}

SPECTREParser::Component_typeContext* SPECTREParser::component_type() {
  Component_typeContext *_localctx = _tracker.createInstance<Component_typeContext>(_ctx, getState());
  enterRule(_localctx, 262, SPECTREParser::RuleComponent_type);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2465);
    _la = _input->LA(1);
    if (!(((((_la - 78) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 78)) & ((1ULL << (SPECTREParser::A2D - 78))
      | (1ULL << (SPECTREParser::B3SOIPD - 78))
      | (1ULL << (SPECTREParser::BJT - 78))
      | (1ULL << (SPECTREParser::BJT301 - 78))
      | (1ULL << (SPECTREParser::BJT500 - 78))
      | (1ULL << (SPECTREParser::BJT503 - 78))
      | (1ULL << (SPECTREParser::BJT504 - 78))
      | (1ULL << (SPECTREParser::BJT504T - 78))
      | (1ULL << (SPECTREParser::BSIM1 - 78))
      | (1ULL << (SPECTREParser::BSIM2 - 78))
      | (1ULL << (SPECTREParser::BSIM3 - 78))
      | (1ULL << (SPECTREParser::BSIM3V3 - 78))
      | (1ULL << (SPECTREParser::BSIM4 - 78))
      | (1ULL << (SPECTREParser::BSIMSOI - 78))
      | (1ULL << (SPECTREParser::BTASOI - 78))
      | (1ULL << (SPECTREParser::CAPACITOR - 78))
      | (1ULL << (SPECTREParser::CCCS - 78))
      | (1ULL << (SPECTREParser::CCVS - 78))
      | (1ULL << (SPECTREParser::CKTROM - 78))
      | (1ULL << (SPECTREParser::CORE - 78))
      | (1ULL << (SPECTREParser::D2A - 78))
      | (1ULL << (SPECTREParser::DELAY - 78))
      | (1ULL << (SPECTREParser::DIO500 - 78))
      | (1ULL << (SPECTREParser::DIODE - 78))
      | (1ULL << (SPECTREParser::EKV - 78))
      | (1ULL << (SPECTREParser::FOURIER - 78))
      | (1ULL << (SPECTREParser::GAAS - 78))
      | (1ULL << (SPECTREParser::HBT - 78))
      | (1ULL << (SPECTREParser::HISIM - 78))
      | (1ULL << (SPECTREParser::HVMOS - 78))
      | (1ULL << (SPECTREParser::INDUCTOR - 78))
      | (1ULL << (SPECTREParser::INTCAP - 78))
      | (1ULL << (SPECTREParser::IPROBE - 78))
      | (1ULL << (SPECTREParser::ISOURCE - 78))
      | (1ULL << (SPECTREParser::JFET - 78))
      | (1ULL << (SPECTREParser::JUNCAP - 78))
      | (1ULL << (SPECTREParser::MISNAN - 78))
      | (1ULL << (SPECTREParser::MOS11011 - 78))
      | (1ULL << (SPECTREParser::MOS11010 - 78))
      | (1ULL << (SPECTREParser::MOS3002 - 78))
      | (1ULL << (SPECTREParser::MOS3100 - 78))
      | (1ULL << (SPECTREParser::MOS1000 - 78))
      | (1ULL << (SPECTREParser::MOS1100 - 78))
      | (1ULL << (SPECTREParser::MUTUAL_INDUCTOR - 78))
      | (1ULL << (SPECTREParser::MSLINE - 78))
      | (1ULL << (SPECTREParser::MTLINE - 78))
      | (1ULL << (SPECTREParser::MOS705 - 78))
      | (1ULL << (SPECTREParser::MOS902 - 78))
      | (1ULL << (SPECTREParser::MOS903 - 78))
      | (1ULL << (SPECTREParser::MOS30 - 78))
      | (1ULL << (SPECTREParser::MOS40 - 78))
      | (1ULL << (SPECTREParser::MOS15 - 78))
      | (1ULL << (SPECTREParser::MOS0 - 78))
      | (1ULL << (SPECTREParser::MOS1 - 78))
      | (1ULL << (SPECTREParser::MOS2 - 78))
      | (1ULL << (SPECTREParser::MOS3 - 78))
      | (1ULL << (SPECTREParser::NODCAP - 78))
      | (1ULL << (SPECTREParser::NODE - 78))
      | (1ULL << (SPECTREParser::NPORT - 78))
      | (1ULL << (SPECTREParser::PARAMTEST - 78))
      | (1ULL << (SPECTREParser::PCCCS - 78))
      | (1ULL << (SPECTREParser::PCCVS - 78))
      | (1ULL << (SPECTREParser::PHY_RES - 78))
      | (1ULL << (SPECTREParser::PORT - 78)))) != 0) || ((((_la - 142) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 142)) & ((1ULL << (SPECTREParser::PSITFT - 142))
      | (1ULL << (SPECTREParser::PVCCS - 142))
      | (1ULL << (SPECTREParser::PVCVS - 142))
      | (1ULL << (SPECTREParser::QUANTITY - 142))
      | (1ULL << (SPECTREParser::RDIFF - 142))
      | (1ULL << (SPECTREParser::RELAY - 142))
      | (1ULL << (SPECTREParser::RESISTOR - 142))
      | (1ULL << (SPECTREParser::SCCCS - 142))
      | (1ULL << (SPECTREParser::SCCVS - 142))
      | (1ULL << (SPECTREParser::SVCCS - 142))
      | (1ULL << (SPECTREParser::SVCVS - 142))
      | (1ULL << (SPECTREParser::SWITCH - 142))
      | (1ULL << (SPECTREParser::TLINE - 142))
      | (1ULL << (SPECTREParser::TOM2 - 142))
      | (1ULL << (SPECTREParser::TOM3 - 142))
      | (1ULL << (SPECTREParser::TRANSFORMER - 142))
      | (1ULL << (SPECTREParser::VBIC - 142))
      | (1ULL << (SPECTREParser::VCCS - 142))
      | (1ULL << (SPECTREParser::VCVS - 142))
      | (1ULL << (SPECTREParser::VSOURCE - 142))
      | (1ULL << (SPECTREParser::WINDING - 142))
      | (1ULL << (SPECTREParser::ZCCCS - 142))
      | (1ULL << (SPECTREParser::ZCCVS - 142))
      | (1ULL << (SPECTREParser::ZVCCS - 142))
      | (1ULL << (SPECTREParser::ZVCVS - 142))
      | (1ULL << (SPECTREParser::BSOURCE - 142)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool SPECTREParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 109: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool SPECTREParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);
    case 1: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> SPECTREParser::_decisionToDFA;
atn::PredictionContextCache SPECTREParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN SPECTREParser::_atn;
std::vector<uint16_t> SPECTREParser::_serializedATN;

std::vector<std::string> SPECTREParser::_ruleNames = {
  "netlist", "netlist_title", "netlist_entity", "include", "standard_include", 
  "cpp_include", "ahdl_include", "lang", "library", "library_header", "library_content", 
  "library_footer", "section", "section_header", "section_content", "section_footer", 
  "analogmodel", "subckt", "subckt_header", "subckt_content", "subckt_footer", 
  "if_statement", "if_alternative", "if_body", "analysis", "ac", "acmatch", 
  "dc", "dcmatch", "envlp", "sp", "stb", "sweep", "sweep_header", "sweep_content", 
  "sweep_footer", "tdr", "tran", "xf", "pac", "pdisto", "pnoise", "psp", 
  "pss", "pxf", "pz", "qpac", "qpnoise", "qpsp", "qpss", "qpxf", "sens", 
  "sens_output_variables_list", "sens_design_parameters_list", "sens_analyses_list", 
  "montecarlo", "montecarlo_header", "montecarlo_content", "montecarlo_export", 
  "montecarlo_footer", "noise", "checklimit", "global", "model", "model_name", 
  "model_master", "control", "alter", "altergroup", "altergroup_header", 
  "altergroup_content", "altergroup_footer", "assert_statement", "check_statement", 
  "save", "option", "set", "shell", "info", "nodeset", "ic", "statistics", 
  "statistics_header", "statistics_content", "statistics_footer", "process", 
  "mismatch", "correlate", "truncate", "vary", "reliability", "reliability_header", 
  "reliability_content", "reliability_footer", "reliability_control", "global_declarations", 
  "component", "component_id", "component_master", "component_attribute", 
  "component_value", "component_value_list", "component_analysis", "node_list", 
  "node_list_item", "node_mapping", "node_pair", "node_branch", "node", 
  "expression", "expression_unary", "expression_function_call", "expression_pair", 
  "expression_scope", "expression_operator", "expression_atom", "parameter_list", 
  "parameter_list_item", "array_expression", "array_item", "parameter_assign", 
  "parameter_id", "parameter_access", "value_access", "value_access_assign", 
  "time_pair", "time_point", "filepath", "filepath_element", "keyword", 
  "analysis_type", "component_type"
};

std::vector<std::string> SPECTREParser::_literalNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "'='", "'!'", "'<'", "'>'", "", "", "", "", "", 
  "", "", "", "", "", "", "", "'and'", "'or'", "':'", "';'", "'+'", "'-'", 
  "'*'", "'('", "')'", "'['", "']'", "'{'", "'}'", "'?'", "','", "'$'", 
  "'&'", "'.'", "'_'", "'@'", "'#'", "'\\'", "'/'", "'''", "'\"'", "'|'", 
  "'%'", "'^'", "'~'"
};

std::vector<std::string> SPECTREParser::_symbolicNames = {
  "", "BLOCK_COMMENT", "LINE_COMMENT", "GLOBAL", "INCLUDE", "CPP_INCLUDE", 
  "AHDL_INCLUDE", "LIBRARY", "LIBRARY_END", "SECTION", "SECTION_END", "SUBCKT", 
  "INLINE_SUBCKT", "SUBCKT_END", "SIMULATOR", "MODEL", "EXPORT", "SAVE", 
  "ALTER", "ALTERGROUP", "OPTIONS", "SET", "SHELL", "INFO", "NODESET", "IC", 
  "ASSERT", "CHECK", "LANGUAGE", "PORTS", "WAVE", "PWL", "SIN", "SFFM", 
  "PULSE", "COEFFS", "INSENSITIVE", "IF", "ELSE", "PARAMETERS", "ANALOGMODEL", 
  "CHECKPOINT", "SPECTRE", "SPICE", "STATISTICS", "PROCESS", "CORRELATE", 
  "TRUNCATE", "MISMATCH", "VARY", "RELIABILITY", "AC", "ACMATCH", "DC", 
  "DCMATCH", "ENVLP", "SP", "STB", "SWEEP", "TDR", "TRAN", "XF", "PAC", 
  "PDISTO", "PNOISE", "PSP", "PSS", "PXF", "PZ", "QPAC", "QPNOISE", "QPSP", 
  "QPSS", "QPXF", "SENS", "MONTECARLO", "NOISE", "CHECKLIMIT", "A2D", "B3SOIPD", 
  "BJT", "BJT301", "BJT500", "BJT503", "BJT504", "BJT504T", "BSIM1", "BSIM2", 
  "BSIM3", "BSIM3V3", "BSIM4", "BSIMSOI", "BTASOI", "CAPACITOR", "CCCS", 
  "CCVS", "CKTROM", "CORE", "D2A", "DELAY", "DIO500", "DIODE", "EKV", "FOURIER", 
  "GAAS", "HBT", "HISIM", "HVMOS", "INDUCTOR", "INTCAP", "IPROBE", "ISOURCE", 
  "JFET", "JUNCAP", "MISNAN", "MOS11011", "MOS11010", "MOS3002", "MOS3100", 
  "MOS1000", "MOS1100", "MUTUAL_INDUCTOR", "MSLINE", "MTLINE", "MOS705", 
  "MOS902", "MOS903", "MOS30", "MOS40", "MOS15", "MOS0", "MOS1", "MOS2", 
  "MOS3", "NODCAP", "NODE", "NPORT", "PARAMTEST", "PCCCS", "PCCVS", "PHY_RES", 
  "PORT", "PSITFT", "PVCCS", "PVCVS", "QUANTITY", "RDIFF", "RELAY", "RESISTOR", 
  "SCCCS", "SCCVS", "SVCCS", "SVCVS", "SWITCH", "TLINE", "TOM2", "TOM3", 
  "TRANSFORMER", "VBIC", "VCCS", "VCVS", "VSOURCE", "WINDING", "ZCCCS", 
  "ZCCVS", "ZVCCS", "ZVCVS", "BSOURCE", "EQUAL", "EXCLAMATION_MARK", "LESS_THAN", 
  "GREATER_THAN", "LESS_THAN_EQUAL", "GREATER_THAN_EQUAL", "LOGIC_EQUAL", 
  "LOGIC_NOT_EQUAL", "LOGIC_AND", "LOGIC_OR", "LOGIC_BITWISE_AND", "LOGIC_BITWISE_OR", 
  "LOGIC_XOR", "BITWISE_SHIFT_LEFT", "BITWISE_SHIFT_RIGHT", "POWER_OPERATOR", 
  "AND", "OR", "COLON", "SEMICOLON", "PLUS", "MINUS", "STAR", "OPEN_ROUND", 
  "CLOSE_ROUND", "OPEN_SQUARE", "CLOSE_SQUARE", "OPEN_CURLY", "CLOSE_CURLY", 
  "QUESTION_MARK", "COMMA", "DOLLAR", "AMPERSAND", "DOT", "UNDERSCORE", 
  "AT_SIGN", "POUND_SIGN", "BACKSLASH", "SLASH", "APEX", "QUOTES", "PIPE", 
  "PERCENT", "CARET", "TILDE", "ARROW", "NUMBER", "ID", "STRING", "PERCENTAGE", 
  "COMPLEX", "WS", "NL", "CNL"
};

dfa::Vocabulary SPECTREParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> SPECTREParser::_tokenNames;

SPECTREParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  static uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0xdf, 0x9a6, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 
       0xe, 0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 
       0x9, 0x11, 0x4, 0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 
       0x9, 0x14, 0x4, 0x15, 0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 
       0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 
       0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 
       0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 0x1f, 0x9, 0x1f, 0x4, 0x20, 
       0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 0x9, 0x22, 0x4, 0x23, 
       0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 0x25, 0x4, 0x26, 
       0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 0x4, 0x29, 
       0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 0x2c, 
       0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
       0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 
       0x9, 0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 
       0x9, 0x35, 0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 
       0x9, 0x38, 0x4, 0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 
       0x9, 0x3b, 0x4, 0x3c, 0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 
       0x9, 0x3e, 0x4, 0x3f, 0x9, 0x3f, 0x4, 0x40, 0x9, 0x40, 0x4, 0x41, 
       0x9, 0x41, 0x4, 0x42, 0x9, 0x42, 0x4, 0x43, 0x9, 0x43, 0x4, 0x44, 
       0x9, 0x44, 0x4, 0x45, 0x9, 0x45, 0x4, 0x46, 0x9, 0x46, 0x4, 0x47, 
       0x9, 0x47, 0x4, 0x48, 0x9, 0x48, 0x4, 0x49, 0x9, 0x49, 0x4, 0x4a, 
       0x9, 0x4a, 0x4, 0x4b, 0x9, 0x4b, 0x4, 0x4c, 0x9, 0x4c, 0x4, 0x4d, 
       0x9, 0x4d, 0x4, 0x4e, 0x9, 0x4e, 0x4, 0x4f, 0x9, 0x4f, 0x4, 0x50, 
       0x9, 0x50, 0x4, 0x51, 0x9, 0x51, 0x4, 0x52, 0x9, 0x52, 0x4, 0x53, 
       0x9, 0x53, 0x4, 0x54, 0x9, 0x54, 0x4, 0x55, 0x9, 0x55, 0x4, 0x56, 
       0x9, 0x56, 0x4, 0x57, 0x9, 0x57, 0x4, 0x58, 0x9, 0x58, 0x4, 0x59, 
       0x9, 0x59, 0x4, 0x5a, 0x9, 0x5a, 0x4, 0x5b, 0x9, 0x5b, 0x4, 0x5c, 
       0x9, 0x5c, 0x4, 0x5d, 0x9, 0x5d, 0x4, 0x5e, 0x9, 0x5e, 0x4, 0x5f, 
       0x9, 0x5f, 0x4, 0x60, 0x9, 0x60, 0x4, 0x61, 0x9, 0x61, 0x4, 0x62, 
       0x9, 0x62, 0x4, 0x63, 0x9, 0x63, 0x4, 0x64, 0x9, 0x64, 0x4, 0x65, 
       0x9, 0x65, 0x4, 0x66, 0x9, 0x66, 0x4, 0x67, 0x9, 0x67, 0x4, 0x68, 
       0x9, 0x68, 0x4, 0x69, 0x9, 0x69, 0x4, 0x6a, 0x9, 0x6a, 0x4, 0x6b, 
       0x9, 0x6b, 0x4, 0x6c, 0x9, 0x6c, 0x4, 0x6d, 0x9, 0x6d, 0x4, 0x6e, 
       0x9, 0x6e, 0x4, 0x6f, 0x9, 0x6f, 0x4, 0x70, 0x9, 0x70, 0x4, 0x71, 
       0x9, 0x71, 0x4, 0x72, 0x9, 0x72, 0x4, 0x73, 0x9, 0x73, 0x4, 0x74, 
       0x9, 0x74, 0x4, 0x75, 0x9, 0x75, 0x4, 0x76, 0x9, 0x76, 0x4, 0x77, 
       0x9, 0x77, 0x4, 0x78, 0x9, 0x78, 0x4, 0x79, 0x9, 0x79, 0x4, 0x7a, 
       0x9, 0x7a, 0x4, 0x7b, 0x9, 0x7b, 0x4, 0x7c, 0x9, 0x7c, 0x4, 0x7d, 
       0x9, 0x7d, 0x4, 0x7e, 0x9, 0x7e, 0x4, 0x7f, 0x9, 0x7f, 0x4, 0x80, 
       0x9, 0x80, 0x4, 0x81, 0x9, 0x81, 0x4, 0x82, 0x9, 0x82, 0x4, 0x83, 
       0x9, 0x83, 0x4, 0x84, 0x9, 0x84, 0x4, 0x85, 0x9, 0x85, 0x3, 0x2, 
       0x7, 0x2, 0x10c, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x10f, 0xb, 0x2, 0x3, 
       0x2, 0x3, 0x2, 0x6, 0x2, 0x113, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x114, 
       0x5, 0x2, 0x117, 0xa, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x11b, 0xa, 
       0x2, 0xc, 0x2, 0xe, 0x2, 0x11e, 0xb, 0x2, 0x7, 0x2, 0x120, 0xa, 0x2, 
       0xc, 0x2, 0xe, 0x2, 0x123, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 
       0x6, 0x3, 0x128, 0xa, 0x3, 0xd, 0x3, 0xe, 0x3, 0x129, 0x3, 0x3, 0x7, 
       0x3, 0x12d, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x130, 0xb, 0x3, 0x3, 0x3, 
       0x5, 0x3, 0x133, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
       0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
       0x4, 0x3, 0x4, 0x5, 0x4, 0x141, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 
       0x5, 0x5, 0x5, 0x146, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 
       0x6, 0x14b, 0xa, 0x6, 0x3, 0x6, 0x7, 0x6, 0x14e, 0xa, 0x6, 0xc, 0x6, 
       0xe, 0x6, 0x151, 0xb, 0x6, 0x3, 0x6, 0x5, 0x6, 0x154, 0xa, 0x6, 0x3, 
       0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x159, 0xa, 0x7, 0xc, 0x7, 0xe, 
       0x7, 0x15c, 0xb, 0x7, 0x3, 0x7, 0x5, 0x7, 0x15f, 0xa, 0x7, 0x3, 0x8, 
       0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x164, 0xa, 0x8, 0x3, 0x8, 0x5, 0x8, 
       0x167, 0xa, 0x8, 0x3, 0x8, 0x7, 0x8, 0x16a, 0xa, 0x8, 0xc, 0x8, 0xe, 
       0x8, 0x16d, 0xb, 0x8, 0x3, 0x8, 0x5, 0x8, 0x170, 0xa, 0x8, 0x3, 0x9, 
       0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
       0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x17d, 0xa, 0x9, 0x5, 
       0x9, 0x17f, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x6, 0xa, 0x183, 0xa, 0xa, 
       0xd, 0xa, 0xe, 0xa, 0x184, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 
       0x3, 0xb, 0x7, 0xb, 0x18c, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x18f, 0xb, 
       0xb, 0x3, 0xb, 0x5, 0xb, 0x192, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 
       0xd, 0x3, 0xd, 0x5, 0xd, 0x198, 0xa, 0xd, 0x3, 0xd, 0x7, 0xd, 0x19b, 
       0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x19e, 0xb, 0xd, 0x3, 0xd, 0x5, 0xd, 
       0x1a1, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x6, 0xe, 0x1a5, 0xa, 0xe, 0xd, 
       0xe, 0xe, 0xe, 0x1a6, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 
       0xf, 0x7, 0xf, 0x1ae, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0x1b1, 0xb, 0xf, 
       0x3, 0xf, 0x5, 0xf, 0x1b4, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 
       0x3, 0x11, 0x5, 0x11, 0x1ba, 0xa, 0x11, 0x3, 0x11, 0x7, 0x11, 0x1bd, 
       0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0x1c0, 0xb, 0x11, 0x3, 0x11, 0x5, 
       0x11, 0x1c3, 0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
       0x3, 0x12, 0x7, 0x12, 0x1ca, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0x1cd, 
       0xb, 0x12, 0x3, 0x12, 0x5, 0x12, 0x1d0, 0xa, 0x12, 0x3, 0x12, 0x3, 
       0x12, 0x3, 0x12, 0x3, 0x12, 0x7, 0x12, 0x1d6, 0xa, 0x12, 0xc, 0x12, 
       0xe, 0x12, 0x1d9, 0xb, 0x12, 0x3, 0x12, 0x5, 0x12, 0x1dc, 0xa, 0x12, 
       0x5, 0x12, 0x1de, 0xa, 0x12, 0x3, 0x13, 0x3, 0x13, 0x6, 0x13, 0x1e2, 
       0xa, 0x13, 0xd, 0x13, 0xe, 0x13, 0x1e3, 0x3, 0x13, 0x3, 0x13, 0x3, 
       0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x1eb, 0xa, 0x14, 0x3, 0x14, 
       0x6, 0x14, 0x1ee, 0xa, 0x14, 0xd, 0x14, 0xe, 0x14, 0x1ef, 0x3, 0x15, 
       0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x1f6, 0xa, 0x16, 0x3, 
       0x16, 0x7, 0x16, 0x1f9, 0xa, 0x16, 0xc, 0x16, 0xe, 0x16, 0x1fc, 0xb, 
       0x16, 0x3, 0x16, 0x5, 0x16, 0x1ff, 0xa, 0x16, 0x3, 0x17, 0x3, 0x17, 
       0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x205, 0xa, 0x17, 0x3, 0x18, 0x3, 
       0x18, 0x3, 0x18, 0x3, 0x19, 0x7, 0x19, 0x20b, 0xa, 0x19, 0xc, 0x19, 
       0xe, 0x19, 0x20e, 0xb, 0x19, 0x3, 0x19, 0x3, 0x19, 0x7, 0x19, 0x212, 
       0xa, 0x19, 0xc, 0x19, 0xe, 0x19, 0x215, 0xb, 0x19, 0x5, 0x19, 0x217, 
       0xa, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
       0x6, 0x19, 0x21e, 0xa, 0x19, 0xd, 0x19, 0xe, 0x19, 0x21f, 0x3, 0x19, 
       0x7, 0x19, 0x223, 0xa, 0x19, 0xc, 0x19, 0xe, 0x19, 0x226, 0xb, 0x19, 
       0x3, 0x19, 0x5, 0x19, 0x229, 0xa, 0x19, 0x3, 0x19, 0x7, 0x19, 0x22c, 
       0xa, 0x19, 0xc, 0x19, 0xe, 0x19, 0x22f, 0xb, 0x19, 0x3, 0x19, 0x5, 
       0x19, 0x232, 0xa, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
       0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
       0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
       0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
       0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
       0x5, 0x1a, 0x250, 0xa, 0x1a, 0x3, 0x1b, 0x5, 0x1b, 0x253, 0xa, 0x1b, 
       0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x257, 0xa, 0x1b, 0x3, 0x1b, 0x7, 
       0x1b, 0x25a, 0xa, 0x1b, 0xc, 0x1b, 0xe, 0x1b, 0x25d, 0xb, 0x1b, 0x3, 
       0x1b, 0x5, 0x1b, 0x260, 0xa, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x263, 0xa, 
       0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x7, 0x1b, 0x267, 0xa, 0x1b, 0xc, 0x1b, 
       0xe, 0x1b, 0x26a, 0xb, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x26d, 0xa, 0x1b, 
       0x5, 0x1b, 0x26f, 0xa, 0x1b, 0x3, 0x1c, 0x5, 0x1c, 0x272, 0xa, 0x1c, 
       0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x276, 0xa, 0x1c, 0x3, 0x1c, 0x5, 
       0x1c, 0x279, 0xa, 0x1c, 0x3, 0x1c, 0x7, 0x1c, 0x27c, 0xa, 0x1c, 0xc, 
       0x1c, 0xe, 0x1c, 0x27f, 0xb, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x282, 0xa, 
       0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x285, 0xa, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
       0x5, 0x1c, 0x289, 0xa, 0x1c, 0x3, 0x1c, 0x7, 0x1c, 0x28c, 0xa, 0x1c, 
       0xc, 0x1c, 0xe, 0x1c, 0x28f, 0xb, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x292, 
       0xa, 0x1c, 0x5, 0x1c, 0x294, 0xa, 0x1c, 0x3, 0x1d, 0x5, 0x1d, 0x297, 
       0xa, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x29b, 0xa, 0x1d, 0x3, 
       0x1d, 0x7, 0x1d, 0x29e, 0xa, 0x1d, 0xc, 0x1d, 0xe, 0x1d, 0x2a1, 0xb, 
       0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x2a4, 0xa, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 
       0x2a7, 0xa, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x7, 0x1d, 0x2ab, 0xa, 0x1d, 
       0xc, 0x1d, 0xe, 0x1d, 0x2ae, 0xb, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x2b1, 
       0xa, 0x1d, 0x5, 0x1d, 0x2b3, 0xa, 0x1d, 0x3, 0x1e, 0x5, 0x1e, 0x2b6, 
       0xa, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x2b9, 0xa, 0x1e, 0x3, 0x1e, 0x3, 
       0x1e, 0x5, 0x1e, 0x2bd, 0xa, 0x1e, 0x3, 0x1e, 0x7, 0x1e, 0x2c0, 0xa, 
       0x1e, 0xc, 0x1e, 0xe, 0x1e, 0x2c3, 0xb, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 
       0x2c6, 0xa, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x2c9, 0xa, 0x1e, 0x3, 0x1e, 
       0x5, 0x1e, 0x2cc, 0xa, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x7, 0x1e, 0x2d0, 
       0xa, 0x1e, 0xc, 0x1e, 0xe, 0x1e, 0x2d3, 0xb, 0x1e, 0x3, 0x1e, 0x5, 
       0x1e, 0x2d6, 0xa, 0x1e, 0x5, 0x1e, 0x2d8, 0xa, 0x1e, 0x3, 0x1f, 0x5, 
       0x1f, 0x2db, 0xa, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x2de, 0xa, 0x1f, 0x3, 
       0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x2e2, 0xa, 0x1f, 0x3, 0x1f, 0x7, 0x1f, 
       0x2e5, 0xa, 0x1f, 0xc, 0x1f, 0xe, 0x1f, 0x2e8, 0xb, 0x1f, 0x3, 0x1f, 
       0x5, 0x1f, 0x2eb, 0xa, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x2ee, 0xa, 0x1f, 
       0x3, 0x1f, 0x5, 0x1f, 0x2f1, 0xa, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x7, 
       0x1f, 0x2f5, 0xa, 0x1f, 0xc, 0x1f, 0xe, 0x1f, 0x2f8, 0xb, 0x1f, 0x3, 
       0x1f, 0x5, 0x1f, 0x2fb, 0xa, 0x1f, 0x5, 0x1f, 0x2fd, 0xa, 0x1f, 0x3, 
       0x20, 0x5, 0x20, 0x300, 0xa, 0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 
       0x304, 0xa, 0x20, 0x3, 0x20, 0x7, 0x20, 0x307, 0xa, 0x20, 0xc, 0x20, 
       0xe, 0x20, 0x30a, 0xb, 0x20, 0x3, 0x20, 0x5, 0x20, 0x30d, 0xa, 0x20, 
       0x3, 0x20, 0x5, 0x20, 0x310, 0xa, 0x20, 0x3, 0x20, 0x3, 0x20, 0x7, 
       0x20, 0x314, 0xa, 0x20, 0xc, 0x20, 0xe, 0x20, 0x317, 0xb, 0x20, 0x3, 
       0x20, 0x5, 0x20, 0x31a, 0xa, 0x20, 0x5, 0x20, 0x31c, 0xa, 0x20, 0x3, 
       0x21, 0x5, 0x21, 0x31f, 0xa, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 
       0x323, 0xa, 0x21, 0x3, 0x21, 0x7, 0x21, 0x326, 0xa, 0x21, 0xc, 0x21, 
       0xe, 0x21, 0x329, 0xb, 0x21, 0x3, 0x21, 0x5, 0x21, 0x32c, 0xa, 0x21, 
       0x3, 0x21, 0x5, 0x21, 0x32f, 0xa, 0x21, 0x3, 0x21, 0x3, 0x21, 0x7, 
       0x21, 0x333, 0xa, 0x21, 0xc, 0x21, 0xe, 0x21, 0x336, 0xb, 0x21, 0x3, 
       0x21, 0x5, 0x21, 0x339, 0xa, 0x21, 0x5, 0x21, 0x33b, 0xa, 0x21, 0x3, 
       0x22, 0x3, 0x22, 0x6, 0x22, 0x33f, 0xa, 0x22, 0xd, 0x22, 0xe, 0x22, 
       0x340, 0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x5, 0x23, 0x346, 0xa, 0x23, 
       0x3, 0x23, 0x3, 0x23, 0x7, 0x23, 0x34a, 0xa, 0x23, 0xc, 0x23, 0xe, 
       0x23, 0x34d, 0xb, 0x23, 0x3, 0x23, 0x7, 0x23, 0x350, 0xa, 0x23, 0xc, 
       0x23, 0xe, 0x23, 0x353, 0xb, 0x23, 0x3, 0x23, 0x3, 0x23, 0x7, 0x23, 
       0x357, 0xa, 0x23, 0xc, 0x23, 0xe, 0x23, 0x35a, 0xb, 0x23, 0x3, 0x23, 
       0x5, 0x23, 0x35d, 0xa, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x25, 0x3, 
       0x25, 0x7, 0x25, 0x363, 0xa, 0x25, 0xc, 0x25, 0xe, 0x25, 0x366, 0xb, 
       0x25, 0x3, 0x25, 0x5, 0x25, 0x369, 0xa, 0x25, 0x3, 0x26, 0x5, 0x26, 
       0x36c, 0xa, 0x26, 0x3, 0x26, 0x3, 0x26, 0x5, 0x26, 0x370, 0xa, 0x26, 
       0x3, 0x26, 0x7, 0x26, 0x373, 0xa, 0x26, 0xc, 0x26, 0xe, 0x26, 0x376, 
       0xb, 0x26, 0x3, 0x26, 0x5, 0x26, 0x379, 0xa, 0x26, 0x3, 0x26, 0x5, 
       0x26, 0x37c, 0xa, 0x26, 0x3, 0x26, 0x3, 0x26, 0x7, 0x26, 0x380, 0xa, 
       0x26, 0xc, 0x26, 0xe, 0x26, 0x383, 0xb, 0x26, 0x3, 0x26, 0x5, 0x26, 
       0x386, 0xa, 0x26, 0x5, 0x26, 0x388, 0xa, 0x26, 0x3, 0x27, 0x5, 0x27, 
       0x38b, 0xa, 0x27, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x38f, 0xa, 0x27, 
       0x3, 0x27, 0x7, 0x27, 0x392, 0xa, 0x27, 0xc, 0x27, 0xe, 0x27, 0x395, 
       0xb, 0x27, 0x3, 0x27, 0x5, 0x27, 0x398, 0xa, 0x27, 0x3, 0x27, 0x5, 
       0x27, 0x39b, 0xa, 0x27, 0x3, 0x27, 0x3, 0x27, 0x7, 0x27, 0x39f, 0xa, 
       0x27, 0xc, 0x27, 0xe, 0x27, 0x3a2, 0xb, 0x27, 0x3, 0x27, 0x5, 0x27, 
       0x3a5, 0xa, 0x27, 0x5, 0x27, 0x3a7, 0xa, 0x27, 0x3, 0x28, 0x5, 0x28, 
       0x3aa, 0xa, 0x28, 0x3, 0x28, 0x5, 0x28, 0x3ad, 0xa, 0x28, 0x3, 0x28, 
       0x3, 0x28, 0x5, 0x28, 0x3b1, 0xa, 0x28, 0x3, 0x28, 0x7, 0x28, 0x3b4, 
       0xa, 0x28, 0xc, 0x28, 0xe, 0x28, 0x3b7, 0xb, 0x28, 0x3, 0x28, 0x5, 
       0x28, 0x3ba, 0xa, 0x28, 0x3, 0x28, 0x5, 0x28, 0x3bd, 0xa, 0x28, 0x3, 
       0x28, 0x5, 0x28, 0x3c0, 0xa, 0x28, 0x3, 0x28, 0x3, 0x28, 0x7, 0x28, 
       0x3c4, 0xa, 0x28, 0xc, 0x28, 0xe, 0x28, 0x3c7, 0xb, 0x28, 0x3, 0x28, 
       0x5, 0x28, 0x3ca, 0xa, 0x28, 0x5, 0x28, 0x3cc, 0xa, 0x28, 0x3, 0x29, 
       0x5, 0x29, 0x3cf, 0xa, 0x29, 0x3, 0x29, 0x5, 0x29, 0x3d2, 0xa, 0x29, 
       0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 0x3d6, 0xa, 0x29, 0x3, 0x29, 0x7, 
       0x29, 0x3d9, 0xa, 0x29, 0xc, 0x29, 0xe, 0x29, 0x3dc, 0xb, 0x29, 0x3, 
       0x29, 0x5, 0x29, 0x3df, 0xa, 0x29, 0x3, 0x29, 0x5, 0x29, 0x3e2, 0xa, 
       0x29, 0x3, 0x29, 0x5, 0x29, 0x3e5, 0xa, 0x29, 0x3, 0x29, 0x3, 0x29, 
       0x7, 0x29, 0x3e9, 0xa, 0x29, 0xc, 0x29, 0xe, 0x29, 0x3ec, 0xb, 0x29, 
       0x3, 0x29, 0x5, 0x29, 0x3ef, 0xa, 0x29, 0x5, 0x29, 0x3f1, 0xa, 0x29, 
       0x3, 0x2a, 0x5, 0x2a, 0x3f4, 0xa, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x3f7, 
       0xa, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x3fb, 0xa, 0x2a, 0x3, 
       0x2a, 0x7, 0x2a, 0x3fe, 0xa, 0x2a, 0xc, 0x2a, 0xe, 0x2a, 0x401, 0xb, 
       0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x404, 0xa, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 
       0x407, 0xa, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x40a, 0xa, 0x2a, 0x3, 0x2a, 
       0x3, 0x2a, 0x7, 0x2a, 0x40e, 0xa, 0x2a, 0xc, 0x2a, 0xe, 0x2a, 0x411, 
       0xb, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x414, 0xa, 0x2a, 0x5, 0x2a, 0x416, 
       0xa, 0x2a, 0x3, 0x2b, 0x5, 0x2b, 0x419, 0xa, 0x2b, 0x3, 0x2b, 0x5, 
       0x2b, 0x41c, 0xa, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x5, 0x2b, 0x420, 0xa, 
       0x2b, 0x3, 0x2b, 0x7, 0x2b, 0x423, 0xa, 0x2b, 0xc, 0x2b, 0xe, 0x2b, 
       0x426, 0xb, 0x2b, 0x3, 0x2b, 0x5, 0x2b, 0x429, 0xa, 0x2b, 0x3, 0x2b, 
       0x5, 0x2b, 0x42c, 0xa, 0x2b, 0x3, 0x2b, 0x5, 0x2b, 0x42f, 0xa, 0x2b, 
       0x3, 0x2b, 0x3, 0x2b, 0x7, 0x2b, 0x433, 0xa, 0x2b, 0xc, 0x2b, 0xe, 
       0x2b, 0x436, 0xb, 0x2b, 0x3, 0x2b, 0x5, 0x2b, 0x439, 0xa, 0x2b, 0x5, 
       0x2b, 0x43b, 0xa, 0x2b, 0x3, 0x2c, 0x5, 0x2c, 0x43e, 0xa, 0x2c, 0x3, 
       0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x442, 0xa, 0x2c, 0x3, 0x2c, 0x7, 0x2c, 
       0x445, 0xa, 0x2c, 0xc, 0x2c, 0xe, 0x2c, 0x448, 0xb, 0x2c, 0x3, 0x2c, 
       0x5, 0x2c, 0x44b, 0xa, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x44e, 0xa, 0x2c, 
       0x3, 0x2c, 0x3, 0x2c, 0x7, 0x2c, 0x452, 0xa, 0x2c, 0xc, 0x2c, 0xe, 
       0x2c, 0x455, 0xb, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x458, 0xa, 0x2c, 0x5, 
       0x2c, 0x45a, 0xa, 0x2c, 0x3, 0x2d, 0x5, 0x2d, 0x45d, 0xa, 0x2d, 0x3, 
       0x2d, 0x5, 0x2d, 0x460, 0xa, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 
       0x464, 0xa, 0x2d, 0x3, 0x2d, 0x7, 0x2d, 0x467, 0xa, 0x2d, 0xc, 0x2d, 
       0xe, 0x2d, 0x46a, 0xb, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x46d, 0xa, 0x2d, 
       0x3, 0x2d, 0x5, 0x2d, 0x470, 0xa, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x473, 
       0xa, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x7, 0x2d, 0x477, 0xa, 0x2d, 0xc, 
       0x2d, 0xe, 0x2d, 0x47a, 0xb, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x47d, 0xa, 
       0x2d, 0x5, 0x2d, 0x47f, 0xa, 0x2d, 0x3, 0x2e, 0x5, 0x2e, 0x482, 0xa, 
       0x2e, 0x3, 0x2e, 0x5, 0x2e, 0x485, 0xa, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 
       0x5, 0x2e, 0x489, 0xa, 0x2e, 0x3, 0x2e, 0x7, 0x2e, 0x48c, 0xa, 0x2e, 
       0xc, 0x2e, 0xe, 0x2e, 0x48f, 0xb, 0x2e, 0x3, 0x2e, 0x5, 0x2e, 0x492, 
       0xa, 0x2e, 0x3, 0x2e, 0x5, 0x2e, 0x495, 0xa, 0x2e, 0x3, 0x2e, 0x5, 
       0x2e, 0x498, 0xa, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x7, 0x2e, 0x49c, 0xa, 
       0x2e, 0xc, 0x2e, 0xe, 0x2e, 0x49f, 0xb, 0x2e, 0x3, 0x2e, 0x5, 0x2e, 
       0x4a2, 0xa, 0x2e, 0x5, 0x2e, 0x4a4, 0xa, 0x2e, 0x3, 0x2f, 0x5, 0x2f, 
       0x4a7, 0xa, 0x2f, 0x3, 0x2f, 0x5, 0x2f, 0x4aa, 0xa, 0x2f, 0x3, 0x2f, 
       0x3, 0x2f, 0x5, 0x2f, 0x4ae, 0xa, 0x2f, 0x3, 0x2f, 0x7, 0x2f, 0x4b1, 
       0xa, 0x2f, 0xc, 0x2f, 0xe, 0x2f, 0x4b4, 0xb, 0x2f, 0x3, 0x2f, 0x5, 
       0x2f, 0x4b7, 0xa, 0x2f, 0x3, 0x2f, 0x5, 0x2f, 0x4ba, 0xa, 0x2f, 0x3, 
       0x2f, 0x5, 0x2f, 0x4bd, 0xa, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x7, 0x2f, 
       0x4c1, 0xa, 0x2f, 0xc, 0x2f, 0xe, 0x2f, 0x4c4, 0xb, 0x2f, 0x3, 0x2f, 
       0x5, 0x2f, 0x4c7, 0xa, 0x2f, 0x5, 0x2f, 0x4c9, 0xa, 0x2f, 0x3, 0x30, 
       0x5, 0x30, 0x4cc, 0xa, 0x30, 0x3, 0x30, 0x3, 0x30, 0x5, 0x30, 0x4d0, 
       0xa, 0x30, 0x3, 0x30, 0x7, 0x30, 0x4d3, 0xa, 0x30, 0xc, 0x30, 0xe, 
       0x30, 0x4d6, 0xb, 0x30, 0x3, 0x30, 0x5, 0x30, 0x4d9, 0xa, 0x30, 0x3, 
       0x30, 0x5, 0x30, 0x4dc, 0xa, 0x30, 0x3, 0x30, 0x3, 0x30, 0x7, 0x30, 
       0x4e0, 0xa, 0x30, 0xc, 0x30, 0xe, 0x30, 0x4e3, 0xb, 0x30, 0x3, 0x30, 
       0x5, 0x30, 0x4e6, 0xa, 0x30, 0x5, 0x30, 0x4e8, 0xa, 0x30, 0x3, 0x31, 
       0x5, 0x31, 0x4eb, 0xa, 0x31, 0x3, 0x31, 0x5, 0x31, 0x4ee, 0xa, 0x31, 
       0x3, 0x31, 0x3, 0x31, 0x5, 0x31, 0x4f2, 0xa, 0x31, 0x3, 0x31, 0x7, 
       0x31, 0x4f5, 0xa, 0x31, 0xc, 0x31, 0xe, 0x31, 0x4f8, 0xb, 0x31, 0x3, 
       0x31, 0x5, 0x31, 0x4fb, 0xa, 0x31, 0x3, 0x31, 0x5, 0x31, 0x4fe, 0xa, 
       0x31, 0x3, 0x31, 0x5, 0x31, 0x501, 0xa, 0x31, 0x3, 0x31, 0x3, 0x31, 
       0x7, 0x31, 0x505, 0xa, 0x31, 0xc, 0x31, 0xe, 0x31, 0x508, 0xb, 0x31, 
       0x3, 0x31, 0x5, 0x31, 0x50b, 0xa, 0x31, 0x5, 0x31, 0x50d, 0xa, 0x31, 
       0x3, 0x32, 0x5, 0x32, 0x510, 0xa, 0x32, 0x3, 0x32, 0x3, 0x32, 0x5, 
       0x32, 0x514, 0xa, 0x32, 0x3, 0x32, 0x7, 0x32, 0x517, 0xa, 0x32, 0xc, 
       0x32, 0xe, 0x32, 0x51a, 0xb, 0x32, 0x3, 0x32, 0x5, 0x32, 0x51d, 0xa, 
       0x32, 0x3, 0x32, 0x5, 0x32, 0x520, 0xa, 0x32, 0x3, 0x32, 0x3, 0x32, 
       0x7, 0x32, 0x524, 0xa, 0x32, 0xc, 0x32, 0xe, 0x32, 0x527, 0xb, 0x32, 
       0x3, 0x32, 0x5, 0x32, 0x52a, 0xa, 0x32, 0x5, 0x32, 0x52c, 0xa, 0x32, 
       0x3, 0x33, 0x5, 0x33, 0x52f, 0xa, 0x33, 0x3, 0x33, 0x5, 0x33, 0x532, 
       0xa, 0x33, 0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x536, 0xa, 0x33, 0x3, 
       0x33, 0x7, 0x33, 0x539, 0xa, 0x33, 0xc, 0x33, 0xe, 0x33, 0x53c, 0xb, 
       0x33, 0x3, 0x33, 0x5, 0x33, 0x53f, 0xa, 0x33, 0x3, 0x33, 0x5, 0x33, 
       0x542, 0xa, 0x33, 0x3, 0x33, 0x5, 0x33, 0x545, 0xa, 0x33, 0x3, 0x33, 
       0x3, 0x33, 0x7, 0x33, 0x549, 0xa, 0x33, 0xc, 0x33, 0xe, 0x33, 0x54c, 
       0xb, 0x33, 0x3, 0x33, 0x5, 0x33, 0x54f, 0xa, 0x33, 0x5, 0x33, 0x551, 
       0xa, 0x33, 0x3, 0x34, 0x5, 0x34, 0x554, 0xa, 0x34, 0x3, 0x34, 0x5, 
       0x34, 0x557, 0xa, 0x34, 0x3, 0x34, 0x3, 0x34, 0x5, 0x34, 0x55b, 0xa, 
       0x34, 0x3, 0x34, 0x7, 0x34, 0x55e, 0xa, 0x34, 0xc, 0x34, 0xe, 0x34, 
       0x561, 0xb, 0x34, 0x3, 0x34, 0x5, 0x34, 0x564, 0xa, 0x34, 0x3, 0x34, 
       0x5, 0x34, 0x567, 0xa, 0x34, 0x3, 0x34, 0x5, 0x34, 0x56a, 0xa, 0x34, 
       0x3, 0x34, 0x3, 0x34, 0x7, 0x34, 0x56e, 0xa, 0x34, 0xc, 0x34, 0xe, 
       0x34, 0x571, 0xb, 0x34, 0x3, 0x34, 0x5, 0x34, 0x574, 0xa, 0x34, 0x5, 
       0x34, 0x576, 0xa, 0x34, 0x3, 0x35, 0x3, 0x35, 0x5, 0x35, 0x57a, 0xa, 
       0x35, 0x3, 0x35, 0x3, 0x35, 0x5, 0x35, 0x57e, 0xa, 0x35, 0x3, 0x35, 
       0x3, 0x35, 0x5, 0x35, 0x582, 0xa, 0x35, 0x3, 0x35, 0x7, 0x35, 0x585, 
       0xa, 0x35, 0xc, 0x35, 0xe, 0x35, 0x588, 0xb, 0x35, 0x3, 0x35, 0x5, 
       0x35, 0x58b, 0xa, 0x35, 0x3, 0x36, 0x3, 0x36, 0x6, 0x36, 0x58f, 0xa, 
       0x36, 0xd, 0x36, 0xe, 0x36, 0x590, 0x3, 0x36, 0x3, 0x36, 0x3, 0x37, 
       0x3, 0x37, 0x6, 0x37, 0x597, 0xa, 0x37, 0xd, 0x37, 0xe, 0x37, 0x598, 
       0x3, 0x37, 0x3, 0x37, 0x3, 0x38, 0x3, 0x38, 0x6, 0x38, 0x59f, 0xa, 
       0x38, 0xd, 0x38, 0xe, 0x38, 0x5a0, 0x3, 0x38, 0x3, 0x38, 0x3, 0x39, 
       0x3, 0x39, 0x6, 0x39, 0x5a7, 0xa, 0x39, 0xd, 0x39, 0xe, 0x39, 0x5a8, 
       0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 
       0x7, 0x3a, 0x5b1, 0xa, 0x3a, 0xc, 0x3a, 0xe, 0x3a, 0x5b4, 0xb, 0x3a, 
       0x3, 0x3a, 0x7, 0x3a, 0x5b7, 0xa, 0x3a, 0xc, 0x3a, 0xe, 0x3a, 0x5ba, 
       0xb, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x7, 0x3a, 0x5be, 0xa, 0x3a, 0xc, 
       0x3a, 0xe, 0x3a, 0x5c1, 0xb, 0x3a, 0x3, 0x3a, 0x5, 0x3a, 0x5c4, 0xa, 
       0x3a, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x7, 
       0x3c, 0x5cb, 0xa, 0x3c, 0xc, 0x3c, 0xe, 0x3c, 0x5ce, 0xb, 0x3c, 0x3, 
       0x3c, 0x5, 0x3c, 0x5d1, 0xa, 0x3c, 0x3, 0x3d, 0x3, 0x3d, 0x7, 0x3d, 
       0x5d5, 0xa, 0x3d, 0xc, 0x3d, 0xe, 0x3d, 0x5d8, 0xb, 0x3d, 0x3, 0x3d, 
       0x5, 0x3d, 0x5db, 0xa, 0x3d, 0x3, 0x3e, 0x3, 0x3e, 0x5, 0x3e, 0x5df, 
       0xa, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x5, 0x3e, 0x5e3, 0xa, 0x3e, 0x3, 
       0x3e, 0x7, 0x3e, 0x5e6, 0xa, 0x3e, 0xc, 0x3e, 0xe, 0x3e, 0x5e9, 0xb, 
       0x3e, 0x3, 0x3e, 0x5, 0x3e, 0x5ec, 0xa, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 
       0x5, 0x3e, 0x5f0, 0xa, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x7, 0x3e, 0x5f4, 
       0xa, 0x3e, 0xc, 0x3e, 0xe, 0x3e, 0x5f7, 0xb, 0x3e, 0x3, 0x3e, 0x5, 
       0x3e, 0x5fa, 0xa, 0x3e, 0x5, 0x3e, 0x5fc, 0xa, 0x3e, 0x3, 0x3f, 0x3, 
       0x3f, 0x3, 0x3f, 0x5, 0x3f, 0x601, 0xa, 0x3f, 0x3, 0x3f, 0x7, 0x3f, 
       0x604, 0xa, 0x3f, 0xc, 0x3f, 0xe, 0x3f, 0x607, 0xb, 0x3f, 0x3, 0x3f, 
       0x5, 0x3f, 0x60a, 0xa, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x7, 
       0x3f, 0x60f, 0xa, 0x3f, 0xc, 0x3f, 0xe, 0x3f, 0x612, 0xb, 0x3f, 0x3, 
       0x3f, 0x5, 0x3f, 0x615, 0xa, 0x3f, 0x5, 0x3f, 0x617, 0xa, 0x3f, 0x3, 
       0x40, 0x3, 0x40, 0x3, 0x40, 0x7, 0x40, 0x61c, 0xa, 0x40, 0xc, 0x40, 
       0xe, 0x40, 0x61f, 0xb, 0x40, 0x3, 0x40, 0x5, 0x40, 0x622, 0xa, 0x40, 
       0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x7, 0x41, 0x628, 0xa, 
       0x41, 0xc, 0x41, 0xe, 0x41, 0x62b, 0xb, 0x41, 0x3, 0x41, 0x7, 0x41, 
       0x62e, 0xa, 0x41, 0xc, 0x41, 0xe, 0x41, 0x631, 0xb, 0x41, 0x3, 0x41, 
       0x5, 0x41, 0x634, 0xa, 0x41, 0x3, 0x42, 0x3, 0x42, 0x3, 0x43, 0x3, 
       0x43, 0x5, 0x43, 0x63a, 0xa, 0x43, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 
       0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 
       0x3, 0x44, 0x3, 0x44, 0x5, 0x44, 0x647, 0xa, 0x44, 0x3, 0x45, 0x3, 
       0x45, 0x3, 0x45, 0x3, 0x45, 0x7, 0x45, 0x64d, 0xa, 0x45, 0xc, 0x45, 
       0xe, 0x45, 0x650, 0xb, 0x45, 0x3, 0x45, 0x5, 0x45, 0x653, 0xa, 0x45, 
       0x3, 0x45, 0x3, 0x45, 0x3, 0x45, 0x7, 0x45, 0x658, 0xa, 0x45, 0xc, 
       0x45, 0xe, 0x45, 0x65b, 0xb, 0x45, 0x3, 0x45, 0x5, 0x45, 0x65e, 0xa, 
       0x45, 0x5, 0x45, 0x660, 0xa, 0x45, 0x3, 0x46, 0x3, 0x46, 0x3, 0x46, 
       0x6, 0x46, 0x665, 0xa, 0x46, 0xd, 0x46, 0xe, 0x46, 0x666, 0x3, 0x46, 
       0x3, 0x46, 0x3, 0x47, 0x3, 0x47, 0x3, 0x47, 0x7, 0x47, 0x66e, 0xa, 
       0x47, 0xc, 0x47, 0xe, 0x47, 0x671, 0xb, 0x47, 0x3, 0x47, 0x3, 0x47, 
       0x7, 0x47, 0x675, 0xa, 0x47, 0xc, 0x47, 0xe, 0x47, 0x678, 0xb, 0x47, 
       0x3, 0x47, 0x5, 0x47, 0x67b, 0xa, 0x47, 0x3, 0x48, 0x3, 0x48, 0x3, 
       0x49, 0x3, 0x49, 0x7, 0x49, 0x681, 0xa, 0x49, 0xc, 0x49, 0xe, 0x49, 
       0x684, 0xb, 0x49, 0x3, 0x49, 0x5, 0x49, 0x687, 0xa, 0x49, 0x3, 0x4a, 
       0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x7, 0x4a, 0x68e, 0xa, 
       0x4a, 0xc, 0x4a, 0xe, 0x4a, 0x691, 0xb, 0x4a, 0x3, 0x4a, 0x5, 0x4a, 
       0x694, 0xa, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x7, 
       0x4a, 0x69a, 0xa, 0x4a, 0xc, 0x4a, 0xe, 0x4a, 0x69d, 0xb, 0x4a, 0x3, 
       0x4a, 0x5, 0x4a, 0x6a0, 0xa, 0x4a, 0x5, 0x4a, 0x6a2, 0xa, 0x4a, 0x3, 
       0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x7, 0x4b, 0x6a8, 0xa, 0x4b, 
       0xc, 0x4b, 0xe, 0x4b, 0x6ab, 0xb, 0x4b, 0x3, 0x4b, 0x5, 0x4b, 0x6ae, 
       0xa, 0x4b, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x7, 0x4c, 
       0x6b4, 0xa, 0x4c, 0xc, 0x4c, 0xe, 0x4c, 0x6b7, 0xb, 0x4c, 0x3, 0x4c, 
       0x5, 0x4c, 0x6ba, 0xa, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x7, 
       0x4c, 0x6bf, 0xa, 0x4c, 0xc, 0x4c, 0xe, 0x4c, 0x6c2, 0xb, 0x4c, 0x3, 
       0x4c, 0x5, 0x4c, 0x6c5, 0xa, 0x4c, 0x5, 0x4c, 0x6c7, 0xa, 0x4c, 0x3, 
       0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x7, 0x4d, 0x6cd, 0xa, 0x4d, 
       0xc, 0x4d, 0xe, 0x4d, 0x6d0, 0xb, 0x4d, 0x3, 0x4d, 0x5, 0x4d, 0x6d3, 
       0xa, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x7, 0x4d, 0x6d8, 0xa, 
       0x4d, 0xc, 0x4d, 0xe, 0x4d, 0x6db, 0xb, 0x4d, 0x3, 0x4d, 0x5, 0x4d, 
       0x6de, 0xa, 0x4d, 0x5, 0x4d, 0x6e0, 0xa, 0x4d, 0x3, 0x4e, 0x3, 0x4e, 
       0x3, 0x4e, 0x3, 0x4e, 0x7, 0x4e, 0x6e6, 0xa, 0x4e, 0xc, 0x4e, 0xe, 
       0x4e, 0x6e9, 0xb, 0x4e, 0x3, 0x4e, 0x5, 0x4e, 0x6ec, 0xa, 0x4e, 0x3, 
       0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x7, 0x4e, 0x6f1, 0xa, 0x4e, 0xc, 0x4e, 
       0xe, 0x4e, 0x6f4, 0xb, 0x4e, 0x3, 0x4e, 0x5, 0x4e, 0x6f7, 0xa, 0x4e, 
       0x5, 0x4e, 0x6f9, 0xa, 0x4e, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x3, 
       0x4f, 0x7, 0x4f, 0x6ff, 0xa, 0x4f, 0xc, 0x4f, 0xe, 0x4f, 0x702, 0xb, 
       0x4f, 0x3, 0x4f, 0x5, 0x4f, 0x705, 0xa, 0x4f, 0x3, 0x4f, 0x3, 0x4f, 
       0x3, 0x4f, 0x7, 0x4f, 0x70a, 0xa, 0x4f, 0xc, 0x4f, 0xe, 0x4f, 0x70d, 
       0xb, 0x4f, 0x3, 0x4f, 0x5, 0x4f, 0x710, 0xa, 0x4f, 0x5, 0x4f, 0x712, 
       0xa, 0x4f, 0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x7, 0x50, 
       0x718, 0xa, 0x50, 0xc, 0x50, 0xe, 0x50, 0x71b, 0xb, 0x50, 0x3, 0x50, 
       0x5, 0x50, 0x71e, 0xa, 0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x7, 
       0x50, 0x723, 0xa, 0x50, 0xc, 0x50, 0xe, 0x50, 0x726, 0xb, 0x50, 0x3, 
       0x50, 0x5, 0x50, 0x729, 0xa, 0x50, 0x5, 0x50, 0x72b, 0xa, 0x50, 0x3, 
       0x51, 0x3, 0x51, 0x5, 0x51, 0x72f, 0xa, 0x51, 0x3, 0x51, 0x3, 0x51, 
       0x3, 0x51, 0x7, 0x51, 0x734, 0xa, 0x51, 0xc, 0x51, 0xe, 0x51, 0x737, 
       0xb, 0x51, 0x3, 0x51, 0x5, 0x51, 0x73a, 0xa, 0x51, 0x3, 0x52, 0x3, 
       0x52, 0x3, 0x52, 0x7, 0x52, 0x73f, 0xa, 0x52, 0xc, 0x52, 0xe, 0x52, 
       0x742, 0xb, 0x52, 0x3, 0x52, 0x5, 0x52, 0x745, 0xa, 0x52, 0x3, 0x52, 
       0x3, 0x52, 0x7, 0x52, 0x749, 0xa, 0x52, 0xc, 0x52, 0xe, 0x52, 0x74c, 
       0xb, 0x52, 0x3, 0x52, 0x5, 0x52, 0x74f, 0xa, 0x52, 0x5, 0x52, 0x751, 
       0xa, 0x52, 0x3, 0x53, 0x3, 0x53, 0x6, 0x53, 0x755, 0xa, 0x53, 0xd, 
       0x53, 0xe, 0x53, 0x756, 0x3, 0x53, 0x3, 0x53, 0x3, 0x54, 0x3, 0x54, 
       0x7, 0x54, 0x75d, 0xa, 0x54, 0xc, 0x54, 0xe, 0x54, 0x760, 0xb, 0x54, 
       0x3, 0x54, 0x3, 0x54, 0x7, 0x54, 0x764, 0xa, 0x54, 0xc, 0x54, 0xe, 
       0x54, 0x767, 0xb, 0x54, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 0x3, 0x55, 
       0x3, 0x55, 0x5, 0x55, 0x76e, 0xa, 0x55, 0x3, 0x56, 0x3, 0x56, 0x7, 
       0x56, 0x772, 0xa, 0x56, 0xc, 0x56, 0xe, 0x56, 0x775, 0xb, 0x56, 0x3, 
       0x56, 0x5, 0x56, 0x778, 0xa, 0x56, 0x3, 0x57, 0x3, 0x57, 0x7, 0x57, 
       0x77c, 0xa, 0x57, 0xc, 0x57, 0xe, 0x57, 0x77f, 0xb, 0x57, 0x3, 0x57, 
       0x3, 0x57, 0x7, 0x57, 0x783, 0xa, 0x57, 0xc, 0x57, 0xe, 0x57, 0x786, 
       0xb, 0x57, 0x3, 0x57, 0x6, 0x57, 0x789, 0xa, 0x57, 0xd, 0x57, 0xe, 
       0x57, 0x78a, 0x3, 0x57, 0x3, 0x57, 0x7, 0x57, 0x78f, 0xa, 0x57, 0xc, 
       0x57, 0xe, 0x57, 0x792, 0xb, 0x57, 0x3, 0x57, 0x5, 0x57, 0x795, 0xa, 
       0x57, 0x3, 0x58, 0x3, 0x58, 0x7, 0x58, 0x799, 0xa, 0x58, 0xc, 0x58, 
       0xe, 0x58, 0x79c, 0xb, 0x58, 0x3, 0x58, 0x3, 0x58, 0x7, 0x58, 0x7a0, 
       0xa, 0x58, 0xc, 0x58, 0xe, 0x58, 0x7a3, 0xb, 0x58, 0x3, 0x58, 0x6, 
       0x58, 0x7a6, 0xa, 0x58, 0xd, 0x58, 0xe, 0x58, 0x7a7, 0x3, 0x58, 0x3, 
       0x58, 0x7, 0x58, 0x7ac, 0xa, 0x58, 0xc, 0x58, 0xe, 0x58, 0x7af, 0xb, 
       0x58, 0x3, 0x58, 0x5, 0x58, 0x7b2, 0xa, 0x58, 0x3, 0x59, 0x3, 0x59, 
       0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x6, 0x59, 0x7b9, 0xa, 0x59, 0xd, 
       0x59, 0xe, 0x59, 0x7ba, 0x3, 0x59, 0x3, 0x59, 0x7, 0x59, 0x7bf, 0xa, 
       0x59, 0xc, 0x59, 0xe, 0x59, 0x7c2, 0xb, 0x59, 0x3, 0x59, 0x5, 0x59, 
       0x7c5, 0xa, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 
       0x59, 0x6, 0x59, 0x7cc, 0xa, 0x59, 0xd, 0x59, 0xe, 0x59, 0x7cd, 0x3, 
       0x59, 0x3, 0x59, 0x6, 0x59, 0x7d2, 0xa, 0x59, 0xd, 0x59, 0xe, 0x59, 
       0x7d3, 0x3, 0x59, 0x3, 0x59, 0x7, 0x59, 0x7d8, 0xa, 0x59, 0xc, 0x59, 
       0xe, 0x59, 0x7db, 0xb, 0x59, 0x3, 0x59, 0x5, 0x59, 0x7de, 0xa, 0x59, 
       0x5, 0x59, 0x7e0, 0xa, 0x59, 0x3, 0x5a, 0x3, 0x5a, 0x3, 0x5a, 0x7, 
       0x5a, 0x7e5, 0xa, 0x5a, 0xc, 0x5a, 0xe, 0x5a, 0x7e8, 0xb, 0x5a, 0x3, 
       0x5a, 0x5, 0x5a, 0x7eb, 0xa, 0x5a, 0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5b, 
       0x3, 0x5b, 0x7, 0x5b, 0x7f1, 0xa, 0x5b, 0xc, 0x5b, 0xe, 0x5b, 0x7f4, 
       0xb, 0x5b, 0x3, 0x5b, 0x5, 0x5b, 0x7f7, 0xa, 0x5b, 0x3, 0x5b, 0x3, 
       0x5b, 0x3, 0x5b, 0x7, 0x5b, 0x7fc, 0xa, 0x5b, 0xc, 0x5b, 0xe, 0x5b, 
       0x7ff, 0xb, 0x5b, 0x3, 0x5b, 0x5, 0x5b, 0x802, 0xa, 0x5b, 0x5, 0x5b, 
       0x804, 0xa, 0x5b, 0x3, 0x5c, 0x3, 0x5c, 0x6, 0x5c, 0x808, 0xa, 0x5c, 
       0xd, 0x5c, 0xe, 0x5c, 0x809, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5d, 0x3, 
       0x5d, 0x3, 0x5d, 0x5, 0x5d, 0x811, 0xa, 0x5d, 0x3, 0x5d, 0x7, 0x5d, 
       0x814, 0xa, 0x5d, 0xc, 0x5d, 0xe, 0x5d, 0x817, 0xb, 0x5d, 0x3, 0x5d, 
       0x3, 0x5d, 0x7, 0x5d, 0x81b, 0xa, 0x5d, 0xc, 0x5d, 0xe, 0x5d, 0x81e, 
       0xb, 0x5d, 0x3, 0x5e, 0x3, 0x5e, 0x5, 0x5e, 0x822, 0xa, 0x5e, 0x3, 
       0x5f, 0x3, 0x5f, 0x7, 0x5f, 0x826, 0xa, 0x5f, 0xc, 0x5f, 0xe, 0x5f, 
       0x829, 0xb, 0x5f, 0x3, 0x5f, 0x5, 0x5f, 0x82c, 0xa, 0x5f, 0x3, 0x60, 
       0x3, 0x60, 0x3, 0x60, 0x7, 0x60, 0x831, 0xa, 0x60, 0xc, 0x60, 0xe, 
       0x60, 0x834, 0xb, 0x60, 0x3, 0x60, 0x5, 0x60, 0x837, 0xa, 0x60, 0x3, 
       0x61, 0x3, 0x61, 0x3, 0x61, 0x6, 0x61, 0x83c, 0xa, 0x61, 0xd, 0x61, 
       0xe, 0x61, 0x83d, 0x3, 0x61, 0x3, 0x61, 0x7, 0x61, 0x842, 0xa, 0x61, 
       0xc, 0x61, 0xe, 0x61, 0x845, 0xb, 0x61, 0x3, 0x61, 0x5, 0x61, 0x848, 
       0xa, 0x61, 0x3, 0x61, 0x3, 0x61, 0x6, 0x61, 0x84c, 0xa, 0x61, 0xd, 
       0x61, 0xe, 0x61, 0x84d, 0x3, 0x61, 0x7, 0x61, 0x851, 0xa, 0x61, 0xc, 
       0x61, 0xe, 0x61, 0x854, 0xb, 0x61, 0x3, 0x61, 0x5, 0x61, 0x857, 0xa, 
       0x61, 0x5, 0x61, 0x859, 0xa, 0x61, 0x3, 0x62, 0x3, 0x62, 0x5, 0x62, 
       0x85d, 0xa, 0x62, 0x3, 0x62, 0x5, 0x62, 0x860, 0xa, 0x62, 0x3, 0x62, 
       0x7, 0x62, 0x863, 0xa, 0x62, 0xc, 0x62, 0xe, 0x62, 0x866, 0xb, 0x62, 
       0x3, 0x62, 0x7, 0x62, 0x869, 0xa, 0x62, 0xc, 0x62, 0xe, 0x62, 0x86c, 
       0xb, 0x62, 0x3, 0x62, 0x5, 0x62, 0x86f, 0xa, 0x62, 0x3, 0x63, 0x3, 
       0x63, 0x3, 0x64, 0x3, 0x64, 0x5, 0x64, 0x875, 0xa, 0x64, 0x3, 0x65, 
       0x3, 0x65, 0x3, 0x65, 0x3, 0x65, 0x6, 0x65, 0x87b, 0xa, 0x65, 0xd, 
       0x65, 0xe, 0x65, 0x87c, 0x3, 0x66, 0x5, 0x66, 0x880, 0xa, 0x66, 0x3, 
       0x66, 0x3, 0x66, 0x5, 0x66, 0x884, 0xa, 0x66, 0x3, 0x66, 0x5, 0x66, 
       0x887, 0xa, 0x66, 0x3, 0x67, 0x3, 0x67, 0x5, 0x67, 0x88b, 0xa, 0x67, 
       0x3, 0x67, 0x3, 0x67, 0x6, 0x67, 0x88f, 0xa, 0x67, 0xd, 0x67, 0xe, 
       0x67, 0x890, 0x3, 0x67, 0x6, 0x67, 0x894, 0xa, 0x67, 0xd, 0x67, 0xe, 
       0x67, 0x895, 0x5, 0x67, 0x898, 0xa, 0x67, 0x3, 0x67, 0x3, 0x67, 0x3, 
       0x67, 0x3, 0x67, 0x5, 0x67, 0x89e, 0xa, 0x67, 0x3, 0x67, 0x3, 0x67, 
       0x6, 0x67, 0x8a2, 0xa, 0x67, 0xd, 0x67, 0xe, 0x67, 0x8a3, 0x3, 0x67, 
       0x6, 0x67, 0x8a7, 0xa, 0x67, 0xd, 0x67, 0xe, 0x67, 0x8a8, 0x5, 0x67, 
       0x8ab, 0xa, 0x67, 0x3, 0x67, 0x3, 0x67, 0x3, 0x67, 0x3, 0x67, 0x5, 
       0x67, 0x8b1, 0xa, 0x67, 0x3, 0x67, 0x3, 0x67, 0x6, 0x67, 0x8b5, 0xa, 
       0x67, 0xd, 0x67, 0xe, 0x67, 0x8b6, 0x3, 0x67, 0x6, 0x67, 0x8ba, 0xa, 
       0x67, 0xd, 0x67, 0xe, 0x67, 0x8bb, 0x5, 0x67, 0x8be, 0xa, 0x67, 0x3, 
       0x67, 0x3, 0x67, 0x5, 0x67, 0x8c2, 0xa, 0x67, 0x3, 0x68, 0x3, 0x68, 
       0x3, 0x68, 0x5, 0x68, 0x8c7, 0xa, 0x68, 0x3, 0x68, 0x3, 0x68, 0x3, 
       0x68, 0x5, 0x68, 0x8cc, 0xa, 0x68, 0x5, 0x68, 0x8ce, 0xa, 0x68, 0x3, 
       0x69, 0x6, 0x69, 0x8d1, 0xa, 0x69, 0xd, 0x69, 0xe, 0x69, 0x8d2, 0x3, 
       0x69, 0x3, 0x69, 0x6, 0x69, 0x8d7, 0xa, 0x69, 0xd, 0x69, 0xe, 0x69, 
       0x8d8, 0x3, 0x69, 0x3, 0x69, 0x5, 0x69, 0x8dd, 0xa, 0x69, 0x3, 0x6a, 
       0x3, 0x6a, 0x3, 0x6a, 0x5, 0x6a, 0x8e2, 0xa, 0x6a, 0x3, 0x6b, 0x3, 
       0x6b, 0x3, 0x6b, 0x3, 0x6b, 0x3, 0x6c, 0x3, 0x6c, 0x3, 0x6c, 0x3, 
       0x6c, 0x3, 0x6d, 0x3, 0x6d, 0x3, 0x6d, 0x3, 0x6d, 0x3, 0x6e, 0x3, 
       0x6e, 0x3, 0x6e, 0x5, 0x6e, 0x8f3, 0xa, 0x6e, 0x3, 0x6f, 0x3, 0x6f, 
       0x3, 0x6f, 0x3, 0x6f, 0x3, 0x6f, 0x3, 0x6f, 0x5, 0x6f, 0x8fb, 0xa, 
       0x6f, 0x3, 0x6f, 0x3, 0x6f, 0x3, 0x6f, 0x3, 0x6f, 0x3, 0x6f, 0x3, 
       0x6f, 0x3, 0x6f, 0x3, 0x6f, 0x3, 0x6f, 0x5, 0x6f, 0x906, 0xa, 0x6f, 
       0x7, 0x6f, 0x908, 0xa, 0x6f, 0xc, 0x6f, 0xe, 0x6f, 0x90b, 0xb, 0x6f, 
       0x3, 0x70, 0x3, 0x70, 0x3, 0x70, 0x3, 0x71, 0x3, 0x71, 0x3, 0x71, 
       0x3, 0x71, 0x5, 0x71, 0x914, 0xa, 0x71, 0x6, 0x71, 0x916, 0xa, 0x71, 
       0xd, 0x71, 0xe, 0x71, 0x917, 0x3, 0x71, 0x3, 0x71, 0x3, 0x72, 0x3, 
       0x72, 0x3, 0x72, 0x3, 0x72, 0x3, 0x73, 0x3, 0x73, 0x3, 0x73, 0x5, 
       0x73, 0x923, 0xa, 0x73, 0x6, 0x73, 0x925, 0xa, 0x73, 0xd, 0x73, 0xe, 
       0x73, 0x926, 0x3, 0x73, 0x3, 0x73, 0x3, 0x74, 0x3, 0x74, 0x3, 0x75, 
       0x3, 0x75, 0x3, 0x75, 0x3, 0x75, 0x3, 0x75, 0x3, 0x75, 0x3, 0x75, 
       0x5, 0x75, 0x934, 0xa, 0x75, 0x3, 0x76, 0x6, 0x76, 0x937, 0xa, 0x76, 
       0xd, 0x76, 0xe, 0x76, 0x938, 0x3, 0x77, 0x3, 0x77, 0x3, 0x77, 0x3, 
       0x77, 0x3, 0x77, 0x3, 0x77, 0x3, 0x77, 0x3, 0x77, 0x3, 0x77, 0x3, 
       0x77, 0x3, 0x77, 0x3, 0x77, 0x3, 0x77, 0x5, 0x77, 0x948, 0xa, 0x77, 
       0x3, 0x78, 0x3, 0x78, 0x7, 0x78, 0x94c, 0xa, 0x78, 0xc, 0x78, 0xe, 
       0x78, 0x94f, 0xb, 0x78, 0x3, 0x78, 0x3, 0x78, 0x3, 0x79, 0x3, 0x79, 
       0x3, 0x79, 0x3, 0x79, 0x3, 0x79, 0x3, 0x79, 0x3, 0x79, 0x5, 0x79, 
       0x95a, 0xa, 0x79, 0x3, 0x7a, 0x3, 0x7a, 0x3, 0x7a, 0x3, 0x7a, 0x3, 
       0x7a, 0x3, 0x7a, 0x3, 0x7a, 0x3, 0x7a, 0x5, 0x7a, 0x964, 0xa, 0x7a, 
       0x3, 0x7b, 0x3, 0x7b, 0x3, 0x7b, 0x7, 0x7b, 0x969, 0xa, 0x7b, 0xc, 
       0x7b, 0xe, 0x7b, 0x96c, 0xb, 0x7b, 0x3, 0x7c, 0x3, 0x7c, 0x3, 0x7c, 
       0x3, 0x7d, 0x5, 0x7d, 0x972, 0xa, 0x7d, 0x3, 0x7d, 0x3, 0x7d, 0x3, 
       0x7d, 0x3, 0x7d, 0x5, 0x7d, 0x978, 0xa, 0x7d, 0x3, 0x7d, 0x3, 0x7d, 
       0x3, 0x7e, 0x3, 0x7e, 0x3, 0x7e, 0x3, 0x7e, 0x3, 0x7f, 0x3, 0x7f, 
       0x3, 0x7f, 0x3, 0x7f, 0x3, 0x7f, 0x3, 0x7f, 0x3, 0x7f, 0x3, 0x7f, 
       0x5, 0x7f, 0x988, 0xa, 0x7f, 0x3, 0x80, 0x3, 0x80, 0x3, 0x81, 0x3, 
       0x81, 0x3, 0x82, 0x3, 0x82, 0x3, 0x82, 0x3, 0x82, 0x3, 0x82, 0x3, 
       0x82, 0x3, 0x82, 0x3, 0x82, 0x3, 0x82, 0x3, 0x82, 0x3, 0x82, 0x3, 
       0x82, 0x3, 0x82, 0x3, 0x82, 0x3, 0x82, 0x3, 0x82, 0x5, 0x82, 0x99e, 
       0xa, 0x82, 0x3, 0x83, 0x3, 0x83, 0x3, 0x84, 0x3, 0x84, 0x3, 0x85, 
       0x3, 0x85, 0x3, 0x85, 0x2, 0x3, 0xdc, 0x86, 0x2, 0x4, 0x6, 0x8, 0xa, 
       0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 
       0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 
       0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 
       0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 
       0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 
       0x7c, 0x7e, 0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c, 0x8e, 0x90, 
       0x92, 0x94, 0x96, 0x98, 0x9a, 0x9c, 0x9e, 0xa0, 0xa2, 0xa4, 0xa6, 
       0xa8, 0xaa, 0xac, 0xae, 0xb0, 0xb2, 0xb4, 0xb6, 0xb8, 0xba, 0xbc, 
       0xbe, 0xc0, 0xc2, 0xc4, 0xc6, 0xc8, 0xca, 0xcc, 0xce, 0xd0, 0xd2, 
       0xd4, 0xd6, 0xd8, 0xda, 0xdc, 0xde, 0xe0, 0xe2, 0xe4, 0xe6, 0xe8, 
       0xea, 0xec, 0xee, 0xf0, 0xf2, 0xf4, 0xf6, 0xf8, 0xfa, 0xfc, 0xfe, 
       0x100, 0x102, 0x104, 0x106, 0x108, 0x2, 0xe, 0x3, 0x2, 0xd, 0xe, 
       0x3, 0x2, 0x20, 0x25, 0x4, 0x2, 0x35, 0x35, 0x37, 0x37, 0x3, 0x2, 
       0xd8, 0xd9, 0x3, 0x2, 0xbe, 0xbf, 0x5, 0x2, 0xc1, 0xc1, 0xc5, 0xc5, 
       0xd1, 0xd1, 0x5, 0x2, 0xc2, 0xc2, 0xc6, 0xc6, 0xd1, 0xd1, 0x6, 0x2, 
       0xab, 0xb9, 0xbe, 0xc0, 0xd0, 0xd0, 0xd4, 0xd5, 0x8, 0x2, 0xb, 0xb, 
       0x13, 0x13, 0x1f, 0x1f, 0x37, 0x37, 0x65, 0x65, 0xd9, 0xd9, 0x3, 
       0x2, 0x14, 0x34, 0x3, 0x2, 0x35, 0x4f, 0x3, 0x2, 0x50, 0xa9, 0x2, 
       0xb33, 0x2, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x4, 0x127, 0x3, 0x2, 0x2, 
       0x2, 0x6, 0x140, 0x3, 0x2, 0x2, 0x2, 0x8, 0x145, 0x3, 0x2, 0x2, 0x2, 
       0xa, 0x147, 0x3, 0x2, 0x2, 0x2, 0xc, 0x155, 0x3, 0x2, 0x2, 0x2, 0xe, 
       0x160, 0x3, 0x2, 0x2, 0x2, 0x10, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x12, 
       0x180, 0x3, 0x2, 0x2, 0x2, 0x14, 0x188, 0x3, 0x2, 0x2, 0x2, 0x16, 
       0x193, 0x3, 0x2, 0x2, 0x2, 0x18, 0x195, 0x3, 0x2, 0x2, 0x2, 0x1a, 
       0x1a2, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1aa, 0x3, 0x2, 0x2, 0x2, 0x1e, 
       0x1b5, 0x3, 0x2, 0x2, 0x2, 0x20, 0x1b7, 0x3, 0x2, 0x2, 0x2, 0x22, 
       0x1dd, 0x3, 0x2, 0x2, 0x2, 0x24, 0x1df, 0x3, 0x2, 0x2, 0x2, 0x26, 
       0x1e7, 0x3, 0x2, 0x2, 0x2, 0x28, 0x1f1, 0x3, 0x2, 0x2, 0x2, 0x2a, 
       0x1f3, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x200, 0x3, 0x2, 0x2, 0x2, 0x2e, 
       0x206, 0x3, 0x2, 0x2, 0x2, 0x30, 0x216, 0x3, 0x2, 0x2, 0x2, 0x32, 
       0x24f, 0x3, 0x2, 0x2, 0x2, 0x34, 0x26e, 0x3, 0x2, 0x2, 0x2, 0x36, 
       0x293, 0x3, 0x2, 0x2, 0x2, 0x38, 0x2b2, 0x3, 0x2, 0x2, 0x2, 0x3a, 
       0x2d7, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x2fc, 0x3, 0x2, 0x2, 0x2, 0x3e, 
       0x31b, 0x3, 0x2, 0x2, 0x2, 0x40, 0x33a, 0x3, 0x2, 0x2, 0x2, 0x42, 
       0x33c, 0x3, 0x2, 0x2, 0x2, 0x44, 0x345, 0x3, 0x2, 0x2, 0x2, 0x46, 
       0x35e, 0x3, 0x2, 0x2, 0x2, 0x48, 0x360, 0x3, 0x2, 0x2, 0x2, 0x4a, 
       0x387, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x3a6, 0x3, 0x2, 0x2, 0x2, 0x4e, 
       0x3cb, 0x3, 0x2, 0x2, 0x2, 0x50, 0x3f0, 0x3, 0x2, 0x2, 0x2, 0x52, 
       0x415, 0x3, 0x2, 0x2, 0x2, 0x54, 0x43a, 0x3, 0x2, 0x2, 0x2, 0x56, 
       0x459, 0x3, 0x2, 0x2, 0x2, 0x58, 0x47e, 0x3, 0x2, 0x2, 0x2, 0x5a, 
       0x4a3, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x4c8, 0x3, 0x2, 0x2, 0x2, 0x5e, 
       0x4e7, 0x3, 0x2, 0x2, 0x2, 0x60, 0x50c, 0x3, 0x2, 0x2, 0x2, 0x62, 
       0x52b, 0x3, 0x2, 0x2, 0x2, 0x64, 0x550, 0x3, 0x2, 0x2, 0x2, 0x66, 
       0x575, 0x3, 0x2, 0x2, 0x2, 0x68, 0x577, 0x3, 0x2, 0x2, 0x2, 0x6a, 
       0x58c, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x594, 0x3, 0x2, 0x2, 0x2, 0x6e, 
       0x59c, 0x3, 0x2, 0x2, 0x2, 0x70, 0x5a4, 0x3, 0x2, 0x2, 0x2, 0x72, 
       0x5ad, 0x3, 0x2, 0x2, 0x2, 0x74, 0x5c5, 0x3, 0x2, 0x2, 0x2, 0x76, 
       0x5c7, 0x3, 0x2, 0x2, 0x2, 0x78, 0x5d2, 0x3, 0x2, 0x2, 0x2, 0x7a, 
       0x5fb, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x616, 0x3, 0x2, 0x2, 0x2, 0x7e, 
       0x618, 0x3, 0x2, 0x2, 0x2, 0x80, 0x623, 0x3, 0x2, 0x2, 0x2, 0x82, 
       0x635, 0x3, 0x2, 0x2, 0x2, 0x84, 0x639, 0x3, 0x2, 0x2, 0x2, 0x86, 
       0x646, 0x3, 0x2, 0x2, 0x2, 0x88, 0x65f, 0x3, 0x2, 0x2, 0x2, 0x8a, 
       0x661, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x66a, 0x3, 0x2, 0x2, 0x2, 0x8e, 
       0x67c, 0x3, 0x2, 0x2, 0x2, 0x90, 0x67e, 0x3, 0x2, 0x2, 0x2, 0x92, 
       0x6a1, 0x3, 0x2, 0x2, 0x2, 0x94, 0x6a3, 0x3, 0x2, 0x2, 0x2, 0x96, 
       0x6c6, 0x3, 0x2, 0x2, 0x2, 0x98, 0x6df, 0x3, 0x2, 0x2, 0x2, 0x9a, 
       0x6f8, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x711, 0x3, 0x2, 0x2, 0x2, 0x9e, 
       0x72a, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x72c, 0x3, 0x2, 0x2, 0x2, 0xa2, 
       0x750, 0x3, 0x2, 0x2, 0x2, 0xa4, 0x752, 0x3, 0x2, 0x2, 0x2, 0xa6, 
       0x75a, 0x3, 0x2, 0x2, 0x2, 0xa8, 0x76d, 0x3, 0x2, 0x2, 0x2, 0xaa, 
       0x76f, 0x3, 0x2, 0x2, 0x2, 0xac, 0x779, 0x3, 0x2, 0x2, 0x2, 0xae, 
       0x796, 0x3, 0x2, 0x2, 0x2, 0xb0, 0x7df, 0x3, 0x2, 0x2, 0x2, 0xb2, 
       0x7e1, 0x3, 0x2, 0x2, 0x2, 0xb4, 0x803, 0x3, 0x2, 0x2, 0x2, 0xb6, 
       0x805, 0x3, 0x2, 0x2, 0x2, 0xb8, 0x80d, 0x3, 0x2, 0x2, 0x2, 0xba, 
       0x821, 0x3, 0x2, 0x2, 0x2, 0xbc, 0x823, 0x3, 0x2, 0x2, 0x2, 0xbe, 
       0x82d, 0x3, 0x2, 0x2, 0x2, 0xc0, 0x858, 0x3, 0x2, 0x2, 0x2, 0xc2, 
       0x85a, 0x3, 0x2, 0x2, 0x2, 0xc4, 0x870, 0x3, 0x2, 0x2, 0x2, 0xc6, 
       0x874, 0x3, 0x2, 0x2, 0x2, 0xc8, 0x87a, 0x3, 0x2, 0x2, 0x2, 0xca, 
       0x87f, 0x3, 0x2, 0x2, 0x2, 0xcc, 0x8c1, 0x3, 0x2, 0x2, 0x2, 0xce, 
       0x8cd, 0x3, 0x2, 0x2, 0x2, 0xd0, 0x8dc, 0x3, 0x2, 0x2, 0x2, 0xd2, 
       0x8e1, 0x3, 0x2, 0x2, 0x2, 0xd4, 0x8e3, 0x3, 0x2, 0x2, 0x2, 0xd6, 
       0x8e7, 0x3, 0x2, 0x2, 0x2, 0xd8, 0x8eb, 0x3, 0x2, 0x2, 0x2, 0xda, 
       0x8ef, 0x3, 0x2, 0x2, 0x2, 0xdc, 0x8fa, 0x3, 0x2, 0x2, 0x2, 0xde, 
       0x90c, 0x3, 0x2, 0x2, 0x2, 0xe0, 0x90f, 0x3, 0x2, 0x2, 0x2, 0xe2, 
       0x91b, 0x3, 0x2, 0x2, 0x2, 0xe4, 0x91f, 0x3, 0x2, 0x2, 0x2, 0xe6, 
       0x92a, 0x3, 0x2, 0x2, 0x2, 0xe8, 0x933, 0x3, 0x2, 0x2, 0x2, 0xea, 
       0x936, 0x3, 0x2, 0x2, 0x2, 0xec, 0x947, 0x3, 0x2, 0x2, 0x2, 0xee, 
       0x949, 0x3, 0x2, 0x2, 0x2, 0xf0, 0x959, 0x3, 0x2, 0x2, 0x2, 0xf2, 
       0x963, 0x3, 0x2, 0x2, 0x2, 0xf4, 0x965, 0x3, 0x2, 0x2, 0x2, 0xf6, 
       0x96d, 0x3, 0x2, 0x2, 0x2, 0xf8, 0x971, 0x3, 0x2, 0x2, 0x2, 0xfa, 
       0x97b, 0x3, 0x2, 0x2, 0x2, 0xfc, 0x987, 0x3, 0x2, 0x2, 0x2, 0xfe, 
       0x989, 0x3, 0x2, 0x2, 0x2, 0x100, 0x98b, 0x3, 0x2, 0x2, 0x2, 0x102, 
       0x99d, 0x3, 0x2, 0x2, 0x2, 0x104, 0x99f, 0x3, 0x2, 0x2, 0x2, 0x106, 
       0x9a1, 0x3, 0x2, 0x2, 0x2, 0x108, 0x9a3, 0x3, 0x2, 0x2, 0x2, 0x10a, 
       0x10c, 0x7, 0xde, 0x2, 0x2, 0x10b, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x10c, 
       0x10f, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x10d, 
       0x10e, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x116, 0x3, 0x2, 0x2, 0x2, 0x10f, 
       0x10d, 0x3, 0x2, 0x2, 0x2, 0x110, 0x112, 0x5, 0x10, 0x9, 0x2, 0x111, 
       0x113, 0x7, 0xde, 0x2, 0x2, 0x112, 0x111, 0x3, 0x2, 0x2, 0x2, 0x113, 
       0x114, 0x3, 0x2, 0x2, 0x2, 0x114, 0x112, 0x3, 0x2, 0x2, 0x2, 0x114, 
       0x115, 0x3, 0x2, 0x2, 0x2, 0x115, 0x117, 0x3, 0x2, 0x2, 0x2, 0x116, 
       0x110, 0x3, 0x2, 0x2, 0x2, 0x116, 0x117, 0x3, 0x2, 0x2, 0x2, 0x117, 
       0x121, 0x3, 0x2, 0x2, 0x2, 0x118, 0x11c, 0x5, 0x6, 0x4, 0x2, 0x119, 
       0x11b, 0x7, 0xde, 0x2, 0x2, 0x11a, 0x119, 0x3, 0x2, 0x2, 0x2, 0x11b, 
       0x11e, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x11c, 
       0x11d, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x120, 0x3, 0x2, 0x2, 0x2, 0x11e, 
       0x11c, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x118, 0x3, 0x2, 0x2, 0x2, 0x120, 
       0x123, 0x3, 0x2, 0x2, 0x2, 0x121, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x121, 
       0x122, 0x3, 0x2, 0x2, 0x2, 0x122, 0x124, 0x3, 0x2, 0x2, 0x2, 0x123, 
       0x121, 0x3, 0x2, 0x2, 0x2, 0x124, 0x125, 0x7, 0x2, 0x2, 0x3, 0x125, 
       0x3, 0x3, 0x2, 0x2, 0x2, 0x126, 0x128, 0x7, 0xd9, 0x2, 0x2, 0x127, 
       0x126, 0x3, 0x2, 0x2, 0x2, 0x128, 0x129, 0x3, 0x2, 0x2, 0x2, 0x129, 
       0x127, 0x3, 0x2, 0x2, 0x2, 0x129, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x12a, 
       0x132, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12d, 0x7, 0xde, 0x2, 0x2, 0x12c, 
       0x12b, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x130, 0x3, 0x2, 0x2, 0x2, 0x12e, 
       0x12c, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x12f, 
       0x133, 0x3, 0x2, 0x2, 0x2, 0x130, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x131, 
       0x133, 0x7, 0x2, 0x2, 0x3, 0x132, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x132, 
       0x131, 0x3, 0x2, 0x2, 0x2, 0x133, 0x5, 0x3, 0x2, 0x2, 0x2, 0x134, 
       0x141, 0x5, 0x8, 0x5, 0x2, 0x135, 0x141, 0x5, 0x12, 0xa, 0x2, 0x136, 
       0x141, 0x5, 0x24, 0x13, 0x2, 0x137, 0x141, 0x5, 0x32, 0x1a, 0x2, 
       0x138, 0x141, 0x5, 0x7e, 0x40, 0x2, 0x139, 0x141, 0x5, 0x80, 0x41, 
       0x2, 0x13a, 0x141, 0x5, 0xc0, 0x61, 0x2, 0x13b, 0x141, 0x5, 0x86, 
       0x44, 0x2, 0x13c, 0x141, 0x5, 0xc2, 0x62, 0x2, 0x13d, 0x141, 0x5, 
       0x1a, 0xe, 0x2, 0x13e, 0x141, 0x5, 0x22, 0x12, 0x2, 0x13f, 0x141, 
       0x5, 0xa4, 0x53, 0x2, 0x140, 0x134, 0x3, 0x2, 0x2, 0x2, 0x140, 0x135, 
       0x3, 0x2, 0x2, 0x2, 0x140, 0x136, 0x3, 0x2, 0x2, 0x2, 0x140, 0x137, 
       0x3, 0x2, 0x2, 0x2, 0x140, 0x138, 0x3, 0x2, 0x2, 0x2, 0x140, 0x139, 
       0x3, 0x2, 0x2, 0x2, 0x140, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x140, 0x13b, 
       0x3, 0x2, 0x2, 0x2, 0x140, 0x13c, 0x3, 0x2, 0x2, 0x2, 0x140, 0x13d, 
       0x3, 0x2, 0x2, 0x2, 0x140, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x140, 0x13f, 
       0x3, 0x2, 0x2, 0x2, 0x141, 0x7, 0x3, 0x2, 0x2, 0x2, 0x142, 0x146, 
       0x5, 0xa, 0x6, 0x2, 0x143, 0x146, 0x5, 0xc, 0x7, 0x2, 0x144, 0x146, 
       0x5, 0xe, 0x8, 0x2, 0x145, 0x142, 0x3, 0x2, 0x2, 0x2, 0x145, 0x143, 
       0x3, 0x2, 0x2, 0x2, 0x145, 0x144, 0x3, 0x2, 0x2, 0x2, 0x146, 0x9, 
       0x3, 0x2, 0x2, 0x2, 0x147, 0x148, 0x7, 0x6, 0x2, 0x2, 0x148, 0x14a, 
       0x5, 0x100, 0x81, 0x2, 0x149, 0x14b, 0x5, 0xf2, 0x7a, 0x2, 0x14a, 
       0x149, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x14b, 
       0x153, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x14e, 0x7, 0xde, 0x2, 0x2, 0x14d, 
       0x14c, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x151, 0x3, 0x2, 0x2, 0x2, 0x14f, 
       0x14d, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x150, 0x3, 0x2, 0x2, 0x2, 0x150, 
       0x154, 0x3, 0x2, 0x2, 0x2, 0x151, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x152, 
       0x154, 0x7, 0x2, 0x2, 0x3, 0x153, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x153, 
       0x152, 0x3, 0x2, 0x2, 0x2, 0x154, 0xb, 0x3, 0x2, 0x2, 0x2, 0x155, 
       0x156, 0x7, 0x7, 0x2, 0x2, 0x156, 0x15e, 0x5, 0x100, 0x81, 0x2, 0x157, 
       0x159, 0x7, 0xde, 0x2, 0x2, 0x158, 0x157, 0x3, 0x2, 0x2, 0x2, 0x159, 
       0x15c, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x158, 0x3, 0x2, 0x2, 0x2, 0x15a, 
       0x15b, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x15c, 
       0x15a, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x15f, 0x7, 0x2, 0x2, 0x3, 0x15e, 
       0x15a, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x15f, 
       0xd, 0x3, 0x2, 0x2, 0x2, 0x160, 0x161, 0x7, 0x8, 0x2, 0x2, 0x161, 
       0x163, 0x5, 0x100, 0x81, 0x2, 0x162, 0x164, 0x7, 0xbf, 0x2, 0x2, 
       0x163, 0x162, 0x3, 0x2, 0x2, 0x2, 0x163, 0x164, 0x3, 0x2, 0x2, 0x2, 
       0x164, 0x166, 0x3, 0x2, 0x2, 0x2, 0x165, 0x167, 0x7, 0xd9, 0x2, 0x2, 
       0x166, 0x165, 0x3, 0x2, 0x2, 0x2, 0x166, 0x167, 0x3, 0x2, 0x2, 0x2, 
       0x167, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x168, 0x16a, 0x7, 0xde, 0x2, 0x2, 
       0x169, 0x168, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x16d, 0x3, 0x2, 0x2, 0x2, 
       0x16b, 0x169, 0x3, 0x2, 0x2, 0x2, 0x16b, 0x16c, 0x3, 0x2, 0x2, 0x2, 
       0x16c, 0x170, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x16b, 0x3, 0x2, 0x2, 0x2, 
       0x16e, 0x170, 0x7, 0x2, 0x2, 0x3, 0x16f, 0x16b, 0x3, 0x2, 0x2, 0x2, 
       0x16f, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x170, 0xf, 0x3, 0x2, 0x2, 0x2, 
       0x171, 0x172, 0x7, 0x10, 0x2, 0x2, 0x172, 0x173, 0x7, 0x1e, 0x2, 
       0x2, 0x173, 0x174, 0x7, 0xaa, 0x2, 0x2, 0x174, 0x17f, 0x7, 0x2d, 
       0x2, 0x2, 0x175, 0x176, 0x7, 0x10, 0x2, 0x2, 0x176, 0x177, 0x7, 0x1e, 
       0x2, 0x2, 0x177, 0x178, 0x7, 0xaa, 0x2, 0x2, 0x178, 0x17c, 0x7, 0x2c, 
       0x2, 0x2, 0x179, 0x17a, 0x7, 0x26, 0x2, 0x2, 0x17a, 0x17b, 0x7, 0xaa, 
       0x2, 0x2, 0x17b, 0x17d, 0x7, 0xd9, 0x2, 0x2, 0x17c, 0x179, 0x3, 0x2, 
       0x2, 0x2, 0x17c, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x17d, 0x17f, 0x3, 0x2, 
       0x2, 0x2, 0x17e, 0x171, 0x3, 0x2, 0x2, 0x2, 0x17e, 0x175, 0x3, 0x2, 
       0x2, 0x2, 0x17f, 0x11, 0x3, 0x2, 0x2, 0x2, 0x180, 0x182, 0x5, 0x14, 
       0xb, 0x2, 0x181, 0x183, 0x5, 0x16, 0xc, 0x2, 0x182, 0x181, 0x3, 0x2, 
       0x2, 0x2, 0x183, 0x184, 0x3, 0x2, 0x2, 0x2, 0x184, 0x182, 0x3, 0x2, 
       0x2, 0x2, 0x184, 0x185, 0x3, 0x2, 0x2, 0x2, 0x185, 0x186, 0x3, 0x2, 
       0x2, 0x2, 0x186, 0x187, 0x5, 0x18, 0xd, 0x2, 0x187, 0x13, 0x3, 0x2, 
       0x2, 0x2, 0x188, 0x189, 0x7, 0x9, 0x2, 0x2, 0x189, 0x191, 0x7, 0xd9, 
       0x2, 0x2, 0x18a, 0x18c, 0x7, 0xde, 0x2, 0x2, 0x18b, 0x18a, 0x3, 0x2, 
       0x2, 0x2, 0x18c, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x18d, 0x18b, 0x3, 0x2, 
       0x2, 0x2, 0x18d, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x18e, 0x192, 0x3, 0x2, 
       0x2, 0x2, 0x18f, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x190, 0x192, 0x7, 0x2, 
       0x2, 0x3, 0x191, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x191, 0x190, 0x3, 0x2, 
       0x2, 0x2, 0x192, 0x15, 0x3, 0x2, 0x2, 0x2, 0x193, 0x194, 0x5, 0x6, 
       0x4, 0x2, 0x194, 0x17, 0x3, 0x2, 0x2, 0x2, 0x195, 0x197, 0x7, 0xa, 
       0x2, 0x2, 0x196, 0x198, 0x7, 0xd9, 0x2, 0x2, 0x197, 0x196, 0x3, 0x2, 
       0x2, 0x2, 0x197, 0x198, 0x3, 0x2, 0x2, 0x2, 0x198, 0x1a0, 0x3, 0x2, 
       0x2, 0x2, 0x199, 0x19b, 0x7, 0xde, 0x2, 0x2, 0x19a, 0x199, 0x3, 0x2, 
       0x2, 0x2, 0x19b, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x19c, 0x19a, 0x3, 0x2, 
       0x2, 0x2, 0x19c, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x1a1, 0x3, 0x2, 
       0x2, 0x2, 0x19e, 0x19c, 0x3, 0x2, 0x2, 0x2, 0x19f, 0x1a1, 0x7, 0x2, 
       0x2, 0x3, 0x1a0, 0x19c, 0x3, 0x2, 0x2, 0x2, 0x1a0, 0x19f, 0x3, 0x2, 
       0x2, 0x2, 0x1a1, 0x19, 0x3, 0x2, 0x2, 0x2, 0x1a2, 0x1a4, 0x5, 0x1c, 
       0xf, 0x2, 0x1a3, 0x1a5, 0x5, 0x1e, 0x10, 0x2, 0x1a4, 0x1a3, 0x3, 
       0x2, 0x2, 0x2, 0x1a5, 0x1a6, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a4, 0x3, 
       0x2, 0x2, 0x2, 0x1a6, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1a8, 0x3, 
       0x2, 0x2, 0x2, 0x1a8, 0x1a9, 0x5, 0x20, 0x11, 0x2, 0x1a9, 0x1b, 0x3, 
       0x2, 0x2, 0x2, 0x1aa, 0x1ab, 0x7, 0xb, 0x2, 0x2, 0x1ab, 0x1b3, 0x7, 
       0xd9, 0x2, 0x2, 0x1ac, 0x1ae, 0x7, 0xde, 0x2, 0x2, 0x1ad, 0x1ac, 
       0x3, 0x2, 0x2, 0x2, 0x1ae, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1af, 0x1ad, 
       0x3, 0x2, 0x2, 0x2, 0x1af, 0x1b0, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x1b4, 
       0x3, 0x2, 0x2, 0x2, 0x1b1, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x1b2, 0x1b4, 
       0x7, 0x2, 0x2, 0x3, 0x1b3, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x1b3, 0x1b2, 
       0x3, 0x2, 0x2, 0x2, 0x1b4, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1b6, 
       0x5, 0x6, 0x4, 0x2, 0x1b6, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x1b7, 0x1b9, 
       0x7, 0xc, 0x2, 0x2, 0x1b8, 0x1ba, 0x7, 0xd9, 0x2, 0x2, 0x1b9, 0x1b8, 
       0x3, 0x2, 0x2, 0x2, 0x1b9, 0x1ba, 0x3, 0x2, 0x2, 0x2, 0x1ba, 0x1c2, 
       0x3, 0x2, 0x2, 0x2, 0x1bb, 0x1bd, 0x7, 0xde, 0x2, 0x2, 0x1bc, 0x1bb, 
       0x3, 0x2, 0x2, 0x2, 0x1bd, 0x1c0, 0x3, 0x2, 0x2, 0x2, 0x1be, 0x1bc, 
       0x3, 0x2, 0x2, 0x2, 0x1be, 0x1bf, 0x3, 0x2, 0x2, 0x2, 0x1bf, 0x1c3, 
       0x3, 0x2, 0x2, 0x2, 0x1c0, 0x1be, 0x3, 0x2, 0x2, 0x2, 0x1c1, 0x1c3, 
       0x7, 0x2, 0x2, 0x3, 0x1c2, 0x1be, 0x3, 0x2, 0x2, 0x2, 0x1c2, 0x1c1, 
       0x3, 0x2, 0x2, 0x2, 0x1c3, 0x21, 0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1c5, 
       0x7, 0xd9, 0x2, 0x2, 0x1c5, 0x1c6, 0x5, 0xd0, 0x69, 0x2, 0x1c6, 0x1c7, 
       0x7, 0x2a, 0x2, 0x2, 0x1c7, 0x1cf, 0x5, 0xea, 0x76, 0x2, 0x1c8, 0x1ca, 
       0x7, 0xde, 0x2, 0x2, 0x1c9, 0x1c8, 0x3, 0x2, 0x2, 0x2, 0x1ca, 0x1cd, 
       0x3, 0x2, 0x2, 0x2, 0x1cb, 0x1c9, 0x3, 0x2, 0x2, 0x2, 0x1cb, 0x1cc, 
       0x3, 0x2, 0x2, 0x2, 0x1cc, 0x1d0, 0x3, 0x2, 0x2, 0x2, 0x1cd, 0x1cb, 
       0x3, 0x2, 0x2, 0x2, 0x1ce, 0x1d0, 0x7, 0x2, 0x2, 0x3, 0x1cf, 0x1cb, 
       0x3, 0x2, 0x2, 0x2, 0x1cf, 0x1ce, 0x3, 0x2, 0x2, 0x2, 0x1d0, 0x1de, 
       0x3, 0x2, 0x2, 0x2, 0x1d1, 0x1d2, 0x7, 0xd9, 0x2, 0x2, 0x1d2, 0x1d3, 
       0x5, 0xd0, 0x69, 0x2, 0x1d3, 0x1db, 0x7, 0x2a, 0x2, 0x2, 0x1d4, 0x1d6, 
       0x7, 0xde, 0x2, 0x2, 0x1d5, 0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1d6, 0x1d9, 
       0x3, 0x2, 0x2, 0x2, 0x1d7, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1d7, 0x1d8, 
       0x3, 0x2, 0x2, 0x2, 0x1d8, 0x1dc, 0x3, 0x2, 0x2, 0x2, 0x1d9, 0x1d7, 
       0x3, 0x2, 0x2, 0x2, 0x1da, 0x1dc, 0x7, 0x2, 0x2, 0x3, 0x1db, 0x1d7, 
       0x3, 0x2, 0x2, 0x2, 0x1db, 0x1da, 0x3, 0x2, 0x2, 0x2, 0x1dc, 0x1de, 
       0x3, 0x2, 0x2, 0x2, 0x1dd, 0x1c4, 0x3, 0x2, 0x2, 0x2, 0x1dd, 0x1d1, 
       0x3, 0x2, 0x2, 0x2, 0x1de, 0x23, 0x3, 0x2, 0x2, 0x2, 0x1df, 0x1e1, 
       0x5, 0x26, 0x14, 0x2, 0x1e0, 0x1e2, 0x5, 0x28, 0x15, 0x2, 0x1e1, 
       0x1e0, 0x3, 0x2, 0x2, 0x2, 0x1e2, 0x1e3, 0x3, 0x2, 0x2, 0x2, 0x1e3, 
       0x1e1, 0x3, 0x2, 0x2, 0x2, 0x1e3, 0x1e4, 0x3, 0x2, 0x2, 0x2, 0x1e4, 
       0x1e5, 0x3, 0x2, 0x2, 0x2, 0x1e5, 0x1e6, 0x5, 0x2a, 0x16, 0x2, 0x1e6, 
       0x25, 0x3, 0x2, 0x2, 0x2, 0x1e7, 0x1e8, 0x9, 0x2, 0x2, 0x2, 0x1e8, 
       0x1ea, 0x7, 0xd9, 0x2, 0x2, 0x1e9, 0x1eb, 0x5, 0xd0, 0x69, 0x2, 0x1ea, 
       0x1e9, 0x3, 0x2, 0x2, 0x2, 0x1ea, 0x1eb, 0x3, 0x2, 0x2, 0x2, 0x1eb, 
       0x1ed, 0x3, 0x2, 0x2, 0x2, 0x1ec, 0x1ee, 0x7, 0xde, 0x2, 0x2, 0x1ed, 
       0x1ec, 0x3, 0x2, 0x2, 0x2, 0x1ee, 0x1ef, 0x3, 0x2, 0x2, 0x2, 0x1ef, 
       0x1ed, 0x3, 0x2, 0x2, 0x2, 0x1ef, 0x1f0, 0x3, 0x2, 0x2, 0x2, 0x1f0, 
       0x27, 0x3, 0x2, 0x2, 0x2, 0x1f1, 0x1f2, 0x5, 0x6, 0x4, 0x2, 0x1f2, 
       0x29, 0x3, 0x2, 0x2, 0x2, 0x1f3, 0x1f5, 0x7, 0xf, 0x2, 0x2, 0x1f4, 
       0x1f6, 0x7, 0xd9, 0x2, 0x2, 0x1f5, 0x1f4, 0x3, 0x2, 0x2, 0x2, 0x1f5, 
       0x1f6, 0x3, 0x2, 0x2, 0x2, 0x1f6, 0x1fe, 0x3, 0x2, 0x2, 0x2, 0x1f7, 
       0x1f9, 0x7, 0xde, 0x2, 0x2, 0x1f8, 0x1f7, 0x3, 0x2, 0x2, 0x2, 0x1f9, 
       0x1fc, 0x3, 0x2, 0x2, 0x2, 0x1fa, 0x1f8, 0x3, 0x2, 0x2, 0x2, 0x1fa, 
       0x1fb, 0x3, 0x2, 0x2, 0x2, 0x1fb, 0x1ff, 0x3, 0x2, 0x2, 0x2, 0x1fc, 
       0x1fa, 0x3, 0x2, 0x2, 0x2, 0x1fd, 0x1ff, 0x7, 0x2, 0x2, 0x3, 0x1fe, 
       0x1fa, 0x3, 0x2, 0x2, 0x2, 0x1fe, 0x1fd, 0x3, 0x2, 0x2, 0x2, 0x1ff, 
       0x2b, 0x3, 0x2, 0x2, 0x2, 0x200, 0x201, 0x7, 0x27, 0x2, 0x2, 0x201, 
       0x202, 0x5, 0xdc, 0x6f, 0x2, 0x202, 0x204, 0x5, 0x30, 0x19, 0x2, 
       0x203, 0x205, 0x5, 0x2e, 0x18, 0x2, 0x204, 0x203, 0x3, 0x2, 0x2, 
       0x2, 0x204, 0x205, 0x3, 0x2, 0x2, 0x2, 0x205, 0x2d, 0x3, 0x2, 0x2, 
       0x2, 0x206, 0x207, 0x7, 0x28, 0x2, 0x2, 0x207, 0x208, 0x5, 0x30, 
       0x19, 0x2, 0x208, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x209, 0x20b, 0x7, 0xde, 
       0x2, 0x2, 0x20a, 0x209, 0x3, 0x2, 0x2, 0x2, 0x20b, 0x20e, 0x3, 0x2, 
       0x2, 0x2, 0x20c, 0x20a, 0x3, 0x2, 0x2, 0x2, 0x20c, 0x20d, 0x3, 0x2, 
       0x2, 0x2, 0x20d, 0x20f, 0x3, 0x2, 0x2, 0x2, 0x20e, 0x20c, 0x3, 0x2, 
       0x2, 0x2, 0x20f, 0x213, 0x7, 0xc5, 0x2, 0x2, 0x210, 0x212, 0x7, 0xde, 
       0x2, 0x2, 0x211, 0x210, 0x3, 0x2, 0x2, 0x2, 0x212, 0x215, 0x3, 0x2, 
       0x2, 0x2, 0x213, 0x211, 0x3, 0x2, 0x2, 0x2, 0x213, 0x214, 0x3, 0x2, 
       0x2, 0x2, 0x214, 0x217, 0x3, 0x2, 0x2, 0x2, 0x215, 0x213, 0x3, 0x2, 
       0x2, 0x2, 0x216, 0x20c, 0x3, 0x2, 0x2, 0x2, 0x216, 0x217, 0x3, 0x2, 
       0x2, 0x2, 0x217, 0x21d, 0x3, 0x2, 0x2, 0x2, 0x218, 0x21e, 0x5, 0xc2, 
       0x62, 0x2, 0x219, 0x21e, 0x5, 0x32, 0x1a, 0x2, 0x21a, 0x21e, 0x5, 
       0x86, 0x44, 0x2, 0x21b, 0x21e, 0x5, 0x2c, 0x17, 0x2, 0x21c, 0x21e, 
       0x7, 0xde, 0x2, 0x2, 0x21d, 0x218, 0x3, 0x2, 0x2, 0x2, 0x21d, 0x219, 
       0x3, 0x2, 0x2, 0x2, 0x21d, 0x21a, 0x3, 0x2, 0x2, 0x2, 0x21d, 0x21b, 
       0x3, 0x2, 0x2, 0x2, 0x21d, 0x21c, 0x3, 0x2, 0x2, 0x2, 0x21e, 0x21f, 
       0x3, 0x2, 0x2, 0x2, 0x21f, 0x21d, 0x3, 0x2, 0x2, 0x2, 0x21f, 0x220, 
       0x3, 0x2, 0x2, 0x2, 0x220, 0x228, 0x3, 0x2, 0x2, 0x2, 0x221, 0x223, 
       0x7, 0xde, 0x2, 0x2, 0x222, 0x221, 0x3, 0x2, 0x2, 0x2, 0x223, 0x226, 
       0x3, 0x2, 0x2, 0x2, 0x224, 0x222, 0x3, 0x2, 0x2, 0x2, 0x224, 0x225, 
       0x3, 0x2, 0x2, 0x2, 0x225, 0x227, 0x3, 0x2, 0x2, 0x2, 0x226, 0x224, 
       0x3, 0x2, 0x2, 0x2, 0x227, 0x229, 0x7, 0xc6, 0x2, 0x2, 0x228, 0x224, 
       0x3, 0x2, 0x2, 0x2, 0x228, 0x229, 0x3, 0x2, 0x2, 0x2, 0x229, 0x231, 
       0x3, 0x2, 0x2, 0x2, 0x22a, 0x22c, 0x7, 0xde, 0x2, 0x2, 0x22b, 0x22a, 
       0x3, 0x2, 0x2, 0x2, 0x22c, 0x22f, 0x3, 0x2, 0x2, 0x2, 0x22d, 0x22b, 
       0x3, 0x2, 0x2, 0x2, 0x22d, 0x22e, 0x3, 0x2, 0x2, 0x2, 0x22e, 0x232, 
       0x3, 0x2, 0x2, 0x2, 0x22f, 0x22d, 0x3, 0x2, 0x2, 0x2, 0x230, 0x232, 
       0x7, 0x2, 0x2, 0x3, 0x231, 0x22d, 0x3, 0x2, 0x2, 0x2, 0x231, 0x230, 
       0x3, 0x2, 0x2, 0x2, 0x232, 0x31, 0x3, 0x2, 0x2, 0x2, 0x233, 0x250, 
       0x5, 0x34, 0x1b, 0x2, 0x234, 0x250, 0x5, 0x36, 0x1c, 0x2, 0x235, 
       0x250, 0x5, 0x38, 0x1d, 0x2, 0x236, 0x250, 0x5, 0x3a, 0x1e, 0x2, 
       0x237, 0x250, 0x5, 0x3c, 0x1f, 0x2, 0x238, 0x250, 0x5, 0x3e, 0x20, 
       0x2, 0x239, 0x250, 0x5, 0x40, 0x21, 0x2, 0x23a, 0x250, 0x5, 0x42, 
       0x22, 0x2, 0x23b, 0x250, 0x5, 0x4a, 0x26, 0x2, 0x23c, 0x250, 0x5, 
       0x4c, 0x27, 0x2, 0x23d, 0x250, 0x5, 0x4e, 0x28, 0x2, 0x23e, 0x250, 
       0x5, 0x50, 0x29, 0x2, 0x23f, 0x250, 0x5, 0x52, 0x2a, 0x2, 0x240, 
       0x250, 0x5, 0x54, 0x2b, 0x2, 0x241, 0x250, 0x5, 0x56, 0x2c, 0x2, 
       0x242, 0x250, 0x5, 0x58, 0x2d, 0x2, 0x243, 0x250, 0x5, 0x5a, 0x2e, 
       0x2, 0x244, 0x250, 0x5, 0x5c, 0x2f, 0x2, 0x245, 0x250, 0x5, 0x5e, 
       0x30, 0x2, 0x246, 0x250, 0x5, 0x60, 0x31, 0x2, 0x247, 0x250, 0x5, 
       0x62, 0x32, 0x2, 0x248, 0x250, 0x5, 0x64, 0x33, 0x2, 0x249, 0x250, 
       0x5, 0x66, 0x34, 0x2, 0x24a, 0x250, 0x5, 0x68, 0x35, 0x2, 0x24b, 
       0x250, 0x5, 0x70, 0x39, 0x2, 0x24c, 0x250, 0x5, 0x7a, 0x3e, 0x2, 
       0x24d, 0x250, 0x5, 0x7c, 0x3f, 0x2, 0x24e, 0x250, 0x5, 0xb6, 0x5c, 
       0x2, 0x24f, 0x233, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x234, 0x3, 0x2, 0x2, 
       0x2, 0x24f, 0x235, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x236, 0x3, 0x2, 0x2, 
       0x2, 0x24f, 0x237, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x238, 0x3, 0x2, 0x2, 
       0x2, 0x24f, 0x239, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x23a, 0x3, 0x2, 0x2, 
       0x2, 0x24f, 0x23b, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x23c, 0x3, 0x2, 0x2, 
       0x2, 0x24f, 0x23d, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x23e, 0x3, 0x2, 0x2, 
       0x2, 0x24f, 0x23f, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x240, 0x3, 0x2, 0x2, 
       0x2, 0x24f, 0x241, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x242, 0x3, 0x2, 0x2, 
       0x2, 0x24f, 0x243, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x244, 0x3, 0x2, 0x2, 
       0x2, 0x24f, 0x245, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x246, 0x3, 0x2, 0x2, 
       0x2, 0x24f, 0x247, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x248, 0x3, 0x2, 0x2, 
       0x2, 0x24f, 0x249, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x24a, 0x3, 0x2, 0x2, 
       0x2, 0x24f, 0x24b, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x24c, 0x3, 0x2, 0x2, 
       0x2, 0x24f, 0x24d, 0x3, 0x2, 0x2, 0x2, 0x24f, 0x24e, 0x3, 0x2, 0x2, 
       0x2, 0x250, 0x33, 0x3, 0x2, 0x2, 0x2, 0x251, 0x253, 0x7, 0xd9, 0x2, 
       0x2, 0x252, 0x251, 0x3, 0x2, 0x2, 0x2, 0x252, 0x253, 0x3, 0x2, 0x2, 
       0x2, 0x253, 0x254, 0x3, 0x2, 0x2, 0x2, 0x254, 0x256, 0x7, 0x35, 0x2, 
       0x2, 0x255, 0x257, 0x5, 0xea, 0x76, 0x2, 0x256, 0x255, 0x3, 0x2, 
       0x2, 0x2, 0x256, 0x257, 0x3, 0x2, 0x2, 0x2, 0x257, 0x25f, 0x3, 0x2, 
       0x2, 0x2, 0x258, 0x25a, 0x7, 0xde, 0x2, 0x2, 0x259, 0x258, 0x3, 0x2, 
       0x2, 0x2, 0x25a, 0x25d, 0x3, 0x2, 0x2, 0x2, 0x25b, 0x259, 0x3, 0x2, 
       0x2, 0x2, 0x25b, 0x25c, 0x3, 0x2, 0x2, 0x2, 0x25c, 0x260, 0x3, 0x2, 
       0x2, 0x2, 0x25d, 0x25b, 0x3, 0x2, 0x2, 0x2, 0x25e, 0x260, 0x7, 0x2, 
       0x2, 0x3, 0x25f, 0x25b, 0x3, 0x2, 0x2, 0x2, 0x25f, 0x25e, 0x3, 0x2, 
       0x2, 0x2, 0x260, 0x26f, 0x3, 0x2, 0x2, 0x2, 0x261, 0x263, 0x7, 0xd9, 
       0x2, 0x2, 0x262, 0x261, 0x3, 0x2, 0x2, 0x2, 0x262, 0x263, 0x3, 0x2, 
       0x2, 0x2, 0x263, 0x264, 0x3, 0x2, 0x2, 0x2, 0x264, 0x26c, 0x7, 0x35, 
       0x2, 0x2, 0x265, 0x267, 0x7, 0xde, 0x2, 0x2, 0x266, 0x265, 0x3, 0x2, 
       0x2, 0x2, 0x267, 0x26a, 0x3, 0x2, 0x2, 0x2, 0x268, 0x266, 0x3, 0x2, 
       0x2, 0x2, 0x268, 0x269, 0x3, 0x2, 0x2, 0x2, 0x269, 0x26d, 0x3, 0x2, 
       0x2, 0x2, 0x26a, 0x268, 0x3, 0x2, 0x2, 0x2, 0x26b, 0x26d, 0x7, 0x2, 
       0x2, 0x3, 0x26c, 0x268, 0x3, 0x2, 0x2, 0x2, 0x26c, 0x26b, 0x3, 0x2, 
       0x2, 0x2, 0x26d, 0x26f, 0x3, 0x2, 0x2, 0x2, 0x26e, 0x252, 0x3, 0x2, 
       0x2, 0x2, 0x26e, 0x262, 0x3, 0x2, 0x2, 0x2, 0x26f, 0x35, 0x3, 0x2, 
       0x2, 0x2, 0x270, 0x272, 0x7, 0xd9, 0x2, 0x2, 0x271, 0x270, 0x3, 0x2, 
       0x2, 0x2, 0x271, 0x272, 0x3, 0x2, 0x2, 0x2, 0x272, 0x273, 0x3, 0x2, 
       0x2, 0x2, 0x273, 0x275, 0x7, 0x36, 0x2, 0x2, 0x274, 0x276, 0x5, 0xd0, 
       0x69, 0x2, 0x275, 0x274, 0x3, 0x2, 0x2, 0x2, 0x275, 0x276, 0x3, 0x2, 
       0x2, 0x2, 0x276, 0x278, 0x3, 0x2, 0x2, 0x2, 0x277, 0x279, 0x5, 0xea, 
       0x76, 0x2, 0x278, 0x277, 0x3, 0x2, 0x2, 0x2, 0x278, 0x279, 0x3, 0x2, 
       0x2, 0x2, 0x279, 0x281, 0x3, 0x2, 0x2, 0x2, 0x27a, 0x27c, 0x7, 0xde, 
       0x2, 0x2, 0x27b, 0x27a, 0x3, 0x2, 0x2, 0x2, 0x27c, 0x27f, 0x3, 0x2, 
       0x2, 0x2, 0x27d, 0x27b, 0x3, 0x2, 0x2, 0x2, 0x27d, 0x27e, 0x3, 0x2, 
       0x2, 0x2, 0x27e, 0x282, 0x3, 0x2, 0x2, 0x2, 0x27f, 0x27d, 0x3, 0x2, 
       0x2, 0x2, 0x280, 0x282, 0x7, 0x2, 0x2, 0x3, 0x281, 0x27d, 0x3, 0x2, 
       0x2, 0x2, 0x281, 0x280, 0x3, 0x2, 0x2, 0x2, 0x282, 0x294, 0x3, 0x2, 
       0x2, 0x2, 0x283, 0x285, 0x7, 0xd9, 0x2, 0x2, 0x284, 0x283, 0x3, 0x2, 
       0x2, 0x2, 0x284, 0x285, 0x3, 0x2, 0x2, 0x2, 0x285, 0x286, 0x3, 0x2, 
       0x2, 0x2, 0x286, 0x288, 0x7, 0x36, 0x2, 0x2, 0x287, 0x289, 0x5, 0xd0, 
       0x69, 0x2, 0x288, 0x287, 0x3, 0x2, 0x2, 0x2, 0x288, 0x289, 0x3, 0x2, 
       0x2, 0x2, 0x289, 0x291, 0x3, 0x2, 0x2, 0x2, 0x28a, 0x28c, 0x7, 0xde, 
       0x2, 0x2, 0x28b, 0x28a, 0x3, 0x2, 0x2, 0x2, 0x28c, 0x28f, 0x3, 0x2, 
       0x2, 0x2, 0x28d, 0x28b, 0x3, 0x2, 0x2, 0x2, 0x28d, 0x28e, 0x3, 0x2, 
       0x2, 0x2, 0x28e, 0x292, 0x3, 0x2, 0x2, 0x2, 0x28f, 0x28d, 0x3, 0x2, 
       0x2, 0x2, 0x290, 0x292, 0x7, 0x2, 0x2, 0x3, 0x291, 0x28d, 0x3, 0x2, 
       0x2, 0x2, 0x291, 0x290, 0x3, 0x2, 0x2, 0x2, 0x292, 0x294, 0x3, 0x2, 
       0x2, 0x2, 0x293, 0x271, 0x3, 0x2, 0x2, 0x2, 0x293, 0x284, 0x3, 0x2, 
       0x2, 0x2, 0x294, 0x37, 0x3, 0x2, 0x2, 0x2, 0x295, 0x297, 0x7, 0xd9, 
       0x2, 0x2, 0x296, 0x295, 0x3, 0x2, 0x2, 0x2, 0x296, 0x297, 0x3, 0x2, 
       0x2, 0x2, 0x297, 0x298, 0x3, 0x2, 0x2, 0x2, 0x298, 0x29a, 0x7, 0x37, 
       0x2, 0x2, 0x299, 0x29b, 0x5, 0xea, 0x76, 0x2, 0x29a, 0x299, 0x3, 
       0x2, 0x2, 0x2, 0x29a, 0x29b, 0x3, 0x2, 0x2, 0x2, 0x29b, 0x2a3, 0x3, 
       0x2, 0x2, 0x2, 0x29c, 0x29e, 0x7, 0xde, 0x2, 0x2, 0x29d, 0x29c, 0x3, 
       0x2, 0x2, 0x2, 0x29e, 0x2a1, 0x3, 0x2, 0x2, 0x2, 0x29f, 0x29d, 0x3, 
       0x2, 0x2, 0x2, 0x29f, 0x2a0, 0x3, 0x2, 0x2, 0x2, 0x2a0, 0x2a4, 0x3, 
       0x2, 0x2, 0x2, 0x2a1, 0x29f, 0x3, 0x2, 0x2, 0x2, 0x2a2, 0x2a4, 0x7, 
       0x2, 0x2, 0x3, 0x2a3, 0x29f, 0x3, 0x2, 0x2, 0x2, 0x2a3, 0x2a2, 0x3, 
       0x2, 0x2, 0x2, 0x2a4, 0x2b3, 0x3, 0x2, 0x2, 0x2, 0x2a5, 0x2a7, 0x7, 
       0xd9, 0x2, 0x2, 0x2a6, 0x2a5, 0x3, 0x2, 0x2, 0x2, 0x2a6, 0x2a7, 0x3, 
       0x2, 0x2, 0x2, 0x2a7, 0x2a8, 0x3, 0x2, 0x2, 0x2, 0x2a8, 0x2b0, 0x7, 
       0x37, 0x2, 0x2, 0x2a9, 0x2ab, 0x7, 0xde, 0x2, 0x2, 0x2aa, 0x2a9, 
       0x3, 0x2, 0x2, 0x2, 0x2ab, 0x2ae, 0x3, 0x2, 0x2, 0x2, 0x2ac, 0x2aa, 
       0x3, 0x2, 0x2, 0x2, 0x2ac, 0x2ad, 0x3, 0x2, 0x2, 0x2, 0x2ad, 0x2b1, 
       0x3, 0x2, 0x2, 0x2, 0x2ae, 0x2ac, 0x3, 0x2, 0x2, 0x2, 0x2af, 0x2b1, 
       0x7, 0x2, 0x2, 0x3, 0x2b0, 0x2ac, 0x3, 0x2, 0x2, 0x2, 0x2b0, 0x2af, 
       0x3, 0x2, 0x2, 0x2, 0x2b1, 0x2b3, 0x3, 0x2, 0x2, 0x2, 0x2b2, 0x296, 
       0x3, 0x2, 0x2, 0x2, 0x2b2, 0x2a6, 0x3, 0x2, 0x2, 0x2, 0x2b3, 0x39, 
       0x3, 0x2, 0x2, 0x2, 0x2b4, 0x2b6, 0x7, 0xd9, 0x2, 0x2, 0x2b5, 0x2b4, 
       0x3, 0x2, 0x2, 0x2, 0x2b5, 0x2b6, 0x3, 0x2, 0x2, 0x2, 0x2b6, 0x2b8, 
       0x3, 0x2, 0x2, 0x2, 0x2b7, 0x2b9, 0x5, 0xd0, 0x69, 0x2, 0x2b8, 0x2b7, 
       0x3, 0x2, 0x2, 0x2, 0x2b8, 0x2b9, 0x3, 0x2, 0x2, 0x2, 0x2b9, 0x2ba, 
       0x3, 0x2, 0x2, 0x2, 0x2ba, 0x2bc, 0x7, 0x38, 0x2, 0x2, 0x2bb, 0x2bd, 
       0x5, 0xea, 0x76, 0x2, 0x2bc, 0x2bb, 0x3, 0x2, 0x2, 0x2, 0x2bc, 0x2bd, 
       0x3, 0x2, 0x2, 0x2, 0x2bd, 0x2c5, 0x3, 0x2, 0x2, 0x2, 0x2be, 0x2c0, 
       0x7, 0xde, 0x2, 0x2, 0x2bf, 0x2be, 0x3, 0x2, 0x2, 0x2, 0x2c0, 0x2c3, 
       0x3, 0x2, 0x2, 0x2, 0x2c1, 0x2bf, 0x3, 0x2, 0x2, 0x2, 0x2c1, 0x2c2, 
       0x3, 0x2, 0x2, 0x2, 0x2c2, 0x2c6, 0x3, 0x2, 0x2, 0x2, 0x2c3, 0x2c1, 
       0x3, 0x2, 0x2, 0x2, 0x2c4, 0x2c6, 0x7, 0x2, 0x2, 0x3, 0x2c5, 0x2c1, 
       0x3, 0x2, 0x2, 0x2, 0x2c5, 0x2c4, 0x3, 0x2, 0x2, 0x2, 0x2c6, 0x2d8, 
       0x3, 0x2, 0x2, 0x2, 0x2c7, 0x2c9, 0x7, 0xd9, 0x2, 0x2, 0x2c8, 0x2c7, 
       0x3, 0x2, 0x2, 0x2, 0x2c8, 0x2c9, 0x3, 0x2, 0x2, 0x2, 0x2c9, 0x2cb, 
       0x3, 0x2, 0x2, 0x2, 0x2ca, 0x2cc, 0x5, 0xd0, 0x69, 0x2, 0x2cb, 0x2ca, 
       0x3, 0x2, 0x2, 0x2, 0x2cb, 0x2cc, 0x3, 0x2, 0x2, 0x2, 0x2cc, 0x2cd, 
       0x3, 0x2, 0x2, 0x2, 0x2cd, 0x2d5, 0x7, 0x38, 0x2, 0x2, 0x2ce, 0x2d0, 
       0x7, 0xde, 0x2, 0x2, 0x2cf, 0x2ce, 0x3, 0x2, 0x2, 0x2, 0x2d0, 0x2d3, 
       0x3, 0x2, 0x2, 0x2, 0x2d1, 0x2cf, 0x3, 0x2, 0x2, 0x2, 0x2d1, 0x2d2, 
       0x3, 0x2, 0x2, 0x2, 0x2d2, 0x2d6, 0x3, 0x2, 0x2, 0x2, 0x2d3, 0x2d1, 
       0x3, 0x2, 0x2, 0x2, 0x2d4, 0x2d6, 0x7, 0x2, 0x2, 0x3, 0x2d5, 0x2d1, 
       0x3, 0x2, 0x2, 0x2, 0x2d5, 0x2d4, 0x3, 0x2, 0x2, 0x2, 0x2d6, 0x2d8, 
       0x3, 0x2, 0x2, 0x2, 0x2d7, 0x2b5, 0x3, 0x2, 0x2, 0x2, 0x2d7, 0x2c8, 
       0x3, 0x2, 0x2, 0x2, 0x2d8, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x2d9, 0x2db, 
       0x7, 0xd9, 0x2, 0x2, 0x2da, 0x2d9, 0x3, 0x2, 0x2, 0x2, 0x2da, 0x2db, 
       0x3, 0x2, 0x2, 0x2, 0x2db, 0x2dd, 0x3, 0x2, 0x2, 0x2, 0x2dc, 0x2de, 
       0x5, 0xd0, 0x69, 0x2, 0x2dd, 0x2dc, 0x3, 0x2, 0x2, 0x2, 0x2dd, 0x2de, 
       0x3, 0x2, 0x2, 0x2, 0x2de, 0x2df, 0x3, 0x2, 0x2, 0x2, 0x2df, 0x2e1, 
       0x7, 0x39, 0x2, 0x2, 0x2e0, 0x2e2, 0x5, 0xea, 0x76, 0x2, 0x2e1, 0x2e0, 
       0x3, 0x2, 0x2, 0x2, 0x2e1, 0x2e2, 0x3, 0x2, 0x2, 0x2, 0x2e2, 0x2ea, 
       0x3, 0x2, 0x2, 0x2, 0x2e3, 0x2e5, 0x7, 0xde, 0x2, 0x2, 0x2e4, 0x2e3, 
       0x3, 0x2, 0x2, 0x2, 0x2e5, 0x2e8, 0x3, 0x2, 0x2, 0x2, 0x2e6, 0x2e4, 
       0x3, 0x2, 0x2, 0x2, 0x2e6, 0x2e7, 0x3, 0x2, 0x2, 0x2, 0x2e7, 0x2eb, 
       0x3, 0x2, 0x2, 0x2, 0x2e8, 0x2e6, 0x3, 0x2, 0x2, 0x2, 0x2e9, 0x2eb, 
       0x7, 0x2, 0x2, 0x3, 0x2ea, 0x2e6, 0x3, 0x2, 0x2, 0x2, 0x2ea, 0x2e9, 
       0x3, 0x2, 0x2, 0x2, 0x2eb, 0x2fd, 0x3, 0x2, 0x2, 0x2, 0x2ec, 0x2ee, 
       0x7, 0xd9, 0x2, 0x2, 0x2ed, 0x2ec, 0x3, 0x2, 0x2, 0x2, 0x2ed, 0x2ee, 
       0x3, 0x2, 0x2, 0x2, 0x2ee, 0x2f0, 0x3, 0x2, 0x2, 0x2, 0x2ef, 0x2f1, 
       0x5, 0xd0, 0x69, 0x2, 0x2f0, 0x2ef, 0x3, 0x2, 0x2, 0x2, 0x2f0, 0x2f1, 
       0x3, 0x2, 0x2, 0x2, 0x2f1, 0x2f2, 0x3, 0x2, 0x2, 0x2, 0x2f2, 0x2fa, 
       0x7, 0x39, 0x2, 0x2, 0x2f3, 0x2f5, 0x7, 0xde, 0x2, 0x2, 0x2f4, 0x2f3, 
       0x3, 0x2, 0x2, 0x2, 0x2f5, 0x2f8, 0x3, 0x2, 0x2, 0x2, 0x2f6, 0x2f4, 
       0x3, 0x2, 0x2, 0x2, 0x2f6, 0x2f7, 0x3, 0x2, 0x2, 0x2, 0x2f7, 0x2fb, 
       0x3, 0x2, 0x2, 0x2, 0x2f8, 0x2f6, 0x3, 0x2, 0x2, 0x2, 0x2f9, 0x2fb, 
       0x7, 0x2, 0x2, 0x3, 0x2fa, 0x2f6, 0x3, 0x2, 0x2, 0x2, 0x2fa, 0x2f9, 
       0x3, 0x2, 0x2, 0x2, 0x2fb, 0x2fd, 0x3, 0x2, 0x2, 0x2, 0x2fc, 0x2da, 
       0x3, 0x2, 0x2, 0x2, 0x2fc, 0x2ed, 0x3, 0x2, 0x2, 0x2, 0x2fd, 0x3d, 
       0x3, 0x2, 0x2, 0x2, 0x2fe, 0x300, 0x7, 0xd9, 0x2, 0x2, 0x2ff, 0x2fe, 
       0x3, 0x2, 0x2, 0x2, 0x2ff, 0x300, 0x3, 0x2, 0x2, 0x2, 0x300, 0x301, 
       0x3, 0x2, 0x2, 0x2, 0x301, 0x303, 0x7, 0x3a, 0x2, 0x2, 0x302, 0x304, 
       0x5, 0xea, 0x76, 0x2, 0x303, 0x302, 0x3, 0x2, 0x2, 0x2, 0x303, 0x304, 
       0x3, 0x2, 0x2, 0x2, 0x304, 0x30c, 0x3, 0x2, 0x2, 0x2, 0x305, 0x307, 
       0x7, 0xde, 0x2, 0x2, 0x306, 0x305, 0x3, 0x2, 0x2, 0x2, 0x307, 0x30a, 
       0x3, 0x2, 0x2, 0x2, 0x308, 0x306, 0x3, 0x2, 0x2, 0x2, 0x308, 0x309, 
       0x3, 0x2, 0x2, 0x2, 0x309, 0x30d, 0x3, 0x2, 0x2, 0x2, 0x30a, 0x308, 
       0x3, 0x2, 0x2, 0x2, 0x30b, 0x30d, 0x7, 0x2, 0x2, 0x3, 0x30c, 0x308, 
       0x3, 0x2, 0x2, 0x2, 0x30c, 0x30b, 0x3, 0x2, 0x2, 0x2, 0x30d, 0x31c, 
       0x3, 0x2, 0x2, 0x2, 0x30e, 0x310, 0x7, 0xd9, 0x2, 0x2, 0x30f, 0x30e, 
       0x3, 0x2, 0x2, 0x2, 0x30f, 0x310, 0x3, 0x2, 0x2, 0x2, 0x310, 0x311, 
       0x3, 0x2, 0x2, 0x2, 0x311, 0x319, 0x7, 0x3a, 0x2, 0x2, 0x312, 0x314, 
       0x7, 0xde, 0x2, 0x2, 0x313, 0x312, 0x3, 0x2, 0x2, 0x2, 0x314, 0x317, 
       0x3, 0x2, 0x2, 0x2, 0x315, 0x313, 0x3, 0x2, 0x2, 0x2, 0x315, 0x316, 
       0x3, 0x2, 0x2, 0x2, 0x316, 0x31a, 0x3, 0x2, 0x2, 0x2, 0x317, 0x315, 
       0x3, 0x2, 0x2, 0x2, 0x318, 0x31a, 0x7, 0x2, 0x2, 0x3, 0x319, 0x315, 
       0x3, 0x2, 0x2, 0x2, 0x319, 0x318, 0x3, 0x2, 0x2, 0x2, 0x31a, 0x31c, 
       0x3, 0x2, 0x2, 0x2, 0x31b, 0x2ff, 0x3, 0x2, 0x2, 0x2, 0x31b, 0x30f, 
       0x3, 0x2, 0x2, 0x2, 0x31c, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x31d, 0x31f, 
       0x7, 0xd9, 0x2, 0x2, 0x31e, 0x31d, 0x3, 0x2, 0x2, 0x2, 0x31e, 0x31f, 
       0x3, 0x2, 0x2, 0x2, 0x31f, 0x320, 0x3, 0x2, 0x2, 0x2, 0x320, 0x322, 
       0x7, 0x3b, 0x2, 0x2, 0x321, 0x323, 0x5, 0xea, 0x76, 0x2, 0x322, 0x321, 
       0x3, 0x2, 0x2, 0x2, 0x322, 0x323, 0x3, 0x2, 0x2, 0x2, 0x323, 0x32b, 
       0x3, 0x2, 0x2, 0x2, 0x324, 0x326, 0x7, 0xde, 0x2, 0x2, 0x325, 0x324, 
       0x3, 0x2, 0x2, 0x2, 0x326, 0x329, 0x3, 0x2, 0x2, 0x2, 0x327, 0x325, 
       0x3, 0x2, 0x2, 0x2, 0x327, 0x328, 0x3, 0x2, 0x2, 0x2, 0x328, 0x32c, 
       0x3, 0x2, 0x2, 0x2, 0x329, 0x327, 0x3, 0x2, 0x2, 0x2, 0x32a, 0x32c, 
       0x7, 0x2, 0x2, 0x3, 0x32b, 0x327, 0x3, 0x2, 0x2, 0x2, 0x32b, 0x32a, 
       0x3, 0x2, 0x2, 0x2, 0x32c, 0x33b, 0x3, 0x2, 0x2, 0x2, 0x32d, 0x32f, 
       0x7, 0xd9, 0x2, 0x2, 0x32e, 0x32d, 0x3, 0x2, 0x2, 0x2, 0x32e, 0x32f, 
       0x3, 0x2, 0x2, 0x2, 0x32f, 0x330, 0x3, 0x2, 0x2, 0x2, 0x330, 0x338, 
       0x7, 0x3b, 0x2, 0x2, 0x331, 0x333, 0x7, 0xde, 0x2, 0x2, 0x332, 0x331, 
       0x3, 0x2, 0x2, 0x2, 0x333, 0x336, 0x3, 0x2, 0x2, 0x2, 0x334, 0x332, 
       0x3, 0x2, 0x2, 0x2, 0x334, 0x335, 0x3, 0x2, 0x2, 0x2, 0x335, 0x339, 
       0x3, 0x2, 0x2, 0x2, 0x336, 0x334, 0x3, 0x2, 0x2, 0x2, 0x337, 0x339, 
       0x7, 0x2, 0x2, 0x3, 0x338, 0x334, 0x3, 0x2, 0x2, 0x2, 0x338, 0x337, 
       0x3, 0x2, 0x2, 0x2, 0x339, 0x33b, 0x3, 0x2, 0x2, 0x2, 0x33a, 0x31e, 
       0x3, 0x2, 0x2, 0x2, 0x33a, 0x32e, 0x3, 0x2, 0x2, 0x2, 0x33b, 0x41, 
       0x3, 0x2, 0x2, 0x2, 0x33c, 0x33e, 0x5, 0x44, 0x23, 0x2, 0x33d, 0x33f, 
       0x5, 0x46, 0x24, 0x2, 0x33e, 0x33d, 0x3, 0x2, 0x2, 0x2, 0x33f, 0x340, 
       0x3, 0x2, 0x2, 0x2, 0x340, 0x33e, 0x3, 0x2, 0x2, 0x2, 0x340, 0x341, 
       0x3, 0x2, 0x2, 0x2, 0x341, 0x342, 0x3, 0x2, 0x2, 0x2, 0x342, 0x343, 
       0x5, 0x48, 0x25, 0x2, 0x343, 0x43, 0x3, 0x2, 0x2, 0x2, 0x344, 0x346, 
       0x7, 0xd9, 0x2, 0x2, 0x345, 0x344, 0x3, 0x2, 0x2, 0x2, 0x345, 0x346, 
       0x3, 0x2, 0x2, 0x2, 0x346, 0x347, 0x3, 0x2, 0x2, 0x2, 0x347, 0x34b, 
       0x7, 0x3c, 0x2, 0x2, 0x348, 0x34a, 0x7, 0xde, 0x2, 0x2, 0x349, 0x348, 
       0x3, 0x2, 0x2, 0x2, 0x34a, 0x34d, 0x3, 0x2, 0x2, 0x2, 0x34b, 0x349, 
       0x3, 0x2, 0x2, 0x2, 0x34b, 0x34c, 0x3, 0x2, 0x2, 0x2, 0x34c, 0x351, 
       0x3, 0x2, 0x2, 0x2, 0x34d, 0x34b, 0x3, 0x2, 0x2, 0x2, 0x34e, 0x350, 
       0x5, 0xea, 0x76, 0x2, 0x34f, 0x34e, 0x3, 0x2, 0x2, 0x2, 0x350, 0x353, 
       0x3, 0x2, 0x2, 0x2, 0x351, 0x34f, 0x3, 0x2, 0x2, 0x2, 0x351, 0x352, 
       0x3, 0x2, 0x2, 0x2, 0x352, 0x354, 0x3, 0x2, 0x2, 0x2, 0x353, 0x351, 
       0x3, 0x2, 0x2, 0x2, 0x354, 0x35c, 0x7, 0xc5, 0x2, 0x2, 0x355, 0x357, 
       0x7, 0xde, 0x2, 0x2, 0x356, 0x355, 0x3, 0x2, 0x2, 0x2, 0x357, 0x35a, 
       0x3, 0x2, 0x2, 0x2, 0x358, 0x356, 0x3, 0x2, 0x2, 0x2, 0x358, 0x359, 
       0x3, 0x2, 0x2, 0x2, 0x359, 0x35d, 0x3, 0x2, 0x2, 0x2, 0x35a, 0x358, 
       0x3, 0x2, 0x2, 0x2, 0x35b, 0x35d, 0x7, 0x2, 0x2, 0x3, 0x35c, 0x358, 
       0x3, 0x2, 0x2, 0x2, 0x35c, 0x35b, 0x3, 0x2, 0x2, 0x2, 0x35d, 0x45, 
       0x3, 0x2, 0x2, 0x2, 0x35e, 0x35f, 0x5, 0x6, 0x4, 0x2, 0x35f, 0x47, 
       0x3, 0x2, 0x2, 0x2, 0x360, 0x368, 0x7, 0xc6, 0x2, 0x2, 0x361, 0x363, 
       0x7, 0xde, 0x2, 0x2, 0x362, 0x361, 0x3, 0x2, 0x2, 0x2, 0x363, 0x366, 
       0x3, 0x2, 0x2, 0x2, 0x364, 0x362, 0x3, 0x2, 0x2, 0x2, 0x364, 0x365, 
       0x3, 0x2, 0x2, 0x2, 0x365, 0x369, 0x3, 0x2, 0x2, 0x2, 0x366, 0x364, 
       0x3, 0x2, 0x2, 0x2, 0x367, 0x369, 0x7, 0x2, 0x2, 0x3, 0x368, 0x364, 
       0x3, 0x2, 0x2, 0x2, 0x368, 0x367, 0x3, 0x2, 0x2, 0x2, 0x369, 0x49, 
       0x3, 0x2, 0x2, 0x2, 0x36a, 0x36c, 0x7, 0xd9, 0x2, 0x2, 0x36b, 0x36a, 
       0x3, 0x2, 0x2, 0x2, 0x36b, 0x36c, 0x3, 0x2, 0x2, 0x2, 0x36c, 0x36d, 
       0x3, 0x2, 0x2, 0x2, 0x36d, 0x36f, 0x7, 0x3d, 0x2, 0x2, 0x36e, 0x370, 
       0x5, 0xea, 0x76, 0x2, 0x36f, 0x36e, 0x3, 0x2, 0x2, 0x2, 0x36f, 0x370, 
       0x3, 0x2, 0x2, 0x2, 0x370, 0x378, 0x3, 0x2, 0x2, 0x2, 0x371, 0x373, 
       0x7, 0xde, 0x2, 0x2, 0x372, 0x371, 0x3, 0x2, 0x2, 0x2, 0x373, 0x376, 
       0x3, 0x2, 0x2, 0x2, 0x374, 0x372, 0x3, 0x2, 0x2, 0x2, 0x374, 0x375, 
       0x3, 0x2, 0x2, 0x2, 0x375, 0x379, 0x3, 0x2, 0x2, 0x2, 0x376, 0x374, 
       0x3, 0x2, 0x2, 0x2, 0x377, 0x379, 0x7, 0x2, 0x2, 0x3, 0x378, 0x374, 
       0x3, 0x2, 0x2, 0x2, 0x378, 0x377, 0x3, 0x2, 0x2, 0x2, 0x379, 0x388, 
       0x3, 0x2, 0x2, 0x2, 0x37a, 0x37c, 0x7, 0xd9, 0x2, 0x2, 0x37b, 0x37a, 
       0x3, 0x2, 0x2, 0x2, 0x37b, 0x37c, 0x3, 0x2, 0x2, 0x2, 0x37c, 0x37d, 
       0x3, 0x2, 0x2, 0x2, 0x37d, 0x385, 0x7, 0x3d, 0x2, 0x2, 0x37e, 0x380, 
       0x7, 0xde, 0x2, 0x2, 0x37f, 0x37e, 0x3, 0x2, 0x2, 0x2, 0x380, 0x383, 
       0x3, 0x2, 0x2, 0x2, 0x381, 0x37f, 0x3, 0x2, 0x2, 0x2, 0x381, 0x382, 
       0x3, 0x2, 0x2, 0x2, 0x382, 0x386, 0x3, 0x2, 0x2, 0x2, 0x383, 0x381, 
       0x3, 0x2, 0x2, 0x2, 0x384, 0x386, 0x7, 0x2, 0x2, 0x3, 0x385, 0x381, 
       0x3, 0x2, 0x2, 0x2, 0x385, 0x384, 0x3, 0x2, 0x2, 0x2, 0x386, 0x388, 
       0x3, 0x2, 0x2, 0x2, 0x387, 0x36b, 0x3, 0x2, 0x2, 0x2, 0x387, 0x37b, 
       0x3, 0x2, 0x2, 0x2, 0x388, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x389, 0x38b, 
       0x7, 0xd9, 0x2, 0x2, 0x38a, 0x389, 0x3, 0x2, 0x2, 0x2, 0x38a, 0x38b, 
       0x3, 0x2, 0x2, 0x2, 0x38b, 0x38c, 0x3, 0x2, 0x2, 0x2, 0x38c, 0x38e, 
       0x7, 0x3e, 0x2, 0x2, 0x38d, 0x38f, 0x5, 0xea, 0x76, 0x2, 0x38e, 0x38d, 
       0x3, 0x2, 0x2, 0x2, 0x38e, 0x38f, 0x3, 0x2, 0x2, 0x2, 0x38f, 0x397, 
       0x3, 0x2, 0x2, 0x2, 0x390, 0x392, 0x7, 0xde, 0x2, 0x2, 0x391, 0x390, 
       0x3, 0x2, 0x2, 0x2, 0x392, 0x395, 0x3, 0x2, 0x2, 0x2, 0x393, 0x391, 
       0x3, 0x2, 0x2, 0x2, 0x393, 0x394, 0x3, 0x2, 0x2, 0x2, 0x394, 0x398, 
       0x3, 0x2, 0x2, 0x2, 0x395, 0x393, 0x3, 0x2, 0x2, 0x2, 0x396, 0x398, 
       0x7, 0x2, 0x2, 0x3, 0x397, 0x393, 0x3, 0x2, 0x2, 0x2, 0x397, 0x396, 
       0x3, 0x2, 0x2, 0x2, 0x398, 0x3a7, 0x3, 0x2, 0x2, 0x2, 0x399, 0x39b, 
       0x7, 0xd9, 0x2, 0x2, 0x39a, 0x399, 0x3, 0x2, 0x2, 0x2, 0x39a, 0x39b, 
       0x3, 0x2, 0x2, 0x2, 0x39b, 0x39c, 0x3, 0x2, 0x2, 0x2, 0x39c, 0x3a4, 
       0x7, 0x3e, 0x2, 0x2, 0x39d, 0x39f, 0x7, 0xde, 0x2, 0x2, 0x39e, 0x39d, 
       0x3, 0x2, 0x2, 0x2, 0x39f, 0x3a2, 0x3, 0x2, 0x2, 0x2, 0x3a0, 0x39e, 
       0x3, 0x2, 0x2, 0x2, 0x3a0, 0x3a1, 0x3, 0x2, 0x2, 0x2, 0x3a1, 0x3a5, 
       0x3, 0x2, 0x2, 0x2, 0x3a2, 0x3a0, 0x3, 0x2, 0x2, 0x2, 0x3a3, 0x3a5, 
       0x7, 0x2, 0x2, 0x3, 0x3a4, 0x3a0, 0x3, 0x2, 0x2, 0x2, 0x3a4, 0x3a3, 
       0x3, 0x2, 0x2, 0x2, 0x3a5, 0x3a7, 0x3, 0x2, 0x2, 0x2, 0x3a6, 0x38a, 
       0x3, 0x2, 0x2, 0x2, 0x3a6, 0x39a, 0x3, 0x2, 0x2, 0x2, 0x3a7, 0x4d, 
       0x3, 0x2, 0x2, 0x2, 0x3a8, 0x3aa, 0x7, 0xd9, 0x2, 0x2, 0x3a9, 0x3a8, 
       0x3, 0x2, 0x2, 0x2, 0x3a9, 0x3aa, 0x3, 0x2, 0x2, 0x2, 0x3aa, 0x3ac, 
       0x3, 0x2, 0x2, 0x2, 0x3ab, 0x3ad, 0x5, 0xd0, 0x69, 0x2, 0x3ac, 0x3ab, 
       0x3, 0x2, 0x2, 0x2, 0x3ac, 0x3ad, 0x3, 0x2, 0x2, 0x2, 0x3ad, 0x3ae, 
       0x3, 0x2, 0x2, 0x2, 0x3ae, 0x3b0, 0x7, 0x3f, 0x2, 0x2, 0x3af, 0x3b1, 
       0x5, 0xea, 0x76, 0x2, 0x3b0, 0x3af, 0x3, 0x2, 0x2, 0x2, 0x3b0, 0x3b1, 
       0x3, 0x2, 0x2, 0x2, 0x3b1, 0x3b9, 0x3, 0x2, 0x2, 0x2, 0x3b2, 0x3b4, 
       0x7, 0xde, 0x2, 0x2, 0x3b3, 0x3b2, 0x3, 0x2, 0x2, 0x2, 0x3b4, 0x3b7, 
       0x3, 0x2, 0x2, 0x2, 0x3b5, 0x3b3, 0x3, 0x2, 0x2, 0x2, 0x3b5, 0x3b6, 
       0x3, 0x2, 0x2, 0x2, 0x3b6, 0x3ba, 0x3, 0x2, 0x2, 0x2, 0x3b7, 0x3b5, 
       0x3, 0x2, 0x2, 0x2, 0x3b8, 0x3ba, 0x7, 0x2, 0x2, 0x3, 0x3b9, 0x3b5, 
       0x3, 0x2, 0x2, 0x2, 0x3b9, 0x3b8, 0x3, 0x2, 0x2, 0x2, 0x3ba, 0x3cc, 
       0x3, 0x2, 0x2, 0x2, 0x3bb, 0x3bd, 0x7, 0xd9, 0x2, 0x2, 0x3bc, 0x3bb, 
       0x3, 0x2, 0x2, 0x2, 0x3bc, 0x3bd, 0x3, 0x2, 0x2, 0x2, 0x3bd, 0x3bf, 
       0x3, 0x2, 0x2, 0x2, 0x3be, 0x3c0, 0x5, 0xd0, 0x69, 0x2, 0x3bf, 0x3be, 
       0x3, 0x2, 0x2, 0x2, 0x3bf, 0x3c0, 0x3, 0x2, 0x2, 0x2, 0x3c0, 0x3c1, 
       0x3, 0x2, 0x2, 0x2, 0x3c1, 0x3c9, 0x7, 0x3f, 0x2, 0x2, 0x3c2, 0x3c4, 
       0x7, 0xde, 0x2, 0x2, 0x3c3, 0x3c2, 0x3, 0x2, 0x2, 0x2, 0x3c4, 0x3c7, 
       0x3, 0x2, 0x2, 0x2, 0x3c5, 0x3c3, 0x3, 0x2, 0x2, 0x2, 0x3c5, 0x3c6, 
       0x3, 0x2, 0x2, 0x2, 0x3c6, 0x3ca, 0x3, 0x2, 0x2, 0x2, 0x3c7, 0x3c5, 
       0x3, 0x2, 0x2, 0x2, 0x3c8, 0x3ca, 0x7, 0x2, 0x2, 0x3, 0x3c9, 0x3c5, 
       0x3, 0x2, 0x2, 0x2, 0x3c9, 0x3c8, 0x3, 0x2, 0x2, 0x2, 0x3ca, 0x3cc, 
       0x3, 0x2, 0x2, 0x2, 0x3cb, 0x3a9, 0x3, 0x2, 0x2, 0x2, 0x3cb, 0x3bc, 
       0x3, 0x2, 0x2, 0x2, 0x3cc, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x3cd, 0x3cf, 
       0x7, 0xd9, 0x2, 0x2, 0x3ce, 0x3cd, 0x3, 0x2, 0x2, 0x2, 0x3ce, 0x3cf, 
       0x3, 0x2, 0x2, 0x2, 0x3cf, 0x3d1, 0x3, 0x2, 0x2, 0x2, 0x3d0, 0x3d2, 
       0x5, 0xd0, 0x69, 0x2, 0x3d1, 0x3d0, 0x3, 0x2, 0x2, 0x2, 0x3d1, 0x3d2, 
       0x3, 0x2, 0x2, 0x2, 0x3d2, 0x3d3, 0x3, 0x2, 0x2, 0x2, 0x3d3, 0x3d5, 
       0x7, 0x40, 0x2, 0x2, 0x3d4, 0x3d6, 0x5, 0xea, 0x76, 0x2, 0x3d5, 0x3d4, 
       0x3, 0x2, 0x2, 0x2, 0x3d5, 0x3d6, 0x3, 0x2, 0x2, 0x2, 0x3d6, 0x3de, 
       0x3, 0x2, 0x2, 0x2, 0x3d7, 0x3d9, 0x7, 0xde, 0x2, 0x2, 0x3d8, 0x3d7, 
       0x3, 0x2, 0x2, 0x2, 0x3d9, 0x3dc, 0x3, 0x2, 0x2, 0x2, 0x3da, 0x3d8, 
       0x3, 0x2, 0x2, 0x2, 0x3da, 0x3db, 0x3, 0x2, 0x2, 0x2, 0x3db, 0x3df, 
       0x3, 0x2, 0x2, 0x2, 0x3dc, 0x3da, 0x3, 0x2, 0x2, 0x2, 0x3dd, 0x3df, 
       0x7, 0x2, 0x2, 0x3, 0x3de, 0x3da, 0x3, 0x2, 0x2, 0x2, 0x3de, 0x3dd, 
       0x3, 0x2, 0x2, 0x2, 0x3df, 0x3f1, 0x3, 0x2, 0x2, 0x2, 0x3e0, 0x3e2, 
       0x7, 0xd9, 0x2, 0x2, 0x3e1, 0x3e0, 0x3, 0x2, 0x2, 0x2, 0x3e1, 0x3e2, 
       0x3, 0x2, 0x2, 0x2, 0x3e2, 0x3e4, 0x3, 0x2, 0x2, 0x2, 0x3e3, 0x3e5, 
       0x5, 0xd0, 0x69, 0x2, 0x3e4, 0x3e3, 0x3, 0x2, 0x2, 0x2, 0x3e4, 0x3e5, 
       0x3, 0x2, 0x2, 0x2, 0x3e5, 0x3e6, 0x3, 0x2, 0x2, 0x2, 0x3e6, 0x3ee, 
       0x7, 0x40, 0x2, 0x2, 0x3e7, 0x3e9, 0x7, 0xde, 0x2, 0x2, 0x3e8, 0x3e7, 
       0x3, 0x2, 0x2, 0x2, 0x3e9, 0x3ec, 0x3, 0x2, 0x2, 0x2, 0x3ea, 0x3e8, 
       0x3, 0x2, 0x2, 0x2, 0x3ea, 0x3eb, 0x3, 0x2, 0x2, 0x2, 0x3eb, 0x3ef, 
       0x3, 0x2, 0x2, 0x2, 0x3ec, 0x3ea, 0x3, 0x2, 0x2, 0x2, 0x3ed, 0x3ef, 
       0x7, 0x2, 0x2, 0x3, 0x3ee, 0x3ea, 0x3, 0x2, 0x2, 0x2, 0x3ee, 0x3ed, 
       0x3, 0x2, 0x2, 0x2, 0x3ef, 0x3f1, 0x3, 0x2, 0x2, 0x2, 0x3f0, 0x3ce, 
       0x3, 0x2, 0x2, 0x2, 0x3f0, 0x3e1, 0x3, 0x2, 0x2, 0x2, 0x3f1, 0x51, 
       0x3, 0x2, 0x2, 0x2, 0x3f2, 0x3f4, 0x7, 0xd9, 0x2, 0x2, 0x3f3, 0x3f2, 
       0x3, 0x2, 0x2, 0x2, 0x3f3, 0x3f4, 0x3, 0x2, 0x2, 0x2, 0x3f4, 0x3f6, 
       0x3, 0x2, 0x2, 0x2, 0x3f5, 0x3f7, 0x5, 0xd0, 0x69, 0x2, 0x3f6, 0x3f5, 
       0x3, 0x2, 0x2, 0x2, 0x3f6, 0x3f7, 0x3, 0x2, 0x2, 0x2, 0x3f7, 0x3f8, 
       0x3, 0x2, 0x2, 0x2, 0x3f8, 0x3fa, 0x7, 0x41, 0x2, 0x2, 0x3f9, 0x3fb, 
       0x5, 0xea, 0x76, 0x2, 0x3fa, 0x3f9, 0x3, 0x2, 0x2, 0x2, 0x3fa, 0x3fb, 
       0x3, 0x2, 0x2, 0x2, 0x3fb, 0x403, 0x3, 0x2, 0x2, 0x2, 0x3fc, 0x3fe, 
       0x7, 0xde, 0x2, 0x2, 0x3fd, 0x3fc, 0x3, 0x2, 0x2, 0x2, 0x3fe, 0x401, 
       0x3, 0x2, 0x2, 0x2, 0x3ff, 0x3fd, 0x3, 0x2, 0x2, 0x2, 0x3ff, 0x400, 
       0x3, 0x2, 0x2, 0x2, 0x400, 0x404, 0x3, 0x2, 0x2, 0x2, 0x401, 0x3ff, 
       0x3, 0x2, 0x2, 0x2, 0x402, 0x404, 0x7, 0x2, 0x2, 0x3, 0x403, 0x3ff, 
       0x3, 0x2, 0x2, 0x2, 0x403, 0x402, 0x3, 0x2, 0x2, 0x2, 0x404, 0x416, 
       0x3, 0x2, 0x2, 0x2, 0x405, 0x407, 0x7, 0xd9, 0x2, 0x2, 0x406, 0x405, 
       0x3, 0x2, 0x2, 0x2, 0x406, 0x407, 0x3, 0x2, 0x2, 0x2, 0x407, 0x409, 
       0x3, 0x2, 0x2, 0x2, 0x408, 0x40a, 0x5, 0xd0, 0x69, 0x2, 0x409, 0x408, 
       0x3, 0x2, 0x2, 0x2, 0x409, 0x40a, 0x3, 0x2, 0x2, 0x2, 0x40a, 0x40b, 
       0x3, 0x2, 0x2, 0x2, 0x40b, 0x413, 0x7, 0x41, 0x2, 0x2, 0x40c, 0x40e, 
       0x7, 0xde, 0x2, 0x2, 0x40d, 0x40c, 0x3, 0x2, 0x2, 0x2, 0x40e, 0x411, 
       0x3, 0x2, 0x2, 0x2, 0x40f, 0x40d, 0x3, 0x2, 0x2, 0x2, 0x40f, 0x410, 
       0x3, 0x2, 0x2, 0x2, 0x410, 0x414, 0x3, 0x2, 0x2, 0x2, 0x411, 0x40f, 
       0x3, 0x2, 0x2, 0x2, 0x412, 0x414, 0x7, 0x2, 0x2, 0x3, 0x413, 0x40f, 
       0x3, 0x2, 0x2, 0x2, 0x413, 0x412, 0x3, 0x2, 0x2, 0x2, 0x414, 0x416, 
       0x3, 0x2, 0x2, 0x2, 0x415, 0x3f3, 0x3, 0x2, 0x2, 0x2, 0x415, 0x406, 
       0x3, 0x2, 0x2, 0x2, 0x416, 0x53, 0x3, 0x2, 0x2, 0x2, 0x417, 0x419, 
       0x7, 0xd9, 0x2, 0x2, 0x418, 0x417, 0x3, 0x2, 0x2, 0x2, 0x418, 0x419, 
       0x3, 0x2, 0x2, 0x2, 0x419, 0x41b, 0x3, 0x2, 0x2, 0x2, 0x41a, 0x41c, 
       0x5, 0xd0, 0x69, 0x2, 0x41b, 0x41a, 0x3, 0x2, 0x2, 0x2, 0x41b, 0x41c, 
       0x3, 0x2, 0x2, 0x2, 0x41c, 0x41d, 0x3, 0x2, 0x2, 0x2, 0x41d, 0x41f, 
       0x7, 0x42, 0x2, 0x2, 0x41e, 0x420, 0x5, 0xea, 0x76, 0x2, 0x41f, 0x41e, 
       0x3, 0x2, 0x2, 0x2, 0x41f, 0x420, 0x3, 0x2, 0x2, 0x2, 0x420, 0x428, 
       0x3, 0x2, 0x2, 0x2, 0x421, 0x423, 0x7, 0xde, 0x2, 0x2, 0x422, 0x421, 
       0x3, 0x2, 0x2, 0x2, 0x423, 0x426, 0x3, 0x2, 0x2, 0x2, 0x424, 0x422, 
       0x3, 0x2, 0x2, 0x2, 0x424, 0x425, 0x3, 0x2, 0x2, 0x2, 0x425, 0x429, 
       0x3, 0x2, 0x2, 0x2, 0x426, 0x424, 0x3, 0x2, 0x2, 0x2, 0x427, 0x429, 
       0x7, 0x2, 0x2, 0x3, 0x428, 0x424, 0x3, 0x2, 0x2, 0x2, 0x428, 0x427, 
       0x3, 0x2, 0x2, 0x2, 0x429, 0x43b, 0x3, 0x2, 0x2, 0x2, 0x42a, 0x42c, 
       0x7, 0xd9, 0x2, 0x2, 0x42b, 0x42a, 0x3, 0x2, 0x2, 0x2, 0x42b, 0x42c, 
       0x3, 0x2, 0x2, 0x2, 0x42c, 0x42e, 0x3, 0x2, 0x2, 0x2, 0x42d, 0x42f, 
       0x5, 0xd0, 0x69, 0x2, 0x42e, 0x42d, 0x3, 0x2, 0x2, 0x2, 0x42e, 0x42f, 
       0x3, 0x2, 0x2, 0x2, 0x42f, 0x430, 0x3, 0x2, 0x2, 0x2, 0x430, 0x438, 
       0x7, 0x42, 0x2, 0x2, 0x431, 0x433, 0x7, 0xde, 0x2, 0x2, 0x432, 0x431, 
       0x3, 0x2, 0x2, 0x2, 0x433, 0x436, 0x3, 0x2, 0x2, 0x2, 0x434, 0x432, 
       0x3, 0x2, 0x2, 0x2, 0x434, 0x435, 0x3, 0x2, 0x2, 0x2, 0x435, 0x439, 
       0x3, 0x2, 0x2, 0x2, 0x436, 0x434, 0x3, 0x2, 0x2, 0x2, 0x437, 0x439, 
       0x7, 0x2, 0x2, 0x3, 0x438, 0x434, 0x3, 0x2, 0x2, 0x2, 0x438, 0x437, 
       0x3, 0x2, 0x2, 0x2, 0x439, 0x43b, 0x3, 0x2, 0x2, 0x2, 0x43a, 0x418, 
       0x3, 0x2, 0x2, 0x2, 0x43a, 0x42b, 0x3, 0x2, 0x2, 0x2, 0x43b, 0x55, 
       0x3, 0x2, 0x2, 0x2, 0x43c, 0x43e, 0x7, 0xd9, 0x2, 0x2, 0x43d, 0x43c, 
       0x3, 0x2, 0x2, 0x2, 0x43d, 0x43e, 0x3, 0x2, 0x2, 0x2, 0x43e, 0x43f, 
       0x3, 0x2, 0x2, 0x2, 0x43f, 0x441, 0x7, 0x43, 0x2, 0x2, 0x440, 0x442, 
       0x5, 0xea, 0x76, 0x2, 0x441, 0x440, 0x3, 0x2, 0x2, 0x2, 0x441, 0x442, 
       0x3, 0x2, 0x2, 0x2, 0x442, 0x44a, 0x3, 0x2, 0x2, 0x2, 0x443, 0x445, 
       0x7, 0xde, 0x2, 0x2, 0x444, 0x443, 0x3, 0x2, 0x2, 0x2, 0x445, 0x448, 
       0x3, 0x2, 0x2, 0x2, 0x446, 0x444, 0x3, 0x2, 0x2, 0x2, 0x446, 0x447, 
       0x3, 0x2, 0x2, 0x2, 0x447, 0x44b, 0x3, 0x2, 0x2, 0x2, 0x448, 0x446, 
       0x3, 0x2, 0x2, 0x2, 0x449, 0x44b, 0x7, 0x2, 0x2, 0x3, 0x44a, 0x446, 
       0x3, 0x2, 0x2, 0x2, 0x44a, 0x449, 0x3, 0x2, 0x2, 0x2, 0x44b, 0x45a, 
       0x3, 0x2, 0x2, 0x2, 0x44c, 0x44e, 0x7, 0xd9, 0x2, 0x2, 0x44d, 0x44c, 
       0x3, 0x2, 0x2, 0x2, 0x44d, 0x44e, 0x3, 0x2, 0x2, 0x2, 0x44e, 0x44f, 
       0x3, 0x2, 0x2, 0x2, 0x44f, 0x457, 0x7, 0x43, 0x2, 0x2, 0x450, 0x452, 
       0x7, 0xde, 0x2, 0x2, 0x451, 0x450, 0x3, 0x2, 0x2, 0x2, 0x452, 0x455, 
       0x3, 0x2, 0x2, 0x2, 0x453, 0x451, 0x3, 0x2, 0x2, 0x2, 0x453, 0x454, 
       0x3, 0x2, 0x2, 0x2, 0x454, 0x458, 0x3, 0x2, 0x2, 0x2, 0x455, 0x453, 
       0x3, 0x2, 0x2, 0x2, 0x456, 0x458, 0x7, 0x2, 0x2, 0x3, 0x457, 0x453, 
       0x3, 0x2, 0x2, 0x2, 0x457, 0x456, 0x3, 0x2, 0x2, 0x2, 0x458, 0x45a, 
       0x3, 0x2, 0x2, 0x2, 0x459, 0x43d, 0x3, 0x2, 0x2, 0x2, 0x459, 0x44d, 
       0x3, 0x2, 0x2, 0x2, 0x45a, 0x57, 0x3, 0x2, 0x2, 0x2, 0x45b, 0x45d, 
       0x7, 0xd9, 0x2, 0x2, 0x45c, 0x45b, 0x3, 0x2, 0x2, 0x2, 0x45c, 0x45d, 
       0x3, 0x2, 0x2, 0x2, 0x45d, 0x45f, 0x3, 0x2, 0x2, 0x2, 0x45e, 0x460, 
       0x5, 0xd0, 0x69, 0x2, 0x45f, 0x45e, 0x3, 0x2, 0x2, 0x2, 0x45f, 0x460, 
       0x3, 0x2, 0x2, 0x2, 0x460, 0x461, 0x3, 0x2, 0x2, 0x2, 0x461, 0x463, 
       0x7, 0x44, 0x2, 0x2, 0x462, 0x464, 0x5, 0xea, 0x76, 0x2, 0x463, 0x462, 
       0x3, 0x2, 0x2, 0x2, 0x463, 0x464, 0x3, 0x2, 0x2, 0x2, 0x464, 0x46c, 
       0x3, 0x2, 0x2, 0x2, 0x465, 0x467, 0x7, 0xde, 0x2, 0x2, 0x466, 0x465, 
       0x3, 0x2, 0x2, 0x2, 0x467, 0x46a, 0x3, 0x2, 0x2, 0x2, 0x468, 0x466, 
       0x3, 0x2, 0x2, 0x2, 0x468, 0x469, 0x3, 0x2, 0x2, 0x2, 0x469, 0x46d, 
       0x3, 0x2, 0x2, 0x2, 0x46a, 0x468, 0x3, 0x2, 0x2, 0x2, 0x46b, 0x46d, 
       0x7, 0x2, 0x2, 0x3, 0x46c, 0x468, 0x3, 0x2, 0x2, 0x2, 0x46c, 0x46b, 
       0x3, 0x2, 0x2, 0x2, 0x46d, 0x47f, 0x3, 0x2, 0x2, 0x2, 0x46e, 0x470, 
       0x7, 0xd9, 0x2, 0x2, 0x46f, 0x46e, 0x3, 0x2, 0x2, 0x2, 0x46f, 0x470, 
       0x3, 0x2, 0x2, 0x2, 0x470, 0x472, 0x3, 0x2, 0x2, 0x2, 0x471, 0x473, 
       0x5, 0xd0, 0x69, 0x2, 0x472, 0x471, 0x3, 0x2, 0x2, 0x2, 0x472, 0x473, 
       0x3, 0x2, 0x2, 0x2, 0x473, 0x474, 0x3, 0x2, 0x2, 0x2, 0x474, 0x47c, 
       0x7, 0x44, 0x2, 0x2, 0x475, 0x477, 0x7, 0xde, 0x2, 0x2, 0x476, 0x475, 
       0x3, 0x2, 0x2, 0x2, 0x477, 0x47a, 0x3, 0x2, 0x2, 0x2, 0x478, 0x476, 
       0x3, 0x2, 0x2, 0x2, 0x478, 0x479, 0x3, 0x2, 0x2, 0x2, 0x479, 0x47d, 
       0x3, 0x2, 0x2, 0x2, 0x47a, 0x478, 0x3, 0x2, 0x2, 0x2, 0x47b, 0x47d, 
       0x7, 0x2, 0x2, 0x3, 0x47c, 0x478, 0x3, 0x2, 0x2, 0x2, 0x47c, 0x47b, 
       0x3, 0x2, 0x2, 0x2, 0x47d, 0x47f, 0x3, 0x2, 0x2, 0x2, 0x47e, 0x45c, 
       0x3, 0x2, 0x2, 0x2, 0x47e, 0x46f, 0x3, 0x2, 0x2, 0x2, 0x47f, 0x59, 
       0x3, 0x2, 0x2, 0x2, 0x480, 0x482, 0x7, 0xd9, 0x2, 0x2, 0x481, 0x480, 
       0x3, 0x2, 0x2, 0x2, 0x481, 0x482, 0x3, 0x2, 0x2, 0x2, 0x482, 0x484, 
       0x3, 0x2, 0x2, 0x2, 0x483, 0x485, 0x5, 0xd0, 0x69, 0x2, 0x484, 0x483, 
       0x3, 0x2, 0x2, 0x2, 0x484, 0x485, 0x3, 0x2, 0x2, 0x2, 0x485, 0x486, 
       0x3, 0x2, 0x2, 0x2, 0x486, 0x488, 0x7, 0x45, 0x2, 0x2, 0x487, 0x489, 
       0x5, 0xea, 0x76, 0x2, 0x488, 0x487, 0x3, 0x2, 0x2, 0x2, 0x488, 0x489, 
       0x3, 0x2, 0x2, 0x2, 0x489, 0x491, 0x3, 0x2, 0x2, 0x2, 0x48a, 0x48c, 
       0x7, 0xde, 0x2, 0x2, 0x48b, 0x48a, 0x3, 0x2, 0x2, 0x2, 0x48c, 0x48f, 
       0x3, 0x2, 0x2, 0x2, 0x48d, 0x48b, 0x3, 0x2, 0x2, 0x2, 0x48d, 0x48e, 
       0x3, 0x2, 0x2, 0x2, 0x48e, 0x492, 0x3, 0x2, 0x2, 0x2, 0x48f, 0x48d, 
       0x3, 0x2, 0x2, 0x2, 0x490, 0x492, 0x7, 0x2, 0x2, 0x3, 0x491, 0x48d, 
       0x3, 0x2, 0x2, 0x2, 0x491, 0x490, 0x3, 0x2, 0x2, 0x2, 0x492, 0x4a4, 
       0x3, 0x2, 0x2, 0x2, 0x493, 0x495, 0x7, 0xd9, 0x2, 0x2, 0x494, 0x493, 
       0x3, 0x2, 0x2, 0x2, 0x494, 0x495, 0x3, 0x2, 0x2, 0x2, 0x495, 0x497, 
       0x3, 0x2, 0x2, 0x2, 0x496, 0x498, 0x5, 0xd0, 0x69, 0x2, 0x497, 0x496, 
       0x3, 0x2, 0x2, 0x2, 0x497, 0x498, 0x3, 0x2, 0x2, 0x2, 0x498, 0x499, 
       0x3, 0x2, 0x2, 0x2, 0x499, 0x4a1, 0x7, 0x45, 0x2, 0x2, 0x49a, 0x49c, 
       0x7, 0xde, 0x2, 0x2, 0x49b, 0x49a, 0x3, 0x2, 0x2, 0x2, 0x49c, 0x49f, 
       0x3, 0x2, 0x2, 0x2, 0x49d, 0x49b, 0x3, 0x2, 0x2, 0x2, 0x49d, 0x49e, 
       0x3, 0x2, 0x2, 0x2, 0x49e, 0x4a2, 0x3, 0x2, 0x2, 0x2, 0x49f, 0x49d, 
       0x3, 0x2, 0x2, 0x2, 0x4a0, 0x4a2, 0x7, 0x2, 0x2, 0x3, 0x4a1, 0x49d, 
       0x3, 0x2, 0x2, 0x2, 0x4a1, 0x4a0, 0x3, 0x2, 0x2, 0x2, 0x4a2, 0x4a4, 
       0x3, 0x2, 0x2, 0x2, 0x4a3, 0x481, 0x3, 0x2, 0x2, 0x2, 0x4a3, 0x494, 
       0x3, 0x2, 0x2, 0x2, 0x4a4, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x4a5, 0x4a7, 
       0x7, 0xd9, 0x2, 0x2, 0x4a6, 0x4a5, 0x3, 0x2, 0x2, 0x2, 0x4a6, 0x4a7, 
       0x3, 0x2, 0x2, 0x2, 0x4a7, 0x4a9, 0x3, 0x2, 0x2, 0x2, 0x4a8, 0x4aa, 
       0x5, 0xd0, 0x69, 0x2, 0x4a9, 0x4a8, 0x3, 0x2, 0x2, 0x2, 0x4a9, 0x4aa, 
       0x3, 0x2, 0x2, 0x2, 0x4aa, 0x4ab, 0x3, 0x2, 0x2, 0x2, 0x4ab, 0x4ad, 
       0x7, 0x46, 0x2, 0x2, 0x4ac, 0x4ae, 0x5, 0xea, 0x76, 0x2, 0x4ad, 0x4ac, 
       0x3, 0x2, 0x2, 0x2, 0x4ad, 0x4ae, 0x3, 0x2, 0x2, 0x2, 0x4ae, 0x4b6, 
       0x3, 0x2, 0x2, 0x2, 0x4af, 0x4b1, 0x7, 0xde, 0x2, 0x2, 0x4b0, 0x4af, 
       0x3, 0x2, 0x2, 0x2, 0x4b1, 0x4b4, 0x3, 0x2, 0x2, 0x2, 0x4b2, 0x4b0, 
       0x3, 0x2, 0x2, 0x2, 0x4b2, 0x4b3, 0x3, 0x2, 0x2, 0x2, 0x4b3, 0x4b7, 
       0x3, 0x2, 0x2, 0x2, 0x4b4, 0x4b2, 0x3, 0x2, 0x2, 0x2, 0x4b5, 0x4b7, 
       0x7, 0x2, 0x2, 0x3, 0x4b6, 0x4b2, 0x3, 0x2, 0x2, 0x2, 0x4b6, 0x4b5, 
       0x3, 0x2, 0x2, 0x2, 0x4b7, 0x4c9, 0x3, 0x2, 0x2, 0x2, 0x4b8, 0x4ba, 
       0x7, 0xd9, 0x2, 0x2, 0x4b9, 0x4b8, 0x3, 0x2, 0x2, 0x2, 0x4b9, 0x4ba, 
       0x3, 0x2, 0x2, 0x2, 0x4ba, 0x4bc, 0x3, 0x2, 0x2, 0x2, 0x4bb, 0x4bd, 
       0x5, 0xd0, 0x69, 0x2, 0x4bc, 0x4bb, 0x3, 0x2, 0x2, 0x2, 0x4bc, 0x4bd, 
       0x3, 0x2, 0x2, 0x2, 0x4bd, 0x4be, 0x3, 0x2, 0x2, 0x2, 0x4be, 0x4c6, 
       0x7, 0x46, 0x2, 0x2, 0x4bf, 0x4c1, 0x7, 0xde, 0x2, 0x2, 0x4c0, 0x4bf, 
       0x3, 0x2, 0x2, 0x2, 0x4c1, 0x4c4, 0x3, 0x2, 0x2, 0x2, 0x4c2, 0x4c0, 
       0x3, 0x2, 0x2, 0x2, 0x4c2, 0x4c3, 0x3, 0x2, 0x2, 0x2, 0x4c3, 0x4c7, 
       0x3, 0x2, 0x2, 0x2, 0x4c4, 0x4c2, 0x3, 0x2, 0x2, 0x2, 0x4c5, 0x4c7, 
       0x7, 0x2, 0x2, 0x3, 0x4c6, 0x4c2, 0x3, 0x2, 0x2, 0x2, 0x4c6, 0x4c5, 
       0x3, 0x2, 0x2, 0x2, 0x4c7, 0x4c9, 0x3, 0x2, 0x2, 0x2, 0x4c8, 0x4a6, 
       0x3, 0x2, 0x2, 0x2, 0x4c8, 0x4b9, 0x3, 0x2, 0x2, 0x2, 0x4c9, 0x5d, 
       0x3, 0x2, 0x2, 0x2, 0x4ca, 0x4cc, 0x7, 0xd9, 0x2, 0x2, 0x4cb, 0x4ca, 
       0x3, 0x2, 0x2, 0x2, 0x4cb, 0x4cc, 0x3, 0x2, 0x2, 0x2, 0x4cc, 0x4cd, 
       0x3, 0x2, 0x2, 0x2, 0x4cd, 0x4cf, 0x7, 0x47, 0x2, 0x2, 0x4ce, 0x4d0, 
       0x5, 0xea, 0x76, 0x2, 0x4cf, 0x4ce, 0x3, 0x2, 0x2, 0x2, 0x4cf, 0x4d0, 
       0x3, 0x2, 0x2, 0x2, 0x4d0, 0x4d8, 0x3, 0x2, 0x2, 0x2, 0x4d1, 0x4d3, 
       0x7, 0xde, 0x2, 0x2, 0x4d2, 0x4d1, 0x3, 0x2, 0x2, 0x2, 0x4d3, 0x4d6, 
       0x3, 0x2, 0x2, 0x2, 0x4d4, 0x4d2, 0x3, 0x2, 0x2, 0x2, 0x4d4, 0x4d5, 
       0x3, 0x2, 0x2, 0x2, 0x4d5, 0x4d9, 0x3, 0x2, 0x2, 0x2, 0x4d6, 0x4d4, 
       0x3, 0x2, 0x2, 0x2, 0x4d7, 0x4d9, 0x7, 0x2, 0x2, 0x3, 0x4d8, 0x4d4, 
       0x3, 0x2, 0x2, 0x2, 0x4d8, 0x4d7, 0x3, 0x2, 0x2, 0x2, 0x4d9, 0x4e8, 
       0x3, 0x2, 0x2, 0x2, 0x4da, 0x4dc, 0x7, 0xd9, 0x2, 0x2, 0x4db, 0x4da, 
       0x3, 0x2, 0x2, 0x2, 0x4db, 0x4dc, 0x3, 0x2, 0x2, 0x2, 0x4dc, 0x4dd, 
       0x3, 0x2, 0x2, 0x2, 0x4dd, 0x4e5, 0x7, 0x47, 0x2, 0x2, 0x4de, 0x4e0, 
       0x7, 0xde, 0x2, 0x2, 0x4df, 0x4de, 0x3, 0x2, 0x2, 0x2, 0x4e0, 0x4e3, 
       0x3, 0x2, 0x2, 0x2, 0x4e1, 0x4df, 0x3, 0x2, 0x2, 0x2, 0x4e1, 0x4e2, 
       0x3, 0x2, 0x2, 0x2, 0x4e2, 0x4e6, 0x3, 0x2, 0x2, 0x2, 0x4e3, 0x4e1, 
       0x3, 0x2, 0x2, 0x2, 0x4e4, 0x4e6, 0x7, 0x2, 0x2, 0x3, 0x4e5, 0x4e1, 
       0x3, 0x2, 0x2, 0x2, 0x4e5, 0x4e4, 0x3, 0x2, 0x2, 0x2, 0x4e6, 0x4e8, 
       0x3, 0x2, 0x2, 0x2, 0x4e7, 0x4cb, 0x3, 0x2, 0x2, 0x2, 0x4e7, 0x4db, 
       0x3, 0x2, 0x2, 0x2, 0x4e8, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x4e9, 0x4eb, 
       0x7, 0xd9, 0x2, 0x2, 0x4ea, 0x4e9, 0x3, 0x2, 0x2, 0x2, 0x4ea, 0x4eb, 
       0x3, 0x2, 0x2, 0x2, 0x4eb, 0x4ed, 0x3, 0x2, 0x2, 0x2, 0x4ec, 0x4ee, 
       0x5, 0xd0, 0x69, 0x2, 0x4ed, 0x4ec, 0x3, 0x2, 0x2, 0x2, 0x4ed, 0x4ee, 
       0x3, 0x2, 0x2, 0x2, 0x4ee, 0x4ef, 0x3, 0x2, 0x2, 0x2, 0x4ef, 0x4f1, 
       0x7, 0x48, 0x2, 0x2, 0x4f0, 0x4f2, 0x5, 0xea, 0x76, 0x2, 0x4f1, 0x4f0, 
       0x3, 0x2, 0x2, 0x2, 0x4f1, 0x4f2, 0x3, 0x2, 0x2, 0x2, 0x4f2, 0x4fa, 
       0x3, 0x2, 0x2, 0x2, 0x4f3, 0x4f5, 0x7, 0xde, 0x2, 0x2, 0x4f4, 0x4f3, 
       0x3, 0x2, 0x2, 0x2, 0x4f5, 0x4f8, 0x3, 0x2, 0x2, 0x2, 0x4f6, 0x4f4, 
       0x3, 0x2, 0x2, 0x2, 0x4f6, 0x4f7, 0x3, 0x2, 0x2, 0x2, 0x4f7, 0x4fb, 
       0x3, 0x2, 0x2, 0x2, 0x4f8, 0x4f6, 0x3, 0x2, 0x2, 0x2, 0x4f9, 0x4fb, 
       0x7, 0x2, 0x2, 0x3, 0x4fa, 0x4f6, 0x3, 0x2, 0x2, 0x2, 0x4fa, 0x4f9, 
       0x3, 0x2, 0x2, 0x2, 0x4fb, 0x50d, 0x3, 0x2, 0x2, 0x2, 0x4fc, 0x4fe, 
       0x7, 0xd9, 0x2, 0x2, 0x4fd, 0x4fc, 0x3, 0x2, 0x2, 0x2, 0x4fd, 0x4fe, 
       0x3, 0x2, 0x2, 0x2, 0x4fe, 0x500, 0x3, 0x2, 0x2, 0x2, 0x4ff, 0x501, 
       0x5, 0xd0, 0x69, 0x2, 0x500, 0x4ff, 0x3, 0x2, 0x2, 0x2, 0x500, 0x501, 
       0x3, 0x2, 0x2, 0x2, 0x501, 0x502, 0x3, 0x2, 0x2, 0x2, 0x502, 0x50a, 
       0x7, 0x48, 0x2, 0x2, 0x503, 0x505, 0x7, 0xde, 0x2, 0x2, 0x504, 0x503, 
       0x3, 0x2, 0x2, 0x2, 0x505, 0x508, 0x3, 0x2, 0x2, 0x2, 0x506, 0x504, 
       0x3, 0x2, 0x2, 0x2, 0x506, 0x507, 0x3, 0x2, 0x2, 0x2, 0x507, 0x50b, 
       0x3, 0x2, 0x2, 0x2, 0x508, 0x506, 0x3, 0x2, 0x2, 0x2, 0x509, 0x50b, 
       0x7, 0x2, 0x2, 0x3, 0x50a, 0x506, 0x3, 0x2, 0x2, 0x2, 0x50a, 0x509, 
       0x3, 0x2, 0x2, 0x2, 0x50b, 0x50d, 0x3, 0x2, 0x2, 0x2, 0x50c, 0x4ea, 
       0x3, 0x2, 0x2, 0x2, 0x50c, 0x4fd, 0x3, 0x2, 0x2, 0x2, 0x50d, 0x61, 
       0x3, 0x2, 0x2, 0x2, 0x50e, 0x510, 0x7, 0xd9, 0x2, 0x2, 0x50f, 0x50e, 
       0x3, 0x2, 0x2, 0x2, 0x50f, 0x510, 0x3, 0x2, 0x2, 0x2, 0x510, 0x511, 
       0x3, 0x2, 0x2, 0x2, 0x511, 0x513, 0x7, 0x49, 0x2, 0x2, 0x512, 0x514, 
       0x5, 0xea, 0x76, 0x2, 0x513, 0x512, 0x3, 0x2, 0x2, 0x2, 0x513, 0x514, 
       0x3, 0x2, 0x2, 0x2, 0x514, 0x51c, 0x3, 0x2, 0x2, 0x2, 0x515, 0x517, 
       0x7, 0xde, 0x2, 0x2, 0x516, 0x515, 0x3, 0x2, 0x2, 0x2, 0x517, 0x51a, 
       0x3, 0x2, 0x2, 0x2, 0x518, 0x516, 0x3, 0x2, 0x2, 0x2, 0x518, 0x519, 
       0x3, 0x2, 0x2, 0x2, 0x519, 0x51d, 0x3, 0x2, 0x2, 0x2, 0x51a, 0x518, 
       0x3, 0x2, 0x2, 0x2, 0x51b, 0x51d, 0x7, 0x2, 0x2, 0x3, 0x51c, 0x518, 
       0x3, 0x2, 0x2, 0x2, 0x51c, 0x51b, 0x3, 0x2, 0x2, 0x2, 0x51d, 0x52c, 
       0x3, 0x2, 0x2, 0x2, 0x51e, 0x520, 0x7, 0xd9, 0x2, 0x2, 0x51f, 0x51e, 
       0x3, 0x2, 0x2, 0x2, 0x51f, 0x520, 0x3, 0x2, 0x2, 0x2, 0x520, 0x521, 
       0x3, 0x2, 0x2, 0x2, 0x521, 0x529, 0x7, 0x49, 0x2, 0x2, 0x522, 0x524, 
       0x7, 0xde, 0x2, 0x2, 0x523, 0x522, 0x3, 0x2, 0x2, 0x2, 0x524, 0x527, 
       0x3, 0x2, 0x2, 0x2, 0x525, 0x523, 0x3, 0x2, 0x2, 0x2, 0x525, 0x526, 
       0x3, 0x2, 0x2, 0x2, 0x526, 0x52a, 0x3, 0x2, 0x2, 0x2, 0x527, 0x525, 
       0x3, 0x2, 0x2, 0x2, 0x528, 0x52a, 0x7, 0x2, 0x2, 0x3, 0x529, 0x525, 
       0x3, 0x2, 0x2, 0x2, 0x529, 0x528, 0x3, 0x2, 0x2, 0x2, 0x52a, 0x52c, 
       0x3, 0x2, 0x2, 0x2, 0x52b, 0x50f, 0x3, 0x2, 0x2, 0x2, 0x52b, 0x51f, 
       0x3, 0x2, 0x2, 0x2, 0x52c, 0x63, 0x3, 0x2, 0x2, 0x2, 0x52d, 0x52f, 
       0x7, 0xd9, 0x2, 0x2, 0x52e, 0x52d, 0x3, 0x2, 0x2, 0x2, 0x52e, 0x52f, 
       0x3, 0x2, 0x2, 0x2, 0x52f, 0x531, 0x3, 0x2, 0x2, 0x2, 0x530, 0x532, 
       0x5, 0xd0, 0x69, 0x2, 0x531, 0x530, 0x3, 0x2, 0x2, 0x2, 0x531, 0x532, 
       0x3, 0x2, 0x2, 0x2, 0x532, 0x533, 0x3, 0x2, 0x2, 0x2, 0x533, 0x535, 
       0x7, 0x4a, 0x2, 0x2, 0x534, 0x536, 0x5, 0xea, 0x76, 0x2, 0x535, 0x534, 
       0x3, 0x2, 0x2, 0x2, 0x535, 0x536, 0x3, 0x2, 0x2, 0x2, 0x536, 0x53e, 
       0x3, 0x2, 0x2, 0x2, 0x537, 0x539, 0x7, 0xde, 0x2, 0x2, 0x538, 0x537, 
       0x3, 0x2, 0x2, 0x2, 0x539, 0x53c, 0x3, 0x2, 0x2, 0x2, 0x53a, 0x538, 
       0x3, 0x2, 0x2, 0x2, 0x53a, 0x53b, 0x3, 0x2, 0x2, 0x2, 0x53b, 0x53f, 
       0x3, 0x2, 0x2, 0x2, 0x53c, 0x53a, 0x3, 0x2, 0x2, 0x2, 0x53d, 0x53f, 
       0x7, 0x2, 0x2, 0x3, 0x53e, 0x53a, 0x3, 0x2, 0x2, 0x2, 0x53e, 0x53d, 
       0x3, 0x2, 0x2, 0x2, 0x53f, 0x551, 0x3, 0x2, 0x2, 0x2, 0x540, 0x542, 
       0x7, 0xd9, 0x2, 0x2, 0x541, 0x540, 0x3, 0x2, 0x2, 0x2, 0x541, 0x542, 
       0x3, 0x2, 0x2, 0x2, 0x542, 0x544, 0x3, 0x2, 0x2, 0x2, 0x543, 0x545, 
       0x5, 0xd0, 0x69, 0x2, 0x544, 0x543, 0x3, 0x2, 0x2, 0x2, 0x544, 0x545, 
       0x3, 0x2, 0x2, 0x2, 0x545, 0x546, 0x3, 0x2, 0x2, 0x2, 0x546, 0x54e, 
       0x7, 0x4a, 0x2, 0x2, 0x547, 0x549, 0x7, 0xde, 0x2, 0x2, 0x548, 0x547, 
       0x3, 0x2, 0x2, 0x2, 0x549, 0x54c, 0x3, 0x2, 0x2, 0x2, 0x54a, 0x548, 
       0x3, 0x2, 0x2, 0x2, 0x54a, 0x54b, 0x3, 0x2, 0x2, 0x2, 0x54b, 0x54f, 
       0x3, 0x2, 0x2, 0x2, 0x54c, 0x54a, 0x3, 0x2, 0x2, 0x2, 0x54d, 0x54f, 
       0x7, 0x2, 0x2, 0x3, 0x54e, 0x54a, 0x3, 0x2, 0x2, 0x2, 0x54e, 0x54d, 
       0x3, 0x2, 0x2, 0x2, 0x54f, 0x551, 0x3, 0x2, 0x2, 0x2, 0x550, 0x52e, 
       0x3, 0x2, 0x2, 0x2, 0x550, 0x541, 0x3, 0x2, 0x2, 0x2, 0x551, 0x65, 
       0x3, 0x2, 0x2, 0x2, 0x552, 0x554, 0x7, 0xd9, 0x2, 0x2, 0x553, 0x552, 
       0x3, 0x2, 0x2, 0x2, 0x553, 0x554, 0x3, 0x2, 0x2, 0x2, 0x554, 0x556, 
       0x3, 0x2, 0x2, 0x2, 0x555, 0x557, 0x5, 0xd0, 0x69, 0x2, 0x556, 0x555, 
       0x3, 0x2, 0x2, 0x2, 0x556, 0x557, 0x3, 0x2, 0x2, 0x2, 0x557, 0x558, 
       0x3, 0x2, 0x2, 0x2, 0x558, 0x55a, 0x7, 0x4b, 0x2, 0x2, 0x559, 0x55b, 
       0x5, 0xea, 0x76, 0x2, 0x55a, 0x559, 0x3, 0x2, 0x2, 0x2, 0x55a, 0x55b, 
       0x3, 0x2, 0x2, 0x2, 0x55b, 0x563, 0x3, 0x2, 0x2, 0x2, 0x55c, 0x55e, 
       0x7, 0xde, 0x2, 0x2, 0x55d, 0x55c, 0x3, 0x2, 0x2, 0x2, 0x55e, 0x561, 
       0x3, 0x2, 0x2, 0x2, 0x55f, 0x55d, 0x3, 0x2, 0x2, 0x2, 0x55f, 0x560, 
       0x3, 0x2, 0x2, 0x2, 0x560, 0x564, 0x3, 0x2, 0x2, 0x2, 0x561, 0x55f, 
       0x3, 0x2, 0x2, 0x2, 0x562, 0x564, 0x7, 0x2, 0x2, 0x3, 0x563, 0x55f, 
       0x3, 0x2, 0x2, 0x2, 0x563, 0x562, 0x3, 0x2, 0x2, 0x2, 0x564, 0x576, 
       0x3, 0x2, 0x2, 0x2, 0x565, 0x567, 0x7, 0xd9, 0x2, 0x2, 0x566, 0x565, 
       0x3, 0x2, 0x2, 0x2, 0x566, 0x567, 0x3, 0x2, 0x2, 0x2, 0x567, 0x569, 
       0x3, 0x2, 0x2, 0x2, 0x568, 0x56a, 0x5, 0xd0, 0x69, 0x2, 0x569, 0x568, 
       0x3, 0x2, 0x2, 0x2, 0x569, 0x56a, 0x3, 0x2, 0x2, 0x2, 0x56a, 0x56b, 
       0x3, 0x2, 0x2, 0x2, 0x56b, 0x573, 0x7, 0x4b, 0x2, 0x2, 0x56c, 0x56e, 
       0x7, 0xde, 0x2, 0x2, 0x56d, 0x56c, 0x3, 0x2, 0x2, 0x2, 0x56e, 0x571, 
       0x3, 0x2, 0x2, 0x2, 0x56f, 0x56d, 0x3, 0x2, 0x2, 0x2, 0x56f, 0x570, 
       0x3, 0x2, 0x2, 0x2, 0x570, 0x574, 0x3, 0x2, 0x2, 0x2, 0x571, 0x56f, 
       0x3, 0x2, 0x2, 0x2, 0x572, 0x574, 0x7, 0x2, 0x2, 0x3, 0x573, 0x56f, 
       0x3, 0x2, 0x2, 0x2, 0x573, 0x572, 0x3, 0x2, 0x2, 0x2, 0x574, 0x576, 
       0x3, 0x2, 0x2, 0x2, 0x575, 0x553, 0x3, 0x2, 0x2, 0x2, 0x575, 0x566, 
       0x3, 0x2, 0x2, 0x2, 0x576, 0x67, 0x3, 0x2, 0x2, 0x2, 0x577, 0x579, 
       0x7, 0x4c, 0x2, 0x2, 0x578, 0x57a, 0x5, 0x6a, 0x36, 0x2, 0x579, 0x578, 
       0x3, 0x2, 0x2, 0x2, 0x579, 0x57a, 0x3, 0x2, 0x2, 0x2, 0x57a, 0x57d, 
       0x3, 0x2, 0x2, 0x2, 0x57b, 0x57c, 0x7, 0xd9, 0x2, 0x2, 0x57c, 0x57e, 
       0x5, 0x6c, 0x37, 0x2, 0x57d, 0x57b, 0x3, 0x2, 0x2, 0x2, 0x57d, 0x57e, 
       0x3, 0x2, 0x2, 0x2, 0x57e, 0x581, 0x3, 0x2, 0x2, 0x2, 0x57f, 0x580, 
       0x7, 0xd9, 0x2, 0x2, 0x580, 0x582, 0x5, 0x6c, 0x37, 0x2, 0x581, 0x57f, 
       0x3, 0x2, 0x2, 0x2, 0x581, 0x582, 0x3, 0x2, 0x2, 0x2, 0x582, 0x58a, 
       0x3, 0x2, 0x2, 0x2, 0x583, 0x585, 0x7, 0xde, 0x2, 0x2, 0x584, 0x583, 
       0x3, 0x2, 0x2, 0x2, 0x585, 0x588, 0x3, 0x2, 0x2, 0x2, 0x586, 0x584, 
       0x3, 0x2, 0x2, 0x2, 0x586, 0x587, 0x3, 0x2, 0x2, 0x2, 0x587, 0x58b, 
       0x3, 0x2, 0x2, 0x2, 0x588, 0x586, 0x3, 0x2, 0x2, 0x2, 0x589, 0x58b, 
       0x7, 0x2, 0x2, 0x3, 0x58a, 0x586, 0x3, 0x2, 0x2, 0x2, 0x58a, 0x589, 
       0x3, 0x2, 0x2, 0x2, 0x58b, 0x69, 0x3, 0x2, 0x2, 0x2, 0x58c, 0x58e, 
       0x7, 0xc1, 0x2, 0x2, 0x58d, 0x58f, 0x5, 0xd0, 0x69, 0x2, 0x58e, 0x58d, 
       0x3, 0x2, 0x2, 0x2, 0x58f, 0x590, 0x3, 0x2, 0x2, 0x2, 0x590, 0x58e, 
       0x3, 0x2, 0x2, 0x2, 0x590, 0x591, 0x3, 0x2, 0x2, 0x2, 0x591, 0x592, 
       0x3, 0x2, 0x2, 0x2, 0x592, 0x593, 0x7, 0xc2, 0x2, 0x2, 0x593, 0x6b, 
       0x3, 0x2, 0x2, 0x2, 0x594, 0x596, 0x7, 0xc1, 0x2, 0x2, 0x595, 0x597, 
       0x5, 0xd0, 0x69, 0x2, 0x596, 0x595, 0x3, 0x2, 0x2, 0x2, 0x597, 0x598, 
       0x3, 0x2, 0x2, 0x2, 0x598, 0x596, 0x3, 0x2, 0x2, 0x2, 0x598, 0x599, 
       0x3, 0x2, 0x2, 0x2, 0x599, 0x59a, 0x3, 0x2, 0x2, 0x2, 0x59a, 0x59b, 
       0x7, 0xc2, 0x2, 0x2, 0x59b, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x59c, 0x59e, 
       0x7, 0xc1, 0x2, 0x2, 0x59d, 0x59f, 0x5, 0xd0, 0x69, 0x2, 0x59e, 0x59d, 
       0x3, 0x2, 0x2, 0x2, 0x59f, 0x5a0, 0x3, 0x2, 0x2, 0x2, 0x5a0, 0x59e, 
       0x3, 0x2, 0x2, 0x2, 0x5a0, 0x5a1, 0x3, 0x2, 0x2, 0x2, 0x5a1, 0x5a2, 
       0x3, 0x2, 0x2, 0x2, 0x5a2, 0x5a3, 0x7, 0xc2, 0x2, 0x2, 0x5a3, 0x6f, 
       0x3, 0x2, 0x2, 0x2, 0x5a4, 0x5a6, 0x5, 0x72, 0x3a, 0x2, 0x5a5, 0x5a7, 
       0x5, 0x74, 0x3b, 0x2, 0x5a6, 0x5a5, 0x3, 0x2, 0x2, 0x2, 0x5a7, 0x5a8, 
       0x3, 0x2, 0x2, 0x2, 0x5a8, 0x5a6, 0x3, 0x2, 0x2, 0x2, 0x5a8, 0x5a9, 
       0x3, 0x2, 0x2, 0x2, 0x5a9, 0x5aa, 0x3, 0x2, 0x2, 0x2, 0x5aa, 0x5ab, 
       0x5, 0x76, 0x3c, 0x2, 0x5ab, 0x5ac, 0x5, 0x78, 0x3d, 0x2, 0x5ac, 
       0x71, 0x3, 0x2, 0x2, 0x2, 0x5ad, 0x5ae, 0x7, 0xd9, 0x2, 0x2, 0x5ae, 
       0x5b2, 0x7, 0x4d, 0x2, 0x2, 0x5af, 0x5b1, 0x7, 0xde, 0x2, 0x2, 0x5b0, 
       0x5af, 0x3, 0x2, 0x2, 0x2, 0x5b1, 0x5b4, 0x3, 0x2, 0x2, 0x2, 0x5b2, 
       0x5b0, 0x3, 0x2, 0x2, 0x2, 0x5b2, 0x5b3, 0x3, 0x2, 0x2, 0x2, 0x5b3, 
       0x5b8, 0x3, 0x2, 0x2, 0x2, 0x5b4, 0x5b2, 0x3, 0x2, 0x2, 0x2, 0x5b5, 
       0x5b7, 0x5, 0xea, 0x76, 0x2, 0x5b6, 0x5b5, 0x3, 0x2, 0x2, 0x2, 0x5b7, 
       0x5ba, 0x3, 0x2, 0x2, 0x2, 0x5b8, 0x5b6, 0x3, 0x2, 0x2, 0x2, 0x5b8, 
       0x5b9, 0x3, 0x2, 0x2, 0x2, 0x5b9, 0x5bb, 0x3, 0x2, 0x2, 0x2, 0x5ba, 
       0x5b8, 0x3, 0x2, 0x2, 0x2, 0x5bb, 0x5c3, 0x7, 0xc5, 0x2, 0x2, 0x5bc, 
       0x5be, 0x7, 0xde, 0x2, 0x2, 0x5bd, 0x5bc, 0x3, 0x2, 0x2, 0x2, 0x5be, 
       0x5c1, 0x3, 0x2, 0x2, 0x2, 0x5bf, 0x5bd, 0x3, 0x2, 0x2, 0x2, 0x5bf, 
       0x5c0, 0x3, 0x2, 0x2, 0x2, 0x5c0, 0x5c4, 0x3, 0x2, 0x2, 0x2, 0x5c1, 
       0x5bf, 0x3, 0x2, 0x2, 0x2, 0x5c2, 0x5c4, 0x7, 0x2, 0x2, 0x3, 0x5c3, 
       0x5bf, 0x3, 0x2, 0x2, 0x2, 0x5c3, 0x5c2, 0x3, 0x2, 0x2, 0x2, 0x5c4, 
       0x73, 0x3, 0x2, 0x2, 0x2, 0x5c5, 0x5c6, 0x5, 0x6, 0x4, 0x2, 0x5c6, 
       0x75, 0x3, 0x2, 0x2, 0x2, 0x5c7, 0x5c8, 0x7, 0x12, 0x2, 0x2, 0x5c8, 
       0x5d0, 0x5, 0xea, 0x76, 0x2, 0x5c9, 0x5cb, 0x7, 0xde, 0x2, 0x2, 0x5ca, 
       0x5c9, 0x3, 0x2, 0x2, 0x2, 0x5cb, 0x5ce, 0x3, 0x2, 0x2, 0x2, 0x5cc, 
       0x5ca, 0x3, 0x2, 0x2, 0x2, 0x5cc, 0x5cd, 0x3, 0x2, 0x2, 0x2, 0x5cd, 
       0x5d1, 0x3, 0x2, 0x2, 0x2, 0x5ce, 0x5cc, 0x3, 0x2, 0x2, 0x2, 0x5cf, 
       0x5d1, 0x7, 0x2, 0x2, 0x3, 0x5d0, 0x5cc, 0x3, 0x2, 0x2, 0x2, 0x5d0, 
       0x5cf, 0x3, 0x2, 0x2, 0x2, 0x5d1, 0x77, 0x3, 0x2, 0x2, 0x2, 0x5d2, 
       0x5da, 0x7, 0xc6, 0x2, 0x2, 0x5d3, 0x5d5, 0x7, 0xde, 0x2, 0x2, 0x5d4, 
       0x5d3, 0x3, 0x2, 0x2, 0x2, 0x5d5, 0x5d8, 0x3, 0x2, 0x2, 0x2, 0x5d6, 
       0x5d4, 0x3, 0x2, 0x2, 0x2, 0x5d6, 0x5d7, 0x3, 0x2, 0x2, 0x2, 0x5d7, 
       0x5db, 0x3, 0x2, 0x2, 0x2, 0x5d8, 0x5d6, 0x3, 0x2, 0x2, 0x2, 0x5d9, 
       0x5db, 0x7, 0x2, 0x2, 0x3, 0x5da, 0x5d6, 0x3, 0x2, 0x2, 0x2, 0x5da, 
       0x5d9, 0x3, 0x2, 0x2, 0x2, 0x5db, 0x79, 0x3, 0x2, 0x2, 0x2, 0x5dc, 
       0x5de, 0x7, 0xd9, 0x2, 0x2, 0x5dd, 0x5df, 0x5, 0xd0, 0x69, 0x2, 0x5de, 
       0x5dd, 0x3, 0x2, 0x2, 0x2, 0x5de, 0x5df, 0x3, 0x2, 0x2, 0x2, 0x5df, 
       0x5e0, 0x3, 0x2, 0x2, 0x2, 0x5e0, 0x5e2, 0x7, 0x4e, 0x2, 0x2, 0x5e1, 
       0x5e3, 0x5, 0xea, 0x76, 0x2, 0x5e2, 0x5e1, 0x3, 0x2, 0x2, 0x2, 0x5e2, 
       0x5e3, 0x3, 0x2, 0x2, 0x2, 0x5e3, 0x5eb, 0x3, 0x2, 0x2, 0x2, 0x5e4, 
       0x5e6, 0x7, 0xde, 0x2, 0x2, 0x5e5, 0x5e4, 0x3, 0x2, 0x2, 0x2, 0x5e6, 
       0x5e9, 0x3, 0x2, 0x2, 0x2, 0x5e7, 0x5e5, 0x3, 0x2, 0x2, 0x2, 0x5e7, 
       0x5e8, 0x3, 0x2, 0x2, 0x2, 0x5e8, 0x5ec, 0x3, 0x2, 0x2, 0x2, 0x5e9, 
       0x5e7, 0x3, 0x2, 0x2, 0x2, 0x5ea, 0x5ec, 0x7, 0x2, 0x2, 0x3, 0x5eb, 
       0x5e7, 0x3, 0x2, 0x2, 0x2, 0x5eb, 0x5ea, 0x3, 0x2, 0x2, 0x2, 0x5ec, 
       0x5fc, 0x3, 0x2, 0x2, 0x2, 0x5ed, 0x5ef, 0x7, 0xd9, 0x2, 0x2, 0x5ee, 
       0x5f0, 0x5, 0xd0, 0x69, 0x2, 0x5ef, 0x5ee, 0x3, 0x2, 0x2, 0x2, 0x5ef, 
       0x5f0, 0x3, 0x2, 0x2, 0x2, 0x5f0, 0x5f1, 0x3, 0x2, 0x2, 0x2, 0x5f1, 
       0x5f9, 0x7, 0x4e, 0x2, 0x2, 0x5f2, 0x5f4, 0x7, 0xde, 0x2, 0x2, 0x5f3, 
       0x5f2, 0x3, 0x2, 0x2, 0x2, 0x5f4, 0x5f7, 0x3, 0x2, 0x2, 0x2, 0x5f5, 
       0x5f3, 0x3, 0x2, 0x2, 0x2, 0x5f5, 0x5f6, 0x3, 0x2, 0x2, 0x2, 0x5f6, 
       0x5fa, 0x3, 0x2, 0x2, 0x2, 0x5f7, 0x5f5, 0x3, 0x2, 0x2, 0x2, 0x5f8, 
       0x5fa, 0x7, 0x2, 0x2, 0x3, 0x5f9, 0x5f5, 0x3, 0x2, 0x2, 0x2, 0x5f9, 
       0x5f8, 0x3, 0x2, 0x2, 0x2, 0x5fa, 0x5fc, 0x3, 0x2, 0x2, 0x2, 0x5fb, 
       0x5dc, 0x3, 0x2, 0x2, 0x2, 0x5fb, 0x5ed, 0x3, 0x2, 0x2, 0x2, 0x5fc, 
       0x7b, 0x3, 0x2, 0x2, 0x2, 0x5fd, 0x5fe, 0x7, 0xd9, 0x2, 0x2, 0x5fe, 
       0x600, 0x7, 0x4f, 0x2, 0x2, 0x5ff, 0x601, 0x5, 0xea, 0x76, 0x2, 0x600, 
       0x5ff, 0x3, 0x2, 0x2, 0x2, 0x600, 0x601, 0x3, 0x2, 0x2, 0x2, 0x601, 
       0x609, 0x3, 0x2, 0x2, 0x2, 0x602, 0x604, 0x7, 0xde, 0x2, 0x2, 0x603, 
       0x602, 0x3, 0x2, 0x2, 0x2, 0x604, 0x607, 0x3, 0x2, 0x2, 0x2, 0x605, 
       0x603, 0x3, 0x2, 0x2, 0x2, 0x605, 0x606, 0x3, 0x2, 0x2, 0x2, 0x606, 
       0x60a, 0x3, 0x2, 0x2, 0x2, 0x607, 0x605, 0x3, 0x2, 0x2, 0x2, 0x608, 
       0x60a, 0x7, 0x2, 0x2, 0x3, 0x609, 0x605, 0x3, 0x2, 0x2, 0x2, 0x609, 
       0x608, 0x3, 0x2, 0x2, 0x2, 0x60a, 0x617, 0x3, 0x2, 0x2, 0x2, 0x60b, 
       0x60c, 0x7, 0xd9, 0x2, 0x2, 0x60c, 0x614, 0x7, 0x4f, 0x2, 0x2, 0x60d, 
       0x60f, 0x7, 0xde, 0x2, 0x2, 0x60e, 0x60d, 0x3, 0x2, 0x2, 0x2, 0x60f, 
       0x612, 0x3, 0x2, 0x2, 0x2, 0x610, 0x60e, 0x3, 0x2, 0x2, 0x2, 0x610, 
       0x611, 0x3, 0x2, 0x2, 0x2, 0x611, 0x615, 0x3, 0x2, 0x2, 0x2, 0x612, 
       0x610, 0x3, 0x2, 0x2, 0x2, 0x613, 0x615, 0x7, 0x2, 0x2, 0x3, 0x614, 
       0x610, 0x3, 0x2, 0x2, 0x2, 0x614, 0x613, 0x3, 0x2, 0x2, 0x2, 0x615, 
       0x617, 0x3, 0x2, 0x2, 0x2, 0x616, 0x5fd, 0x3, 0x2, 0x2, 0x2, 0x616, 
       0x60b, 0x3, 0x2, 0x2, 0x2, 0x617, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x618, 
       0x619, 0x7, 0x5, 0x2, 0x2, 0x619, 0x621, 0x5, 0xd0, 0x69, 0x2, 0x61a, 
       0x61c, 0x7, 0xde, 0x2, 0x2, 0x61b, 0x61a, 0x3, 0x2, 0x2, 0x2, 0x61c, 
       0x61f, 0x3, 0x2, 0x2, 0x2, 0x61d, 0x61b, 0x3, 0x2, 0x2, 0x2, 0x61d, 
       0x61e, 0x3, 0x2, 0x2, 0x2, 0x61e, 0x622, 0x3, 0x2, 0x2, 0x2, 0x61f, 
       0x61d, 0x3, 0x2, 0x2, 0x2, 0x620, 0x622, 0x7, 0x2, 0x2, 0x3, 0x621, 
       0x61d, 0x3, 0x2, 0x2, 0x2, 0x621, 0x620, 0x3, 0x2, 0x2, 0x2, 0x622, 
       0x7f, 0x3, 0x2, 0x2, 0x2, 0x623, 0x624, 0x7, 0x11, 0x2, 0x2, 0x624, 
       0x625, 0x5, 0x82, 0x42, 0x2, 0x625, 0x629, 0x5, 0x84, 0x43, 0x2, 
       0x626, 0x628, 0x5, 0xf2, 0x7a, 0x2, 0x627, 0x626, 0x3, 0x2, 0x2, 
       0x2, 0x628, 0x62b, 0x3, 0x2, 0x2, 0x2, 0x629, 0x627, 0x3, 0x2, 0x2, 
       0x2, 0x629, 0x62a, 0x3, 0x2, 0x2, 0x2, 0x62a, 0x633, 0x3, 0x2, 0x2, 
       0x2, 0x62b, 0x629, 0x3, 0x2, 0x2, 0x2, 0x62c, 0x62e, 0x7, 0xde, 0x2, 
       0x2, 0x62d, 0x62c, 0x3, 0x2, 0x2, 0x2, 0x62e, 0x631, 0x3, 0x2, 0x2, 
       0x2, 0x62f, 0x62d, 0x3, 0x2, 0x2, 0x2, 0x62f, 0x630, 0x3, 0x2, 0x2, 
       0x2, 0x630, 0x634, 0x3, 0x2, 0x2, 0x2, 0x631, 0x62f, 0x3, 0x2, 0x2, 
       0x2, 0x632, 0x634, 0x7, 0x2, 0x2, 0x3, 0x633, 0x62f, 0x3, 0x2, 0x2, 
       0x2, 0x633, 0x632, 0x3, 0x2, 0x2, 0x2, 0x634, 0x81, 0x3, 0x2, 0x2, 
       0x2, 0x635, 0x636, 0x7, 0xd9, 0x2, 0x2, 0x636, 0x83, 0x3, 0x2, 0x2, 
       0x2, 0x637, 0x63a, 0x7, 0xd9, 0x2, 0x2, 0x638, 0x63a, 0x5, 0x108, 
       0x85, 0x2, 0x639, 0x637, 0x3, 0x2, 0x2, 0x2, 0x639, 0x638, 0x3, 0x2, 
       0x2, 0x2, 0x63a, 0x85, 0x3, 0x2, 0x2, 0x2, 0x63b, 0x647, 0x5, 0x88, 
       0x45, 0x2, 0x63c, 0x647, 0x5, 0x8a, 0x46, 0x2, 0x63d, 0x647, 0x5, 
       0x92, 0x4a, 0x2, 0x63e, 0x647, 0x5, 0x94, 0x4b, 0x2, 0x63f, 0x647, 
       0x5, 0x96, 0x4c, 0x2, 0x640, 0x647, 0x5, 0x98, 0x4d, 0x2, 0x641, 
       0x647, 0x5, 0x9a, 0x4e, 0x2, 0x642, 0x647, 0x5, 0x9c, 0x4f, 0x2, 
       0x643, 0x647, 0x5, 0x9e, 0x50, 0x2, 0x644, 0x647, 0x5, 0xa0, 0x51, 
       0x2, 0x645, 0x647, 0x5, 0xa2, 0x52, 0x2, 0x646, 0x63b, 0x3, 0x2, 
       0x2, 0x2, 0x646, 0x63c, 0x3, 0x2, 0x2, 0x2, 0x646, 0x63d, 0x3, 0x2, 
       0x2, 0x2, 0x646, 0x63e, 0x3, 0x2, 0x2, 0x2, 0x646, 0x63f, 0x3, 0x2, 
       0x2, 0x2, 0x646, 0x640, 0x3, 0x2, 0x2, 0x2, 0x646, 0x641, 0x3, 0x2, 
       0x2, 0x2, 0x646, 0x642, 0x3, 0x2, 0x2, 0x2, 0x646, 0x643, 0x3, 0x2, 
       0x2, 0x2, 0x646, 0x644, 0x3, 0x2, 0x2, 0x2, 0x646, 0x645, 0x3, 0x2, 
       0x2, 0x2, 0x647, 0x87, 0x3, 0x2, 0x2, 0x2, 0x648, 0x649, 0x7, 0xd9, 
       0x2, 0x2, 0x649, 0x64a, 0x7, 0x14, 0x2, 0x2, 0x64a, 0x652, 0x5, 0xea, 
       0x76, 0x2, 0x64b, 0x64d, 0x7, 0xde, 0x2, 0x2, 0x64c, 0x64b, 0x3, 
       0x2, 0x2, 0x2, 0x64d, 0x650, 0x3, 0x2, 0x2, 0x2, 0x64e, 0x64c, 0x3, 
       0x2, 0x2, 0x2, 0x64e, 0x64f, 0x3, 0x2, 0x2, 0x2, 0x64f, 0x653, 0x3, 
       0x2, 0x2, 0x2, 0x650, 0x64e, 0x3, 0x2, 0x2, 0x2, 0x651, 0x653, 0x7, 
       0x2, 0x2, 0x3, 0x652, 0x64e, 0x3, 0x2, 0x2, 0x2, 0x652, 0x651, 0x3, 
       0x2, 0x2, 0x2, 0x653, 0x660, 0x3, 0x2, 0x2, 0x2, 0x654, 0x655, 0x7, 
       0xd9, 0x2, 0x2, 0x655, 0x65d, 0x7, 0x14, 0x2, 0x2, 0x656, 0x658, 
       0x7, 0xde, 0x2, 0x2, 0x657, 0x656, 0x3, 0x2, 0x2, 0x2, 0x658, 0x65b, 
       0x3, 0x2, 0x2, 0x2, 0x659, 0x657, 0x3, 0x2, 0x2, 0x2, 0x659, 0x65a, 
       0x3, 0x2, 0x2, 0x2, 0x65a, 0x65e, 0x3, 0x2, 0x2, 0x2, 0x65b, 0x659, 
       0x3, 0x2, 0x2, 0x2, 0x65c, 0x65e, 0x7, 0x2, 0x2, 0x3, 0x65d, 0x659, 
       0x3, 0x2, 0x2, 0x2, 0x65d, 0x65c, 0x3, 0x2, 0x2, 0x2, 0x65e, 0x660, 
       0x3, 0x2, 0x2, 0x2, 0x65f, 0x648, 0x3, 0x2, 0x2, 0x2, 0x65f, 0x654, 
       0x3, 0x2, 0x2, 0x2, 0x660, 0x89, 0x3, 0x2, 0x2, 0x2, 0x661, 0x662, 
       0x5, 0x8c, 0x47, 0x2, 0x662, 0x664, 0x5, 0xc0, 0x61, 0x2, 0x663, 
       0x665, 0x5, 0x8e, 0x48, 0x2, 0x664, 0x663, 0x3, 0x2, 0x2, 0x2, 0x665, 
       0x666, 0x3, 0x2, 0x2, 0x2, 0x666, 0x664, 0x3, 0x2, 0x2, 0x2, 0x666, 
       0x667, 0x3, 0x2, 0x2, 0x2, 0x667, 0x668, 0x3, 0x2, 0x2, 0x2, 0x668, 
       0x669, 0x5, 0x90, 0x49, 0x2, 0x669, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x66a, 
       0x66b, 0x7, 0xd9, 0x2, 0x2, 0x66b, 0x66f, 0x7, 0x15, 0x2, 0x2, 0x66c, 
       0x66e, 0x7, 0xde, 0x2, 0x2, 0x66d, 0x66c, 0x3, 0x2, 0x2, 0x2, 0x66e, 
       0x671, 0x3, 0x2, 0x2, 0x2, 0x66f, 0x66d, 0x3, 0x2, 0x2, 0x2, 0x66f, 
       0x670, 0x3, 0x2, 0x2, 0x2, 0x670, 0x672, 0x3, 0x2, 0x2, 0x2, 0x671, 
       0x66f, 0x3, 0x2, 0x2, 0x2, 0x672, 0x67a, 0x7, 0xc5, 0x2, 0x2, 0x673, 
       0x675, 0x7, 0xde, 0x2, 0x2, 0x674, 0x673, 0x3, 0x2, 0x2, 0x2, 0x675, 
       0x678, 0x3, 0x2, 0x2, 0x2, 0x676, 0x674, 0x3, 0x2, 0x2, 0x2, 0x676, 
       0x677, 0x3, 0x2, 0x2, 0x2, 0x677, 0x67b, 0x3, 0x2, 0x2, 0x2, 0x678, 
       0x676, 0x3, 0x2, 0x2, 0x2, 0x679, 0x67b, 0x7, 0x2, 0x2, 0x3, 0x67a, 
       0x676, 0x3, 0x2, 0x2, 0x2, 0x67a, 0x679, 0x3, 0x2, 0x2, 0x2, 0x67b, 
       0x8d, 0x3, 0x2, 0x2, 0x2, 0x67c, 0x67d, 0x5, 0x6, 0x4, 0x2, 0x67d, 
       0x8f, 0x3, 0x2, 0x2, 0x2, 0x67e, 0x686, 0x7, 0xc6, 0x2, 0x2, 0x67f, 
       0x681, 0x7, 0xde, 0x2, 0x2, 0x680, 0x67f, 0x3, 0x2, 0x2, 0x2, 0x681, 
       0x684, 0x3, 0x2, 0x2, 0x2, 0x682, 0x680, 0x3, 0x2, 0x2, 0x2, 0x682, 
       0x683, 0x3, 0x2, 0x2, 0x2, 0x683, 0x687, 0x3, 0x2, 0x2, 0x2, 0x684, 
       0x682, 0x3, 0x2, 0x2, 0x2, 0x685, 0x687, 0x7, 0x2, 0x2, 0x3, 0x686, 
       0x682, 0x3, 0x2, 0x2, 0x2, 0x686, 0x685, 0x3, 0x2, 0x2, 0x2, 0x687, 
       0x91, 0x3, 0x2, 0x2, 0x2, 0x688, 0x689, 0x7, 0xd9, 0x2, 0x2, 0x689, 
       0x68a, 0x7, 0x1c, 0x2, 0x2, 0x68a, 0x68b, 0x5, 0xf2, 0x7a, 0x2, 0x68b, 
       0x693, 0x5, 0xea, 0x76, 0x2, 0x68c, 0x68e, 0x7, 0xde, 0x2, 0x2, 0x68d, 
       0x68c, 0x3, 0x2, 0x2, 0x2, 0x68e, 0x691, 0x3, 0x2, 0x2, 0x2, 0x68f, 
       0x68d, 0x3, 0x2, 0x2, 0x2, 0x68f, 0x690, 0x3, 0x2, 0x2, 0x2, 0x690, 
       0x694, 0x3, 0x2, 0x2, 0x2, 0x691, 0x68f, 0x3, 0x2, 0x2, 0x2, 0x692, 
       0x694, 0x7, 0x2, 0x2, 0x3, 0x693, 0x68f, 0x3, 0x2, 0x2, 0x2, 0x693, 
       0x692, 0x3, 0x2, 0x2, 0x2, 0x694, 0x6a2, 0x3, 0x2, 0x2, 0x2, 0x695, 
       0x696, 0x7, 0xd9, 0x2, 0x2, 0x696, 0x697, 0x7, 0x1c, 0x2, 0x2, 0x697, 
       0x69f, 0x5, 0xf2, 0x7a, 0x2, 0x698, 0x69a, 0x7, 0xde, 0x2, 0x2, 0x699, 
       0x698, 0x3, 0x2, 0x2, 0x2, 0x69a, 0x69d, 0x3, 0x2, 0x2, 0x2, 0x69b, 
       0x699, 0x3, 0x2, 0x2, 0x2, 0x69b, 0x69c, 0x3, 0x2, 0x2, 0x2, 0x69c, 
       0x6a0, 0x3, 0x2, 0x2, 0x2, 0x69d, 0x69b, 0x3, 0x2, 0x2, 0x2, 0x69e, 
       0x6a0, 0x7, 0x2, 0x2, 0x3, 0x69f, 0x69b, 0x3, 0x2, 0x2, 0x2, 0x69f, 
       0x69e, 0x3, 0x2, 0x2, 0x2, 0x6a0, 0x6a2, 0x3, 0x2, 0x2, 0x2, 0x6a1, 
       0x688, 0x3, 0x2, 0x2, 0x2, 0x6a1, 0x695, 0x3, 0x2, 0x2, 0x2, 0x6a2, 
       0x93, 0x3, 0x2, 0x2, 0x2, 0x6a3, 0x6a4, 0x7, 0xd9, 0x2, 0x2, 0x6a4, 
       0x6a5, 0x7, 0x1d, 0x2, 0x2, 0x6a5, 0x6ad, 0x5, 0xf2, 0x7a, 0x2, 0x6a6, 
       0x6a8, 0x7, 0xde, 0x2, 0x2, 0x6a7, 0x6a6, 0x3, 0x2, 0x2, 0x2, 0x6a8, 
       0x6ab, 0x3, 0x2, 0x2, 0x2, 0x6a9, 0x6a7, 0x3, 0x2, 0x2, 0x2, 0x6a9, 
       0x6aa, 0x3, 0x2, 0x2, 0x2, 0x6aa, 0x6ae, 0x3, 0x2, 0x2, 0x2, 0x6ab, 
       0x6a9, 0x3, 0x2, 0x2, 0x2, 0x6ac, 0x6ae, 0x7, 0x2, 0x2, 0x3, 0x6ad, 
       0x6a9, 0x3, 0x2, 0x2, 0x2, 0x6ad, 0x6ac, 0x3, 0x2, 0x2, 0x2, 0x6ae, 
       0x95, 0x3, 0x2, 0x2, 0x2, 0x6af, 0x6b0, 0x7, 0x13, 0x2, 0x2, 0x6b0, 
       0x6b1, 0x7, 0xd9, 0x2, 0x2, 0x6b1, 0x6b9, 0x5, 0xea, 0x76, 0x2, 0x6b2, 
       0x6b4, 0x7, 0xde, 0x2, 0x2, 0x6b3, 0x6b2, 0x3, 0x2, 0x2, 0x2, 0x6b4, 
       0x6b7, 0x3, 0x2, 0x2, 0x2, 0x6b5, 0x6b3, 0x3, 0x2, 0x2, 0x2, 0x6b5, 
       0x6b6, 0x3, 0x2, 0x2, 0x2, 0x6b6, 0x6ba, 0x3, 0x2, 0x2, 0x2, 0x6b7, 
       0x6b5, 0x3, 0x2, 0x2, 0x2, 0x6b8, 0x6ba, 0x7, 0x2, 0x2, 0x3, 0x6b9, 
       0x6b5, 0x3, 0x2, 0x2, 0x2, 0x6b9, 0x6b8, 0x3, 0x2, 0x2, 0x2, 0x6ba, 
       0x6c7, 0x3, 0x2, 0x2, 0x2, 0x6bb, 0x6bc, 0x7, 0x13, 0x2, 0x2, 0x6bc, 
       0x6c4, 0x7, 0xd9, 0x2, 0x2, 0x6bd, 0x6bf, 0x7, 0xde, 0x2, 0x2, 0x6be, 
       0x6bd, 0x3, 0x2, 0x2, 0x2, 0x6bf, 0x6c2, 0x3, 0x2, 0x2, 0x2, 0x6c0, 
       0x6be, 0x3, 0x2, 0x2, 0x2, 0x6c0, 0x6c1, 0x3, 0x2, 0x2, 0x2, 0x6c1, 
       0x6c5, 0x3, 0x2, 0x2, 0x2, 0x6c2, 0x6c0, 0x3, 0x2, 0x2, 0x2, 0x6c3, 
       0x6c5, 0x7, 0x2, 0x2, 0x3, 0x6c4, 0x6c0, 0x3, 0x2, 0x2, 0x2, 0x6c4, 
       0x6c3, 0x3, 0x2, 0x2, 0x2, 0x6c5, 0x6c7, 0x3, 0x2, 0x2, 0x2, 0x6c6, 
       0x6af, 0x3, 0x2, 0x2, 0x2, 0x6c6, 0x6bb, 0x3, 0x2, 0x2, 0x2, 0x6c7, 
       0x97, 0x3, 0x2, 0x2, 0x2, 0x6c8, 0x6c9, 0x7, 0xd9, 0x2, 0x2, 0x6c9, 
       0x6ca, 0x7, 0x16, 0x2, 0x2, 0x6ca, 0x6d2, 0x5, 0xea, 0x76, 0x2, 0x6cb, 
       0x6cd, 0x7, 0xde, 0x2, 0x2, 0x6cc, 0x6cb, 0x3, 0x2, 0x2, 0x2, 0x6cd, 
       0x6d0, 0x3, 0x2, 0x2, 0x2, 0x6ce, 0x6cc, 0x3, 0x2, 0x2, 0x2, 0x6ce, 
       0x6cf, 0x3, 0x2, 0x2, 0x2, 0x6cf, 0x6d3, 0x3, 0x2, 0x2, 0x2, 0x6d0, 
       0x6ce, 0x3, 0x2, 0x2, 0x2, 0x6d1, 0x6d3, 0x7, 0x2, 0x2, 0x3, 0x6d2, 
       0x6ce, 0x3, 0x2, 0x2, 0x2, 0x6d2, 0x6d1, 0x3, 0x2, 0x2, 0x2, 0x6d3, 
       0x6e0, 0x3, 0x2, 0x2, 0x2, 0x6d4, 0x6d5, 0x7, 0xd9, 0x2, 0x2, 0x6d5, 
       0x6dd, 0x7, 0x16, 0x2, 0x2, 0x6d6, 0x6d8, 0x7, 0xde, 0x2, 0x2, 0x6d7, 
       0x6d6, 0x3, 0x2, 0x2, 0x2, 0x6d8, 0x6db, 0x3, 0x2, 0x2, 0x2, 0x6d9, 
       0x6d7, 0x3, 0x2, 0x2, 0x2, 0x6d9, 0x6da, 0x3, 0x2, 0x2, 0x2, 0x6da, 
       0x6de, 0x3, 0x2, 0x2, 0x2, 0x6db, 0x6d9, 0x3, 0x2, 0x2, 0x2, 0x6dc, 
       0x6de, 0x7, 0x2, 0x2, 0x3, 0x6dd, 0x6d9, 0x3, 0x2, 0x2, 0x2, 0x6dd, 
       0x6dc, 0x3, 0x2, 0x2, 0x2, 0x6de, 0x6e0, 0x3, 0x2, 0x2, 0x2, 0x6df, 
       0x6c8, 0x3, 0x2, 0x2, 0x2, 0x6df, 0x6d4, 0x3, 0x2, 0x2, 0x2, 0x6e0, 
       0x99, 0x3, 0x2, 0x2, 0x2, 0x6e1, 0x6e2, 0x7, 0xd9, 0x2, 0x2, 0x6e2, 
       0x6e3, 0x7, 0x17, 0x2, 0x2, 0x6e3, 0x6eb, 0x5, 0xea, 0x76, 0x2, 0x6e4, 
       0x6e6, 0x7, 0xde, 0x2, 0x2, 0x6e5, 0x6e4, 0x3, 0x2, 0x2, 0x2, 0x6e6, 
       0x6e9, 0x3, 0x2, 0x2, 0x2, 0x6e7, 0x6e5, 0x3, 0x2, 0x2, 0x2, 0x6e7, 
       0x6e8, 0x3, 0x2, 0x2, 0x2, 0x6e8, 0x6ec, 0x3, 0x2, 0x2, 0x2, 0x6e9, 
       0x6e7, 0x3, 0x2, 0x2, 0x2, 0x6ea, 0x6ec, 0x7, 0x2, 0x2, 0x3, 0x6eb, 
       0x6e7, 0x3, 0x2, 0x2, 0x2, 0x6eb, 0x6ea, 0x3, 0x2, 0x2, 0x2, 0x6ec, 
       0x6f9, 0x3, 0x2, 0x2, 0x2, 0x6ed, 0x6ee, 0x7, 0xd9, 0x2, 0x2, 0x6ee, 
       0x6f6, 0x7, 0x17, 0x2, 0x2, 0x6ef, 0x6f1, 0x7, 0xde, 0x2, 0x2, 0x6f0, 
       0x6ef, 0x3, 0x2, 0x2, 0x2, 0x6f1, 0x6f4, 0x3, 0x2, 0x2, 0x2, 0x6f2, 
       0x6f0, 0x3, 0x2, 0x2, 0x2, 0x6f2, 0x6f3, 0x3, 0x2, 0x2, 0x2, 0x6f3, 
       0x6f7, 0x3, 0x2, 0x2, 0x2, 0x6f4, 0x6f2, 0x3, 0x2, 0x2, 0x2, 0x6f5, 
       0x6f7, 0x7, 0x2, 0x2, 0x3, 0x6f6, 0x6f2, 0x3, 0x2, 0x2, 0x2, 0x6f6, 
       0x6f5, 0x3, 0x2, 0x2, 0x2, 0x6f7, 0x6f9, 0x3, 0x2, 0x2, 0x2, 0x6f8, 
       0x6e1, 0x3, 0x2, 0x2, 0x2, 0x6f8, 0x6ed, 0x3, 0x2, 0x2, 0x2, 0x6f9, 
       0x9b, 0x3, 0x2, 0x2, 0x2, 0x6fa, 0x6fb, 0x7, 0xd9, 0x2, 0x2, 0x6fb, 
       0x6fc, 0x7, 0x18, 0x2, 0x2, 0x6fc, 0x704, 0x5, 0xea, 0x76, 0x2, 0x6fd, 
       0x6ff, 0x7, 0xde, 0x2, 0x2, 0x6fe, 0x6fd, 0x3, 0x2, 0x2, 0x2, 0x6ff, 
       0x702, 0x3, 0x2, 0x2, 0x2, 0x700, 0x6fe, 0x3, 0x2, 0x2, 0x2, 0x700, 
       0x701, 0x3, 0x2, 0x2, 0x2, 0x701, 0x705, 0x3, 0x2, 0x2, 0x2, 0x702, 
       0x700, 0x3, 0x2, 0x2, 0x2, 0x703, 0x705, 0x7, 0x2, 0x2, 0x3, 0x704, 
       0x700, 0x3, 0x2, 0x2, 0x2, 0x704, 0x703, 0x3, 0x2, 0x2, 0x2, 0x705, 
       0x712, 0x3, 0x2, 0x2, 0x2, 0x706, 0x707, 0x7, 0xd9, 0x2, 0x2, 0x707, 
       0x70f, 0x7, 0x18, 0x2, 0x2, 0x708, 0x70a, 0x7, 0xde, 0x2, 0x2, 0x709, 
       0x708, 0x3, 0x2, 0x2, 0x2, 0x70a, 0x70d, 0x3, 0x2, 0x2, 0x2, 0x70b, 
       0x709, 0x3, 0x2, 0x2, 0x2, 0x70b, 0x70c, 0x3, 0x2, 0x2, 0x2, 0x70c, 
       0x710, 0x3, 0x2, 0x2, 0x2, 0x70d, 0x70b, 0x3, 0x2, 0x2, 0x2, 0x70e, 
       0x710, 0x7, 0x2, 0x2, 0x3, 0x70f, 0x70b, 0x3, 0x2, 0x2, 0x2, 0x70f, 
       0x70e, 0x3, 0x2, 0x2, 0x2, 0x710, 0x712, 0x3, 0x2, 0x2, 0x2, 0x711, 
       0x6fa, 0x3, 0x2, 0x2, 0x2, 0x711, 0x706, 0x3, 0x2, 0x2, 0x2, 0x712, 
       0x9d, 0x3, 0x2, 0x2, 0x2, 0x713, 0x714, 0x7, 0xd9, 0x2, 0x2, 0x714, 
       0x715, 0x7, 0x19, 0x2, 0x2, 0x715, 0x71d, 0x5, 0xea, 0x76, 0x2, 0x716, 
       0x718, 0x7, 0xde, 0x2, 0x2, 0x717, 0x716, 0x3, 0x2, 0x2, 0x2, 0x718, 
       0x71b, 0x3, 0x2, 0x2, 0x2, 0x719, 0x717, 0x3, 0x2, 0x2, 0x2, 0x719, 
       0x71a, 0x3, 0x2, 0x2, 0x2, 0x71a, 0x71e, 0x3, 0x2, 0x2, 0x2, 0x71b, 
       0x719, 0x3, 0x2, 0x2, 0x2, 0x71c, 0x71e, 0x7, 0x2, 0x2, 0x3, 0x71d, 
       0x719, 0x3, 0x2, 0x2, 0x2, 0x71d, 0x71c, 0x3, 0x2, 0x2, 0x2, 0x71e, 
       0x72b, 0x3, 0x2, 0x2, 0x2, 0x71f, 0x720, 0x7, 0xd9, 0x2, 0x2, 0x720, 
       0x728, 0x7, 0x19, 0x2, 0x2, 0x721, 0x723, 0x7, 0xde, 0x2, 0x2, 0x722, 
       0x721, 0x3, 0x2, 0x2, 0x2, 0x723, 0x726, 0x3, 0x2, 0x2, 0x2, 0x724, 
       0x722, 0x3, 0x2, 0x2, 0x2, 0x724, 0x725, 0x3, 0x2, 0x2, 0x2, 0x725, 
       0x729, 0x3, 0x2, 0x2, 0x2, 0x726, 0x724, 0x3, 0x2, 0x2, 0x2, 0x727, 
       0x729, 0x7, 0x2, 0x2, 0x3, 0x728, 0x724, 0x3, 0x2, 0x2, 0x2, 0x728, 
       0x727, 0x3, 0x2, 0x2, 0x2, 0x729, 0x72b, 0x3, 0x2, 0x2, 0x2, 0x72a, 
       0x713, 0x3, 0x2, 0x2, 0x2, 0x72a, 0x71f, 0x3, 0x2, 0x2, 0x2, 0x72b, 
       0x9f, 0x3, 0x2, 0x2, 0x2, 0x72c, 0x72e, 0x7, 0x1a, 0x2, 0x2, 0x72d, 
       0x72f, 0x5, 0xf6, 0x7c, 0x2, 0x72e, 0x72d, 0x3, 0x2, 0x2, 0x2, 0x72e, 
       0x72f, 0x3, 0x2, 0x2, 0x2, 0x72f, 0x730, 0x3, 0x2, 0x2, 0x2, 0x730, 
       0x731, 0x7, 0xaa, 0x2, 0x2, 0x731, 0x739, 0x5, 0xdc, 0x6f, 0x2, 0x732, 
       0x734, 0x7, 0xde, 0x2, 0x2, 0x733, 0x732, 0x3, 0x2, 0x2, 0x2, 0x734, 
       0x737, 0x3, 0x2, 0x2, 0x2, 0x735, 0x733, 0x3, 0x2, 0x2, 0x2, 0x735, 
       0x736, 0x3, 0x2, 0x2, 0x2, 0x736, 0x73a, 0x3, 0x2, 0x2, 0x2, 0x737, 
       0x735, 0x3, 0x2, 0x2, 0x2, 0x738, 0x73a, 0x7, 0x2, 0x2, 0x3, 0x739, 
       0x735, 0x3, 0x2, 0x2, 0x2, 0x739, 0x738, 0x3, 0x2, 0x2, 0x2, 0x73a, 
       0xa1, 0x3, 0x2, 0x2, 0x2, 0x73b, 0x73c, 0x7, 0x1b, 0x2, 0x2, 0x73c, 
       0x744, 0x5, 0xea, 0x76, 0x2, 0x73d, 0x73f, 0x7, 0xde, 0x2, 0x2, 0x73e, 
       0x73d, 0x3, 0x2, 0x2, 0x2, 0x73f, 0x742, 0x3, 0x2, 0x2, 0x2, 0x740, 
       0x73e, 0x3, 0x2, 0x2, 0x2, 0x740, 0x741, 0x3, 0x2, 0x2, 0x2, 0x741, 
       0x745, 0x3, 0x2, 0x2, 0x2, 0x742, 0x740, 0x3, 0x2, 0x2, 0x2, 0x743, 
       0x745, 0x7, 0x2, 0x2, 0x3, 0x744, 0x740, 0x3, 0x2, 0x2, 0x2, 0x744, 
       0x743, 0x3, 0x2, 0x2, 0x2, 0x745, 0x751, 0x3, 0x2, 0x2, 0x2, 0x746, 
       0x74e, 0x7, 0x1b, 0x2, 0x2, 0x747, 0x749, 0x7, 0xde, 0x2, 0x2, 0x748, 
       0x747, 0x3, 0x2, 0x2, 0x2, 0x749, 0x74c, 0x3, 0x2, 0x2, 0x2, 0x74a, 
       0x748, 0x3, 0x2, 0x2, 0x2, 0x74a, 0x74b, 0x3, 0x2, 0x2, 0x2, 0x74b, 
       0x74f, 0x3, 0x2, 0x2, 0x2, 0x74c, 0x74a, 0x3, 0x2, 0x2, 0x2, 0x74d, 
       0x74f, 0x7, 0x2, 0x2, 0x3, 0x74e, 0x74a, 0x3, 0x2, 0x2, 0x2, 0x74e, 
       0x74d, 0x3, 0x2, 0x2, 0x2, 0x74f, 0x751, 0x3, 0x2, 0x2, 0x2, 0x750, 
       0x73b, 0x3, 0x2, 0x2, 0x2, 0x750, 0x746, 0x3, 0x2, 0x2, 0x2, 0x751, 
       0xa3, 0x3, 0x2, 0x2, 0x2, 0x752, 0x754, 0x5, 0xa6, 0x54, 0x2, 0x753, 
       0x755, 0x5, 0xa8, 0x55, 0x2, 0x754, 0x753, 0x3, 0x2, 0x2, 0x2, 0x755, 
       0x756, 0x3, 0x2, 0x2, 0x2, 0x756, 0x754, 0x3, 0x2, 0x2, 0x2, 0x756, 
       0x757, 0x3, 0x2, 0x2, 0x2, 0x757, 0x758, 0x3, 0x2, 0x2, 0x2, 0x758, 
       0x759, 0x5, 0xaa, 0x56, 0x2, 0x759, 0xa5, 0x3, 0x2, 0x2, 0x2, 0x75a, 
       0x75e, 0x7, 0x2e, 0x2, 0x2, 0x75b, 0x75d, 0x7, 0xde, 0x2, 0x2, 0x75c, 
       0x75b, 0x3, 0x2, 0x2, 0x2, 0x75d, 0x760, 0x3, 0x2, 0x2, 0x2, 0x75e, 
       0x75c, 0x3, 0x2, 0x2, 0x2, 0x75e, 0x75f, 0x3, 0x2, 0x2, 0x2, 0x75f, 
       0x761, 0x3, 0x2, 0x2, 0x2, 0x760, 0x75e, 0x3, 0x2, 0x2, 0x2, 0x761, 
       0x765, 0x7, 0xc5, 0x2, 0x2, 0x762, 0x764, 0x7, 0xde, 0x2, 0x2, 0x763, 
       0x762, 0x3, 0x2, 0x2, 0x2, 0x764, 0x767, 0x3, 0x2, 0x2, 0x2, 0x765, 
       0x763, 0x3, 0x2, 0x2, 0x2, 0x765, 0x766, 0x3, 0x2, 0x2, 0x2, 0x766, 
       0xa7, 0x3, 0x2, 0x2, 0x2, 0x767, 0x765, 0x3, 0x2, 0x2, 0x2, 0x768, 
       0x76e, 0x5, 0xac, 0x57, 0x2, 0x769, 0x76e, 0x5, 0xae, 0x58, 0x2, 
       0x76a, 0x76e, 0x5, 0xb4, 0x5b, 0x2, 0x76b, 0x76e, 0x5, 0xb0, 0x59, 
       0x2, 0x76c, 0x76e, 0x5, 0xb2, 0x5a, 0x2, 0x76d, 0x768, 0x3, 0x2, 
       0x2, 0x2, 0x76d, 0x769, 0x3, 0x2, 0x2, 0x2, 0x76d, 0x76a, 0x3, 0x2, 
       0x2, 0x2, 0x76d, 0x76b, 0x3, 0x2, 0x2, 0x2, 0x76d, 0x76c, 0x3, 0x2, 
       0x2, 0x2, 0x76e, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x76f, 0x777, 0x7, 0xc6, 
       0x2, 0x2, 0x770, 0x772, 0x7, 0xde, 0x2, 0x2, 0x771, 0x770, 0x3, 0x2, 
       0x2, 0x2, 0x772, 0x775, 0x3, 0x2, 0x2, 0x2, 0x773, 0x771, 0x3, 0x2, 
       0x2, 0x2, 0x773, 0x774, 0x3, 0x2, 0x2, 0x2, 0x774, 0x778, 0x3, 0x2, 
       0x2, 0x2, 0x775, 0x773, 0x3, 0x2, 0x2, 0x2, 0x776, 0x778, 0x7, 0x2, 
       0x2, 0x3, 0x777, 0x773, 0x3, 0x2, 0x2, 0x2, 0x777, 0x776, 0x3, 0x2, 
       0x2, 0x2, 0x778, 0xab, 0x3, 0x2, 0x2, 0x2, 0x779, 0x77d, 0x7, 0x2f, 
       0x2, 0x2, 0x77a, 0x77c, 0x7, 0xde, 0x2, 0x2, 0x77b, 0x77a, 0x3, 0x2, 
       0x2, 0x2, 0x77c, 0x77f, 0x3, 0x2, 0x2, 0x2, 0x77d, 0x77b, 0x3, 0x2, 
       0x2, 0x2, 0x77d, 0x77e, 0x3, 0x2, 0x2, 0x2, 0x77e, 0x780, 0x3, 0x2, 
       0x2, 0x2, 0x77f, 0x77d, 0x3, 0x2, 0x2, 0x2, 0x780, 0x784, 0x7, 0xc5, 
       0x2, 0x2, 0x781, 0x783, 0x7, 0xde, 0x2, 0x2, 0x782, 0x781, 0x3, 0x2, 
       0x2, 0x2, 0x783, 0x786, 0x3, 0x2, 0x2, 0x2, 0x784, 0x782, 0x3, 0x2, 
       0x2, 0x2, 0x784, 0x785, 0x3, 0x2, 0x2, 0x2, 0x785, 0x788, 0x3, 0x2, 
       0x2, 0x2, 0x786, 0x784, 0x3, 0x2, 0x2, 0x2, 0x787, 0x789, 0x5, 0xa8, 
       0x55, 0x2, 0x788, 0x787, 0x3, 0x2, 0x2, 0x2, 0x789, 0x78a, 0x3, 0x2, 
       0x2, 0x2, 0x78a, 0x788, 0x3, 0x2, 0x2, 0x2, 0x78a, 0x78b, 0x3, 0x2, 
       0x2, 0x2, 0x78b, 0x78c, 0x3, 0x2, 0x2, 0x2, 0x78c, 0x794, 0x7, 0xc6, 
       0x2, 0x2, 0x78d, 0x78f, 0x7, 0xde, 0x2, 0x2, 0x78e, 0x78d, 0x3, 0x2, 
       0x2, 0x2, 0x78f, 0x792, 0x3, 0x2, 0x2, 0x2, 0x790, 0x78e, 0x3, 0x2, 
       0x2, 0x2, 0x790, 0x791, 0x3, 0x2, 0x2, 0x2, 0x791, 0x795, 0x3, 0x2, 
       0x2, 0x2, 0x792, 0x790, 0x3, 0x2, 0x2, 0x2, 0x793, 0x795, 0x7, 0x2, 
       0x2, 0x3, 0x794, 0x790, 0x3, 0x2, 0x2, 0x2, 0x794, 0x793, 0x3, 0x2, 
       0x2, 0x2, 0x795, 0xad, 0x3, 0x2, 0x2, 0x2, 0x796, 0x79a, 0x7, 0x32, 
       0x2, 0x2, 0x797, 0x799, 0x7, 0xde, 0x2, 0x2, 0x798, 0x797, 0x3, 0x2, 
       0x2, 0x2, 0x799, 0x79c, 0x3, 0x2, 0x2, 0x2, 0x79a, 0x798, 0x3, 0x2, 
       0x2, 0x2, 0x79a, 0x79b, 0x3, 0x2, 0x2, 0x2, 0x79b, 0x79d, 0x3, 0x2, 
       0x2, 0x2, 0x79c, 0x79a, 0x3, 0x2, 0x2, 0x2, 0x79d, 0x7a1, 0x7, 0xc5, 
       0x2, 0x2, 0x79e, 0x7a0, 0x7, 0xde, 0x2, 0x2, 0x79f, 0x79e, 0x3, 0x2, 
       0x2, 0x2, 0x7a0, 0x7a3, 0x3, 0x2, 0x2, 0x2, 0x7a1, 0x79f, 0x3, 0x2, 
       0x2, 0x2, 0x7a1, 0x7a2, 0x3, 0x2, 0x2, 0x2, 0x7a2, 0x7a5, 0x3, 0x2, 
       0x2, 0x2, 0x7a3, 0x7a1, 0x3, 0x2, 0x2, 0x2, 0x7a4, 0x7a6, 0x5, 0xa8, 
       0x55, 0x2, 0x7a5, 0x7a4, 0x3, 0x2, 0x2, 0x2, 0x7a6, 0x7a7, 0x3, 0x2, 
       0x2, 0x2, 0x7a7, 0x7a5, 0x3, 0x2, 0x2, 0x2, 0x7a7, 0x7a8, 0x3, 0x2, 
       0x2, 0x2, 0x7a8, 0x7a9, 0x3, 0x2, 0x2, 0x2, 0x7a9, 0x7b1, 0x7, 0xc6, 
       0x2, 0x2, 0x7aa, 0x7ac, 0x7, 0xde, 0x2, 0x2, 0x7ab, 0x7aa, 0x3, 0x2, 
       0x2, 0x2, 0x7ac, 0x7af, 0x3, 0x2, 0x2, 0x2, 0x7ad, 0x7ab, 0x3, 0x2, 
       0x2, 0x2, 0x7ad, 0x7ae, 0x3, 0x2, 0x2, 0x2, 0x7ae, 0x7b2, 0x3, 0x2, 
       0x2, 0x2, 0x7af, 0x7ad, 0x3, 0x2, 0x2, 0x2, 0x7b0, 0x7b2, 0x7, 0x2, 
       0x2, 0x3, 0x7b1, 0x7ad, 0x3, 0x2, 0x2, 0x2, 0x7b1, 0x7b0, 0x3, 0x2, 
       0x2, 0x2, 0x7b2, 0xaf, 0x3, 0x2, 0x2, 0x2, 0x7b3, 0x7b4, 0x7, 0x30, 
       0x2, 0x2, 0x7b4, 0x7b5, 0x7, 0xd9, 0x2, 0x2, 0x7b5, 0x7b6, 0x7, 0xaa, 
       0x2, 0x2, 0x7b6, 0x7b8, 0x7, 0xc3, 0x2, 0x2, 0x7b7, 0x7b9, 0x5, 0xf4, 
       0x7b, 0x2, 0x7b8, 0x7b7, 0x3, 0x2, 0x2, 0x2, 0x7b9, 0x7ba, 0x3, 0x2, 
       0x2, 0x2, 0x7ba, 0x7b8, 0x3, 0x2, 0x2, 0x2, 0x7ba, 0x7bb, 0x3, 0x2, 
       0x2, 0x2, 0x7bb, 0x7bc, 0x3, 0x2, 0x2, 0x2, 0x7bc, 0x7c4, 0x7, 0xc4, 
       0x2, 0x2, 0x7bd, 0x7bf, 0x7, 0xde, 0x2, 0x2, 0x7be, 0x7bd, 0x3, 0x2, 
       0x2, 0x2, 0x7bf, 0x7c2, 0x3, 0x2, 0x2, 0x2, 0x7c0, 0x7be, 0x3, 0x2, 
       0x2, 0x2, 0x7c0, 0x7c1, 0x3, 0x2, 0x2, 0x2, 0x7c1, 0x7c5, 0x3, 0x2, 
       0x2, 0x2, 0x7c2, 0x7c0, 0x3, 0x2, 0x2, 0x2, 0x7c3, 0x7c5, 0x7, 0x2, 
       0x2, 0x3, 0x7c4, 0x7c0, 0x3, 0x2, 0x2, 0x2, 0x7c4, 0x7c3, 0x3, 0x2, 
       0x2, 0x2, 0x7c5, 0x7e0, 0x3, 0x2, 0x2, 0x2, 0x7c6, 0x7d1, 0x7, 0x30, 
       0x2, 0x2, 0x7c7, 0x7c8, 0x7, 0xd9, 0x2, 0x2, 0x7c8, 0x7c9, 0x7, 0xaa, 
       0x2, 0x2, 0x7c9, 0x7cb, 0x7, 0xc3, 0x2, 0x2, 0x7ca, 0x7cc, 0x5, 0xf4, 
       0x7b, 0x2, 0x7cb, 0x7ca, 0x3, 0x2, 0x2, 0x2, 0x7cc, 0x7cd, 0x3, 0x2, 
       0x2, 0x2, 0x7cd, 0x7cb, 0x3, 0x2, 0x2, 0x2, 0x7cd, 0x7ce, 0x3, 0x2, 
       0x2, 0x2, 0x7ce, 0x7cf, 0x3, 0x2, 0x2, 0x2, 0x7cf, 0x7d0, 0x7, 0xc4, 
       0x2, 0x2, 0x7d0, 0x7d2, 0x3, 0x2, 0x2, 0x2, 0x7d1, 0x7c7, 0x3, 0x2, 
       0x2, 0x2, 0x7d2, 0x7d3, 0x3, 0x2, 0x2, 0x2, 0x7d3, 0x7d1, 0x3, 0x2, 
       0x2, 0x2, 0x7d3, 0x7d4, 0x3, 0x2, 0x2, 0x2, 0x7d4, 0x7d5, 0x3, 0x2, 
       0x2, 0x2, 0x7d5, 0x7dd, 0x5, 0xf2, 0x7a, 0x2, 0x7d6, 0x7d8, 0x7, 
       0xde, 0x2, 0x2, 0x7d7, 0x7d6, 0x3, 0x2, 0x2, 0x2, 0x7d8, 0x7db, 0x3, 
       0x2, 0x2, 0x2, 0x7d9, 0x7d7, 0x3, 0x2, 0x2, 0x2, 0x7d9, 0x7da, 0x3, 
       0x2, 0x2, 0x2, 0x7da, 0x7de, 0x3, 0x2, 0x2, 0x2, 0x7db, 0x7d9, 0x3, 
       0x2, 0x2, 0x2, 0x7dc, 0x7de, 0x7, 0x2, 0x2, 0x3, 0x7dd, 0x7d9, 0x3, 
       0x2, 0x2, 0x2, 0x7dd, 0x7dc, 0x3, 0x2, 0x2, 0x2, 0x7de, 0x7e0, 0x3, 
       0x2, 0x2, 0x2, 0x7df, 0x7b3, 0x3, 0x2, 0x2, 0x2, 0x7df, 0x7c6, 0x3, 
       0x2, 0x2, 0x2, 0x7e0, 0xb1, 0x3, 0x2, 0x2, 0x2, 0x7e1, 0x7e2, 0x7, 
       0x31, 0x2, 0x2, 0x7e2, 0x7ea, 0x5, 0xf2, 0x7a, 0x2, 0x7e3, 0x7e5, 
       0x7, 0xde, 0x2, 0x2, 0x7e4, 0x7e3, 0x3, 0x2, 0x2, 0x2, 0x7e5, 0x7e8, 
       0x3, 0x2, 0x2, 0x2, 0x7e6, 0x7e4, 0x3, 0x2, 0x2, 0x2, 0x7e6, 0x7e7, 
       0x3, 0x2, 0x2, 0x2, 0x7e7, 0x7eb, 0x3, 0x2, 0x2, 0x2, 0x7e8, 0x7e6, 
       0x3, 0x2, 0x2, 0x2, 0x7e9, 0x7eb, 0x7, 0x2, 0x2, 0x3, 0x7ea, 0x7e6, 
       0x3, 0x2, 0x2, 0x2, 0x7ea, 0x7e9, 0x3, 0x2, 0x2, 0x2, 0x7eb, 0xb3, 
       0x3, 0x2, 0x2, 0x2, 0x7ec, 0x7ed, 0x7, 0x33, 0x2, 0x2, 0x7ed, 0x7ee, 
       0x7, 0xd9, 0x2, 0x2, 0x7ee, 0x7f6, 0x5, 0xea, 0x76, 0x2, 0x7ef, 0x7f1, 
       0x7, 0xde, 0x2, 0x2, 0x7f0, 0x7ef, 0x3, 0x2, 0x2, 0x2, 0x7f1, 0x7f4, 
       0x3, 0x2, 0x2, 0x2, 0x7f2, 0x7f0, 0x3, 0x2, 0x2, 0x2, 0x7f2, 0x7f3, 
       0x3, 0x2, 0x2, 0x2, 0x7f3, 0x7f7, 0x3, 0x2, 0x2, 0x2, 0x7f4, 0x7f2, 
       0x3, 0x2, 0x2, 0x2, 0x7f5, 0x7f7, 0x7, 0x2, 0x2, 0x3, 0x7f6, 0x7f2, 
       0x3, 0x2, 0x2, 0x2, 0x7f6, 0x7f5, 0x3, 0x2, 0x2, 0x2, 0x7f7, 0x804, 
       0x3, 0x2, 0x2, 0x2, 0x7f8, 0x7f9, 0x7, 0x33, 0x2, 0x2, 0x7f9, 0x801, 
       0x7, 0xd9, 0x2, 0x2, 0x7fa, 0x7fc, 0x7, 0xde, 0x2, 0x2, 0x7fb, 0x7fa, 
       0x3, 0x2, 0x2, 0x2, 0x7fc, 0x7ff, 0x3, 0x2, 0x2, 0x2, 0x7fd, 0x7fb, 
       0x3, 0x2, 0x2, 0x2, 0x7fd, 0x7fe, 0x3, 0x2, 0x2, 0x2, 0x7fe, 0x802, 
       0x3, 0x2, 0x2, 0x2, 0x7ff, 0x7fd, 0x3, 0x2, 0x2, 0x2, 0x800, 0x802, 
       0x7, 0x2, 0x2, 0x3, 0x801, 0x7fd, 0x3, 0x2, 0x2, 0x2, 0x801, 0x800, 
       0x3, 0x2, 0x2, 0x2, 0x802, 0x804, 0x3, 0x2, 0x2, 0x2, 0x803, 0x7ec, 
       0x3, 0x2, 0x2, 0x2, 0x803, 0x7f8, 0x3, 0x2, 0x2, 0x2, 0x804, 0xb5, 
       0x3, 0x2, 0x2, 0x2, 0x805, 0x807, 0x5, 0xb8, 0x5d, 0x2, 0x806, 0x808, 
       0x5, 0xba, 0x5e, 0x2, 0x807, 0x806, 0x3, 0x2, 0x2, 0x2, 0x808, 0x809, 
       0x3, 0x2, 0x2, 0x2, 0x809, 0x807, 0x3, 0x2, 0x2, 0x2, 0x809, 0x80a, 
       0x3, 0x2, 0x2, 0x2, 0x80a, 0x80b, 0x3, 0x2, 0x2, 0x2, 0x80b, 0x80c, 
       0x5, 0xbc, 0x5f, 0x2, 0x80c, 0xb7, 0x3, 0x2, 0x2, 0x2, 0x80d, 0x80e, 
       0x7, 0xd9, 0x2, 0x2, 0x80e, 0x810, 0x7, 0x34, 0x2, 0x2, 0x80f, 0x811, 
       0x5, 0xea, 0x76, 0x2, 0x810, 0x80f, 0x3, 0x2, 0x2, 0x2, 0x810, 0x811, 
       0x3, 0x2, 0x2, 0x2, 0x811, 0x815, 0x3, 0x2, 0x2, 0x2, 0x812, 0x814, 
       0x7, 0xde, 0x2, 0x2, 0x813, 0x812, 0x3, 0x2, 0x2, 0x2, 0x814, 0x817, 
       0x3, 0x2, 0x2, 0x2, 0x815, 0x813, 0x3, 0x2, 0x2, 0x2, 0x815, 0x816, 
       0x3, 0x2, 0x2, 0x2, 0x816, 0x818, 0x3, 0x2, 0x2, 0x2, 0x817, 0x815, 
       0x3, 0x2, 0x2, 0x2, 0x818, 0x81c, 0x7, 0xc5, 0x2, 0x2, 0x819, 0x81b, 
       0x7, 0xde, 0x2, 0x2, 0x81a, 0x819, 0x3, 0x2, 0x2, 0x2, 0x81b, 0x81e, 
       0x3, 0x2, 0x2, 0x2, 0x81c, 0x81a, 0x3, 0x2, 0x2, 0x2, 0x81c, 0x81d, 
       0x3, 0x2, 0x2, 0x2, 0x81d, 0xb9, 0x3, 0x2, 0x2, 0x2, 0x81e, 0x81c, 
       0x3, 0x2, 0x2, 0x2, 0x81f, 0x822, 0x5, 0xbe, 0x60, 0x2, 0x820, 0x822, 
       0x5, 0x6, 0x4, 0x2, 0x821, 0x81f, 0x3, 0x2, 0x2, 0x2, 0x821, 0x820, 
       0x3, 0x2, 0x2, 0x2, 0x822, 0xbb, 0x3, 0x2, 0x2, 0x2, 0x823, 0x82b, 
       0x7, 0xc6, 0x2, 0x2, 0x824, 0x826, 0x7, 0xde, 0x2, 0x2, 0x825, 0x824, 
       0x3, 0x2, 0x2, 0x2, 0x826, 0x829, 0x3, 0x2, 0x2, 0x2, 0x827, 0x825, 
       0x3, 0x2, 0x2, 0x2, 0x827, 0x828, 0x3, 0x2, 0x2, 0x2, 0x828, 0x82c, 
       0x3, 0x2, 0x2, 0x2, 0x829, 0x827, 0x3, 0x2, 0x2, 0x2, 0x82a, 0x82c, 
       0x7, 0x2, 0x2, 0x3, 0x82b, 0x827, 0x3, 0x2, 0x2, 0x2, 0x82b, 0x82a, 
       0x3, 0x2, 0x2, 0x2, 0x82c, 0xbd, 0x3, 0x2, 0x2, 0x2, 0x82d, 0x82e, 
       0x7, 0xd9, 0x2, 0x2, 0x82e, 0x836, 0x5, 0xea, 0x76, 0x2, 0x82f, 0x831, 
       0x7, 0xde, 0x2, 0x2, 0x830, 0x82f, 0x3, 0x2, 0x2, 0x2, 0x831, 0x834, 
       0x3, 0x2, 0x2, 0x2, 0x832, 0x830, 0x3, 0x2, 0x2, 0x2, 0x832, 0x833, 
       0x3, 0x2, 0x2, 0x2, 0x833, 0x837, 0x3, 0x2, 0x2, 0x2, 0x834, 0x832, 
       0x3, 0x2, 0x2, 0x2, 0x835, 0x837, 0x7, 0x2, 0x2, 0x3, 0x836, 0x832, 
       0x3, 0x2, 0x2, 0x2, 0x836, 0x835, 0x3, 0x2, 0x2, 0x2, 0x837, 0xbf, 
       0x3, 0x2, 0x2, 0x2, 0x838, 0x839, 0x7, 0x29, 0x2, 0x2, 0x839, 0x83b, 
       0x7, 0xc1, 0x2, 0x2, 0x83a, 0x83c, 0x5, 0xec, 0x77, 0x2, 0x83b, 0x83a, 
       0x3, 0x2, 0x2, 0x2, 0x83c, 0x83d, 0x3, 0x2, 0x2, 0x2, 0x83d, 0x83b, 
       0x3, 0x2, 0x2, 0x2, 0x83d, 0x83e, 0x3, 0x2, 0x2, 0x2, 0x83e, 0x83f, 
       0x3, 0x2, 0x2, 0x2, 0x83f, 0x847, 0x7, 0xc2, 0x2, 0x2, 0x840, 0x842, 
       0x7, 0xde, 0x2, 0x2, 0x841, 0x840, 0x3, 0x2, 0x2, 0x2, 0x842, 0x845, 
       0x3, 0x2, 0x2, 0x2, 0x843, 0x841, 0x3, 0x2, 0x2, 0x2, 0x843, 0x844, 
       0x3, 0x2, 0x2, 0x2, 0x844, 0x848, 0x3, 0x2, 0x2, 0x2, 0x845, 0x843, 
       0x3, 0x2, 0x2, 0x2, 0x846, 0x848, 0x7, 0x2, 0x2, 0x3, 0x847, 0x843, 
       0x3, 0x2, 0x2, 0x2, 0x847, 0x846, 0x3, 0x2, 0x2, 0x2, 0x848, 0x859, 
       0x3, 0x2, 0x2, 0x2, 0x849, 0x84b, 0x7, 0x29, 0x2, 0x2, 0x84a, 0x84c, 
       0x5, 0xec, 0x77, 0x2, 0x84b, 0x84a, 0x3, 0x2, 0x2, 0x2, 0x84c, 0x84d, 
       0x3, 0x2, 0x2, 0x2, 0x84d, 0x84b, 0x3, 0x2, 0x2, 0x2, 0x84d, 0x84e, 
       0x3, 0x2, 0x2, 0x2, 0x84e, 0x856, 0x3, 0x2, 0x2, 0x2, 0x84f, 0x851, 
       0x7, 0xde, 0x2, 0x2, 0x850, 0x84f, 0x3, 0x2, 0x2, 0x2, 0x851, 0x854, 
       0x3, 0x2, 0x2, 0x2, 0x852, 0x850, 0x3, 0x2, 0x2, 0x2, 0x852, 0x853, 
       0x3, 0x2, 0x2, 0x2, 0x853, 0x857, 0x3, 0x2, 0x2, 0x2, 0x854, 0x852, 
       0x3, 0x2, 0x2, 0x2, 0x855, 0x857, 0x7, 0x2, 0x2, 0x3, 0x856, 0x852, 
       0x3, 0x2, 0x2, 0x2, 0x856, 0x855, 0x3, 0x2, 0x2, 0x2, 0x857, 0x859, 
       0x3, 0x2, 0x2, 0x2, 0x858, 0x838, 0x3, 0x2, 0x2, 0x2, 0x858, 0x849, 
       0x3, 0x2, 0x2, 0x2, 0x859, 0xc1, 0x3, 0x2, 0x2, 0x2, 0x85a, 0x85c, 
       0x5, 0xc4, 0x63, 0x2, 0x85b, 0x85d, 0x5, 0xd0, 0x69, 0x2, 0x85c, 
       0x85b, 0x3, 0x2, 0x2, 0x2, 0x85c, 0x85d, 0x3, 0x2, 0x2, 0x2, 0x85d, 
       0x85f, 0x3, 0x2, 0x2, 0x2, 0x85e, 0x860, 0x5, 0xc6, 0x64, 0x2, 0x85f, 
       0x85e, 0x3, 0x2, 0x2, 0x2, 0x85f, 0x860, 0x3, 0x2, 0x2, 0x2, 0x860, 
       0x864, 0x3, 0x2, 0x2, 0x2, 0x861, 0x863, 0x5, 0xc8, 0x65, 0x2, 0x862, 
       0x861, 0x3, 0x2, 0x2, 0x2, 0x863, 0x866, 0x3, 0x2, 0x2, 0x2, 0x864, 
       0x862, 0x3, 0x2, 0x2, 0x2, 0x864, 0x865, 0x3, 0x2, 0x2, 0x2, 0x865, 
       0x86e, 0x3, 0x2, 0x2, 0x2, 0x866, 0x864, 0x3, 0x2, 0x2, 0x2, 0x867, 
       0x869, 0x7, 0xde, 0x2, 0x2, 0x868, 0x867, 0x3, 0x2, 0x2, 0x2, 0x869, 
       0x86c, 0x3, 0x2, 0x2, 0x2, 0x86a, 0x868, 0x3, 0x2, 0x2, 0x2, 0x86a, 
       0x86b, 0x3, 0x2, 0x2, 0x2, 0x86b, 0x86f, 0x3, 0x2, 0x2, 0x2, 0x86c, 
       0x86a, 0x3, 0x2, 0x2, 0x2, 0x86d, 0x86f, 0x7, 0x2, 0x2, 0x3, 0x86e, 
       0x86a, 0x3, 0x2, 0x2, 0x2, 0x86e, 0x86d, 0x3, 0x2, 0x2, 0x2, 0x86f, 
       0xc3, 0x3, 0x2, 0x2, 0x2, 0x870, 0x871, 0x7, 0xd9, 0x2, 0x2, 0x871, 
       0xc5, 0x3, 0x2, 0x2, 0x2, 0x872, 0x875, 0x7, 0xd9, 0x2, 0x2, 0x873, 
       0x875, 0x5, 0x108, 0x85, 0x2, 0x874, 0x872, 0x3, 0x2, 0x2, 0x2, 0x874, 
       0x873, 0x3, 0x2, 0x2, 0x2, 0x875, 0xc7, 0x3, 0x2, 0x2, 0x2, 0x876, 
       0x87b, 0x5, 0xf2, 0x7a, 0x2, 0x877, 0x87b, 0x5, 0xce, 0x68, 0x2, 
       0x878, 0x87b, 0x5, 0xcc, 0x67, 0x2, 0x879, 0x87b, 0x5, 0xca, 0x66, 
       0x2, 0x87a, 0x876, 0x3, 0x2, 0x2, 0x2, 0x87a, 0x877, 0x3, 0x2, 0x2, 
       0x2, 0x87a, 0x878, 0x3, 0x2, 0x2, 0x2, 0x87a, 0x879, 0x3, 0x2, 0x2, 
       0x2, 0x87b, 0x87c, 0x3, 0x2, 0x2, 0x2, 0x87c, 0x87a, 0x3, 0x2, 0x2, 
       0x2, 0x87c, 0x87d, 0x3, 0x2, 0x2, 0x2, 0x87d, 0xc9, 0x3, 0x2, 0x2, 
       0x2, 0x87e, 0x880, 0x7, 0xc5, 0x2, 0x2, 0x87f, 0x87e, 0x3, 0x2, 0x2, 
       0x2, 0x87f, 0x880, 0x3, 0x2, 0x2, 0x2, 0x880, 0x883, 0x3, 0x2, 0x2, 
       0x2, 0x881, 0x884, 0x7, 0xda, 0x2, 0x2, 0x882, 0x884, 0x5, 0xdc, 
       0x6f, 0x2, 0x883, 0x881, 0x3, 0x2, 0x2, 0x2, 0x883, 0x882, 0x3, 0x2, 
       0x2, 0x2, 0x884, 0x886, 0x3, 0x2, 0x2, 0x2, 0x885, 0x887, 0x7, 0xc6, 
       0x2, 0x2, 0x886, 0x885, 0x3, 0x2, 0x2, 0x2, 0x886, 0x887, 0x3, 0x2, 
       0x2, 0x2, 0x887, 0xcb, 0x3, 0x2, 0x2, 0x2, 0x888, 0x88a, 0x9, 0x3, 
       0x2, 0x2, 0x889, 0x88b, 0x7, 0xaa, 0x2, 0x2, 0x88a, 0x889, 0x3, 0x2, 
       0x2, 0x2, 0x88a, 0x88b, 0x3, 0x2, 0x2, 0x2, 0x88b, 0x88c, 0x3, 0x2, 
       0x2, 0x2, 0x88c, 0x897, 0x7, 0xc1, 0x2, 0x2, 0x88d, 0x88f, 0x5, 0xfc, 
       0x7f, 0x2, 0x88e, 0x88d, 0x3, 0x2, 0x2, 0x2, 0x88f, 0x890, 0x3, 0x2, 
       0x2, 0x2, 0x890, 0x88e, 0x3, 0x2, 0x2, 0x2, 0x890, 0x891, 0x3, 0x2, 
       0x2, 0x2, 0x891, 0x898, 0x3, 0x2, 0x2, 0x2, 0x892, 0x894, 0x5, 0xdc, 
       0x6f, 0x2, 0x893, 0x892, 0x3, 0x2, 0x2, 0x2, 0x894, 0x895, 0x3, 0x2, 
       0x2, 0x2, 0x895, 0x893, 0x3, 0x2, 0x2, 0x2, 0x895, 0x896, 0x3, 0x2, 
       0x2, 0x2, 0x896, 0x898, 0x3, 0x2, 0x2, 0x2, 0x897, 0x88e, 0x3, 0x2, 
       0x2, 0x2, 0x897, 0x893, 0x3, 0x2, 0x2, 0x2, 0x898, 0x899, 0x3, 0x2, 
       0x2, 0x2, 0x899, 0x89a, 0x7, 0xc2, 0x2, 0x2, 0x89a, 0x8c2, 0x3, 0x2, 
       0x2, 0x2, 0x89b, 0x89d, 0x9, 0x3, 0x2, 0x2, 0x89c, 0x89e, 0x7, 0xaa, 
       0x2, 0x2, 0x89d, 0x89c, 0x3, 0x2, 0x2, 0x2, 0x89d, 0x89e, 0x3, 0x2, 
       0x2, 0x2, 0x89e, 0x89f, 0x3, 0x2, 0x2, 0x2, 0x89f, 0x8aa, 0x7, 0xc3, 
       0x2, 0x2, 0x8a0, 0x8a2, 0x5, 0xfc, 0x7f, 0x2, 0x8a1, 0x8a0, 0x3, 
       0x2, 0x2, 0x2, 0x8a2, 0x8a3, 0x3, 0x2, 0x2, 0x2, 0x8a3, 0x8a1, 0x3, 
       0x2, 0x2, 0x2, 0x8a3, 0x8a4, 0x3, 0x2, 0x2, 0x2, 0x8a4, 0x8ab, 0x3, 
       0x2, 0x2, 0x2, 0x8a5, 0x8a7, 0x5, 0xdc, 0x6f, 0x2, 0x8a6, 0x8a5, 
       0x3, 0x2, 0x2, 0x2, 0x8a7, 0x8a8, 0x3, 0x2, 0x2, 0x2, 0x8a8, 0x8a6, 
       0x3, 0x2, 0x2, 0x2, 0x8a8, 0x8a9, 0x3, 0x2, 0x2, 0x2, 0x8a9, 0x8ab, 
       0x3, 0x2, 0x2, 0x2, 0x8aa, 0x8a1, 0x3, 0x2, 0x2, 0x2, 0x8aa, 0x8a6, 
       0x3, 0x2, 0x2, 0x2, 0x8ab, 0x8ac, 0x3, 0x2, 0x2, 0x2, 0x8ac, 0x8ad, 
       0x7, 0xc4, 0x2, 0x2, 0x8ad, 0x8c2, 0x3, 0x2, 0x2, 0x2, 0x8ae, 0x8b0, 
       0x9, 0x3, 0x2, 0x2, 0x8af, 0x8b1, 0x7, 0xaa, 0x2, 0x2, 0x8b0, 0x8af, 
       0x3, 0x2, 0x2, 0x2, 0x8b0, 0x8b1, 0x3, 0x2, 0x2, 0x2, 0x8b1, 0x8b2, 
       0x3, 0x2, 0x2, 0x2, 0x8b2, 0x8bd, 0x7, 0xc5, 0x2, 0x2, 0x8b3, 0x8b5, 
       0x5, 0xfc, 0x7f, 0x2, 0x8b4, 0x8b3, 0x3, 0x2, 0x2, 0x2, 0x8b5, 0x8b6, 
       0x3, 0x2, 0x2, 0x2, 0x8b6, 0x8b4, 0x3, 0x2, 0x2, 0x2, 0x8b6, 0x8b7, 
       0x3, 0x2, 0x2, 0x2, 0x8b7, 0x8be, 0x3, 0x2, 0x2, 0x2, 0x8b8, 0x8ba, 
       0x5, 0xdc, 0x6f, 0x2, 0x8b9, 0x8b8, 0x3, 0x2, 0x2, 0x2, 0x8ba, 0x8bb, 
       0x3, 0x2, 0x2, 0x2, 0x8bb, 0x8b9, 0x3, 0x2, 0x2, 0x2, 0x8bb, 0x8bc, 
       0x3, 0x2, 0x2, 0x2, 0x8bc, 0x8be, 0x3, 0x2, 0x2, 0x2, 0x8bd, 0x8b4, 
       0x3, 0x2, 0x2, 0x2, 0x8bd, 0x8b9, 0x3, 0x2, 0x2, 0x2, 0x8be, 0x8bf, 
       0x3, 0x2, 0x2, 0x2, 0x8bf, 0x8c0, 0x7, 0xc5, 0x2, 0x2, 0x8c0, 0x8c2, 
       0x3, 0x2, 0x2, 0x2, 0x8c1, 0x888, 0x3, 0x2, 0x2, 0x2, 0x8c1, 0x89b, 
       0x3, 0x2, 0x2, 0x2, 0x8c1, 0x8ae, 0x3, 0x2, 0x2, 0x2, 0x8c2, 0xcd, 
       0x3, 0x2, 0x2, 0x2, 0x8c3, 0x8c4, 0x9, 0x4, 0x2, 0x2, 0x8c4, 0x8c6, 
       0x7, 0xc5, 0x2, 0x2, 0x8c5, 0x8c7, 0x5, 0xdc, 0x6f, 0x2, 0x8c6, 0x8c5, 
       0x3, 0x2, 0x2, 0x2, 0x8c6, 0x8c7, 0x3, 0x2, 0x2, 0x2, 0x8c7, 0x8c8, 
       0x3, 0x2, 0x2, 0x2, 0x8c8, 0x8ce, 0x7, 0xc6, 0x2, 0x2, 0x8c9, 0x8cb, 
       0x9, 0x4, 0x2, 0x2, 0x8ca, 0x8cc, 0x5, 0xdc, 0x6f, 0x2, 0x8cb, 0x8ca, 
       0x3, 0x2, 0x2, 0x2, 0x8cb, 0x8cc, 0x3, 0x2, 0x2, 0x2, 0x8cc, 0x8ce, 
       0x3, 0x2, 0x2, 0x2, 0x8cd, 0x8c3, 0x3, 0x2, 0x2, 0x2, 0x8cd, 0x8c9, 
       0x3, 0x2, 0x2, 0x2, 0x8ce, 0xcf, 0x3, 0x2, 0x2, 0x2, 0x8cf, 0x8d1, 
       0x5, 0xd2, 0x6a, 0x2, 0x8d0, 0x8cf, 0x3, 0x2, 0x2, 0x2, 0x8d1, 0x8d2, 
       0x3, 0x2, 0x2, 0x2, 0x8d2, 0x8d0, 0x3, 0x2, 0x2, 0x2, 0x8d2, 0x8d3, 
       0x3, 0x2, 0x2, 0x2, 0x8d3, 0x8dd, 0x3, 0x2, 0x2, 0x2, 0x8d4, 0x8d6, 
       0x7, 0xc1, 0x2, 0x2, 0x8d5, 0x8d7, 0x5, 0xd2, 0x6a, 0x2, 0x8d6, 0x8d5, 
       0x3, 0x2, 0x2, 0x2, 0x8d7, 0x8d8, 0x3, 0x2, 0x2, 0x2, 0x8d8, 0x8d6, 
       0x3, 0x2, 0x2, 0x2, 0x8d8, 0x8d9, 0x3, 0x2, 0x2, 0x2, 0x8d9, 0x8da, 
       0x3, 0x2, 0x2, 0x2, 0x8da, 0x8db, 0x7, 0xc2, 0x2, 0x2, 0x8db, 0x8dd, 
       0x3, 0x2, 0x2, 0x2, 0x8dc, 0x8d0, 0x3, 0x2, 0x2, 0x2, 0x8dc, 0x8d4, 
       0x3, 0x2, 0x2, 0x2, 0x8dd, 0xd1, 0x3, 0x2, 0x2, 0x2, 0x8de, 0x8e2, 
       0x5, 0xda, 0x6e, 0x2, 0x8df, 0x8e2, 0x5, 0xd4, 0x6b, 0x2, 0x8e0, 
       0x8e2, 0x5, 0xd8, 0x6d, 0x2, 0x8e1, 0x8de, 0x3, 0x2, 0x2, 0x2, 0x8e1, 
       0x8df, 0x3, 0x2, 0x2, 0x2, 0x8e1, 0x8e0, 0x3, 0x2, 0x2, 0x2, 0x8e2, 
       0xd3, 0x3, 0x2, 0x2, 0x2, 0x8e3, 0x8e4, 0x5, 0xda, 0x6e, 0x2, 0x8e4, 
       0x8e5, 0x7, 0xaa, 0x2, 0x2, 0x8e5, 0x8e6, 0x5, 0xda, 0x6e, 0x2, 0x8e6, 
       0xd5, 0x3, 0x2, 0x2, 0x2, 0x8e7, 0x8e8, 0x5, 0xda, 0x6e, 0x2, 0x8e8, 
       0x8e9, 0x7, 0xc8, 0x2, 0x2, 0x8e9, 0x8ea, 0x5, 0xda, 0x6e, 0x2, 0x8ea, 
       0xd7, 0x3, 0x2, 0x2, 0x2, 0x8eb, 0x8ec, 0x5, 0xda, 0x6e, 0x2, 0x8ec, 
       0x8ed, 0x7, 0xbc, 0x2, 0x2, 0x8ed, 0x8ee, 0x5, 0xda, 0x6e, 0x2, 0x8ee, 
       0xd9, 0x3, 0x2, 0x2, 0x2, 0x8ef, 0x8f2, 0x9, 0x5, 0x2, 0x2, 0x8f0, 
       0x8f1, 0x7, 0xcb, 0x2, 0x2, 0x8f1, 0x8f3, 0x5, 0xda, 0x6e, 0x2, 0x8f2, 
       0x8f0, 0x3, 0x2, 0x2, 0x2, 0x8f2, 0x8f3, 0x3, 0x2, 0x2, 0x2, 0x8f3, 
       0xdb, 0x3, 0x2, 0x2, 0x2, 0x8f4, 0x8f5, 0x8, 0x6f, 0x1, 0x2, 0x8f5, 
       0x8fb, 0x5, 0xde, 0x70, 0x2, 0x8f6, 0x8fb, 0x5, 0xe0, 0x71, 0x2, 
       0x8f7, 0x8fb, 0x5, 0xe4, 0x73, 0x2, 0x8f8, 0x8fb, 0x5, 0xe8, 0x75, 
       0x2, 0x8f9, 0x8fb, 0x5, 0xe2, 0x72, 0x2, 0x8fa, 0x8f4, 0x3, 0x2, 
       0x2, 0x2, 0x8fa, 0x8f6, 0x3, 0x2, 0x2, 0x2, 0x8fa, 0x8f7, 0x3, 0x2, 
       0x2, 0x2, 0x8fa, 0x8f8, 0x3, 0x2, 0x2, 0x2, 0x8fa, 0x8f9, 0x3, 0x2, 
       0x2, 0x2, 0x8fb, 0x909, 0x3, 0x2, 0x2, 0x2, 0x8fc, 0x8fd, 0xc, 0x3, 
       0x2, 0x2, 0x8fd, 0x8fe, 0x7, 0xc7, 0x2, 0x2, 0x8fe, 0x8ff, 0x5, 0xdc, 
       0x6f, 0x2, 0x8ff, 0x900, 0x7, 0xbc, 0x2, 0x2, 0x900, 0x901, 0x5, 
       0xdc, 0x6f, 0x4, 0x901, 0x908, 0x3, 0x2, 0x2, 0x2, 0x902, 0x903, 
       0xc, 0x4, 0x2, 0x2, 0x903, 0x905, 0x5, 0xe6, 0x74, 0x2, 0x904, 0x906, 
       0x5, 0xdc, 0x6f, 0x2, 0x905, 0x904, 0x3, 0x2, 0x2, 0x2, 0x905, 0x906, 
       0x3, 0x2, 0x2, 0x2, 0x906, 0x908, 0x3, 0x2, 0x2, 0x2, 0x907, 0x8fc, 
       0x3, 0x2, 0x2, 0x2, 0x907, 0x902, 0x3, 0x2, 0x2, 0x2, 0x908, 0x90b, 
       0x3, 0x2, 0x2, 0x2, 0x909, 0x907, 0x3, 0x2, 0x2, 0x2, 0x909, 0x90a, 
       0x3, 0x2, 0x2, 0x2, 0x90a, 0xdd, 0x3, 0x2, 0x2, 0x2, 0x90b, 0x909, 
       0x3, 0x2, 0x2, 0x2, 0x90c, 0x90d, 0x9, 0x6, 0x2, 0x2, 0x90d, 
  };
  static uint16_t serializedATNSegment1[] = {
    0x90e, 0x5, 0xdc, 0x6f, 0x2, 0x90e, 0xdf, 0x3, 0x2, 0x2, 0x2, 0x90f, 
       0x910, 0x7, 0xd9, 0x2, 0x2, 0x910, 0x915, 0x7, 0xc1, 0x2, 0x2, 0x911, 
       0x913, 0x5, 0xdc, 0x6f, 0x2, 0x912, 0x914, 0x7, 0xc8, 0x2, 0x2, 0x913, 
       0x912, 0x3, 0x2, 0x2, 0x2, 0x913, 0x914, 0x3, 0x2, 0x2, 0x2, 0x914, 
       0x916, 0x3, 0x2, 0x2, 0x2, 0x915, 0x911, 0x3, 0x2, 0x2, 0x2, 0x916, 
       0x917, 0x3, 0x2, 0x2, 0x2, 0x917, 0x915, 0x3, 0x2, 0x2, 0x2, 0x917, 
       0x918, 0x3, 0x2, 0x2, 0x2, 0x918, 0x919, 0x3, 0x2, 0x2, 0x2, 0x919, 
       0x91a, 0x7, 0xc2, 0x2, 0x2, 0x91a, 0xe1, 0x3, 0x2, 0x2, 0x2, 0x91b, 
       0x91c, 0x5, 0xe8, 0x75, 0x2, 0x91c, 0x91d, 0x7, 0xc8, 0x2, 0x2, 0x91d, 
       0x91e, 0x5, 0xe8, 0x75, 0x2, 0x91e, 0xe3, 0x3, 0x2, 0x2, 0x2, 0x91f, 
       0x924, 0x9, 0x7, 0x2, 0x2, 0x920, 0x922, 0x5, 0xdc, 0x6f, 0x2, 0x921, 
       0x923, 0x7, 0xc8, 0x2, 0x2, 0x922, 0x921, 0x3, 0x2, 0x2, 0x2, 0x922, 
       0x923, 0x3, 0x2, 0x2, 0x2, 0x923, 0x925, 0x3, 0x2, 0x2, 0x2, 0x924, 
       0x920, 0x3, 0x2, 0x2, 0x2, 0x925, 0x926, 0x3, 0x2, 0x2, 0x2, 0x926, 
       0x924, 0x3, 0x2, 0x2, 0x2, 0x926, 0x927, 0x3, 0x2, 0x2, 0x2, 0x927, 
       0x928, 0x3, 0x2, 0x2, 0x2, 0x928, 0x929, 0x9, 0x8, 0x2, 0x2, 0x929, 
       0xe5, 0x3, 0x2, 0x2, 0x2, 0x92a, 0x92b, 0x9, 0x9, 0x2, 0x2, 0x92b, 
       0xe7, 0x3, 0x2, 0x2, 0x2, 0x92c, 0x934, 0x7, 0xd8, 0x2, 0x2, 0x92d, 
       0x934, 0x7, 0xd9, 0x2, 0x2, 0x92e, 0x934, 0x7, 0xda, 0x2, 0x2, 0x92f, 
       0x934, 0x7, 0xdb, 0x2, 0x2, 0x930, 0x934, 0x5, 0x104, 0x83, 0x2, 
       0x931, 0x934, 0x5, 0x106, 0x84, 0x2, 0x932, 0x934, 0x5, 0x108, 0x85, 
       0x2, 0x933, 0x92c, 0x3, 0x2, 0x2, 0x2, 0x933, 0x92d, 0x3, 0x2, 0x2, 
       0x2, 0x933, 0x92e, 0x3, 0x2, 0x2, 0x2, 0x933, 0x92f, 0x3, 0x2, 0x2, 
       0x2, 0x933, 0x930, 0x3, 0x2, 0x2, 0x2, 0x933, 0x931, 0x3, 0x2, 0x2, 
       0x2, 0x933, 0x932, 0x3, 0x2, 0x2, 0x2, 0x934, 0xe9, 0x3, 0x2, 0x2, 
       0x2, 0x935, 0x937, 0x5, 0xec, 0x77, 0x2, 0x936, 0x935, 0x3, 0x2, 
       0x2, 0x2, 0x937, 0x938, 0x3, 0x2, 0x2, 0x2, 0x938, 0x936, 0x3, 0x2, 
       0x2, 0x2, 0x938, 0x939, 0x3, 0x2, 0x2, 0x2, 0x939, 0xeb, 0x3, 0x2, 
       0x2, 0x2, 0x93a, 0x93b, 0x5, 0xf4, 0x7b, 0x2, 0x93b, 0x93c, 0x7, 
       0xaa, 0x2, 0x2, 0x93c, 0x93d, 0x5, 0xee, 0x78, 0x2, 0x93d, 0x948, 
       0x3, 0x2, 0x2, 0x2, 0x93e, 0x93f, 0x5, 0xf4, 0x7b, 0x2, 0x93f, 0x940, 
       0x7, 0xaa, 0x2, 0x2, 0x940, 0x941, 0x5, 0xdc, 0x6f, 0x2, 0x941, 0x948, 
       0x3, 0x2, 0x2, 0x2, 0x942, 0x943, 0x5, 0xf4, 0x7b, 0x2, 0x943, 0x944, 
       0x7, 0xaa, 0x2, 0x2, 0x944, 0x945, 0x5, 0x100, 0x81, 0x2, 0x945, 
       0x948, 0x3, 0x2, 0x2, 0x2, 0x946, 0x948, 0x5, 0xf4, 0x7b, 0x2, 0x947, 
       0x93a, 0x3, 0x2, 0x2, 0x2, 0x947, 0x93e, 0x3, 0x2, 0x2, 0x2, 0x947, 
       0x942, 0x3, 0x2, 0x2, 0x2, 0x947, 0x946, 0x3, 0x2, 0x2, 0x2, 0x948, 
       0xed, 0x3, 0x2, 0x2, 0x2, 0x949, 0x94d, 0x7, 0xc3, 0x2, 0x2, 0x94a, 
       0x94c, 0x5, 0xf0, 0x79, 0x2, 0x94b, 0x94a, 0x3, 0x2, 0x2, 0x2, 0x94c, 
       0x94f, 0x3, 0x2, 0x2, 0x2, 0x94d, 0x94b, 0x3, 0x2, 0x2, 0x2, 0x94d, 
       0x94e, 0x3, 0x2, 0x2, 0x2, 0x94e, 0x950, 0x3, 0x2, 0x2, 0x2, 0x94f, 
       0x94d, 0x3, 0x2, 0x2, 0x2, 0x950, 0x951, 0x7, 0xc4, 0x2, 0x2, 0x951, 
       0xef, 0x3, 0x2, 0x2, 0x2, 0x952, 0x95a, 0x7, 0xd8, 0x2, 0x2, 0x953, 
       0x95a, 0x7, 0xd9, 0x2, 0x2, 0x954, 0x95a, 0x7, 0xda, 0x2, 0x2, 0x955, 
       0x95a, 0x7, 0xdb, 0x2, 0x2, 0x956, 0x95a, 0x5, 0x104, 0x83, 0x2, 
       0x957, 0x95a, 0x5, 0x106, 0x84, 0x2, 0x958, 0x95a, 0x5, 0x108, 0x85, 
       0x2, 0x959, 0x952, 0x3, 0x2, 0x2, 0x2, 0x959, 0x953, 0x3, 0x2, 0x2, 
       0x2, 0x959, 0x954, 0x3, 0x2, 0x2, 0x2, 0x959, 0x955, 0x3, 0x2, 0x2, 
       0x2, 0x959, 0x956, 0x3, 0x2, 0x2, 0x2, 0x959, 0x957, 0x3, 0x2, 0x2, 
       0x2, 0x959, 0x958, 0x3, 0x2, 0x2, 0x2, 0x95a, 0xf1, 0x3, 0x2, 0x2, 
       0x2, 0x95b, 0x95c, 0x5, 0xf4, 0x7b, 0x2, 0x95c, 0x95d, 0x7, 0xaa, 
       0x2, 0x2, 0x95d, 0x95e, 0x5, 0xdc, 0x6f, 0x2, 0x95e, 0x964, 0x3, 
       0x2, 0x2, 0x2, 0x95f, 0x960, 0x5, 0xf4, 0x7b, 0x2, 0x960, 0x961, 
       0x7, 0xaa, 0x2, 0x2, 0x961, 0x962, 0x5, 0x100, 0x81, 0x2, 0x962, 
       0x964, 0x3, 0x2, 0x2, 0x2, 0x963, 0x95b, 0x3, 0x2, 0x2, 0x2, 0x963, 
       0x95f, 0x3, 0x2, 0x2, 0x2, 0x964, 0xf3, 0x3, 0x2, 0x2, 0x2, 0x965, 
       0x96a, 0x9, 0xa, 0x2, 0x2, 0x966, 0x967, 0x7, 0xbc, 0x2, 0x2, 0x967, 
       0x969, 0x7, 0xd9, 0x2, 0x2, 0x968, 0x966, 0x3, 0x2, 0x2, 0x2, 0x969, 
       0x96c, 0x3, 0x2, 0x2, 0x2, 0x96a, 0x968, 0x3, 0x2, 0x2, 0x2, 0x96a, 
       0x96b, 0x3, 0x2, 0x2, 0x2, 0x96b, 0xf5, 0x3, 0x2, 0x2, 0x2, 0x96c, 
       0x96a, 0x3, 0x2, 0x2, 0x2, 0x96d, 0x96e, 0x7, 0xbc, 0x2, 0x2, 0x96e, 
       0x96f, 0x9, 0x5, 0x2, 0x2, 0x96f, 0xf7, 0x3, 0x2, 0x2, 0x2, 0x970, 
       0x972, 0x7, 0xd9, 0x2, 0x2, 0x971, 0x970, 0x3, 0x2, 0x2, 0x2, 0x971, 
       0x972, 0x3, 0x2, 0x2, 0x2, 0x972, 0x973, 0x3, 0x2, 0x2, 0x2, 0x973, 
       0x977, 0x7, 0xc1, 0x2, 0x2, 0x974, 0x978, 0x5, 0xdc, 0x6f, 0x2, 0x975, 
       0x978, 0x5, 0xd6, 0x6c, 0x2, 0x976, 0x978, 0x5, 0xda, 0x6e, 0x2, 
       0x977, 0x974, 0x3, 0x2, 0x2, 0x2, 0x977, 0x975, 0x3, 0x2, 0x2, 0x2, 
       0x977, 0x976, 0x3, 0x2, 0x2, 0x2, 0x978, 0x979, 0x3, 0x2, 0x2, 0x2, 
       0x979, 0x97a, 0x7, 0xc2, 0x2, 0x2, 0x97a, 0xf9, 0x3, 0x2, 0x2, 0x2, 
       0x97b, 0x97c, 0x5, 0xf8, 0x7d, 0x2, 0x97c, 0x97d, 0x7, 0xaa, 0x2, 
       0x2, 0x97d, 0x97e, 0x5, 0xdc, 0x6f, 0x2, 0x97e, 0xfb, 0x3, 0x2, 0x2, 
       0x2, 0x97f, 0x980, 0x5, 0xfe, 0x80, 0x2, 0x980, 0x981, 0x5, 0xdc, 
       0x6f, 0x2, 0x981, 0x988, 0x3, 0x2, 0x2, 0x2, 0x982, 0x983, 0x5, 0xfe, 
       0x80, 0x2, 0x983, 0x984, 0x7, 0xc5, 0x2, 0x2, 0x984, 0x985, 0x5, 
       0xdc, 0x6f, 0x2, 0x985, 0x986, 0x7, 0xc6, 0x2, 0x2, 0x986, 0x988, 
       0x3, 0x2, 0x2, 0x2, 0x987, 0x97f, 0x3, 0x2, 0x2, 0x2, 0x987, 0x982, 
       0x3, 0x2, 0x2, 0x2, 0x988, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x989, 0x98a, 
       0x5, 0xdc, 0x6f, 0x2, 0x98a, 0xff, 0x3, 0x2, 0x2, 0x2, 0x98b, 0x98c, 
       0x5, 0x102, 0x82, 0x2, 0x98c, 0x101, 0x3, 0x2, 0x2, 0x2, 0x98d, 0x99e, 
       0x7, 0xd9, 0x2, 0x2, 0x98e, 0x99e, 0x7, 0xda, 0x2, 0x2, 0x98f, 0x990, 
       0x7, 0xd9, 0x2, 0x2, 0x990, 0x99e, 0x5, 0x102, 0x82, 0x2, 0x991, 
       0x992, 0x7, 0xd1, 0x2, 0x2, 0x992, 0x993, 0x5, 0x102, 0x82, 0x2, 
       0x993, 0x994, 0x7, 0xd1, 0x2, 0x2, 0x994, 0x99e, 0x3, 0x2, 0x2, 0x2, 
       0x995, 0x996, 0x7, 0xd0, 0x2, 0x2, 0x996, 0x99e, 0x5, 0x102, 0x82, 
       0x2, 0x997, 0x998, 0x7, 0xcb, 0x2, 0x2, 0x998, 0x99e, 0x5, 0x102, 
       0x82, 0x2, 0x999, 0x99a, 0x7, 0xbf, 0x2, 0x2, 0x99a, 0x99e, 0x5, 
       0x102, 0x82, 0x2, 0x99b, 0x99c, 0x7, 0xc9, 0x2, 0x2, 0x99c, 0x99e, 
       0x5, 0x102, 0x82, 0x2, 0x99d, 0x98d, 0x3, 0x2, 0x2, 0x2, 0x99d, 0x98e, 
       0x3, 0x2, 0x2, 0x2, 0x99d, 0x98f, 0x3, 0x2, 0x2, 0x2, 0x99d, 0x991, 
       0x3, 0x2, 0x2, 0x2, 0x99d, 0x995, 0x3, 0x2, 0x2, 0x2, 0x99d, 0x997, 
       0x3, 0x2, 0x2, 0x2, 0x99d, 0x999, 0x3, 0x2, 0x2, 0x2, 0x99d, 0x99b, 
       0x3, 0x2, 0x2, 0x2, 0x99e, 0x103, 0x3, 0x2, 0x2, 0x2, 0x99f, 0x9a0, 
       0x9, 0xb, 0x2, 0x2, 0x9a0, 0x105, 0x3, 0x2, 0x2, 0x2, 0x9a1, 0x9a2, 
       0x9, 0xc, 0x2, 0x2, 0x9a2, 0x107, 0x3, 0x2, 0x2, 0x2, 0x9a3, 0x9a4, 
       0x9, 0xd, 0x2, 0x2, 0x9a4, 0x109, 0x3, 0x2, 0x2, 0x2, 0x1c6, 0x10d, 
       0x114, 0x116, 0x11c, 0x121, 0x129, 0x12e, 0x132, 0x140, 0x145, 0x14a, 
       0x14f, 0x153, 0x15a, 0x15e, 0x163, 0x166, 0x16b, 0x16f, 0x17c, 0x17e, 
       0x184, 0x18d, 0x191, 0x197, 0x19c, 0x1a0, 0x1a6, 0x1af, 0x1b3, 0x1b9, 
       0x1be, 0x1c2, 0x1cb, 0x1cf, 0x1d7, 0x1db, 0x1dd, 0x1e3, 0x1ea, 0x1ef, 
       0x1f5, 0x1fa, 0x1fe, 0x204, 0x20c, 0x213, 0x216, 0x21d, 0x21f, 0x224, 
       0x228, 0x22d, 0x231, 0x24f, 0x252, 0x256, 0x25b, 0x25f, 0x262, 0x268, 
       0x26c, 0x26e, 0x271, 0x275, 0x278, 0x27d, 0x281, 0x284, 0x288, 0x28d, 
       0x291, 0x293, 0x296, 0x29a, 0x29f, 0x2a3, 0x2a6, 0x2ac, 0x2b0, 0x2b2, 
       0x2b5, 0x2b8, 0x2bc, 0x2c1, 0x2c5, 0x2c8, 0x2cb, 0x2d1, 0x2d5, 0x2d7, 
       0x2da, 0x2dd, 0x2e1, 0x2e6, 0x2ea, 0x2ed, 0x2f0, 0x2f6, 0x2fa, 0x2fc, 
       0x2ff, 0x303, 0x308, 0x30c, 0x30f, 0x315, 0x319, 0x31b, 0x31e, 0x322, 
       0x327, 0x32b, 0x32e, 0x334, 0x338, 0x33a, 0x340, 0x345, 0x34b, 0x351, 
       0x358, 0x35c, 0x364, 0x368, 0x36b, 0x36f, 0x374, 0x378, 0x37b, 0x381, 
       0x385, 0x387, 0x38a, 0x38e, 0x393, 0x397, 0x39a, 0x3a0, 0x3a4, 0x3a6, 
       0x3a9, 0x3ac, 0x3b0, 0x3b5, 0x3b9, 0x3bc, 0x3bf, 0x3c5, 0x3c9, 0x3cb, 
       0x3ce, 0x3d1, 0x3d5, 0x3da, 0x3de, 0x3e1, 0x3e4, 0x3ea, 0x3ee, 0x3f0, 
       0x3f3, 0x3f6, 0x3fa, 0x3ff, 0x403, 0x406, 0x409, 0x40f, 0x413, 0x415, 
       0x418, 0x41b, 0x41f, 0x424, 0x428, 0x42b, 0x42e, 0x434, 0x438, 0x43a, 
       0x43d, 0x441, 0x446, 0x44a, 0x44d, 0x453, 0x457, 0x459, 0x45c, 0x45f, 
       0x463, 0x468, 0x46c, 0x46f, 0x472, 0x478, 0x47c, 0x47e, 0x481, 0x484, 
       0x488, 0x48d, 0x491, 0x494, 0x497, 0x49d, 0x4a1, 0x4a3, 0x4a6, 0x4a9, 
       0x4ad, 0x4b2, 0x4b6, 0x4b9, 0x4bc, 0x4c2, 0x4c6, 0x4c8, 0x4cb, 0x4cf, 
       0x4d4, 0x4d8, 0x4db, 0x4e1, 0x4e5, 0x4e7, 0x4ea, 0x4ed, 0x4f1, 0x4f6, 
       0x4fa, 0x4fd, 0x500, 0x506, 0x50a, 0x50c, 0x50f, 0x513, 0x518, 0x51c, 
       0x51f, 0x525, 0x529, 0x52b, 0x52e, 0x531, 0x535, 0x53a, 0x53e, 0x541, 
       0x544, 0x54a, 0x54e, 0x550, 0x553, 0x556, 0x55a, 0x55f, 0x563, 0x566, 
       0x569, 0x56f, 0x573, 0x575, 0x579, 0x57d, 0x581, 0x586, 0x58a, 0x590, 
       0x598, 0x5a0, 0x5a8, 0x5b2, 0x5b8, 0x5bf, 0x5c3, 0x5cc, 0x5d0, 0x5d6, 
       0x5da, 0x5de, 0x5e2, 0x5e7, 0x5eb, 0x5ef, 0x5f5, 0x5f9, 0x5fb, 0x600, 
       0x605, 0x609, 0x610, 0x614, 0x616, 0x61d, 0x621, 0x629, 0x62f, 0x633, 
       0x639, 0x646, 0x64e, 0x652, 0x659, 0x65d, 0x65f, 0x666, 0x66f, 0x676, 
       0x67a, 0x682, 0x686, 0x68f, 0x693, 0x69b, 0x69f, 0x6a1, 0x6a9, 0x6ad, 
       0x6b5, 0x6b9, 0x6c0, 0x6c4, 0x6c6, 0x6ce, 0x6d2, 0x6d9, 0x6dd, 0x6df, 
       0x6e7, 0x6eb, 0x6f2, 0x6f6, 0x6f8, 0x700, 0x704, 0x70b, 0x70f, 0x711, 
       0x719, 0x71d, 0x724, 0x728, 0x72a, 0x72e, 0x735, 0x739, 0x740, 0x744, 
       0x74a, 0x74e, 0x750, 0x756, 0x75e, 0x765, 0x76d, 0x773, 0x777, 0x77d, 
       0x784, 0x78a, 0x790, 0x794, 0x79a, 0x7a1, 0x7a7, 0x7ad, 0x7b1, 0x7ba, 
       0x7c0, 0x7c4, 0x7cd, 0x7d3, 0x7d9, 0x7dd, 0x7df, 0x7e6, 0x7ea, 0x7f2, 
       0x7f6, 0x7fd, 0x801, 0x803, 0x809, 0x810, 0x815, 0x81c, 0x821, 0x827, 
       0x82b, 0x832, 0x836, 0x83d, 0x843, 0x847, 0x84d, 0x852, 0x856, 0x858, 
       0x85c, 0x85f, 0x864, 0x86a, 0x86e, 0x874, 0x87a, 0x87c, 0x87f, 0x883, 
       0x886, 0x88a, 0x890, 0x895, 0x897, 0x89d, 0x8a3, 0x8a8, 0x8aa, 0x8b0, 
       0x8b6, 0x8bb, 0x8bd, 0x8c1, 0x8c6, 0x8cb, 0x8cd, 0x8d2, 0x8d8, 0x8dc, 
       0x8e1, 0x8f2, 0x8fa, 0x905, 0x907, 0x909, 0x913, 0x917, 0x922, 0x926, 
       0x933, 0x938, 0x947, 0x94d, 0x959, 0x963, 0x96a, 0x971, 0x977, 0x987, 
       0x99d, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));
  _serializedATN.insert(_serializedATN.end(), serializedATNSegment1,
    serializedATNSegment1 + sizeof(serializedATNSegment1) / sizeof(serializedATNSegment1[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

SPECTREParser::Initializer SPECTREParser::_init;
