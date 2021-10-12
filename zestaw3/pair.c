#include <stdio.h>
#include <stdlib.h>

int compare(const void *elem1, const void *elem2)
{
    int f = *((int *)elem1);
    int s = *((int *)elem2);
    if (f > s)
        return 1;
    if (f < s)
        return -1;
    return 0;
}

int count_pairs(int *A, int n, int k)
{
    int sum = 0, i = 0, j;
    while (i < n)
    {
        j = i;
        while (j + 1 < n && A[j] == A[j + 1])
            j++;
        if ((i > 0 && A[i - 1] + k >= A[i]) || (j + 1 < n && A[j] + k >= A[j + 1]))
        {
            sum += j - i + 1;
        }
        i = j + 1;
    }
    return sum;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int *arr = (int *)calloc((size_t)n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    qsort(arr, (size_t)n, sizeof(*arr), compare);
    printf("%d\n", count_pairs(arr, n, k));
    return 0;
}