#include <stdio.h>

// divide number to cells to avoid overflow
// adjust parameters for expected input: cell_size*n < MAX_INT and cell_size*arr_size > n!
#define CELL_SIZE 1000000
#define ARR_SIZE 50

void factorial(int n)
{
    int cells[ARR_SIZE] = {0};
    cells[0] = 1;
    int last = 0;
    for (int x = 1; x <= n; ++x)
    {
        // calculate value of each cell
        for (int i = 0; i <= last; i++)
        {
            cells[i] = x * cells[i];
        }
        // remove overflow (above cell size)
        for (int i = 0; i <= last; i++)
        {
            cells[i + 1] += cells[i] / CELL_SIZE;
            cells[i] = cells[i] % CELL_SIZE;
        }
        // update index of last used cell
        if (cells[last + 1] > 0)
        {
            last++;
        }
    }
    //print digits
    printf("%d", cells[last]);
    for (int i = last - 1; i >= 0; i--)
    {
        for (int j = CELL_SIZE / 10; j > 0; j /= 10)
        {
            printf("%d", cells[i] / j);
            cells[i] = cells[i] % j;
        }
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    factorial(n);
    return 0;
}