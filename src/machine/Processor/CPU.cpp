//
// Created by timun on 07/10/2018.
//


#include "CPU.h"


// Fetch Decode Execute Cycle

CPU::CPU() {

}

// CPU Processing
unsigned short CPU::tick(RAM &ram) {
    fetch(ram);
    decode();
    execute(ram);
    return flags;
}

// Fetch Decode Execute Cycle
void CPU::fetch(RAM &ram) {
    opcode = ram.getByte(programcounter++); // Fetch
    operand = ram.getByte(programcounter++); // Fetch
}

void CPU::decode() {
    currentreg = opcode & 0x0F;
    opcode >>= 4;
}

void CPU::execute(RAM &ram) {


    switch (opcode) {
        case 0x00 :
            HLT(operand);
            break;
        case 0x01 :
            NOP(operand);
            break;
        case 0x02 :
            JMP(operand);
            break;
        case 0x03 :
            MOV(operand);
            break;
        case 0x04 :
            ADD(operand, ram);
            break;
        case 0x05 :
            SUB(operand, ram);
            break;
        case 0x06 :
            MUL(operand, ram);
            break;
        case 0x07 :
            DIV(operand, ram);
            break;
        case 0x08 :
            MOD(operand, ram);
            break;
        default:
            HLT(operand);
            break;
    }

}


void CPU::HLT(unsigned short operand) {
    programcounter = 0;
    setFlags(0x01);
}

void CPU::NOP(unsigned short operand) {
    setFlags(0x00);
}

void CPU::JMP(unsigned short operand) {
    programcounter = operand;
    if (programcounter % 2 != 0) programcounter--;
    setFlags(0x00);
}

void CPU::MOV(unsigned short operand) {

    setFlags(0x00);
}

void CPU::ADD(unsigned short operand, RAM &ram) {
    setCurrentReg(getCurrentRegVal() + ram.getByte(operand));
    setFlags(0x00);
}

void CPU::SUB(unsigned short operand, RAM &ram) {
    setCurrentReg(getCurrentRegVal() - ram.getByte(operand));
    setFlags(0x00);
}

void CPU::MUL(unsigned short operand, RAM &ram) {
    setCurrentReg(getCurrentRegVal() * ram.getByte(operand));
    setFlags(0x00);
}

void CPU::DIV(unsigned short operand, RAM &ram) {
    setCurrentReg(getCurrentRegVal() / ram.getByte(operand));
    setFlags(0x00);
}

void CPU::MOD(unsigned short operand, RAM &ram) {
    setCurrentReg(getCurrentRegVal() % ram.getByte(operand));
    setFlags(0x00);
}


unsigned short CPU::getFlags() {
    return flags;
}

void CPU::setFlags(unsigned short flags) {
    CPU::flags = flags;
}

unsigned short CPU::getRegisters(unsigned short reg) {
    return registers[reg];
}

unsigned short CPU::getCurrentRegVal() {
    return registers[currentreg];
}

unsigned short CPU::getCurrentReg() {
    return currentreg;
}

void CPU::changeCurrentReg(unsigned short reg) {
    currentreg = reg;
}

void CPU::setCurrentReg(unsigned short val) {
    registers[currentreg] = val;
}

unsigned short CPU::getProgramCounter() {
    return programcounter;
}

unsigned short CPU::getOPcode() {
    return opcode;
}

unsigned short CPU::getOPerand() {
    return operand;
}

