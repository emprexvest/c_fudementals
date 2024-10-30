/*
Objective
In this challenge, we will learning the basics of C pointers.
In many problems in C, you will need to have a solid grasp of the pointer syntax and use of pointers to pass data between functions.
*/

/*
Task
This challenge requires you to fix the swap function to properly swap the two values in memory.
*/

/*
Input Format
There are two lines of text that are read in as numbers to be swapped.
*/

/*
Example 1:
Inputs = stdin [50,100]
Output = stdout [100,50]
*/

/*
The function swap takes in the pointer of a and pointer of b.
The pointer of a is defined to the value of b.
The pointer of b is defined to the value of temp.
The pointer of temp is defined as the value of address of a.
*/

/*
temp is set to a
a is set to b
b is set to temp


so if b is set to  
*/

#include <stdio.h>

// something is wrong here :(
int swap( int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int main() {
    int x = 10, y = 20;
    printf("%d %d\n", x, y);
    swap(&x, &y);
    printf("%d %d\n", x, y);
    return 0;
}