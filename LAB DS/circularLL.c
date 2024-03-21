#include <stdio.h>
#include <stdlib.h>
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
void insertAtEnd(struct cList *list, int val);
void print(struct cList *list);

int main()
{
    struct cList myList;
    createList(&myList);
    insertAtEnd(&myList, 1);
    insertAtEnd(&myList, 2);
    insertAtEnd(&myList, 3);
    print(&myList);
    return 0;
}

void createList(struct cList *myList)
{
    myList->head->link = NULL;
}

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

// insert node At End
void insertAtEnd(struct cList *list, int val)
{
    struct node *current = list->head->link;
    struct node *newNode = createNode(val);
    if (current == NULL)
    {
        list->head->link = newNode;
        newNode->link = newNode;
        return;
    }
        do{
            current = current->link;
        }while(current->link != list->head->link);
        newNode->link = current->link;
        current->link = newNode;
}

// display Circular LinkedList
void print(struct cList *list){
    struct node *temp = list->head->link;
    if(temp == NULL){
        printf("List is Empty!");
    }
    do{
        printf("%d -> " , temp->data);
        temp = temp->link;
    }while(temp->link != list->head->link);
    printf("%d -> ", temp->data);
    printf("%d", temp->link->data);
}