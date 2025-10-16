#include <stdio.h>
#include <stdlib.h>  
#include <time.h>  

#define N 100

int main(void)
{
    int MAS[N], max, min, temp;
    int L = 0, R = 0, lc=0, rc=0;
    int FLAG = 0;


    //srand(time(NULL));


    printf_s("Initial array:\n");
    for (int i = 0; i < N; i++)
    {
        MAS[i] = rand() % 101 - 50;
        printf(" %4d", MAS[i]);
    }
    printf("\nSorted array:\n\n");

    max = min = MAS[0];

    for (int i = 0; i < N; i++)
    {
        if (MAS[i] < 0 && FLAG == 0)
        {
            L = i;
            FLAG = 1;
        }

        if ((MAS[i] >= 0 || i == N - 1) && FLAG == 1)
        {
            R = (MAS[i] >= 0) ? (i - 1) : i;
            FLAG = 0;
        }

        for (int i = L; i <= R; i++) 
        {
            if (MAS[i] > MAS[max]) max=j;
            
            if (MAS[i] < MAS[max]) min=j;
        }

                temp = MAS[i];
                MAS[i] = MAS[R];
                MAS[R] = temp;
      
    }

    for (int i = 0; i < N; i++)
    {
        printf_s(" %4d",MAS[i]);
    }

    //max = min = MAS[0];

    /*printf("\nSorted array:\n\n");
    
    for (int i = 0; i < N; i++)
    {
        printf_s("MAS[%d] = %d\n", i, MAS[i]);
    }*/
    return 0;
}
