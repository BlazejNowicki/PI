#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x;
    int y;
} point;

int check_from_vertex(point *arr, int s, int n)
{
    // wystarczy sprawdzić czy odpowiadające pary punktów leżą na prostej prostopadłej do osi symetrii w takiej samej odległości od przecięcia
    int axis_x, axis_y, l, r, dot_prod, dist_dif;

    // punkt do określenia czy odległość od przecięcia jest równa
    point centr; 
    centr.x = arr[s].x;
    centr.y = arr[s].y;

    // wektor kierunkowy osi symetrii
    axis_x = 2 * arr[s].x - arr[(((n + 1) / 2) + s) % n].x - arr[((n / 2) + s) % n].x; //x2
    axis_y = 2 * arr[s].y - arr[(((n + 1) / 2) + s) % n].y - arr[((n / 2) + s) % n].y; //x2

    // czy każda para punktów spełnia warunek
    for (int i = 1; i < (n + 1) / 2; ++i)
    {
        l = (n + s - i) % n;
        r = (n + s + i) % n;
        // iloczyn skalarny wektorów kierunkowych osi symetrii i prostej przechodzącej przez badane punkty
        dot_prod = (arr[l].x - arr[r].x) * axis_x + (arr[l].y - arr[r].y) * axis_y;

        // różnica odległości od przecięcia
        dist_dif = (centr.x - arr[l].x)*(centr.x-arr[l].x) + (centr.y - arr[l].y)*(centr.y-arr[l].y);
        dist_dif -= (centr.x - arr[r].x)*(centr.x-arr[r].x) + (centr.y - arr[r].y)*(centr.y-arr[r].y);
    
        if(dot_prod != 0 || dist_dif != 0)
            return 0;
    }
    return 1;
}

int check_between_vertexes(point *arr, int s, int n)
{
    // analogicznie jak powyżej
    int axis_x, axis_y, l, r, dot_prod, dist_dif;

    // środek odcinka pomiędzy dwoma sąsiednimi wierzchołkami
    point centr;
    centr.x = arr[s].x + arr[s+1].x; // obie współżędne x2 żeby uniknąć 0.5
    centr.y = arr[s].y + arr[s+1].y;

    // oś symetrii
    axis_x = centr.x - arr[((n / 2) + s) % n].x - arr[((n / 2) + s +1) % n].x; //x2
    axis_y = centr.y - arr[((n/ 2) + s) % n].y - arr[((n / 2) + s + 1) % n].y; //x2


    for (int i = 0; i < n/2; ++i)
    {
        l = (n + s - i) % n;
        r = (n + s + i + 1) % n;

        // iloczyn skalarny
        dot_prod = (arr[l].x - arr[r].x) * axis_x + (arr[l].y - arr[r].y) * axis_y;

        // różnica odległości
        dist_dif = (centr.x - 2*arr[l].x)*(centr.x-2*arr[l].x) + (centr.y - 2*arr[l].y)*(centr.y-2*arr[l].y);
        dist_dif -= (centr.x - 2*arr[r].x)*(centr.x-2*arr[r].x) + (centr.y - 2*arr[r].y)*(centr.y-2*arr[r].y);

        if(dot_prod != 0 || dist_dif != 0)
            return 0;
    }
    return 1;
}

void test_case()
{
    int n, counter = 0;
    scanf("%d", &n);
    point *arr = malloc((size_t)(n) * sizeof(point));

    for (int i = 0; i < n; i++)
        scanf("%d %d", &arr[i].x, &arr[i].y);

    if (n % 2 == 0)
    {
        // dla parzystokątnych osie symetrii mogą być w wierzchołku albo pomiędzy nimi
        for (int i = 0; i < n / 2; i++)
        {
            counter += check_from_vertex(arr, i, n);
            counter += check_between_vertexes(arr, i, n);
        }
    }
    else
    {
        // dla nieparzystokątnych osie symetrii tylko w wierzchołkach
        for (int i = 0; i < n; i++)
        {
            counter += check_from_vertex(arr, i, n);
        }
    }
    printf("%d\n", counter);
    free(arr);
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
