#pragma once
#include <cstddef>
#include <iostream>
#include <inttypes.h>
#include "c_array.h"
#include "op_code.h"
#include "heap.h"

namespace Eric {

    struct Registers {
        int64_t data_registers[3];
        uint16_t memory_register;

        int64_t get_data_at(size_t index) {
            return data_registers[index];
        }

        void set_data_at(size_t index, int64_t value) {
            data_registers[index] = value;
        }

        int64_t A() {
            return data_registers[0];
        }

        int64_t B() {
            return data_registers[1];
        }

        int64_t C() {
            return data_registers[2];
        }

        uint16_t M() {
            return memory_register;
        }

        void A(int64_t value) {
            data_registers[0] = value;
        }

        void B(int64_t value) {
            data_registers[1] = value;
        }

        void C(int64_t value) {
            data_registers[2] = value;
        }

        void M(uint16_t value) {
            memory_register = value;
        }

        void print_state() {
            std::cout << "[ A] : " << A() << "\n";
            std::cout << "[ B] : " << B() << "\n";
            std::cout << "[ C] : " << C() << "\n";
            std::cout << "[ M] : " << M() << "\n";
        }
    };

    class VirtualMachine {
    public:
        size_t instruction_ptr;
        Registers registers;
        dyn_c_array<uint8_t> byteCode;
        Heap heap;

        VirtualMachine();
        void process();
        uint8_t next();
        void print_state();
    };
}

