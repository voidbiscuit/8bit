//
// Created by timun on 05/10/2018.
//
#include <cstring>
#include "RAM.h"

RAM::RAM() {
    RAM::data = (unsigned char *) calloc(maxaddr, 1);
    clearRAM();
}

void RAM::clearRAM() {
    memset(data, 0x00, maxaddr + 1);
}

unsigned char RAM::getByte(unsigned short addr) {
    return data[addr];
}

void RAM::setByte(unsigned short addr, unsigned char newdata) {
    data[addr] = newdata;
}

void RAM::loadProg(unsigned char *data) {
    clearRAM();
    for (unsigned short i = 0; i <= maxaddr; i++) {
        setByte(i, data[i]);
    }
}

unsigned short RAM::getMaxAddr() {
    return maxaddr;
}


