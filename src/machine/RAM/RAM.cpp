//
// Created by timun on 05/10/2018.
//


#include <cstring>
#include "RAM.h"

RAM::RAM(short size) {
    RAM::size = size;
    RAM::data = (char *) calloc(size, 1);
    memset(data, 0x00, size);
}

char RAM::getByte(short loc) {
    return data[loc];
}

void RAM::setByte(short loc, char newdata) {
    data[loc] = newdata;
}

void RAM::loadProg(char *data, short length) {
    for (short i = 0; i < length; i++)
        setByte(i, data[i]);
}

short RAM::getMaxRAM() {
    return size;
}


