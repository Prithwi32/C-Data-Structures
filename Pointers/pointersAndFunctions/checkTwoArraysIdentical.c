#include <stdio.h>
int checkIdentical(int n, int m, int *p, int *q)
{
    if (n == m)
    {
        for (int i = 0; i < n; i++)
        {
            if (*(p + i) == *(q + i))
            {
                continue;
            }
            else
            {
                return 0;
                break;
            }
        }
    }
    else
    {
        return 0;
    }
    return 1;
}
int main()
{
    int n, m, a1[20], a2[20];
    printf("Enter size of first Array: ");
    scanf("%d", &n);
    printf("Enter size of second Array: ");
    scanf("%d", &m);
    printf("Enter first array elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &a1[i]);
    }
    printf("Enter second array elements: ");
    for(int i=0; i<m; i++){
        scanf("%d", &a2[i]);
    }
    int ans = checkIdentical(n, m, a1, a2);
    if (ans == 1)
    {
        printf("Arrays are identical.");
    }
    else
    {
        printf("Arrays are not identical");
    }
    return 0;
}