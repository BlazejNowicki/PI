#include <stdio.h>
#define MAX_LEN 100

typedef struct operation
{
    char o; // działanie: * / + -
    long long v; // wartość po wykonaniu działania
} opr;

void print_solution(opr arr[], int l)
{
    for (int i = 1; i <= l; i++)
    {
        printf("%c", arr[i].o);
    }
    printf("\n");
    
}

int check_limit(opr arr[], long t, int limit, int *flag)
{
    // prawda jeśli wykonywanie operacji *+ sprawia że modyfikowana wartość zawsze przekracza t i limit nigdy nie jest osiągany
    *flag = 0; 
    int i = 0;
    // sprawdź wsztsktie kombinacje operacji *+ do limitu, pomijaj te które wcześniej przekraczają t
    while (arr[i].v != t)
    {
        // --- DEBUG ---
        //  for (int j = 0; j <= i; j++)
        // {
        //     printf("(%c, %ld) ", arr[j].o, arr[j].v);
        // }
        // printf("\n");
        // ---

        if ((i == limit || arr[i].v > t) && arr[i].o == '*')
        {
            if(i == limit)*flag = 1;
            arr[i].o = '+';
            arr[i].v = 2 * arr[i - 1].v;
        }
        else if ((i == limit || arr[i].v > t) && arr[i].o == '+')
        {
            if(i == limit)*flag = 1;
            while (arr[i].o == '+' && i > 0)
                i--;
            if (i == 0)
            {
                return 0;
            }
            arr[i].o = '+';
            arr[i].v = 2 * arr[i - 1].v;
        }
        else
        {
            if(arr[i].v == 1) // pomiń sprawdzanie operacji * gdy warotść x=1 bo x*x=1
            {
                i++;
                arr[i].o = '+';
                arr[i].v = 2 * arr[i-1].v;
            }else{
                i++;
                arr[i].o = '*';
                arr[i].v = arr[i-1].v * arr[i-1].v;
            }
        }
    }
    return 1;
}

void test_case()
{
    long long s, t;
    int flag = 1, limit = 1;
    opr buffer[MAX_LEN];
    scanf("%ld %ld", &s, &t);
    // warunki brzegowe
    if (s == t)
    {
        printf("\n");
        return;
    }
    if (t == 0)
    {
        printf("-\n");
        return;
    }
    if (s == 0){
        printf("NO\n");
        return;
    }
    buffer[0].o = '+';
    // dla określonego limitu sprawdź czy uzyskanie liczby t jest możliwe
    while (flag)
    {
        buffer[0].v = s;
        // ciągi składające się z *+
        if (check_limit(buffer, t, limit, &flag))
        {
            print_solution(buffer, limit);
            return;
        }
        // ciągi zaczynające się od / potem *+
        if(s != 0 && limit > 0)
        {
            buffer[0].v = 1;
            if (check_limit(buffer, t, limit-1, &flag))
            {
                printf("/");
                print_solution(buffer, limit-1);
                return;
            }
        }
        limit++;
    }
    printf("NO\n");
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