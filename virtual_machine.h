#pragma once
#include <cstddef>
#include <iostream>
#include <inttypes.h>
#include "c_array.h"
#include "op_code.h"

namespace Eric {

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
        void push_operation();
        void iadd_operation();
        void print_operation();
        void print_state();

    private:
        int32_t byteCode_length;
        void process();
        int32_t next();
        int32_t stack_pop();
        void stack_push(int32_t value);
    };
}

