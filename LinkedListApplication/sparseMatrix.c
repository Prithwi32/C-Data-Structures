// #include <stdio.h>
// #include <stdlib.h>
// struct node
// {
//     int value, row, col;
//     struct node *link;
// };
// struct list
// {
//     struct node *head;
// };
// void createList(struct cList *myList)
// {
//     myList->head->link = NULL;
// }
// void createHead(struct list *l){
//         l->head->row = -1;
//         l->head->col = -1;
//         l->head->link = NULL;

//         return;
// }
// struct node *createnode(int row, int col, int val)
// {
//     struct node *newnode = (struct node *)malloc(sizeof(struct node));
//     if (newnode == NULL)
//     {
//         printf("Dynamic Memory Allocation Not Possible!");
//     }
//     newnode->value = val;
//     newnode->row = row;
//     newnode->col = col;
//     newnode->link = NULL;

//     return (newnode);
// }

// void insertnode(struct list *l, int row, int col, int val)
// {
//     struct node *new = createnode(row, col, val);
//     if (l->head == NULL)
//     {
//         l->head = createnode(-1, -1, 0);
//         l->head->link = new;
//         return;
//     }
//     struct node *current = l->head->link;
//     while (current->link != NULL)
//     {
//         current = current->link;
//     }
//     current->link = new;
// }

// void display(struct list *l, int m, int n)
// {   int i, j;
//     struct node *current = l->head->link;
//     if(l->head->link == NULL) return;
//         for (i = 0; i < m; i++)
//         {
//             for (j = 0; j < n; j++)
//             {
//                 if (current != NULL && current->row == i && current->col == j)
//                 {
//                     printf("%d ", current->value);
//                     current = current->link;
//                 }else{
//                     printf("0 ");
//                 }
//             }
//                 printf("\n");
//         }
// }
// int main()
// {
//     struct list sparseMatrix;
//     // sparseMatrix.head = NULL;
//     createList(&sparseMatrix);
//     insertnode(&sparseMatrix, 1, 0, 2);
//     display(&sparseMatrix, 3, 3);

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value, row, col;
    struct node *link;
};

struct list
{
    struct node *head;
};

// void createHead(struct list *l)
// {
//     l->head = (struct node *)malloc(sizeof(struct node));
//     if (l->head == NULL)
//     {
//         printf("Dynamic Memory Allocation Not Possible!");
//         exit(1);
//     }
//     l->head->row = -1;
//     l->head->col = -1;
//     l->head->link = NULL;
// }

struct node *createnode(int row, int col, int val)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Dynamic Memory Allocation Not Possible!");
        exit(1);
    }
    newnode->value = val;
    newnode->row = row;
    newnode->col = col;
    newnode->link = NULL;

    return newnode;
}

void insertnode(struct list *l, int row, int col, int val)
{
    struct node *new = createnode(row, col, val);
    if (l->head == NULL)
    {
        l->head = createnode(-1, -1, 0);
        l->head->link = new;
        return;
    }
    if (l->head->link == NULL)
    {
        l->head->link = new;
        return;
    }
    struct node *current = l->head->link;
    while (current->link != NULL)
    {
        current = current->link;
    }
    current->link = new;
}

void display(struct list *l, int m, int n)
{
    int i, j;
    struct node *current = l->head->link;
    if (current == NULL)
        return;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (current != NULL && current->row == i && current->col == j)
            {
                printf("%d ", current->value);
                current = current->link;
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main()
{
    struct list sparseMatrix;
    sparseMatrix.head = NULL; // Initialize head to NULL
    // createHead(&sparseMatrix);
    insertnode(&sparseMatrix, 0, 1, 1);
    insertnode(&sparseMatrix, 1, 0, 2);
    display(&sparseMatrix, 3, 3);

    return 0;
}
