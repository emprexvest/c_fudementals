#include <stdio.h>

union myUnion_u {
    int i;
    char c;
    short s;
};


int main () {

    union myUnion_u u;
    u.i =208186;

    printf("%d\n", u.i);

    return 0;
}