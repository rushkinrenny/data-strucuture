#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
    struct node *prev;
    int info;
    struct node *next;
};
struct node *insert_beg(struct node *);
struct node *insert_end(struct node*);
struct node *insert_after(struct node*);
struct node *delete_beg(struct node*);
struct node *delete_end(struct node*);
struct node *delete_val(struct node*);
struct node *display(struct node *);
struct node *start=NULL;
void main()
{
    int choice;
    do{
    printf("\t\t****MAIN MENU****");
    printf("\nDouble  LINKED LIST");
    printf("\n1.Insert at begging\n2.Insert at end\n3.Insert after node\n4.Delete at begging\n5.Delete at end\n6.Delete at value\n7.Display\n8.Exit");
    printf("\nEnter the choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        start=insert_beg(start);
        printf("\n");
        system("pause");
        system("cls");break;
    case 2:
        start=insert_end(start);
        printf("\n");
        system("pause");
        system("cls");break;
    case 3:
        start=insert_after(start);
        printf("\n");
        system("pause");
        system("cls");break;
    case 4:
        start=delete_beg(start);
        printf("\n");
        system("pause");
        system("cls");break;
    case 5:
        start=delete_end(start);
        printf("\n");
        system("pause");
        system("cls");break;
    case 6:
        start=delete_val(start);
        printf("\n");
        system("pause");
        system("cls");break;

    case 7:
        start=display(start);
        printf("\n");
        system("pause");
        system("cls");
        break;
    }
 }while(choice!=8);
}
struct node* insert_beg(struct node *start)
{   struct node *new_node;
    int num;
  new_node=(struct node *)malloc(sizeof(struct node));
  printf("Enter the element : ");
  scanf("%d",&num);
  new_node->info=num;
  if(start==NULL)
  {

      new_node->next=NULL;
      new_node->prev=NULL;
      start=new_node;
  }
  else
  {
      new_node->next=start;
      start->prev=new_node;
      new_node->prev=NULL;
      start=new_node;

  }
  return start;
}
struct node *insert_end(struct node *start)
{
 struct node *new_node,*ptr;
 new_node=(struct node *)malloc(sizeof(struct node));
 if(start==NULL)
        printf("DOUBLE LINKED LIST IS EMPTY...");
 else{
    int num;
    printf("Enter the Element : ");
    scanf("%d",&num);
    new_node->info=num;
    new_node->next=NULL;
    ptr = start;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    ptr->next=new_node;
    new_node->prev=ptr;

 }
 return start;
}
struct node *insert_after(struct node *start)
{ int val,num;
 struct node *ptr,*new_node;
 new_node=(struct node *)malloc(sizeof(struct node));
 ptr=start;
 if(start==NULL)
    printf("DOUBLE LINKED LIST IS EMPTY...");
 else{ printf("Enter the value after which new node is inserted : ");
       scanf("%d",&val);
 while(ptr->info!=val&&ptr->next!=NULL)
        ptr=ptr->next;
 if(ptr->next==NULL && ptr->info!=val)
    printf("%d is not found in the Double liked list...",val);
 else
 { printf("Enter the element : ");
 scanf("%d",&num);
  new_node->info =num;
  if(ptr->next==NULL)
  {
      new_node->prev=ptr;
      new_node->next=NULL;
      ptr->next=new_node;
  }
  else{
     new_node->prev=ptr;
     new_node->next=ptr->next;
     ptr->next->prev=new_node;
     ptr->next=new_node;
  }
 }
}
 return start;
}
struct node *delete_beg(struct node *start)
{ struct node *ptr;
   ptr=start;
    if(start==NULL)
        printf("UNDERFLOW");
        else if(start->next==NULL)
        {
            printf("%d is deleted from Double linked list...",ptr->info);
            start=NULL;
            free(ptr);
        }
    else{ start=start->next;
         start->prev=NULL;
         printf("%d is deleted from Double linked list...",ptr->info);
         free(ptr);
    }
    return start;
}
struct node *delete_end(struct node *start)
{ struct node *ptr;
ptr=start;
  if(start==NULL)
        printf("UNDERFLOW");
  else if(start->next==NULL)
  {
      printf("%d is deleted from Double linked list...",ptr->info);
      start=NULL;
      free(ptr);
  }
  else
  {
      while(ptr->next!=NULL)
        ptr=ptr->next;
      ptr->prev->next=NULL;
      printf("%d is deleted from Double linked list...",ptr->info);
      free(ptr);

  }
  return start;
}
struct node *delete_val(struct node *start)
{
 struct node *ptr;
 int val;
 ptr=start;
 if(start==NULL)
    printf("UNDERFLOW");
 else{
        printf("Enter the value, which node is deleted : ");
        scanf("%d",&val);
 while(ptr->info!=val&&ptr->next!=NULL)//Terminate when either value is found or not
        ptr=ptr->next;
        if(ptr->next==NULL&&ptr->info!=val)
            printf("%d is not  found in the Double linked list...",val);
        else if((ptr->next==NULL&&ptr->prev!=NULL)&&ptr->info==val)//case when the value at last node
        {
            ptr->prev->next=NULL;
            printf("%d is deleted from double linked list...",ptr->info);
            free(ptr);
        }
        else if(ptr->next==NULL&&ptr->prev==NULL)//when only single node is rest
        {
            printf("%d is deleted from linked list...",ptr->info);
            start=NULL;
            free(ptr);
        }
        else if(ptr->prev==NULL&&ptr->next!=NULL)//case when the value at first node
        {
            start=start->next;
            start->prev=NULL;
            printf("%d is deleted from Double linked list...",ptr->info);
            free(ptr);
        }
        else{
             ptr->prev->next=ptr->next;
             ptr->next=ptr->prev;
             printf("%d  is deleted from Double linked list...",ptr->info);
             free(ptr);
        }
 }
        return start;
}
struct node *display(struct node *start)
{
 if(start==NULL)
        printf("DOUBLE LINKED IS EMPTY...");
 else
 {
     struct node *ptr;
     ptr=start;
     printf("DOUBLE LINKED LIST : \n");
     while(ptr!=NULL)
     {
         printf(" %p | %d [%p] %p ",ptr->prev,ptr->info,ptr,ptr->next);
         if(ptr->next==NULL)
           ;
         else
            printf(" <=> ");
         ptr=ptr->next;
     }
     printf("\n\nIn DOUBLE LINKED LIST, PREV PART OF FIRST NODE HAS NULL AND NEXT PART OF LAST NODE HAS NULL...\n");
 } return start;
}
