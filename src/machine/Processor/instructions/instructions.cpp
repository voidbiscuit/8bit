//
// Created by timun on 07/10/2018.
//

#include "instructions.h"

instructions::instructions() {

}

void instructions::HLT(CPU &cpu, short operand) {

    cpu.setFlags(0x01);
}

void instructions::NOP(CPU &cpu, short operand) {

    cpu.setFlags(0x00);
}

void instructions::JMP(CPU &cpu, short operand) {
    cpu.setProgramcounter(operand);
    cpu.setFlags(0x00);
}

void instructions::MOV(CPU &cpu, short operand) {

    cpu.setFlags(0x00);
}

void instructions::ADD(CPU &cpu, short operand) {

    cpu.setFlags(0x00);
}

void instructions::SUB(CPU &cpu, short operand) {

    cpu.setFlags(0x00);
}

void instructions::MUL(CPU &cpu, short operand) {

    cpu.setFlags(0x00);
}

void instructions::DIV(CPU &cpu, short operand) {

    cpu.setFlags(0x00);
}