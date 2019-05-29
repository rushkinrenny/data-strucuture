#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
    int info;
    struct node *left,*right;
};
struct node *root=NULL;
struct node *insert(struct node *);
traversal(struct node *);
display(struct node *);
search(struct node *);
preorder(struct node *);
postorder(struct node *);
inorder(struct node *);
struct node *delete(struct node *,int,int*);
int minimum(struct node *);
void main()
{
    int choice,val,updated;
    do{system("cls");
    printf("***BINARY SEARCH TREE IMPLEMENTATION***");
    printf("\n1.INSERTION\n2.DELETION\n3.SEARCH\n4.TRAVERSAL\n5.DISPLAY\n6.EXIT\nCHOICE : ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        root=insert(root);
        printf("BINARY SEARCH TREE\n");
        display(root);
        printf("\n");
        system("pause");
        break;
    case 2:
        printf("Enter element to be deleted : ");
        scanf("%d", &val);
        updated = 0;
        root = delete(root,val, &updated);
        if(updated){
            printf("\n%d deleted from the BST\n", val);
            predisplay(root);
        }
        else
            printf("\n%d is not found in the BST", val);
            printf("\n");
        system("pause");
            break;

    case 3:
        search(root);
        printf("\n");
        system("pause");
        break;
    case 4:
        predisplay(root);
        printf("\n\nPreorder  : ");
        preorder(root);
        printf("\n\nInorder   : ");
        inorder(root);
        printf("\n\nPostorder : ");
        postorder(root);
        printf("\n");
        system("pause");
        break;

    case 5:
        predisplay(root);
        printf("\n");
        system("pause");
        break;
    case 6:
        printf("BYE....HAVE A NICE DAY");

    }

}while(choice!=6);
}
struct node *insert(struct node *root )
{ struct node *new_node,*ptr=root;
int val;
new_node =(struct node *)malloc(sizeof(struct node));
printf("Enter the value to be inserted : ");
scanf("%d",&val);
new_node->info=val;
new_node->left=NULL;
new_node->right=NULL;
    if(ptr==NULL)
        root=new_node;
    else
    {
        while(1){
            if(val<ptr->info)
            {
                if(ptr->left==NULL)
                {
                    ptr->left=new_node;
                    break;
                }
                ptr=ptr->left;
            }
            else
            {
                if(ptr->right==NULL)
                {
                    ptr->right=new_node;
                    break;
                }
                ptr=ptr->right;
            }

    }
    }
     return root;
}
void predisplay(struct node *root){
    if(root==NULL)
        printf("\nBinary Search Tree is empty...");
    else{
        printf("\nBinary Search Tree : \n");
        display(root);
    }
}


display(struct node *ptr)
{
    if(ptr!=NULL)
    {
        printf(" %d ",ptr->info);
        if(ptr->left!=NULL||ptr->right!=NULL)
            printf("(");
        display(ptr->left);
        display(ptr->right);
        if(ptr->left!=NULL||ptr->right!=NULL)
            printf(")");
    }

}
search(struct node *ptr)
{ int val;
    printf("Enter the value to be search : ");
    scanf("%d",&val);
    while(ptr!=NULL)
    {
        if(ptr->info==val)
        {
            printf("%d is searched in Binary search tree...",val);
            break;
        }
        else if(ptr->info>val)
            ptr=ptr->left;
        else
            ptr=ptr->right;
    }
    if(ptr==NULL)
        printf("%d is not found in Binary Search Tree...",val);
}

preorder(struct node *ptr)
{
    if(ptr!=NULL)
    {
        printf(" %d ",ptr->info);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}
inorder(struct node *ptr)
{
    if(ptr!=NULL)
    {
        inorder(ptr->left);
        printf(" %d ",ptr->info);
        inorder(ptr->right);
    }
}
postorder(struct node *ptr)
{
    if(ptr!=NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        printf(" %d ",ptr->info);

    }
}
struct node* delete(struct node *root, int element, int *updated){
    if(root == NULL) return root;
    else if(root->info > element) root->left = delete(root->left, element, updated);
    else if(root->info < element) root->right = delete(root->right, element, updated);
    else{
        *updated = 1;
        if(root->left==NULL && root->right==NULL){
            free(root);
            root = NULL;
        }
        else if(root->left==NULL){
            struct node *temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right==NULL){
            struct node *temp = root;
            root = root->left;
            free(temp);
        }
        else{
            int temp = minimum(root->right);        //Using minimum of Right
            root->info = temp;
            root->right = delete(root->right, temp, updated);
        }
        return root;
    }

}
int minimum(struct node *current){
    while(1){
        if(current->left == NULL)
            return current->info;
        current = current->left;
    }
}
