//
// Created by timun on 05/10/2018.
//


#include "RAM.h"

#include <array>

RAM::RAM(short size) {
    RAM::size = size;
    RAM::data = (char *) calloc(size, 1);
}

char RAM::getByte(short loc) {
    return data[loc];
}

void RAM::setByte(short loc, char newdata) {
    data[loc] = newdata;
}

short RAM::getMaxRAM() {
    return size;
}


