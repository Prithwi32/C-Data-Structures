#include <stdio.h>
int main(){
    int *ptr, i, n, arr[20], sum=0, avg=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    ptr = arr;
    for(int i=0; i<n; i++){
        sum += *ptr;
        ptr++;
    }
    avg = sum / n;
    printf("Average is: %d", avg);
    return 0;
}

// NOTE: At the end of this program pointer is pointing to last element of the array.