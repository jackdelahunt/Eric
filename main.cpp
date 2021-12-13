#include <iostream>
#include "vm/virtual_machine.h"
#include "generator/generator.h"

int main() {
    auto vm = Eric::VM::VirtualMachine();
    auto gen = Eric::Generator::Generator();
    gen.generate_from_file("../main.ere", vm);
    vm.run();
    return 0;
}
