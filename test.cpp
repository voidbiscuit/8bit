//
// Created by timun on 07/10/2018.
//

#include <cstdio>
#include "test.h"

test::test() {

}

void test::testPointers() {
    int x = 4;
    printf("\nValue of X %d", x);
    x = addtwo(x);
    printf("\nValue of X %d", x);
    addtwoptr(x);
    printf("\nValue of X %d", x);


}

int test::addtwo(int x) {
    x += 2;
    return x;
}

void test::addtwoptr(int &x) {
    x += 2;
}