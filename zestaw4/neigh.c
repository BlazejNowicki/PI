#include <stdio.h>
#include <stdlib.h>

int n;

int **sum_values_in_range(int **arr, int r)
{
    int sum;
    // allocate NxN array and iterate
    int **sums = (int **)malloc((size_t)n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        sums[i] = (int *)malloc((size_t)n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            // for arr[i][j] sum its neighbours(in range r)
            sum = 0;
            for (int k = i - r; k <= i + r; k++)
                for (int l = j - r; l <= j + r; l++)
                    if (k >= 0 && k < n && l >= 0 && l < n)
                        sum += arr[k][l];
            sums[i][j] = sum;
        }
    }
    return sums;
}

int main()
{
    int k;
    scanf("%d %d", &n, &k);

    // create NxN array
    int **arr = (int **)malloc((size_t)n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc((size_t)n * sizeof(int));
        for (int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);
    }

    // find specified array
    int **sums = sum_values_in_range(arr, k);

    // print result
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", sums[i][j]);
        printf("\n");
    }
    return 0;
}