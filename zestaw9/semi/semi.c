#include <stdio.h>

void test_case()
{
    int n, m, limit, cnt = 0;
    scanf("%d %d", &n, &m);
    limit = (1 << n);
    for (int i = 1; i < limit; ++i)
    {
        if (i % m != 0)
        {
            for (int j = 0; j < n; ++j)
            {
                if ((i ^ (1 << j)) % m == 0 && (i ^ (1 << j)) > 0)
                {
                    cnt++;
                    break;
                }
            }
        }
    }
    printf("%d\n", cnt);
}

int main()
{
    // int t;
    // scanf("%d", &t);
    // while (t--)
    // {
        test_case();
    //     printf("----------------\n");
    // }
}
