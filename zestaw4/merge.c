#include <stdio.h>
#include <stdlib.h>

int n;

int merge(int **left, int length)
{
    //single row left(nothing to merge)
    if (length == 1)
        return n;

    //merge rows from the first and the second half
    int **right = (int **)(left + (length + 1) / 2);
    int length_left = merge(left, (length + 1) / 2);
    int length_right = merge(right, length - (length + 1) / 2);

    // merge rows at right[0] and left[0] to ans[], then assign ans[] to left[0] and free space at right[0]
    int *ans = (int *)malloc((size_t)(length_left + length_right) * sizeof(int));
    int counter = 0, i = 0, j = 0, min;

    while (i < length_left || j < length_right)
    {
        if (j >= length_right || (i < length_left && left[0][i] < right[0][j]))
        {
            min = left[0][i];
            i++;
        }
        else
        {
            min = right[0][j];
            j++;
        }
        //avoid duplicates
        if (counter == 0 || min > ans[counter - 1])
        {
            ans[counter] = min;
            counter++;
        }
    }
    left[0] = ans;
    free(right[0]);
    return counter;
}

int main()
{
    scanf("%d", &n);

    // create NxN array
    int **t1 = (int **)malloc((size_t)n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        t1[i] = (int *)malloc((size_t)n * sizeof(int));
        for (int j = 0; j < n; j++)
            scanf("%d", &t1[i][j]);
    }
    // merge rows to t1[0]
    int t2_length = merge(t1, n);
    int *t2 = t1[0];

    // print t2[]
    for (int i = 0; i < t2_length; i++)
        printf("%d ", t2[i]);
    printf("\n");
    return 0;
}