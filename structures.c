#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_EMPLOYEES 1000

struct employee_t {
        int id;
        char firstName[50];
        char lastName[50];
        float income;
        bool isManger;
    };

int main() {

    struct employee_t Richard;
    Richard.id = 1986;
    strcpy(Richard.firstName, "Richard");
    strcpy(Richard.lastName, "Vest");
    Richard.income = 100.00;
    Richard.isManger = false;
    

    printf("%s\n", Richard.firstName);
    printf("%s\n", Richard.lastName);

    return 0;
}
