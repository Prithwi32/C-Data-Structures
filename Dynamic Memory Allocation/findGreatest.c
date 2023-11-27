#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, *p, i, maxi;
    printf("Enter size of the array: ");
    scanf("%d", &n);
    p = (int *)malloc(n * sizeof(int));
    printf("Enter array Elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", (p + i));
    }
    maxi = *p;
    for (int i = 0; i < n; i++)
    {
        if (*(p + i) > maxi)
        {
            maxi = *(p + i);
        }
        // else
        // {
        //     continue;
        // }
    }
    free(p);
    printf("Greatest Element is: %d", maxi);

    return 0;
}