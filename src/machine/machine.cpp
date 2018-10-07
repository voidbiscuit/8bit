//
// Created by timun on 05/10/2018.
//

#include "machine.h"

#include <cstdio>
#include <string>

// Constructor
machine::machine(short size) {
    allocRAM(size);
    initProcessor();
    setIO();
}

// Initialise
void machine::allocRAM(short size) {
    ram = new RAM(size);
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
    showOut();
    char program[] = {
            0x4F,
            0x4A,
            0x53
    };
    ram->loadProg(program, sizeof(program));
    while (cpu->getFlags() == 0x00) {
        showOut();
        cpu->tick(*ram);
    }
    showOut();
}