#include <iostream>
#include "virtual_machine.h"
#include "op_code.h"
#include "operations.h"

int main() {
    auto vm = Eric::VirtualMachine();
    vm.byteCode.append(Eric::OPCode::LOAD);
    vm.byteCode.append(0);
    vm.byteCode.append(10);

    vm.byteCode.append(Eric::OPCode::LOAD);
    vm.byteCode.append(1);
    vm.byteCode.append(20);

    vm.byteCode.append(Eric::OPCode::ADD);
    vm.byteCode.append(0);
    vm.byteCode.append(1);

    vm.process();
    vm.process();
    vm.process();
    vm.print_state();
    return 0;
}
