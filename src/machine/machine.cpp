//
// Created by timun on 05/10/2018.
//

#include "machine.h"

#include <cstdio>
#include <string>

// Components
#include "RAM/RAM.h"

// Constructor
machine::machine(short size) {
    allocRAM(size);
    setIO();
}

// Initialise
void machine::allocRAM(short size) {
    ram = new RAM(size);
}

void machine::setIO() {
    display = new output();
}


// See RAM

void machine::dispRAM() {
    short columns = 8;
    printf("\n\n ADDR DATA");
    for (short reg = 0; reg < ram->getMaxRAM(); reg++) {
        if (reg % columns == 0) printf("\n%#*x", 5, reg);
        printf(" ");
        display->printByte(ram->getByte(reg));
    }
}


// Test
void machine::testMachine() {
    ram->getByte(12);
    ram->setByte(12, 12);
    ram->getByte(12);
}