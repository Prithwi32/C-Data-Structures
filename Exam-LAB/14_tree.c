// 14. Develop a menu driven program to implement Binary Search tree with the following operations. i) Construction 
// ii) Traversals (Pre, In and Post Order)
// iii) Searching a node by key and displaying its information along with its parent if exists, otherwise a suitable message. 
// iv)Counting all nodes. v) Finding height.
// vi Finding node with the Maximum key value and printing the node details along with the parent.

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

void search(struct node *root, int key ){
    if(root==NULL){
        printf("No nodes\n");
        return;
    }
    struct node *prev=NULL;
    struct node *temp=root;
    while(temp!=NULL){
        if(temp->data==key){
            if(prev==NULL)
                printf("%d found and it is the root node\n",key);
            else
                printf("%d is found and it's parent node is %d\n",key,prev->data);
            return;
        }
        prev=temp;
        if(key<temp->data)
            temp=temp->llink;
        else
            temp=temp->rlink;
    }
    printf("Key not found\n");
}

void maximum(struct node *root){
    if(root==NULL){
        printf("No Nodes\n");
        return;
    }
    struct node *temp=root->rlink;
    struct node *prev=root;
    while(temp->rlink!=NULL){
        prev=temp;
        temp=temp->rlink;
    }
    printf("%d is the node with maximum value and it's parent node is %d\n",temp->data, prev->data);
}

int max(int a, int b){
    return (a>b)?a:b;
}

int height(struct node *root){
    if(root==NULL){
        return 0;
    }
    return 1+max(height(root->llink), height(root->rlink));
}


int count(struct node *root){
    int l,r;
    if(root==NULL){
        return 0;
    }
    l=count(root->llink);
    r=count(root->rlink);
    return (1+l+r);
}

int main(){
    struct node *root=(struct node *)malloc(sizeof(struct node));
    root=NULL;
    int choice, value, key,h,c;
    while(1){
        printf("\nEnter\n1.Construction\nTraversals (2.Pre, 3.In and 4.Post Order)\n5.Searching a node by key\n6.Counting all nodes\n7.Finding height\n8.Finding node with the Maximum key value\n");
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
            case 5:printf("Enter key to search\n");
            scanf("%d",&key);
            search(root, key);
            break;
            case 6:c=count(root);
            printf("Number of nodes in the tree is %d\n",c);
            break;
            case 7:h=height(root);
            printf("Height of the tree is %d\n",h);
            break;
            case 8:maximum(root);
            break;
            case 0:printf("Thank you\n");
            return 0;
            default:printf("Invalid choice\n\tTry again\n");
        }
    }
    return 0;
}