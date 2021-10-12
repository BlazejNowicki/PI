#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    printf(rand()%2?"YES\n":"NO\n");
    return 0;
}