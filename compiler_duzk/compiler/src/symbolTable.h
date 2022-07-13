#ifndef SYMTABLE_H
#define SYMTABLE_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <string>
#include <stack>
#include <array>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <iomanip>
// classes
enum{
    CLS_INT,
    CLS_BOOLEAN,
    CLS_FLOAT,
    CLS_DOUBLE,
    CLS_VOID
};
// types
enum{
    TP_CONST,
    TP_VAR,
    TP_CONST_ARRAY,
    TP_ARRAY,
    TP_PARAM
};

struct Var{
    int cls;                // class
    int type;               // type
    int length;             // 对于数组变量表示长度，对于函数参数表示第几个。
    int line;               // 行号
    int global = 0;;        // 全局变量标志
	int offset = 0;         // 相对s0寄存器的偏移值
    int reg_idx = 0;            // 1-64
    bool in_memory = false;         // whether in memory
    bool is_using = true;
    std::string name;
};
struct BlockTable{
    int line;                                       // line num
    std::map<int, struct BlockTable*> sub_blocks;   // child block
    std::map<std::string, Var> local_symbols;       // local symbols
};
struct Func{
    int cls;                // class
    int param_num = 0;          // number of parameter
    int line;               // line number
    int stack_size = 0;     // allocated stack size
    struct BlockTable func_block;
    std::string name;
};
class SymbolTable{
public:
    std::map<std::string, Var> global_symbols;  // symbols for global variable
    std::map<std::string, Func> func_symbols;   // symbols for functions
    std::vector<BlockTable*> block_s;        // stack for blocks
    std::string cur_func;                        // current function
    int stack_offset;                            // stack offset value
    int temp_var;
    int temp_in_func;
public:
    SymbolTable(){
        stack_offset = 0;
        temp_var = 0;
        cur_func = "$";
        block_s.push_back(nullptr);
    }
    
    Var* lookup_var(const std::string & name);          // look up variable
    Func* lookup_func(const std::string & func_name);   // look up funtion
    Var* lookup_param(Func& func, int para_index);      // look up parameter in function declaration

    void addSymbol(std::string name, int cls, int type, int length, int line);
    void addFunc(std::string name, int return_class, int param_num, int line);
    void addBlock(int line);

    std::string gen_temp_var(int lc, int cls, int type = TP_VAR);
    std::string gen_temp_array(int lc, int cls, int size);
    std::string get_s0_offset(Var *info);

    void printSymbol(std::ofstream & o);
};
std::string class_to_string(int cls);

#endif