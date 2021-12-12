#include <iostream>
#include "virtual_machine.h"
#include "op_code.h"
#include "operations.h"
#include "heap.h"

int main() {
    auto vm = Eric::VirtualMachine();
    vm.byteCode.append(Eric::OPCode::LOAD);
    vm.byteCode.append(0);
    vm.byteCode.append(100);
    vm.byteCode.append(Eric::OPCode::MOV);
    vm.byteCode.append(1);
    vm.byteCode.append(0);



    vm.process();
    vm.process();
    vm.print_state();
    return 0;
}
