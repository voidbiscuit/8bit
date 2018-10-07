//
// Created by timun on 07/10/2018.
//


#include "CPU.h"


// Fetch Decode Execute Cycle

CPU::CPU() {

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
    opcode = (instructionregister & 0xF0) >> 0x04;
    operand = instructionregister & 0x0F;
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
            ADD(operand);
            break;
        case 0x05 :
            SUB(operand);
            break;
        case 0x06 :
            MUL(operand);
            break;
        case 0x07 :
            DIV(operand);
            break;
        case 0x08 :
            MOD(operand);
            break;


        default:
            printf("No instr");
            break;
    }

}


void CPU::HLT(short operand) {
    setFlags(0x01);
}

void CPU::NOP(short operand) {

    setFlags(0x00);
}

void CPU::JMP(short operand) {
    setProgramcounter(operand);
    setFlags(0x00);
}

void CPU::MOV(short operand) {
    setFlags(0x00);
}

void CPU::ADD(short operand) {
    setRegister_a(getRegister_a() + operand);
    setFlags(0x00);
}

void CPU::SUB(short operand) {
    setRegister_a(getRegister_a() - operand);
    setFlags(0x00);
}

void CPU::MUL(short operand) {
    setRegister_a(getRegister_a() * operand);
    setFlags(0x00);
}

void CPU::DIV(short operand) {
    setRegister_a(getRegister_a() / operand);
    setFlags(0x00);
}

void CPU::MOD(short operand) {
    setRegister_a(getRegister_a() % operand);
    setFlags(0x00);
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


