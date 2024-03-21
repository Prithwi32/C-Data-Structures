// 15. Develop a menu driven program to implement Binary Search tree with the followingoperations. i) Construction ii) Traversals (Pre, In and Post Order) iii) Searching a node by key and deleting if exists ( node to be deleted may be leaf or non- leaf with one child ortwo children)

#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *llink, *rlink;
};
struct node *createNode(int value){
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("Memory allocation is not possible\n");
        return NULL;
    }
    newNode->data=value;
    newNode->llink=newNode->rlink=NULL;
    return newNode;
}

struct node *construct(struct node *root, int value){
    struct node *newNode=createNode(value);
    if(root==NULL){
        root=newNode;
        return root;
    }
    if(value<root->data){
        root->llink=construct(root->llink,value);
    }
    else{
        root->rlink=construct(root->rlink, value);
    }
    return root;
}

void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->llink);
        printf("%d\t",root->data);
        inorder(root->rlink);
    }
}

void preorder(struct node *root){
    if(root!=NULL){
        printf("%d\t",root->data);
        preorder(root->llink);
        preorder(root->rlink);
    }
}

void postorder(struct node *root){
    if(root!=NULL){
        postorder(root->llink);
        postorder(root->rlink);
        printf("%d\t",root->data);
    }
}

struct node *deleteKey(struct node *root, int key){
    struct node *temp=root, *q, *suc, *parent=NULL;
    while(temp!=NULL){
        if(temp->data==key)
        break;
        parent=temp;
        if(temp->data<key)
            temp=temp->rlink;
        else
            temp=temp->llink;
    }
    if(temp==NULL){
        printf("Key not found\n");
        return root;
    }
    if(temp->llink==NULL){
        q=temp->rlink;
    }
    else if(temp->rlink==NULL){
        q=temp->llink;
    }
    else{
        q=suc=temp->rlink;
        while(suc->llink!=NULL){
            suc=suc->llink;
        }
        suc->llink=temp->llink;
    }
    if(parent==NULL)
        return q;
    if(parent->llink==temp)
        parent->llink=q;
    else
        parent->rlink=q;
    printf("Deleted element is %d it's parent is %d\n",key, parent->data);
    free(temp);
    return root;
}

int main(){
    struct node *root=(struct node *)malloc(sizeof(struct node));
    root=NULL;
    int choice, value, key,h,c;
    while(1){
        printf("\nEnter\n1.Construction\nTraversals (2.Pre, 3.In and 4.Post Order)\n5.Searching a node by key and delete that node\n");
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("Enter element : ");
            scanf("%d",&value);
            root=construct(root, value);
            break;
            case 2:preorder(root);
            break;
            case 3:inorder(root);
            break;
            case 4:postorder(root);
            break;
            case 5:printf("Enter key to search and delete\n");
            scanf("%d",&key);
            root=deleteKey(root, key);
            printf("\nAfter deleting a node inorder : ");
            inorder(root);
            printf("\nAfter deleting a node preorder : ");
            preorder(root);
            printf("\nAfter deleting a node postorder : ");
            postorder(root);
            break;
            case 0:printf("Thank you\n");
            return 0;
            default:printf("Invalid choice\n\tTry again\n");
        }
    }
    return 0;
}