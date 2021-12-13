#include <iostream>
#include "virtual_machine.h"
#include "op_code.h"

int main() {
    auto vm = Eric::VirtualMachine();
    vm.appendInstruction(Eric::PUSH);
    vm.appendInstruction(10);
    vm.appendInstruction(Eric::PUSH);
    vm.appendInstruction(20);
    vm.appendInstruction(Eric::IADD);
    vm.appendInstruction(Eric::HALT);

    vm.run();
    vm.print_state();
    return 0;
}
