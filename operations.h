#pragma once
#include "virtual_machine.h"

namespace Eric::Operations {
    void add(VirtualMachine& vm);
    void load(VirtualMachine& vm);
    void set_var(VirtualMachine& vm);
    void get_var(VirtualMachine& vm);
    void move(VirtualMachine& vm);
}