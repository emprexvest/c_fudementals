#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_EMPLOYEES 1000

struct employee_t {
    int id;
    int income;
    bool staff;
};

void initialize_employee(struct employee_t *e) {
    e->id = 0;
    e->income = 0;
    e->staff = false;

    return;
}

int main() {

    // Example of value returned from a database
    int n = 4;

    // Dynamically allocating the size of memory based on the n of employees returned from the database
    struct employee_t *employees = malloc(sizeof(struct employee_t)*n);

    // Check if employees is not null and return error if the allocator failed
    if(employees == NULL) {
        printf("The allocator failed\n");
        return -1;
    }

    initialize_employee(&employees[0]);

    printf("%d\n", employees[0].income);

    // Free up memory and set employees to NULL for memory safety
    free(employees);
    employees = NULL;

    return 0;
}