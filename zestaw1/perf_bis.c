#include <stdio.h>

int perf(int M)
{
    int ans=1, t=2, i=2, n=M;
    while(n>1){
        if(n%i==0){
            t *= i;
            n /= i;
        }else{
            ans *= (1-t)/(1-i);
            i += 1;
            t = i;
        }
    }
    ans *= (1-t)/(1-i);
    return ans==M*2;
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    for (int i = m; i <= n && i<10000; ++i)
    {
        if(perf(i))
            printf("%d\n", i);
    }
    return 0;
}