#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct cList {
    struct node *head;
};

int count = 0;

void createList(struct cList *myList);
struct node *createNode(int val);
void display(struct cList *list);
void insertAtFront(struct cList *list, int val);
void insertAtRear(struct cList *list, int val);
void insertAtPosition(struct cList *list, int val, int pos);
void deleteAtFront(struct cList *list);
void deleteAtRear(struct cList *list);
void deleteAtPosition(struct cList *list, int pos);
void deleteByKey(struct cList *list, int key);
void searchByKey(struct cList *list, int key);
void createOrderedList(struct cList *list, int val);
void reverseList(struct cList *list);
struct cList *copyList(struct cList *list);
void search_by_pos(struct cList *list);

void main() {
    int choice, value, pos, key, i;
    struct cList myList;
    createList(&myList);
    struct cList orderList;
    createList(&orderList);

    do {
        printf("\n\n----- Circular Singly Linked List Menu -----\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Front\n");
        printf("5. Delete at Rear\n");
        printf("6. Delete at Position\n");
        printf("7. Delete by Key\n");
        printf("8. Search by Key\n");
        printf("9. Create an Ordered List\n");
        printf("10. Reverse the List\n");
        printf("11. Create a Copy of the List\n");
        printf("12. Search by Position\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter a value to insert at front: ");
            scanf("%d", &value);
            insertAtFront(&myList, value);
            display(&myList);
            break;
        case 2:
            printf("Enter a value to insert at rear: ");
            scanf("%d", &value);
            insertAtRear(&myList, value);
            display(&myList);
            break;
        case 3:
            printf("Enter a value to insert: ");
            scanf("%d", &value);
            printf("Enter a position to insert: ");
            scanf("%d", &pos);
            insertAtPosition(&myList, value, pos);
            display(&myList);
            break;
        case 4:
            deleteAtFront(&myList);
            display(&myList);
            break;
        case 5:
            deleteAtRear(&myList);
            display(&myList);
            break;
        case 6:
            printf("Enter a position to delete: ");
            scanf("%d", &pos);
            deleteAtPosition(&myList, pos);
            display(&myList);
            break;
        case 7:
            printf("Enter a key to delete: ");
            scanf("%d", &key);
            deleteByKey(&myList, key);
            display(&myList);
            break;
        case 8:
            printf("Enter a key to search: ");
            scanf("%d", &key);
            searchByKey(&myList, key);
            break;
        case 9:
            printf("Enter number of nodes in ordered list:\n");
            scanf("%d",&key);
            printf("Enter a value to be inserted: ");
            for(i=0; i<key; i++){
            scanf("%d", &value);
            createOrderedList(&orderList, value);
        }
            display(&orderList);
            break;
        case 10:
            reverseList(&myList);
            display(&myList);
            break;
        case 11:
            {
                struct cList *copy = copyList(&myList);
                printf("Copy of the list: ");
                display(copy);
                break;
            }
        case 12: search_by_pos(&myList);
        break;
        case 0:
            printf("Exiting the program.\n");
            exit(0);
            break;
        default:
            printf("Invalid Choice! Please enter a valid option.\n");
            break;
        }
    }while(choice != 0);
}

void createList(struct cList *myList) {
    myList->head = createNode(0); // Allocate memory for the head node
    myList->head->link = NULL;// Circular link to itself
}

struct node *createNode(int val) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Dynamic Memory Allocation Not Possible!");
        return NULL;
    }
    newNode->data = val;
    newNode->link = NULL;  // Initialize link to NULL
    return newNode;
}

void display(struct cList *list) {
    struct node *temp = list->head->link;
    if (temp == NULL) {
        printf("List is Empty!\n");
        return;
    }
    printf("List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->link;
    } while (temp != list->head->link);
}

// insert node at Start
void insertAtFront(struct cList *list, int val)
{
    struct node *current = list->head->link;
    struct node *newNode = createNode(val);

    if (list->head->link == NULL)
    {
        list->head->link = newNode;
        newNode->link = newNode;
        count++;
        return;
    }

    while (current->link != list->head->link)
    {
        current = current->link;
    }
    current->link = newNode;
    newNode->link = list->head->link;
    list->head->link = newNode;
    count++;
}

// insert node At End
void insertAtRear(struct cList *list, int val)
{
    struct node *current = list->head->link;
    struct node *newNode = createNode(val);
    if (current == NULL)
    {
        list->head->link = newNode;
        newNode->link = newNode;
        count++;
        return;
    }
    do
    {
      current = current->link;
    } while (current->link != list->head->link);
    newNode->link = current->link;
    current->link = newNode;
    count++;
}

void insertAtPosition(struct cList *list, int val, int pos) {
    if (pos < 0 || pos > count) {
        printf("Invalid position, Insertion not possible.\n");
        return;
    }

    if (pos == 0) {
        insertAtFront(list, val);
        return;
    }

    if (pos == count) {
        insertAtRear(list, val);
        return;
    }

    int i;
    struct node *current = list->head->link;
    struct node *newNode = createNode(val);

    for (i = 1; i < pos; i++) {
        current = current->link;
    }

    newNode->link = current->link;
    current->link = newNode;
    count++;
}

void deleteAtFront(struct cList *list) {
    struct node *current = list->head->link;
    struct node *tail = list->head->link;
    if (list->head->link == NULL)
    {
        // printf("Nothing to delete, List is Empty!");
        return;
    }
    else if (tail->link == list->head->link)
    {
        free(current);
        list->head->link = NULL;
        count--;
        return;
    }
    else
    {
        while (tail->link != list->head->link)
        {
            tail = tail->link;
        }
        tail->link = current->link;
        list->head->link = current->link;
        free(current);
        count--;
    }
}

void deleteAtRear(struct cList *list) {
    if (list->head->link == list->head) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct node *current = list->head->link;
    struct node *previous = NULL;

    while (current->link != list->head->link) {
        previous = current;
        current = current->link;
    }

    if (previous != NULL) {
        previous->link = list->head->link;
        free(current);
        count--;
    } else {
        // Only one element in the list
        free(current);
        list->head->link = NULL;
        count = 0;
    }
}

void deleteAtPosition(struct cList *list, int pos) {
    if (pos < 0 || pos >= count) {
        printf("Invalid position, Deletion not possible.\n");
        return;
    }

    if (pos == 0) {
        deleteAtFront(list);
        return;
    }

    if (pos == count - 1) {
        deleteAtRear(list);
        return;
    }

    int i;
    struct node *current = list->head->link;
    struct node *previous = NULL;

    for (i = 0; i < pos; i++) {
        previous = current;
        current = current->link;
    }

    previous->link = current->link;
    free(current);
    count--;
}

void deleteByKey(struct cList *list, int key) {
    struct node *current = list->head->link;
    struct node *previous = NULL;

    while (current->link != list->head->link && current->data != key) {
        previous = current;
        current = current->link;
    }

    if (current->data == key) {
        if (previous != NULL) {
            previous->link = current->link;
        } else {
            // Deleting the first node
            list->head->link = current->link;
        }
        free(current);
        count--;
        printf("Node with key %d deleted successfully.\n", key);
    } else {
        printf("Node with key %d not found.\n", key);
    }
}

void searchByKey(struct cList *list, int key) {
    struct node *current = list->head->link;
    int position = 0;
    while (current->link != list->head->link && current->data != key) {
        current = current->link;
        position++;
    }

    if (current->data == key) {
        printf("Key %d found at position %d.\n", key, position);
    } else {
        printf("Key %d not found in the list.\n", key);
    }
}

void createOrderedList(struct cList *list, int val) {
    struct node *newNode = createNode(val);
    struct node *current = list->head;
    if(current == NULL || current->data > val){
        newNode->link = current;
        list->head = newNode;
        return;
    }

    while (current->link != NULL && current->link->data < val) {
        current = current->link;
    }
    newNode->link = current->link;
    current->link = newNode;
}

void reverseList(struct cList *list) {
    // Check if the list is empty or has only one node
    if (list == NULL || list->head == NULL || list->head->link == list->head) {
        return;
    }

    struct node *current = list->head->link;
    struct node *previous = NULL;
    struct node *nextNode = NULL;

    do {
        nextNode = current->link;
        current->link = previous;
        previous = current;
        current = nextNode;
    } while (current != list->head->link);

    list->head->link = previous;
}

struct cList *copyList(struct cList *list) {
    struct cList *copyList = (struct cList *)malloc(sizeof(struct cList));
    createList(copyList);

    struct node *current = list->head->link;

    while (current->link != list->head->link) {
        insertAtRear(copyList, current->data);
        current = current->link;
    }

    // Copy the last node
    insertAtRear(copyList, current->data);

    return copyList;
}

void search_by_pos(struct cList *list){
    int pos, i;
    struct node *curr = list->head->link;
    printf("Enter position to search: ");
    scanf("%d",&pos);
    if(pos < 0 || pos > count){
        printf("Invalid position to search!");
        return;
    }
    for(i=0; i<pos; i++){
        curr = curr->link;
    }
    printf("Element at %d position is: %d",pos,curr->data);
}

