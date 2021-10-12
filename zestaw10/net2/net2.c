#include <stdio.h>
#include <stdlib.h>

int check(int a[], int b[], int size) {
    int c = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] < b[i]) {
            return 1;
        }
        else if(a[i] == b[i]){
            c++;
        }
    }
    if( c == size){
        return 1;
    }
    return 0;
}

int add(int a[], int size) {
    if (a[size - 1] == 0) {
        a[size - 1] = 1;
        return 0;

    } else {
        int r = 1, i = size - 1;
        while (a[i] + r > 1 && i >= 0) {
            a[i] = 0;
            r = 1;
            i--;
        }
        if(i>=0)a[i] = 1;
        return i<0?1:0;
    }
}

int check_gate(int l, int a[], int u[], int d[]) {
    if (l < 0) {
        return a[-l-1];
    }
    int up, down;
    up = check_gate(u[l-1], a, u, d);
    down = check_gate(d[l-1], a, u, d);
    return (up && (!down)) || ((!up) && down);

}

int main() {
    int n, m, l;
    scanf("%d %d %d", &n, &m, &l);
    int *u = (int *) malloc((size_t) (m) * sizeof(int));
    int *d = (int *) malloc((size_t) (m) * sizeof(int));
    char *a1 = (char *) malloc((size_t) (n) * sizeof(char));
    char *b1 = (char *) malloc((size_t) (n) * sizeof(char));
    int *a = (int *) malloc((size_t) (n) * sizeof(int));
    int *b = (int *) malloc((size_t) (n) * sizeof(int));

    //wczytanie bramek

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u[i], &d[i]);
    }

    //dolne ogranicznie a
    //górne ogranicznie b

    scanf("%s", a1);
    scanf("%s", b1);
    for (int i = 0; i < n; i++) {
        a[i] = a1[i] - '0';
        b[i] = b1[i] - '0';
    }
    free(a1);
    free(b1);
    int cnt = 0;

    while (check(a, b, n) != 0) {
        // for (int i = 0; i < n; i++)
        // {
        //     printf("%d", a[i]);
        // }
        // printf("\n");
        if (check_gate(l, a, u, d) != 0) {
            cnt++;
        }
        if(add(a, n))break;
    }

    printf("%d", cnt);

    free(a);
    free(b);
    free(u);
    free(d);
    return 0;
}