//
// Created by timun on 07/10/2018.
//

#ifndef INC_8BIT_INSTRUCTIONS_H
#define INC_8BIT_INSTRUCTIONS_H


#include "../../RAM/RAM.h"
#include "../CPU.h"

class instructions {

public:
    void HLT(RAM &ram, CPU &cpu);

    void NOP(RAM &ram, CPU &cpu);

    void JMP(RAM &ram, CPU &cpu);

    void MOV(RAM &ram, CPU &cpu);

    void ADD(RAM &ram, CPU &cpu);

    void SUB(RAM &ram, CPU &cpu);

    void MUL(RAM &ram, CPU &cpu);

    void DIV(RAM &ram, CPU &cpu);

};


#endif //INC_8BIT_INSTRUCTIONS_H
