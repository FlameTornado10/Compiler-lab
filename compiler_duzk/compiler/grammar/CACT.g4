grammar CACT;

// The language generated
options {
    language = Cpp;
}

@header {
    #include <vector>
    #include <string>
}

/********** Parser **********/
compUnit
    : (decl | funcDef)+ EOF
    ;

decl
    : constDecl
    | varDecl
    ;

constDecl
    : 'const' bType constDef (',' constDef)* ';'
    ;

bType
    : 'int'
    | 'bool'
    | 'float'
    | 'double'
    ;

constDef                                                    // const define     
    : Ident '=' constExp                                                # constDefVal
    | Ident '[' IntConst ']' '=' '{' (constExp (',' constExp)*)? '}'    # constDefArray
    ;

constExp
    locals[
        std::string name,
        int cls
    ]
    : number            #constExpNumber
    | BoolConst         #constExpBoolConst
    ;

varDecl
    : bType varDef (',' varDef)* ';'
    ;

varDef
    : Ident                                                             # varDefVal
    | Ident '[' IntConst ']'                                            # varDefArray
    | Ident '=' constExp                                                # varDefInitVal
    | Ident '[' IntConst ']' '=' '{' (constExp (',' constExp)*)? '}'    # varDefInitArray
    ;

funcDef
    : ret = funcType name = Ident '(' (funcFParam (',' funcFParam)*)? ')' block
    ;

funcType
    : 'void'
    | 'int'
    | 'float'
    | 'double'
    | 'bool'
    ;

funcFParam
    : bType Ident ('[' ']')?
    ;

block
    : '{' (blockltem)* '}'
    ;

blockltem
    : decl
    | stmt
    ;

stmt
    : lVal '=' exp ';'                      # assignStmt
    | (exp)? ';'                            # exprStmt
    | block                                 # blockStmt
    | 'if' '(' cond ')' stmt                # ifStmt    // condition
    | 'if' '(' cond ')' stmt elseStmt       # ifElseStmt
    | 'while' '(' cond ')' stmt             # whileStmt
    | 'break' ';'                           # breakStmt
    | 'continue' ';'                        # continueStmt
    | 'return' (exp)? ';'                   # returnStmt
    ;
elseStmt
    : 'else' stmt
    ;


cond
    locals[
        std::string name,
        int cls,
        bool value
    ]
    : lOrExp
    ;

lVal
    locals[
        std::string name,
        int cls,
        bool elemwise
    ]
    :Ident ('[' exp ']')?
    ;
exp 
    locals[
        std::string name,
        int cls
    ]
    : addExp
    | BoolConst
    ;
    
addExp
    locals[
        std::string name,
        int cls,
        bool elemwise
    ]
    : mulExp
    | addExp ('+' | '-') mulExp
    ;
mulExp
    locals[
        std::string name,
        int cls,
        bool elemwise
    ]
    : unaryExp
    | mulExp ('*' | '/' | '%') unaryExp
    ;
primaryExp
    locals[
        std::string name,
        int cls,
        bool elemwise
    ]
    : '(' exp ')'
    | lVal
    | BoolConst
    | number
    ;
unaryExp 
    locals[
        std::string name,
        int cls,
        bool elemwise
    ]
    : primaryExp                    # primary
    | Ident '(' (funcRParams)? ')'  # funcCall
    | unaryOp unaryExp              # unary
    ;


number
    locals[
        std::string name,
        int cls
    ]
    : IntConst
    | DoubleConst
    | FloatConst
    ;

funcRParams
    : exp (',' exp)*
    ;

unaryOp
    : '+'
    | '-'
    | '!'
    ;




relExp
    locals[
        std::string name,
        int cls,
        bool value
    ]
    : addExp
    | relExp ('<' | '>' | '<=' | '>=') addExp
    | BoolConst
    ;

eqExp
    locals[
        std::string name,
        int cls,
        bool value
    ]
    : relExp
    | eqExp ('==' | '!=') relExp
    ;

lAndExp
    locals[
        std::string name,
        int cls,
        bool value
    ]
    : eqExp
    | lAndExp '&&' eqExp
    ;

lOrExp
    locals[
        std::string name,
        int cls,
        bool value
    ]
    : lAndExp
    | lOrExp '||' lAndExp
    ;


/********** Lexer **********/
BoolConst : 'true' | 'false';
LeftBigBracket : '{';
Ident
    : IdentNondigit [a-zA-Z_0-9]*
    ;

fragment
IdentNondigit
    : [a-zA-Z_]
    ;

fragment
Digit
    : [0-9]
    ;

IntConst
    : DecimalConst 
    | OctalConst
    | HexadecimalConst
    ;

fragment
DecimalConst
    : '0'
    | NonzeroDigit Digit*
    ;

fragment
OctalConst
    : '0' OctalDigit+
    ;

fragment
HexadecimalConst
    : HexadecimalPrefix HexadecimalDigit+
    ;

fragment
NonzeroDigit
    : [1-9]
    ;

fragment
OctalDigit
    : [0-7]
    ;

fragment
HexadecimalPrefix
    : '0x'
    | '0X'
    ;

fragment
HexadecimalDigit
    : [0-9a-fA-F]
    ;

DoubleConst
    : FloatSequence
    | FloatSequence ScientificNotation
    | Digit* ScientificNotation
    ;

FloatConst
    : FloatSequence FloatSuffix
    | FloatSequence ScientificNotation FloatSuffix
    | Digit* ScientificNotation FloatSuffix
    ;

fragment
FloatSuffix
    : 'F'
    | 'f'
    ;

fragment
FloatSequence
    : Digit* '.' Digit+
    | Digit+ '.' Digit*
    ;

fragment
ScientificNotation
    : ('e' | 'E') ('+' | '-')? Digit+
    ;

NewLine
    : ('\r' '\n'? | '\n') 
      -> skip
    ;

WhiteSpace
    : [ \t]+ 
      -> skip
    ;

BlockComment
    : '/*' .*? '*/'
      -> skip
    ;

LineComment
    : '//' ~[\r\n]*
      -> skip
    ;