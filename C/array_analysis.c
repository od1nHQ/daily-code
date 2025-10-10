#include <stdio.h>
#include <stdlib.h>  // For rand(), srand()
#include <time.h>    // For time()

#define N 10         // Array size

int main(void)
{
    int MAS[N], min, max, temp;
    int L = -1, R = -1, Lc = -1, Rc = -1;
    int dist = 0;
    int FLAG = 0;

    // Additional array for positive numbers (subset of the sorted array)
    int POS[N];
    int pos_count = 0;

    srand(time(NULL)); // Initialize the random number generator with the current time

    // -------------------------------------------------------------
    // 1. Generate the array with random numbers in range [-50, 50]
    // -------------------------------------------------------------
    printf("Initial array:\n");
    for (int i = 0; i < N; i++)
    {
        MAS[i] = rand() % 101 - 50;
        printf("MAS[%d] = %d\n", i, MAS[i]);
    }

    // -------------------------------------------------------------
    // 2. Find the longest segment of positive numbers
    // -------------------------------------------------------------
    for (int i = 0; i < N; i++)
    {
        if (MAS[i] > 0 && FLAG == 0)
        {
            L = i;       // Start of positive segment
            FLAG = 1;
        }

        if ((MAS[i] <= 0 || i == N - 1) && FLAG == 1)
        {
            // If we reach the end or hit a non-positive number
            R = (MAS[i] <= 0) ? (i - 1) : i;
            FLAG = 0;

            // Save the longest segment boundaries
            if (R - L + 1 > dist)
            {
                dist = R - L + 1;
                Lc = L;
                Rc = R;
            }
        }
    }

    if (dist > 0)
    {
        printf("\nLongest segment of positive numbers:\n");
        printf("Start index: %d, End index: %d\n", Lc, Rc);
        printf("Length: %d\n", dist);
    }
    else
    {
        printf("\nNo positive segment found.\n");
    }

    // -------------------------------------------------------------
    // 3. Find minimum and maximum values in the array
    // -------------------------------------------------------------
    max = min = MAS[0];
    for (int i = 1; i < N; i++)
    {
        if (max < MAS[i]) max = MAS[i];
        if (min > MAS[i]) min = MAS[i];
    }

    printf("\nMax = %d\nMin = %d\n", max, min);

    // -------------------------------------------------------------
    // 4. Sort the array using a simple bubble sort algorithm
    // -------------------------------------------------------------
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (MAS[i] > MAS[j])
            {
                temp = MAS[i];
                MAS[i] = MAS[j];
                MAS[j] = temp;
            }
        }
    }

    printf("\nSorted array:\n");
    for (int i = 0; i < N; i++)
    {
        printf("MAS[%d] = %d\n", i, MAS[i]);
    }

    // -------------------------------------------------------------
    // 5. Reverse the longest positive segment directly in MAS
    // -------------------------------------------------------------
    if (Lc != -1 && Rc != -1)
    {
        for (int i = 0; i < (Rc - Lc + 1) / 2; i++)
        {
            temp = MAS[Lc + i];
            MAS[Lc + i] = MAS[Rc - i];
            MAS[Rc - i] = temp;
        }
    }

    // -------------------------------------------------------------
    // 6. Extract only positive numbers into a separate array POS[]
    // -------------------------------------------------------------
    for (int i = 0; i < N; i++)
    {
        if (MAS[i] > 0)
        {
            POS[pos_count] = MAS[i];
            pos_count++;
        }
    }

    // -------------------------------------------------------------
    // 7. Print and reverse the array of positive numbers
    // -------------------------------------------------------------
    if (pos_count > 0)
    {
        printf("\nPositive numbers array:\n");
        for (int i = 0; i < pos_count; i++)
        {
            printf("POS[%d] = %d\n", i, POS[i]);
        }
        // Reverse the positive numbers array
        for (int i = 0; i < pos_count / 2; i++)
        {
            temp = POS[i];
            POS[i] = POS[pos_count - 1 - i];
            POS[pos_count - 1 - i] = temp;
        }

        printf("\nReversed positive numbers array:\n");
        for (int i = 0; i < pos_count; i++)
        {
            printf("POS[%d] = %d\n", i, POS[i]);
        }
    }
    else
    {
        print("\nNo positive numbers found in the array.\n");
    }

    return 0;
}
