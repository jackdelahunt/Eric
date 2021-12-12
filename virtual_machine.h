#pragma once
#include <cstddef>
#include <inttypes.h>
#include "c_array.h"
#include "op_code.h"

namespace Eric {
    class VirtualMachine {
    public:
        size_t instruction_ptr;
        static_c_array<int64_t> registers;
        dyn_c_array<uint8_t> byteCode;

        VirtualMachine();
        void process();
        uint8_t next();
        void print_state();
    };
}


