#include <stdio.h>
#define ll long long

ll find_num(ll k)
{
    ll div = 1, x = 0;
    while (10 * div + 1 <= k)
        div = 10 * div + 1;

    while (div > 0)
    {
        if (k / div > 9)
            return (ll)-1;
        x = 10 * x + k / div;
        k %= div;
        div /= 10;
    }
    return x;
}

int main()
{
    ll k;
    scanf("%lld", &k);
    printf("%lld\n", find_num(k));
    return 0;
}
