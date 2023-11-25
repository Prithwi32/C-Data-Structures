#include <stdio.h>
int findLargest(int *p, int *q);
int main(){
    int x, y;
    scanf("%d %d", &x, &y);
    int ans = findLargest(&x, &y);
    printf("Largest Number is: %d", ans);
    return 0;
}

int findLargest(int *p, int *q){
    int temp;
    if(*p > *q){
        temp = *p;
    }else{
        temp = *q;
    }
    return temp;
}

