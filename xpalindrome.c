#include <stdio.h>
#include <stdbool.h>

int main() {
    int x;
    int original;
    int reversed = 0;

    printf("Enter an integer: ");
    scanf("%d", &x);

    // Store the original value of x
    original = x;

    // Check that 
    while (x > 0) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }

        if (original == reversed) {
        printf("%d is a palindrome\n", original);
    } else {
        printf("%d is not a palindrome\n", original);
    }

    return 0;
}  