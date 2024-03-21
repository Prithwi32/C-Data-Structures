#include <stdio.h>
#include <stdlib.h>
struct linkedList
{
    struct node *head;
};
struct node
{
    int data;
    struct node *link;
};

struct node *createNode(int value);
void createList(struct linkedList *myList);
void display(struct linkedList *list);
void freeList(struct linkedList *list);
void insertAtBeginning(struct linkedList *list, int value);
void insertAtEnd(struct linkedList *list, int value);
void insertAtPosition(struct linkedList *list, int value, int pos);
void deleteAtBeginning(struct linkedList *list);
void deleteAtEnd(struct linkedList *list);
void deleteAtPosition(struct linkedList *list, int pos);
void deleteByKey(struct linkedList *list, int key);
void searchByKey(struct linkedList *list, int key);
void createAnOrderedList(struct linkedList *list, int data);
void reverseList(struct linkedList *list);
void copyOfList(struct linkedList* source, struct linkedList* destination);

int main()
{
    struct linkedList myList;
    createList(&myList);

    int choice, value, pos, key;
    struct linkedList copyList;
    createList(&copyList);

    while(1)
    {
        printf("\n1. Display List");
        printf("\n2. Insert at Beginning");
        printf("\n3. Insert at End");
        printf("\n4. Insert at Position");
        printf("\n5. Delete at Beginning");
        printf("\n6. Delete at End");
        printf("\n7. Delete at Position");
        printf("\n8. Delete by Key");
        printf("\n9. Search by Key");
        printf("\n10. Create an Ordered List");
        printf("\n11. Reverse List");
        printf("\n12. Create Copy of the List");
        printf("\n0. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            display(&myList);
            break;
        case 2:
            printf("Enter value to insert at the beginning: ");
            scanf("%d", &value);
            insertAtBeginning(&myList, value);
            display(&myList);
            break;
        case 3:
            printf("Enter value to insert at the end: ");
            scanf("%d", &value);
            insertAtEnd(&myList, value);
            display(&myList);
            break;
        case 4:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            printf("Enter position to insert at: ");
            scanf("%d", &pos);
            insertAtPosition(&myList, value, pos);
            break;
        case 5:
            deleteAtBeginning(&myList);
            break;
        case 6:
            deleteAtEnd(&myList);
            break;
        case 7:
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            deleteAtPosition(&myList, pos);
            break;
        case 8:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            deleteByKey(&myList, key);
            break;
        case 9:
            printf("Enter key to search: ");
            scanf("%d", &key);
            searchByKey(&myList, key);
            break;
        case 10:
            printf("Enter value to insert in an ordered list: ");
            scanf("%d", &value);
            createAnOrderedList(&myList, value);
            break;
        case 11:
            reverseList(&myList);
            break;
        case 12:
            copyOfList(&myList, &copyList);
            printf("Copy of the list created.\n");
            break;
        case 0:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid Option!");
            return 0;
        }
    }

    // Free allocated memory before exiting
    freeList(&myList);
    freeList(&copyList);
    return 0;
}

struct node *createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Dynamic Memory Allocation not possible.");
    }
    newNode->data = value;
    newNode->link = NULL;
    return (newNode);
}

void createList(struct linkedList *myList)
{
    myList = createNode(0);
    // myList->head = NULL;
}

// // display linkedList
void display(struct linkedList *list)
{
    struct node *current = list->head->link;
    while (current != NULL)
    {
        printf("%d->", current->data);
        current = current->link;
    }
}

// free List
void freeList(struct linkedList *list)
{
    struct node *current = list->head;
    struct node *next = NULL;
    while (current != NULL)
    {
        next = current->link;
        free(current);
        current = next;
    }
}

// insertion at beginning
void insertAtBeginning(struct linkedList *list, int value)
{
    struct node *newNode = createNode(value);
    struct node *current = list->head;
    newNode->link = current->link;
    current->link = newNode;
}

// insertion at end
void insertAtEnd(struct linkedList *list, int value)
{
    struct node *newNode = createNode(value);
    struct node *current = list->head;
    while (current->link != NULL)
    {
        current = current->link;
    }
    current->link = newNode;
    newNode->link = NULL;
}

// insertion at a position
void insertAtPosition(struct linkedList *list, int value, int pos)
{
    int i;
    struct node *newNode = createNode(value);
    struct node *current = list->head;
    // insert at start condition
    if (pos == 0)
    {
        newNode->link = current->link;
        current->link = newNode;
        return;
    }
    // insert at position
    for (i = 0; i <= (pos - 1 && current != NULL); i++)
    {
        current = current->link;
    }
    // position is out of range
    if (current == NULL)
    {
        printf("Invalid position, Insertion not possible\n");
        return;
    }
    // position within range
    newNode->link = current->link;
    current->link = newNode;
}

// delete at begin
void deleteAtBeginning(struct linkedList *list)
{
    struct node *current = list->head->link;
    current = current->link;
    free(current);
}

// delete at end
void deleteAtEnd(struct linkedList *list)
{
    struct node *current = list->head;
    struct node *prev = NULL;
    while (current->link != NULL)
    {
        prev = current;
        current = current->link;
    }
    prev->link = NULL;
    free(current);
}

// delete at position
void deleteAtPosition(struct linkedList *list, int pos)
{
    int i;
    struct node *current = list->head->link;
    struct node *prev = NULL;
    if (pos == 0)
    {
        list->head->link = current->link;
        free(current);
        return;
    }

    for (i = 1; i <= pos - 1 && current != NULL; i++)
    {
        prev = current;
        current = current->link;
    }
    if (current != NULL)
    {
        printf("Invalid position, Deletion not possible!");
        return;
    }
    prev->link = current->link;
    free(current);
}

// delete by key
void deleteByKey(struct linkedList *list, int key)
{
    if (list->head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct node* current = list->head;
    struct node* prev = NULL;

    // Check if the key is in the first node
    if (current != NULL && current->data == key) {
        list->head = current->link;
        free(current);
        printf("Deleted node with key %d.\n", key);
        return;
    }

    // Search for the key in the rest of the list
    while (current != NULL && current->data != key) {
        prev = current;
        current = current->link;
    }

    // If key was not present in the list
    if (current == NULL) {
        printf("Key %d not found in the list.\n", key);
        return;
    }

    // Unlink the node with the key
    prev->link = current->link;
    free(current);
    printf("Deleted node with key %d.\n", key);
}

// search by key
void searchByKey(struct linkedList *list, int key)
{
        struct node* current = list->head;
    int position = 0;

    while (current != NULL) {
        if (current->data == key) {
            printf("Key %d found at position %d.\n", key, position);
            return;
        }
        current = current->link;
        position++;
    }

    printf("Key %d not found in the list.\n", key);
}

// create an orderedList
void createAnOrderedList(struct linkedList *list, int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;

    // If the list is empty or the data is smaller than the first node
    if (list->head == NULL || data < list->head->data) {
        newNode->link = list->head;
        list->head = newNode;
        printf("Inserted %d in the ordered list.\n", data);
        return;
    }

    struct node* current = list->head;
    struct node* prev = NULL;

    // Find the correct position to insert the node
    while (current != NULL && data >= current->data) {
        prev = current;
        current = current->link;
    }

    // Insert the node
    newNode->link = current;
    prev->link = newNode;

    printf("Inserted %d in the ordered list.\n", data);
}

// reverseList
void reverseList(struct linkedList *list)
{
    struct node *current = list->head;
    struct node *prev = NULL;
    struct node *next = NULL;
    while (current != NULL)
    {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    list->head = prev;
    // display(list->head);
}

// copy of List
void copyOfList(struct linkedList* source, struct linkedList* destination)
{
    struct node* currentSource = source->head;
    struct node* currentDest = NULL;
    struct node* newNode;

    while (currentSource != NULL) {
        newNode = (struct node*)malloc(sizeof(struct node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }

        newNode->data = currentSource->data;
        newNode->link = NULL;

        if (currentDest == NULL) {
            destination->head = newNode;
            currentDest = destination->head;
        } else {
            currentDest->link = newNode;
            currentDest = currentDest->link;
        }

        currentSource = currentSource->link;
    }

    printf("List copied.\n");
}