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
    machine(short size);

    // Tests
    void testMachine();

    // Machine Properties
protected:
    RAM *ram;
    CPU *cpu;
    output *display;

    // Initialise
private:

    void allocRAM(short size);

    void initProcessor();

    void setIO();
};


#endif //INC_8BIT_MACHINE_H
