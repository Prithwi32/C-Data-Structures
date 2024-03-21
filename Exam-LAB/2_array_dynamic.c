// 2. Develop a menu driven program to implement the following operations on an array of integers with dynamic
// memory allocation. Display the array contents after each operation.
// i) Insert by position ii) Delete by key iii) Search by position iv) Reverse the contents.

// Dynamic memory allocation
#include <stdio.h>
#include <stdlib.h>
int ne = 0; // Initializing Number of Elements in Array

// Function to insert an element into Array at specified position
void insert_by_pos(int *arr, int size)
{
    int i, pos, ele;
    if (ne == size)
    {
        printf("Array is full.\n");
        printf("Reallocating Array\n");
        size++;
        arr = (int *)realloc(arr, size * sizeof(int));
    }
    printf("Enter The element to be inserted : \n");
    scanf("%d", &ele);
    printf("Enter The position where The elements should be inserted\n");
    scanf("%d", &pos);
    if (pos >= 0 && pos < ne + 1)
    {
        for (i = ne-1; i >= pos ; i--)
        {
            *(arr + i + 1) = *(arr + i);
        }
        *(arr + pos) = ele;
        ne++;
    }
    else
        printf("invalid position\n");
}

// Function to delete a key element into Array
void delete_by_ele(int *arr)
{
    int i, ele;
    if (ne == 0)
    {
        printf("Array is empty.\n");
        return;
    }
    printf("Enter The elements that should be deleted\n");
    scanf("%d", &ele);
    for (i = 0; i < ne && *(arr + i) != ele; i++)
        ; 
    if (i == ne)
    {
        printf("element not found in The Array list\n");
        return;
    }
    for (; i < ne - 1; i++)
    {
        *(arr + i) = *(arr + i + 1);
    }
    ne--;
}


// Function to search an element in Array at specified position
void search_by_pos(int *arr)
{
    int pos, i;
    if (ne == 0)
    {
        printf("Array is empty\n");
        return;
    }
    printf("Enter The position from where element should be searched\n");
    scanf("%d", &pos);
    if (pos >= 1 && pos <= ne)
    {
        i = pos - 1;
        printf("element at %d is %d\n", pos, *(arr + i));
    }
    else
        printf("invalid position\n");
}

// Function to reverse The elements of Array
void reverse(int *arr)
{
    int t, i;
    if (ne == 0)
    {
        printf("Array is empty\n");
        return;
    }
    for (i = 0; i < ne / 2; i++)
    {
        t = *(arr + i);
        *(arr + i) = *(arr + ne - i - 1);
        *(arr + ne - i - 1) = t;
    }
}

void display(int *arr)
{
    if (ne == 0)
    {
        printf("Array is Empty\n");
        return;
    }
    int i;
    printf("Array is: ");
    for (i = 0; i < ne; i++)
    {
        printf("%d ", *(arr + i));
    }
}

int main()
{
    int *arr, size, n, choice, i;
    printf("Enter capacity of Array:\n");
    scanf("%d",&size);
    printf("Enter number elements:\n");
    scanf("%d",&n);
    ne = n;
    arr = (int *)malloc(size * sizeof(int));
    if(arr == NULL){
        printf("Dynamic memory allocation not possible\n");
        return 0;
    }
    printf("Enter array Elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    while (1)
    {
        printf("\nEnter\n1.Insert_by_position\n2.Delete_by_key\n3.search_by_position\n4.Reverse_contents\n5.Display\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            insert_by_pos(arr,size);
            display(arr);
            break;
            case 2:delete_by_ele(arr);
            display(arr);
            break;
            case 3: search_by_pos(arr);
            display(arr);
            break;
            case 4: reverse(arr);
            display(arr);
            break;
            case 5: display(arr);
            break;
            break;
            default : printf("Invalid Choice\n");
            return 0;
        }
    }
    return 0;
}
