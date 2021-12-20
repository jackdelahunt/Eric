#include <iostream>
#include "virtual_machine.h"
#include "op_code.h"
#include "debug.h"

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
        auto instruction = byteCode[instruction_ptr++];
        if(instruction >= 0) {
            std::cout << "FETCHED NON OP CODE\n";
            print_state();
        }
        switch (instruction) {
            case ICONST:
                iconst_operation();
                DEBUG("running :: iconst")
                break;
            case IADD:
                iadd_operation();
                DEBUG("running :: iadd")
                break;
            case IF_ICMP_EQ:
                if_icmp_eq_operation();
                DEBUG("running :: if_icmp_eq")
                break;
            case CALL:
                call_operation();
                DEBUG("running :: call")
                break;
            case CALL_TO:
                call_to_operation();
                DEBUG("running :: call_to")
                break;
            case RET:
                ret_operation();
                DEBUG("running :: ret")
                break;
            case LOCAL:
                local_operation();
                DEBUG("running :: local")
                break;
            case PRINT:
                print_operation();
                DEBUG("running :: print")
                break;
            case NO_OP:
                DEBUG("running :: no_op")
                break;
            case RCPY:
                rcpy_operation();
                DEBUG("running :: rcpy")
                break;
            case SCPY:
                scpy_operation();
                DEBUG("running :: scpy")
                break;
        }
    }

    void VirtualMachine::iconst_operation() {
        stack_push(current_byte());
    }

    void VirtualMachine::iadd_operation() {
        auto a = stack_pop();
        auto b = stack_pop();
        stack_push(a + b);
    }

    void VirtualMachine::if_icmp_eq_operation() {
        auto branch_to = current_byte();
        if(stack_pop() == stack_pop()) {
            instruction_ptr = branch_to;
        }
    }

    void VirtualMachine::call_operation() {
        auto address = current_byte();
        auto nArgs = current_byte();
        stack_push(nArgs);          // save the arg count
        stack_push(frame_ptr);      // save the frame ptr
        stack_push(instruction_ptr);// save where the instruction ptr is
        frame_ptr = stack_ptr;      // set local calls to be from current stack
        instruction_ptr = address;  // jump to function
    }

    void VirtualMachine::call_to_operation() {
        auto offset = current_byte();
        auto nArgs = current_byte();
        stack_push(nArgs);          // save the arg count
        stack_push(frame_ptr);      // save the frame ptr
        stack_push(instruction_ptr);// save where the instruction ptr is
        frame_ptr = stack_ptr;      // set local calls to be from current stack
        instruction_ptr += offset;  // jump to function
    }

    void VirtualMachine::ret_operation() {
        instruction_ptr = stack_pop();  // return to function call
        frame_ptr = stack_pop();        // return frame to calling frame
        stack_ptr -= stack_pop();       // pop args from stack
    }

    void VirtualMachine::local_operation() {
        auto local_index = current_byte();                                       // what arg number is it
        auto top_arg_address = frame_ptr - 3;                                    // last arg is 3 words below frame pointer
        auto bottom_arg_address = top_arg_address - (stack[frame_ptr - 2] - 1);  // bottom address is top minus arg count
        stack_push(stack[bottom_arg_address + local_index]);               // push this arg back to the stack
    }

    void VirtualMachine::print_operation() {
        std::cout << stack_pop();
    }

    void VirtualMachine::rcpy_operation() {
        auto reg = current_byte();
        switch (reg) {
            case 0:
                stack_push(r0); break;
            case 1:
                stack_push(r1); break;
            default:
                throw std::exception();
        }
    }

    void VirtualMachine::scpy_operation() {
        auto reg = current_byte();
        switch (reg) {
            case 0:
                r0 = stack_pop(); break;
            case 1:
                r1 = stack_pop(); break;
            default:
                throw std::exception();
        }
    }

    void VirtualMachine::print_state() {
        std::cout << "\n===================\n";
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

