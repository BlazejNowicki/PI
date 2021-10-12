#include <stdio.h>
#define llu unsigned long long

int main()
{
    int n;
    llu ans=0;
    scanf("%d", &n);
    for ( int i=1; i<=n; i += 2){
        for (int j=i; j<=n; j *= 2){
            ans += (llu)i;
        }
    }
    printf("%llu\n", ans);
    return 0;
}