// Task
// Build a conditional statement that evaluates the input temp
// If greater than 70 degrees it is hot
// Else if less than 70 and greater than 30 it is just right
// Else less than 30 it is cold

#include <stdio.h>

    int main() {

        int temp;
        scanf("%d", &temp);

        if (temp > 70) {
            printf("It is too hot!\n");
        } else if (temp >= 30 && temp <= 70) {
            printf("It is just right!\n");
        } else {
            printf("It is too cold!\n");
        }

        return 0;
    }
