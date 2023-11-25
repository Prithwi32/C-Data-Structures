#include <stdio.h>
#include <string.h>

int main()
{
    int len, i;
    char str[20], temp[20], *ptr;
    // gets(str);
    scanf("%s", str);
    len = strlen(str);
    ptr = ptr - len + 1;
    for (i = 0; i < len; i++)
    {
        temp[i] = *ptr;
        ptr--;
    }
    printf("Original Array: %s", str);
    printf("Reversed Array: %s", temp);
    // for (int i = 0; i < len; i++)
    // {
    //     printf("%d", str[i]);
    // }
    // for (int i = 0; i < len; i++)
    // {
    //     printf("%d", temp[i]);
    // }
    return 0;
}