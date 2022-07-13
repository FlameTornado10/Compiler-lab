
#include "RISCV.h"

using namespace std;
using namespace OP;
using namespace REGS;
using namespace RISCV_OP;
#define NO_REG_ALLOC

string reg_name[64] = {
    "x0", "ra", "sp", "gp", "tp",
    "t0", "t1", "t2",
    "s0", "s1",
    "a0", "a1", "a2", "a3", "a4", "a5", "a6", "a7",
    "s2", "s3", "s4", "s5", "s6", "s7", "s8", "s9", "s10", "s11",
    "t3", "t4", "t5", "t6",

    "ft0", "ft1", "ft2", "ft3", "ft4", "ft5", "ft6", "ft7",
    "fs0", "fs1",
    "fa0", "fa1", "fa2", "fa3", "fa4", "fa5", "fa6", "fa7",
    "fs2", "fs3", "fs4", "fs5", "fs6", "fs7", "fs8", "fs9",
    "fs10", "fs11",
    "ft8", "ft9", "ft10", "ft11"};
string get_s0_offset(Var* info) {
    if (!info->global) {
        int offset_to_sp = info->offset + 16;  // ra:8 + sp:8
        std::string res = std::to_string(offset_to_sp);
        return res;
    } else {
        return (info->name) + ".g";
    }
}
string load_by_cls(int cls) {
    string rst;
    if (cls == CLS_INT || cls == CLS_BOOLEAN) {
        rst = LOAD_INT;
        return rst;
    } else if (cls == CLS_FLOAT) {
        rst = LOAD_FLOAT;
        return rst;
    } else if (cls == CLS_DOUBLE) {
        rst = LOAD_DOUBLE;
        return rst;
    } else {
        rst = LOAD_LONG;
        return rst;
    }
}
string store_by_cls(int cls) {
    string rst;
    if (cls == CLS_INT || cls == CLS_BOOLEAN) {
        rst = STORE_INT;
        return rst;
    } else if (cls == CLS_FLOAT) {
        rst = STORE_FLOAT;
        return rst;
    } else if (cls == CLS_DOUBLE) {
        rst = STORE_DOUBLE;
        return rst;
    } else {
        rst = STORE_LONG;
        return rst;
    }
}
string move_by_cls(int cls) {
    string rst;
    if (cls == CLS_INT || cls == CLS_BOOLEAN) {
        rst = ASM_MOVE_INT;
        return rst;
    } else if (cls == CLS_FLOAT) {
        rst = ASM_MOVE_FLT;
        return rst;
    } else if (cls == CLS_DOUBLE) {
        rst = ASM_MOVE_DBL;
        return rst;
    }
}
string sll_by_cls(int cls) {
    string rst;
    if (cls == CLS_INT || cls == CLS_BOOLEAN) {
        rst = ASM_SLL_IW_2;
        return rst;
    } else if (cls == CLS_FLOAT) {
        rst = ASM_SLL_IW_2;
        return rst;
    } else if (cls == CLS_DOUBLE) {
        rst = ASM_SLL_IW_3;
        return rst;
    }
}
int size_by_cls(int cls) {
    int rst;
    if (cls == CLS_INT || cls == CLS_BOOLEAN) {
        rst = 2;
        return rst;
    } else if (cls == CLS_FLOAT) {
        rst = 2;
        return rst;
    } else if (cls == CLS_DOUBLE) {
        rst = 3;
        return rst;
    }
}
// add one in lru vec tail
void lru_add_tail(std::map<int, int>& regs_pos, std::vector<int>& lru_vec, int i) {
    regs_pos[i] = lru_vec.size();
    lru_vec.push_back(i);
}
void update_lru(std::map<int, int>& regs_pos, std::vector<int>& lru_vec, int i) {
    int pos = regs_pos[i];
    int size = lru_vec.size();
    for (int id = pos; id <= size - 2; id++) {
        int reg_id = lru_vec[id + 1];
        lru_vec[id] = lru_vec[id + 1];
        regs_pos[reg_id] = id;
    }
    lru_vec[size - 1] = i;
    regs_pos[i] = size - 1;
}
// get the first one in lru vec
int release_from_list(std::map<int, int>& regs_pos, std::vector<int>& lru_vec) {
    int latest_recently_used = lru_vec[0];  // reg id
    regs_pos[latest_recently_used] = -1;
    lru_vec.erase(lru_vec.begin());
    // update the one released
    for (auto temp = regs_pos.begin(); temp != regs_pos.end(); temp++) {
        temp->second--;
    }
    lru_add_tail(regs_pos, lru_vec, latest_recently_used);
    return latest_recently_used;
}
void RISCV::RISCV_GEN(string rst, string op, string arg1, string arg2, int cls) {
    RVC_t t;
    t.rst = rst;
    t.op = op;
    t.arg1 = arg1;
    t.arg2 = arg2;
    t.cls = cls;
    this->rv_codes.push_back(t);
}
void RISCV::RISCV_GEN_GLOBAL(string rst) {
    RVC_t t;
    t.rst = rst;
    this->rv_codes_global.push_back(t);
}
// free one register by moving information in it to memory
void RISCV::free_reg(int reg_id, int cls, SymbolTable& st) {
    int var_offset = regs_info[reg_id].offset;
    string var_name = regs_info[reg_id].name;
    Var* origin;
    if (var_name.find("$") != std::string::npos) {
        regs_info[reg_id].offset = 0;
        regs_info[reg_id].name = "";
        return;
    }
    Var* cur_var = st.lookup_var(var_name);
    if (cur_var == nullptr) {  // original var not valid
        regs_info[reg_id].offset = 0;
        regs_info[reg_id].name = "";
        return;
    }
    // original one is not meaningless

    if (var_offset > 0) {
        string off_str = "-" + to_string(var_offset + 16) + "(s0)";
        // st reg, memory
        RISCV_GEN(off_str, store_by_cls(cls), reg_name[reg_id], VOID, cls);
    } else {  // Global vars' offsets are less than or equal to 0 (Zero)
        RISCV_GEN("t6", ASM_LA, var_name, VOID, 100);
        RISCV_GEN("0(t6)", store_by_cls(cls), reg_name[reg_id], VOID, cls);
    }
    regs_info[reg_id].offset = 0;
    regs_info[reg_id].name = "";
    regs_info[reg_id].var_ptr->reg_idx = 0;
    regs_info[reg_id].var_ptr->in_memory = true;
    return;
}
int ffl;
void RISCV::RISCV_GEN(IR& ir, SymbolTable& st) {
    int size = ir.ir_codes.size();
    ffl++;
    string op;
    auto a = ir.ir_codes.end() - 1;
    for (; a->op != FUNC_END && a->op != BLOCK_BEGIN && a->op != BLOCK_END && a != ir.ir_codes.begin();
         a--)
        ;
    if (a != ir.ir_codes.begin())
        a++;  // not block begin or end
    for (; a != ir.ir_codes.end(); a++) {
        RISCV_GEN(*a, st);
        // one time for Array assign elemwise
        while (a->op == ARRAY_ASSIGN_ELEMWISE) {
            a++;
        }
    }
}

int RISCV::recycle(int cls, Var* var, SymbolTable& st) {
    // output one reg
    int latest_recently_used;
    if (cls == CLS_BOOLEAN || cls == CLS_INT) {  // recycle one in int registers
        latest_recently_used = release_from_list(int_regs_pos, lru_vec_int_regs);
        std::cout << "recycle: " << reg_name[latest_recently_used];
        cout << endl;
    } else {  // recycle one in flt registers
        latest_recently_used = release_from_list(flt_regs_pos, lru_vec_flt_regs);
    }
    free_reg(latest_recently_used, cls, st);
    return latest_recently_used;
}
// TOOL
void RISCV::update_reg_info(int reg_id, int var_offset, string var_name, Var* var_ptr) {
    regs_info[reg_id].offset = var_offset;
    regs_info[reg_id].name = var_name;
    regs_info[reg_id].var_ptr = var_ptr;
    var_ptr->reg_idx = reg_id;
}
int RISCV::getReg_specific_var(int cls, int reg_id, SymbolTable& st, Var* var) {
    if (var->in_memory == true) {
        cout << "?????" << var->name << " " << reg_id << endl;
        RISCV_GEN(reg_name[reg_id], load_by_cls(cls), "-" + st.get_s0_offset(var) + "(s0)", VOID, cls);
        regs_info[reg_id].offset = var->offset;
        regs_info[reg_id].name = var->name;
        regs_info[reg_id].var_ptr = var;
        var->in_memory = false;
        var->reg_idx = reg_id;
        return reg_id;
    }
    if (regs_info[reg_id].name == "") {
        if (cls == CLS_BOOLEAN || cls == CLS_INT) {
            lru_add_tail(int_regs_pos, lru_vec_int_regs, reg_id);
        } else {
            lru_add_tail(flt_regs_pos, lru_vec_flt_regs, reg_id);
        }
        regs_info[reg_id].offset = var->offset;
        regs_info[reg_id].name = var->name;
        regs_info[reg_id].var_ptr = var;
        var->in_memory = false;
        var->reg_idx = reg_id;
        return reg_id;
    }
    // Some variable is using this register
    free_reg(reg_id, cls, st);
    if (cls == CLS_BOOLEAN || cls == CLS_INT) {
        update_lru(int_regs_pos, lru_vec_int_regs, reg_id);
    } else {
        update_lru(flt_regs_pos, lru_vec_flt_regs, reg_id);
    }
    regs_info[reg_id].offset = var->offset;
    regs_info[reg_id].name = var->name;
    regs_info[reg_id].var_ptr = var;
    var->in_memory = false;
    var->reg_idx = reg_id;
    return reg_id;
}
Var* RISCV::getReg_specific(int cls, int reg_id, SymbolTable& st) {
    if (regs_info[reg_id].name == "") {
        if (cls == CLS_BOOLEAN || cls == CLS_INT) {
            lru_add_tail(int_regs_pos, lru_vec_int_regs, reg_id);
        } else {
            lru_add_tail(flt_regs_pos, lru_vec_flt_regs, reg_id);
        }
        regs_info[reg_id].offset = 0;
        regs_info[reg_id].name = "$$";
        regs_info[reg_id].var_ptr = nullptr;
        return nullptr;
    }
    // Some variable is using this register
    cout << "getReg_spe"
         << " " << regs_info[reg_id].name << endl;
    free_reg(reg_id, cls, st);
    if (cls == CLS_BOOLEAN || cls == CLS_INT) {
        update_lru(int_regs_pos, lru_vec_int_regs, reg_id);
    } else {
        update_lru(flt_regs_pos, lru_vec_flt_regs, reg_id);
    }
    // cout << "getReg_spe"
    //      << " " << reg_name[reg_id] << endl;
    // cout << "getReg_spe"
    //      << " " << regs_info[reg_id].name << endl;
    Var* origin = regs_info[reg_id].var_ptr;
    cout << "getReg_spe" << (origin == nullptr) << endl;
    regs_info[reg_id].offset = 0;
    regs_info[reg_id].name = "$$";
    regs_info[reg_id].var_ptr = nullptr;
    return origin;
}
int RISCV::getReg(int cls, Var* var, SymbolTable& st) {
    // cout<<"getReg: ";
    string var_name = var->name;
    int var_offset = var->offset;
    if (var->reg_idx != 0) {  // in some register
        int i = var->reg_idx;
        if (cls == CLS_BOOLEAN || cls == CLS_INT) {
            update_lru(int_regs_pos, lru_vec_int_regs, i);
        } else {
            update_lru(flt_regs_pos, lru_vec_flt_regs, i);
        }
        return var->reg_idx;
    }
    // if (true == var->in_memory) {  // in memory
    //     var->in_memory = false;
    //     int reg_id = getReg(cls, var, st);
    //     if (var->offset > 0) {
    //         string off_str = "-" + to_string(var_offset + 16) + "(s0)";
    //         // st reg, memory
    //         RISCV_GEN(reg_name[reg_id], load_by_cls(cls), off_str, VOID, cls);
    //     } else {  // Global vars' offsets are less than or equal to 0 (Zero)
    //         RISCV_GEN("t6", ASM_LA, var_name, VOID, 100);
    //         RISCV_GEN(reg_name[reg_id], load_by_cls(cls), "0(t6)", VOID, cls);
    //     }
    //     return reg_id;
    // }
    // MEMORY
    // var->reg_idx == 0
    if (cls == CLS_BOOLEAN || cls == CLS_INT) {
        for (auto i : IntRegs) {
            if (regs_info[i].name == "") {
                lru_add_tail(int_regs_pos, lru_vec_int_regs, i);
                update_reg_info(i, var_offset, var_name, var);
                cout << "getReg: " << reg_name[i] << " to " << var_name << endl;
                return i;
            }
        }
        return -1;
        // recycle
        // int one = recycle(cls, var, st);
        // update_reg_info(one, var_offset, var_name, var);
        // return one;
    } else if (cls == CLS_FLOAT || cls == CLS_DOUBLE) {
        for (auto i : FltRegs) {
            if (regs_info[i].name == "") {
                lru_add_tail(flt_regs_pos, lru_vec_flt_regs, i);
                update_reg_info(i, var_offset, var_name, var);
                return i;
            }
        }
        return -2;
    }
}
// TO DO: Check
void RISCV::clear_cur_block(SymbolTable& st) {
    int size = st.block_s.size();
    auto cur_block = st.block_s[size - 1];
    for (auto a = cur_block->local_symbols.begin();
         a != cur_block->local_symbols.end(); a++) {
        cout << "clear var: " << a->second.name << " " << a->second.reg_idx << endl;
        a->second.is_using = 0;
        int reg_id = a->second.reg_idx;
        if (reg_id != 0) {
            regs_info[reg_id].name = "";
            regs_info[reg_id].offset = 0;
            regs_info[reg_id].var_ptr = nullptr;
            cout << "clear " << reg_name[reg_id] << endl;
        }
    }
}
void RISCV::clear_func(SymbolTable& st) {
    for (auto a : IntRegs) {
        regs_info[a].offset = 0;
        regs_info[a].name = "";
    }
    for (auto a : FltRegs) {
        regs_info[a].offset = 0;
        regs_info[a].name = "";
    }
    int_regs_pos.clear();
    flt_regs_pos.clear();
    lru_vec_int_regs.clear();
    lru_vec_flt_regs.clear();
    regs_info.clear();
}
#define RIGHT
void RISCV::finish_func_begin_end_in_RV(string func_name, SymbolTable& st) {
    func_regs[func_name + "int"] = lru_vec_int_regs;
    func_regs[func_name + "flt"] = lru_vec_flt_regs;

    int size = rv_codes.size();
    Func* func_info = st.lookup_func(func_name);
    int stack_size = func_info->stack_size;
    for (int i = size - 1; i >= 0; i--) {
        if (rv_codes[i].op == ASM_FUNCBEGIN) {
            rv_codes[i].arg1 = to_string(stack_size);
#ifdef RIGHT
            int size_int = func_regs[func_name + "int"].size();
            int stack = 0;
            for (int j = 0; j < size_int; j++) {
                RVC_t rvc;
                rvc.rst = "-" + to_string(stack + 8) + "(sp)";
                stack += 8;
                rvc.op = store_by_cls(100);
                rvc.arg1 = reg_name[lru_vec_int_regs[j]];
                rvc.arg2 = VOID;
                rvc.cls = 100;
                rv_codes.insert(rv_codes.begin() + i + 1, rvc);
            }
#endif
            break;
        }
    }
#ifdef RIGHT
    int size_int = func_regs[func_name + "int"].size();
    int stack = 0;
    for (int j = 0; j < size_int; j++) {
        if (reg_name[lru_vec_int_regs[j]] != "a0") {
            RISCV_GEN(reg_name[lru_vec_int_regs[j]], load_by_cls(100),
                      "-" + to_string(stack + 8) + "(sp)", VOID, 100);
        }
        stack += 8;
    }
#endif
    RISCV_GEN(func_name, ASM_FUNCEND, to_string(func_info->stack_size), VOID, 100);
}
int call_assign_get_flag;
Var* origin_var;
void RISCV::RISCV_GEN(IRC_t& ic, SymbolTable& st) {
    string rst = ic.rst;
    string arg1 = ic.arg1;
    string arg2 = ic.arg2;
    if (ic.op == OP::BLOCK_BEGIN) {
        return;
    }
    if (ic.op == OP::BLOCK_END) {
        return;
    }
    if (ic.op.find(OP::TEMP_ASSIGN_LOGIC) != std::string::npos) {
        string op_string = ic.op.substr(18);  // 17 + 1 (TEMP_ASSIGN_LOCIC's length is 17)
        Var* rst = st.lookup_var(ic.rst);
        Var* arg1 = st.lookup_var(ic.arg1);
        Var* arg2 = st.lookup_var(ic.arg2);
        int cls = ic.cls;
        string backup_0 = ic.backup_0;
        string reg_arg1 = reg_name[getReg(cls, arg1, st)];
        string reg_arg2 = reg_name[getReg(cls, arg2, st)];
        string reg_rst = reg_name[getReg(cls, rst, st)];

        if (op_string == "&&") {  // LAnd
            RISCV_GEN(reg_rst, RISCV_OP::ASM_AND, reg_arg1, reg_arg2, cls);
        }
        if (op_string == "||") {  // LOr
            RISCV_GEN(reg_rst, ASM_OR, reg_arg1, reg_arg2, cls);
        }
        return;
    }
    // $9 = bool if y == $8
    if (ic.op.find(OP::TEMP_ASSIGN_REL) != std::string::npos) {
        string op_string = ic.op.substr(16);  // 16 + 1 (TEMP_ASSIGN_REL's length is 17)
        Var* rst = st.lookup_var(ic.rst);
        Var* arg1 = st.lookup_var(ic.arg1);
        Var* arg2 = st.lookup_var(ic.arg2);
        int cls = ic.cls;
        string backup_0 = ic.backup_0;
        string reg_rst = reg_name[getReg(cls, rst, st)];
        string reg_arg1 = reg_name[getReg(cls, arg1, st)];
        string reg_arg2 = reg_name[getReg(cls, arg2, st)];
        if (op_string == "<=") {  // rst = !(arg2 < arg1)
            RISCV_GEN(reg_rst, ASM_LTE, reg_arg1, reg_arg2, cls);
        }
        if (op_string == "<") {
            RISCV_GEN(reg_rst, ASM_LT, reg_arg1, reg_arg2, cls);
        }
        if (op_string == ">=") {
            RISCV_GEN(reg_rst, ASM_GTE, reg_arg1, reg_arg2, cls);
        }
        if (op_string == ">") {
            RISCV_GEN(reg_rst, ASM_GT, reg_arg1, reg_arg2, cls);
        }
        if (op_string == "==") {
            RISCV_GEN(reg_rst, ASM_EQ, reg_arg1, reg_arg2, cls);
        }
        if (op_string == "!=") {
            RISCV_GEN(reg_rst, ASM_NE, reg_arg1, reg_arg2, cls);
        }
        return;
    }
    // store int sth, [array aa + jiji], align 4
    if (ic.op == OP::ARRAY_ASSIGN) {
        Var* rst = st.lookup_var(ic.rst);
        Var* arg1 = st.lookup_var(ic.arg1);
        Var* arg2 = st.lookup_var(ic.arg2);
        int cls = ic.cls;
        string backup_0 = ic.backup_0;
        // string reg_rst = reg_name[getReg(cls, rst, st)];
        string reg_arg1 = reg_name[getReg(cls, arg1, st)];
        string reg_arg2 = reg_name[getReg(cls, arg2, st)];
        if (0 == rst->global) {
            RISCV_GEN("t5", sll_by_cls(cls), reg_arg2, VOID, cls);  // get off in array
            string off_str = st.get_s0_offset(rst);
            RISCV_GEN("t6", ASM_ADD_64, "s0", "t5", cls);
            string exact_pos = "-" + off_str + "(t6)";
            RISCV_GEN(exact_pos, store_by_cls(cls), reg_arg1, VOID, cls);
        } else {
            RISCV_GEN("t5", sll_by_cls(cls), reg_arg2, VOID, cls);  // get off in array
            RISCV_GEN("t6", ASM_LA, ic.rst, VOID, cls);
            RISCV_GEN("t6", ASM_ADD_64, "t6", "t5", cls);
            RISCV_GEN("0(t6)", store_by_cls(cls), reg_arg1, VOID, cls);
        }
        return;
    }
    // store int 1, [array a + 3], align 4
    // store float 1, [array a + 3], align 4
    if (ic.op == OP::ARRAY_ASSIGN_INIT) {
        Var* rst = st.lookup_var(ic.rst);
        int index = stoi(ic.arg2);
        int cls = ic.cls;
        int true_off = size_by_cls(cls) * index;
        string val_str = ic.arg1;
        string backup_0 = ic.backup_0;
        if (0 == rst->global) {
            // RISCV_GEN("t5", ASM_LI, to_string(true_off), VOID, cls);
            string off_str = st.get_s0_offset(rst);
            RISCV_GEN("t6", ASM_ADD_64_IMM, "s0", to_string(true_off), cls);
            string exact_pos = "-" + off_str + "(t6)";
            if (ic.cls == CLS_BOOLEAN) {
                RISCV_GEN("t5", ASM_LI, val_str, VOID, cls);
                RISCV_GEN(exact_pos, STORE_BOOL, "t5", VOID, cls);
            }
            if (ic.cls == CLS_INT) {
                RISCV_GEN("t5", ASM_LI, val_str, VOID, cls);
                RISCV_GEN(exact_pos, STORE_INT, "t5", VOID, cls);
            }
            if (CLS_FLOAT == cls || CLS_DOUBLE == cls) {
                string label_str = ".LC" + std::to_string(flt_double_temp_count);
                RISCV_GEN_GLOBAL(".section .rodata");
                if (CLS_FLOAT == ic.cls) {
                    float fval = std::stof(ic.arg1);  // stof
                    int decimal_fval = *(int*)&fval;
                    RISCV_GEN_GLOBAL(".align   2");
                    RISCV_GEN_GLOBAL(label_str + ":");
                    RISCV_GEN_GLOBAL(".word    " + std::to_string(decimal_fval));
                }
                if (CLS_DOUBLE == ic.cls) {
                    double dval = std::stod(ic.arg1);  // stod
                    long long decimal_dval = *(long long*)&dval;
                    RISCV_GEN_GLOBAL(".align   3");
                    RISCV_GEN_GLOBAL(label_str + ":");
                    RISCV_GEN_GLOBAL(".quad    " + std::to_string(decimal_dval));
                }
                RISCV_GEN("t6", ASM_LA, label_str, VOID, 100);
                RISCV_GEN("t5", load_by_cls(cls), "0(t6)", VOID, cls);
                RISCV_GEN(exact_pos, store_by_cls(cls), "t5", VOID, cls);
                flt_double_temp_count++;
            }
        } else {
            RISCV_GEN("t5", ASM_LA, ic.rst, VOID, cls);
            string exact_pos = to_string(true_off) + "(t5)";
            if (ic.cls == CLS_BOOLEAN) {
                RISCV_GEN("t5", ASM_LI, val_str, VOID, cls);
                RISCV_GEN(exact_pos, STORE_BOOL, "t5", VOID, cls);
            }
            if (ic.cls == CLS_INT) {
                RISCV_GEN("t5", ASM_LI, val_str, VOID, cls);
                RISCV_GEN(exact_pos, STORE_INT, "t5", VOID, cls);
            }
            if (CLS_FLOAT == cls || CLS_DOUBLE == cls) {
                string label_str = ".LC" + std::to_string(flt_double_temp_count);
                RISCV_GEN_GLOBAL(".section .rodata");
                if (CLS_FLOAT == ic.cls) {
                    float fval = std::stof(ic.arg1);  // stof
                    int decimal_fval = *(int*)&fval;
                    RISCV_GEN_GLOBAL(".align   2");
                    RISCV_GEN_GLOBAL(label_str + ":");
                    RISCV_GEN_GLOBAL(".word    " + std::to_string(decimal_fval));
                }
                if (CLS_DOUBLE == ic.cls) {
                    double dval = std::stod(ic.arg1);  // stod
                    long long decimal_dval = *(long long*)&dval;
                    RISCV_GEN_GLOBAL(".align   3");
                    RISCV_GEN_GLOBAL(label_str + ":");
                    RISCV_GEN_GLOBAL(".quad    " + std::to_string(decimal_dval));
                }
                RISCV_GEN("t6", ASM_LA, label_str, VOID, 100);
                RISCV_GEN("t5", load_by_cls(cls), "0(t6)", VOID, cls);
                RISCV_GEN(exact_pos, store_by_cls(cls), "t5", VOID, cls);
                flt_double_temp_count++;
            }
        }
        return;
    }
    if (ic.op == OP::TEMP_ASSIGN_DIRECT) {
        Var* rst = st.lookup_var(ic.rst);
        int cls = ic.cls;
        string reg_rst = reg_name[getReg(cls, rst, st)];
        if (ic.cls == CLS_BOOLEAN) {
            string value = ic.arg1;
            RISCV_GEN(reg_rst, ASM_LI, value, VOID, cls);
        }
        if (ic.cls == CLS_INT) {
            RISCV_GEN(reg_rst, ASM_LI, ic.arg1, VOID, cls);
        }
        if (CLS_FLOAT == cls || CLS_DOUBLE == cls) {
            string label_str = ".LC" + std::to_string(flt_double_temp_count);
            RISCV_GEN_GLOBAL(".section .rodata");
            if (CLS_FLOAT == ic.cls) {
                float fval = std::stof(ic.arg1);  // stof
                int decimal_fval = *(int*)&fval;
                RISCV_GEN_GLOBAL(".align   2");
                RISCV_GEN_GLOBAL(label_str + ":");
                RISCV_GEN_GLOBAL(".word    " + std::to_string(decimal_fval));
            }
            if (CLS_DOUBLE == ic.cls) {
                double dval = std::stod(ic.arg1);  // stod
                long long decimal_dval = *(long long*)&dval;
                RISCV_GEN_GLOBAL(".align   3");
                RISCV_GEN_GLOBAL(label_str + ":");
                RISCV_GEN_GLOBAL(".quad    " + std::to_string(decimal_dval));
            }
            // RISCV_GEN_GLOBAL(".text");
            RISCV_GEN("t6", ASM_LA, label_str, VOID, 100);
            RISCV_GEN(reg_rst, load_by_cls(cls), "0(t6)", VOID, cls);
            flt_double_temp_count++;
        }
        return;
    }
    // store double 2, ptr
    if (ic.op == OP::VAR_ASSIGN) {
        Var* rst = st.lookup_var(ic.rst);
        Var* arg1 = st.lookup_var(ic.arg1);
        int cls = ic.cls;
        string backup_0 = ic.backup_0;
        string reg_rst = reg_name[getReg(cls, rst, st)];
        string reg_arg1 = reg_name[getReg(cls, arg1, st)];
        RISCV_GEN(reg_rst, move_by_cls(cls), reg_arg1, VOID, cls);
        return;
        // if (CLS_BOOLEAN == cls || CLS_INT == cls) {
        //     RISCV_GEN(reg_rst, move_by_cls(cls), reg_arg1, VOID, cls);
        // } else {
        //     string off_str = st.get_s0_offset(arg1);
        //     string exact_pos = "-" + off_str + "(s0)";
        //     RISCV_GEN(exact_pos, store_by_cls(cls), reg_arg1, VOID, cls);
        //     RISCV_GEN(reg_rst, load_by_cls(cls), exact_pos, VOID, cls);
        // }
        return;
    }
    if (ic.op.find(OP::TEMP_ASSIGN_1) != std::string::npos) {
        Var* rst = st.lookup_var(ic.rst);
        Var* arg1 = st.lookup_var(ic.arg1);
        int cls = ic.cls;
        string reg_rst = reg_name[getReg(cls, rst, st)];
        string reg_arg1 = reg_name[getReg(cls, arg1, st)];
        if (ic.op == OP::TEMP_ASSIGN_1_NOT) {  // bool
            RISCV_GEN(reg_rst, ASM_SEQZ, reg_arg1, VOID, cls);
        }
        if (ic.op == OP::TEMP_ASSIGN_1_NEG) {  // int float double
            if (CLS_INT == cls)
                RISCV_GEN(reg_rst, ASM_NEG_INT, reg_arg1, VOID, cls);
            if (CLS_FLOAT == cls)
                RISCV_GEN(reg_rst, ASM_NEG_FLT, reg_arg1, VOID, cls);
            if (CLS_DOUBLE == cls)
                RISCV_GEN(reg_rst, ASM_NEG_DBL, reg_arg1, VOID, cls);
        }
        return;
    }
#define inst_by_cls_2(cls, op_int, op_flt, op_dbl)           \
    if (CLS_INT == cls)                                      \
        RISCV_GEN(reg_rst, op_int, reg_arg1, reg_arg2, cls); \
    if (CLS_FLOAT == cls)                                    \
        RISCV_GEN(reg_rst, op_flt, reg_arg1, reg_arg2, cls); \
    if (CLS_DOUBLE == cls)                                   \
        RISCV_GEN(reg_rst, op_dbl, reg_arg1, reg_arg2, cls);

    if (ic.op.find(OP::TEMP_ASSIGN_2) != std::string::npos) {
        Var* rst = st.lookup_var(ic.rst);
        Var* arg1 = st.lookup_var(ic.arg1);
        Var* arg2 = st.lookup_var(ic.arg2);
        int cls = ic.cls;
        string reg_rst = reg_name[getReg(cls, rst, st)];
        string reg_arg1 = reg_name[getReg(cls, arg1, st)];
        string reg_arg2 = reg_name[getReg(cls, arg2, st)];
        if (ic.op == OP::TEMP_ASSIGN_2_ADD) {  // int float double
            inst_by_cls_2(cls, ASM_ADD_INT, ASM_ADD_FLT, ASM_ADD_DBL);
        }
        if (ic.op == OP::TEMP_ASSIGN_2_SUB) {  // int float double
            inst_by_cls_2(cls, ASM_SUB_INT, ASM_SUB_FLT, ASM_SUB_DBL);
        }
        if (ic.op == OP::TEMP_ASSIGN_2_MUL) {  // int float double
            inst_by_cls_2(cls, ASM_MUL_INT, ASM_MUL_FLT, ASM_MUL_DBL);
        }
        if (ic.op == OP::TEMP_ASSIGN_2_DIV) {  // int float double
            inst_by_cls_2(cls, ASM_DIV_INT, ASM_DIV_FLT, ASM_DIV_DBL);
        }
        if (ic.op == OP::TEMP_ASSIGN_2_MOD) {  // int float double
            inst_by_cls_2(cls, ASM_MOD_INT, ASM_MOD_FLT, ASM_MOD_DBL);
        }
        return;
    }
    if (ic.op == OP::TEMP_ASSIGN_ARRAY_LVAL) {
        Var* rst = st.lookup_var(ic.rst);
        Var* arg1 = st.lookup_var(ic.arg1);
        Var* arg2 = st.lookup_var(ic.arg2);
        int cls = ic.cls;
        string backup_0 = ic.backup_0;
        string reg_rst = reg_name[getReg(cls, rst, st)];
        string reg_arg2 = reg_name[getReg(cls, arg2, st)];
        // rst is destination, arg1 is array, arg2 is index
        if (0 == rst->global) {
            RISCV_GEN("t5", sll_by_cls(cls), reg_arg2, VOID, cls);  // get off in array
            string off_str = st.get_s0_offset(arg1);
            RISCV_GEN("t6", ASM_ADD_64, "s0", "t5", cls);
            string exact_pos = "-" + off_str + "(t6)";
            RISCV_GEN(reg_rst, load_by_cls(cls), exact_pos, VOID, cls);
        } else {
            RISCV_GEN("t5", sll_by_cls(cls), reg_arg2, VOID, cls);  // get off in array
            RISCV_GEN("t6", ASM_LA, ic.arg1, VOID, cls);
            RISCV_GEN("t6", ASM_ADD_64, "t6", "t5", cls);
            RISCV_GEN(reg_rst, load_by_cls(cls), "0(t6)", VOID, cls);
        }
        return;
    }
    if (ic.op == OP::GOTO) {
        RISCV_GEN(ic.rst, ASM_GOTO, VOID, VOID, 100);
    }
    if (ic.op == OP::LABEL) {
        RISCV_GEN(ic.rst, ASM_LABEL, VOID, VOID, 100);
    }
    // beqz a, label_0
    if (ic.op == OP::BEQZ) {
        cout << "1" << endl;
        Var* arg1 = st.lookup_var(ic.arg1);
        cout << "2" << endl;
        string reg_arg1 = reg_name[getReg(arg1->cls, arg1, st)];
        cout << "2" << endl;
        RISCV_GEN(ic.rst, ASM_BEQZ, reg_arg1, VOID, 100);
    }
    if (ic.op == OP::RET_VAL) {
        Var* rst = st.lookup_var(ic.rst);
        int cls = ic.cls;
        string reg_rst = reg_name[getReg(cls, rst, st)];
        Var* temp;
        if (reg_rst == "a0" || reg_rst == "fa0") {
            // RISCV_GEN(ic.rst, ASM_RET, ic.arg1, VOID, 100);
        } else {
            if (CLS_BOOLEAN == cls || CLS_INT == cls) {
                temp = getReg_specific(cls, REGS::a0, st);
                RISCV_GEN("a0", move_by_cls(cls), reg_rst, VOID, 100);
            } else {
                temp = getReg_specific(cls, REGS::a0, st);
                RISCV_GEN("fa0", move_by_cls(cls), reg_rst, VOID, 100);
            }
        }
    }
    if (ic.op == OP::RET) {
        // RISCV_GEN(ic.rst, ASM_RET, ic.arg1, VOID, 100);
    }
    if (ic.op == OP::CALL_STORE_RESULT) {
        Var* rst = st.lookup_var(ic.rst);
        int cls = rst->cls;
        string reg_rst = reg_name[getReg(cls, rst, st)];
        string result;
        if (CLS_FLOAT == cls || CLS_DOUBLE == cls) {
            result = "fa0";
        } else
            result = "a0";
        if (reg_rst == result) {
        } else
            RISCV_GEN(reg_rst, move_by_cls(cls), result, VOID, cls);
    }
    if (ic.op == OP::CALL_ASSIGN) {  // TODO
        int param_count = stoi(ic.arg2);
        int param_num = stoi(ic.backup_0);
        Var* param = st.lookup_var(ic.rst);
        int cls = param->cls;
        int origin_reg = getReg(cls, param, st);
        string reg_rst = reg_name[origin_reg];
        string dest = (CLS_BOOLEAN == cls || CLS_INT == cls) ? "a0" : "fa0";
        if (reg_rst == dest) {
        } else {
            call_assign_get_flag = 1;
            origin_var = regs_info[REGS::a0].var_ptr;
            string off_str = get_s0_offset(origin_var);
            string exact_pos = "-" + off_str + "(s0)";
            RISCV_GEN(exact_pos, store_by_cls(origin_var->cls),
                      reg_name[a0], VOID, origin_var->cls);
            RISCV_GEN(dest, move_by_cls(param->cls), reg_rst, VOID, param->cls);
        }
        if (param_count == param_num - 1) {
            string func_name = ic.arg1;
            if (func_name == "print_int") {
                Var* a1_var = regs_info[REGS::a1].var_ptr;
                string off_str = get_s0_offset(a1_var);
                string exact_pos = "-" + off_str + "(s0)";
                RISCV_GEN(exact_pos, store_by_cls(a1_var->cls),
                          "a1", VOID, a1_var->cls);
            }
        }
    }
    if (ic.op == OP::CALL) {  // TODO
        auto func_name = ic.rst;
        RISCV_GEN(func_name, ASM_CALL, VOID, VOID, 100);
        if (call_assign_get_flag == 1) {
            call_assign_get_flag = 0;
            int cls = origin_var->cls;
            string off_str = get_s0_offset(origin_var);
            string exact_pos = "-" + off_str + "(s0)";
            RISCV_GEN("a0", load_by_cls(cls), exact_pos, VOID, cls);
        }
        if (func_name == "print_int") {
            Var* a1_var = regs_info[REGS::a1].var_ptr;
            string off_str = get_s0_offset(a1_var);
            string exact_pos = "-" + off_str + "(s0)";     
            int cls = a1_var->cls;
            RISCV_GEN("a1", load_by_cls(cls), exact_pos, VOID, cls);
        }
    }
    if (ic.op == OP::FUNC_BEGIN) {  // TODO
        string func_name = ic.rst;
        RISCV_GEN(func_name, ASM_FUNCBEGIN, VOID, VOID, 100);
    }
    if (ic.op == OP::FUNC_END) {  // TODO
    }
    if (ic.op == OP::ALLOCA) {  // HHH
    }
    // $1 = alloca [6 x double], align 8
    if (ic.op == OP::ALLOCA_ARRAY) {  // HHH
    }
    // store int [array a + 2], [array b + 2], align 4
    // store int [array a + 3], [array b + 3], align 4
    if (ic.op == OP::ARRAY_ASSIGN_ELEMWISE) {
        Var* rst = st.lookup_var(ic.rst);
        Var* arg1 = st.lookup_var(ic.arg1);
        int index = stoi(ic.backup_0);
        int cls = ic.cls;
        Var* temp = getReg_specific(cls, REGS::s0, st);  // get s0
        if (0 == rst->global) {
            string off_str = st.get_s0_offset(rst);
            RISCV_GEN("t5", ASM_ADD_32_IMM, "s0", "-" + off_str, cls);
        } else {
            RISCV_GEN("t5", ASM_LA, ic.rst, VOID, cls);
        }
        if (0 == arg1->global) {
            string off_str = st.get_s0_offset(arg1);
            RISCV_GEN("t6", ASM_ADD_32_IMM, "s0", "-" + off_str, cls);
        } else {
            RISCV_GEN("t6", ASM_LA, ic.arg1, VOID, cls);
        }
        int length = rst->length;
        for (int i = 0; i < length; i++) {
            string true_off = to_string(size_by_cls(cls) * i);
            RISCV_GEN("s0", load_by_cls(cls), true_off + "(t5)", VOID, cls);
            RISCV_GEN(true_off + "(t6)", store_by_cls(cls), "s0", VOID, cls);
        }
    }
    // store  int [array x
    if (ic.op == OP::ARRAY_ASSIGN_ELEMWISE_ADD) {  // todo
    }
    // store  int [array x
    if (ic.op == OP::ARRAY_ASSIGN_ELEMWISE_MUL) {  // todo
    }
    // store int a, ptr b
    if (ic.op == OP::STORE_PARAM) {  // TODO
        Var* param = st.lookup_var(ic.rst);
        int cls = param->cls;
        int reg_a0 = getReg_specific_var(cls, REGS::a0, st, param);
    }
    // store bool 1, ptr a
    if (ic.op == OP::STORE_VAL) {
    }
}

void RISCV::printRC() {
    for (auto a : rv_codes_global) {
        cout << a.rst << endl;
    }
    // cout << "HHH" << endl;
    // cout << rv_codes.size();
    cout << endl;
    for (auto a : rv_codes) {
        // cout << a.op << endl;
        if (a.op == ASM_FUNCBEGIN) {
            string func_name = a.rst;
            int frame_size = stoi(a.arg1);
            cout << ("") << endl;
            cout << (".text") << endl;
            cout << (".align   1") << endl;
            cout << (".globl   " + func_name) << endl;
            cout << (".type    " + func_name + ", @function") << endl;
            cout << (func_name + ":") << endl;

            int div = frame_size / 16;
            int mod = frame_size % 16;
            int size = (mod == 0) ? (div + 1) * 16 : (div + 2) * 16;  // ra sp 8+8
            cout << ("#frame size: " + to_string(size)) << endl;
            cout << "\t" << ("addi  sp, sp, -" + to_string(size)) << endl;
            cout << "\t" << ("sd    ra, " + to_string(size - 8) + "(sp)") << endl;
            cout << "\t" << ("sd    s0, " + to_string(size - 16) + "(sp)") << endl;
            cout << "\t" << ("addi  s0, sp, " + to_string(size)) << endl;
            continue;
        }
        if (a.op == ASM_FUNCEND) {
            auto func_name = a.rst;
            int frame_size = stoi(a.arg1);
            int div = frame_size / 16;
            int mod = frame_size % 16;
            int size = (mod == 0) ? (div + 1) * 16 : (div + 2) * 16;  // ra sp 8+8

            cout << "\t" << ("ld    ra, " + to_string(size - 8) + "(sp)") << endl;
            cout << "\t" << ("ld    s0, " + to_string(size - 16) + "(sp)") << endl;
            cout << "\t" << ("addi  sp, sp, " + to_string(size)) << endl;
            cout << "\t" << ("jr    ra") << endl;
            cout << "\t" << (".size    " + func_name + ",  .-" + func_name) << endl;

            continue;
        }
        if (a.op == ASM_LABEL) {
            cout << a.rst + ":" << endl;
            // cout << "HI";
            continue;
        }
        cout << "\t";
        if (a.op == ASM_CALL) {
            cout << left << setw(7) << "call" << a.rst;
        }
        if (a.op == ASM_RET) {
            // cout << "jr ra";
        }
        if (a.op == ASM_GOTO) {
            cout << left << setw(7) << "j" << a.rst;
        }
        if (a.op == ASM_BEQZ) {
            cout << left << setw(7) << "beqz" << a.arg1 << ", " << a.rst;
        }
        if (a.op == ASM_LA) {
            cout << left << setw(7) << "la" << a.rst << ", " << a.arg1;
        }
        if (a.op == STORE_INT || a.op == STORE_BOOL) {
            cout << left << setw(7) << "sw" << a.arg1 << ", " << a.rst;
        }
        if (a.op == STORE_LONG) {
            cout << left << setw(7) << "sd" << a.arg1 << ", " << a.rst;
        }
        if (a.op == STORE_FLOAT) {
            cout << left << setw(7) << "fsw" << a.arg1 << ", " << a.rst;
        }
        if (a.op == STORE_DOUBLE) {
            cout << left << setw(7) << "fsd" << a.arg1 << ", " << a.rst;
        }
        if (a.op == LOAD_INT || a.op == LOAD_BOOL) {
            cout << left << setw(7) << "lw" << a.rst << ", " << a.arg1;
        }
        if (a.op == LOAD_LONG) {
            cout << left << setw(7) << "ld" << a.rst << ", " << a.arg1;
        }
        if (a.op == LOAD_FLOAT) {
            cout << left << setw(7) << "flw" << a.rst << ", " << a.arg1;
        }
        if (a.op == LOAD_DOUBLE) {
            cout << left << setw(7) << "fld" << a.rst << ", " << a.arg1;
        }
        if (a.op == ASM_ADD_64) {
            cout << left << setw(7) << "add" << a.rst << "," << a.arg1 << ", " << a.arg2;
        }
        if (a.op == ASM_ADD_64_IMM) {
            cout << left << setw(7) << "addi" << a.rst << "," << a.arg1 << ", " << a.arg2;
        }
        if (a.op == ASM_ADD_32_IMM) {
            cout << left << setw(7) << "addiw" << a.rst << "," << a.arg1 << ", " << a.arg2;
        }
        if (a.op == ASM_ADD_INT) {
            cout << left << setw(7) << "addw" << a.rst << "," << a.arg1 << ", " << a.arg2;
        }
        if (a.op == ASM_ADD_FLT) {
            cout << left << setw(7) << "fadd.s" << a.rst << "," << a.arg1 << ", " << a.arg2;
        }
        if (a.op == ASM_ADD_DBL) {
            cout << left << setw(7) << "fadd.d" << a.rst << "," << a.arg1 << ", " << a.arg2;
        }
        if (a.op == ASM_SUB_64) {
            cout << left << setw(7) << "sub" << a.rst << "," << a.arg1 << ", " << a.arg2;
        }
        if (a.op == ASM_SUB_64_IMM) {
            cout << left << setw(7) << "subi" << a.rst << "," << a.arg1 << ", " << a.arg2;
        }
        if (a.op == ASM_SUB_32) {
            cout << left << setw(7) << "subw" << a.rst << "," << a.arg1 << ", " << a.arg2;
        }
        if (a.op == ASM_SUB_32_IMM) {
            cout << left << setw(7) << "subiw" << a.rst << "," << a.arg1 << ", " << a.arg2;
        }
        if (a.op == ASM_SUB_INT) {
            cout << left << setw(7) << "subw" << a.rst << "," << a.arg1 << ", " << a.arg2;
        }
        if (a.op == ASM_SUB_FLT) {
            cout << left << setw(7) << "fsub.s" << a.rst << "," << a.arg1 << ", " << a.arg2;
        }
        if (a.op == ASM_SUB_DBL) {
            cout << left << setw(7) << "fsub.d" << a.rst << "," << a.arg1 << ", " << a.arg2;
        }
        if (a.op == ASM_MUL_64) {
            cout << left << setw(7) << "mul" << a.rst << "," << a.arg1 << ", " << a.arg2;
        }
        if (a.op == ASM_MUL_32) {
            cout << left << setw(7) << "mulw" << a.rst << "," << a.arg1 << ", " << a.arg2;
        }
        if (a.op == ASM_MUL_INT) {
            cout << left << setw(7) << "mulw" << a.rst << "," << a.arg1 << ", " << a.arg2;
        }
        if (a.op == ASM_MUL_FLT) {
            cout << left << setw(7) << "fmul.s " << a.rst << "," << a.arg1 << ", " << a.arg2;
        }
        if (a.op == ASM_MUL_DBL) {
            cout << left << setw(7) << "fmul.d " << a.rst << "," << a.arg1 << ", " << a.arg2;
        }
        if (a.op == ASM_DIV_64) {
            cout << left << setw(7) << "div" << a.rst << "," << a.arg1 << ", " << a.arg2;
        }
        if (a.op == ASM_DIV_32) {
            cout << left << setw(7) << "divw" << a.rst << "," << a.arg1 << ", " << a.arg2;
        }
        if (a.op == ASM_DIV_INT) {
            cout << left << setw(7) << "divw" << a.rst << "," << a.arg1 << ", " << a.arg2;
        }
        if (a.op == ASM_DIV_FLT) {
            cout << left << setw(7) << "fdiv.s" << a.rst << "," << a.arg1 << ", " << a.arg2;
        }
        if (a.op == ASM_DIV_DBL) {
            cout << left << setw(7) << "fdiv.d" << a.rst << "," << a.arg1 << ", " << a.arg2;
        }
        if (a.op.find("mod") != string::npos) {
            cout << left << setw(7) << a.op << a.rst
                 << ", " << a.arg1 << ", " << a.arg2;
        }
        if (a.op == ASM_SLL_IW_2) {
            cout << left << setw(7) << a.op << a.rst
                 << ", " << a.arg1 << ", "
                 << "2";
        }
        if (a.op == ASM_SLL_IW_3) {
            cout << left << setw(7) << a.op << a.rst
                 << ", " << a.arg1 << ", "
                 << "3";
        }
        if (a.op == ASM_SEQZ) {
            cout << left << setw(7) << "seqz" << a.rst << ", " << a.arg1;
        }
        if (a.op == ASM_NEG_INT) {
            cout << left << setw(7) << "neg" << a.rst << ", " << a.arg1;
        }
        if (a.op == ASM_NEG_FLT) {
            cout << left << setw(7) << "fneg.s" << a.rst << ", " << a.arg1;
        }
        if (a.op == ASM_NEG_DBL) {
            cout << left << setw(7) << "fneg.d" << a.rst << ", " << a.arg1;
        }
        if (a.op == ASM_AND) {
            cout << left << setw(7) << "and" << a.rst
                 << ", " << a.arg1 << ", " << a.arg2;
        }
        if (a.op == ASM_OR) {
            cout << left << setw(7) << "or" << a.rst
                 << ", " << a.arg1 << ", " << a.arg2;
        }
        if (a.op == ASM_LT) {  // rst = (arg1 < arg2)
            int cls = a.cls;
            // cout<<"LT CLS: "<<cls<<endl;
            if (CLS_INT == cls) {
                cout << left << setw(7) << "slt" << a.rst
                     << ", " << a.arg1 << ", " << a.arg2;
            }
            if (CLS_FLOAT == cls) {
                cout << left << setw(7) << "flt.s" << a.rst
                     << ", " << a.arg1 << ", " << a.arg2;
            }
            if (CLS_DOUBLE == cls) {
                cout << left << setw(7) << "flt.d" << a.rst
                     << ", " << a.arg1 << ", " << a.arg2;
            }
        }
        if (a.op == ASM_LTE) {  // rst = !(arg2 < arg1)
            int cls = a.cls;
            if (CLS_INT == cls) {
                cout << left << setw(7) << "slt" << a.rst
                     << ", " << a.arg2 << ", " << a.arg1;
            }
            if (CLS_FLOAT == cls) {
                cout << left << setw(7) << "flt.s" << a.rst
                     << ", " << a.arg2 << ", " << a.arg1;
            }
            if (CLS_DOUBLE == cls) {
                cout << left << setw(7) << "flt.d" << a.rst
                     << ", " << a.arg2 << ", " << a.arg1;
            }
            cout << endl;
            cout << left << setw(7) << "xori" << a.rst
                 << ", " << a.rst << ", "
                 << "1";
        }
        if (a.op == ASM_GT) {  // rst = (arg1 > arg2) = (arg2 < arg1)
            int cls = a.cls;
            if (CLS_INT == cls) {
                cout << left << setw(7) << "slt" << a.rst
                     << ", " << a.arg2 << ", " << a.arg1;
            }
            if (CLS_FLOAT == cls) {
                cout << left << setw(7) << "flt.s" << a.rst
                     << ", " << a.arg2 << ", " << a.arg1;
            }
            if (CLS_DOUBLE == cls) {
                cout << left << setw(7) << "flt.d" << a.rst
                     << ", " << a.arg2 << ", " << a.arg1;
            }
        }
        if (a.op == ASM_GTE) {  // rst = (arg1 >= arg2) = !(arg1 < arg2)
            int cls = a.cls;
            if (CLS_INT == cls) {
                cout << left << setw(7) << "slt" << a.rst
                     << ", " << a.arg1 << ", " << a.arg2;
            }
            if (CLS_FLOAT == cls) {
                cout << left << setw(7) << "flt.s" << a.rst
                     << ", " << a.arg1 << ", " << a.arg2;
            }
            if (CLS_DOUBLE == cls) {
                cout << left << setw(7) << "flt.d" << a.rst
                     << ", " << a.arg1 << ", " << a.arg2;
            }
            cout << endl;
            cout << left << setw(7) << "xori" << a.rst
                 << ", " << a.rst << ", "
                 << "1";
        }
        if (a.op == ASM_EQ) {  // rst = (arg1 == arg2)
            int cls = a.cls;
            if (CLS_INT == cls) {
                cout << left << setw(7) << "xor" << a.rst
                     << ", " << a.arg1 << ", " << a.arg2;
                cout << endl;
                cout << left << setw(7) << "seqz" << a.rst
                     << ", " << a.rst;
            }
            if (CLS_FLOAT == cls) {
                cout << left << setw(7) << "feq.s" << a.rst
                     << ", " << a.arg1 << ", " << a.arg2;
            }
            if (CLS_DOUBLE == cls) {
                cout << left << setw(7) << "feq.d" << a.rst
                     << ", " << a.arg1 << ", " << a.arg2;
            }
        }
        if (a.op == ASM_NE) {  // rst = (arg1 != arg2)
            int cls = a.cls;
            if (CLS_INT == cls) {
                cout << left << setw(7) << "xor" << a.rst
                     << ", " << a.arg1 << ", " << a.arg2;
                cout << endl;
                cout << left << setw(7) << "snez" << a.rst
                     << ", " << a.rst;
            }
            if (CLS_FLOAT == cls) {
                cout << left << setw(7) << "feq.s" << a.rst
                     << ", " << a.arg1 << ", " << a.arg2;
                cout << endl;
                // xori rst, rst, 1
                cout << left << setw(7) << "xori" << a.rst
                     << ", " << a.rst << ", "
                     << "1";
            }
            if (CLS_DOUBLE == cls) {
                cout << left << setw(7) << "feq.d" << a.rst
                     << ", " << a.arg1 << ", " << a.arg2;
                cout << endl;
                // xori rst, rst, 1
                cout << left << setw(7) << "xori" << a.rst
                     << ", " << a.rst << ", "
                     << "1";
            }
        }
        if (a.op == ASM_MOVE_INT) {
            cout << left << setw(7) << "mv" << a.rst
                 << ", " << a.arg1;
        }
        if (a.op == ASM_MOVE_FLT) {
            cout << left << setw(7) << "fmv.s" << a.rst
                 << ", " << a.arg1;
        }
        if (a.op == ASM_MOVE_DBL) {
            cout << left << setw(7) << "fmv.d" << a.rst
                 << ", " << a.arg1;
        }
        if (a.op == ASM_LI) {
            cout << left << setw(7) << "li" << a.rst
                 << ", " << a.arg1;
        }
        if (a.op == ASM_MOVE_FLT) {
        }
        if (a.op == ASM_MOVE_DBL) {
        }
        cout << endl;
    }
}