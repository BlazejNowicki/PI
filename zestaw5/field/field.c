#include <stdio.h>
#include <stdlib.h>

int max_area(int **arr, int n)
{
    int max_area = 0, rectangle_width, rectangle_height, flag;
    // for each index as a top-left corner...
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            // ... check every possible legal width and height of a rectangle ...
            rectangle_width = n-j;
            while (rectangle_width > 0){
                rectangle_height = 1;
                flag = 1;
                while(flag && rectangle_height+i <= n){
                    for(int k=0; k<rectangle_width; ++k){
                        if(arr[i+rectangle_height-1][j+k] == 1){
                            flag = 0;
                            break;
                        }
                    }
                    // ... and remember the greatest area
                    if(flag && max_area < rectangle_height*rectangle_width){
                        max_area = rectangle_height*rectangle_width; 
                    }
                    rectangle_height++;
                }
                rectangle_width--;
            }
        }
    
    return max_area;
}

int main()
{
    int n;
    scanf("%d", &n);
    // alocate and fill NxN dynamic array
    int **arr = (int **)malloc((size_t)n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc((size_t)n * sizeof(int));
        for (int j = 0; j < n; ++j)
            scanf("%d", &arr[i][j]);
    }
    printf("%d\n", max_area(arr, n));
    
    for(int i=0; i<n; ++i)
        free(arr[i]);
    free(arr);
    return 0;
}
