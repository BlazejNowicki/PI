#include <stdio.h>

int is_prime(int n)
{
    if (n == 2 || n == 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0 || n < 2)
        return 0;
    int i = 5;
    while (i * i <= n)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
        i += 6;
    }
    return 1;
}

int square_one(int i)
{
    int tmp = 0;
    while (i != 4 && i != 1)
    {
        while (i > 0)
        {
            tmp += (i % 10) * (i % 10);
            i /= 10;
        }
        i = tmp;
        tmp = 0;
    }
    return i == 1 ? 1 : 0;
}

int main()
{
    int l, u, k;
    scanf("%d %d %d", &l, &u, &k);
    while (l <= u && k > 0)
    {
        if (square_one(l) && is_prime(l))
            k--;
        l++;
    }
    printf("%d\n", k ? -1 : l - 1);
    return 0;
}