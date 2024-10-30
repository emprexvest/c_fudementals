// Task
// Create a copy of the string "hehe" using hex syntax, and ensure that they are the same strings!
//


#include <stdio.h>
#include <string.h>

int main() {
    char *myPointerString = "hehe";
    char myHexString[] = {'h', 'e', 'h', 'e', 0};

        if (!strcmp(myPointerString, myHexString)) {
            printf("Yay!\n");
        } else {
            printf("Nay!\n");
            }

    return 0;
}