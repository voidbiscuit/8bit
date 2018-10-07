#include <iostream>
#include "src/machine/machine.h"

#define RAM 128

int main() {
    machine *machine1 = new machine(RAM);
    machine1->testMachine();
    return 0;
}