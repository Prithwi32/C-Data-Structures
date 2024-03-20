// 3. Develop a menu driven program to implement the following operations on an array of integers with dynamic
// memory allocation. Display the array contents after each operation.
// i) Insert by order ii) Delete by position iii) Search by key iv) Reverse the contents.

#include <stdio.h>
#include <stdlib.h>

int ne = 0;

// Function to insert an element into Array in order
void insert_by_order()
{
    // int i, ele;
    // if (ne == size)
    // {
    //     printf("Array is full.\n");
    //     printf("Reallocating Array \n");
    //     size++;
    //     arr = (int *)realloc(arr, size * sizeof(int));
    // }
    // printf("Enter The element to be inserted : ");
    // scanf("%d", &ele);
    // for (i = ne - 1; *(arr + i) >= ele; i--)
    //     *(arr + i + 1) = *(arr + i);
    // *(arr + i + 1) = ele;
    // ne++;

    // int cap, n, ele;
    //  printf("Enter capacity of array: ");
    //  scanf("%d",&cap);
    //  order = (int *)malloc(cap*sizeof(int));
    //  printf("Enter number of elements: ");
    //  scanf("%d",&n);
    //  printf("Enter element to insert: ");
    //  for(int i=n-1; i>=0; i--){
    //     scanf("%d",&ele);
    //     if(ele < *(order + i))
    //     *(order+i+1) = *(order + i);
    //     *(order+i) = ele;
    //  }

int cap, n, ele;
    // Input the capacity of the array
    printf("Enter capacity of array: ");
    scanf("%d", &cap);

    // Allocate memory for the array
    int *order = (int *)malloc(cap * sizeof(int));
    if (order == NULL)
    {
        printf("Memory allocation failed.\n");
        return ; // Error code for memory allocation failure
    }

    // Input the number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input elements and insert them in sorted order
    printf("Enter elements to insert:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ele);

        // Find the correct position to insert the element
        int j = i - 1;
        while (j >= 0 && order[j] > ele)
        {
            order[j + 1] = order[j];
            j--;
        }
        order[j + 1] = ele;
    }

    // Display the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", order[i]);
    }
    printf("\n");

    // Free dynamically allocated memory
    free(order);
}

// Function to delete an element in Array at specified position
void delete_by_pos(int *arr)
{
    int i, pos, val;
    if (ne == 0)
    {
        printf("Array is empty.\n");
        return;
    }
    printf("Enter The position from where elements should be deleted\n");
    scanf("%d", &pos);
    if (pos >= 1 && pos <= ne)
    {
        val = *(arr + pos - 1);
        for (i = pos - 1; i < ne - 1; i++)
        {
            *(arr + i) = *(arr + i + 1);
        }
        ne--;
        printf("Deleted element is: %d\n", val);
    }
    else
        printf("invalid position.\n");
}

// Function to search an element in Array
void search_by_key(int *arr)
{
    int i, ele, flag = 0;
    if (ne == 0)
    {
        printf("Array is empty\n");
        return;
    }
    printf("Enter The element that should be searched\n");
    scanf("%d", &ele);
    for (i = 0; i < ne; i++)
    {
        if (*(arr + i) == ele)
        {
            printf("element found at position %d\n", i + 1);
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        printf("element not found\n");
}

// Function to reverse The elements of Array
void reverse(int *arr)
{
    int temp, i;
    if (ne == 0)
    {
        printf("Array is empty\n");
        return;
    }
    for (i = 0; i < ne / 2; i++)
    {
        temp = *(arr + i);
        *(arr + i) = *(arr + ne - i - 1);
        *(arr + ne - i - 1) = temp;
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
    int *arr, size, n, choice, i, j, temp, *order;
    printf("Enter capacity of Array:\n");
    scanf("%d", &size);
    printf("Enter number elements:\n");
    scanf("%d", &n);
    ne = n;
    arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL)
    {
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
        printf("\nEnter\n1.Insert_by_order\n2.Delete_by_position\n3.search_by_key\n4.Reverse_contents\n5.Display\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        // case 1: for(i=1; i<n; i++){
        //     for(j=0; j<n-i; j++){
        //         if(*(arr+j) > *(arr+j+1)){
        //            temp = *(arr+j+1);
        //            *(arr+j+1) = *(arr+j);
        //            *(arr+j) = temp;
        //         }
        //     }
        // }
        case 1:
            insert_by_order();
            display(order); 
            break;
        case 2:
            delete_by_pos(arr);
            display(arr);
            break;
        case 3:
            search_by_key(arr);
            display(arr);
            break;
        case 4:
            reverse(arr);
            display(arr);
            break;
        case 5:
            display(arr);
            break;
            break;
        default:
            printf("Invalid Choice\n");
            return 0;
        }
    }
    return 0;
}
