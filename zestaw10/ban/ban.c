#include <stdio.h>
#include <string.h>
#define llu unsigned long long
#define N_MAX 100

int add(int arr[N_MAX], int i)
{
    int step = 1;
    for (; i < N_MAX; ++i)
    {
        arr[i] = (arr[i] + step) % 2;
        step = (step - arr[i] + 1) / 2;
    }
    return step > 0 ? 1 : 0;
}

int divide(int arr[])
{
    int rest = 0, t;
    for (int i = 0; i < N_MAX; ++i)
    {
        t = 10 * rest + arr[i];
        if (t < 2)
        {
            rest = rest * 10 + arr[i];
            arr[i] = 0;
        }
        else
        {
            arr[i] = t / 2;
            rest = t % 2;
        }
    }
    return rest;
}

void read(int a[N_MAX], int b[N_MAX])
{
    char s[N_MAX];
    int tmp[N_MAX], len, t;
    scanf("%s", s);
    len = (int)strlen(s);
    for (int i = 0; i < N_MAX; ++i)
    {
        if (i < len)
            tmp[N_MAX - len + i] = s[i] - '0';
        else
            tmp[i - len] = 0;
    }
    for (int i = 0; i < N_MAX; ++i)
    {
        t = divide(tmp);
        b[i] = t;
        a[i] = t;
    }
}

void check(int arr[N_MAX], int flag)
{
    int ans[N_MAX], size = 0;
    for (int i = 0; i < N_MAX; ++i)
    {
        if ((i + flag) % 2 == 1 && arr[i] > 0)
        {
            if (add(arr, i))
            {
                printf("NO\n");
                return;
            }
            else
            {
                ans[size] = i;
                size++;
            }
        }
        else if (arr[i] > 0)
        {
            ans[size] = i;
            size++;
        }
    }
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", ans[i]);
    }
    printf("\n");
}

void test_case()
{
    int a[N_MAX], b[N_MAX];
    read(a, b);
    check(a, 0);
    check(b, 1);
}

int main()
{
    // int t;
    // scanf("%d", &t);
    // while (t--)
    // {
    test_case();
    // }
}
