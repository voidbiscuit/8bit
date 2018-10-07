//
// Created by timun on 05/10/2018.
//

#ifndef INC_8BIT_OUTPUT_H
#define INC_8BIT_OUTPUT_H

#include <cstdio>
#include <cstdlib>

#include "../RAM/RAM.h"

class output {
public:
    char *getByte(char c);

    void printByte(char c);

    void dispRAM(RAM &ram);
};


#endif //INC_8BIT_OUTPUT_H
