//
// Created by timun on 05/10/2018.
//

#include "machine.h"

// Constructor
machine::machine() {
    allocRAM();
    initProcessor();
    setIO();
}

// Initialise
void machine::allocRAM() {
    ram = new RAM();
}

void machine::initProcessor() {
    cpu = new CPU();
}

void machine::setIO() {
    display = new output();
}

// Output

void machine::showOut() {
    display->dispSystem(*cpu, *ram);
}


// Test
void machine::testMachine() {
    unsigned char program[256] = {
            0x40, 0x03, 0x00, 0x00, 0xFF, 0XFF
    };
    ram->loadProg(program);
    while (cpu->getFlags() == 0x00) {
        showOut();
        cpu->tick(*ram);
    }
    showOut();
}