// #include <stdio.h>

// int reverseBytes(int num) {
//     int reversed = 0;
//     int original_sign = num >> 31; // Extract the sign bit
//     // int size = sizeof(num) * 8; // Determine the number of bits in the integer
//     // int sign = num < 0 ? 1 : 0; // Check if the number is negative

//     for (int i = 0; i < 31; i++) {
//         reversed <<= 1;
//         reversed |= (num >> i) & 1;
//     }

//     // Handle negative numbers:
//     if (original_sign) {
//         reversed = -reversed;
//     }

//     return reversed;
// }

// int main() {
//     int num;

//     printf("Enter an integer: ");
//     scanf("%d", &num);

//     int reversedNum = reverseBytes(num);

//     if (num == reversedNum) {
//         printf("%d is a palindrome in binary\n", num);
//     } else {
//         printf("%d is not a palindrome in binary\n", num);
//     }

//     return 0;
// }

#include <stdio.h>

int main() {
    int num, original, reversed = 0, digit, count = 0;
    

    printf("Enter an integer: ");
    scanf("%d", &num);

    original = num;

    // Count the number of digits
    while (num > 0) {
        num /= 10;
        count++;
    }

    int digits[count];
    num = original; // Restore the original value

    // Extract digits and store them in the array
    for (int i = count - 1; i >= 0; i--) {
        digits[i] = num % 10;
        num /= 10;
    }

    // Check for palindrome
    for (int i = 0, j = count - 1; i < j; i++, j--) {
        if (digits[i] != digits[j]) {
            printf("%d is not a palindrome\n", original);
            return 0;
        }
    }

    printf("%d is a palindrome\n", original);

    return 0;
}