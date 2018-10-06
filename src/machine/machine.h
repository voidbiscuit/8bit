//
// Created by timun on 05/10/2018.
//

#ifndef INC_8BIT_MACHINE_H
#define INC_8BIT_MACHINE_H

#include "RAM/RAM.h"
#include "IO/output.h"

class machine {
public:
    // Constructor
    machine(short size);

    // IO
    void dispRAM();

    // Tests
    void testMachine();

private:
    // Machine Properties
    RAM *ram;
    output *display;

    // Initialise
    void allocRAM(short size);

    void setIO();
};


#endif //INC_8BIT_MACHINE_H
