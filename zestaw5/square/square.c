#define N_MAX 200
#include <stdio.h>
#include <stdlib.h>

void square(int arr[N_MAX][N_MAX], int centers[N_MAX*N_MAX])
{
    int n, k, sum, size, counter = 0;
    scanf(" %d %d", &n, &k);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf(" %d", &arr[i][j]);

    for (int i = 1; i < n - 1; ++i)
        for (int j = 1; j < n - 1; ++j)
        {
            size = 1;
            while (0 <= j - size && j + size < n && 0 <= i - size && i + size < n)
            {
                sum = 0;
                for (int m = -size; m < size; ++m)
                {
                    sum += arr[i + size][j - m] +
                           arr[i - size][j + m] +
                           arr[i + m][j + size] +
                           arr[i - m][j - size];
                }
                if (sum == k)
                {
                    centers[counter] = N_MAX * i + j;
                    counter++;
                }
                size += 1;
            }
        }

    printf("%d\n", counter);
    for (int i = 0; i < counter; i++)
        printf("%d %d\n", centers[i] / N_MAX, centers[i] % N_MAX);
}

int main()
{
    int arr[N_MAX][N_MAX];
    int centers[N_MAX * N_MAX];

    square(arr, centers);
    return 0;
}
