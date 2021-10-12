#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return (int)*(char *)b - (int)*(char *)a;
}

int main()
{
    char a[51], b[51], c[51] = {'\0'};
    int i = 0, j = 0, n;
    scanf("%s", a);
    strcpy(b, a);
    n = (int)strlen(a);
    qsort(b, (size_t)n, sizeof(char), cmp); // sortowanie kopii wyrazu dla znalezienia najbardziej wartościowych liter
    while (i < n) // i - do iterowania po wyrazie wejściowym, j - indeks litery w wyrazie posortowanym której szukamy
    {
        for (int k = i; k < n; k++)
        {
            if (a[k] == b[j]) // jeśli kolejna litera warotściowa występuje po poprzedniej w wyrazie to możemy ją dodać na koniec tworzonego wyrazu
            {
                strncat(c, &a[k], 1);
                i = k + 1;
                break;
            }
        }
        j++;
    }
    puts(c);
    return 0;
}
