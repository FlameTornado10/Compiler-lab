#include "IR.h"

using namespace std;

int traverse_time;
std::string IR::gen_label() {
    return "label" + std::to_string(++label_cnt);
}
std::string macro_to_string(int cls) {
    std::string result = (cls == 0) ? "int" : (cls == 1) ? "bool"
                                          : (cls == 2)   ? "float"
                                          : (cls == 3)   ? "double"
                                          : (cls == 4)   ? "void"
                                                         : "ERROR in macro!";
    return result;
}
std::string char_to_string(char cls) {
    std::string result = (cls == '0') ? "int" : (cls == '1') ? "bool"
                                            : (cls == '2')   ? "float"
                                            : (cls == '3')   ? "double"
                                            : (cls == '4')   ? "void"
                                                             : "ERROR in char!";
    return result;
}
int macro_to_align(int cls) {
    int result = (cls == 0) ? 4 : (cls == 1) ? 4
                              : (cls == 2)   ? 4
                              : (cls == 3)   ? 8
                                             : 0;
    return result;
}
// add intermediate code
// also serve as func_name, op, cls_of_parameter, VOID, ret_cls, int global, VOID
int label_flag;
int label_pos;
std::string label_l;
void IR::traverse_for_redundant_label() {
    for (auto i = this->labels_and_codes.begin();
         i != this->labels_and_codes.end(); i++) {
        std::string label = i->first;
        std::string temp = i->first;
        while (this->labels_and_codes[label].op == OP::GOTO) {
            label = this->labels_and_codes[label].rst;
        }
        for (auto i = this->ir_codes.begin();
             i != this->ir_codes.end(); i++) {
            if (i->op == OP::GOTO) {
                if (i->rst == temp) {
                    i->rst = label;
                }
            }
        }
    }
}
void IR::traverse_cur_block_for_dag_optimization(int enter_block) {
    int size = this->ir_codes.size();
    std::string op;
    if (enter_block == ENTER_BLOCK) {
        op = OP::BLOCK_BEGIN;
    } else
        op = OP::BLOCK_END;
    int i;
    // find previous block op
    for (i = size - 1; i >= 0; i--) {
        if (this->ir_codes[i].op == op) {
            break;
        }
    }
    // entering first block
    if (i == 0) {
        return;
    }
    // ir_codes[i].op == op
    int first = i + 1;
    map<string, int> ir_and_index;
    // optimize codes from (i) to (size - 1)
    for (int j = first; j < size - 1; j++) {
        string temp_op = this->ir_codes[j].op;
        if (ir_and_index.count(temp_op) == 0)
            ir_and_index.insert(pair<string, int>(temp_op, j));
        else {
            for (int t = j + 1; t < size - 1; t++) {
            }
        }
    }
}
void IR::addIC(std::string rst, std::string op, std::string arg1, std::string arg2, int cls, int global, std::string backup) {
    IRC_t t;
    t.arg1 = arg1;
    t.arg2 = arg2;
    t.op = op;
    t.rst = rst;
    t.cls = cls;
    t.backup_0 = backup;

    if (global) {
        this->ir_codes_global.push_back(t);
    } else {
        this->ir_codes.push_back(t);
    }
    if (op == OP::BLOCK_BEGIN || op == OP::BLOCK_END) {
        return;
    }
    int size = this->ir_codes.size();
    if (label_flag) {
        int size = this->ir_codes.size();
        this->labels_and_codes.insert(
            std::pair<std::string, IRCode>(
                this->ir_codes[label_pos].rst, this->ir_codes[size - 1]));
    }

    if (op == OP::LABEL) {
        label_flag = 1;
        label_pos = size - 1;
    } else
        label_flag = 0;
}
// add parameters in string
// void IR::addIC(std::string func_name, std::string op, std::string cls_of_parameter, int ret_cls, int global) {
//     IRC_t t;
//     t.rst = func_name;
//     t.op = op;
//     t.arg1 = cls_of_parameter;
//     t.cls = ret_cls;
//     if (global) {
//         this->ir_codes_global.push_back(t);
//     } else {
//         this->ir_codes.push_back(t);
//     }
// }
std::string print_parameters(std::string class_of_parameters) {
    std::string result = "";
    int size = class_of_parameters.size();
    for (int i = 0; i < size; i++) {
        if (i != 0) {
            result.append(", ");
        }
        result.append(char_to_string(class_of_parameters[i]));
        result.append(" ");
        result.append("%");
        result.append(std::to_string(i));
    }
    return result;
}

void IR::printIC() {
    for (auto item = ir_codes_global.begin(); item != ir_codes_global.end(); item++) {
        std::string cls_string = macro_to_string(item->cls);
        if (item->op == OP::GLOBAL_ASSIGN) {
            std::string flag = (item->arg2 == "const") ? "const" : "global";
            std::cout << "@"
                      << item->rst << " = "
                      << "dso_local "
                      << flag << " "
                      << cls_string << " "
                      << item->arg1 << ", align "
                      << macro_to_align(item->cls)
                      << "\n";
            continue;
        }
        if (item->op == OP::GLOBAL_ARRAY) {
            // std::cout<<&item<<"  FFFF  ";
            std::string flag = (item->arg2 == "const") ? "const" : "global";
            std::cout << "@"
                      << item->rst << " = "
                      << "dso_local "
                      << flag << " "
                      << "[" + item->arg1 + " x "
                      << cls_string << "] [";
            int fff = 0;
            int length = std::stoi(item->arg1);
            for (int i = 0; i < length; i++) {
                item++;
                if (!fff)
                    fff = 1;
                else
                    std::cout << ", ";
                std::cout << cls_string << " " << item->arg1;
            }
            std::cout << "], align "
                      << macro_to_align(item->cls)
                      << "\n";
            continue;
        }
    }
    for (auto item = ir_codes.begin(); item != ir_codes.end(); item++) {
        cout << setw(24) << item->op << "   ";
        std::string cls_string = macro_to_string(item->cls);
        if (item->op == OP::BLOCK_BEGIN) {
            std::cout << "==========BLOCK BEGIN==========\n";
            continue;
        }
        if (item->op == OP::BLOCK_END) {
            std::cout << "==========BLOCK END  ==========\n";
            continue;
        }
        if (item->op.find(OP::TEMP_ASSIGN_LOGIC) != std::string::npos) {
            std::string op_string = item->op.substr(18);
            std::cout << "    "
                      << item->rst << " = if " << cls_string << " "
                      << item->arg1 << " " << op_string << " "
                      << item->arg2
                      << "\n";
            continue;
        }
        // $9 = bool if y == $8
        if (item->op.find(OP::TEMP_ASSIGN_REL) != std::string::npos) {
            std::string op_string = item->op.substr(16);
            std::cout << "    "
                      << item->rst << " = " << cls_string << " if "
                      << item->arg1 << " " << op_string << " "
                      << item->arg2
                      << "\n";
            continue;
        }
        // store double 2, ptr @db, align 8, !tbaa !6
        if (item->op == OP::VAR_ASSIGN) {
            std::cout << "    "
                      << "store "
                      << cls_string << " "
                      << item->arg1
                      << ", ptr "
                      << item->rst
                      << ", align "
                      << macro_to_align(item->cls)
                      << "\n";
            continue;
        }
        if (item->op == OP::TEMP_ASSIGN) {
            std::cout << "    "
                      << item->rst << " = "
                      << cls_string << " "
                      << item->arg1
                      << "\n";
            continue;
        }
        if (item->op == OP::TEMP_ASSIGN_DIRECT) {
            std::cout << "    "
                      << item->rst << " = "
                      << cls_string << " "
                      << item->arg1
                      << "\n";
            continue;
        }
        if (item->op == OP::TEMP_ASSIGN_1_NOT) {
            std::cout << "    "
                      << item->rst << " = "
                      << cls_string << " "
                      << "!"
                      << item->arg1
                      << "\n";
            continue;
        }
        if (item->op == OP::TEMP_ASSIGN_1_NEG) {
            std::cout << "    "
                      << item->rst << " = "
                      << cls_string << " "
                      << "-"
                      << item->arg1
                      << "\n";
            continue;
        }
        if (item->op == OP::TEMP_ASSIGN_2_ADD) {
            std::cout << "    "
                      << item->rst << " = "
                      << cls_string << " "
                      << item->arg1 << " + "
                      << item->arg2
                      << "\n";
            continue;
        }
        if (item->op == OP::TEMP_ASSIGN_2_MUL) {
            std::cout << "    "
                      << item->rst << " = "
                      << cls_string << " "
                      << item->arg1 << " * "
                      << item->arg2
                      << "\n";
            continue;
        }
        if (item->op == OP::TEMP_ASSIGN_2_DIV) {
            std::cout << "    "
                      << item->rst << " = "
                      << cls_string << " "
                      << item->arg1 << " / "
                      << item->arg2
                      << "\n";
            continue;
        }
        if (item->op == OP::TEMP_ASSIGN_2_MOD) {
            std::cout << "    "
                      << item->rst << " = "
                      << cls_string << " "
                      << item->arg1 << " % "
                      << item->arg2
                      << "\n";
            continue;
        }

        if (item->op == OP::TEMP_ASSIGN_ARRAY_LVAL) {
            std::cout << "    "
                      << item->rst << " = "
                      << cls_string << " "
                      << "[array " << item->arg1 << " + " << item->arg2 << "]"
                      << "\n";
            continue;
        }
        if (item->op == OP::GOTO) {
            std::cout << "    "
                      << "goto"
                      << "  "
                      << item->rst << "\n";
        }
        if (item->op == OP::LABEL) {
            std::cout << item->rst << ":\n";
            continue;
        }
        // beqz a, label_0
        if (item->op == OP::BEQZ) {
            std::cout << "    "
                      << "beqz "
                      << item->arg1
                      << " "
                      << item->rst << "\n";
            continue;
        }
        if (item->op == OP::RET_VAL) {
            std::cout << "    "
                      << "ret"
                      << " " << cls_string << " " << item->rst << "\n";
            continue;
        }
        if (item->op == OP::RET) {
            std::cout << "    "
                      << "ret\n";
            continue;
        }
        if (item->op == OP::CALL_STORE_RESULT) {
            cout << "    \t";
            cout << item->rst << " = call";
            cout << endl;
        }
        if (item->op == OP::CALL_ASSIGN) {
            cout << "    \t";
            cout << "param"<<"_"<<item->arg2<<" = "<<item->rst;
            cout << endl;
        }
        if (item->op == OP::CALL) {
            auto temp = item;
            int param_num = std::stoi(item->arg1);
            std::cout << "    ";
            std::cout << "call "
                      << macro_to_string(temp->cls) << " "
                      << "@" << temp->rst << "()" << endl;
            continue;
        }
        if (item->op == OP::FUNC_BEGIN) {
            std::cout << "declare "
                      << "dso_local "
                      << cls_string << " "
                      << "@" << item->rst
                      << "(" << print_parameters(item->arg1) << ") "
                      << "#0 {\n";
            continue;
        }
        if (item->op == OP::FUNC_END) {
            std::cout << "}\n";
            continue;
        }
        if (item->op == OP::ALLOCA) {
            std::cout << "    "
                      << item->rst << " = alloca "
                      << std::setw(6)
                      << cls_string << ", align "
                      << macro_to_align(item->cls)  //<<" "<<item->cls
                      << "\n";
            continue;
        }
        // $1 = alloca [6 x double], align 8
        if (item->op == OP::ALLOCA_ARRAY) {
            std::cout << "    "
                      << item->rst << " = alloca "
                      << std::setw(2)
                      << "[" << item->arg1 << " x "
                      << cls_string << "], align "
                      << macro_to_align(item->cls)  //<<" "<<item->cls
                      << "\n";
            continue;
        }
        // store int sth, [array aa + jiji], align 4
        if (item->op == OP::ARRAY_ASSIGN) {
            std::cout << "    "
                      << "store " << cls_string
                      << item->arg1 << ", "
                      << "[array " << item->rst << " + " << item->arg2 << "]"
                      << ", align" << macro_to_align(item->cls)
                      << "\n";
            continue;
        }

        // store int 1, [array a + 3], align 4
        if (item->op == OP::ARRAY_ASSIGN_INIT) {
            std::cout << "    store "
                      << std::setw(4)
                      << cls_string << " "
                      << " " << item->arg1 << ", [array "
                      << item->rst << " + " << item->arg2 << "]"
                      << ", align "
                      << macro_to_align(item->cls)
                      << "\n";
            continue;
        }
        // store int [array a + 2], [array b + 3], align 4
        if (item->op == OP::ARRAY_ASSIGN_ELEMWISE) {
            std::cout << "    store "
                      << std::setw(4)
                      << cls_string << " "
                      << "[array " << item->arg1 << " + " << item->backup_0 << "]"
                      << ", [array " << item->rst << " + " << item->backup_0 << "]"
                      << ", align "
                      << macro_to_align(item->cls)
                      << "\n";
            continue;
        }
        // store  int [array x + 1]+ [array z + 1]=> [array y + 1], align 4
        if (item->op == OP::ARRAY_ASSIGN_ELEMWISE_ADD) {
            std::cout << "    store "
                      << std::setw(4)
                      << cls_string << " "
                      << "[array " << item->arg1 << " + " << item->backup_0 << "]"
                      << "+[array " << item->arg2 << " + " << item->backup_0 << "]"
                      << "=> [array " << item->rst << " + " << item->backup_0 << "]"
                      << ", align "
                      << macro_to_align(item->cls)
                      << "\n";
            continue;
        }
        // store  int [array x + 1]*[array z + 1]=> [array y + 1], align 4
        if (item->op.find(OP::ARRAY_ASSIGN_ELEMWISE) != std::string::npos) {
            std::cout << item->op;
            std::cout << item->op;
            std::cout << item->op;
            std::cout << endl;
            string ic_op;
            if (item->op.find("*") != std::string::npos)
                ic_op = "*";
            if (item->op.find("/") != std::string::npos)
                ic_op = "/";
            if (item->op.find("%") != std::string::npos)
                ic_op = "%";
            std::cout << "    store "
                      << std::setw(4)
                      << cls_string << " "
                      << "[array " << item->arg1 << " + " << item->backup_0 << "]" << ic_op
                      << "[array " << item->arg2 << " + " << item->backup_0 << "]"
                      << "=> [array " << item->rst << " + " << item->backup_0 << "]"
                      << ", align "
                      << macro_to_align(item->cls)
                      << "\n";
            continue;
        }
        // store int a, ptr b, align 4
        if (item->op == OP::STORE_PARAM) {
            std::cout << "    store "
                      << std::setw(6)
                      << cls_string << " "
                      << "%"
                      << item->arg1 << ", ptr "
                      << item->rst << ", align "
                      << macro_to_align(item->cls)
                      << "\n";
            continue;
        }
        // store bool 1, ptr a, align 4
        if (item->op == OP::STORE_VAL) {
            std::cout << "    store "
                      << std::setw(6)
                      << cls_string << " "              // bool
                      << " " << item->arg1 << ", ptr "  // 1, ptr
                      << item->rst << ", align "        // a, align
                      << macro_to_align(item->cls)
                      << "\n";
            continue;
        }
    }
}
