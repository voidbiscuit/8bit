#include <iostream>
#include "src/machine/machine.h"

#define RAM 128

int main() {
    machine *machine1 = new machine(RAM);
    machine1->dispRAM();
    machine1->testMachine();
    machine1->dispRAM();
    return 0;
}


