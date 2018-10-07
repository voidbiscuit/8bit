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


// Test
void machine::testMachine() {
    display->dispRAM(*ram);
    ram->setByte(12, 12);
    display->dispRAM(*ram);
}