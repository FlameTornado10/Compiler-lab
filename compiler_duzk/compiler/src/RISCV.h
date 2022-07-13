/*
什么：需求源于本能，做出选择源于本能。
需要干点啥呢
生成汇编！
怎么生成？
    什么时候生成
        enter block
        exit block
    以哪种方式生成
        遍历中间代码，分配寄存器
RISCV CODE:
getReg()
*/
#ifndef RISCV_H
#define RISCV_H
#include "IR.h"

using namespace std;

typedef struct RVCode {
    string rst;
    string op;
    string arg1;
    string arg2;
    int cls;
} RVC_t;

namespace RISCV_OP {
// li
CA ASM_LI = "li";

// Call
CA ASM_CALL = "call";
CA ASM_RET = "ret";
// goto label
CA ASM_GOTO = "goto";
CA ASM_LABEL = "label";
CA ASM_BEQZ = "beqz";
CA ASM_FUNCBEGIN = "func_begin";
CA ASM_FUNCEND = "func_end";
// lui + addi
CA ASM_LA = "la";
// store
CA STORE_INT = "sw";
CA STORE_LONG = "sd";
CA STORE_BOOL = "sw";
CA STORE_FLOAT = "fsw";
CA STORE_DOUBLE = "fsd";
// load
CA LOAD_INT = "lw";
CA LOAD_LONG = "ld";
CA LOAD_BOOL = "lw";
CA LOAD_FLOAT = "flw";
CA LOAD_DOUBLE = "fld";
// Arithmetic
CA ASM_ADD_64 = "add";
CA ASM_ADD_64_IMM = "addi";
CA ASM_ADD_32 = "addw";
CA ASM_ADD_32_IMM = "addiw";
CA ASM_ADD_INT = "addw";
CA ASM_ADD_FLT = "fadd.s";
CA ASM_ADD_DBL = "fadd.d";

CA ASM_SUB_64 = "sub";
CA ASM_SUB_64_IMM = "subi";
CA ASM_SUB_32 = "subw";
CA ASM_SUB_32_IMM = "subiw";
CA ASM_SUB_INT = "subw";
CA ASM_SUB_FLT = "fsub.s";
CA ASM_SUB_DBL = "fsub.d";

CA ASM_MUL_64 =   "mul";
CA ASM_MUL_32 =   "mulw";
CA ASM_MUL_INT =  "mulw";
CA ASM_MUL_FLT = "fmul.s";
CA ASM_MUL_DBL = "fmul.d";

CA ASM_DIV_64 =   "div";
CA ASM_DIV_32 =   "divw";
CA ASM_DIV_INT =  "divw";
CA ASM_DIV_FLT = "fdiv.s";
CA ASM_DIV_DBL = "fdiv.d";

CA ASM_MOD_64 =   "mod";
CA ASM_MOD_32 =   "modw";
CA ASM_MOD_INT =  "modw";
CA ASM_MOD_FLT = "fmod.s";
CA ASM_MOD_DBL = "fmod.d";

CA ASM_SLL_IW_2 = "slliw";
CA ASM_SLL_IW_3 = "slliw";
CA ASM_SEQZ = "asm_seqz";
CA ASM_NEG_INT = "asm_neg_int";
CA ASM_NEG_FLT = "asm_neg_flt";
CA ASM_NEG_DBL = "asm_neg_dbl";
CA ASM_AND = "asm_and";
CA ASM_OR = "asm_or";
CA ASM_LT = "asm_lt";
CA ASM_LTE = "asm_lte";
CA ASM_GT = "asm_gt";
CA ASM_GTE = "asm_gte";
CA ASM_EQ = "asm_==";
CA ASM_NE = "asm_!=";
CA ASM_MOVE_INT = "asm_mv_int";
CA ASM_MOVE_FLT = "asm_mv_flt";
CA ASM_MOVE_DBL = "asm_mv_dbl";

CA ASM_TEXT = "asm_text";
}  // namespace RISCV_OP

namespace REGS {
CA Ze = 0, ra = 1, sp = 2, gp = 3, tp = 4;
CA t0 = 5, t1 = 6, t2 = 7;
CA s0 = 8, s1 = 9;
CA a0 = 10, a1 = 11, a2 = 12, a3 = 13, a4 = 14, a5 = 15, a6 = 16, a7 = 17;
CA s2 = 18, s3 = 19, s4 = 20, s5 = 21, s6 = 22, s7 = 23, s8 = 24, s9 = 25, s10 = 26, s11 = 27;
CA t3 = 28, t4 = 29, t5 = 30, t6 = 31;

CA ft0 = 0 + 32, ft1 = 1 + 32, ft2 = 2 + 32, ft3 = 3 + 32, ft4 = 4 + 32, ft5 = 5 + 32, ft6 = 6 + 32, ft7 = 7 + 32;
CA fs0 = 8 + 32, fs1 = 9 + 32;
CA fa0 = 10 + 32, fa1 = 11 + 32, fa2 = 12 + 32, fa3 = 13 + 32, fa4 = 14 + 32, fa5 = 15 + 32, fa6 = 16 + 32, fa7 = 17 + 32;
CA fs2 = 18 + 32, fs3 = 19 + 32, fs4 = 20 + 32, fs5 = 21 + 32, fs6 = 22 + 32, fs7 = 23 + 32, fs8 = 24 + 32, fs9 = 25 + 32;
CA fs10 = 26 + 32, fs11 = 27 + 32;
CA ft8 = 28 + 32, ft9 = 29 + 32, ft10 = 30 + 32, ft11 = 31 + 32;
CA IntRegs = {a0, a1, a2, a3, a4, a5, a6, a7,
              s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11,
              t0, t1};  // t2, t3, t4, t5, t6 is saved
CA FltRegs = {fa0, fa1, fa2, fa3, fa4, fa5, fa6, fa7,
              fs1, fs2, fs3, fs4, fs5, fs6, fs7, fs8, fs9, fs10, fs11,
              fs0,
              ft0, ft1, ft2, ft3, ft4, ft5, ft6, ft7, ft8, ft9, ft10, ft11};
}  // namespace REGS

extern string reg_name[64];
using namespace REGS;
typedef struct {
    int offset;
    string name;
    Var* var_ptr;
} reg_info;
class RISCV {
   public:
    int flt_double_temp_count = 0;
    vector<RVC_t> rv_codes;
    vector<RVC_t> rv_codes_global;
    map<int, reg_info> regs_info;
    map<int, int> int_regs_pos;
    map<int, int> flt_regs_pos;
    vector<int> lru_vec_int_regs;
    vector<int> lru_vec_flt_regs;
    map<string, vector<int>> func_regs;
   public:
    RISCV() {
        for (auto a : IntRegs) {
            regs_info[a].offset = 0;
            regs_info[a].name = "";
        }
        for (auto a : FltRegs) {
            regs_info[a].offset = 0;
            regs_info[a].name = "";
        }
    }
    void RISCV_GEN(IR& ir, SymbolTable& st);
    void RISCV_GEN(IRC_t& ic, SymbolTable& st);
    void RISCV_GEN(string rst, string op, string arg1, string arg2, int cls);
    void RISCV_GEN_GLOBAL(string rst);
    int recycle(int cls_flag, Var* var, SymbolTable& st);
    void free_reg(int reg_id, int cls_flag, SymbolTable& st);
    int getReg(int cls, Var* var, SymbolTable& st);
    Var* getReg_specific(int cls, int reg_id, SymbolTable& st);
    int getReg_specific_var(int cls, int reg_id, SymbolTable& st, Var* var);
    void update_reg_info(int reg_id, int var_offset, string var_name, Var* var_ptr);
    void clear_cur_block(SymbolTable& st);
    void clear_func(SymbolTable &st);
    void finish_func_begin_end_in_RV(std::string func_name, SymbolTable &st);
    void printRC();
    // void RISCV_FuncBegin(IRC_t&);
    // void RISCV_FuncEnd(IRC_t&);
    // void RISCV_Call(IRC_t&);
    // void RISCV_Return(IRC_t&);
    // void RISCV_Label(IRC_t&);
    // void RISCV_Goto(IRC_t&);
    // void RISCV_Beqz(IRC_t&);

    // void RISCV_Arithmetic(IRC_t&);
    // void RISCV_Load(IRC_t&);
    // void RISCV_Store(IRC_t&);
    // void RISCV_Move(IRC_t&);
    // void RISCV_Li(IRC_t&);

    // void RISCV_READARRAY(IRC_t&);
    // void RISCV_SAVEARRAY(IRC_t&);
    // void RISCV_GLOBAL(IRC_t&);
    // void RISCV_GLOBAL_ARRAY(IRC_t&);
    // void RISCV_GLOBAL_ARRAY_ASSIGN(IRC_t&);
};

#endif