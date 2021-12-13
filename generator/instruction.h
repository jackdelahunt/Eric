#include <cstddef>
#include <string>
#include "../vm/op_code.h"

namespace Eric::Generator {
    class Instruction {
    public:
        std::string name;
        VM::OPCode opCode;
        size_t argCount;

        Instruction(std::string name, VM::OPCode opCode, size_t argCount);
    };
}