#include <stdio.h>
void strCat(char *ps1, char *ps2);
int main(){
    char str1[100], str2[100], *ps1, *ps2;
    printf("Enter first String: ");
    scanf("%s", str1);
    // gets(str1);
    printf("Enter second String: ");
    scanf("%s", str2);
    // gets(str2);
    ps1 = str1;
    ps2 = str2;
    strCat(ps1, ps2);
    printf("The resultant string is: %s", ps1);
    return 0;
}
void strCat(char *ps1, char *ps2){
    while(*ps1 != '\0'){
        ps1++;
    }
    while(*ps2 != '\0'){
        *ps1 = *ps2;
        ps1++;
        ps2++;
    }
    *ps1 = '\0';
}
