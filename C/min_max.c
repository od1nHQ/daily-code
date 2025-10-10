#include <stdio.h>
#include <stdlib.h> // For rand(), srand()
#include <time.h>   // For time()
#define N 10        // Define the array size

int main(void)
{
    int MAS[N], min, max, temp;

    srand(time(NULL)); // Initialize the random number generator using the current time

    // Generate the array with random numbers and print each value
    for (int i = 0; i < N; i++)
    {
        MAS[i] = rand() % 100; // Random number between 0 and 99
        printf("MAS[%d] = %d\n", i, MAS[i]);
    }

    max = min = MAS[0]; // Initialize max and min with the first element of the array
    
    // Find the maximum and minimum values in the array
    for (int i = 1; i < N; i++)
    {
        if (max < MAS[i]) max = MAS[i]; // Update max if a larger number is found
        if (min > MAS[i]) min = MAS[i]; // Update min if a smaller number is found
    }

    printf("\nMax = %d\nMin = %d\n", max, min); // Print the max and min values

    // Sort the array using the bubble sort algorithm
    for (int i = 0; i < N - 1; i++) 
    {
        for (int j = i + 1; j < N; j++) 
        {
            // Swap elements if they are in the wrong order
            if (MAS[i] > MAS[j]) 
            {
                temp = MAS[i];
                MAS[i] = MAS[j];
                MAS[j] = temp;
            }
        }
    }

    // Print the sorted array
    printf("\nSorted array:\n");
    for (int i = 0; i < N; i++)
    {
        printf("MAS[%d] = %d\n", i, MAS[i]); // Print each sorted value
    }

    return 0;
}
