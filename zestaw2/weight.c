#include <stdio.h>
#include <stdlib.h>

int *weights;

int check(int index, int sum)
{
    if (sum == 0)
        return 1;
    else if (index < 0)
        return 0;
    else
    {
        if (check(index - 1, sum))
            return 1;
        else if (check(index - 1, sum - weights[index]))
            return 1;
        else if (check(index - 1, sum + weights[index]))
            return 1;
        else
            return 0;
    }
}

int main()
{
    int n, w;
    scanf("%d %d", &n, &w);
    weights = malloc(sizeof(int) * n);
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &weights[i]);
        sum += weights[i];
    }
    if (w > sum)
        printf("NO\n");
    else
        printf(check(n - 1, w) ? "YES\n" : "NO\n");
    return 0;
}