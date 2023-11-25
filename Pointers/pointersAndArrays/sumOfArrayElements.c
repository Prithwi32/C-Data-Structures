#include <stdio.h>
int main(){
    int arr[20], n, i, sum=0, *ptr;
    // read array size
    scanf("%d", &n);
    // reading array elements
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    // printing array elements
    // for (i = 0; i < n; i++)
    // {
    //     printf("%d\t", arr[i]);
    // }

    // assignment of pointer
    ptr = arr;
    // ptr = &arr[0];
    for(int i=0; i<n; i++){
        sum += *(ptr+i);
    }
    printf("Sum of Array Elements is: %d", sum);
    return 0;
}

// NOTE: In this programme, At the end also pointer is still pointing to first element of array.