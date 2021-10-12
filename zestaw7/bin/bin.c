#include <stdio.h>

#define llu unsigned long long

void print_binary(llu a, int n)
{
    for (int i = n - 1; i >= 0; --i)
    {
        printf("%llu", (a >> i) & 1);
    }
    printf("\n");
}

void binary_sequence(int n, int k)
{
    llu c = 0; // reprezentujemy ciąg binarny jako liczbę
    // k razy szukamy kolejnego poprawnego ciągu
    for (int i = 1; i < k; ++i)
    {
        // print_binary(c,n);
        c += 1;
        for (int j = 0; j < n - 1; ++j)
        {
            // maskami bitowymi znajdujemy sąsiadujące jedynki
            if (((c >> j) & 3) == 3)
            {
                // przeskakujemy do następnego ciągu który ma czanse być poprawny
                c += (llu)(1 << j);
            }
        }
        // sprawdzamy czy ciągi nie są już dłuższe niż n
        if (c >= (1 << n))
        {
            printf("-1\n");
            return;
        }
    }
    //wypisujemy znaleziony ciąg
    print_binary(c, n);
}

int main()
{
    int n, t;
    scanf("%d %d", &n, &t);
    binary_sequence(n, t);
    return 0;
}
