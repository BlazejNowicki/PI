#include <stdio.h>
#include <string.h>
#define MAX_LEN 50
#define LAST_CHAR 'z'

int check_prime(int a)
{
    for (int c = 2; c <= a - 1; c++)
    {
        if (a % c == 0)
            return 0;
    }
    return 1;
}

int next_prime(int a)
{
    do
    {
        a++;
    } while (!check_prime(a));
    return a;
}

void test_case()
{
    int n;
    char s[MAX_LEN + 1], t[MAX_LEN + 1];
    scanf("%s", s);
    n = (int)strlen(s);
    memset(t, LAST_CHAR, (size_t)n);
    t[n] = '\0';
    for (int o = 0; o < n; o++)
        for (int p = 2; p < n; p = next_prime(p))
            for (int i = 0; i < n; i++)
            {
                if (s[(o + i * p) % n] < t[i])
                {
                    for (int j = i; j < n; ++j)
                        t[j] = s[(o + j * p) % n];
                    break;
                }
                if (s[(o + i * p) % n] > t[i])
                    break;
            }
    puts(t);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        test_case();
    }
}
