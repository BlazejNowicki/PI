#include <stdio.h>
#include <string.h>
#include <limits.h>
#define N_MAX 32

void test_case()
{
    int sums[N_MAX], n, g, t, min;
    scanf("%d %d", &n, &g);
    memset(sums, 0, N_MAX * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t);
        if ((t & (~g)) == 0)
        {
            for (int i = 0; i < N_MAX; ++i)
            {
                sums[i] += (t >> i) & 1;
            }
        }
    }
    min = INT_MAX;
    for (int i = 0; i < N_MAX; i++)
    {
        if (((g >> i) & 1) == 1 && sums[i] <= min)
        {
            min = sums[i];
        }
    }
    if (min == INT_MAX)
        min = 0;
    printf("%d\n", min);
}

int main()
{
    test_case();
}
