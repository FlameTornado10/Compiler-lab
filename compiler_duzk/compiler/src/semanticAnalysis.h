#pragma

#include "../grammar/CACTBaseListener.h"
#include "../grammar/CACTLexer.h"
#include "IR.h"
#include "RISCV.h"
extern int traverse_time;
class SemanticAnalysis : public CACTBaseListener
{
private:
    /* data */
    SymbolTable sym_table;
	IR ir;
	RISCV rv;
    std::stack<std::string> tp_stack;   // type stack
    std::vector<std::string> label_stack; // label stack
	std::string parameter_string;

    antlr4::tree::ParseTreeProperty<std::vector<std::string>> if_labels;
    antlr4::tree::ParseTreeProperty<std::vector<std::string>> while_labels;
public:
    SemanticAnalysis(/* args */){}
    ~SemanticAnalysis(){}

    // start
    void enterCompUnit(CACTParser::CompUnitContext * /*ctx*/) override;
    void exitCompUnit(CACTParser::CompUnitContext * /*ctx*/) override;

    // const declare
	void enterConstDecl(CACTParser::ConstDeclContext * /*ctx*/) override;
	void exitConstDecl(CACTParser::ConstDeclContext * /*ctx*/) override;

	void enterConstDefVal(CACTParser::ConstDefValContext * /*ctx*/) override;
	void exitConstDefVal(CACTParser::ConstDefValContext * /*ctx*/) override;

	void enterConstDefArray(CACTParser::ConstDefArrayContext * /*ctx*/) override;
	void exitConstDefArray(CACTParser::ConstDefArrayContext * /*ctx*/) override;

	// var decl
	void enterVarDecl(CACTParser::VarDeclContext * /*ctx*/) override;
	void exitVarDecl(CACTParser::VarDeclContext * /*ctx*/) override;

	void enterVarDefVal(CACTParser::VarDefValContext * /*ctx*/) override;
	void exitVarDefVal(CACTParser::VarDefValContext * /*ctx*/) override;

	void enterVarDefArray(CACTParser::VarDefArrayContext * /*ctx*/) override;
	void exitVarDefArray(CACTParser::VarDefArrayContext * /*ctx*/) override;

	void enterVarDefInitVal(CACTParser::VarDefInitValContext * /*ctx*/) override;
	void exitVarDefInitVal(CACTParser::VarDefInitValContext * /*ctx*/) override;

	void enterVarDefInitArray(CACTParser::VarDefInitArrayContext * /*ctx*/) override;
	void exitVarDefInitArray(CACTParser::VarDefInitArrayContext * /*ctx*/) override;
    
    // function define
    void enterFuncDef(CACTParser::FuncDefContext * /*ctx*/) override ;
    void exitFuncDef(CACTParser::FuncDefContext * /*ctx*/) override ;

	// block
	void enterBlock(CACTParser::BlockContext * /*ctx*/) override;
	void exitBlock(CACTParser::BlockContext * /*ctx*/) override;

	// function statement
	void enterFuncCall(CACTParser::FuncCallContext * /*ctx*/) override;
	void exitFuncCall(CACTParser::FuncCallContext * /*ctx*/) override;

    void enterReturnStmt(CACTParser::ReturnStmtContext * /*ctx*/) override;
	void exitReturnStmt(CACTParser::ReturnStmtContext * /*ctx*/) override;

    // condition statement
    void enterCond(CACTParser::CondContext * /*ctx*/) override ;
    void exitCond(CACTParser::CondContext * /*ctx*/) override ;

	void enterIfStmt(CACTParser::IfStmtContext * /*ctx*/) override;
	void exitIfStmt(CACTParser::IfStmtContext * /*ctx*/) override;

	void enterIfElseStmt(CACTParser::IfElseStmtContext * /*ctx*/) override;
	void exitIfElseStmt(CACTParser::IfElseStmtContext * /*ctx*/) override;

	void enterElseStmt(CACTParser::ElseStmtContext* ) override;
	void exitElseStmt(CACTParser::ElseStmtContext* ) override;

	void enterWhileStmt(CACTParser::WhileStmtContext * /*ctx*/) override;
	void exitWhileStmt(CACTParser::WhileStmtContext * /*ctx*/) override;

	void enterBreakStmt(CACTParser::BreakStmtContext * /*ctx*/) override;
  	void exitBreakStmt(CACTParser::BreakStmtContext * /*ctx*/) override;

 	void enterContinueStmt(CACTParser::ContinueStmtContext * /*ctx*/) override;
	void exitContinueStmt(CACTParser::ContinueStmtContext * /*ctx*/) override;

    // expression
	void enterAssignStmt(CACTParser::AssignStmtContext * /*ctx*/) override;
	void exitAssignStmt(CACTParser::AssignStmtContext * /*ctx*/) override;

	void enterExp(CACTParser::ExpContext * /*ctx*/) override;
	void exitExp(CACTParser::ExpContext * /*ctx*/) override;

	void enterLVal(CACTParser::LValContext * /*ctx*/) override;
	void exitLVal(CACTParser::LValContext * /*ctx*/) override;

	void enterPrimary(CACTParser::PrimaryContext * /*ctx*/) override;
	void exitPrimary(CACTParser::PrimaryContext * /*ctx*/) override;

	void enterUnary(CACTParser::UnaryContext * /*ctx*/) override;
	void exitUnary(CACTParser::UnaryContext * /*ctx*/) override;

	void enterMulExp(CACTParser::MulExpContext * /*ctx*/) override;
	void exitMulExp(CACTParser::MulExpContext * /*ctx*/) override;

	void enterAddExp(CACTParser::AddExpContext * /*ctx*/) override;
	void exitAddExp(CACTParser::AddExpContext * /*ctx*/) override;

	void enterRelExp(CACTParser::RelExpContext * /*ctx*/) override;
	void exitRelExp(CACTParser::RelExpContext * /*ctx*/) override;

	void enterEqExp(CACTParser::EqExpContext * /*ctx*/) override;
	void exitEqExp(CACTParser::EqExpContext * /*ctx*/) override;

	void enterLAndExp(CACTParser::LAndExpContext * /*ctx*/) override;
	void exitLAndExp(CACTParser::LAndExpContext * /*ctx*/) override;

	void enterLOrExp(CACTParser::LOrExpContext * /*ctx*/) override;
	void exitLOrExp(CACTParser::LOrExpContext * /*ctx*/) override;
};
