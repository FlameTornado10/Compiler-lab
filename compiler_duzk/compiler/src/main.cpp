#include <iostream>

#include "antlr4-runtime.h"
#include "../grammar/CACTLexer.h"
#include "../grammar/CACTParser.h"
#include "../grammar/CACTBaseListener.h"

#include "semanticAnalysis.h"

using namespace antlr4;
int flagflagflag;
int main(int argc, const char* argv[]) {
    std::ifstream stream;
    stream.open(argv[1]);
    ANTLRInputStream input(stream);
    
    // Syntax analysis 
    CACTLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    CACTParser parser(&tokens);

    // Semantic analysis
    SemanticAnalysis listener;
    tree::ParseTree *tree = parser.compUnit();
    if(lexer.getNumberOfSyntaxErrors() >0 || parser.getNumberOfSyntaxErrors()>0){
        std::cout << "syntax error!" << std::endl;
        return 1;
    }
    std::cout << "Semantic Analysis begins!" << std::endl;
        // tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);
    tree::ParseTreeWalker walker;
    // semantic analysis and basic intemediate code generation
    try {
        walker.walk(&listener, tree);
    } catch (const std::exception &e){
        std::cerr << e.what();
        std::cout << "Semantic Error!" << std::endl;
        exit(1);
    }
    traverse_time++;
    // try {
    //     walker.walk(&listener, tree);
    // } catch (const std::exception &e){
    //     std::cerr << e.what();
    //     std::cout << "Semantic Error!" << std::endl;
    //     exit(1);
    // }

    std::cout << "debug: hello" << std::endl;

    std::cout << "-------------------------Print AST:--------------------------" << std::endl;
    std::cout << tree->toStringTree(&parser) << std::endl;

    return 0;
        //test
}
