#include <stdio.h>

int main(void) {
    long int x, r;  // x - the entered number, r - digit of the number
    long int n = 0;  // n - reversed number
    int isNegative = 0;  // Flag to indicate whether the number is negative

    // Prompt the user to enter an integer
    printf("\nEnter an integer: ");
    scanf("%ld", &x);  // Using standard scanf for input

    // Check if the number is negative
    if (x < 0) {
        isNegative = 1;  // Set the flag if the number is negative
        x = -x;  // Make the number positive for easier digit manipulation
    }

    // Reverse the digits of the number
    do {
        r = x % 10;      // Get the last digit
        x = x / 10;      // Remove the last digit from the number
        n = n * 10 + r;  // Add the digit to the new reversed number
    } while (x != 0);  // Continue until all digits are processed

    // If the number was negative, add the minus sign back
    if (isNegative) {
        n = -n;
    }

    // Output the reversed number
    printf("\nReversed digit number: %ld\n", n);

    return 0;
}
