#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, c, step;
    scanf("%d", &n);
    // alocate NxN dynamic array
    int **arr = (int **)malloc((size_t)n * sizeof(int *));
    for (int i = 0; i < n; ++i)
        arr[i] = (int *)malloc((size_t)n * sizeof(int));

    // fill in spiral 
    c = 1;
    for (int level = 0; level < n / 2; ++level)
    {
        for (int i = 0; i < n - 2 * level - 1; ++i)
        {
            step = n - 2 * level - 1;
            arr[level][level + i] = c + i;
            arr[level + i][n - 1 - level] = c + step + i;
            arr[n - 1 - level][n - 1 - i - level] = c + 2 * step + i;
            arr[n - 1 - i - level][level] = c + 3 * step + i;
        }
        c += 4 * step;
    }

    // add missing center in odd-sized arrays
    if (n % 2 == 1)
        arr[n % 2 + 1][n % 2 + 1] = c;

    // print array
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            printf("%d\t", arr[i][j]);
        printf("\n");
    }
    //free allocated space
    for(int i=0; i<n; ++i)
        free(arr[i]);
    free(arr);
    return 0;
}
