#ifndef IR_H
#define IR_H

#include "symbolTable.h"
#define CA constexpr auto

#define ENTER_BLOCK 1
#define EXIT_BLOCK 0

typedef struct IRCode {
    std::string rst;
    std::string op;
    std::string arg1;
    std::string arg2;
    std::string backup_0;
    int cls;
} IRC_t;

class IR {
   public:
    std::vector<IRC_t> ir_codes;
    std::vector<IRC_t> ir_codes_global;
    std::map<std::string, IRC_t> labels_and_codes;
    int label_cnt;

   public:
    IR() {
        label_cnt = 0;
    }

    std::string gen_label();

    void addIC(std::string rst, std::string op, std::string arg1, std::string arg2, int cls, int global, std::string backup);
    // void addIC(std::string func_name, std::string op, std::string cls_of_parameter, int ret_cls, int global);
    void printIC();
    void traverse_for_redundant_label();
    void traverse_cur_block_for_dag_optimization(int enter_block);
};

// IR op
namespace OP {
CA VOID = "";

CA ALLOCA = "alloca";
CA ALLOCA_ARRAY = "alloca_array";

CA ARRAY_ASSIGN_INIT = "array_init";
CA ARRAY_ASSIGN_ELEMWISE = "array_assign_elemwise";
CA ARRAY_ASSIGN_ELEMWISE_MUL = "array_assign_elemwise_mul";
CA ARRAY_ASSIGN_ELEMWISE_ADD = "array_assign_elemwise_add";
CA ARRAY_ASSIGN_ELEMWISE_DIV = "array_assign_elemwise_div";
CA ARRAY_ASSIGN_ELEMWISE_MOD = "array_assign_elemwise_mod";

CA BLOCK_BEGIN = "block_begin";
CA BLOCK_END = "block_end";

CA VAR_ASSIGN = "var_assign";
CA ARRAY_ASSIGN = "assign_array";

CA TEMP_ASSIGN = "temp_assign";						// not true op
CA TEMP_ASSIGN_1 = "temp_assign_1";					// not true op
CA TEMP_ASSIGN_2 = "temp_assign_2";					// not true op
CA TEMP_ASSIGN_DIRECT = "temp_assign_direct";

CA TEMP_ASSIGN_1_NOT = "temp_assign_1_not";
CA TEMP_ASSIGN_1_NEG = "temp_assign_1_neg";

CA TEMP_ASSIGN_LOGIC = "temp_assign_logic";		// length is 17
CA TEMP_ASSIGN_LOGIC_AND = "temp_assign_logic_and";
CA TEMP_ASSIGN_LOGIC_OR = "temp_assign_logic_or";

CA TEMP_ASSIGN_2_ADD = "temp_assign_2_add";
CA TEMP_ASSIGN_2_SUB = "temp_assign_2_sub";
CA TEMP_ASSIGN_2_MUL = "temp_assign_2_mul";
CA TEMP_ASSIGN_2_DIV = "temp_assign_2_div";
CA TEMP_ASSIGN_2_MOD = "temp_assign_2_mod";

CA TEMP_ASSIGN_REL = "temp_assign_rel";
CA TEMP_ASSIGN_REL_LT = "temp_assign_rel_<";
CA TEMP_ASSIGN_REL_LTE = "temp_assign_rel_<=";
CA TEMP_ASSIGN_REL_GT = "temp_assign_rel_>";
CA TEMP_ASSIGN_REL_GTE = "temp_assign_rel_>=";
CA TEMP_ASSIGN_REL_EQ = "temp_assign_rel_==";
CA TEMP_ASSIGN_REL_NEQ = "temp_assign_rel_!=";
CA TEMP_ASSIGN_ARRAY_LVAL = "temp_assign_array_lval";

CA STORE_PARAM = "store_param";
CA STORE = "store";
CA STORE_VAL = "store_val";

// 函数
CA FUNC_BEGIN = "func_begin";
CA FUNC_END = "func_end";
CA CALL = "call";
CA CALL_ASSIGN = "call_assign";
CA CALL_STORE_RESULT = "call_store";
CA RET = "ret";
CA RET_VAL = "ret_val";

// 跳转
CA LABEL = "label";
CA GOTO = "goto";
CA BEQZ = "beqz";

// 全局变量
CA GLOBAL_ASSIGN = "global_assign";
CA GLOBAL_ARRAY = "global_array";
CA GLOBAL_ARRAY_ASSIGN = "global_array_assign";
}  // namespace OP

std::string macro_to_string(int cls);
std::string char_to_string(char cls);

#endif