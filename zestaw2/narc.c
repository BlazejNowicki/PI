#include <stdio.h>

int m, b, flag = 1;

void print_ans(int value)
{
    char tab[m];
    for (int i = 0; i < m; ++i)
    {
        tab[i] = value % b;
        value /= b;
        if (tab[i] > 9)
            tab[i] = tab[i] + 'A' - 10;
        else
            tab[i] += '0';
    }
    for (int i = m - 1; i >= 0; --i)
        printf("%c", tab[i]);
    printf(" ");
    flag = 0;
}

int power(int a, int w)
{
    int ans = 1;
    for (int i = 0; i < w; ++i)
        ans *= a;
    return ans;
}

void find_narc(int pow_sum, int level, int value)
{
    if (level == 0)
    {
        if (value == pow_sum)
            print_ans(value);
    }
    else
    {
        for (int i = (value == 0 ? 1 : 0); i < b; ++i)
            find_narc(pow_sum + power(i, m), level / b, value + i * level);
    }
}

int main()
{
    scanf("%d %d", &m, &b);
    find_narc(0, power(b, m - 1), 0);
    printf(flag ? "NO\n" : "\n");
    return 0;
}