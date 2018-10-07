//
// Created by timun on 07/10/2018.
//

#ifndef INC_8BIT_INSTRUCTIONS_H
#define INC_8BIT_INSTRUCTIONS_H


#include "../../RAM/RAM.h"
#include "../CPU.h"

class instructions {
public:
    instructions();

    void HLT(CPU &cpu, short operand);

    void NOP(CPU &cpu, short operand);

    void JMP(CPU &cpu, short operand);

    void MOV(CPU &cpu, short operand);

    void ADD(CPU &cpu, short operand);

    void SUB(CPU &cpu, short operand);

    void MUL(CPU &cpu, short operand);

    void DIV(CPU &cpu, short operand);

};


#endif //INC_8BIT_INSTRUCTIONS_H
