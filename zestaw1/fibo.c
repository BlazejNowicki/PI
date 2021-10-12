#include <stdio.h>

int fibo(int n)
{
    int a = 0, b = 1, t;
    while (a * b < n)
    {
        t = b;
        b = a + b;
        a = t;
    }
    return a * b == n;
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    printf(fibo(n) ? "YES\n" : "NO\n");
    return 0;
}
