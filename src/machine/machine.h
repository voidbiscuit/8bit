//
// Created by timun on 05/10/2018.
//

#ifndef INC_8BIT_MACHINE_H
#define INC_8BIT_MACHINE_H

#include "RAM/RAM.h"
#include "Processor/CPU.h"
#include "IO/output.h"


class machine {
public:
    // Constructor
    machine();

protected:
    // Machine Properties
    RAM *ram;
    CPU *cpu;
    output *display;

private:
    // Initialise
    void allocRAM();

    void initProcessor();

    void setIO();

public:
    // IO
    void showOut();

    // Tests
    void testMachine();
};


#endif //INC_8BIT_MACHINE_H
