#include <iostream>
#include "virtual_machine.h"
#include "op_code.h"

namespace Eric::VM {
    VirtualMachine::VirtualMachine() {
        r0 = 0;
        r1 = 0;
        instruction_ptr = 0;
        stack_ptr = -1;
        frame_ptr = 0;
        byteCode_length = 0;
    }

    void VirtualMachine::run() {
        while (byteCode[instruction_ptr] != HALT || instruction_ptr >= byteCode_length) {
            process();
        }
    }

    void VirtualMachine::appendInstruction(int32_t instruction) {
        byteCode[byteCode_length++] = instruction;
    }

    void VirtualMachine::process() {
        switch (byteCode[instruction_ptr++]) {
            case ICONST:
                iconst_operation(); break;
            case IADD:
                iadd_operation(); break;
            case IF_ICMP_EQ:
                if_icmp_eq_operation(); break;
            case PRINT:
                print_operation(); break;
        }
    }

    void VirtualMachine::iconst_operation() {
        stack_push(current_byte());
    }

    void VirtualMachine::iadd_operation() {
        stack_push(stack_pop() + stack_pop());
    }

    void VirtualMachine::if_icmp_eq_operation() {
        auto branch_to = current_byte();
        if(stack_pop() == stack_pop()) {
            instruction_ptr = branch_to;
        }
    }

    void VirtualMachine::print_operation() {
        std::cout << stack_pop();
    }

    void VirtualMachine::print_state() {
        std::cout << "r0: " << r0 << "\n";
        std::cout << "r1: " << r1 << "\n\n";

        std::cout << "i_ptr: " << instruction_ptr << "\n";
        std::cout << "s_ptr: " << stack_ptr << "\n";
        std::cout << "f_ptr: " << frame_ptr << "\n\n";

        for(int i = 0; i <= stack_ptr; i++) {
            if(i == stack_ptr)
                std::cout << "[" << stack[i] << "]";
            else
                std::cout << stack[i] << ", ";
        }
    }

    int32_t VirtualMachine::current_byte() {
        return byteCode[instruction_ptr++];
    }

    int32_t VirtualMachine::stack_pop() {
        return stack[stack_ptr--];
    }

    void VirtualMachine::stack_push(int32_t value) {
        stack[++stack_ptr] = value;
    }
}

