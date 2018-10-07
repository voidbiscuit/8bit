//
// Created by timun on 07/10/2018.
//

#ifndef INC_8BIT_CPU_H
#define INC_8BIT_CPU_H

#include "../RAM/RAM.h"
#include "instructions/instructions.h"

class CPU {
public:
    CPU();

    short tick(RAM &ram);

private:
    void fetch(RAM &ram);

    void decode();

    void execute(RAM &ram);

private:
    instructions *instructionset;
    short programcounter = 0;
    short instructionregister;
    short opcode = 0;
    short operand = 0;
    short registers[4] = {0, 0, 0, 0};
    short flags = 0;

protected:
    short getFlags();

    void setFlags(short flags);
};


#endif //INC_8BIT_CPU_H
