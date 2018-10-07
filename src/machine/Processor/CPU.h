//
// Created by timun on 07/10/2018.
//

#ifndef INC_8BIT_CPU_H
#define INC_8BIT_CPU_H

#include <cstdio>

#include "../RAM/RAM.h"

class CPU {
public:
    CPU();

    short tick(RAM &ram);

private:
    void fetch(RAM &ram);

    void decode();

    void execute(RAM &ram);

private:
    // Data
    short programcounter = 0;
    short instructionregister = 0;
    short register_a = 0;
    short register_b = 0;
    short register_c = 0;
    short register_d = 0;


    // Decode/Execute
    short opcode = 0;
    short operand = 0;
    short flags = 0;


private:
    void HLT(short operand);

    void NOP(short operand);

    void JMP(short operand);

    void MOV(short operand);

    void ADD(short operand);

    void SUB(short operand);

    void MUL(short operand);

    void DIV(short operand);

    void MOD(short operand);


    // Getters and Setters
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
