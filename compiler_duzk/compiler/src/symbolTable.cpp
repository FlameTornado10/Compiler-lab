#include "symbolTable.h"

#define SYM_CLS(x) (x.cls == CLS_INT ? "int" : x.cls == CLS_BOOLEAN ? "bool"   \
                                           : x.cls == CLS_FLOAT     ? "float"  \
                                           : x.cls == CLS_DOUBLE    ? "double" \
                                                                    : "void")
#define SYM_TYP(x) (x.type == TP_CONST ? "const" : x.type == TP_VAR       ? "var"         \
                                               : x.type == TP_CONST_ARRAY ? "const_array" \
                                               : x.type == TP_ARRAY       ? "array"       \
                                                                          : "para")
std::string class_to_string(int cls) {
    if (cls == CLS_INT)
        return "int";
    else if (cls == CLS_BOOLEAN)
        return "bool";
    else if (cls == CLS_FLOAT)
        return "float";
    else if (cls == CLS_DOUBLE)
        return "double";
    else if (cls == CLS_VOID)
        return "void";
}
Var* SymbolTable::lookup_var(const std::string& name) {
    int size = block_s.size();
    while (size > 1) {
        BlockTable* bt = block_s[size - 1];
        if (bt->local_symbols.count(name) == 1)
            return &bt->local_symbols[name];
        size--;
    }
    if (global_symbols.count(name) == 1)
        return &global_symbols[name];
    else
        return nullptr;
}
Func* SymbolTable::lookup_func(const std::string& name) {
    if (func_symbols.count(name) == 1)
        return &func_symbols[name];
    else
        return nullptr;
}
Var* SymbolTable::lookup_param(Func& func, int para_idx) {
    std::cout << "\t[T] lookup parameter"
              << "\n";
    std::cout << "func name: " << func.name << "\n";
    std::cout << "para_idx: " << para_idx << "\n";
    for (auto i = func.func_block.local_symbols.begin();
         i != func.func_block.local_symbols.end(); i++) {
        std::cout << "i.first: " << i->first << "\n";
        std::cout << "i.second.length: " << i->second.length << "\n";
        std::cout << "i.second.type: " << i->second.type << "\n";
        if (i->second.length == para_idx && i->second.type == TP_PARAM) {
            return &(i->second);
        }
    }
}

void SymbolTable::addSymbol(std::string name, int cls, int type, int length, int line) {
    auto var = new Var;
    var->name = name;
    var->cls = cls;
    var->type = type;
    var->length = length;
    var->line = line;
    var->is_using = true;
    var->in_memory = false;
    if (type == TP_CONST || type == TP_VAR || type == TP_PARAM) {
        stack_offset += (cls == CLS_DOUBLE) ? 8 : 4;
        var->offset = stack_offset;
    } else if (type == TP_ARRAY || type == TP_CONST_ARRAY) {
        stack_offset += ((cls == CLS_DOUBLE) ? 8 : 4) * length;
        var->offset = stack_offset;
    }
    // std::cout << "add 1 ";
    int size = block_s.size();
    // std::cout << "add 2 "
    //   << " size: " << size;
    if (cur_func == "$") {
        if (global_symbols.count(name) == 0) {
            var->global = 1;
            var->offset = -(var->offset);
            global_symbols.insert(std::pair<std::string, Var>(name, *var));
        } else
            throw std::runtime_error("line[%d] error: multiply declaration of: '" + name + "'\n");
    } else {
        BlockTable* top = block_s[size - 1];
        if (top->local_symbols.count(name) != 0) {
            throw std::runtime_error("line[%d] error: multiply declaration of: '" + name + "'\n");
        }
        // name should not be any parameter's name
        BlockTable* param_block = &func_symbols[cur_func].func_block;
        int check_func = 0;
        // the one under the stack top may be parameter block, if so
        // param_block's local symbols may include the name
        if (block_s[size - 2] == param_block && param_block->local_symbols.count(name) != 0) {
            throw std::runtime_error("line[%d] error: redeclaration of function parameter: '" + name + "'\n");
        }
        std::cout << "\t[T] add symbol " + name + " in " << cur_func << " length: " << length << "\n";
        top->local_symbols.insert(std::pair<std::string, Var>(name, *var));
    }
}

void SymbolTable::addFunc(std::string name, int return_cls, int param_num, int line) {
    auto func = new Func;
    func->name = name;
    func->cls = return_cls;
    func->param_num = param_num;
    func->line = line;
    func->func_block.line = line;

    std::cout << "\t[T] add funtion: function name: " + name << std::endl;
    std::cout << "\tfunc class: " << class_to_string(return_cls);
    std::cout << "\n";
    if (func_symbols.count(name) == 0)
        func_symbols.insert(std::pair<std::string, Func>(name, *func));
    else
        throw std::runtime_error("line " + std::to_string(line) +
                                 ": error: redefinition of '" + name + "'\n");
    cur_func = name;
    block_s.push_back(&func_symbols[name].func_block);
}

void SymbolTable::addBlock(int line) {
    std::cout << "        [T] add block in line: " +
                     std::to_string(line)
              << std::endl;
    BlockTable* block = new BlockTable;
    block->line = line;
    int size = block_s.size();
    BlockTable* top = block_s[size - 1];
    if (top == nullptr) {
        block_s.push_back(block);
    } else {
        top->sub_blocks.insert(std::pair<int, BlockTable*>(line, block));
        block_s.push_back(block);
    }
}

std::string SymbolTable::gen_temp_var(int lc, int cls, int type) {
    std::string name = "$" + std::to_string(++temp_var);
    std::cout << "\t"
              << "[T] gen temp var in " << lc << " ";
    std::cout << class_to_string(cls) << "\n";
    // std::cout << " GGG ";
    if (cls != CLS_INT && cls != CLS_BOOLEAN && cls != CLS_FLOAT && cls != CLS_DOUBLE)
        throw std::runtime_error("wrong class in the generation of temp var" + name);
    // std::cout << " HHH ";
    if (type == TP_CONST || type == TP_CONST_ARRAY)
        this->addSymbol(name, cls, TP_CONST, 0, lc);
    else if (type == TP_ARRAY || type == TP_VAR) {
        // std::cout << " gonna add symbol ";
        // std::cout << std::endl;
        this->addSymbol(name, cls, TP_VAR, 0, lc);
    }
    return name;
}

std::string SymbolTable::gen_temp_array(int lc, int cls, int size) {
    std::string name = "$" + std::to_string(++temp_var);
    if (cls != CLS_INT && cls != CLS_BOOLEAN && cls != CLS_FLOAT && cls != CLS_DOUBLE)
        throw std::runtime_error("wrong class in the generation of temp var" + name);
    this->addSymbol(name, cls, TP_ARRAY, size, lc);
    return name;
}

std::string SymbolTable::get_s0_offset(Var* info) {
    if (!info->global) {
        int offset_to_sp = info->offset + 16;  // ra:8 + sp:8
        std::string res = std::to_string(offset_to_sp);
        return res;
    } else {
        return (info->name) + ".g";
    }
}

void printTable(std::ofstream& o, std::map<std::string, Var>& sym_table) {
    o << std::setw(14) << "name" << '|'
      << std::setw(7) << "class" << '|'
      << std::setw(12) << "type" << '|'
      << std::setw(10) << "val" << '|'
      << std::setw(5) << "line" << '|' << std::endl;
    for (auto i = sym_table.begin(); i != sym_table.end(); i++) {
        o << std::setw(14) << i->first << '|'
          << std::setw(7) << SYM_CLS(i->second) << '|'
          << std::setw(12) << SYM_TYP(i->second) << '|'
          << std::dec << std::setw(10) << i->second.length << '|'
          << std::dec << std::setw(5) << i->second.line << '|' << std::endl;
    }
    o << std::endl;
}

void printBlock(std::ofstream& o, BlockTable* block) {
    o << "Block " << block->line << " has " << block->sub_blocks.size() << " children:\n";
    for (auto i = block->sub_blocks.begin(); i != block->sub_blocks.end(); i++)
        o << "\t" << i->first;
    o << std::endl;

    o << "Block " << block->line << " local symbols:\n";
    printTable(o, block->local_symbols);
    for (auto i = block->sub_blocks.begin(); i != block->sub_blocks.end(); i++)
        printBlock(o, i->second);

    o << "Block " << block->line << " ends.\n";
    o << std::endl;
}

void printFunc(std::ofstream& o, Func& func) {
    o << func.name << " returns " << SYM_CLS(func) << ':' << std::endl;
    printBlock(o, &func.func_block);
    o << func.name << " ends.\n";
    o << std::endl;
}

void SymbolTable::printSymbol(std::ofstream& o) {
    o << std::right;
    o << "global:" << std::endl;
    printTable(o, global_symbols);
    for (auto i = func_symbols.begin(); i != func_symbols.end(); i++) {
        if (i->first != "main")
            printFunc(o, i->second);
    }
    printFunc(o, func_symbols["main"]);
}