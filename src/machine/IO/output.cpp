//
// Created by timun on 05/10/2018.
//

#include "output.h"

void output::printByte(short c) {
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

void output::dispRAM(RAM &ram) {
    short columns = 8;
    printf("\n\n ADDR DATA");
    for (short reg = 0; reg < ram.getMaxRAM(); reg++) {
        if (reg % columns == 0) printf("\n%#*x", 5, reg);
        printf(" ");
        printByte(ram.getByte(reg));
    }
}

void output::dispCPU(CPU &cpu) {
    // Flow
    printf("\n\nProgram Counter      : ");
    printByte(cpu.getProgramcounter());
    printf("\nInstruction Register : ");
    printByte(cpu.getInstructionregister());
    printf("\n\n");
    // Data
    printf(" A : ");
    printByte(cpu.getRegister_a());
    printf(" B : ");
    printByte(cpu.getRegister_b());
    printf(" C : ");
    printByte(cpu.getRegister_c());
    printf(" D : ");
    printByte(cpu.getRegister_d());
}

void output::dispSystem(CPU &cpu, RAM &ram) {
    printf("\n\n\n");
    dispCPU(cpu);
    dispRAM(ram);
}