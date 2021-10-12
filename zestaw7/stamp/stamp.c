#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int find_optimal(int **T, int **P, int n, int k, int l)
{
    int max_sum = -INT_MAX, cur_sum;
    // dla każdego poprawnego ustawienia P sprawdzamy jaka będzie suma
    for (int i = 0; i < n - k; ++i)
        for (int j = 0; j < n - l; ++j)
        {
            cur_sum = 0;
            // jeśli polu w T odpowiada 1 w P to dodajemy
            for (int x = 0; x < k; ++x)
                for (int y = 0; y < l; ++y)
                {
                    if (P[x][y] > 0)
                        cur_sum += T[i + x][j + y];
                }
            if (cur_sum > max_sum)
                max_sum = cur_sum;
        }
    return max_sum;
}

int main()
{
    int n, k, l;
    scanf("%d %d %d", &n, &k, &l);
    int **T = (int **)malloc((size_t)n * sizeof(int *));
    for (int i = 0; i < n; ++i)
    {
        T[i] = (int *)malloc((size_t)n * sizeof(int));
        for (int j = 0; j < n; ++j)
            scanf("%d", &T[i][j]);
    }
    int **P = (int **)malloc((size_t)k * sizeof(int *));
    for (int i = 0; i < k; ++i)
    {
        P[i] = (int *)malloc((size_t)l * sizeof(int));
        for (int j = 0; j < l; ++j)
            scanf("%d", &P[i][j]);
    }

    printf("%d\n", find_optimal(T, P, n, k, l));

    for (int i = 0; i < n; ++i)
        free(T[i]);
    free(T);
    for (int i = 0; i < k; ++i)
        free(P[i]);
    free(P);
    return 0;
}
