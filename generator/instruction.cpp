#include "instruction.h"
#include <utility>

namespace Eric::Generator {
    Instruction::Instruction(std::string name, VM::OPCode opCode, size_t argCount) {
        this->name = std::move(name);
        this->opCode = opCode;
        this->argCount = argCount;
    }
}