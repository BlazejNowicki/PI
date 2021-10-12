#include <stdio.h>
#include <stdlib.h>

int max_field(int **arr, int n)
{
    int max_size = 0, current_size, flag;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            current_size = 0;
            flag = 1;
            while (flag && i + current_size < n && j + current_size < n)
            {
                for (int k = 0; k <= current_size; k++)
                    if (arr[i + k][j + current_size] == 1)
                        flag = 0;
                for (int k = 0; k < current_size; k++)
                    if (arr[i + current_size][j + k] == 1)
                        flag = 0;
                if(flag)current_size++;
            }
            if (current_size > max_size)
                max_size = current_size;
        }
    return max_size*max_size;
}

int main()
{
    int n;
    scanf("%d", &n);
    int **arr = (int **)malloc((size_t)n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc((size_t)n * sizeof(int));
        for (int j = 0; j < n; ++j)
            scanf("%d", &arr[i][j]);
    }
    printf("%d\n", max_field(arr, n));
}
