//
// Created by timun on 05/10/2018.
//

#ifndef INC_8BIT_OUTPUT_H
#define INC_8BIT_OUTPUT_H

#include <cstdio>
#include <cstdlib>

#include "../RAM/RAM.h"
#include "../Processor/CPU.h"

class output {
private:
    void printByte(short c);

    void dispRAM(RAM &ram);

    void dispCPU(CPU &cpu);

public:
    void dispSystem(CPU &cpu, RAM &ram);

};


#endif //INC_8BIT_OUTPUT_H
