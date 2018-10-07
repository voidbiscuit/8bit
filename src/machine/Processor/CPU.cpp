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
            instructionset->HLT(this, operand);
            break;
        case 0x01 :
            instructionset->NOP(this, operand);
            break;
        case 0x02 :
            instructionset->JMP(this, operand);
            break;
        case 0x03 :
            instructionset->MOV(this, operand);
            break;
        case 0x04 :
            instructionset->ADD(this, operand);
            break;
        case 0x05 :
            instructionset->SUB(this, operand);
            break;
        case 0x06 :
            instructionset->MUL(this, operand);
            break;
        case 0x07 :
            instructionset->DIV(this, operand);
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

short CPU::getRegister_a() {
    return register_a;
}

void CPU::setRegister_a(short register_a) {
    CPU::register_a = register_a;
}

short CPU::getRegister_b() {
    return register_b;
}

void CPU::setRegister_b(short register_b) {
    CPU::register_b = register_b;
}

short CPU::getRegister_c() {
    return register_c;
}

void CPU::setRegister_c(short register_c) {
    CPU::register_c = register_c;
}

short CPU::getRegister_d() {
    return register_d;
}

void CPU::setRegister_d(short register_d) {
    CPU::register_d = register_d;
}

short CPU::getProgramcounter() {
    return programcounter;
}

void CPU::setProgramcounter(short programcounter) {
    CPU::programcounter = programcounter;
}

short CPU::getInstructionregister() {
    return instructionregister;
}

void CPU::setInstructionregister(short instructionregister) {
    CPU::instructionregister = instructionregister;
}


