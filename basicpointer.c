// Task Create a basic pointer within the main function

// Objective print out the value of x and the value of pX reference in the stack

#include <stdio.h>

int main() {

    int x = 3;
    int *pX = &x;

    printf("%d\n", x);
    printf("%p\n", pX);


    return 0;
}