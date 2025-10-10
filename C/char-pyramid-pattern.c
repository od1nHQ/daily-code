#include <stdio.h>

int main() {
    char pt = 'A', temp;
    int choice;

    // Prompt the user to choose the pyramid type
    printf("Choose the pyramid type:\n");
    printf("1. For-loop pyramid\n");
    printf("2. While-loop pyramid\n");
    printf("Enter your choice (1 or 2): ");
    scanf_s("%d", &choice);

    // Prompt the user to input the upper limit for the pyramid (A-Z)
    printf("Enter a character for the pyramid limit (e.g., 'A' to 'Z'): ");
    scanf_s(" %c", &temp, 1);  // Input the limit character

    // Input validation: Ensure the character is within the range A-Z
    if (temp < 'A' || temp > 'Z') {
        printf("Invalid input. Please enter a letter between 'A' and 'Z'.\n");
        return 1;  // Exit the program with an error
    }

    switch (choice) {
        case 1:  // For-loop pyramid
            printf("\nGenerating pyramid with for-loop:\n");
            for (pt = 'A'; pt <= temp; pt++) {
                printf("\n");

                // Print spaces for alignment
                for (char c = pt; c <= temp; c++) 
                    printf(" ");

                // Print characters from 'A' to the current character (left side)
                for (char c = 'A'; c <= pt; c++) 
                    printf("%c", c);

                // Print characters from current character-1 back down to 'A' (right side)
                for (char c = pt - 1; c >= 'A'; c--) 
                    printf("%c", c);
            }
            break;

        case 2:  // While-loop pyramid
            printf("\nGenerating pyramid with while-loop:\n");
            while (pt <= temp) {
                printf("\n");

                // Print spaces for alignment
                char c = pt;
                while (c <= temp) {
                    printf(" ");
                    c++;
                }

                // Print characters from 'A' to the current character (left side)
                c = 'A';
                while (c <= pt) {
                    printf("%c", c);
                    c++;
                }

                // Print characters from current character-1 back down to 'A' (right side)
                c = pt - 1;
                while (c >= 'A') {
                    printf("%c", c);
                    c--;
                }

                pt++;  // Move to the next row
            }
            break;

        default:
            printf("Invalid choice! Please choose 1 or 2.\n");
            return 1;  // Exit the program with an error if the choice is invalid
    }

    return 0;
}
