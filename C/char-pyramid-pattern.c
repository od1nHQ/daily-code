#include <stdio.h>

int main() {
    char temp;

    // Prompt the user to enter a character for the pyramid limit (e.g., 'A' to 'Z')
    printf("Enter a character for the pyramid limit (e.g., 'A' to 'Z'): ");
    scanf("%c", &temp);

    // Check if the input is within the valid range ('A' to 'Z')
    if (temp < 'A' || temp > 'Z') {
        printf("Invalid input. Please enter a letter between 'A' and 'Z'.\n");
        return 1; // Exit the program with an error if the input is invalid
    }

    // Generate the pyramid
    for (char pt = 'A'; pt <= temp; pt++) {
        printf("\n");

        // Print spaces for alignment
        for (char c = pt; c <= temp; c++) 
            printf(" ");

        // Print characters from 'A' to the current character (left side of the pyramid)
        for (char c = 'A'; c <= pt; c++) 
            printf("%c", c);

        // Print characters from the current character-1 back down to 'A' (right side of the pyramid)
        for (char c = pt - 1; c >= 'A'; c--) 
            printf("%c", c);
    }

    return 0;
}
