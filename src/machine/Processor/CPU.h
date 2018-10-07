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
    // Instructions
    instructions *instructionset;

    // Data
    short register_a = 0;
    short register_b = 0;
    short register_c = 0;
    short register_d = 0;
    short programcounter = 0;
    short instructionregister = 0;

    // Decode/Execute
    short opcode = 0;
    short operand = 0;
    short flags = 0;

public:
    short getFlags();

    void setFlags(short flags);

    short getRegister_a();

    void setRegister_a(short register_a);

    short getRegister_b();

    void setRegister_b(short register_b);

    short getRegister_c();

    void setRegister_c(short register_c);

    short getRegister_d();

    void setRegister_d(short register_d);

    short getProgramcounter();

    void setProgramcounter(short programcounter);

    short getInstructionregister();

    void setInstructionregister(short instructionregister);
};


#endif //INC_8BIT_CPU_H
