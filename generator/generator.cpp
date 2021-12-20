#include "generator.h"

#include <fstream>
#include <vector>

namespace Eric::Generator {
    Generator::Generator() {
        instructions = {
                Instruction("iconst", VM::ICONST, 1),
                Instruction("iadd", VM::IADD, 0),
                Instruction("if_icmp_eq", VM::IF_ICMP_EQ, 1),
                Instruction("call", VM::CALL, 2),
                Instruction("call_to", VM::CALL_TO, 2),
                Instruction("ret", VM::RET, 0),
                Instruction("local", VM::LOCAL, 1),
                Instruction("print", VM::PRINT, 0),
                Instruction("no_op", VM::NO_OP, 0),
                Instruction("rcpy", VM::RCPY, 1),
                Instruction("scpy", VM::SCPY, 1),
                Instruction("halt", VM::HALT, 0)
        };
    }

    void Generator::generate_from_file(const char* file, VM::VirtualMachine& virtualMachine) {
        std::string buffer;

        std::ifstream f(file);
        f.seekg(0, std::ios::end);
        buffer.resize(f.tellg());
        f.seekg(0);
        f.read(buffer.data(), buffer.size());
        std::vector<std::string> lines;
        tokenize(buffer, '\n', lines);
        for(auto& line : lines) {
            parse_line(line, virtualMachine);
        }
    }

    void Generator::parse_line(std::string& line, VM::VirtualMachine& virtualMachine) {
        std::vector<std::string> words;
        tokenize(line, ' ', words);
        bool found = false;
        for(auto& instruction : instructions) {
            if (instruction.name == words[0] && instruction.argCount == words.size() - 1) {
                virtualMachine.appendInstruction(instruction.opCode);
                for(int c = 1; c < words.size(); c++) {
                    virtualMachine.appendInstruction(std::stoi(words[c]));
                }
                found = true;
            }
        }

        if(!found) {
            std::cout << "Could not find instruction " << words[0] << " with arg count " << words.size() - 1 << "\n";
        }
    }

    void tokenize(std::string &str, char delim, std::vector<std::string> &out)
    {
        size_t start;
        size_t end = 0;

        while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
        {
            end = str.find(delim, start);
            out.push_back(str.substr(start, end - start));
        }
    }
}