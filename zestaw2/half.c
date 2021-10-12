#include <stdio.h>


int find_index(int arr[], int length){
    int sum_left=0, sum_right=0, index_left=0, index_right=length-1;
    while(index_left != index_right){
        if(sum_left < sum_right){
            sum_left += arr[index_left];
            index_left += 1;
        }
        else{
            sum_right += arr[index_right];
            index_right -= 1;
        }
    }
    return index_left;
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; ++i){
        scanf("%d", &arr[i]);
    }
    printf("%d\n", find_index(arr, n));
    return 0;
}