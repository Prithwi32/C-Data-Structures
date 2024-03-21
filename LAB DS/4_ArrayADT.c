#include <stdio.h>
#include <stdlib.h>
void insertByPosition(int *arr, int *size, int pos, int val);
int deleteByPosition(int *arr, int *size, int pos);
void insertByKey(int *arr, int *size, int key, int val);
void deleteByKey(int *arr, int *size, int key);
void insertByOrder(int *arr, int *size, int value);
int searchByKey(int *arr, int size, int key);
int searchByPosition(int *arr, int *size, int pos);
void reverseContents(int *arr, int *size);
void display(int *arr, int *size);
int main()
{
    int a[100], n, *arr, *size, i;
    arr = a;
    printf("Enter size of Array: \n");
    scanf("%d",&n);
    size = &n;
    arr = (int *)malloc((*size) * sizeof(int));
    if(arr == NULL){
        printf("Dynamic Memory allocation not possible!");
        return 0;
    }
    printf("Enter %d elements\n", *size);
    for (i = 0; i < *size; i++)
    {
        scanf("%d", (arr + i));
    }
    while (1)
    {
        int i, j, pos, val, key;
        printf("\nEnter\n1 to insert by position\t2 to delete by position\t3 to insert by key\t4 to delete by key\n");
        printf("5 to insert by order\t6 to search by key\t7 to search by position\t8 to reverse the contents\n");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            printf("Enter position and value to be inserted:\n");
            scanf("%d%d", &pos, &val);
            insertByPosition(arr, size, pos, val);
            break;
        case 2:
            printf("Enter element's position to delete:\n");
            scanf("%d", &pos);
            int del = deleteByPosition(arr, size, pos);
            if (del != -1)
            {
                printf("The deleted value is: %d\n", del);
            }
            display(arr, size);
            break;
        case 3:
            printf("Enter key and value to be inserted:\n");
            scanf("%d%d", &key, &val);
            insertByKey(arr, size, key, val);
            break;
        case 4:
            printf("Enter key: ");
            scanf("%d", &key);
            deleteByKey(arr, size, key);
            break;
        case 5:
            for(i=1; i<*size; i++){
                for(j=0; j<*size-i; j++){
                    if(*(arr+j) > *(arr+j+1)){
                        int temp = *(arr+j);
                        *(arr+j) = *(arr+j+1);
                        *(arr+j+1) = temp;
                    }
                }
            }
            printf("Enter value to be inserted:\n");
            scanf("%d", &val);
            insertByOrder(arr, size, val);
            break;
        case 6:
            printf("Enter key to be searched:\n");
            scanf("%d", &key);
            int index = searchByKey(arr, *size, key);
            if (index != -1)
                printf("Key is found at index: %d", index);
            else
                printf("Key is not found!\n");
            break;
        case 7:
            printf("Enter position to be searched: ");
            scanf("%d", &pos);
            int val = searchByPosition(arr, size, pos);
            if (val != -1)
                printf("Value found at position: %d", val);
            else
                printf("Position is not found!");
            break;
        case 8:
            reverseContents(arr, size);
            break;
        default:
            printf("Invalid Option!");
            return 0;
        }
    }
    return 0;
}

void display(int *arr, int *size)
{
    int i;
    printf("Array is: \n");
    for (i = 0; i < *size; i++)
    {
        printf("%d ", *(arr + i));
    }
}

void insertByPosition(int *arr, int *size, int pos, int val)
{
    if (pos >= 0 && pos < *size)
    {
        for (int i = *size - 1; i >= pos; i--)
            *(arr + i + 1) = *(arr + i);
        *(arr + pos) = val;
        (*size)++;
    }
    else
    {
        printf("Position is invalid!\n");
    }
    display(arr, size);
}

int deleteByPosition(int *arr, int *size, int pos)
{
    if (pos >= 0 && pos < *size)
    {
        int val = *(arr + pos);
        for (int i = pos; i < *size; i++)
            *(arr + i) = *(arr + i + 1);
        (*size)--;
        return val;
    }else{
        printf("Invalid position!\n");
    }
    return -1;
}

void insertByKey(int *arr, int *size, int key, int val)
{
    int pos = searchByKey(arr, *size, key);
    if(pos != -1){
        insertByPosition(arr, size, pos, val);
    }else{
        printf("Key not found, Insertion not possible!\n");
    }
    // display(arr, size);
}

void deleteByKey(int *arr, int *size, int key)
{
    int pos = searchByKey(arr, *size, key);
    if(pos != -1){
        int val = deleteByPosition(arr, size, pos);
        printf("The key item %d is deleted\n", val);
    }else{
        printf("Key not found, Deletion not possible!\n");
    }
    display(arr, size);
}

void insertByOrder(int *arr, int *size, int value)
{
    int i;
    for(i=(*size)-1; *(arr+i)>=value; i--)
        *(arr+i+1) = *(arr+i);
    *(arr+i+1) = value;
    (*size)++;
    display(arr, size);
}

int searchByKey(int *arr, int size, int key)
{
    int i;
    for(i=0; i<size; i++){
        if(*(arr+i) == key) return i;
    }
    return -1;
}

int searchByPosition(int *arr, int *size, int pos)
{
    if(pos>=0 && pos<*size) return *(arr+pos);
    else printf("Invalid position, searching unsuccessful!\n");
    return -1;
}

void reverseContents(int *arr, int *size)
{
    int i, temp;
    for(i=0; i<(*size)/2; i++){
        temp = *(arr+i);
        *(arr+i) = *(arr+(*size)-i-1);
        *(arr+(*size)-i-1) = temp;
    }
    display(arr, size);
}