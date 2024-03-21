// circular doubly linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *nlink;
    struct node *plink;
};

struct cdlist
{
    struct node *head;
};

struct node *createnode(int val){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Dynamic memory allocation not possible");
        return NULL;
    }
    newNode->data = val;
    newNode->nlink = newNode->plink = NULL;
    return (newNode);
}

void createList(struct cdlist *list)
{
    list->head = createnode(0);
}

void insertAtRear(struct cdlist *list, int val)
{
    struct node *new = createnode(val);
    if (list->head->nlink == NULL)
    {
        list->head->nlink = new;
        new->nlink = new;
        new->plink = new;
        (list->head->data)++;
        return;
    }
    struct node *last = list->head->nlink->plink;
    new->plink = last;
    last->nlink = new;
    new->nlink = list->head->nlink;
    list->head->nlink->plink = new;
    (list->head->data)++;
}

void insertAtFront(struct cdlist *list, int val)
{
    struct node *new = createnode(val);
    if (list->head->nlink == NULL)
    {
        list->head->nlink = new;
        new->nlink = new;
        new->plink = new;
        (list->head->data)++;
        return;
    }
    struct node *first = list->head->nlink;
    struct node *last = first->plink;
    new->nlink = first;
    first->plink = new;
    new->plink = last;
    last->nlink = new;
    list->head->nlink = new;
    (list->head->data)++;
}

void insertAtPosition(struct cdlist *list, int pos, int val)
{
    int i;
    if (pos < 1 || pos > (list->head->data + 1))
    {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1)
    {
        insertAtFront(list, val);
        return;
    }
    if (pos == list->head->data + 1)
    {
        insertAtRear(list, val);
        return;
    }
    struct node *new = createnode(val);
    struct node *curr = list->head;
    for (i = 1; i < pos; i++)
    {
        curr = curr->nlink;
    }
    new->plink = curr;
    new->nlink = curr->nlink;
    curr->nlink->plink = new;
    curr->nlink = new;
    (list->head->data)++;
}

void deleteAtFront(struct cdlist *list){
    struct node *curr = list->head->nlink;
    if (curr == NULL)
    {
        printf("List is Empty!\n");
        return;
    }
    if (curr->nlink == curr)
    {
        list->head->nlink = NULL;
        free(curr);
        (list->head->data)--;
        return;
    }
    struct node *last = curr->plink;
    curr->nlink->plink = last;
    last->nlink = curr->nlink;
    list->head->nlink = curr->nlink;
    (list->head->data)--;
    free(curr);
}

void deleteAtRear(struct cdlist *list)
{
    struct node *curr = list ->head->nlink;
    if (curr == NULL)
    {
        printf("List is Empty!\n");
        return;
    }
    if (curr->nlink == curr)
    {
        list->head->nlink = NULL;
        free(curr);
        (list->head->data)--;
        return;
    }
    struct node *last = curr->plink;
    last->plink->nlink = curr;
    curr->plink = last->plink;
    (list->head->data)--;
    free(last);
}

void deleteAtPosition(struct cdlist *list, int pos){
    int i;
    if (pos < 1 || pos > (list->head->data))
    {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1)
    {
        deleteAtFront(list);
        return;
    }
    if (pos == list->head->data)
    {
        deleteAtRear(list);
        return;
    }
    struct node *curr = list->head;
    for (i = 1; i < pos; i++)
    {
        curr = curr->nlink;
    }
    struct node *temp = curr->nlink;
    curr->nlink = temp->nlink;
    temp->nlink->plink = temp->plink;
    // temp->nlink->plink = curr;
    free(temp);
    (list->head->data)--;
}

int searchByKey(struct cdlist *list, int key)
{
    int i = 1;
    struct node *curr = list->head->nlink;
    if (curr == NULL)
    {
        printf("List is Empty\n");
        return -1;
    }
    do
    {
        if (curr->data == key)
        {
            return i;
        }
        i++;
        curr = curr->nlink;
    } while (curr != list->head->nlink);
    printf("Key not found\n");
    return -1;
}

void deleteByKey(struct cdlist *list, int key)
{
    int pos;
    pos = searchByKey(list, key);
    if (pos != -1)
    {
        deleteAtPosition(list, pos);
        return;
    }
    else
    {
        printf("Key not found\n");
    }
}

void reverseList(struct cdlist *list)
{
    struct node *curr = list->head->nlink;
    if (curr == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    if(curr->nlink == curr){
        printf("reverse not required\n");
        return;
    }
    struct node *temp;
    do{
        temp = curr->nlink;
        curr->nlink = curr->plink;
        curr->plink = temp;
        curr = curr->plink;

    }while(curr != list->head->nlink);
    list->head->nlink = list->head->nlink->nlink;
}

void copyList(struct cdlist *list,struct cdlist *newlist)
{
    if (list->head == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    newlist->head->data = list->head->data;
    struct node *original = list->head->nlink;
    struct node *copy = newlist->head;
    do{
        insertAtRear(newlist, original->data);
        original = original->nlink;
    }while(original != list->head->nlink);
}

void createOrderedList(struct cdlist *list, int val){
    // int i;
    // struct node *curr = list->head->nlink;
    // if(curr == NULL || curr->data > val){
    //     insertAtFront(list, val);
    //     return;
    // }
    // for(i=1; curr->data < val && curr->nlink != list->head->nlink; i++)
    // curr = curr->nlink;

    // if(curr->nlink == list->head->nlink && curr->data > val){
    //     insertAtPosition(list,i,val);
    //     return;
    // }
    // insertAtPosition(list, i+1, val);
// }

    struct node *first = list->head->nlink;
    struct node *new = createnode(val);
    if(first ==  NULL){
        list->head->nlink = new;
        new->nlink = new;
        new->plink = new;
        (list->head->data)++;
        return;
    }
    struct node *curr = list->head->nlink;
    // do{
    //     if(curr->nlink->data < val)
    //     curr = curr->nlink;
    //     else
    //     break;
    // }while(curr->nlink != first);
    // // if(curr == list->head){
    // //     insertAtFront(list, val);
    // //     return;
    // // }

    while(curr != list->head->nlink && curr->data < val)
    curr = curr->nlink;
        struct node *next = curr->nlink;
        new->nlink = next;
        next->plink = new;
        new->plink = curr;
        curr->nlink = new;
        (list->head->data)++;
    }

void display(struct cdlist *list){
    if(list->head->nlink == NULL){
        printf("List is Empty\n");
        return;
    }
    printf("List was: ");
    struct node *curr = list->head->nlink;
    do{
        printf("%d",curr->data);
        if(curr->nlink != list->head->nlink){
            printf("->");
        }
        curr = curr->nlink;
    }while(curr != list->head->nlink);
}

void search_by_pos(struct cdlist *list){
    int pos, i;
    printf("Enter position to be searched: ");
    scanf("%d", &pos);
    if(pos < 1 || pos > (list->head->data)){
        printf("Invalid position to search!");
        return;
    }
    struct node *curr = list->head->nlink;
    for(i=1; i<pos; i++){
        curr = curr->nlink;
    }
    printf("The element at %d position is: %d",pos,curr->data);
}

int main()
{
    int choice, value, pos, key, i, n;
    struct cdlist myList;
    createList(&myList);
    struct cdlist orderList;
    createList(&orderList);
    struct cdlist copy;
    createList(&copy);
    do
    {
        printf("\n\n----- Circular Doubly Linked List Menu -----\n");
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

        switch (choice)
        {
        case 0:
            printf("Exiting the program.\n");
            display(&myList);
            return 0;
            break;
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
            insertAtPosition(&myList, pos, value);
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
            pos = searchByKey(&myList, key);
            if(pos != -1){
                printf("Key element found at position: %d\n", pos);
            }
            break;
        case 9:
            printf("Enter number of nodes in ordered list:\n");
            scanf("%d", &n);
            printf("Enter a value to be inserted: ");
            for (i = 0; i < n; i++)
            {
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
            copyList(&myList, &copy);
            printf("Copy of the list: ");
            display(&copy);
            break;
        }
        case 12: search_by_pos(&myList);
        break;
        default:
            printf("Invalid Choice! Please enter a valid option.\n");
            break;
        }
    } while (choice != 0);
    return 0;
}