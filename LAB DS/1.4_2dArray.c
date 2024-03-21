#include <stdio.h>
int rows = 3;
int cols = 3;
void read(int *ptr, int rows, int cols);
void display(int *ptr, int rows, int cols);
int main()
{
    int arr[rows][cols];
    printf("Enter row size of Array: ");
    scanf("%d", &rows);
    printf("Enter column size of Array: ");
    scanf("%d", &cols);
    printf("Enter array Elements: ");
    read(&arr[0][0], rows, cols);
    printf("2D Array:\n");
    display(&arr[0][0], rows, cols);
    return 0;
}
void read(int *ptr, int rows, int cols)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            scanf("%d", (ptr + i*cols + j));
        }
    }
}
void display(int *ptr, int rows, int cols)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d ", *(ptr + i*cols + j));
        }
        printf("\n");
    }
}