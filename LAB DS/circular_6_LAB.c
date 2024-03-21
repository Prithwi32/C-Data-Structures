#include <stdio.h>
#include <stdlib.h>
int count = 0;
struct node
{
    int data;
    struct node *link;
};
struct cList
{
    struct node *head;
};

void createList(struct cList *myList);
struct node *createNode(int val);
void display(struct cList *list);
void insertAtFront(struct cList *list, int val);
void insertAtRear(struct cList *list, int val);
void insertAtPosition(struct cList *list, int val, int pos);
void deleteAtFront(struct cList *list);
void deleteAtRear(struct cList *list);
void deleteAtPosition(struct cList *list, int pos);

int main()
{
    int choice, value, pos;
    struct cList myList;
    createList(&myList);
    while (1)
    {
        printf("\n0. Exit\n1. Insert at Front\n2. Insert at Rear\n3. Insert at Position");
        printf("\n4. Delete at Front\n5. Delete at Rear\n6. Delete at Position\n7. Delete by Key");
        printf("\n8. Search by Key\n9. Create an Ordered List\n10. Reverse List\n11. Create Copy of the List");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            printf("Exiting program.\n");
            printf("Created List was: ");
            display(&myList);
            break;
        case 1:
            printf("Enter a value to insert at beginning: ");
            scanf("%d", &value);
            insertAtFront(&myList, value);
            display(&myList);
            break;
        case 2:
            printf("Enter a value to insert at end: ");
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
            printf("Enter position of node to delete: ");
            scanf("%d", &pos);
            deleteAtPosition(&myList, pos);
            display(&myList);
            break;
        default:
            printf("Invalid Choice!");
            return 0;
        }
    }
    return 0;
}

void createList(struct cList *myList)
{
    myList->head = createNode(count);
    myList->head->link = NULL;
}

// void createList(struct cList *myList)
// {
//     myList->head = createNode(0);      // Allocate memory for the head node
//     myList->head->link = myList->head; // Circular link to itself
// }

// function to create nodes
struct node *createNode(int val)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    if (new == NULL)
    {
        printf("Dynamic Memory Allocation Not Possible!");
    }
    new->data = val;
    new->link = NULL;
    return (new);
}

// display Circular LinkedList
void display(struct cList *list)
{
    struct node *temp = list->head->link;
    if (temp == NULL)
    {
        printf("List is Empty!");
    }
    while (temp->link != list->head->link)
    {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("%d", temp->data);
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

// insert at position
void insertAtPosition(struct cList *list, int val, int pos)
{
    int i;
    struct node *current = list->head->link;
    struct node *newNode = createNode(val);
    if (pos == 0)
    {
        insertAtFront(list, val);
    }
    else if (pos == count)
    {
        insertAtRear(list, val);
    }
    else
    {
        for (i = 1; i < pos - 1 && current->link != list->head->link; i++)
        {
            current = current->link;
        }
        if (current->link == list->head->link)
        {
            printf("Invalid position, Insertion not possible.");
            return;
        }
        newNode->link = current->link;
        current->link = newNode;
        count++;

        // while(current->link != list->head->link){
        //     cnt++;
        //     if(cnt == pos-1){
        //         newNode->link = current->link;
        //         current->link = newNode;
        //     }
        //     current = current->link;
        // }
        // count++;
    }
}

// delete at Start
void deleteAtFront(struct cList *list)
{
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

// delete at Rear
void deleteAtRear(struct cList *list)
{
    struct node *tail = list->head->link;
    struct node *prev = NULL;
    if (list->head->link == NULL)
    {
        printf("Empty List!, Nothing to delete");
        return;
    }
    else if (tail->link == tail)
    {
        free(tail);
        list->head->link = NULL;
        count--;
        return;
    }
    else
    {
        while (tail->link != list->head->link)
        {
            prev = tail;
            tail = tail->link;
        }
        prev->link = tail->link;
        free(tail);
        count--;
    }
}

// delete at position
void deleteAtPosition(struct cList *list, int pos)
{
    int i;
    struct node *current = list->head->link;
    struct node *prev = NULL;
    if (pos == 0)
    {
        deleteAtFront(list);
        return;
    }
    else if (pos == count)
    {
        deleteAtRear(list);
        return;
    }
    else
    {
        for (i = 1; i < (pos-1 && current->link != list->head->link); i++)
        {
            prev = current;
            current = current->link;
        }
        if(current->link == list->head->link){
            printf("Invalid position to delete!");
            return;
        }
        prev->link = list->head->link;
        free(current);
        count--;
    }
}