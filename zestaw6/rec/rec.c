#include <stdio.h>
#define N_MAX 100

// array to represent the plain
int plain[2 * N_MAX + 1][2 * N_MAX + 1];

int main()
{
    int n, x1, y1, x2, y2;
    scanf("%d", &n);
    while (n--)
    {
        //flip the color of every square of the given rectangle
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for(int i=N_MAX+x1; i<N_MAX+x2; ++i)
            for(int j=N_MAX+y1; j<N_MAX+y2; ++j){
                if( plain[i][j] == 1){
                    plain[i][j] = 0;
                }else{
                    plain[i][j] = 1;
                }
            }
    }
    // count the blacks
    int counter = 0;
    for (int i = 0; i <= 2*N_MAX; ++i)
        for (int j = 0; j <= 2*N_MAX; ++j)
            if (plain[i][j] == 1)
                counter++;
    printf("%d\n", counter);
    return 0;
}
