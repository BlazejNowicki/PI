#include <stdio.h>
#include <limits.h>
#define N_MAX 50

int min(int a, int b)
{
    return a < b ? a : b;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

void search_two(int colors[3][N_MAX], int n, int flag[])
{
    int first, second, min_steps = INT_MAX, s;
    if (n < 2)
    {
        // za mało pudełek na dwa kolory
        printf("-1\n");
        return;
    }
    // oznacz kolory które występują
    if (flag[0] == 0)
    {
        first = 1;
        second = 2;
    }
    else if (flag[1] == 0)
    {
        first = 0;
        second = 2;
    }
    else
    {
        first = 0;
        second = 1;
    }
    // dla każdego koloru wyznacz pudełko do którego będą trafiać przekładane kule (a - first, b - second)
    for (int a = 0; a < n; ++a)
    {
        for (int b = 0; b < n; b++)
        {
            if (a != b)
            {
                // ile minimalnie kul należy przełożyć dla danego ustawienia
                s = 0;
                for (int p = 0; p < n; ++p)
                {
                    if (p == a)
                        // dla pudełka wybrano kolor więc usuń pozostałe
                        s += colors[second][p];
                    else if (p == b)
                        s += colors[first][p];
                    else
                        // dla pudełka nie wybrano koloru więc zostaw kule koloru którego jest najwięcej
                        s += min(colors[first][p], colors[second][p]);
                }
                // zapamiętaj najlepsze ustawienie
                if (s < min_steps)
                    min_steps = s;
            }
        }
    }
    printf("%d\n", min_steps);
}

void search_three(int colors[3][N_MAX], int n, int flag[3])
{
    int min_steps = INT_MAX, s;
    enum color {red, green, blue};
    if (n < 3)
    {
        // za mało pudełek żeby pomieścić trzy kolory
        printf("-1\n");
        return;
    }
    // dla każdego koloru wyznacz pudełko do którego będą trafiać przekładane kule
    for (int r = 0; r < n; ++r)
    {
        for (int g = 0; g < n; g++)
        {
            for (int b = 0; b < n; b++)
            {
                if (r != g && r != b && g != b)
                {
                    // ile minimalnie kul należy przełożyć dla danego ustawienia
                    s = 0;
                    for (int p = 0; p < n; ++p)
                    {
                        if (p == r)
                            // dla pudełka wybrano kolor więc usuwamy pozostałe
                            s += colors[green][p] + colors[blue][p];
                        else if (p == b)
                            s += colors[green][p] + colors[red][p];
                        else if (p == g)
                            s += colors[red][p] + colors[blue][p];
                        else
                            // dla pudełka nie wybrano koloru więc zostawiamy kule koloru którego jest najwięcej
                            s += colors[red][p] + colors[green][p] + colors[blue][p] - max(colors[green][p], max(colors[red][p], colors[blue][p]));
                    }
                    // zapamiętaj najlepsze ustawienie
                    if (s < min_steps)
                        min_steps = s;
                }
            }
        }
    }
    printf("%d\n", min_steps);
}

void test_case()
{
    int colors[3][N_MAX], n;
    int flag[] = {0, 0, 0}; // czy są kule danego koloru
    scanf("%d", &n);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%d", &colors[i][j]);
            if (colors[i][j] > 0)
                flag[i] = 1;
        }
    }
    switch (flag[0] + flag[1] + flag[2]) // ile kolorów trzeba rozważyć
    {
    case 0:
    case 1:
        printf("0\n");
        break;
    case 2:
        search_two(colors, n, flag);
        break;
    case 3:
        search_three(colors, n, flag);
        break;
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        test_case();
    }
}
