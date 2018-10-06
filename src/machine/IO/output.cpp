//
// Created by timun on 05/10/2018.
//

#include "output.h"
#include <cstdio>
#include <cstdlib>

char *output::getByte(char c) {
    char ret[8] = {
            c >> 7 & true ? '1' : '0',
            c >> 6 & true ? '1' : '0',
            c >> 5 & true ? '1' : '0',
            c >> 4 & true ? '1' : '0',
            c >> 3 & true ? '1' : '0',
            c >> 2 & true ? '1' : '0',
            c >> 1 & true ? '1' : '0',
            c >> 0 & true ? '1' : '0'
    };
    return ret;
}

void output::printByte(char c) {
    printf(
            // Format
            "%c%c%c%c%c%c%c%c",
            // Data AND Map
            c >> 7 & true ? '1' : '0',
            c >> 6 & true ? '1' : '0',
            c >> 5 & true ? '1' : '0',
            c >> 4 & true ? '1' : '0',
            c >> 3 & true ? '1' : '0',
            c >> 2 & true ? '1' : '0',
            c >> 1 & true ? '1' : '0',
            c >> 0 & true ? '1' : '0'
    );
}

void output::writeBytesAllMethods(char c) {
    // Original
    printf(
            // Format
            "\n%c%c%c%c%c%c%c%c",
            // Data AND Map
            c & (char) 128 ? '1' : '0',
            c & (char) 64 ? '1' : '0',
            c & (char) 32 ? '1' : '0',
            c & (char) 16 ? '1' : '0',
            c & (char) 8 ? '1' : '0',
            c & (char) 4 ? '1' : '0',
            c & (char) 2 ? '1' : '0',
            c & (char) 1 ? '1' : '0'
    );
    // Bitshift
    printf(
            // Format
            "\n%c%c%c%c%c%c%c%c",
            // Data AND Map
            c >> 7 & true ? '1' : '0',
            c >> 6 & true ? '1' : '0',
            c >> 5 & true ? '1' : '0',
            c >> 4 & true ? '1' : '0',
            c >> 3 & true ? '1' : '0',
            c >> 2 & true ? '1' : '0',
            c >> 1 & true ? '1' : '0',
            c >> 0 & true ? '1' : '0'
    );
    // Shift in loop
    printf("\n");
    //for (short i = 128; i > false; i >>= true) printf("%c", c & i ? '1' : '0');
}