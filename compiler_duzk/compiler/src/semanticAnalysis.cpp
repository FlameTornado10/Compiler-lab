

#include "semanticAnalysis.h"
#include <stdio.h>
#include "symbolTable.h"
using namespace OP;
using namespace REGS;
using namespace std;
extern int flagflagflag;
// TOOL
#define check_initial_array_class(var_cls, literal_type)               \
    (var_cls == CLS_INT && literal_type != CACTLexer::IntConst ||      \
     var_cls == CLS_BOOLEAN && literal_type != CACTLexer::BoolConst || \
     var_cls == CLS_FLOAT && literal_type != CACTLexer::FloatConst ||  \
     var_cls == CLS_DOUBLE && literal_type != CACTLexer::DoubleConst)
#define IS_GLO 1
#define NO_GLO 0
// TOOL
int string_to_class(string class_str, size_t line, bool include_void = true) {
    if (class_str == "int")
        return CLS_INT;
    else if (class_str == "bool")
        return CLS_BOOLEAN;
    else if (class_str == "float")
        return CLS_FLOAT;
    else if (class_str == "double")
        return CLS_DOUBLE;
    else if ((class_str == "void") && include_void)
        return CLS_VOID;
    else
        throw runtime_error("line " +
                            to_string(line) +
                            ": error: unknown class: '" + class_str + "'\n");
}
Var* temp;
void SemanticAnalysis::enterCompUnit(CACTParser::CompUnitContext* ctx) {
    if (traverse_time == 0) {
        cout << "[DEBUG] [A] in  compunit" << endl;
        sym_table.addFunc("print_int", CLS_VOID, 1, 0);
        sym_table.addSymbol("_int_", CLS_INT, TP_PARAM, 0, 0);
        sym_table.block_s.pop_back();
        sym_table.cur_func = "$";

        sym_table.addFunc("print_float", CLS_VOID, 1, 0);
        sym_table.addSymbol("_float_", CLS_FLOAT, TP_PARAM, 0, 0);
        sym_table.block_s.pop_back();
        sym_table.cur_func = "$";

        sym_table.addFunc("print_double", CLS_VOID, 1, 0);
        sym_table.addSymbol("_double_", CLS_DOUBLE, TP_PARAM, 0, 0);
        sym_table.block_s.pop_back();
        sym_table.cur_func = "$";

        sym_table.addFunc("print_bool", CLS_VOID, 1, 0);
        sym_table.addSymbol("_bool_", CLS_BOOLEAN, TP_PARAM, 0, 0);
        sym_table.block_s.pop_back();
        sym_table.cur_func = "$";

        sym_table.addFunc("get_int", CLS_INT, 0, 0);
        sym_table.block_s.pop_back();
        sym_table.cur_func = "$";

        sym_table.addFunc("get_float", CLS_FLOAT, 0, 0);
        sym_table.block_s.pop_back();
        sym_table.cur_func = "$";

        sym_table.addFunc("get_double", CLS_DOUBLE, 0, 0);
        sym_table.block_s.pop_back();
        sym_table.cur_func = "$";
    }
}
void SemanticAnalysis::exitCompUnit(CACTParser::CompUnitContext* ctx) {
    if (traverse_time == 0) {
        if (sym_table.lookup_func("main") == nullptr)
            throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                ": error: function 'main' not found\n");
        cout << "I'm out!!!!!!"
             << "\n";

        ir.printIC();
        cout << "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT\n";
        cout << "---------------------------------------------------------\n";
        for (auto i = ir.labels_and_codes.begin();
             i != ir.labels_and_codes.end(); i++) {
            std::cout << "i.first: " << i->first << "     ";
            std::cout << "i.second.op: " << i->second.op << "\n";
        }
        ir.traverse_for_redundant_label();
        ir.printIC();
        rv.printRC();

        string a_str = "7.8";
        double double_val = stod(a_str);  // stod
        cout << "HEY " << double_val << endl;
        string value_str = to_string(double_val);  // to_string
        cout << "HEY " << value_str << endl;
        double dval = stod(value_str);  // sto_d
        cout << "HEY " << dval << endl;
        long long decimal_dval = *(long long*)(&dval);
        cout << to_string(decimal_dval) << endl;
        vector<int> test;
        test.push_back(0);
        test.push_back(1);
        test.push_back(3);
        auto ite = test.begin() + 2;
        test.insert(ite, 4);
        int size = test.size();
        for (int i = 0; i < size; i++) {
            cout << test[i];
        }
        cout << endl;
        cout << to_string(true) << endl;
        // Var* jj = sym_table.lookup_var(temp->name);
        // cout<<"HEY "<<(jj == nullptr)<<endl;

        // vector<int> tt;
        // tt.push_back(0);
        // tt.push_back(1);
        // for (auto a = tt.end() - 1; *a != 0; a--)
        //     cout << "GGGJJJKKK" << *a;
        // cout<<endl;
        // map<int, int> test;
        // test[0] = 1;
        // test[1] = 2;
        // test[0] = 2;
        // cout<<test[0]<<test[1]<<test[0]<<"\n";

        /* LRU test
            int regs[40] = {0};
            Var* temp;
            Var* temp1;
            for (int i = 0; i < 28; i++){
                string temp_var = sym_table.gen_temp_var(0, CLS_FLOAT, TP_VAR);
                Var* var_info = sym_table.lookup_var(temp_var);
                regs[i] = rv.getReg(var_info->cls, var_info);
                cout<<reg_name[regs[i]]<<endl;
                if (i == 2){
                    temp = var_info;
                }
                if (i == 5){
                    temp1 = var_info;
                }
            }
            regs[39] = rv.getReg(temp->cls,temp);
            regs[39] = rv.getReg(temp1->cls,temp1);
            int i = 0;
            for (auto a : FltRegs){
                cout<<setw(4)<<reg_name[a]<<" "<<setw(2)<<a<<": pos: ";
                cout<<setw(2)<<rv.flt_regs_pos[a]<<" ";
                cout<<"lru vec: ";
                cout<<reg_name[rv.lru_vec_flt_regs[i]]<<" ";
                cout<<rv.lru_vec_flt_regs[i];
                cout<<" ";
                i++;
                cout<<endl;
            }
            for (auto a : FltRegs){
                int pos = rv.flt_regs_pos[a];
                if (rv.lru_vec_flt_regs[pos] != a){
                    cout<<"wrong!"<<"\n";
                }
            }*/
    }
    if (traverse_time == 1) {
        ir.traverse_for_redundant_label();
    }
}

void SemanticAnalysis::enterConstDecl(CACTParser::ConstDeclContext* ctx) {
    string type_str = ctx->bType()->getText();
    tp_stack.push(type_str);
}
void SemanticAnalysis::exitConstDecl(CACTParser::ConstDeclContext* ctx) {
    tp_stack.pop();
    // cout << "const variable define: " << endl;
    // for(const auto & const_def : ctx->constDef())    {
    //     cout << "\tname: " << const_def->Ident()->getText().c_str() \
    //             << " type: " << ctx->bType()->getText().c_str() << endl;
    // }
}

void SemanticAnalysis::enterFuncDef(CACTParser::FuncDefContext* ctx) {
    if (traverse_time == 0) {
        string func_name = ctx->name->getText();
        string ret_class_str = ctx->ret->getText();
        cout << "[DEBUG] [A] in  func def: function name: " + func_name << endl;
        sym_table.stack_offset = 0;
        sym_table.temp_in_func = 0;
        cout << "\treturn class: " << ret_class_str;
        cout << "\n";
        int ret_class = string_to_class(ret_class_str, ctx->getStart()->getLine());

        cout << "\tret_class: " << ret_class;
        cout << "\n";
        int param_num = ctx->funcFParam().size();
        if (func_name == "main") {
            if (param_num != 0)
                throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                    ": error: too many arguments for function 'main'\n");
            if (ret_class != CLS_INT)
                throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                    ": error: function 'main' returns " + ret_class_str + "\n");
        }
        // add function to symbol table
        sym_table.addFunc(func_name, ret_class, param_num, ctx->getStart()->getLine());

        // add parameters to symbol table
        int param_index = 0;
        string param_string = "";
        for (auto& param : ctx->funcFParam()) {
            string param_name = param->Ident()->getText();
            int param_class = string_to_class(param->bType()->getText(), ctx->getStart()->getLine(), false);
            std::cout << "PPPPPPP: param_class: " << param_class << " " << param_name << "\n";
            sym_table.addSymbol(param_name, param_class, TP_PARAM, param_index, param->getStart()->getLine());
            param_string.append(to_string(param_class));
            param_index++;
        }
        int size = sym_table.block_s.size();
        auto cur_block = sym_table.block_s[size - 1];
        cout << "\t"
             << "params' classes: " << param_string << "\n";
        ir.addIC(func_name, FUNC_BEGIN, param_string, VOID, ret_class, 0, VOID);
        int i, j;
        for (auto& param : ctx->funcFParam()) {
            string param_name = param->Ident()->getText();
            int param_class = string_to_class(param->bType()->getText(), ctx->getStart()->getLine(), false);
            ir.addIC(param_name, ALLOCA, VOID, VOID, param_class, NO_GLO, VOID);
        }
        j = 1;
        for (auto& param : ctx->funcFParam()) {
            i = param_num + j;
            int origin = j - 1;
            string param_name = param->Ident()->getText();
            int param_class = string_to_class(param->bType()->getText(), ctx->getStart()->getLine(), false);
            Var* info = sym_table.lookup_var(param_name);
            string offset_str = sym_table.get_s0_offset(info);
            ir.addIC(param_name, STORE_PARAM, to_string(origin), offset_str, param_class, NO_GLO, VOID);
            j++;
        }
        sym_table.temp_in_func = 2 * param_num;
    }
}
void SemanticAnalysis::exitFuncDef(CACTParser::FuncDefContext* ctx) {
    if (traverse_time == 0) {
        string func_name = ctx->name->getText();
        Func* funcInfo = sym_table.lookup_func(func_name);
        funcInfo->stack_size = sym_table.stack_offset;
        sym_table.cur_func = "$";
        sym_table.block_s.pop_back();
        sym_table.stack_offset = 0;
        ir.addIC(func_name, FUNC_END, "ERROR in exit FuncDef", VOID, 6, 0, VOID);
        rv.finish_func_begin_end_in_RV(func_name, sym_table);
        rv.clear_func(sym_table);
        for (auto a : rv.func_regs[func_name + "int"]) {
            cout << a << endl;
        }
        cout << "exitFuncdef" << endl;
    }
}
// TOOL
int getIntBase(string int_string) {
    int base = 10;
    if (int_string.substr(0, 1) == "0") {
        if (int_string.substr(0, 2) == "0x" || int_string.substr(0, 2) == "0X")
            base = 16;
        else
            base = 8;
    } else if (int_string.substr(0, 1) == "-") {  // recursion
        if (int_string.substr(1, 2) == "0x" || int_string.substr(1, 2) == "0X")
            base = 16;
        else if (int_string.substr(1, 1) == "0")
            base = 8;
    }
    return base;
}
// TOOL
void check_class_and_get_val(int& var_cls, string& value_str, string lex_val, size_t getType, int line, string cls_str, string var_name, int& int_val, bool& bool_val, float& float_val, double& double_val) {
    if (cls_str == "int") {
        var_cls = CLS_INT;
        if (getType != CACTLexer::IntConst)
            throw runtime_error("line " + to_string(line) + ": error: invalid init value of '" + var_name + "'\n");
        int_val = stoi(lex_val, 0, getIntBase(lex_val));
        value_str = to_string(int_val);
    } else if (cls_str == "bool") {
        var_cls = CLS_BOOLEAN;
        if (getType != CACTLexer::BoolConst)
            throw runtime_error("line " + to_string(line) + ": error: invalid init value of '" + var_name + "'\n");
        bool_val = (lex_val == "true") ? true : false;
        value_str = to_string(bool_val);
    } else if (cls_str == "float") {
        var_cls = CLS_FLOAT;
        if (getType != CACTLexer::FloatConst)
            throw runtime_error("line " + to_string(line) + ": error: invalid init value of '" + var_name + "'\n");
        float_val = stof(lex_val.substr(0, lex_val.length() - 1));
        value_str = to_string(float_val);
    } else if (cls_str == "double") {
        var_cls = CLS_DOUBLE;
        if (getType != CACTLexer::DoubleConst)
            throw runtime_error("line " + to_string(line) + ": error: invalid init value of '" + var_name + "'\n");
        double_val = stod(lex_val);
        value_str = to_string(double_val);
    } else {
        throw runtime_error("line " + to_string(line) +
                            ": error: unknown type name '" + cls_str + "'\n");
    }
}
// Const definition
void SemanticAnalysis::enterConstDefVal(CACTParser::ConstDefValContext* ctx) {
    if (traverse_time == 0) {
        string var_name = ctx->Ident()->getText();
        string cls_str = tp_stack.top();
        string lex_val = ctx->constExp()->getText();  // const's val
        int var_cls;
        string value_str;
        int int_val;
        bool bool_val;
        float float_val;
        double double_val;

        cout << "[DEBUG] [A] in  const def Val: " << var_name << endl;

        check_class_and_get_val(var_cls, value_str, lex_val, ctx->constExp()->getStart()->getType(),
                                ctx->getStart()->getLine(), cls_str, var_name,
                                int_val, bool_val, float_val, double_val);
        cout << "\tvar class: " << var_cls << "\n";
        sym_table.addSymbol(var_name, var_cls, TP_CONST, 0, ctx->getStart()->getLine());
        Var* var = sym_table.lookup_var(var_name);
        auto offset_str = sym_table.get_s0_offset(var);
        if (var->global) {
            ir.addIC(var_name, OP::GLOBAL_ASSIGN, value_str, "const", var_cls, IS_GLO, VOID);
        } else {
            ir.addIC(var_name, ALLOCA, VOID, VOID, var_cls, NO_GLO, VOID);
            ir.addIC(var_name, TEMP_ASSIGN_DIRECT, value_str, offset_str, var_cls, NO_GLO, VOID);
        }
    }
}
void SemanticAnalysis::exitConstDefVal(CACTParser::ConstDefValContext* ctx) {
    if (traverse_time == 0) {
    }
}
// TOOL
void set_value_by_class(int var_cls, const string literal_val, int& int_val, bool& bool_val, float& float_val, double& double_val, string& value_str) {
    if (var_cls == CLS_INT) {
        int_val = std::stoi(literal_val, 0, getIntBase(literal_val));
        value_str = std::to_string(int_val);
    } else if (var_cls == CLS_BOOLEAN) {
        bool_val = (literal_val == "true") ? 1 : 0;
        value_str = std::to_string(bool_val);
    } else if (var_cls == CLS_FLOAT) {
        float_val = std::stof(literal_val.substr(0, literal_val.length() - 1));
        value_str = std::to_string(float_val);
    } else if (var_cls == CLS_DOUBLE) {
        double_val = std::stod(literal_val);
        value_str = std::to_string(double_val);
    }
}
// global & not global
void SemanticAnalysis::enterConstDefArray(CACTParser::ConstDefArrayContext* ctx) {
    if (traverse_time == 0) {
        string var_name = ctx->Ident()->getText();
        cout << "Bracket: "
             << to_string(ctx->LeftBigBracket()->getSymbol()->getType())
             << endl;

        int array_len = stoi(ctx->IntConst()->getText());
        if (array_len <= 0)
            throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                ": error: size of array '" + var_name + "' is negative\n");
        string class_str = tp_stack.top();  // type
        string value_str;
        int int_val;
        bool bool_val;
        float float_val;
        double double_val;
        int var_cls = string_to_class(class_str, ctx->getStart()->getLine(), false);

        sym_table.addSymbol(var_name, var_cls, TP_CONST_ARRAY, array_len, ctx->getStart()->getLine());

        Var* var = sym_table.lookup_var(var_name);
        int item_count = 0;

        string temp = (var->global) ? var_name : sym_table.cur_func + "." + var_name;
        if (var->global) {
            ir.addIC(var_name, GLOBAL_ARRAY, std::to_string(array_len), "const", var_cls, IS_GLO, VOID);
            for (auto& elem : ctx->constExp()) {
                string literal_val = elem->getText();
                auto literal_type = elem->getStart()->getType();
                cout << "type: " + to_string(literal_type)
                     << endl;
                if (check_initial_array_class(var_cls, literal_type))
                    throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                        ": error: invalid init value of '" + var_name + "'\n");
                set_value_by_class(var_cls, literal_val,
                                   int_val, bool_val, float_val, double_val,
                                   value_str);
                ir.addIC(var_name, OP::GLOBAL_ARRAY_ASSIGN, value_str, std::to_string(item_count), var_cls, IS_GLO, VOID);
                item_count++;
            }
            if (item_count > array_len)
                throw runtime_error("line " + to_string(ctx->getStart()->getLine()) + ": error: excess elements in array init value\n");
            while (item_count < array_len) {
                ir.addIC(var_name, OP::GLOBAL_ARRAY_ASSIGN, "0",
                         std::to_string(item_count), var_cls, IS_GLO, VOID);
                item_count++;
            }
        } else {
            ir.addIC(var_name, ALLOCA_ARRAY, std::to_string(array_len), VOID, var_cls, NO_GLO, VOID);
            for (auto& elem : ctx->constExp()) {
                string literal_val = elem->getText();
                auto literal_type = elem->getStart()->getType();
                if (check_initial_array_class(var_cls, literal_type)) {
                    throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                        ": error: invalid init value of '" + var_name + "'\n");
                }
                set_value_by_class(var_cls, literal_val,
                                   int_val, bool_val, float_val, double_val,
                                   value_str);
                ir.addIC(var_name, OP::ARRAY_ASSIGN_INIT,
                         value_str, std::to_string(item_count), var_cls, NO_GLO, VOID);
                item_count++;
            }
            if (item_count > array_len)
                throw runtime_error("line " + to_string(ctx->getStart()->getLine()) + ": error: excess elements in array init value\n");
            while (item_count < array_len) {
                ir.addIC(var_name, OP::ARRAY_ASSIGN_INIT,
                         "0", std::to_string(item_count), var_cls, NO_GLO, VOID);
                item_count++;
            }
        }
    }
}
void SemanticAnalysis::exitConstDefArray(CACTParser::ConstDefArrayContext* ctx) {
    if (traverse_time == 0) {
        cout << "[DEBUG] [A] out const def array"
             << ctx->constExp().back()->getText()
             << "\n";
    }
}

// Variable declaration
void SemanticAnalysis::enterVarDecl(CACTParser::VarDeclContext* ctx) {
    if (traverse_time == 0) {
        string cls_str = ctx->bType()->getText();
        cout << "[DEBUG] [A] in  var declare:" + cls_str << endl;
        tp_stack.push(cls_str);
    }
}
void SemanticAnalysis::exitVarDecl(CACTParser::VarDeclContext* ctx) {
    if (traverse_time == 0) {
        cout << "[DEBUG] [A] out var declare" << endl;
        tp_stack.pop();
        // cout << "variable define: " << endl;
        // for(const auto & var_def : ctx->varDef()){
        //     cout << "\tname: " << var_def->Ident()->getText().c_str() \
    //             << " type: " << ctx->bType()->getText().c_str() << endl;
        // }
    }
}

void SemanticAnalysis::enterVarDefVal(CACTParser::VarDefValContext* ctx) {
    if (traverse_time == 0) {
        string var_name = ctx->Ident()->getText();  // variable name
        string class_str = tp_stack.top();          // class
        int var_cls = string_to_class(class_str, ctx->getStart()->getLine(), false);
        sym_table.addSymbol(var_name, var_cls, TP_VAR, 0, ctx->getStart()->getLine());
        Var* var = sym_table.lookup_var(var_name);
        if (var_name == "a") {
            temp = var;
            cout << "HAHA HAHA" << endl;
        }
        auto offset_str = sym_table.get_s0_offset(var);
        if (var->global) {
            ir.addIC(var_name, OP::GLOBAL_ASSIGN, "0", "", var_cls, IS_GLO, VOID);
        } else {
            ir.addIC(var_name, ALLOCA, VOID, VOID, var_cls, NO_GLO, VOID);
            string value_str;
            if (CLS_FLOAT == var->cls || CLS_DOUBLE == var->cls)
                value_str = "0.0";
            else
                value_str = "0";
            ir.addIC(var_name, TEMP_ASSIGN_DIRECT, value_str, offset_str, var_cls, NO_GLO, VOID);
        }
        // ir.addIC(to_string(sym_table.temp_in_func + 1), ALLOCA, VOID, VOID, var_cls, 0);
        // sym_table.temp_in_func++;
    }
}
void SemanticAnalysis::exitVarDefVal(CACTParser::VarDefValContext* ctx) {}

void SemanticAnalysis::enterVarDefArray(CACTParser::VarDefArrayContext* ctx) {
    if (traverse_time == 0) {
        string var_name = ctx->Ident()->getText();  // 类型名
        int array_len = stoi(ctx->IntConst()->getText());
        if (array_len <= 0)
            throw runtime_error("line " + to_string(ctx->getStart()->getLine()) + ": error: size of array '" + var_name + "' is negative\n");
        string class_str = tp_stack.top();                                            // 类型名
        int var_cls = string_to_class(class_str, ctx->getStart()->getLine(), false);  // 类型变量
        cout << "[DEBUG] [A] in  var def array " << var_name << " "
             << "length: " << array_len
             << endl;

        sym_table.addSymbol(var_name, var_cls, TP_ARRAY, array_len, ctx->getStart()->getLine());
        Var* array_info = sym_table.lookup_var(var_name);
        cout << "\t"
             << "global: " << array_info->global << "\n";
        if (array_info->global) {
            ir.addIC(var_name, GLOBAL_ARRAY, std::to_string(array_len), "const", var_cls, IS_GLO, VOID);
            for (int i = 1; i <= array_len; i++) {
                ir.addIC(var_name, OP::GLOBAL_ARRAY_ASSIGN, "0", std::to_string(i), var_cls, IS_GLO, VOID);
            }
        } else {
            ir.addIC(var_name, ALLOCA_ARRAY, std::to_string(array_len), VOID, var_cls, NO_GLO, VOID);
        }
    }
}
void SemanticAnalysis::exitVarDefArray(CACTParser::VarDefArrayContext* ctx) {}

void SemanticAnalysis::enterVarDefInitVal(CACTParser::VarDefInitValContext* ctx) {
    if (traverse_time == 0) {
        string var_name = ctx->Ident()->getText();  // 变量名
        cout << "[DEBUG] [A] in  var def init Val: " + var_name << endl;
        string cls_str = tp_stack.top();                  // 类型名
        string literal_val = ctx->constExp()->getText();  // 初始值
        int var_cls;
        string value_str;
        int int_val;
        bool bool_val;
        float float_val;
        double double_val;
        check_class_and_get_val(var_cls, value_str, literal_val, ctx->constExp()->getStart()->getType(),
                                ctx->getStart()->getLine(), cls_str, var_name,
                                int_val, bool_val, float_val, double_val);

        sym_table.addSymbol(var_name, var_cls, TP_VAR, 0, ctx->getStart()->getLine());
        Var* var = sym_table.lookup_var(var_name);
        auto offset_str = sym_table.get_s0_offset(var);
        if (var->global) {
            ir.addIC(var_name, OP::GLOBAL_ASSIGN, value_str, " ", var_cls, IS_GLO, VOID);
        } else {
            ir.addIC(var_name, ALLOCA, VOID, VOID, var_cls, NO_GLO, VOID);
            ir.addIC(var_name, TEMP_ASSIGN_DIRECT, value_str, offset_str, var_cls, NO_GLO, VOID);
        }
    }
}
void SemanticAnalysis::exitVarDefInitVal(CACTParser::VarDefInitValContext* ctx) {}

void SemanticAnalysis::enterVarDefInitArray(CACTParser::VarDefInitArrayContext* ctx) {
    if (traverse_time == 0) {
        string var_name = ctx->Ident()->getText();  // 类型名
        int array_len = stoi(ctx->IntConst()->getText());
        if (array_len <= 0)
            throw runtime_error("line " + to_string(ctx->getStart()->getLine()) + ": error: size of array '" + var_name + "' is negative\n");
        string class_str = tp_stack.top();  // 类型名
        string value_str;
        int int_val;
        bool bool_val;
        float float_val;
        double double_val;
        int var_cls = string_to_class(class_str, ctx->getStart()->getLine(), false);

        sym_table.addSymbol(var_name, var_cls, TP_ARRAY, array_len, ctx->getStart()->getLine());

        Var* var = sym_table.lookup_var(var_name);
        int init_count = 0;
        if (var->global) {
            ir.addIC(var_name, GLOBAL_ARRAY, std::to_string(array_len), " ", var_cls, IS_GLO, VOID);
            for (auto& elem : ctx->constExp()) {
                string literal_val = elem->getText();
                auto literal_type = elem->getStart()->getType();

                if (check_initial_array_class(var_cls, literal_type))
                    throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                        ": error: invalid init value of '" + var_name + "'\n");
                set_value_by_class(var_cls, literal_val,
                                   int_val, bool_val, float_val, double_val,
                                   value_str);
                ir.addIC(var_name, OP::GLOBAL_ARRAY_ASSIGN, value_str, std::to_string(init_count), var_cls, IS_GLO, VOID);
                init_count++;
            }
            if (init_count > array_len)
                throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                    ": error: excess elements in array initializer\n");
            while (init_count < array_len) {
                ir.addIC(var_name, OP::GLOBAL_ARRAY_ASSIGN, "0", std::to_string(init_count), var_cls, IS_GLO, VOID);
                init_count++;
            }
        } else {
            ir.addIC(var_name, ALLOCA_ARRAY, std::to_string(array_len), VOID, var_cls, NO_GLO, VOID);
            for (auto& elem : ctx->constExp()) {
                string literal_val = elem->getText();
                auto literal_type = elem->getStart()->getType();

                if (check_initial_array_class(var_cls, literal_type))
                    throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                        ": error: invalid initializer of '" + var_name + "'\n");
                set_value_by_class(var_cls, literal_val,
                                   int_val, bool_val, float_val, double_val,
                                   value_str);
                ir.addIC(var_name, OP::ARRAY_ASSIGN_INIT,
                         value_str, std::to_string(init_count), var_cls, NO_GLO, VOID);
                init_count++;
            }
            if (init_count > array_len)
                throw runtime_error("line " + to_string(ctx->getStart()->getLine()) + ": error: excess elements in array initializer\n");
            while (init_count < array_len) {
                ir.addIC(var_name, OP::ARRAY_ASSIGN_INIT, "0", std::to_string(init_count), var_cls, NO_GLO, VOID);
                init_count++;
            }
        }
    }
}
void SemanticAnalysis::exitVarDefInitArray(CACTParser::VarDefInitArrayContext* ctx) {}

// Blocks
void SemanticAnalysis::enterBlock(CACTParser::BlockContext* ctx) {
    if (traverse_time == 0) {
        // add and push
        cout << "[DEBUG] [A] in  block" << endl;
        sym_table.addBlock(ctx->getStart()->getLine());
        cout << "[DEBUG] [A] in  block done" << endl;
        // some IC are generated
        rv.RISCV_GEN(ir, sym_table);
        ir.addIC(VOID, BLOCK_BEGIN, VOID, VOID, 100, NO_GLO, VOID);
    }
}
void SemanticAnalysis::exitBlock(CACTParser::BlockContext* ctx) {
    if (traverse_time == 0) {
        cout << "[DEBUG] [A] out block" << endl;
        rv.RISCV_GEN(ir, sym_table);
        rv.clear_cur_block(sym_table);
        sym_table.block_s.pop_back();
        ir.addIC(VOID, BLOCK_END, VOID, VOID, 100, NO_GLO, VOID);
    }
}
// function
void SemanticAnalysis::enterFuncCall(CACTParser::FuncCallContext* ctx) {
    if (traverse_time == 0) {
        string func_name = ctx->Ident()->getText();
        Func* func_info = sym_table.lookup_func(func_name);
        int para_count = 1;
        auto para_info = sym_table.lookup_param(*func_info, para_count);
        int param_num = 0;
        if (ctx->funcRParams())
            param_num = ctx->funcRParams()->exp().size();

        if (!func_info) {
            throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                ": error: undefined function '" + func_name + "'\n");
        }
        if (param_num < func_info->param_num) {
            throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                ": error: too few arguments to function '" + func_name + "'\n");
        }
        if (param_num > func_info->param_num) {
            throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                ": error: too many arguments to function '" + func_name + "'\n");
        }
    }
}
void SemanticAnalysis::exitFuncCall(CACTParser::FuncCallContext* ctx) {
    if (traverse_time == 0) {
        auto func_name = ctx->Ident()->getText();
        auto func_info = sym_table.lookup_func(func_name);
        cout << "[DEBUG] [A] out funcCall"
             << "\n";
        cout
            << "func name: " << func_name
            << "\n";
        // ir.addIC(var_name, OP::ARRAY_ASSIGN_INIT,
        //                  value_str, std::to_string(init_count), var_cls, NO_GLO,VOID);

        int para_count = 0;
        if (ctx->funcRParams()) {
            int para_num = ctx->funcRParams()->exp().size();
            for (auto& param : ctx->funcRParams()->exp()) {
                auto para_info = sym_table.lookup_param(*func_info, para_count);
                cout << "param class: " << param->cls << " param_name: " << param->name << " "
                     << "\tpara_info class: " << para_info->cls
                     << "\n";
                if (para_info->cls != param->cls)
                    throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                        ": error: incompatible type for argument " + to_string(para_count) +
                                        " of '" + func_name + "'\n");
                Var* temp_info = sym_table.lookup_var(param->name);
                auto offset_str = sym_table.get_s0_offset(temp_info);
                ir.addIC(param->name, CALL_ASSIGN, func_name,
                         to_string(para_count), temp_info->cls, NO_GLO, to_string(para_num));
                para_count++;
            }
            ir.addIC(func_name, OP::CALL, to_string(func_info->param_num),
                     VOID, func_info->cls, NO_GLO, VOID);
        } else {
            ir.addIC(func_name, OP::CALL, to_string(func_info->param_num),
                     VOID, func_info->cls, NO_GLO, VOID);
        }
        if (func_info->cls == CLS_VOID) {
            ctx->cls = CLS_VOID;
        } else {
            auto ret_var = sym_table.gen_temp_var(ctx->getStart()->getLine(), func_info->cls);
            ctx->cls = func_info->cls;
            ctx->name = ret_var;
            Var* ret_info = sym_table.lookup_var(ret_var);
            auto offset_str = sym_table.get_s0_offset(ret_info);
            ir.addIC(ret_var, CALL_STORE_RESULT, offset_str, VOID, func_info->cls, NO_GLO, VOID);
        }
    }
}

void SemanticAnalysis::enterReturnStmt(CACTParser::ReturnStmtContext* ctx) {
    if (traverse_time == 0) {
        cout << "[DEBUG] [A] enter ret stmt" << endl;
    }
}
void SemanticAnalysis::exitReturnStmt(CACTParser::ReturnStmtContext* ctx) {
    if (traverse_time == 0) {
        cout << "[DEBUG] [A] out ret stmt" << endl;

        if (ctx->exp() != nullptr) {
            cout << "exp not null" << endl;
            string ret_name = ctx->exp()->name;
            cout << "ret_name: " + ret_name << endl;

            cout << "cur_func: " + sym_table.cur_func << endl;
            Var* ret_info = sym_table.lookup_var(ret_name);
            Func* func_info = sym_table.lookup_func(sym_table.cur_func);
            int cls = ctx->exp()->cls;
            cout << "func_info class: " << func_info->cls;
            cout << "\tret class: " << cls;
            cout << "\n";
            if (cls != func_info->cls)
                throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                    ": error: returning type incompatible\n");
            ir.addIC(ret_name, OP::RET_VAL, VOID, VOID, func_info->cls, NO_GLO, VOID);

        } else {
            cout << "exp null" << endl;
            Func* func_info = sym_table.lookup_func(sym_table.cur_func);
            if (func_info->cls != CLS_VOID)
                throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                    ": error: returning type incompatible\n");

            ir.addIC(VOID, OP::RET, VOID, VOID, CLS_VOID, NO_GLO, VOID);
        }
        cout << "\t[DEBUG] [A] out ret stmt done" << endl;
    }
}
// branch statement
void SemanticAnalysis::enterIfStmt(CACTParser::IfStmtContext* ctx) {
    if (traverse_time == 0) {
        auto label1 = ir.gen_label();
        std::vector<std::string> label_set = {label1};
        if_labels.put(ctx, label_set);
    }
}
void SemanticAnalysis::exitIfStmt(CACTParser::IfStmtContext* ctx) {
    if (traverse_time == 0) {
        auto labels = if_labels.get(ctx);
        ir.addIC(labels[0], OP::LABEL, VOID, VOID, 100, NO_GLO, VOID);
    }
}

void SemanticAnalysis::enterIfElseStmt(CACTParser::IfElseStmtContext* ctx) {
    if (traverse_time == 0) {
        auto label1 = ir.gen_label();
        auto label2 = ir.gen_label();
        std::vector<std::string> label_set = {label1, label2};
        if_labels.put(ctx, label_set);
    }
}
void SemanticAnalysis::exitIfElseStmt(CACTParser::IfElseStmtContext* ctx) {
    if (traverse_time == 0) {
        auto labels = if_labels.get(ctx);
        ir.addIC(labels[1], OP::LABEL, VOID, VOID, 100, NO_GLO, VOID);
    }
}

void SemanticAnalysis::enterElseStmt(CACTParser::ElseStmtContext* ctx) {
    if (traverse_time == 0) {
        auto labels = if_labels.get(ctx->parent);
        ir.addIC(labels[1], OP::GOTO, VOID, VOID, 100, NO_GLO, VOID);
        ir.addIC(labels[0], OP::LABEL, VOID, VOID, 100, NO_GLO, VOID);
    }
}
void SemanticAnalysis::exitElseStmt(CACTParser::ElseStmtContext* ctx) {}

void SemanticAnalysis::enterWhileStmt(CACTParser::WhileStmtContext* ctx) {
    if (traverse_time == 0) {
        auto label_begin = ir.gen_label();
        auto label_end = ir.gen_label();
        std::vector<std::string> label_set = {label_begin, label_end};
        while_labels.put(ctx, label_set);
        label_stack.push_back(label_begin);
        label_stack.push_back(label_end);
        ir.addIC(label_begin, OP::LABEL, VOID, VOID, 100, NO_GLO, VOID);
    }
}
void SemanticAnalysis::exitWhileStmt(CACTParser::WhileStmtContext* ctx) {
    if (traverse_time == 0) {
        cout << "[DEBUG] [A] out while stmt"
             << "\n";
        auto labels = while_labels.get(ctx);
        ir.addIC(labels[0], OP::GOTO, VOID, VOID, 100, NO_GLO, VOID);
        ir.addIC(labels[1], OP::LABEL, VOID, VOID, 100, NO_GLO, VOID);
        label_stack.pop_back();
        label_stack.pop_back();
    }
}

void SemanticAnalysis::enterBreakStmt(CACTParser::BreakStmtContext* ctx) {}
void SemanticAnalysis::exitBreakStmt(CACTParser::BreakStmtContext* ctx) {
    if (traverse_time == 0) {
        auto index = label_stack.size();
        auto label = label_stack[index - 1];
        ir.addIC(label, OP::GOTO, VOID, VOID, 100, NO_GLO, VOID);
    }
}

void SemanticAnalysis::enterContinueStmt(CACTParser::ContinueStmtContext* ctx) {}
void SemanticAnalysis::exitContinueStmt(CACTParser::ContinueStmtContext* ctx) {
    if (traverse_time == 0) {
        auto index = label_stack.size();
        auto label = label_stack[index - 2];
        ir.addIC(label, OP::GOTO, VOID, VOID, 100, NO_GLO, VOID);
    }
}

// Condition
void SemanticAnalysis::enterCond(CACTParser::CondContext* ctx) {}
void SemanticAnalysis::exitCond(CACTParser::CondContext* ctx) {
    if (traverse_time == 0) {
        cout << "[DEBUG] [A] in  Cond"
             << "\n";
        ctx->cls = ctx->lOrExp()->cls;
        ctx->name = ctx->lOrExp()->name;
        if (ctx->cls != CLS_BOOLEAN) {
            throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                ": error: incompatible type in condition statement\n");
        }
        // cout<<"BBBBBBUUUUUGGGGGG"<<"\n";
        string flag = ctx->parent->children[0]->getText();  // if or while
        cout << flag << "\n";
        // cout<<"?????"<<"\n";
        Var* info = sym_table.lookup_var(ctx->name);
        // cout<<"?????"<<"\n";
        auto offset_str = sym_table.get_s0_offset(info);
        if (flag == "if") {
            auto labels = if_labels.get(ctx->parent);
            ir.addIC(labels[0], OP::BEQZ, info->name, offset_str, CLS_VOID, NO_GLO, VOID);
        } else if (flag == "while") {
            auto labels = while_labels.get(ctx->parent);
            ir.addIC(labels[1], OP::BEQZ, info->name, VOID, CLS_VOID, NO_GLO, VOID);
        }
        cout << "[DEBUG] [A] in  Cond done"
             << "\n";
    }
}

// Expression
void SemanticAnalysis::enterAssignStmt(CACTParser::AssignStmtContext* ctx) {}
void SemanticAnalysis::exitAssignStmt(CACTParser::AssignStmtContext* ctx) {
    if (traverse_time == 0) {
        bool isElemwise = false;
        bool isArray = false;
        string lVal_name = ctx->lVal()->name;
        string index_name;
        cout << "[DEBUG] [A] out assignstmt " << endl;
        int line = ctx->getStart()->getLine();
        // lval is Ident '[' exp ']'        ( Array )
        if (ctx->lVal()->exp() != nullptr) {
            cout << "lval is array elem\n";
            index_name = ctx->lVal()->exp()->name;
            Var* index_info = sym_table.lookup_var(index_name);
            if (index_info->cls != CLS_INT)
                throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                    ": error: index has wrong class\n");
            isArray = true;
        }
        // check lVal if declared
        Var* lVar_info = sym_table.lookup_var(lVal_name);
        if (lVar_info == nullptr) {
            throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                ": error: '" + lVal_name + "' undeclared\n");
        }

        // check exp if declared
        string rval_name = ctx->exp()->name;
        Var* rval_var_info = sym_table.lookup_var(rval_name);
        cout << "\trval_name: " + rval_name << "\n";
        cout << "\trval_type: " << rval_var_info->type << "\n";
        if (rval_var_info == nullptr) {
            throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                ": error: '" + lVal_name + "' undeclared (expession wrong)\n");
        }
        // type examination
        if (rval_var_info->cls != lVar_info->cls)
            throw runtime_error("line " + to_string(ctx->getStart()->getLine()) + ": error: incompatible types when assigning\n");

        if (lVar_info->type == TP_ARRAY &&
            (rval_var_info->type == TP_ARRAY || rval_var_info->type == TP_CONST_ARRAY)) {
            isElemwise = true;
            if (lVar_info->length != rval_var_info->length)
                throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                    ": error: incompatible length in element wise assignment\n");
        }
        cout << "\tisElemwise: " << isElemwise << "\n";
        int var_cls = lVar_info->cls;
        int var_type = lVar_info->type;

        if (lVar_info->type == TP_CONST || lVar_info->type == TP_CONST_ARRAY) {
            throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                ": error: assignment of constant variable\n");
        }
        auto lhs_offset_str = sym_table.get_s0_offset(lVar_info);
        auto rhs_offset_str = sym_table.get_s0_offset(rval_var_info);
        if (!isArray && !isElemwise) {  // a = b
            ir.addIC(lVal_name, VAR_ASSIGN, rval_name, lhs_offset_str, var_cls, NO_GLO, VOID);
        } else if (isElemwise) {  // A = B (a[i] = b[i] for all i)
            if (lVar_info->length != rval_var_info->length)
                throw std::runtime_error(
                    "line " + std::to_string(ctx->getStart()->getLine()) +
                    ": error: incompatible length when assigning\n");
            int length = lVar_info->length;
            // A = B + C
            if (ctx->exp()->addExp()->addExp() != nullptr) {
                string B_name = ctx->exp()->addExp()->addExp()->name;
                string C_name = ctx->exp()->addExp()->mulExp()->name;
                for (int i = 0; i < length; i++) {
                    ir.addIC(lVal_name, OP::ARRAY_ASSIGN_ELEMWISE_ADD,
                             B_name, C_name, var_cls, NO_GLO, to_string(i));
                }
            } else if (ctx->exp()->addExp()->mulExp()->mulExp() != nullptr) {
                string B_name = ctx->exp()->addExp()->mulExp()->mulExp()->name;
                string C_name = ctx->exp()->addExp()->mulExp()->unaryExp()->name;
                for (int i = 0; i < length; i++) {
                    ir.addIC(lVal_name, OP::ARRAY_ASSIGN_ELEMWISE_MUL,
                             B_name, C_name, var_cls, NO_GLO, to_string(i));
                }
            } else {
                for (int i = 0; i < length; i++) {
                    ir.addIC(lVal_name, OP::ARRAY_ASSIGN_ELEMWISE,
                             rval_name, VOID, var_cls, NO_GLO, to_string(i));
                }
            }
        } else {  // a[i] = b
            auto array_name = ctx->lVal()->Ident()->getText();
            auto array_info = sym_table.lookup_var(array_name);
            auto index_var = sym_table.lookup_var(index_name);

            ir.addIC(array_name, OP::ARRAY_ASSIGN, rval_name, index_name, var_cls, NO_GLO, VOID);
        }
    }
}

void SemanticAnalysis::enterPrimary(CACTParser::PrimaryContext* ctx) {}
void SemanticAnalysis::exitPrimary(CACTParser::PrimaryContext* ctx) {
    if (traverse_time == 0) {
        cout << "[DEBUG] [A] out primary\n";
        // ( exp )
        if (ctx->primaryExp()->exp() != nullptr) {
            ctx->cls = ctx->primaryExp()->exp()->cls;
            ctx->name = ctx->primaryExp()->exp()->name;
        }
        // lVal
        else if (ctx->primaryExp()->lVal() != nullptr) {
            ctx->cls = ctx->primaryExp()->lVal()->cls;
            ctx->name = ctx->primaryExp()->lVal()->name;
        }
        // bool
        else if (ctx->getText() == "true" || ctx->getText() == "false") {
            string temp = sym_table.gen_temp_var(ctx->getStart()->getLine(), CLS_BOOLEAN, TP_CONST);
            ctx->cls = CLS_BOOLEAN;
            ctx->name = temp;
            Var* tmp_info = sym_table.lookup_var(temp);
            ir.addIC(ctx->name, TEMP_ASSIGN_DIRECT, ctx->getText(), VOID, tmp_info->cls, NO_GLO, VOID);

        }
        // number
        else {
            int num_cls = ctx->primaryExp()->getStart()->getType();
            string literal_val = ctx->getText();
            string value_str;
            int int_val;
            float float_val;
            double double_val;

            if (num_cls == CACTLexer::IntConst) {
                ctx->cls = CLS_INT;
                ctx->name = sym_table.gen_temp_var(ctx->getStart()->getLine(), CLS_INT, TP_CONST);
                int_val = stoi(literal_val, 0, getIntBase(literal_val));
                value_str = to_string(int_val);
            } else if (num_cls == CACTLexer::FloatConst) {
                ctx->cls = CLS_FLOAT;
                ctx->name = sym_table.gen_temp_var(ctx->getStart()->getLine(), CLS_FLOAT, TP_CONST);
                float_val = stof(literal_val.substr(0, literal_val.length() - 1));
                value_str = to_string(float_val);
            } else if (num_cls == CACTLexer::DoubleConst) {
                ctx->cls = CLS_DOUBLE;
                ctx->name = sym_table.gen_temp_var(ctx->getStart()->getLine(), CLS_DOUBLE, TP_CONST);
                double_val = stod(literal_val);
                value_str = to_string(double_val);
            }
            Var* tmp_info = sym_table.lookup_var(ctx->name);
            ir.addIC(ctx->name, TEMP_ASSIGN_DIRECT, value_str, ctx->getText(), tmp_info->cls, NO_GLO, VOID);
        }
    }
}

void SemanticAnalysis::enterUnary(CACTParser::UnaryContext* ctx) {
    if (traverse_time == 0) {
        cout << "[DEBUG] [A] in  Unary\n";
    }
}
void SemanticAnalysis::exitUnary(CACTParser::UnaryContext* ctx) {
    if (traverse_time == 0) {
        cout << "[DEBUG] [A] out Unary \n";
        if (ctx->unaryOp()->getText() == "!") {
            if (ctx->unaryExp()->cls != CLS_BOOLEAN)
                throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                    ": error: wrong type argument to unary exclamation mark\n");
            ctx->cls = CLS_BOOLEAN;
            ctx->name = sym_table.gen_temp_var(ctx->getStart()->getLine(), CLS_BOOLEAN);
            Var* tmp_info = sym_table.lookup_var(ctx->name);
            string child_name = ctx->unaryExp()->name;
            Var* child_info = sym_table.lookup_var(child_name);
            ir.addIC(ctx->name, TEMP_ASSIGN_1_NOT, child_name, VOID, ctx->cls, NO_GLO, VOID);
        } else if (ctx->unaryOp()->getText() == "+") {
            if (ctx->cls == CLS_BOOLEAN)
                throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                    ": error: wrong type argument to unary '+' mark\n");
            ctx->cls = ctx->unaryExp()->cls;
            ctx->name = ctx->unaryExp()->name;
        } else if (ctx->unaryOp()->getText() == "-") {
            if (ctx->cls == CLS_BOOLEAN)
                throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                    ": error: wrong type argument to unary '-' mark\n");
            ctx->cls = ctx->unaryExp()->cls;
            ctx->name = sym_table.gen_temp_var(ctx->getStart()->getLine(), ctx->cls);
            Var* tmp_info = sym_table.lookup_var(ctx->name);
            string child_name = ctx->unaryExp()->name;
            Var* child_info = sym_table.lookup_var(child_name);
            ir.addIC(ctx->name, TEMP_ASSIGN_1_NEG, child_name, VOID, ctx->cls, NO_GLO, VOID);
        }
    }
}

void SemanticAnalysis::enterMulExp(CACTParser::MulExpContext* ctx) {
    if (traverse_time == 0) {
        cout << "[DEBUG] [A] in  mul exp\n";
    }
}
void SemanticAnalysis::exitMulExp(CACTParser::MulExpContext* ctx) {
    if (traverse_time == 0) {
        cout << "[DEBUG] [A] out mul exp\n";
        // unaryexp
        if (!ctx->mulExp()) {
            ctx->cls = ctx->unaryExp()->cls;
            ctx->name = (ctx->cls == CLS_VOID) ? "NULL" : ctx->unaryExp()->name;
        }
        // mulExp ('*' | '/' | '%') unaryExp
        else {
            if (ctx->mulExp()->cls != ctx->unaryExp()->cls)  // class examination
                throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                    ": error: different type in mulExp\n");
            auto operand1 = ctx->mulExp()->name;
            auto operand2 = ctx->unaryExp()->name;
            Var* op1_info = sym_table.lookup_var(operand1);
            Var* op2_info = sym_table.lookup_var(operand2);
            string op = ctx->children[1]->getText();
            string ic_op;
            if ("*" == op)
                ic_op = "_mul";
            if ("/" == op)
                ic_op = "_div";
            if ("%" == op)
                ic_op = "_mod";
            // element wise op
            if ((op1_info->type == TP_ARRAY || op1_info->type == TP_CONST_ARRAY) &&
                (op2_info->type == TP_ARRAY || op2_info->type == TP_CONST_ARRAY)) {
                if (op1_info->length != op2_info->length) {
                    throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                        ": error: wrong size to element wise operation\n");
                }
                auto res = sym_table.gen_temp_array(ctx->getStart()->getLine(), op1_info->cls, op1_info->length);
                ctx->elemwise = true;
                ctx->cls = op1_info->cls;
                ctx->name = res;
                Var* res_info = sym_table.lookup_var(res);
                int length = op1_info->length;
                if (ctx->parent->children.size() != 1) {
                    for (int i = 0; i < length; i++) {
                        ir.addIC(ctx->name, OP::ARRAY_ASSIGN_ELEMWISE + ic_op,
                                 operand1, operand2, ctx->cls, NO_GLO, to_string(i));
                    }
                }
            }
            // normal op
            else {
                if (op1_info->type == TP_ARRAY ||
                    op1_info->type == TP_CONST_ARRAY ||
                    op2_info->type == TP_ARRAY ||
                    op2_info->type == TP_CONST_ARRAY) {
                    throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                        ": error: invalid operands in mulExp\n");
                } else if (op1_info->cls == CLS_BOOLEAN) {
                    throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                        ": error: invalid operands in mulExp\n");
                }
                auto res = sym_table.gen_temp_var(ctx->getStart()->getLine(), op1_info->cls);
                ctx->elemwise = false;
                ctx->cls = op1_info->cls;
                ctx->name = res;
                Var* res_info = sym_table.lookup_var(res);
                ir.addIC(ctx->name, TEMP_ASSIGN_2 + ic_op, operand1, operand2, ctx->cls, NO_GLO, VOID);
            }
        }
        cout << "[DEBUG] [A] out mul exp done\n";
    }
}

void SemanticAnalysis::enterAddExp(CACTParser::AddExpContext* ctx) {
    if (traverse_time == 0) {
        cout << "[DEBUG] [A] in add exp" << endl;
    }
}
void SemanticAnalysis::exitAddExp(CACTParser::AddExpContext* ctx) {
    if (traverse_time == 0) {
        // mulexp
        cout << "[DEBUG] [A] out add exp" << endl;

        if (!ctx->addExp()) {
            ctx->cls = ctx->mulExp()->cls;
            ctx->name = ctx->mulExp()->name;
            ctx->elemwise = ctx->mulExp()->elemwise;
            cout << "name: " + ctx->name << endl;

        }
        // addExp ('+' | '-') mulExp
        else {
            if (ctx->addExp()->cls != ctx->mulExp()->cls)  // class examination
                throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                    ": error: wrong type to binary + or -\n");
            auto operand1 = ctx->addExp()->name;
            auto operand2 = ctx->mulExp()->name;
            Var* op1_info = sym_table.lookup_var(operand1);
            Var* op2_info = sym_table.lookup_var(operand2);

            // element wise op
            if ((op1_info->type == TP_ARRAY || op1_info->type == TP_CONST_ARRAY) &&
                (op2_info->type == TP_ARRAY || op2_info->type == TP_CONST_ARRAY)) {
                if (op1_info->length != op2_info->length) {
                    throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                        ": error: wrong size to element wise operation\n");
                }
                auto res = sym_table.gen_temp_array(ctx->getStart()->getLine(), op1_info->cls, op1_info->length);
                ctx->elemwise = true;
                ctx->cls = op1_info->cls;
                ctx->name = res;

                Var* res_info = sym_table.lookup_var(res);
                int length = op1_info->length;
                if (ctx->parent->children.size() != 1) {
                    for (int i = 0; i < length; i++) {
                        ir.addIC(ctx->name, OP::ARRAY_ASSIGN_ELEMWISE_ADD,
                                 operand1, operand2, ctx->cls, NO_GLO, to_string(i));
                    }
                }
            }
            // normal op
            else {
                if (op1_info->type == TP_ARRAY ||
                    op1_info->type == TP_CONST_ARRAY ||
                    op2_info->type == TP_ARRAY ||
                    op2_info->type == TP_CONST_ARRAY) {
                    throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                        ": error: invalid operands to binary + or -\n");
                } else if (op1_info->cls == CLS_BOOLEAN) {
                    throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                        ": error: invalid operands to binary + or -\n");
                }
                auto res = sym_table.gen_temp_var(ctx->getStart()->getLine(), op1_info->cls);
                ctx->elemwise = false;
                ctx->cls = op1_info->cls;
                ctx->name = res;
                Var* res_info = sym_table.lookup_var(res);
                ir.addIC(ctx->name, TEMP_ASSIGN_2_ADD, operand1, operand2, ctx->cls, NO_GLO, VOID);
            }
        }
        cout << "[DEBUG] [A] out add exp done" << endl;
    }
}

void SemanticAnalysis::enterExp(CACTParser::ExpContext* ctx) {
    if (traverse_time == 0) {
        cout << "[DEBUG] [A] in  Exp"
             << "\n";
    }
}
void SemanticAnalysis::exitExp(CACTParser::ExpContext* ctx) {
    if (traverse_time == 0) {
        // addExp
        cout << "[DEBUG] [A] out Exp"
             << "\n";
        if (ctx->addExp()) {
            ctx->cls = ctx->addExp()->cls;
            ctx->name = ctx->addExp()->name;
            cout << "\tadd EXP name: " + ctx->name << endl;
        }
        // BoolConst
        if (ctx->BoolConst()) {
            ctx->cls = CLS_BOOLEAN;
        }
    }
}

void SemanticAnalysis::enterLVal(CACTParser::LValContext* ctx) {}
void SemanticAnalysis::exitLVal(CACTParser::LValContext* ctx) {
    if (traverse_time == 0) {
        // Ident
        if (ctx->exp() == nullptr) {
            string var_name = ctx->Ident()->getText();
            Var* var_info = sym_table.lookup_var(var_name);
            if (!var_info)
                throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                    ": error: '" + var_name + "' undeclared (first use in this function)\n");
            ctx->cls = var_info->cls;
            ctx->name = ctx->Ident()->getText();
        }
        // Ident[exp]
        else {
            string array_name = ctx->Ident()->getText();
            Var* array_info = sym_table.lookup_var(array_name);
            if (!array_info)
                throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                    ": error: '" + array_name + "' undeclared (first use in this function)\n");
            if (!(array_info->type == TP_ARRAY || array_info->type == TP_CONST_ARRAY))
                throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                    ": error: subscripted value is not array");

            ctx->cls = array_info->cls;
            auto exp_name = ctx->exp()->name;
            Var* exp_info = sym_table.lookup_var(exp_name);
            if (exp_info->cls != CLS_INT)
                throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                    ": error: array subscript is not an integer\n");
            string arrayelem = sym_table.gen_temp_var(ctx->getStart()->getLine(), ctx->cls, array_info->type);
            ctx->name = arrayelem;
            Var* tmp_info = sym_table.lookup_var(arrayelem);
            if (ctx->parent->children.size() == 1) {
                cout << "\texit LVAL without brother\n";
                ir.addIC(ctx->name, TEMP_ASSIGN_ARRAY_LVAL, array_name, exp_name, exp_info->cls, NO_GLO, VOID);
            }
        }
    }
}

void SemanticAnalysis::enterRelExp(CACTParser::RelExpContext* ctx) {
    if (traverse_time == 0) {
        cout << "[DEBUG] [A] in  Rel exp"
             << "\n";
    }
}
void SemanticAnalysis::exitRelExp(CACTParser::RelExpContext* ctx) {
    if (traverse_time == 0) {
        cout << "[DEBUG] [A] out Rel exp"
             << "\n";
        // boolconst
        if (ctx->BoolConst()) {
            auto res = sym_table.gen_temp_var(ctx->getStart()->getLine(), CLS_BOOLEAN);
            ctx->cls = CLS_BOOLEAN;
            ctx->name = res;
            ctx->value = ctx->BoolConst()->getText() == "true" ? 1 : 0;
            Var* res_info = sym_table.lookup_var(res);
        }
        // relExp ('<' | '>' | '<=' | '>=') addExp
        else if (ctx->relExp()) {
            string operand1 = ctx->relExp()->name;
            string operand2 = ctx->addExp()->name;
            Var* op1_info = sym_table.lookup_var(operand1);
            Var* op2_info = sym_table.lookup_var(operand2);
            std::cout << "FFFFFFFF" << op1_info->cls << "\n";
            // to check!!
            if (op1_info->cls != op2_info->cls || op1_info->cls == CLS_BOOLEAN) {
                throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                    ": error: wrong type to comparison\n");
            }
            if (op1_info->type == TP_ARRAY ||
                op1_info->type == TP_CONST_ARRAY ||
                op2_info->type == TP_ARRAY ||
                op2_info->type == TP_CONST_ARRAY) {
                throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                    ": error: invalid operands to comparison\n");
            }

            auto res = sym_table.gen_temp_var(ctx->getStart()->getLine(), CLS_BOOLEAN);
            ctx->cls = CLS_BOOLEAN;
            ctx->name = res;

            Var* res_info = sym_table.lookup_var(res);

            string base = TEMP_ASSIGN_REL;
            ir.addIC(ctx->name, base + "_" + ctx->children[1]->getText(),
                     operand1, operand2, op1_info->cls, NO_GLO, VOID);
        }
        // addExp
        else {
            ctx->cls = ctx->addExp()->cls;
            ctx->name = ctx->addExp()->name;
        }
        cout << "[DEBUG] [A] out Rel exp done"
             << "\n";
    }
}

void SemanticAnalysis::enterEqExp(CACTParser::EqExpContext* ctx) {}
void SemanticAnalysis::exitEqExp(CACTParser::EqExpContext* ctx) {
    if (traverse_time == 0) {
        // eqExp ('==' | '!=') relExp
        if (ctx->eqExp()) {
            string operand1 = ctx->eqExp()->name;
            string operand2 = ctx->relExp()->name;
            Var* op1_info = sym_table.lookup_var(operand1);
            Var* op2_info = sym_table.lookup_var(operand2);

            if (op1_info->cls != op2_info->cls) {
                throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                    ": error: wrong type to comparison\n");
            }
            if (op1_info->type == TP_ARRAY ||
                op1_info->type == TP_CONST_ARRAY ||
                op2_info->type == TP_ARRAY ||
                op2_info->type == TP_CONST_ARRAY) {
                throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                    ": error: invalid operands to comparison\n");
            }

            auto res = sym_table.gen_temp_var(ctx->getStart()->getLine(), CLS_BOOLEAN);
            ctx->cls = CLS_BOOLEAN;
            ctx->name = res;

            Var* res_info = sym_table.lookup_var(res);
            string base = TEMP_ASSIGN_REL;
            ir.addIC(ctx->name, base + "_" + ctx->children[1]->getText(),
                     operand1, operand2, ctx->cls, NO_GLO, VOID);
        }
        // relExp
        else {
            ctx->cls = ctx->relExp()->cls;
            ctx->name = ctx->relExp()->name;
        }
    }
}

void SemanticAnalysis::enterLAndExp(CACTParser::LAndExpContext* ctx) {}
void SemanticAnalysis::exitLAndExp(CACTParser::LAndExpContext* ctx) {
    if (traverse_time == 0) {
        // lAndExp '&&' eqExp
        if (ctx->lAndExp()) {
            string operand1 = ctx->lAndExp()->name;
            string operand2 = ctx->eqExp()->name;
            Var* op1_info = sym_table.lookup_var(operand1);
            Var* op2_info = sym_table.lookup_var(operand2);

            if (op1_info->cls != op2_info->cls) {
                throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                    ": error: wrong type to &7\n");
            }
            if (op1_info->type == TP_ARRAY ||
                op1_info->type == TP_CONST_ARRAY ||
                op2_info->type == TP_ARRAY ||
                op2_info->type == TP_CONST_ARRAY) {
                throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                    ": error: invalid operands to &&\n");
            }

            auto res = sym_table.gen_temp_var(ctx->getStart()->getLine(), CLS_BOOLEAN);
            ctx->cls = CLS_BOOLEAN;
            ctx->name = res;

            Var* res_info = sym_table.lookup_var(res);

            string base = TEMP_ASSIGN_LOGIC;
            ir.addIC(ctx->name, base + "_" + ctx->children[1]->getText(),
                     operand1, operand2, ctx->cls, NO_GLO, VOID);
        }
        // eqExp
        else {
            ctx->cls = ctx->eqExp()->cls;
            ctx->name = ctx->eqExp()->name;
        }
    }
}

void SemanticAnalysis::enterLOrExp(CACTParser::LOrExpContext* ctx) {
    if (traverse_time == 0) {
        cout << "[DEBUG] [A] in  LOR exp"
             << "\n";
    }
}
void SemanticAnalysis::exitLOrExp(CACTParser::LOrExpContext* ctx) {
    if (traverse_time == 0) {
        cout << "[DEBUG] [A] out LOR exp"
             << "\n";
        // lOrExp '||' lAndExp
        if (ctx->lOrExp()) {
            string operand1 = ctx->lOrExp()->name;
            string operand2 = ctx->lAndExp()->name;
            Var* op1_info = sym_table.lookup_var(operand1);
            Var* op2_info = sym_table.lookup_var(operand2);

            if (op1_info->cls != op2_info->cls) {
                throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                    ": error: wrong type to ||\n");
            }
            if (op1_info->type == TP_ARRAY ||
                op1_info->type == TP_CONST_ARRAY ||
                op2_info->type == TP_ARRAY ||
                op2_info->type == TP_CONST_ARRAY) {
                throw runtime_error("line " + to_string(ctx->getStart()->getLine()) +
                                    ": error: invalid operands to ||\n");
            }

            auto res = sym_table.gen_temp_var(ctx->getStart()->getLine(), CLS_BOOLEAN);
            ctx->cls = CLS_BOOLEAN;
            ctx->name = res;

            Var* res_info = sym_table.lookup_var(res);

            string base = TEMP_ASSIGN_LOGIC;
            ir.addIC(ctx->name, base + "_" + ctx->children[1]->getText(),
                     operand1, operand2, ctx->cls, NO_GLO, VOID);
        }
        // lAndExp
        else {
            ctx->cls = ctx->lAndExp()->cls;
            ctx->name = ctx->lAndExp()->name;
        }
        cout << "[DEBUG] [A] out LOR exp done"
             << "\n";
    }
}
