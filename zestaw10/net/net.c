#include <stdio.h>
#include <string.h>
#define N_MAX 110
#define M_MAX 3050

typedef struct
{
    int left;
    int right;
} gate;

void read_binary(int bin[], int n)
{
    char tmp[N_MAX + 1];
    scanf("%s", tmp);
    for (int i = 0; i < n; i++)
    {
        bin[i] = tmp[i] - '0';
    }
}

void add(int arr[], int n)
{
    arr[n - 1] += 1;
    for (int i = n - 1; arr[i] > 1 && i > 0; --i)
    {
        arr[i] = 0;
        arr[i - 1] += 1;
    }
}

int less_equal(int a[], int b[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (a[i] > b[i])
            return 0;
        if (a[i] < b[i])
            return 1;
    }
    return 1;
}

int evaluate_net(int g, int bin[], gate gates[])
{
    if (g < 0)
        return bin[-g - 1];
    int l, r;
    l = evaluate_net(gates[g].left, bin, gates);
    r = evaluate_net(gates[g].right, bin, gates);
    return (l && (!r)) || ((!l) && r);
}

void test_case()
{
    int low[N_MAX], high[N_MAX], n, m, out, l, r, counter = 0;
    gate gates[M_MAX + 1];
    scanf("%d %d %d", &n, &m, &out);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d", &l, &r);
        gates[i].left = l;
        gates[i].right = r;
    }
    read_binary(low, n);
    read_binary(high, n);
    while (less_equal(low, high, n))
    {
        counter += evaluate_net(out, low, gates);
        add(low, n);
    }
    printf("%d\n", counter);
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
