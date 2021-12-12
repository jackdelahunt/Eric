#include <iostream>
#include "virtual_machine.h"
#include "op_code.h"
#include "operations.h"

namespace Eric {
    VirtualMachine::VirtualMachine() {
        instruction_ptr = 0;
        registers = Registers();
        byteCode = dyn_c_array<uint8_t>();
        heap = Heap();
    }

    void VirtualMachine::process() {
        switch (byteCode.at(instruction_ptr)) {
            case ADD:
                Operations::add(*this);
                break;
            case LOAD:
                Operations::load(*this);
                break;
            case SET_VAR:
                Operations::set_var(*this);
                break;
            case GET_VAR:
                Operations::get_var(*this);
                break;
        }
        instruction_ptr++;
    }

    uint8_t VirtualMachine::next() {
        return byteCode.at(++instruction_ptr);
    }

    void VirtualMachine::print_state() {
        registers.print_state();
    }
}

