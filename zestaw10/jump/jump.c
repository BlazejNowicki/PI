#include <stdio.h>
#include <stdlib.h>
// #include <time.h>

#define MAX_SIZE 100000

void test_case()
{
    int arr[MAX_SIZE * 2 + 1];
    for (int i = 0; i < MAX_SIZE * 2 + 1; ++i)
    {
        arr[i] = 0;
    }

    int n, p, m, t;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d %d", &p, &m);
        arr[MAX_SIZE + p] = m;
    }

    t = MAX_SIZE * 2;
    while (t > 1)
    {
        if (arr[t] == 0 || (arr[t] == 1 && arr[t - 1] == 0))
        {
            --t;
        }
        else if (arr[t] > 2 && arr[t - 1] == 0)
        {
            if (arr[t + 2] > 0)
            {
                arr[t] -= 2;
                ++arr[t - 2];
                ++arr[t + 3];
                --arr[t + 2];
                if (arr[t + 4] > 0)
                {
                    t += 4;
                }
                else
                {
                    t += 3;
                }
            }
            else
            {
                arr[t] -= 3;
                ++arr[t - 2];
                ++arr[t + 2];
                if (arr[t + 3] > 0)
                {
                    t += 3;
                }
                else
                {
                    t += 2;
                }
            }
        }
        else if (arr[t] > 0 && arr[t - 1] > 0)
        {
            --arr[t - 1];
            --arr[t];
            ++arr[t + 1];
            if (arr[t + 2] > 0)
                t += 2;
            else
                t += 1;
        }
        else if (arr[t] > 1 && arr[t - 1] == 0)
        {
            arr[t] -= 2;
            ++arr[t - 2];
            ++arr[t + 1];
            if (arr[t + 2] > 0)
                t += 2;
            else
                t += 1;
        }
    }
    for (int i = 0; i < 2 * MAX_SIZE; i++)
    {
        if (arr[i] == 1)
            printf("%d ", i - MAX_SIZE);
    }
    printf("\n");
    // free(arr);
}

int main()
{
    // int t;
    // scanf("%d", &t);
    // while (t--)
    // {
    // clock_t begin = clock();
    test_case();
    // clock_t end = clock();
    // double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    // printf("%lf", time_spent);

    // }
}
