
    #include <vector>
    #include <string>


// Generated from CACT.g4 by ANTLR 4.8


#include "CACTListener.h"

#include "CACTParser.h"


using namespace antlrcpp;
using namespace antlr4;

CACTParser::CACTParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

CACTParser::~CACTParser() {
  delete _interpreter;
}

std::string CACTParser::getGrammarFileName() const {
  return "CACT.g4";
}

const std::vector<std::string>& CACTParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& CACTParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- CompUnitContext ------------------------------------------------------------------

CACTParser::CompUnitContext::CompUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::CompUnitContext::EOF() {
  return getToken(CACTParser::EOF, 0);
}

std::vector<CACTParser::DeclContext *> CACTParser::CompUnitContext::decl() {
  return getRuleContexts<CACTParser::DeclContext>();
}

CACTParser::DeclContext* CACTParser::CompUnitContext::decl(size_t i) {
  return getRuleContext<CACTParser::DeclContext>(i);
}

std::vector<CACTParser::FuncDefContext *> CACTParser::CompUnitContext::funcDef() {
  return getRuleContexts<CACTParser::FuncDefContext>();
}

CACTParser::FuncDefContext* CACTParser::CompUnitContext::funcDef(size_t i) {
  return getRuleContext<CACTParser::FuncDefContext>(i);
}


size_t CACTParser::CompUnitContext::getRuleIndex() const {
  return CACTParser::RuleCompUnit;
}

void CACTParser::CompUnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompUnit(this);
}

void CACTParser::CompUnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompUnit(this);
}

CACTParser::CompUnitContext* CACTParser::compUnit() {
  CompUnitContext *_localctx = _tracker.createInstance<CompUnitContext>(_ctx, getState());
  enterRule(_localctx, 0, CACTParser::RuleCompUnit);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(60); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(60);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
      case 1: {
        setState(58);
        decl();
        break;
      }

      case 2: {
        setState(59);
        funcDef();
        break;
      }

      }
      setState(62); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__0)
      | (1ULL << CACTParser::T__3)
      | (1ULL << CACTParser::T__4)
      | (1ULL << CACTParser::T__5)
      | (1ULL << CACTParser::T__6)
      | (1ULL << CACTParser::T__13))) != 0));
    setState(64);
    match(CACTParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclContext ------------------------------------------------------------------

CACTParser::DeclContext::DeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::ConstDeclContext* CACTParser::DeclContext::constDecl() {
  return getRuleContext<CACTParser::ConstDeclContext>(0);
}

CACTParser::VarDeclContext* CACTParser::DeclContext::varDecl() {
  return getRuleContext<CACTParser::VarDeclContext>(0);
}


size_t CACTParser::DeclContext::getRuleIndex() const {
  return CACTParser::RuleDecl;
}

void CACTParser::DeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDecl(this);
}

void CACTParser::DeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDecl(this);
}

CACTParser::DeclContext* CACTParser::decl() {
  DeclContext *_localctx = _tracker.createInstance<DeclContext>(_ctx, getState());
  enterRule(_localctx, 2, CACTParser::RuleDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(68);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(66);
        constDecl();
        break;
      }

      case CACTParser::T__3:
      case CACTParser::T__4:
      case CACTParser::T__5:
      case CACTParser::T__6: {
        enterOuterAlt(_localctx, 2);
        setState(67);
        varDecl();
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

//----------------- ConstDeclContext ------------------------------------------------------------------

CACTParser::ConstDeclContext::ConstDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::BTypeContext* CACTParser::ConstDeclContext::bType() {
  return getRuleContext<CACTParser::BTypeContext>(0);
}

std::vector<CACTParser::ConstDefContext *> CACTParser::ConstDeclContext::constDef() {
  return getRuleContexts<CACTParser::ConstDefContext>();
}

CACTParser::ConstDefContext* CACTParser::ConstDeclContext::constDef(size_t i) {
  return getRuleContext<CACTParser::ConstDefContext>(i);
}


size_t CACTParser::ConstDeclContext::getRuleIndex() const {
  return CACTParser::RuleConstDecl;
}

void CACTParser::ConstDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstDecl(this);
}

void CACTParser::ConstDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstDecl(this);
}

CACTParser::ConstDeclContext* CACTParser::constDecl() {
  ConstDeclContext *_localctx = _tracker.createInstance<ConstDeclContext>(_ctx, getState());
  enterRule(_localctx, 4, CACTParser::RuleConstDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(70);
    match(CACTParser::T__0);
    setState(71);
    bType();
    setState(72);
    constDef();
    setState(77);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::T__1) {
      setState(73);
      match(CACTParser::T__1);
      setState(74);
      constDef();
      setState(79);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(80);
    match(CACTParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BTypeContext ------------------------------------------------------------------

CACTParser::BTypeContext::BTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::BTypeContext::getRuleIndex() const {
  return CACTParser::RuleBType;
}

void CACTParser::BTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBType(this);
}

void CACTParser::BTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBType(this);
}

CACTParser::BTypeContext* CACTParser::bType() {
  BTypeContext *_localctx = _tracker.createInstance<BTypeContext>(_ctx, getState());
  enterRule(_localctx, 6, CACTParser::RuleBType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(82);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__3)
      | (1ULL << CACTParser::T__4)
      | (1ULL << CACTParser::T__5)
      | (1ULL << CACTParser::T__6))) != 0))) {
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

//----------------- ConstDefContext ------------------------------------------------------------------

CACTParser::ConstDefContext::ConstDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::ConstDefContext::getRuleIndex() const {
  return CACTParser::RuleConstDef;
}

void CACTParser::ConstDefContext::copyFrom(ConstDefContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ConstDefArrayContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::ConstDefArrayContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

tree::TerminalNode* CACTParser::ConstDefArrayContext::IntConst() {
  return getToken(CACTParser::IntConst, 0);
}

tree::TerminalNode* CACTParser::ConstDefArrayContext::LeftBigBracket() {
  return getToken(CACTParser::LeftBigBracket, 0);
}

std::vector<CACTParser::ConstExpContext *> CACTParser::ConstDefArrayContext::constExp() {
  return getRuleContexts<CACTParser::ConstExpContext>();
}

CACTParser::ConstExpContext* CACTParser::ConstDefArrayContext::constExp(size_t i) {
  return getRuleContext<CACTParser::ConstExpContext>(i);
}

CACTParser::ConstDefArrayContext::ConstDefArrayContext(ConstDefContext *ctx) { copyFrom(ctx); }

void CACTParser::ConstDefArrayContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstDefArray(this);
}
void CACTParser::ConstDefArrayContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstDefArray(this);
}
//----------------- ConstDefValContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::ConstDefValContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::ConstExpContext* CACTParser::ConstDefValContext::constExp() {
  return getRuleContext<CACTParser::ConstExpContext>(0);
}

CACTParser::ConstDefValContext::ConstDefValContext(ConstDefContext *ctx) { copyFrom(ctx); }

void CACTParser::ConstDefValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstDefVal(this);
}
void CACTParser::ConstDefValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstDefVal(this);
}
CACTParser::ConstDefContext* CACTParser::constDef() {
  ConstDefContext *_localctx = _tracker.createInstance<ConstDefContext>(_ctx, getState());
  enterRule(_localctx, 8, CACTParser::RuleConstDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(104);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<ConstDefContext *>(_tracker.createInstance<CACTParser::ConstDefValContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(84);
      match(CACTParser::Ident);
      setState(85);
      match(CACTParser::T__7);
      setState(86);
      constExp();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<ConstDefContext *>(_tracker.createInstance<CACTParser::ConstDefArrayContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(87);
      match(CACTParser::Ident);
      setState(88);
      match(CACTParser::T__8);
      setState(89);
      match(CACTParser::IntConst);
      setState(90);
      match(CACTParser::T__9);
      setState(91);
      match(CACTParser::T__7);
      setState(92);
      match(CACTParser::LeftBigBracket);
      setState(101);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CACTParser::BoolConst)
        | (1ULL << CACTParser::IntConst)
        | (1ULL << CACTParser::DoubleConst)
        | (1ULL << CACTParser::FloatConst))) != 0)) {
        setState(93);
        constExp();
        setState(98);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CACTParser::T__1) {
          setState(94);
          match(CACTParser::T__1);
          setState(95);
          constExp();
          setState(100);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(103);
      match(CACTParser::T__10);
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

//----------------- ConstExpContext ------------------------------------------------------------------

CACTParser::ConstExpContext::ConstExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::ConstExpContext::getRuleIndex() const {
  return CACTParser::RuleConstExp;
}

void CACTParser::ConstExpContext::copyFrom(ConstExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->name = ctx->name;
  this->cls = ctx->cls;
}

//----------------- ConstExpBoolConstContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::ConstExpBoolConstContext::BoolConst() {
  return getToken(CACTParser::BoolConst, 0);
}

CACTParser::ConstExpBoolConstContext::ConstExpBoolConstContext(ConstExpContext *ctx) { copyFrom(ctx); }

void CACTParser::ConstExpBoolConstContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstExpBoolConst(this);
}
void CACTParser::ConstExpBoolConstContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstExpBoolConst(this);
}
//----------------- ConstExpNumberContext ------------------------------------------------------------------

CACTParser::NumberContext* CACTParser::ConstExpNumberContext::number() {
  return getRuleContext<CACTParser::NumberContext>(0);
}

CACTParser::ConstExpNumberContext::ConstExpNumberContext(ConstExpContext *ctx) { copyFrom(ctx); }

void CACTParser::ConstExpNumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstExpNumber(this);
}
void CACTParser::ConstExpNumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstExpNumber(this);
}
CACTParser::ConstExpContext* CACTParser::constExp() {
  ConstExpContext *_localctx = _tracker.createInstance<ConstExpContext>(_ctx, getState());
  enterRule(_localctx, 10, CACTParser::RuleConstExp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(108);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::IntConst:
      case CACTParser::DoubleConst:
      case CACTParser::FloatConst: {
        _localctx = dynamic_cast<ConstExpContext *>(_tracker.createInstance<CACTParser::ConstExpNumberContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(106);
        number();
        break;
      }

      case CACTParser::BoolConst: {
        _localctx = dynamic_cast<ConstExpContext *>(_tracker.createInstance<CACTParser::ConstExpBoolConstContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(107);
        match(CACTParser::BoolConst);
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

//----------------- VarDeclContext ------------------------------------------------------------------

CACTParser::VarDeclContext::VarDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::BTypeContext* CACTParser::VarDeclContext::bType() {
  return getRuleContext<CACTParser::BTypeContext>(0);
}

std::vector<CACTParser::VarDefContext *> CACTParser::VarDeclContext::varDef() {
  return getRuleContexts<CACTParser::VarDefContext>();
}

CACTParser::VarDefContext* CACTParser::VarDeclContext::varDef(size_t i) {
  return getRuleContext<CACTParser::VarDefContext>(i);
}


size_t CACTParser::VarDeclContext::getRuleIndex() const {
  return CACTParser::RuleVarDecl;
}

void CACTParser::VarDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDecl(this);
}

void CACTParser::VarDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDecl(this);
}

CACTParser::VarDeclContext* CACTParser::varDecl() {
  VarDeclContext *_localctx = _tracker.createInstance<VarDeclContext>(_ctx, getState());
  enterRule(_localctx, 12, CACTParser::RuleVarDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(110);
    bType();
    setState(111);
    varDef();
    setState(116);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::T__1) {
      setState(112);
      match(CACTParser::T__1);
      setState(113);
      varDef();
      setState(118);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(119);
    match(CACTParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDefContext ------------------------------------------------------------------

CACTParser::VarDefContext::VarDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::VarDefContext::getRuleIndex() const {
  return CACTParser::RuleVarDef;
}

void CACTParser::VarDefContext::copyFrom(VarDefContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- VarDefInitArrayContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::VarDefInitArrayContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

tree::TerminalNode* CACTParser::VarDefInitArrayContext::IntConst() {
  return getToken(CACTParser::IntConst, 0);
}

tree::TerminalNode* CACTParser::VarDefInitArrayContext::LeftBigBracket() {
  return getToken(CACTParser::LeftBigBracket, 0);
}

std::vector<CACTParser::ConstExpContext *> CACTParser::VarDefInitArrayContext::constExp() {
  return getRuleContexts<CACTParser::ConstExpContext>();
}

CACTParser::ConstExpContext* CACTParser::VarDefInitArrayContext::constExp(size_t i) {
  return getRuleContext<CACTParser::ConstExpContext>(i);
}

CACTParser::VarDefInitArrayContext::VarDefInitArrayContext(VarDefContext *ctx) { copyFrom(ctx); }

void CACTParser::VarDefInitArrayContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDefInitArray(this);
}
void CACTParser::VarDefInitArrayContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDefInitArray(this);
}
//----------------- VarDefInitValContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::VarDefInitValContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::ConstExpContext* CACTParser::VarDefInitValContext::constExp() {
  return getRuleContext<CACTParser::ConstExpContext>(0);
}

CACTParser::VarDefInitValContext::VarDefInitValContext(VarDefContext *ctx) { copyFrom(ctx); }

void CACTParser::VarDefInitValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDefInitVal(this);
}
void CACTParser::VarDefInitValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDefInitVal(this);
}
//----------------- VarDefValContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::VarDefValContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::VarDefValContext::VarDefValContext(VarDefContext *ctx) { copyFrom(ctx); }

void CACTParser::VarDefValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDefVal(this);
}
void CACTParser::VarDefValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDefVal(this);
}
//----------------- VarDefArrayContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::VarDefArrayContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

tree::TerminalNode* CACTParser::VarDefArrayContext::IntConst() {
  return getToken(CACTParser::IntConst, 0);
}

CACTParser::VarDefArrayContext::VarDefArrayContext(VarDefContext *ctx) { copyFrom(ctx); }

void CACTParser::VarDefArrayContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDefArray(this);
}
void CACTParser::VarDefArrayContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDefArray(this);
}
CACTParser::VarDefContext* CACTParser::varDef() {
  VarDefContext *_localctx = _tracker.createInstance<VarDefContext>(_ctx, getState());
  enterRule(_localctx, 14, CACTParser::RuleVarDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(146);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<VarDefContext *>(_tracker.createInstance<CACTParser::VarDefValContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(121);
      match(CACTParser::Ident);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<VarDefContext *>(_tracker.createInstance<CACTParser::VarDefArrayContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(122);
      match(CACTParser::Ident);
      setState(123);
      match(CACTParser::T__8);
      setState(124);
      match(CACTParser::IntConst);
      setState(125);
      match(CACTParser::T__9);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<VarDefContext *>(_tracker.createInstance<CACTParser::VarDefInitValContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(126);
      match(CACTParser::Ident);
      setState(127);
      match(CACTParser::T__7);
      setState(128);
      constExp();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<VarDefContext *>(_tracker.createInstance<CACTParser::VarDefInitArrayContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(129);
      match(CACTParser::Ident);
      setState(130);
      match(CACTParser::T__8);
      setState(131);
      match(CACTParser::IntConst);
      setState(132);
      match(CACTParser::T__9);
      setState(133);
      match(CACTParser::T__7);
      setState(134);
      match(CACTParser::LeftBigBracket);
      setState(143);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CACTParser::BoolConst)
        | (1ULL << CACTParser::IntConst)
        | (1ULL << CACTParser::DoubleConst)
        | (1ULL << CACTParser::FloatConst))) != 0)) {
        setState(135);
        constExp();
        setState(140);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CACTParser::T__1) {
          setState(136);
          match(CACTParser::T__1);
          setState(137);
          constExp();
          setState(142);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(145);
      match(CACTParser::T__10);
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

//----------------- FuncDefContext ------------------------------------------------------------------

CACTParser::FuncDefContext::FuncDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::BlockContext* CACTParser::FuncDefContext::block() {
  return getRuleContext<CACTParser::BlockContext>(0);
}

CACTParser::FuncTypeContext* CACTParser::FuncDefContext::funcType() {
  return getRuleContext<CACTParser::FuncTypeContext>(0);
}

tree::TerminalNode* CACTParser::FuncDefContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

std::vector<CACTParser::FuncFParamContext *> CACTParser::FuncDefContext::funcFParam() {
  return getRuleContexts<CACTParser::FuncFParamContext>();
}

CACTParser::FuncFParamContext* CACTParser::FuncDefContext::funcFParam(size_t i) {
  return getRuleContext<CACTParser::FuncFParamContext>(i);
}


size_t CACTParser::FuncDefContext::getRuleIndex() const {
  return CACTParser::RuleFuncDef;
}

void CACTParser::FuncDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncDef(this);
}

void CACTParser::FuncDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncDef(this);
}

CACTParser::FuncDefContext* CACTParser::funcDef() {
  FuncDefContext *_localctx = _tracker.createInstance<FuncDefContext>(_ctx, getState());
  enterRule(_localctx, 16, CACTParser::RuleFuncDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(148);
    dynamic_cast<FuncDefContext *>(_localctx)->ret = funcType();
    setState(149);
    dynamic_cast<FuncDefContext *>(_localctx)->name = match(CACTParser::Ident);
    setState(150);
    match(CACTParser::T__11);
    setState(159);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__3)
      | (1ULL << CACTParser::T__4)
      | (1ULL << CACTParser::T__5)
      | (1ULL << CACTParser::T__6))) != 0)) {
      setState(151);
      funcFParam();
      setState(156);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CACTParser::T__1) {
        setState(152);
        match(CACTParser::T__1);
        setState(153);
        funcFParam();
        setState(158);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(161);
    match(CACTParser::T__12);
    setState(162);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncTypeContext ------------------------------------------------------------------

CACTParser::FuncTypeContext::FuncTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::FuncTypeContext::getRuleIndex() const {
  return CACTParser::RuleFuncType;
}

void CACTParser::FuncTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncType(this);
}

void CACTParser::FuncTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncType(this);
}

CACTParser::FuncTypeContext* CACTParser::funcType() {
  FuncTypeContext *_localctx = _tracker.createInstance<FuncTypeContext>(_ctx, getState());
  enterRule(_localctx, 18, CACTParser::RuleFuncType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(164);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__3)
      | (1ULL << CACTParser::T__4)
      | (1ULL << CACTParser::T__5)
      | (1ULL << CACTParser::T__6)
      | (1ULL << CACTParser::T__13))) != 0))) {
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

//----------------- FuncFParamContext ------------------------------------------------------------------

CACTParser::FuncFParamContext::FuncFParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::BTypeContext* CACTParser::FuncFParamContext::bType() {
  return getRuleContext<CACTParser::BTypeContext>(0);
}

tree::TerminalNode* CACTParser::FuncFParamContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}


size_t CACTParser::FuncFParamContext::getRuleIndex() const {
  return CACTParser::RuleFuncFParam;
}

void CACTParser::FuncFParamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncFParam(this);
}

void CACTParser::FuncFParamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncFParam(this);
}

CACTParser::FuncFParamContext* CACTParser::funcFParam() {
  FuncFParamContext *_localctx = _tracker.createInstance<FuncFParamContext>(_ctx, getState());
  enterRule(_localctx, 20, CACTParser::RuleFuncFParam);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(166);
    bType();
    setState(167);
    match(CACTParser::Ident);
    setState(170);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CACTParser::T__8) {
      setState(168);
      match(CACTParser::T__8);
      setState(169);
      match(CACTParser::T__9);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

CACTParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::BlockContext::LeftBigBracket() {
  return getToken(CACTParser::LeftBigBracket, 0);
}

std::vector<CACTParser::BlockltemContext *> CACTParser::BlockContext::blockltem() {
  return getRuleContexts<CACTParser::BlockltemContext>();
}

CACTParser::BlockltemContext* CACTParser::BlockContext::blockltem(size_t i) {
  return getRuleContext<CACTParser::BlockltemContext>(i);
}


size_t CACTParser::BlockContext::getRuleIndex() const {
  return CACTParser::RuleBlock;
}

void CACTParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void CACTParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}

CACTParser::BlockContext* CACTParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 22, CACTParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(172);
    match(CACTParser::LeftBigBracket);
    setState(176);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__0)
      | (1ULL << CACTParser::T__2)
      | (1ULL << CACTParser::T__3)
      | (1ULL << CACTParser::T__4)
      | (1ULL << CACTParser::T__5)
      | (1ULL << CACTParser::T__6)
      | (1ULL << CACTParser::T__11)
      | (1ULL << CACTParser::T__14)
      | (1ULL << CACTParser::T__15)
      | (1ULL << CACTParser::T__16)
      | (1ULL << CACTParser::T__17)
      | (1ULL << CACTParser::T__18)
      | (1ULL << CACTParser::T__20)
      | (1ULL << CACTParser::T__21)
      | (1ULL << CACTParser::T__22)
      | (1ULL << CACTParser::BoolConst)
      | (1ULL << CACTParser::LeftBigBracket)
      | (1ULL << CACTParser::Ident)
      | (1ULL << CACTParser::IntConst)
      | (1ULL << CACTParser::DoubleConst)
      | (1ULL << CACTParser::FloatConst))) != 0)) {
      setState(173);
      blockltem();
      setState(178);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(179);
    match(CACTParser::T__10);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockltemContext ------------------------------------------------------------------

CACTParser::BlockltemContext::BlockltemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::DeclContext* CACTParser::BlockltemContext::decl() {
  return getRuleContext<CACTParser::DeclContext>(0);
}

CACTParser::StmtContext* CACTParser::BlockltemContext::stmt() {
  return getRuleContext<CACTParser::StmtContext>(0);
}


size_t CACTParser::BlockltemContext::getRuleIndex() const {
  return CACTParser::RuleBlockltem;
}

void CACTParser::BlockltemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockltem(this);
}

void CACTParser::BlockltemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockltem(this);
}

CACTParser::BlockltemContext* CACTParser::blockltem() {
  BlockltemContext *_localctx = _tracker.createInstance<BlockltemContext>(_ctx, getState());
  enterRule(_localctx, 24, CACTParser::RuleBlockltem);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(183);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::T__0:
      case CACTParser::T__3:
      case CACTParser::T__4:
      case CACTParser::T__5:
      case CACTParser::T__6: {
        enterOuterAlt(_localctx, 1);
        setState(181);
        decl();
        break;
      }

      case CACTParser::T__2:
      case CACTParser::T__11:
      case CACTParser::T__14:
      case CACTParser::T__15:
      case CACTParser::T__16:
      case CACTParser::T__17:
      case CACTParser::T__18:
      case CACTParser::T__20:
      case CACTParser::T__21:
      case CACTParser::T__22:
      case CACTParser::BoolConst:
      case CACTParser::LeftBigBracket:
      case CACTParser::Ident:
      case CACTParser::IntConst:
      case CACTParser::DoubleConst:
      case CACTParser::FloatConst: {
        enterOuterAlt(_localctx, 2);
        setState(182);
        stmt();
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

//----------------- StmtContext ------------------------------------------------------------------

CACTParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::StmtContext::getRuleIndex() const {
  return CACTParser::RuleStmt;
}

void CACTParser::StmtContext::copyFrom(StmtContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExprStmtContext ------------------------------------------------------------------

CACTParser::ExpContext* CACTParser::ExprStmtContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::ExprStmtContext::ExprStmtContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::ExprStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprStmt(this);
}
void CACTParser::ExprStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprStmt(this);
}
//----------------- WhileStmtContext ------------------------------------------------------------------

CACTParser::CondContext* CACTParser::WhileStmtContext::cond() {
  return getRuleContext<CACTParser::CondContext>(0);
}

CACTParser::StmtContext* CACTParser::WhileStmtContext::stmt() {
  return getRuleContext<CACTParser::StmtContext>(0);
}

CACTParser::WhileStmtContext::WhileStmtContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::WhileStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileStmt(this);
}
void CACTParser::WhileStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileStmt(this);
}
//----------------- IfStmtContext ------------------------------------------------------------------

CACTParser::CondContext* CACTParser::IfStmtContext::cond() {
  return getRuleContext<CACTParser::CondContext>(0);
}

CACTParser::StmtContext* CACTParser::IfStmtContext::stmt() {
  return getRuleContext<CACTParser::StmtContext>(0);
}

CACTParser::IfStmtContext::IfStmtContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::IfStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStmt(this);
}
void CACTParser::IfStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStmt(this);
}
//----------------- BlockStmtContext ------------------------------------------------------------------

CACTParser::BlockContext* CACTParser::BlockStmtContext::block() {
  return getRuleContext<CACTParser::BlockContext>(0);
}

CACTParser::BlockStmtContext::BlockStmtContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::BlockStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockStmt(this);
}
void CACTParser::BlockStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockStmt(this);
}
//----------------- IfElseStmtContext ------------------------------------------------------------------

CACTParser::CondContext* CACTParser::IfElseStmtContext::cond() {
  return getRuleContext<CACTParser::CondContext>(0);
}

CACTParser::StmtContext* CACTParser::IfElseStmtContext::stmt() {
  return getRuleContext<CACTParser::StmtContext>(0);
}

CACTParser::ElseStmtContext* CACTParser::IfElseStmtContext::elseStmt() {
  return getRuleContext<CACTParser::ElseStmtContext>(0);
}

CACTParser::IfElseStmtContext::IfElseStmtContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::IfElseStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfElseStmt(this);
}
void CACTParser::IfElseStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfElseStmt(this);
}
//----------------- AssignStmtContext ------------------------------------------------------------------

CACTParser::LValContext* CACTParser::AssignStmtContext::lVal() {
  return getRuleContext<CACTParser::LValContext>(0);
}

CACTParser::ExpContext* CACTParser::AssignStmtContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::AssignStmtContext::AssignStmtContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::AssignStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignStmt(this);
}
void CACTParser::AssignStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignStmt(this);
}
//----------------- BreakStmtContext ------------------------------------------------------------------

CACTParser::BreakStmtContext::BreakStmtContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::BreakStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBreakStmt(this);
}
void CACTParser::BreakStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBreakStmt(this);
}
//----------------- ReturnStmtContext ------------------------------------------------------------------

CACTParser::ExpContext* CACTParser::ReturnStmtContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::ReturnStmtContext::ReturnStmtContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::ReturnStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStmt(this);
}
void CACTParser::ReturnStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStmt(this);
}
//----------------- ContinueStmtContext ------------------------------------------------------------------

CACTParser::ContinueStmtContext::ContinueStmtContext(StmtContext *ctx) { copyFrom(ctx); }

void CACTParser::ContinueStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterContinueStmt(this);
}
void CACTParser::ContinueStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitContinueStmt(this);
}
CACTParser::StmtContext* CACTParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 26, CACTParser::RuleStmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(223);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::AssignStmtContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(185);
      lVal();
      setState(186);
      match(CACTParser::T__7);
      setState(187);
      exp();
      setState(188);
      match(CACTParser::T__2);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::ExprStmtContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(191);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CACTParser::T__11)
        | (1ULL << CACTParser::T__20)
        | (1ULL << CACTParser::T__21)
        | (1ULL << CACTParser::T__22)
        | (1ULL << CACTParser::BoolConst)
        | (1ULL << CACTParser::Ident)
        | (1ULL << CACTParser::IntConst)
        | (1ULL << CACTParser::DoubleConst)
        | (1ULL << CACTParser::FloatConst))) != 0)) {
        setState(190);
        exp();
      }
      setState(193);
      match(CACTParser::T__2);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::BlockStmtContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(194);
      block();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::IfStmtContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(195);
      match(CACTParser::T__14);
      setState(196);
      match(CACTParser::T__11);
      setState(197);
      cond();
      setState(198);
      match(CACTParser::T__12);
      setState(199);
      stmt();
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::IfElseStmtContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(201);
      match(CACTParser::T__14);
      setState(202);
      match(CACTParser::T__11);
      setState(203);
      cond();
      setState(204);
      match(CACTParser::T__12);
      setState(205);
      stmt();
      setState(206);
      elseStmt();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::WhileStmtContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(208);
      match(CACTParser::T__15);
      setState(209);
      match(CACTParser::T__11);
      setState(210);
      cond();
      setState(211);
      match(CACTParser::T__12);
      setState(212);
      stmt();
      break;
    }

    case 7: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::BreakStmtContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(214);
      match(CACTParser::T__16);
      setState(215);
      match(CACTParser::T__2);
      break;
    }

    case 8: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::ContinueStmtContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(216);
      match(CACTParser::T__17);
      setState(217);
      match(CACTParser::T__2);
      break;
    }

    case 9: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<CACTParser::ReturnStmtContext>(_localctx));
      enterOuterAlt(_localctx, 9);
      setState(218);
      match(CACTParser::T__18);
      setState(220);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CACTParser::T__11)
        | (1ULL << CACTParser::T__20)
        | (1ULL << CACTParser::T__21)
        | (1ULL << CACTParser::T__22)
        | (1ULL << CACTParser::BoolConst)
        | (1ULL << CACTParser::Ident)
        | (1ULL << CACTParser::IntConst)
        | (1ULL << CACTParser::DoubleConst)
        | (1ULL << CACTParser::FloatConst))) != 0)) {
        setState(219);
        exp();
      }
      setState(222);
      match(CACTParser::T__2);
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

//----------------- ElseStmtContext ------------------------------------------------------------------

CACTParser::ElseStmtContext::ElseStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::StmtContext* CACTParser::ElseStmtContext::stmt() {
  return getRuleContext<CACTParser::StmtContext>(0);
}


size_t CACTParser::ElseStmtContext::getRuleIndex() const {
  return CACTParser::RuleElseStmt;
}

void CACTParser::ElseStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElseStmt(this);
}

void CACTParser::ElseStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElseStmt(this);
}

CACTParser::ElseStmtContext* CACTParser::elseStmt() {
  ElseStmtContext *_localctx = _tracker.createInstance<ElseStmtContext>(_ctx, getState());
  enterRule(_localctx, 28, CACTParser::RuleElseStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(225);
    match(CACTParser::T__19);
    setState(226);
    stmt();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpContext ------------------------------------------------------------------

CACTParser::ExpContext::ExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::AddExpContext* CACTParser::ExpContext::addExp() {
  return getRuleContext<CACTParser::AddExpContext>(0);
}

tree::TerminalNode* CACTParser::ExpContext::BoolConst() {
  return getToken(CACTParser::BoolConst, 0);
}


size_t CACTParser::ExpContext::getRuleIndex() const {
  return CACTParser::RuleExp;
}

void CACTParser::ExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExp(this);
}

void CACTParser::ExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExp(this);
}

CACTParser::ExpContext* CACTParser::exp() {
  ExpContext *_localctx = _tracker.createInstance<ExpContext>(_ctx, getState());
  enterRule(_localctx, 30, CACTParser::RuleExp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(230);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(228);
      addExp(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(229);
      match(CACTParser::BoolConst);
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

//----------------- CondContext ------------------------------------------------------------------

CACTParser::CondContext::CondContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::LOrExpContext* CACTParser::CondContext::lOrExp() {
  return getRuleContext<CACTParser::LOrExpContext>(0);
}


size_t CACTParser::CondContext::getRuleIndex() const {
  return CACTParser::RuleCond;
}

void CACTParser::CondContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCond(this);
}

void CACTParser::CondContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCond(this);
}

CACTParser::CondContext* CACTParser::cond() {
  CondContext *_localctx = _tracker.createInstance<CondContext>(_ctx, getState());
  enterRule(_localctx, 32, CACTParser::RuleCond);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(232);
    lOrExp(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LValContext ------------------------------------------------------------------

CACTParser::LValContext::LValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::LValContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::ExpContext* CACTParser::LValContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}


size_t CACTParser::LValContext::getRuleIndex() const {
  return CACTParser::RuleLVal;
}

void CACTParser::LValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLVal(this);
}

void CACTParser::LValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLVal(this);
}

CACTParser::LValContext* CACTParser::lVal() {
  LValContext *_localctx = _tracker.createInstance<LValContext>(_ctx, getState());
  enterRule(_localctx, 34, CACTParser::RuleLVal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(234);
    match(CACTParser::Ident);
    setState(239);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      setState(235);
      match(CACTParser::T__8);
      setState(236);
      exp();
      setState(237);
      match(CACTParser::T__9);
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

//----------------- PrimaryExpContext ------------------------------------------------------------------

CACTParser::PrimaryExpContext::PrimaryExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::ExpContext* CACTParser::PrimaryExpContext::exp() {
  return getRuleContext<CACTParser::ExpContext>(0);
}

CACTParser::LValContext* CACTParser::PrimaryExpContext::lVal() {
  return getRuleContext<CACTParser::LValContext>(0);
}

tree::TerminalNode* CACTParser::PrimaryExpContext::BoolConst() {
  return getToken(CACTParser::BoolConst, 0);
}

CACTParser::NumberContext* CACTParser::PrimaryExpContext::number() {
  return getRuleContext<CACTParser::NumberContext>(0);
}


size_t CACTParser::PrimaryExpContext::getRuleIndex() const {
  return CACTParser::RulePrimaryExp;
}

void CACTParser::PrimaryExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimaryExp(this);
}

void CACTParser::PrimaryExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimaryExp(this);
}

CACTParser::PrimaryExpContext* CACTParser::primaryExp() {
  PrimaryExpContext *_localctx = _tracker.createInstance<PrimaryExpContext>(_ctx, getState());
  enterRule(_localctx, 36, CACTParser::RulePrimaryExp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(248);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CACTParser::T__11: {
        enterOuterAlt(_localctx, 1);
        setState(241);
        match(CACTParser::T__11);
        setState(242);
        exp();
        setState(243);
        match(CACTParser::T__12);
        break;
      }

      case CACTParser::Ident: {
        enterOuterAlt(_localctx, 2);
        setState(245);
        lVal();
        break;
      }

      case CACTParser::BoolConst: {
        enterOuterAlt(_localctx, 3);
        setState(246);
        match(CACTParser::BoolConst);
        break;
      }

      case CACTParser::IntConst:
      case CACTParser::DoubleConst:
      case CACTParser::FloatConst: {
        enterOuterAlt(_localctx, 4);
        setState(247);
        number();
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

//----------------- UnaryExpContext ------------------------------------------------------------------

CACTParser::UnaryExpContext::UnaryExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::UnaryExpContext::getRuleIndex() const {
  return CACTParser::RuleUnaryExp;
}

void CACTParser::UnaryExpContext::copyFrom(UnaryExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->name = ctx->name;
  this->cls = ctx->cls;
  this->elemwise = ctx->elemwise;
}

//----------------- FuncCallContext ------------------------------------------------------------------

tree::TerminalNode* CACTParser::FuncCallContext::Ident() {
  return getToken(CACTParser::Ident, 0);
}

CACTParser::FuncRParamsContext* CACTParser::FuncCallContext::funcRParams() {
  return getRuleContext<CACTParser::FuncRParamsContext>(0);
}

CACTParser::FuncCallContext::FuncCallContext(UnaryExpContext *ctx) { copyFrom(ctx); }

void CACTParser::FuncCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncCall(this);
}
void CACTParser::FuncCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncCall(this);
}
//----------------- UnaryContext ------------------------------------------------------------------

CACTParser::UnaryOpContext* CACTParser::UnaryContext::unaryOp() {
  return getRuleContext<CACTParser::UnaryOpContext>(0);
}

CACTParser::UnaryExpContext* CACTParser::UnaryContext::unaryExp() {
  return getRuleContext<CACTParser::UnaryExpContext>(0);
}

CACTParser::UnaryContext::UnaryContext(UnaryExpContext *ctx) { copyFrom(ctx); }

void CACTParser::UnaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnary(this);
}
void CACTParser::UnaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnary(this);
}
//----------------- PrimaryContext ------------------------------------------------------------------

CACTParser::PrimaryExpContext* CACTParser::PrimaryContext::primaryExp() {
  return getRuleContext<CACTParser::PrimaryExpContext>(0);
}

CACTParser::PrimaryContext::PrimaryContext(UnaryExpContext *ctx) { copyFrom(ctx); }

void CACTParser::PrimaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimary(this);
}
void CACTParser::PrimaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimary(this);
}
CACTParser::UnaryExpContext* CACTParser::unaryExp() {
  UnaryExpContext *_localctx = _tracker.createInstance<UnaryExpContext>(_ctx, getState());
  enterRule(_localctx, 38, CACTParser::RuleUnaryExp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(260);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<UnaryExpContext *>(_tracker.createInstance<CACTParser::PrimaryContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(250);
      primaryExp();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<UnaryExpContext *>(_tracker.createInstance<CACTParser::FuncCallContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(251);
      match(CACTParser::Ident);
      setState(252);
      match(CACTParser::T__11);
      setState(254);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CACTParser::T__11)
        | (1ULL << CACTParser::T__20)
        | (1ULL << CACTParser::T__21)
        | (1ULL << CACTParser::T__22)
        | (1ULL << CACTParser::BoolConst)
        | (1ULL << CACTParser::Ident)
        | (1ULL << CACTParser::IntConst)
        | (1ULL << CACTParser::DoubleConst)
        | (1ULL << CACTParser::FloatConst))) != 0)) {
        setState(253);
        funcRParams();
      }
      setState(256);
      match(CACTParser::T__12);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<UnaryExpContext *>(_tracker.createInstance<CACTParser::UnaryContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(257);
      unaryOp();
      setState(258);
      unaryExp();
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

//----------------- NumberContext ------------------------------------------------------------------

CACTParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CACTParser::NumberContext::IntConst() {
  return getToken(CACTParser::IntConst, 0);
}

tree::TerminalNode* CACTParser::NumberContext::DoubleConst() {
  return getToken(CACTParser::DoubleConst, 0);
}

tree::TerminalNode* CACTParser::NumberContext::FloatConst() {
  return getToken(CACTParser::FloatConst, 0);
}


size_t CACTParser::NumberContext::getRuleIndex() const {
  return CACTParser::RuleNumber;
}

void CACTParser::NumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumber(this);
}

void CACTParser::NumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumber(this);
}

CACTParser::NumberContext* CACTParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 40, CACTParser::RuleNumber);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(262);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::IntConst)
      | (1ULL << CACTParser::DoubleConst)
      | (1ULL << CACTParser::FloatConst))) != 0))) {
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

//----------------- FuncRParamsContext ------------------------------------------------------------------

CACTParser::FuncRParamsContext::FuncRParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CACTParser::ExpContext *> CACTParser::FuncRParamsContext::exp() {
  return getRuleContexts<CACTParser::ExpContext>();
}

CACTParser::ExpContext* CACTParser::FuncRParamsContext::exp(size_t i) {
  return getRuleContext<CACTParser::ExpContext>(i);
}


size_t CACTParser::FuncRParamsContext::getRuleIndex() const {
  return CACTParser::RuleFuncRParams;
}

void CACTParser::FuncRParamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncRParams(this);
}

void CACTParser::FuncRParamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncRParams(this);
}

CACTParser::FuncRParamsContext* CACTParser::funcRParams() {
  FuncRParamsContext *_localctx = _tracker.createInstance<FuncRParamsContext>(_ctx, getState());
  enterRule(_localctx, 42, CACTParser::RuleFuncRParams);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(264);
    exp();
    setState(269);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CACTParser::T__1) {
      setState(265);
      match(CACTParser::T__1);
      setState(266);
      exp();
      setState(271);
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

//----------------- UnaryOpContext ------------------------------------------------------------------

CACTParser::UnaryOpContext::UnaryOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CACTParser::UnaryOpContext::getRuleIndex() const {
  return CACTParser::RuleUnaryOp;
}

void CACTParser::UnaryOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryOp(this);
}

void CACTParser::UnaryOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryOp(this);
}

CACTParser::UnaryOpContext* CACTParser::unaryOp() {
  UnaryOpContext *_localctx = _tracker.createInstance<UnaryOpContext>(_ctx, getState());
  enterRule(_localctx, 44, CACTParser::RuleUnaryOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(272);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CACTParser::T__20)
      | (1ULL << CACTParser::T__21)
      | (1ULL << CACTParser::T__22))) != 0))) {
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

//----------------- MulExpContext ------------------------------------------------------------------

CACTParser::MulExpContext::MulExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::UnaryExpContext* CACTParser::MulExpContext::unaryExp() {
  return getRuleContext<CACTParser::UnaryExpContext>(0);
}

CACTParser::MulExpContext* CACTParser::MulExpContext::mulExp() {
  return getRuleContext<CACTParser::MulExpContext>(0);
}


size_t CACTParser::MulExpContext::getRuleIndex() const {
  return CACTParser::RuleMulExp;
}

void CACTParser::MulExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulExp(this);
}

void CACTParser::MulExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulExp(this);
}


CACTParser::MulExpContext* CACTParser::mulExp() {
   return mulExp(0);
}

CACTParser::MulExpContext* CACTParser::mulExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::MulExpContext *_localctx = _tracker.createInstance<MulExpContext>(_ctx, parentState);
  CACTParser::MulExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 46;
  enterRecursionRule(_localctx, 46, CACTParser::RuleMulExp, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(275);
    unaryExp();
    _ctx->stop = _input->LT(-1);
    setState(282);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<MulExpContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleMulExp);
        setState(277);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(278);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CACTParser::T__23)
          | (1ULL << CACTParser::T__24)
          | (1ULL << CACTParser::T__25))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(279);
        unaryExp(); 
      }
      setState(284);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AddExpContext ------------------------------------------------------------------

CACTParser::AddExpContext::AddExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::MulExpContext* CACTParser::AddExpContext::mulExp() {
  return getRuleContext<CACTParser::MulExpContext>(0);
}

CACTParser::AddExpContext* CACTParser::AddExpContext::addExp() {
  return getRuleContext<CACTParser::AddExpContext>(0);
}


size_t CACTParser::AddExpContext::getRuleIndex() const {
  return CACTParser::RuleAddExp;
}

void CACTParser::AddExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddExp(this);
}

void CACTParser::AddExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddExp(this);
}


CACTParser::AddExpContext* CACTParser::addExp() {
   return addExp(0);
}

CACTParser::AddExpContext* CACTParser::addExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::AddExpContext *_localctx = _tracker.createInstance<AddExpContext>(_ctx, parentState);
  CACTParser::AddExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 48;
  enterRecursionRule(_localctx, 48, CACTParser::RuleAddExp, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(286);
    mulExp(0);
    _ctx->stop = _input->LT(-1);
    setState(293);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<AddExpContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleAddExp);
        setState(288);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(289);
        _la = _input->LA(1);
        if (!(_la == CACTParser::T__20

        || _la == CACTParser::T__21)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(290);
        mulExp(0); 
      }
      setState(295);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- RelExpContext ------------------------------------------------------------------

CACTParser::RelExpContext::RelExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::AddExpContext* CACTParser::RelExpContext::addExp() {
  return getRuleContext<CACTParser::AddExpContext>(0);
}

tree::TerminalNode* CACTParser::RelExpContext::BoolConst() {
  return getToken(CACTParser::BoolConst, 0);
}

CACTParser::RelExpContext* CACTParser::RelExpContext::relExp() {
  return getRuleContext<CACTParser::RelExpContext>(0);
}


size_t CACTParser::RelExpContext::getRuleIndex() const {
  return CACTParser::RuleRelExp;
}

void CACTParser::RelExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelExp(this);
}

void CACTParser::RelExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelExp(this);
}


CACTParser::RelExpContext* CACTParser::relExp() {
   return relExp(0);
}

CACTParser::RelExpContext* CACTParser::relExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::RelExpContext *_localctx = _tracker.createInstance<RelExpContext>(_ctx, parentState);
  CACTParser::RelExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 50;
  enterRecursionRule(_localctx, 50, CACTParser::RuleRelExp, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(299);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      setState(297);
      addExp(0);
      break;
    }

    case 2: {
      setState(298);
      match(CACTParser::BoolConst);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(306);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<RelExpContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleRelExp);
        setState(301);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(302);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << CACTParser::T__26)
          | (1ULL << CACTParser::T__27)
          | (1ULL << CACTParser::T__28)
          | (1ULL << CACTParser::T__29))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(303);
        addExp(0); 
      }
      setState(308);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- EqExpContext ------------------------------------------------------------------

CACTParser::EqExpContext::EqExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::RelExpContext* CACTParser::EqExpContext::relExp() {
  return getRuleContext<CACTParser::RelExpContext>(0);
}

CACTParser::EqExpContext* CACTParser::EqExpContext::eqExp() {
  return getRuleContext<CACTParser::EqExpContext>(0);
}


size_t CACTParser::EqExpContext::getRuleIndex() const {
  return CACTParser::RuleEqExp;
}

void CACTParser::EqExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqExp(this);
}

void CACTParser::EqExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqExp(this);
}


CACTParser::EqExpContext* CACTParser::eqExp() {
   return eqExp(0);
}

CACTParser::EqExpContext* CACTParser::eqExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::EqExpContext *_localctx = _tracker.createInstance<EqExpContext>(_ctx, parentState);
  CACTParser::EqExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 52;
  enterRecursionRule(_localctx, 52, CACTParser::RuleEqExp, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(310);
    relExp(0);
    _ctx->stop = _input->LT(-1);
    setState(317);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<EqExpContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleEqExp);
        setState(312);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(313);
        _la = _input->LA(1);
        if (!(_la == CACTParser::T__30

        || _la == CACTParser::T__31)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(314);
        relExp(0); 
      }
      setState(319);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LAndExpContext ------------------------------------------------------------------

CACTParser::LAndExpContext::LAndExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::EqExpContext* CACTParser::LAndExpContext::eqExp() {
  return getRuleContext<CACTParser::EqExpContext>(0);
}

CACTParser::LAndExpContext* CACTParser::LAndExpContext::lAndExp() {
  return getRuleContext<CACTParser::LAndExpContext>(0);
}


size_t CACTParser::LAndExpContext::getRuleIndex() const {
  return CACTParser::RuleLAndExp;
}

void CACTParser::LAndExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLAndExp(this);
}

void CACTParser::LAndExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLAndExp(this);
}


CACTParser::LAndExpContext* CACTParser::lAndExp() {
   return lAndExp(0);
}

CACTParser::LAndExpContext* CACTParser::lAndExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::LAndExpContext *_localctx = _tracker.createInstance<LAndExpContext>(_ctx, parentState);
  CACTParser::LAndExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 54;
  enterRecursionRule(_localctx, 54, CACTParser::RuleLAndExp, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(321);
    eqExp(0);
    _ctx->stop = _input->LT(-1);
    setState(328);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<LAndExpContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLAndExp);
        setState(323);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(324);
        match(CACTParser::T__32);
        setState(325);
        eqExp(0); 
      }
      setState(330);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LOrExpContext ------------------------------------------------------------------

CACTParser::LOrExpContext::LOrExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CACTParser::LAndExpContext* CACTParser::LOrExpContext::lAndExp() {
  return getRuleContext<CACTParser::LAndExpContext>(0);
}

CACTParser::LOrExpContext* CACTParser::LOrExpContext::lOrExp() {
  return getRuleContext<CACTParser::LOrExpContext>(0);
}


size_t CACTParser::LOrExpContext::getRuleIndex() const {
  return CACTParser::RuleLOrExp;
}

void CACTParser::LOrExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLOrExp(this);
}

void CACTParser::LOrExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CACTListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLOrExp(this);
}


CACTParser::LOrExpContext* CACTParser::lOrExp() {
   return lOrExp(0);
}

CACTParser::LOrExpContext* CACTParser::lOrExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CACTParser::LOrExpContext *_localctx = _tracker.createInstance<LOrExpContext>(_ctx, parentState);
  CACTParser::LOrExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 56;
  enterRecursionRule(_localctx, 56, CACTParser::RuleLOrExp, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(332);
    lAndExp(0);
    _ctx->stop = _input->LT(-1);
    setState(339);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<LOrExpContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLOrExp);
        setState(334);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(335);
        match(CACTParser::T__33);
        setState(336);
        lAndExp(0); 
      }
      setState(341);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool CACTParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 23: return mulExpSempred(dynamic_cast<MulExpContext *>(context), predicateIndex);
    case 24: return addExpSempred(dynamic_cast<AddExpContext *>(context), predicateIndex);
    case 25: return relExpSempred(dynamic_cast<RelExpContext *>(context), predicateIndex);
    case 26: return eqExpSempred(dynamic_cast<EqExpContext *>(context), predicateIndex);
    case 27: return lAndExpSempred(dynamic_cast<LAndExpContext *>(context), predicateIndex);
    case 28: return lOrExpSempred(dynamic_cast<LOrExpContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool CACTParser::mulExpSempred(MulExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CACTParser::addExpSempred(AddExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CACTParser::relExpSempred(RelExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool CACTParser::eqExpSempred(EqExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CACTParser::lAndExpSempred(LAndExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CACTParser::lOrExpSempred(LOrExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> CACTParser::_decisionToDFA;
atn::PredictionContextCache CACTParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN CACTParser::_atn;
std::vector<uint16_t> CACTParser::_serializedATN;

std::vector<std::string> CACTParser::_ruleNames = {
  "compUnit", "decl", "constDecl", "bType", "constDef", "constExp", "varDecl", 
  "varDef", "funcDef", "funcType", "funcFParam", "block", "blockltem", "stmt", 
  "elseStmt", "exp", "cond", "lVal", "primaryExp", "unaryExp", "number", 
  "funcRParams", "unaryOp", "mulExp", "addExp", "relExp", "eqExp", "lAndExp", 
  "lOrExp"
};

std::vector<std::string> CACTParser::_literalNames = {
  "", "'const'", "','", "';'", "'int'", "'bool'", "'float'", "'double'", 
  "'='", "'['", "']'", "'}'", "'('", "')'", "'void'", "'if'", "'while'", 
  "'break'", "'continue'", "'return'", "'else'", "'+'", "'-'", "'!'", "'*'", 
  "'/'", "'%'", "'<'", "'>'", "'<='", "'>='", "'=='", "'!='", "'&&'", "'||'", 
  "", "'{'"
};

std::vector<std::string> CACTParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "BoolConst", 
  "LeftBigBracket", "Ident", "IntConst", "DoubleConst", "FloatConst", "NewLine", 
  "WhiteSpace", "BlockComment", "LineComment"
};

dfa::Vocabulary CACTParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> CACTParser::_tokenNames;

CACTParser::Initializer::Initializer() {
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

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x2e, 0x159, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x3, 
    0x2, 0x3, 0x2, 0x6, 0x2, 0x3f, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x40, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x47, 0xa, 0x3, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x4e, 0xa, 0x4, 0xc, 
    0x4, 0xe, 0x4, 0x51, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x63, 0xa, 
    0x6, 0xc, 0x6, 0xe, 0x6, 0x66, 0xb, 0x6, 0x5, 0x6, 0x68, 0xa, 0x6, 0x3, 
    0x6, 0x5, 0x6, 0x6b, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x6f, 0xa, 
    0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x75, 0xa, 0x8, 
    0xc, 0x8, 0xe, 0x8, 0x78, 0xb, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x7, 0x9, 0x8d, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x90, 0xb, 
    0x9, 0x5, 0x9, 0x92, 0xa, 0x9, 0x3, 0x9, 0x5, 0x9, 0x95, 0xa, 0x9, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0x9d, 
    0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0xa0, 0xb, 0xa, 0x5, 0xa, 0xa2, 0xa, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xad, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x7, 
    0xd, 0xb1, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0xb4, 0xb, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xba, 0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0xc2, 0xa, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0xdf, 
    0xa, 0xf, 0x3, 0xf, 0x5, 0xf, 0xe2, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xe9, 0xa, 0x11, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 
    0x13, 0xf2, 0xa, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0xfb, 0xa, 0x14, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0x101, 0xa, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0x107, 0xa, 0x15, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x7, 0x17, 0x10e, 0xa, 0x17, 
    0xc, 0x17, 0xe, 0x17, 0x111, 0xb, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x7, 0x19, 0x11b, 
    0xa, 0x19, 0xc, 0x19, 0xe, 0x19, 0x11e, 0xb, 0x19, 0x3, 0x1a, 0x3, 0x1a, 
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x7, 0x1a, 0x126, 0xa, 0x1a, 
    0xc, 0x1a, 0xe, 0x1a, 0x129, 0xb, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
    0x5, 0x1b, 0x12e, 0xa, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x7, 0x1b, 
    0x133, 0xa, 0x1b, 0xc, 0x1b, 0xe, 0x1b, 0x136, 0xb, 0x1b, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x7, 0x1c, 0x13e, 
    0xa, 0x1c, 0xc, 0x1c, 0xe, 0x1c, 0x141, 0xb, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x7, 0x1d, 0x149, 0xa, 0x1d, 
    0xc, 0x1d, 0xe, 0x1d, 0x14c, 0xb, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x7, 0x1e, 0x154, 0xa, 0x1e, 0xc, 0x1e, 
    0xe, 0x1e, 0x157, 0xb, 0x1e, 0x3, 0x1e, 0x2, 0x8, 0x30, 0x32, 0x34, 
    0x36, 0x38, 0x3a, 0x1f, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 
    0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 
    0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x2, 0xa, 0x3, 0x2, 
    0x6, 0x9, 0x4, 0x2, 0x6, 0x9, 0x10, 0x10, 0x3, 0x2, 0x28, 0x2a, 0x3, 
    0x2, 0x17, 0x19, 0x3, 0x2, 0x1a, 0x1c, 0x3, 0x2, 0x17, 0x18, 0x3, 0x2, 
    0x1d, 0x20, 0x3, 0x2, 0x21, 0x22, 0x2, 0x168, 0x2, 0x3e, 0x3, 0x2, 0x2, 
    0x2, 0x4, 0x46, 0x3, 0x2, 0x2, 0x2, 0x6, 0x48, 0x3, 0x2, 0x2, 0x2, 0x8, 
    0x54, 0x3, 0x2, 0x2, 0x2, 0xa, 0x6a, 0x3, 0x2, 0x2, 0x2, 0xc, 0x6e, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0x70, 0x3, 0x2, 0x2, 0x2, 0x10, 0x94, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0x96, 0x3, 0x2, 0x2, 0x2, 0x14, 0xa6, 0x3, 0x2, 
    0x2, 0x2, 0x16, 0xa8, 0x3, 0x2, 0x2, 0x2, 0x18, 0xae, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0xb9, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xe1, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0xe3, 0x3, 0x2, 0x2, 0x2, 0x20, 0xe8, 0x3, 0x2, 0x2, 0x2, 0x22, 
    0xea, 0x3, 0x2, 0x2, 0x2, 0x24, 0xec, 0x3, 0x2, 0x2, 0x2, 0x26, 0xfa, 
    0x3, 0x2, 0x2, 0x2, 0x28, 0x106, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x108, 0x3, 
    0x2, 0x2, 0x2, 0x2c, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x112, 0x3, 0x2, 
    0x2, 0x2, 0x30, 0x114, 0x3, 0x2, 0x2, 0x2, 0x32, 0x11f, 0x3, 0x2, 0x2, 
    0x2, 0x34, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x36, 0x137, 0x3, 0x2, 0x2, 0x2, 
    0x38, 0x142, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x3c, 
    0x3f, 0x5, 0x4, 0x3, 0x2, 0x3d, 0x3f, 0x5, 0x12, 0xa, 0x2, 0x3e, 0x3c, 
    0x3, 0x2, 0x2, 0x2, 0x3e, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x40, 0x3, 
    0x2, 0x2, 0x2, 0x40, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x40, 0x41, 0x3, 0x2, 
    0x2, 0x2, 0x41, 0x42, 0x3, 0x2, 0x2, 0x2, 0x42, 0x43, 0x7, 0x2, 0x2, 
    0x3, 0x43, 0x3, 0x3, 0x2, 0x2, 0x2, 0x44, 0x47, 0x5, 0x6, 0x4, 0x2, 
    0x45, 0x47, 0x5, 0xe, 0x8, 0x2, 0x46, 0x44, 0x3, 0x2, 0x2, 0x2, 0x46, 
    0x45, 0x3, 0x2, 0x2, 0x2, 0x47, 0x5, 0x3, 0x2, 0x2, 0x2, 0x48, 0x49, 
    0x7, 0x3, 0x2, 0x2, 0x49, 0x4a, 0x5, 0x8, 0x5, 0x2, 0x4a, 0x4f, 0x5, 
    0xa, 0x6, 0x2, 0x4b, 0x4c, 0x7, 0x4, 0x2, 0x2, 0x4c, 0x4e, 0x5, 0xa, 
    0x6, 0x2, 0x4d, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x51, 0x3, 0x2, 0x2, 
    0x2, 0x4f, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x50, 0x3, 0x2, 0x2, 0x2, 
    0x50, 0x52, 0x3, 0x2, 0x2, 0x2, 0x51, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x52, 
    0x53, 0x7, 0x5, 0x2, 0x2, 0x53, 0x7, 0x3, 0x2, 0x2, 0x2, 0x54, 0x55, 
    0x9, 0x2, 0x2, 0x2, 0x55, 0x9, 0x3, 0x2, 0x2, 0x2, 0x56, 0x57, 0x7, 
    0x27, 0x2, 0x2, 0x57, 0x58, 0x7, 0xa, 0x2, 0x2, 0x58, 0x6b, 0x5, 0xc, 
    0x7, 0x2, 0x59, 0x5a, 0x7, 0x27, 0x2, 0x2, 0x5a, 0x5b, 0x7, 0xb, 0x2, 
    0x2, 0x5b, 0x5c, 0x7, 0x28, 0x2, 0x2, 0x5c, 0x5d, 0x7, 0xc, 0x2, 0x2, 
    0x5d, 0x5e, 0x7, 0xa, 0x2, 0x2, 0x5e, 0x67, 0x7, 0x26, 0x2, 0x2, 0x5f, 
    0x64, 0x5, 0xc, 0x7, 0x2, 0x60, 0x61, 0x7, 0x4, 0x2, 0x2, 0x61, 0x63, 
    0x5, 0xc, 0x7, 0x2, 0x62, 0x60, 0x3, 0x2, 0x2, 0x2, 0x63, 0x66, 0x3, 
    0x2, 0x2, 0x2, 0x64, 0x62, 0x3, 0x2, 0x2, 0x2, 0x64, 0x65, 0x3, 0x2, 
    0x2, 0x2, 0x65, 0x68, 0x3, 0x2, 0x2, 0x2, 0x66, 0x64, 0x3, 0x2, 0x2, 
    0x2, 0x67, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0x3, 0x2, 0x2, 0x2, 
    0x68, 0x69, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6b, 0x7, 0xd, 0x2, 0x2, 0x6a, 
    0x56, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x59, 0x3, 0x2, 0x2, 0x2, 0x6b, 0xb, 
    0x3, 0x2, 0x2, 0x2, 0x6c, 0x6f, 0x5, 0x2a, 0x16, 0x2, 0x6d, 0x6f, 0x7, 
    0x25, 0x2, 0x2, 0x6e, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6d, 0x3, 0x2, 
    0x2, 0x2, 0x6f, 0xd, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x5, 0x8, 0x5, 
    0x2, 0x71, 0x76, 0x5, 0x10, 0x9, 0x2, 0x72, 0x73, 0x7, 0x4, 0x2, 0x2, 
    0x73, 0x75, 0x5, 0x10, 0x9, 0x2, 0x74, 0x72, 0x3, 0x2, 0x2, 0x2, 0x75, 
    0x78, 0x3, 0x2, 0x2, 0x2, 0x76, 0x74, 0x3, 0x2, 0x2, 0x2, 0x76, 0x77, 
    0x3, 0x2, 0x2, 0x2, 0x77, 0x79, 0x3, 0x2, 0x2, 0x2, 0x78, 0x76, 0x3, 
    0x2, 0x2, 0x2, 0x79, 0x7a, 0x7, 0x5, 0x2, 0x2, 0x7a, 0xf, 0x3, 0x2, 
    0x2, 0x2, 0x7b, 0x95, 0x7, 0x27, 0x2, 0x2, 0x7c, 0x7d, 0x7, 0x27, 0x2, 
    0x2, 0x7d, 0x7e, 0x7, 0xb, 0x2, 0x2, 0x7e, 0x7f, 0x7, 0x28, 0x2, 0x2, 
    0x7f, 0x95, 0x7, 0xc, 0x2, 0x2, 0x80, 0x81, 0x7, 0x27, 0x2, 0x2, 0x81, 
    0x82, 0x7, 0xa, 0x2, 0x2, 0x82, 0x95, 0x5, 0xc, 0x7, 0x2, 0x83, 0x84, 
    0x7, 0x27, 0x2, 0x2, 0x84, 0x85, 0x7, 0xb, 0x2, 0x2, 0x85, 0x86, 0x7, 
    0x28, 0x2, 0x2, 0x86, 0x87, 0x7, 0xc, 0x2, 0x2, 0x87, 0x88, 0x7, 0xa, 
    0x2, 0x2, 0x88, 0x91, 0x7, 0x26, 0x2, 0x2, 0x89, 0x8e, 0x5, 0xc, 0x7, 
    0x2, 0x8a, 0x8b, 0x7, 0x4, 0x2, 0x2, 0x8b, 0x8d, 0x5, 0xc, 0x7, 0x2, 
    0x8c, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x90, 0x3, 0x2, 0x2, 0x2, 0x8e, 
    0x8c, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x92, 
    0x3, 0x2, 0x2, 0x2, 0x90, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x91, 0x89, 0x3, 
    0x2, 0x2, 0x2, 0x91, 0x92, 0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 0x3, 0x2, 
    0x2, 0x2, 0x93, 0x95, 0x7, 0xd, 0x2, 0x2, 0x94, 0x7b, 0x3, 0x2, 0x2, 
    0x2, 0x94, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x94, 0x80, 0x3, 0x2, 0x2, 0x2, 
    0x94, 0x83, 0x3, 0x2, 0x2, 0x2, 0x95, 0x11, 0x3, 0x2, 0x2, 0x2, 0x96, 
    0x97, 0x5, 0x14, 0xb, 0x2, 0x97, 0x98, 0x7, 0x27, 0x2, 0x2, 0x98, 0xa1, 
    0x7, 0xe, 0x2, 0x2, 0x99, 0x9e, 0x5, 0x16, 0xc, 0x2, 0x9a, 0x9b, 0x7, 
    0x4, 0x2, 0x2, 0x9b, 0x9d, 0x5, 0x16, 0xc, 0x2, 0x9c, 0x9a, 0x3, 0x2, 
    0x2, 0x2, 0x9d, 0xa0, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9c, 0x3, 0x2, 0x2, 
    0x2, 0x9e, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa2, 0x3, 0x2, 0x2, 0x2, 
    0xa0, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xa1, 0x99, 0x3, 0x2, 0x2, 0x2, 0xa1, 
    0xa2, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa4, 
    0x7, 0xf, 0x2, 0x2, 0xa4, 0xa5, 0x5, 0x18, 0xd, 0x2, 0xa5, 0x13, 0x3, 
    0x2, 0x2, 0x2, 0xa6, 0xa7, 0x9, 0x3, 0x2, 0x2, 0xa7, 0x15, 0x3, 0x2, 
    0x2, 0x2, 0xa8, 0xa9, 0x5, 0x8, 0x5, 0x2, 0xa9, 0xac, 0x7, 0x27, 0x2, 
    0x2, 0xaa, 0xab, 0x7, 0xb, 0x2, 0x2, 0xab, 0xad, 0x7, 0xc, 0x2, 0x2, 
    0xac, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xac, 0xad, 0x3, 0x2, 0x2, 0x2, 0xad, 
    0x17, 0x3, 0x2, 0x2, 0x2, 0xae, 0xb2, 0x7, 0x26, 0x2, 0x2, 0xaf, 0xb1, 
    0x5, 0x1a, 0xe, 0x2, 0xb0, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb4, 0x3, 
    0x2, 0x2, 0x2, 0xb2, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb3, 0x3, 0x2, 
    0x2, 0x2, 0xb3, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb2, 0x3, 0x2, 0x2, 
    0x2, 0xb5, 0xb6, 0x7, 0xd, 0x2, 0x2, 0xb6, 0x19, 0x3, 0x2, 0x2, 0x2, 
    0xb7, 0xba, 0x5, 0x4, 0x3, 0x2, 0xb8, 0xba, 0x5, 0x1c, 0xf, 0x2, 0xb9, 
    0xb7, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xba, 0x1b, 
    0x3, 0x2, 0x2, 0x2, 0xbb, 0xbc, 0x5, 0x24, 0x13, 0x2, 0xbc, 0xbd, 0x7, 
    0xa, 0x2, 0x2, 0xbd, 0xbe, 0x5, 0x20, 0x11, 0x2, 0xbe, 0xbf, 0x7, 0x5, 
    0x2, 0x2, 0xbf, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xc2, 0x5, 0x20, 0x11, 
    0x2, 0xc1, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc2, 0x3, 0x2, 0x2, 0x2, 
    0xc2, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xe2, 0x7, 0x5, 0x2, 0x2, 0xc4, 
    0xe2, 0x5, 0x18, 0xd, 0x2, 0xc5, 0xc6, 0x7, 0x11, 0x2, 0x2, 0xc6, 0xc7, 
    0x7, 0xe, 0x2, 0x2, 0xc7, 0xc8, 0x5, 0x22, 0x12, 0x2, 0xc8, 0xc9, 0x7, 
    0xf, 0x2, 0x2, 0xc9, 0xca, 0x5, 0x1c, 0xf, 0x2, 0xca, 0xe2, 0x3, 0x2, 
    0x2, 0x2, 0xcb, 0xcc, 0x7, 0x11, 0x2, 0x2, 0xcc, 0xcd, 0x7, 0xe, 0x2, 
    0x2, 0xcd, 0xce, 0x5, 0x22, 0x12, 0x2, 0xce, 0xcf, 0x7, 0xf, 0x2, 0x2, 
    0xcf, 0xd0, 0x5, 0x1c, 0xf, 0x2, 0xd0, 0xd1, 0x5, 0x1e, 0x10, 0x2, 0xd1, 
    0xe2, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd3, 0x7, 0x12, 0x2, 0x2, 0xd3, 0xd4, 
    0x7, 0xe, 0x2, 0x2, 0xd4, 0xd5, 0x5, 0x22, 0x12, 0x2, 0xd5, 0xd6, 0x7, 
    0xf, 0x2, 0x2, 0xd6, 0xd7, 0x5, 0x1c, 0xf, 0x2, 0xd7, 0xe2, 0x3, 0x2, 
    0x2, 0x2, 0xd8, 0xd9, 0x7, 0x13, 0x2, 0x2, 0xd9, 0xe2, 0x7, 0x5, 0x2, 
    0x2, 0xda, 0xdb, 0x7, 0x14, 0x2, 0x2, 0xdb, 0xe2, 0x7, 0x5, 0x2, 0x2, 
    0xdc, 0xde, 0x7, 0x15, 0x2, 0x2, 0xdd, 0xdf, 0x5, 0x20, 0x11, 0x2, 0xde, 
    0xdd, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xe0, 
    0x3, 0x2, 0x2, 0x2, 0xe0, 0xe2, 0x7, 0x5, 0x2, 0x2, 0xe1, 0xbb, 0x3, 
    0x2, 0x2, 0x2, 0xe1, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xc4, 0x3, 0x2, 
    0x2, 0x2, 0xe1, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xcb, 0x3, 0x2, 0x2, 
    0x2, 0xe1, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xd8, 0x3, 0x2, 0x2, 0x2, 
    0xe1, 0xda, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xe2, 
    0x1d, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe4, 0x7, 0x16, 0x2, 0x2, 0xe4, 0xe5, 
    0x5, 0x1c, 0xf, 0x2, 0xe5, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe9, 0x5, 
    0x32, 0x1a, 0x2, 0xe7, 0xe9, 0x7, 0x25, 0x2, 0x2, 0xe8, 0xe6, 0x3, 0x2, 
    0x2, 0x2, 0xe8, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xe9, 0x21, 0x3, 0x2, 0x2, 
    0x2, 0xea, 0xeb, 0x5, 0x3a, 0x1e, 0x2, 0xeb, 0x23, 0x3, 0x2, 0x2, 0x2, 
    0xec, 0xf1, 0x7, 0x27, 0x2, 0x2, 0xed, 0xee, 0x7, 0xb, 0x2, 0x2, 0xee, 
    0xef, 0x5, 0x20, 0x11, 0x2, 0xef, 0xf0, 0x7, 0xc, 0x2, 0x2, 0xf0, 0xf2, 
    0x3, 0x2, 0x2, 0x2, 0xf1, 0xed, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf2, 0x3, 
    0x2, 0x2, 0x2, 0xf2, 0x25, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf4, 0x7, 0xe, 
    0x2, 0x2, 0xf4, 0xf5, 0x5, 0x20, 0x11, 0x2, 0xf5, 0xf6, 0x7, 0xf, 0x2, 
    0x2, 0xf6, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xfb, 0x5, 0x24, 0x13, 0x2, 
    0xf8, 0xfb, 0x7, 0x25, 0x2, 0x2, 0xf9, 0xfb, 0x5, 0x2a, 0x16, 0x2, 0xfa, 
    0xf3, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xf8, 
    0x3, 0x2, 0x2, 0x2, 0xfa, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xfb, 0x27, 0x3, 
    0x2, 0x2, 0x2, 0xfc, 0x107, 0x5, 0x26, 0x14, 0x2, 0xfd, 0xfe, 0x7, 0x27, 
    0x2, 0x2, 0xfe, 0x100, 0x7, 0xe, 0x2, 0x2, 0xff, 0x101, 0x5, 0x2c, 0x17, 
    0x2, 0x100, 0xff, 0x3, 0x2, 0x2, 0x2, 0x100, 0x101, 0x3, 0x2, 0x2, 0x2, 
    0x101, 0x102, 0x3, 0x2, 0x2, 0x2, 0x102, 0x107, 0x7, 0xf, 0x2, 0x2, 
    0x103, 0x104, 0x5, 0x2e, 0x18, 0x2, 0x104, 0x105, 0x5, 0x28, 0x15, 0x2, 
    0x105, 0x107, 0x3, 0x2, 0x2, 0x2, 0x106, 0xfc, 0x3, 0x2, 0x2, 0x2, 0x106, 
    0xfd, 0x3, 0x2, 0x2, 0x2, 0x106, 0x103, 0x3, 0x2, 0x2, 0x2, 0x107, 0x29, 
    0x3, 0x2, 0x2, 0x2, 0x108, 0x109, 0x9, 0x4, 0x2, 0x2, 0x109, 0x2b, 0x3, 
    0x2, 0x2, 0x2, 0x10a, 0x10f, 0x5, 0x20, 0x11, 0x2, 0x10b, 0x10c, 0x7, 
    0x4, 0x2, 0x2, 0x10c, 0x10e, 0x5, 0x20, 0x11, 0x2, 0x10d, 0x10b, 0x3, 
    0x2, 0x2, 0x2, 0x10e, 0x111, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x10d, 0x3, 
    0x2, 0x2, 0x2, 0x10f, 0x110, 0x3, 0x2, 0x2, 0x2, 0x110, 0x2d, 0x3, 0x2, 
    0x2, 0x2, 0x111, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x112, 0x113, 0x9, 0x5, 
    0x2, 0x2, 0x113, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x114, 0x115, 0x8, 0x19, 
    0x1, 0x2, 0x115, 0x116, 0x5, 0x28, 0x15, 0x2, 0x116, 0x11c, 0x3, 0x2, 
    0x2, 0x2, 0x117, 0x118, 0xc, 0x3, 0x2, 0x2, 0x118, 0x119, 0x9, 0x6, 
    0x2, 0x2, 0x119, 0x11b, 0x5, 0x28, 0x15, 0x2, 0x11a, 0x117, 0x3, 0x2, 
    0x2, 0x2, 0x11b, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x11a, 0x3, 0x2, 
    0x2, 0x2, 0x11c, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x31, 0x3, 0x2, 0x2, 
    0x2, 0x11e, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x120, 0x8, 0x1a, 0x1, 
    0x2, 0x120, 0x121, 0x5, 0x30, 0x19, 0x2, 0x121, 0x127, 0x3, 0x2, 0x2, 
    0x2, 0x122, 0x123, 0xc, 0x3, 0x2, 0x2, 0x123, 0x124, 0x9, 0x7, 0x2, 
    0x2, 0x124, 0x126, 0x5, 0x30, 0x19, 0x2, 0x125, 0x122, 0x3, 0x2, 0x2, 
    0x2, 0x126, 0x129, 0x3, 0x2, 0x2, 0x2, 0x127, 0x125, 0x3, 0x2, 0x2, 
    0x2, 0x127, 0x128, 0x3, 0x2, 0x2, 0x2, 0x128, 0x33, 0x3, 0x2, 0x2, 0x2, 
    0x129, 0x127, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x12b, 0x8, 0x1b, 0x1, 0x2, 
    0x12b, 0x12e, 0x5, 0x32, 0x1a, 0x2, 0x12c, 0x12e, 0x7, 0x25, 0x2, 0x2, 
    0x12d, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x12c, 0x3, 0x2, 0x2, 0x2, 
    0x12e, 0x134, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x130, 0xc, 0x4, 0x2, 0x2, 
    0x130, 0x131, 0x9, 0x8, 0x2, 0x2, 0x131, 0x133, 0x5, 0x32, 0x1a, 0x2, 
    0x132, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x133, 0x136, 0x3, 0x2, 0x2, 0x2, 
    0x134, 0x132, 0x3, 0x2, 0x2, 0x2, 0x134, 0x135, 0x3, 0x2, 0x2, 0x2, 
    0x135, 0x35, 0x3, 0x2, 0x2, 0x2, 0x136, 0x134, 0x3, 0x2, 0x2, 0x2, 0x137, 
    0x138, 0x8, 0x1c, 0x1, 0x2, 0x138, 0x139, 0x5, 0x34, 0x1b, 0x2, 0x139, 
    0x13f, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x13b, 0xc, 0x3, 0x2, 0x2, 0x13b, 
    0x13c, 0x9, 0x9, 0x2, 0x2, 0x13c, 0x13e, 0x5, 0x34, 0x1b, 0x2, 0x13d, 
    0x13a, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x141, 0x3, 0x2, 0x2, 0x2, 0x13f, 
    0x13d, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x140, 0x3, 0x2, 0x2, 0x2, 0x140, 
    0x37, 0x3, 0x2, 0x2, 0x2, 0x141, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x142, 0x143, 
    0x8, 0x1d, 0x1, 0x2, 0x143, 0x144, 0x5, 0x36, 0x1c, 0x2, 0x144, 0x14a, 
    0x3, 0x2, 0x2, 0x2, 0x145, 0x146, 0xc, 0x3, 0x2, 0x2, 0x146, 0x147, 
    0x7, 0x23, 0x2, 0x2, 0x147, 0x149, 0x5, 0x36, 0x1c, 0x2, 0x148, 0x145, 
    0x3, 0x2, 0x2, 0x2, 0x149, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x148, 
    0x3, 0x2, 0x2, 0x2, 0x14a, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x39, 0x3, 
    0x2, 0x2, 0x2, 0x14c, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x14e, 0x8, 
    0x1e, 0x1, 0x2, 0x14e, 0x14f, 0x5, 0x38, 0x1d, 0x2, 0x14f, 0x155, 0x3, 
    0x2, 0x2, 0x2, 0x150, 0x151, 0xc, 0x3, 0x2, 0x2, 0x151, 0x152, 0x7, 
    0x24, 0x2, 0x2, 0x152, 0x154, 0x5, 0x38, 0x1d, 0x2, 0x153, 0x150, 0x3, 
    0x2, 0x2, 0x2, 0x154, 0x157, 0x3, 0x2, 0x2, 0x2, 0x155, 0x153, 0x3, 
    0x2, 0x2, 0x2, 0x155, 0x156, 0x3, 0x2, 0x2, 0x2, 0x156, 0x3b, 0x3, 0x2, 
    0x2, 0x2, 0x157, 0x155, 0x3, 0x2, 0x2, 0x2, 0x23, 0x3e, 0x40, 0x46, 
    0x4f, 0x64, 0x67, 0x6a, 0x6e, 0x76, 0x8e, 0x91, 0x94, 0x9e, 0xa1, 0xac, 
    0xb2, 0xb9, 0xc1, 0xde, 0xe1, 0xe8, 0xf1, 0xfa, 0x100, 0x106, 0x10f, 
    0x11c, 0x127, 0x12d, 0x134, 0x13f, 0x14a, 0x155, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

CACTParser::Initializer CACTParser::_init;
