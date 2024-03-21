#include <stdio.h>
int main(){
    int len, i;
    char name[30], *ptr;
    // scanf("%s", name);
    gets(name);
    ptr = name;
    while(*ptr != '\0'){
        ptr++;
    }
    len = ptr - name;
    printf("Length of String is: %d", len);
    return 0;
}