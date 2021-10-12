#include <stdio.h>
#include <stdlib.h>

int main()
{
    // liczymy trójkąty dwukolorowe i odejmujemy od liczby wszystkich
    int n, t, x, y, s=0;
    scanf("%d %d", &n, &t);
    int *arr = (int *)malloc((size_t)n * sizeof(int));
    for (int i = 0; i < n; ++i)
        arr[i] = 0;
    for (int i = 0; i < t; ++i)
    {
        scanf("%d %d", &x, &y);
        arr[x-1]++;
        arr[y-1]++;
    }
    for (int i = 0; i < n; i++){
        s += arr[i]*(n-1-arr[i]);
    }
    s = ((n)*(n-1)*(n-2))/6 - s/2;
    printf("%d\n", s);
    free(arr);
    return 0;
}
