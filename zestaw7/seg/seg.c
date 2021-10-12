#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int max_sum(int **arr, int n, int k, int dir_x, int dir_y, int start)
{
    int cur_sum, max_sum = -INT_MAX, s_x = 0, s_y = 0, x, y;
    // dla każdego z n mijesc w których zaczynają się kolumny, wiersze itd
    for (int i = 0; i < n; ++i)
    {
        x = s_x;
        y = s_y;
        cur_sum = 0;
        // tworzymy pierwszą sumę ciągu
        for (int j = 0; j < k; ++j)
        {
            cur_sum += arr[(x + n) % n][(y + n) % n];
            x = (n + x + dir_x) % n;
            y = (n + y + dir_y) % n;
        }
        // przesówamy ciąg po prostej
        for (int j = 0; j < n; ++j)
        {
            if (cur_sum > max_sum)
                max_sum = cur_sum;
            cur_sum += arr[(n + x) % n][(n + y) % n] - arr[(2 * n + x - dir_x * k) % n][(2 * n + y - dir_y * k) % n];
            x = (x + dir_x) % n;
            y = (y + dir_y) % n;
        }
        // dobieranie miejsc startowych
        if (start)
            s_x = (1 + s_x) % n;
        else
            s_y = (1 + s_y) % n;
    }
    return max_sum;
}

int main()
{
    int n, k, ans = -INT_MAX, tmp;
    // kierunki w które należy się poruszać i miejsca startowe, aby sprawdzić odpowiednio wiersze, kolumny, skośne prawo i lewo
    int dir[4][3] = {{0, 1, 1}, {1, 0, 0}, {1, 1, 1}, {-1, 1, 1}};
    scanf("%d %d", &n, &k);
    int **arr = (int **)malloc((size_t)n * sizeof(int *));
    for (int i = 0; i < n; ++i)
    {
        arr[i] = (int *)malloc((size_t)n * sizeof(int));
        for (int j = 0; j < n; ++j)
            scanf("%d", &arr[i][j]);
    }
    // maksymalna suma w każdym kierunku 
    for (int i = 0; i < 4; ++i)
    {
        tmp = max_sum(arr, n, k, dir[i][0], dir[i][1], dir[i][2]);
        if (ans < tmp)
            ans = tmp;
    }
    printf("%d\n", ans);
    for (int i = 0; i < n; ++i)
        free(arr[i]);
    free(arr);
    return 0;
}
