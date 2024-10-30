/*
Objective
In this challenge, we will be exercising your knowledge of structs in C. 
Structs are a way of organizing information that is related into one memory location. 
Structs make data that are logically related easier to organize.

In this exercise, we'll create an employee structure and add fields to it that we can access.

*/

/*
Task
Finish the employee struct. Create a character buffer to store the employees name and a variable for his age.

Create an employee named "Steve", 42 years.

*/

#include <stdio.h>
#include <string.h>


struct Employee {
    int age;
    char name[64];

};

int main() {

    struct Employee emp;
    emp.age = 42;
    strcpy(emp.name, "Steve");

    printf("%s, aged %d years\n", emp.name, emp.age);
    return 0;
};