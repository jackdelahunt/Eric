#pragma once
#include <cstddef>
#include <iostream>
#include <inttypes.h>
#include "op_code.h"

namespace Eric::VM {

    class VirtualMachine {
    public:
        int32_t r0;
        int32_t r1;

        int32_t instruction_ptr;
        int32_t stack_ptr;
        int32_t frame_ptr;

        int32_t stack[128];
        int32_t byteCode[1024];

        VirtualMachine();
        void run();
        void appendInstruction(int32_t instruction);
        void iconst_operation();
        void if_icmp_eq_operation();
        void iadd_operation();
        void print_operation();
        void print_state();

    private:
        int32_t byteCode_length;
        void process();
        int32_t current_byte();
        int32_t stack_pop();
        void stack_push(int32_t value);
    };
}

