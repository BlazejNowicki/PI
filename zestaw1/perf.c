#include <stdio.h>

void perf(int m, int n)
{
    int ans[10];
    int num = 0;
    while (m <= n)
    {
        int sum = 0;
        for (int i = 1; i <= m / 2; ++i)
            if (m % i == 0)
                sum += i;
        if (sum == m)
            ans[num++] = m;
        m++;
    }
    printf("%d\n", num);
    for (int i = 0; i < num; ++i)
    {
        printf("%d ", ans[i]);
    }
    printf("\n");
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    perf(m, n);
    return 0;
}