#include <stdio.h>
#include <stdlib.h> // for rand(), srand()
#include <time.h>   // for time()
#define N 10

int main(void)
{
    int MAS[N], min, max;

    srand(time(NULL)); // initialize random number generator

    for (int i = 0; i < N; i++)
    {
        MAS[i] = rand() % 100;
        printf("MAS[%d] = %d\n", i, MAS[i]);
    }

    max = min = MAS[0];

    for (int i = 1; i < N; i++)
    {
        if (max < MAS[i]) max = MAS[i];
        if (min > MAS[i]) min = MAS[i];
    }

    printf("\nMax = %d\nMin = %d\n", max, min);

    return 0;
}
