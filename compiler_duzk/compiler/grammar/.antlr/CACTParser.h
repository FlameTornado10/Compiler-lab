
    #include <vector>
    #include <string>


// Generated from /home/compiler26/Work/compiler_dzk/compiler/grammar/CACT.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  CACTParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, T__25 = 26, 
    T__26 = 27, T__27 = 28, T__28 = 29, T__29 = 30, T__30 = 31, T__31 = 32, 
    T__32 = 33, T__33 = 34, BoolConst = 35, LeftBigBracket = 36, Ident = 37, 
    IntConst = 38, DoubleConst = 39, FloatConst = 40, NewLine = 41, WhiteSpace = 42, 
    BlockComment = 43, LineComment = 44
  };

  enum {
    RuleCompUnit = 0, RuleDecl = 1, RuleConstDecl = 2, RuleBType = 3, RuleConstDef = 4, 
    RuleConstExp = 5, RuleVarDecl = 6, RuleVarDef = 7, RuleFuncDef = 8, 
    RuleFuncType = 9, RuleFuncFParam = 10, RuleBlock = 11, RuleBlockltem = 12, 
    RuleStmt = 13, RuleElseStmt = 14, RuleCond = 15, RuleLVal = 16, RuleExp = 17, 
    RuleAddExp = 18, RuleMulExp = 19, RulePrimaryExp = 20, RuleUnaryExp = 21, 
    RuleNumber = 22, RuleFuncRParams = 23, RuleUnaryOp = 24, RuleRelExp = 25, 
    RuleEqExp = 26, RuleLAndExp = 27, RuleLOrExp = 28
  };

  explicit CACTParser(antlr4::TokenStream *input);
  ~CACTParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class CompUnitContext;
  class DeclContext;
  class ConstDeclContext;
  class BTypeContext;
  class ConstDefContext;
  class ConstExpContext;
  class VarDeclContext;
  class VarDefContext;
  class FuncDefContext;
  class FuncTypeContext;
  class FuncFParamContext;
  class BlockContext;
  class BlockltemContext;
  class StmtContext;
  class ElseStmtContext;
  class CondContext;
  class LValContext;
  class ExpContext;
  class AddExpContext;
  class MulExpContext;
  class PrimaryExpContext;
  class UnaryExpContext;
  class NumberContext;
  class FuncRParamsContext;
  class UnaryOpContext;
  class RelExpContext;
  class EqExpContext;
  class LAndExpContext;
  class LOrExpContext; 

  class  CompUnitContext : public antlr4::ParserRuleContext {
  public:
    CompUnitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<DeclContext *> decl();
    DeclContext* decl(size_t i);
    std::vector<FuncDefContext *> funcDef();
    FuncDefContext* funcDef(size_t i);

   
  };

  CompUnitContext* compUnit();

  class  DeclContext : public antlr4::ParserRuleContext {
  public:
    DeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ConstDeclContext *constDecl();
    VarDeclContext *varDecl();

   
  };

  DeclContext* decl();

  class  ConstDeclContext : public antlr4::ParserRuleContext {
  public:
    ConstDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BTypeContext *bType();
    std::vector<ConstDefContext *> constDef();
    ConstDefContext* constDef(size_t i);

   
  };

  ConstDeclContext* constDecl();

  class  BTypeContext : public antlr4::ParserRuleContext {
  public:
    BTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  BTypeContext* bType();

  class  ConstDefContext : public antlr4::ParserRuleContext {
  public:
    ConstDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ConstDefContext() = default;
    void copyFrom(ConstDefContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ConstDefArrayContext : public ConstDefContext {
  public:
    ConstDefArrayContext(ConstDefContext *ctx);

    antlr4::tree::TerminalNode *Ident();
    antlr4::tree::TerminalNode *IntConst();
    antlr4::tree::TerminalNode *LeftBigBracket();
    std::vector<ConstExpContext *> constExp();
    ConstExpContext* constExp(size_t i);
  };

  class  ConstDefValContext : public ConstDefContext {
  public:
    ConstDefValContext(ConstDefContext *ctx);

    antlr4::tree::TerminalNode *Ident();
    ConstExpContext *constExp();
  };

  ConstDefContext* constDef();

  class  ConstExpContext : public antlr4::ParserRuleContext {
  public:
    std::string name;
    int cls;
    ConstExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ConstExpContext() = default;
    void copyFrom(ConstExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ConstExpBoolConstContext : public ConstExpContext {
  public:
    ConstExpBoolConstContext(ConstExpContext *ctx);

    antlr4::tree::TerminalNode *BoolConst();
  };

  class  ConstExpNumberContext : public ConstExpContext {
  public:
    ConstExpNumberContext(ConstExpContext *ctx);

    NumberContext *number();
  };

  ConstExpContext* constExp();

  class  VarDeclContext : public antlr4::ParserRuleContext {
  public:
    VarDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BTypeContext *bType();
    std::vector<VarDefContext *> varDef();
    VarDefContext* varDef(size_t i);

   
  };

  VarDeclContext* varDecl();

  class  VarDefContext : public antlr4::ParserRuleContext {
  public:
    VarDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    VarDefContext() = default;
    void copyFrom(VarDefContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  VarDefInitArrayContext : public VarDefContext {
  public:
    VarDefInitArrayContext(VarDefContext *ctx);

    antlr4::tree::TerminalNode *Ident();
    antlr4::tree::TerminalNode *IntConst();
    antlr4::tree::TerminalNode *LeftBigBracket();
    std::vector<ConstExpContext *> constExp();
    ConstExpContext* constExp(size_t i);
  };

  class  VarDefInitValContext : public VarDefContext {
  public:
    VarDefInitValContext(VarDefContext *ctx);

    antlr4::tree::TerminalNode *Ident();
    ConstExpContext *constExp();
  };

  class  VarDefValContext : public VarDefContext {
  public:
    VarDefValContext(VarDefContext *ctx);

    antlr4::tree::TerminalNode *Ident();
  };

  class  VarDefArrayContext : public VarDefContext {
  public:
    VarDefArrayContext(VarDefContext *ctx);

    antlr4::tree::TerminalNode *Ident();
    antlr4::tree::TerminalNode *IntConst();
  };

  VarDefContext* varDef();

  class  FuncDefContext : public antlr4::ParserRuleContext {
  public:
    CACTParser::FuncTypeContext *ret = nullptr;
    antlr4::Token *name = nullptr;
    FuncDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BlockContext *block();
    FuncTypeContext *funcType();
    antlr4::tree::TerminalNode *Ident();
    std::vector<FuncFParamContext *> funcFParam();
    FuncFParamContext* funcFParam(size_t i);

   
  };

  FuncDefContext* funcDef();

  class  FuncTypeContext : public antlr4::ParserRuleContext {
  public:
    FuncTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  FuncTypeContext* funcType();

  class  FuncFParamContext : public antlr4::ParserRuleContext {
  public:
    FuncFParamContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BTypeContext *bType();
    antlr4::tree::TerminalNode *Ident();

   
  };

  FuncFParamContext* funcFParam();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LeftBigBracket();
    std::vector<BlockltemContext *> blockltem();
    BlockltemContext* blockltem(size_t i);

   
  };

  BlockContext* block();

  class  BlockltemContext : public antlr4::ParserRuleContext {
  public:
    BlockltemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclContext *decl();
    StmtContext *stmt();

   
  };

  BlockltemContext* blockltem();

  class  StmtContext : public antlr4::ParserRuleContext {
  public:
    StmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    StmtContext() = default;
    void copyFrom(StmtContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ExprStmtContext : public StmtContext {
  public:
    ExprStmtContext(StmtContext *ctx);

    ExpContext *exp();
  };

  class  WhileStmtContext : public StmtContext {
  public:
    WhileStmtContext(StmtContext *ctx);

    CondContext *cond();
    StmtContext *stmt();
  };

  class  IfStmtContext : public StmtContext {
  public:
    IfStmtContext(StmtContext *ctx);

    CondContext *cond();
    StmtContext *stmt();
  };

  class  BlockStmtContext : public StmtContext {
  public:
    BlockStmtContext(StmtContext *ctx);

    BlockContext *block();
  };

  class  IfElseStmtContext : public StmtContext {
  public:
    IfElseStmtContext(StmtContext *ctx);

    CondContext *cond();
    StmtContext *stmt();
    ElseStmtContext *elseStmt();
  };

  class  AssignStmtContext : public StmtContext {
  public:
    AssignStmtContext(StmtContext *ctx);

    LValContext *lVal();
    ExpContext *exp();
  };

  class  BreakStmtContext : public StmtContext {
  public:
    BreakStmtContext(StmtContext *ctx);

  };

  class  ReturnStmtContext : public StmtContext {
  public:
    ReturnStmtContext(StmtContext *ctx);

    ExpContext *exp();
  };

  class  ContinueStmtContext : public StmtContext {
  public:
    ContinueStmtContext(StmtContext *ctx);

  };

  StmtContext* stmt();

  class  ElseStmtContext : public antlr4::ParserRuleContext {
  public:
    ElseStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StmtContext *stmt();

   
  };

  ElseStmtContext* elseStmt();

  class  CondContext : public antlr4::ParserRuleContext {
  public:
    std::string name;
    int cls;
    bool value;
    CondContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LOrExpContext *lOrExp();

   
  };

  CondContext* cond();

  class  LValContext : public antlr4::ParserRuleContext {
  public:
    std::string name;
    int cls;
    bool elemwise;
    LValContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Ident();
    ExpContext *exp();

   
  };

  LValContext* lVal();

  class  ExpContext : public antlr4::ParserRuleContext {
  public:
    std::string name;
    int cls;
    ExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AddExpContext *addExp();
    antlr4::tree::TerminalNode *BoolConst();

   
  };

  ExpContext* exp();

  class  AddExpContext : public antlr4::ParserRuleContext {
  public:
    std::string name;
    int cls;
    bool elemwise;
    AddExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    MulExpContext *mulExp();
    AddExpContext *addExp();

   
  };

  AddExpContext* addExp();
  AddExpContext* addExp(int precedence);
  class  MulExpContext : public antlr4::ParserRuleContext {
  public:
    std::string name;
    int cls;
    bool elemwise;
    MulExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnaryExpContext *unaryExp();
    MulExpContext *mulExp();

   
  };

  MulExpContext* mulExp();
  MulExpContext* mulExp(int precedence);
  class  PrimaryExpContext : public antlr4::ParserRuleContext {
  public:
    std::string name;
    int cls;
    bool elemwise;
    PrimaryExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpContext *exp();
    LValContext *lVal();
    antlr4::tree::TerminalNode *BoolConst();
    NumberContext *number();

   
  };

  PrimaryExpContext* primaryExp();

  class  UnaryExpContext : public antlr4::ParserRuleContext {
  public:
    std::string name;
    int cls;
    bool elemwise;
    UnaryExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    UnaryExpContext() = default;
    void copyFrom(UnaryExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  FuncCallContext : public UnaryExpContext {
  public:
    FuncCallContext(UnaryExpContext *ctx);

    antlr4::tree::TerminalNode *Ident();
    FuncRParamsContext *funcRParams();
  };

  class  UnaryContext : public UnaryExpContext {
  public:
    UnaryContext(UnaryExpContext *ctx);

    UnaryOpContext *unaryOp();
    UnaryExpContext *unaryExp();
  };

  class  PrimaryContext : public UnaryExpContext {
  public:
    PrimaryContext(UnaryExpContext *ctx);

    PrimaryExpContext *primaryExp();
  };

  UnaryExpContext* unaryExp();

  class  NumberContext : public antlr4::ParserRuleContext {
  public:
    std::string name;
    int cls;
    NumberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IntConst();
    antlr4::tree::TerminalNode *DoubleConst();
    antlr4::tree::TerminalNode *FloatConst();

   
  };

  NumberContext* number();

  class  FuncRParamsContext : public antlr4::ParserRuleContext {
  public:
    FuncRParamsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpContext *> exp();
    ExpContext* exp(size_t i);

   
  };

  FuncRParamsContext* funcRParams();

  class  UnaryOpContext : public antlr4::ParserRuleContext {
  public:
    UnaryOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  UnaryOpContext* unaryOp();

  class  RelExpContext : public antlr4::ParserRuleContext {
  public:
    std::string name;
    int cls;
    bool value;
    RelExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AddExpContext *addExp();
    antlr4::tree::TerminalNode *BoolConst();
    RelExpContext *relExp();

   
  };

  RelExpContext* relExp();
  RelExpContext* relExp(int precedence);
  class  EqExpContext : public antlr4::ParserRuleContext {
  public:
    std::string name;
    int cls;
    bool value;
    EqExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RelExpContext *relExp();
    EqExpContext *eqExp();

   
  };

  EqExpContext* eqExp();
  EqExpContext* eqExp(int precedence);
  class  LAndExpContext : public antlr4::ParserRuleContext {
  public:
    std::string name;
    int cls;
    bool value;
    LAndExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EqExpContext *eqExp();
    LAndExpContext *lAndExp();

   
  };

  LAndExpContext* lAndExp();
  LAndExpContext* lAndExp(int precedence);
  class  LOrExpContext : public antlr4::ParserRuleContext {
  public:
    std::string name;
    int cls;
    bool value;
    LOrExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LAndExpContext *lAndExp();
    LOrExpContext *lOrExp();

   
  };

  LOrExpContext* lOrExp();
  LOrExpContext* lOrExp(int precedence);

  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool addExpSempred(AddExpContext *_localctx, size_t predicateIndex);
  bool mulExpSempred(MulExpContext *_localctx, size_t predicateIndex);
  bool relExpSempred(RelExpContext *_localctx, size_t predicateIndex);
  bool eqExpSempred(EqExpContext *_localctx, size_t predicateIndex);
  bool lAndExpSempred(LAndExpContext *_localctx, size_t predicateIndex);
  bool lOrExpSempred(LOrExpContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

