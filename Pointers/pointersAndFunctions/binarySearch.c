// #include <stdio.h>
// int bs(int arr[], int n, int key)
// {
//     int *ptr1, *ptr2;
//     ptr1 = arr;
//     ptr2 = &arr[n];
//     while (ptr1 <= ptr2){
//         int *mid = ptr1 + (ptr2-ptr1) / 2;
//         if(arr[*mid] == key) return *mid;
//         else if(arr[*mid] > key) ptr2 = mid - 1;
//         else ptr1 = mid + 1;
//     }
//     return -1;
// }
// int main()
// {
//     int n, arr[20], key;
//     printf("Enter size of array: ");
//     scanf("%d", &n);
//     printf("Enter array Elements: ");
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
//     printf("Enter key you want to search: ");
//     scanf("%d", &key);
//     int ans = bs(arr, n, key);
//     printf("Key is found at the index: %d",ans);

//     return 0;
// }


#include <stdio.h>

int binarySearch(int *arr, int n, int x) {
    int *low = arr, *high = arr + n - 1;
    while (low <= high) {
        int *mid = low + (high - low) / 2;
        if (*mid == x) {
            return mid - arr;
        } else if (*mid < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 5;
    int result = binarySearch(arr, n, x);
    if (result == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", result);
    }
    return 0;
}