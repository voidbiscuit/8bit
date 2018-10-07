//
// Created by timun on 07/10/2018.
//

#include <cstdio>
#include "CPU.h"
#include "instructions/instructions.h"


// Fetch Decode Execute Cycle

CPU::CPU() {
    instructionset = new instructions();
}

short CPU::tick(RAM &ram) {
    fetch(ram);
    decode();
    execute(ram);
    return flags;
}

void CPU::fetch(RAM &ram) {
    instructionregister = ram.getByte(programcounter++);
}

void CPU::decode() {
    opcode = (instructionregister & 0xF0) >> 4;
    operand = instructionregister & 0x0F;
}


void CPU::execute(RAM &ram) {
    switch (opcode) {
        case 0x00 :
            instructionset->HLT(ram, this);
            break;
        case 0x01 :
            instructionset->NOP(ram, this);
            break;
        case 0x02 :
            instructionset->JMP(ram, this);
            break;
        case 0x03 :
            instructionset->MOV(ram, this);
            break;
        case 0x04 :
            instructionset->ADD(ram, this);
            break;
        case 0x05 :
            instructionset->SUB(ram, this);
            break;
        case 0x06 :
            instructionset->MUL(ram, this);
            break;
        case 0x07 :
            instructionset->DIV(ram, this);
            break;


        default:
            printf("No instr");
            break;
    }

}

short CPU::getFlags() {
    return flags;
}

void CPU::setFlags(short flags) {
    CPU::flags = flags;
}
