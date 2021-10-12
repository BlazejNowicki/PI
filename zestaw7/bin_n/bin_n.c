#include <stdio.h>
#include <stdlib.h>
#define llu unsigned long long

int main()
{
    llu n, k;
    scanf("%llu %llu", &n, &k);
    llu *fib = (llu *)malloc((size_t)(n + 1) * sizeof(llu));
    fib[0] = 1;
    fib[1] = 2;
    for (llu i = 2; i <= n; ++i)
        fib[i] = fib[i - 1] + fib[i - 2];

    if (fib[n] >= k)
    {
        for (llu i = n; i > 0; --i)
        {
            if (k > fib[i - 1])
            {
                printf("1");
                k -= fib[i - 1];
            }
            else
            {
                printf("0");
            }
        }
        printf("\n");
    }
    else
    {
        printf("-1\n");
    }
    free(fib);
    return 0;
}
