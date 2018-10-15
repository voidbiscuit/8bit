//
// Created by timun on 05/10/2018.
//

#ifndef INC_8BIT_RAM_H
#define INC_8BIT_RAM_H

#include <cstdlib>
#include <cstdint>


class RAM {

private:
    unsigned char *data;
    const unsigned short maxaddr = 255;

public:
    RAM();

    void clearRAM();

    unsigned char getByte(unsigned short addr);

    void setByte(unsigned short addr, unsigned char data);

    void loadProg(unsigned char *data);

    unsigned short getMaxAddr();
};

#endif //INC_8BIT_RAM_H
