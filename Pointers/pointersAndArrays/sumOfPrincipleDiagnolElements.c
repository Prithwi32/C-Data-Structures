#include <stdio.h>
int main(){
    int n, i, j,sum=0;
    int *ptr;
    scanf("%d", &n);
    int arr[n][n];
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
        scanf("%d", &arr[i][j]);
        }
    }
    ptr = &arr[0][0];
    for(int i=0; i<n; i++){
        sum += *(ptr+i*n+i);
        // or
        // sum += *(*(ptr+i)+i);
    }
    printf("Sum of Principle Diagonal Elements is: %d", sum);

return 0;
}