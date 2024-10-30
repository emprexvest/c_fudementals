/*
Objective
Learn about string operations and binary arithmetic in C.
*/

/*
Task
Given a number, x, return whether or not that number is a palindrome. Return the result as a bool, in the form true or false.

A palindrome is defined as a string of characters that is the same string when reversed.

For example: 121 is a palindrome, while 123 is not.

Try to solve this without converting the number to a string.

*/

/*
Input format
x will be a decimal number served as a 32-bit signed integer value.
*/

#include <stdio.h>
#include <stdbool.h>


int reverseBytes(int num) {
    int reversed = 0;
    int size = sizeof(num) * 8;

    for (int i = 0; i < size; i++) {
        reversed <<= 1;
        reversed |= (num >> i) & 1;
    }
    return reversed;

};



int main() {

    int x;

    printf("Please input a number to check if it is a palindrome: ");
    scanf("%d", &x);

    int reversedNum = reverseBytes(x);
    
    if(x == reversedNum) {
        printf("%d is a palindrome\n", x);
    } else {
        printf("%d is not a palindrome \n", x);
    }

    return 0;
}