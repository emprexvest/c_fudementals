// Task
// Build a basic function to return x + y = z
// Call the main function inside the main method
// Syntax for a function return_type name(parameters) { code block };
// Always clear and simple function names
// Functions should perform one task at a time

#include <stdio.h>

int add(int x, int y) {

    int z = x + y;
    return z;
}

int main() {

    int callAddFuntion = add(1, 2);

    printf("%d\n", callAddFuntion);
    return 0;
}
