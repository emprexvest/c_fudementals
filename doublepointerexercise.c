/*
Objective
In this challenge, we will learn the basics of double C pointers.
In many problems in C, you will need to have a solid grasp of the pointer syntax and use of pointers to pass data between functions.
Double pointers are used in code that requires a memory address to be updated by another function.
This is common when you are passing around a buffer that may need to be resized by a called function, or a structure that needs to be populated.
*/

/*
Task
This challenge requires you to fix the code to the right.
The function takes a pointer to a pointer. Write a valid heap allocated memory address to that parameter.
Before the function returns, write the number 10 to that location.
*/



#include <stdio.h>
#include <stdlib.h>

/**
Correct this code to update the value in the heap 
to 10 before giving the address to main
**/

int foo(int **ptr) {
    int value = 10;
    *ptr = (int *)malloc(sizeof(int));

    if(ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return -1;
    }

    **ptr = value;
}

int main() {
    int *ptr = NULL;
    if(0 != foo(&ptr)) {
        return -1;
    }

    if(ptr != NULL) {
        printf("Value: %d\n", *ptr);
        free(ptr);
    }

    return 0;
}