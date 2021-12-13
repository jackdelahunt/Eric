#pragma once
#include "../vm/virtual_machine.h"
#include <vector>
#include "instruction.h"

namespace Eric::Generator {

    class Generator {
    public:
        std::vector<Instruction> instructions;

        Generator();

        void generate_from_file(const char *file, VM::VirtualMachine &virtualMachine);

    private:
        void parse_line(std::string &line, VM::VirtualMachine &virtualMachine);
    };

    void tokenize(std::string &str, char delim, std::vector<std::string> &out);
}

