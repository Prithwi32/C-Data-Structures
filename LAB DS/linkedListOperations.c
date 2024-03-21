#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct linkedList
{
    struct node *head;
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
void copyOfList(struct linkedList *source, struct linkedList *destination);

int main()
{
    struct linkedList myList;
    createList(&myList);

    int choice, value, pos, key;
    struct linkedList copyList;
    createList(&copyList);

    do
    {
        printf("\n0. Exit\n1. Display List\n2. Insert at Beginning\n3. Insert at End\n4. Insert at Position");
        printf("\n5. Delete at Beginning\n6. Delete at End\n7. Delete at Position\n8. Delete by Key");
        printf("\n9. Search by Key\n10. Create an Ordered List\n11. Reverse List\n12. Create Copy of the List");
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
            display(&myList);
            break;
        case 5:
            deleteAtBeginning(&myList);
            display(&myList);
            break;
        case 6:
            deleteAtEnd(&myList);
            display(&myList);
            break;
        case 7:
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            deleteAtPosition(&myList, pos);
            display(&myList);
            break;
        case 8:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            deleteByKey(&myList, key);
            display(&myList);
            break;
        case 9:
            printf("Enter key to search: ");
            scanf("%d", &key);
            searchByKey(&myList, key);
            display(&myList);
            break;
        case 10:
            printf("Enter value to insert in an ordered list: ");
            scanf("%d", &value);
            createAnOrderedList(&copyList, value);
            display(&copyList);
            break;
        case 11:
            reverseList(&myList);
            display(&myList);
            break;
        case 12:
            copyOfList(&myList, &copyList);
            printf("Copy of the list created.\n");
            display(&myList);
            break;
        case 0:
            printf("Exiting program.\n");
            printf("Created List was: ");
            display(&myList);
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
            display(&myList);
        }

    } while (choice != 0);

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
        printf("Dynamic Memory Allocation not possible.\n");
        exit(EXIT_FAILURE);
        return 0;
    }
    newNode->data = value;
    newNode->link = NULL;
    return newNode;
}

void createList(struct linkedList *myList)
{
    myList->head = NULL;
}

void display(struct linkedList *list)
{
    struct node *current = list->head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->link;
    }
    printf("NULL\n");
}

void freeList(struct linkedList *list)
{
    struct node *current = list->head;
    struct node *next;
    while (current != NULL)
    {
        next = current->link;
        free(current);
        current = next;
    }
    list->head = NULL;
}

void insertAtBeginning(struct linkedList *list, int value)
{
    struct node *newNode = createNode(value);
    newNode->link = list->head;
    list->head = newNode;
}

void insertAtEnd(struct linkedList *list, int value)
{
    struct node *newNode = createNode(value);
    struct node *current = list->head;
    if (list->head == NULL)
    {
        list->head = newNode;
        return;
    }
    while (current->link != NULL)
    {
        current = current->link;
    }
    current->link = newNode;
}

void insertAtPosition(struct linkedList *list, int value, int pos)
{
    // if (pos < 0)
    // {
    //     printf("Invalid position.\n");
    //     return;
    // }
    // struct node *newNode = createNode(value);
    // struct node *current = list->head;
    // if (pos == 0)
    // {
    //     newNode->link = list->head;
    //     list->head = newNode;
    //     return;
    // }
    // for (int i = 0; i < pos - 1; i++)
    // {
    //     if (current == NULL)
    //     {
    //         printf("Invalid position.\n");
    //         return;
    //     }
    //     current = current->link;
    // }

    // newNode->link = current->link;
    // current->link = newNode;
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

void deleteAtBeginning(struct linkedList *list)
{
    if (list->head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct node *current = list->head;
    list->head = current->link;
    free(current);
}

void deleteAtEnd(struct linkedList *list)
{
    if (list->head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    } // if (list->head->link == NULL)
    // {
    //     free(list->head);
    //     list->head = NULL;
    //     return;
    // }

    // struct node *current = list->head;
    // while (current->link->link != NULL)
    // {
    //     current = current->link;
    // }

    // free(current->link);
    // current->link = NULL;
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

void deleteAtPosition(struct linkedList *list, int pos)
{
    // if (pos < 0)
    // {
    //     printf("Invalid position.\n");
    //     return;
    // }
    if (list->head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if (pos == 0)
    {
        struct node *temp = list->head;
        list->head = temp->link;
        free(temp);
        return;
    }
    struct node *current = list->head;
    for (int i = 0; i < pos - 1; i++)
    {
        if (current == NULL || current->link == NULL)
        {
            printf("Invalid position.\n");
            return;
        }
        current = current->link;
    }
    struct node *temp = current->link;
    current->link = temp->link;
    free(temp);
    // int i;
    // struct node *current = list->head->link;
    // struct node *prev = NULL;
    // if (pos == 0)
    // {
    //     list->head->link = current->link;
    //     free(current);
    //     return;
    // }

    // for (i = 1; i <= pos - 1 && current != NULL; i++)
    // {
    //     prev = current;
    //     current = current->link;
    // }
    // if (current != NULL)
    // {
    //     printf("Invalid position, Deletion not possible!");
    //     return;
    // }
    // prev->link = current->link;
    // free(current);
}

void deleteByKey(struct linkedList *list, int key)
{
    if (list->head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct node *current = list->head;
    struct node *prev = NULL;

    if (current != NULL && current->data == key)
    {
        list->head = current->link;
        free(current);
        return;
    }

    while (current != NULL && current->data != key)
    {
        prev = current;
        current = current->link;
    }

    if (current == NULL)
    {
        printf("Key %d not found in the list.\n", key);
        return;
    }

    prev->link = current->link;
    free(current);
}

void searchByKey(struct linkedList *list, int key)
{
    struct node *current = list->head;
    int position = 0;

    while (current != NULL)
    {
        if (current->data == key)
        {
            printf("Key %d found at position %d.\n", key, position);
            return;
        }
        current = current->link;
        position++;
    }

    printf("Key %d not found in the list.\n", key);
}

void createAnOrderedList(struct linkedList *list, int value)
{
    struct node *newNode = createNode(value);

    if (list->head == NULL || value < list->head->data)
    {
        newNode->link = list->head;
        list->head = newNode;
        return;
    }

    struct node *current = list->head;
    struct node *prev = NULL;

    while (current != NULL && value >= current->data)
    {
        prev = current;
        current = current->link;
    }

    newNode->link = current;
    prev->link = newNode;

    // struct node *newNode = createNode(value);
    // struct node *current = list->head;
    // while (current != NULL && current->link->data < value)
    // {
    //     current = current->link;
    // }
    // newNode->link = current->link;
    // current->link = newNode;
}

void reverseList(struct linkedList *list)
{
    struct node *prev = NULL;
    struct node *current = list->head;
    struct node *next = NULL;

    while (current != NULL)
    {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }

    list->head = prev;
}

void copyOfList(struct linkedList *source, struct linkedList *destination)
{
    struct node *currentSource = source->head;
    struct node *currentDest = NULL;
    struct node *newNode;

    while (currentSource != NULL)
    {
        newNode = createNode(currentSource->data);

        if (currentDest == NULL)
        {
            destination->head = newNode;
            currentDest = destination->head;
        }
        else
        {
            currentDest->link = newNode;
            currentDest = currentDest->link;
        }

        currentSource = currentSource->link;
    }
}
