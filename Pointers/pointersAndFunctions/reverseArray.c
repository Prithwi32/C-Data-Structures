#include <stdio.h>
void readElements(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}
int *reverse(int *ptr, int n)
{
    static int temp[20];
    int i;
    for (i = 0; i < n; i++)
    {
        temp[i] = *(ptr + n - i -1);
    }
    return temp;
}
void display(int *ptr, int *temp, int n)
{
    int i;
    printf("Original Array: ");
    for (i = 0; i < n; i++)
    {
        printf(" %d", *(ptr + i));
    }
    printf(" Reversed Array: ");
    for (i = 0; i < n; i++)
    {
        printf(" %d", *(temp + i));
    }
}
int main()
{
    int arr[20], *temp, *ptr, n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    readElements(arr, n);
    ptr = arr;
    temp = reverse(arr, n);
    display(ptr, temp, n);

    return 0;
}