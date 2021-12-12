#include "operations.h"

namespace Eric::Operations {
    void add(VirtualMachine &vm) {
        size_t r1 = vm.next();
        size_t r2 = vm.next();
        vm.registers.C(vm.registers.get_data_at(r1) + vm.registers.get_data_at(r2));
    }

    void load(VirtualMachine &vm) {
        auto r = vm.next();
        auto value = vm.next();
        vm.registers.set_data_at(r, value);
    }

    void set_var(VirtualMachine& vm) {
        uint8_t value = vm.next();
        auto address = vm.heap.alloc<uint8_t >(&value);
        vm.registers.M(address);
    }

    void get_var(VirtualMachine& vm) {
        auto r = vm.next();
        // TODO: can only load address that is already in memory register
        vm.registers.set_data_at(r, vm.heap.lookup(vm.registers.M()));
    }
}