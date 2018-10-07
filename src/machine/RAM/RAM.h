//
// Created by timun on 05/10/2018.
//

#ifndef INC_8BIT_RAM_H
#define INC_8BIT_RAM_H

#include <cstdlib>


class RAM {

private:
    char *data;
    short size;

public:
    RAM(short size);

    char getByte(short loc);

    void setByte(short loc, char data);

    void loadProg(char *data, short size);

    short getMaxRAM();
};

#endif //INC_8BIT_RAM_H
