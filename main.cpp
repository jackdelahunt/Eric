#include <iostream>
#include "virtual_machine.h"
#include "op_code.h"
#include "operations.h"
#include "heap.h"

int main() {
    auto vm = Eric::VirtualMachine();
    vm.byteCode.append(Eric::OPCode::SET_VAR);
    vm.byteCode.append(100);
    vm.byteCode.append(Eric::OPCode::SET_VAR);
    vm.byteCode.append(200);

    vm.process();
    vm.process();
    vm.process();
    vm.print_state();
    return 0;
}
