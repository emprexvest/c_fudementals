#include <stdio.h>
#include <stdbool.h>

#define MAX_IDS 1000


struct __attribute__((__packed__)) employee_t  {
    int id;
    char firstName[64];
    char lastName[64];
    float income;
    bool isManager;
};

int main() {
    struct employee_t employees[MAX_IDS];

    printf("Size of employee name: %ld\n", sizeof(struct employee_t) );

    return 0;
};
