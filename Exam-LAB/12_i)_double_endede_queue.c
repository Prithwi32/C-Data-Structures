// 12. Develop a menu driven program to implement the following types of Queues by allocating memory dynamically.
// ii) Double ended Queue

// Double Ended Queue Dynamic
#include <stdio.h>
#include <stdlib.h>
int size;

struct Queue
{
    int *queue; // Base address of array to store Queue
    int front;  // Index Of front element in Queue
    int rear;   // Index of rear element in Queue
} Q;

// Function to insert an element to rear of Queue
void pushrear(int val)
{
    // Checking if Queue is Full
    if (Q.rear == size - 1 && Q.front == 0 || Q.front > Q.rear)
    {
        printf("Queue is Full\n");
        printf("Reallocating Memory\n");
        size++;
        Q.queue = (int *)realloc(Q.queue, size * sizeof(int));
    }
    // if (Q.front == -1)
    //     Q.front = Q.rear = 0;
    // if (Q.rear == size - 1)
    // {
    //     Q.rear = 0;
    // }
    // else
    // {
    //     Q.rear++;
    // }
    Q.rear++;
    *(Q.queue + Q.rear) = val;
    if (Q.front == -1)
        Q.front = 0;
    printf("Insertion Succesfull\n");
}

// Function to insert an element to front of Queue
void pushfront(int val)
{
    // Checking if Queue is Full
    // if (Q.rear == size - 1 && Q.front == 0 || Q.front > Q.rear)
    // {
    //     printf("Queue is Full\n");
    //     printf("Reallocating Memory\n");
    //     size++;
    //     Q.queue = (int *)realloc(Q.queue, size * sizeof(int));
    // }
    // if (Q.front == -1)
    // {
    //     Q.front = Q.rear = 0;
    // }
    // else if (Q.front == 0)
    // {
    //     Q.front = size - 1;
    // }
    // else
    // {
    //     Q.front--;
    // }

    if(Q.rear == -1){
        Q.rear++;
        *(Q.queue + Q.rear) = val;
        return;
    }
    if(Q.front != 0){
        Q.front--;
    *(Q.queue + Q.front) = val;
    return;
    }
    printf("Front Insertion not possible\n");
}

// Function to delete the front element of Queue
void popfront()
{
    if (Q.front == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        // Deleting Element from front
        printf("Deleted Element : %d\n", *(Q.queue + Q.front));
        Q.front++;
        if(Q.front > Q.rear)
        Q.front = Q.rear = -1;
    }
    // if (Q.front == Q.rear)
    // {
    //     Q.front = Q.rear = -1;
    // }
    // else if (Q.front == size - 1)
    // {
    //     Q.front = 0;
    // }
    // else
    // {
    //     Q.front++;
    // }
}

// Function to delete the rear element of Queue
void poprear()
{
    if (Q.front == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        // Deleting Element from rear
        printf("Deleted Element : %d\n", *(Q.queue + Q.rear));
        Q.rear--;
        if(Q.front > Q.rear)
        Q.front = Q.rear = -1;
    }
    // if (Q.front == Q.rear)
    //     Q.front = Q.rear = -1;

    // else if (Q.rear == 0)
    //     Q.rear = size - 1;
    // else
    //     Q.rear--;
}

// Function Display all elements of Queue
void display()
{
    int i, fpos = Q.front, rpos = Q.rear;
    // Checking if Queue is Empty
    if (Q.front == -1)
    {
        printf("Queue is Empty\n");
    }
    if (fpos <= rpos)
    {
        for (i = fpos; i <= rpos; i++)
            printf("%d ", *(Q.queue + i));
    }

    else
    {
        for (i = fpos; i <= size - 1; i++)
            printf("%d ", *(Q.queue + i));
        fpos = 0;
        for (i = fpos; i <= rpos; i++)
            printf("%d ", *(Q.queue + i));
    }
    printf("\n");
}

void main()
{
    Q.front = Q.rear = -1; // Initializing Empty Queue
    int val, choice;
    printf("Enter the Size : ");
    scanf("%d", &size);
    Q.queue = (int *)malloc(size * sizeof(int)); // Dynamically Allocating Array for Queue
    printf("Main Menu\n1.Push-Front\n2.Pop-Front\n3.Push-Rear\n4.Pop-Rear\n5.Display\n6.Exit\n");
    for (;;)
    {
        printf("Enter Your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted : ");
            scanf("%d", &val);
            pushfront(val);
            break;
        case 2:
            popfront();
            break;
        case 3:
            printf("Enter the element to be inserted : ");
            scanf("%d", &val);
            pushrear(val);
            break;
        case 4:
            poprear();
            break;
        case 5:
            printf("Queue : ");
            display();
            break;
        case 6:
            printf("!! THANK YOU !!\n");
            exit(0);
        default:
            printf("Invalid Choice\nEnter Again\n");
        }
    }
}














// #include<stdio.h>
// #include<stdlib.h>

// // Structure to represent a queue
// struct queue {
//     int* a;    // Array to store elements of the queue
//     int front; // Front of the queue
//     int rear;  // Rear of the queue
// } q;

// int size; // Size of the queue

// // Function to determine the priority of an element in the queue
// int priority(int num) {
//     int i = 0;
//     while (i <= q.rear && *(q.a + i) < num) {
//         i++;
//     }
//     return i;
// }

// // Function to enqueue an element at the rear of the queue
// void renqueue() {
//     int item, i;
//     printf("Enter element to enqueue: ");
//     scanf("%d", &item);

//     // Check if the queue is full and reallocate memory if necessary
//     if (q.rear == size - 1) {
//         printf("Queue is full, reallocating memory...\n");
//         size++;
//         q.a = (int*)realloc(q.a, size * sizeof(int));
//     }

//     // If queue is empty, set front and rear to 0 and insert the element
//     if (q.front == -1) {
//         q.front = 0;
//         q.rear = 0;
//         *(q.a + q.rear) = item;
//         return;
//     }

//     // Increment rear and insert the element
//     q.rear++;
//     *(q.a + q.rear) = item;
// }

// // Function to enqueue an element at the front of the queue
// void fenqueue() {
//     int item, i;
//     printf("Enter element to enqueue: ");
//     scanf("%d", &item);

//     // Check if the queue is full and reallocate memory if necessary
//     if (q.front == 0 && q.rear == size - 1) {
//         printf("Queue is full, reallocating memory...\n");
//         size++;
//         q.a = (int*)realloc(q.a, size * sizeof(int));
//     }

//     // If queue is empty, set front and rear to 0 and insert the element
//     if (q.front == -1) {
//         q.front = 0;
//         q.rear = 0;
//         *(q.a + q.rear) = item;
//         return;
//     }

//     // If front is at the beginning, shift elements to make space for the new element
//     if (q.front == 0) {
//         for (i = q.rear; i >= 0; i--) {
//             *(q.a + i + 1) = *(q.a + i);
//         }
//         // Insert the element at the front
//         *(q.a + 0) = item;
//         q.rear++;
//         return;
//     } else {
//         // Decrement front and insert the element
//         q.front--;
//         *(q.a + q.front) = item;
//     }
// }

// // Function to dequeue an element from the front of the queue
// void fdequeue() {
//     // Check if the queue is empty
//     if (q.front == -1) {
//         printf("Queue is empty\n");
//         return;
//     }

//     // Print the dequeued element and update front
//     printf("Dequeued element: %d\n", *(q.a + q.front));

//     // If queue has only one element, set front and rear to -1
//     if (q.front == q.rear) {
//         q.front = q.rear = -1;
//     } else {
//         // Increment front
//         q.front++;
//     }
// }

// // Function to dequeue an element from the rear of the queue
// void rdequeue() {
//     // Check if the queue is empty
//     if (q.rear == -1) {
//         printf("Queue is empty\n");
//         return;
//     }

//     // Print the dequeued element and update rear
//     printf("Dequeued element: %d\n", *(q.a + q.rear));

//     // If queue has only one element, set front and rear to -1
//     if (q.front == q.rear) {
//         q.front = q.rear = -1;
//     } else {
//         // Decrement rear
//         q.rear--;
//     }
// }

// // Function to display the elements of the queue
// void display() {
//     // Check if the queue is empty
//     if (q.front == -1) {
//         printf("Queue is empty\n");
//         return;
//     }

//     // Print the elements of the queue
//     printf("Queue elements: ");
//     for (int i = q.front; i <= q.rear; i++) {
//         printf("%d ", *(q.a + i));
//     }
//     printf("\n");
// }

// // Main function
// void main() {
//     q.front = q.rear = -1;
//     int choice;
//     printf("Enter the size of the queue: ");
//     scanf("%d", &size);
//     q.a = (int*)malloc(size * sizeof(int));

//     printf("Menu:\n1. Insert at front\n2. Insert at rear\n3. Delete from front\n4. Delete from rear\n5. Display\n6. Exit\n");

//     while (1) {
//         printf("Enter your choice: ");
//         scanf("%d", &choice);
//         switch (choice) {
//             case 1:
//                 fenqueue();
//                 display();
//                 break;
//             case 2:
//                 renqueue();
//                 display();
//                 break;
//             case 3:
//                 fdequeue();
//                 display();
//                 break;
//             case 4:
//                 rdequeue();
//                 display();
//                 break;
//             case 5:
//                 display();
//                 break;
//             case 6:
//                 exit(0);
//             default:
//                 printf("Enter a valid choice\n");
//         }
//     }
// }

