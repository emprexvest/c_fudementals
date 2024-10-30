#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 1000

struct employee_t {
    int id;
    int income;
    bool staff;
};

int initialize_employee(struct employee_t *e){
    // Data hiding of numEmployees
    static int numEmployees = 0;
    numEmployees++;

    e->id = numEmployees;
    e->income = 0;
    e->staff = false;

    return numEmployees;
}

int main() {

    // Example of data returned from a database
    int n = 4; 

    // Dynamically set the size memory size based on the n of employee_t
    struct employee_t *employees = malloc(sizeof(struct employee_t)*n);

    // Check if allocation failed
    if(employees == NULL) {
        printf("The allocator failed");
        return -1;
    }

    // Loop through all of the values of employees id
    for(int i = 0; i < n; i++) {    
    int id = initialize_employee(&employees[i]);
    printf("New employee is: %d\n", id);
    }

    // Free memory and set employees to NULL for memory safety
    free(employees);
    employees = NULL;

    return 0;
}