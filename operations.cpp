#include "operations.h"

namespace Eric::Operations {
    void add(VirtualMachine &vm) {
        size_t r1 = vm.next();
        size_t r2 = vm.next();
        vm.registers.set(0, vm.registers.at(r1) + vm.registers.at(r2));
    }

    void load(VirtualMachine &vm) {
        auto r = vm.next();
        auto value = vm.next();
        vm.registers.set(r, value);
    }
}