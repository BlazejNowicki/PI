#include <stdio.h>
#include <string.h>

//Constants for conversion
const int values[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
const char symbols[13][2] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

//Convert roman number to decimal number
int to_decimal(char arr[])
{
    int n = (int)strlen(arr), i = 0, j = 0, sum = 0;
    while (i < n)
    {
        // Identify symbol and add corresponding value to sum
        while (j < 13 && !((i + 1 < n && symbols[j][1] != 0 && symbols[j][0] == arr[i] && symbols[j][1] == arr[i + 1]) ||
                           (symbols[j][1] == 0 && symbols[j][0] == arr[i])))
            j++;
        sum += values[j];
        i += (symbols[j][1] == 0 ? 1 : 2);
    }
    return sum;
}

// Convert decimal number to roman number
void to_roman(int s)
{
    int i = 0;
    while (s > 0 && i < 13)
    {
        // Substract value and add corresponing symbol if possible
        if (values[i] > s)
            i++;
        else
        {
            s -= values[i];
            printf("%c", symbols[i][0]);
            if (symbols[i][1] != 0)
                printf("%c", symbols[i][1]);
        }
    }
    printf("\n");
}

int main()
{
    char a[20], b[20];
    scanf("%s %s", a, b);
    to_roman(to_decimal(a) + to_decimal(b));
    return 0;
}
