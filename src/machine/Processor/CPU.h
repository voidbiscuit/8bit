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

    unsigned short tick(RAM &ram);

private:
    void fetch(RAM &ram);

    void decode();

    void execute(RAM &ram);

private:
    // Data
    unsigned short programcounter = 0;
    unsigned short opcode = 0;
    unsigned short operand = 0;
    unsigned short currentreg = 0;
    unsigned short registers[16] =
            {
                    0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00, 0x00, 0x00
            };

    unsigned short flags = 0;


private:
    void HLT(unsigned short operand);

    void NOP(unsigned short operand);

    void JMP(unsigned short operand);

    void MOV(unsigned short operand);

    void ADD(unsigned short operand, RAM &ram);

    void SUB(unsigned short operand, RAM &ram);

    void MUL(unsigned short operand, RAM &ram);

    void DIV(unsigned short operand, RAM &ram);

    void MOD(unsigned short operand, RAM &ram);


    // Getters and Setters
public:
    // Registers
    unsigned short getRegisters(unsigned short reg);

    unsigned short getCurrentRegVal();

    unsigned short getCurrentReg();

    void changeCurrentReg(unsigned short reg);

    void setCurrentReg(unsigned short val);

    // Flags
    unsigned short getFlags();

    void setFlags(unsigned short flags);


    unsigned short getOPcode();

    unsigned short getOPerand();

    unsigned short getProgramCounter();
};


#endif //INC_8BIT_CPU_H
