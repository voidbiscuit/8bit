//
// Created by timun on 05/10/2018.
//

#include <cstring>
#include <cwchar>
#include "output.h"

unsigned char output::retHex(unsigned short c) {
    switch (c & 0x0F) {
        case 0x00:
            return '0';
        case 0x01:
            return '1';
        case 0x02:
            return '2';
        case 0x03:
            return '3';
        case 0x04:
            return '4';
        case 0x05:
            return '5';
        case 0x06:
            return '6';
        case 0x07:
            return '7';
        case 0x08:
            return '8';
        case 0x09:
            return '9';
        case 0x0A:
            return 'A';
        case 0x0B:
            return 'B';
        case 0x0C:
            return 'C';
        case 0x0D:
            return 'D';
        case 0x0E:
            return 'E';
        case 0x0F:
            return 'F';
    }
    return '0';
}


void output::dispSystem(CPU &cpu, RAM &ram) {
    // CPU DISP
    printf(
            //Format
            "\n\n"
            "\n|-------------------------------------------------------------------CPU--|"
            "\n| [Program Counter ]  0x%c%c   [OPcode]  0x%c%c [OPerand]  0x%c%c              |"
            "\n| [Current Register]  0x%c%c                                               |"
            "\n| [0]0x%c%c [1]0x%c%c [2]0x%c%c [3]0x%c%c [4]0x%c%c [5]0x%c%c [6]0x%c%c [7]0x%c%c        |"
            "\n| [8]0x%c%c [9]0x%c%c [A]0x%c%c [B]0x%c%c [C]0x%c%c [D]0x%c%c [E]0x%c%c [F]0x%c%c        |"
            "\n|------------------------------------------------------------------------|",
            //Data
            retHex(cpu.getProgramCounter() >> 4), retHex(cpu.getProgramCounter()),
            retHex(cpu.getOPcode() >> 4), retHex(cpu.getOPcode()),
            retHex(cpu.getOPerand() >> 4), retHex(cpu.getOPerand()),
            retHex(cpu.getCurrentReg() >> 4), retHex((cpu.getCurrentReg())),
            retHex(cpu.getRegisters(0x00) >> 4), retHex(cpu.getRegisters(0x00)),
            retHex(cpu.getRegisters(0x01) >> 4), retHex(cpu.getRegisters(0x01)),
            retHex(cpu.getRegisters(0x02) >> 4), retHex(cpu.getRegisters(0x02)),
            retHex(cpu.getRegisters(0x03) >> 4), retHex(cpu.getRegisters(0x03)),
            retHex(cpu.getRegisters(0x04) >> 4), retHex(cpu.getRegisters(0x04)),
            retHex(cpu.getRegisters(0x05) >> 4), retHex(cpu.getRegisters(0x05)),
            retHex(cpu.getRegisters(0x06) >> 4), retHex(cpu.getRegisters(0x06)),
            retHex(cpu.getRegisters(0x07) >> 4), retHex(cpu.getRegisters(0x07)),
            retHex(cpu.getRegisters(0x08) >> 4), retHex(cpu.getRegisters(0x08)),
            retHex(cpu.getRegisters(0x09) >> 4), retHex(cpu.getRegisters(0x09)),
            retHex(cpu.getRegisters(0x0A) >> 4), retHex(cpu.getRegisters(0x0A)),
            retHex(cpu.getRegisters(0x0B) >> 4), retHex(cpu.getRegisters(0x0B)),
            retHex(cpu.getRegisters(0x0C) >> 4), retHex(cpu.getRegisters(0x0C)),
            retHex(cpu.getRegisters(0x0D) >> 4), retHex(cpu.getRegisters(0x0D)),
            retHex(cpu.getRegisters(0x0E) >> 4), retHex(cpu.getRegisters(0x0E)),
            retHex(cpu.getRegisters(0x0F) >> 4), retHex(cpu.getRegisters(0x0F))
    );

    // Data Declare
    printf("\n|-------------------------------------------------------------------RAM--|");
    for (unsigned short lineno = 0; lineno < 16; lineno++) {
        printf("\n| 0x%c%c |   ", retHex(lineno * columns >> 4), retHex(lineno * columns));
        for (unsigned short col = 0; col < columns; col++) {
            if (col % 2 == 0)printf("%c", lineno * columns + col == cpu.getProgramCounter() ? '>' : ' ');
            printf(
                    "%c%c",
                    retHex(ram.getByte(lineno * columns + col) >> 4),
                    retHex(ram.getByte(lineno * columns + col))
            );
        }
        for (unsigned short i = 0; i < 22; i++) printf(" ");
        printf("|");
    }

    printf("\n|------------------------------------------------------------------------|");
}