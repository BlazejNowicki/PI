#include <stdio.h>
#define MAX_LEVEL 8

int n;

int is_prime(int n){
    if(n==2 || n==3)
        return 1;
    if(n%2==0 || n%3==0 || n<2)
        return 0;
    int i=5;
    while(i*i <= n){
        if(n%i==0 || n%(i+2)==0)
            return 0;
        i += 6;
    }
    return 1;
}

void iterate(int base, int level){
    if(level == 0){
        if(is_prime(base))
            printf("%d\n", base);
    }
    else{
        int tmp;
        for(int i=base%10; i<10; ++i){
            tmp = base*10+i;
            if(tmp<=n){
                iterate(tmp, level-1);
            }
        }
    }
}

int main(){
    scanf("%d", &n);
    iterate(0, MAX_LEVEL);
}
