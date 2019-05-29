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
    printf("\nCIRCULAR DOUBLE  LINKED LIST");
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
        system("cls");break;
    }
 }while(choice!=8);
}
struct node *insert_beg(struct node *start)
{
    struct node *new_node,*ptr;
    int val;
    printf("Enter the value : ");
    scanf("%d",&val);
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->info=val;
    if(start==NULL)
    {
        new_node->next=new_node;
        new_node->prev=new_node;
        start=new_node;
    }
    else
    { ptr=start;
        while(ptr->next!=start)
            ptr=ptr->next;
        new_node->next=start;
        new_node->prev=ptr;
        start->prev=new_node;
        ptr->next=new_node;
        start=new_node;
    } return start;
}
struct node *insert_end(struct node *start)
{ struct node *ptr,*new_node;
 int val;
ptr=start;
 if(start==NULL)
        printf("CIRCULAR DOUBLE LINKED LIST IS EMPTY");
 else{ printf("Enter the value : ");
      scanf("%d",&val);
      new_node=(struct node*)malloc(sizeof(struct node));
      new_node->info=val;
 while(ptr->next!=start)
    ptr=ptr->next;
   new_node->next=start;
    new_node->prev=ptr;
    start->prev=new_node;
    ptr->next=new_node;

 }
   return start;
}
struct node *insert_after(struct node *start)
{ struct node *ptr,*new_node;
  int num,val;
  new_node=(struct node *)malloc(sizeof(struct node));
  ptr=start;
  if(start==NULL)
        printf("CIRCULAR DOUBLE LINKED LIST IS EMPTY");
  else
  {
    printf("Enter the info part of that node,after which new node is inserted : ");
    scanf("%d",&num);
    while(ptr->next!=NULL&&ptr->info!=num)
        ptr=ptr->next;
    if(ptr->next==NULL&&ptr->info!=num)
        printf("%d is not found in the circular linked list");
    else if(ptr==start&&ptr->next==start)////case when the value at first node
    {
        printf("Enter the value : ");
        scanf("%d",&val);
        new_node->info=val;
        new_node->next=start;
        new_node->prev=ptr;
        ptr->next=new_node;
        ptr->prev=new_node;
    }
    else if(ptr->next==start)//insert at end
    {
        printf("Enter the value : ");
        scanf("%d",&val);
        new_node->info=val;
        new_node->next=start;
        new_node->prev=ptr;
        ptr->next=new_node;
        start->prev=new_node;
    }
    else{
        printf("Enter the value : ");
        scanf("%d",&val);
        new_node->info=val;
        new_node->next=ptr->next;
        new_node->prev=ptr;
        ptr->next=new_node;
        ptr->next->prev=new_node;
    }

  }return start;
}
struct node *delete_beg(struct node *start)
{
 struct node *ptr;
 ptr=start;
 if(start==NULL)
        printf("OVERFLOW");
 else
 {
     if(ptr->next!=start)
     {
         start=start->next;
         ptr->prev->next=start;
         start->prev=ptr->prev;
         printf("%d is deleted from circular double linked list...",ptr->info);
         free(ptr);
     }
     else
     {
         printf("%d is deleted from circular double linked list...",ptr->info);
         free(ptr);
         start=NULL;
     }
 }return start;

}
struct node *delete_end(struct node *start)
 {
    struct node *ptr;
    ptr=start;
    if(start==NULL)
        printf("OVERFLOW...");
    else
    {
        while(ptr->next!=start)
            ptr=ptr->next;
        if(ptr==start)
        {
            printf("%d is deleted from circular double linked list...",ptr->info);
            free(ptr);
            start=NULL;
        }
        else
        {
            ptr->prev->next=start;
            start->prev=ptr->prev;
            printf("%d is deleted from circular double linked list...",ptr->info);
            free(ptr);
        }
    }return start;
 }
 struct node *delete_val(struct node *start)
 {
     struct node *ptr;
     int num;
     if(start==NULL)
        printf("OVERFLOW...");
     else
     { ptr=start;
       printf("Enter the info part of that node,which you want to delete : ");
       scanf("%d",&num);
         while(ptr->next!=start&&ptr->info!=num)
            ptr=ptr->next;
         if(ptr->next==start&&ptr->info!=num)
            printf("%d is not found in the circular double linked list...",num);
         else if((ptr->next==start&&ptr->info==num)&&ptr!=start)//last value
         {
           ptr->prev->next=start;
           start->prev=ptr->prev;
           printf("%d is deleted from circular double linked list...",ptr->info);
           free(ptr);
         }
         else if((ptr->next==start&&ptr->info==num)&&ptr==start)
         {
             printf("%d is deleted from circular double linked list",ptr->info);//only single value
             free(ptr);
             start=NULL;
         }
         else if((ptr->next!=start&&ptr->info==num)&&ptr==start)//starting element
         {
             start=start->next;
             ptr->prev->next=start;
             start->prev=ptr->prev;
             printf("%d is deleted from circular double linked list...",ptr->info);
             free(ptr);
         }
         else{
            ptr->prev->next=ptr->next;
            ptr->next->prev=ptr->prev;
            printf("%d is deleted from circular double linked list...",ptr->info);
            free(ptr);
         }
     }return start;
 }
struct node *display(struct node *start)
{
  struct node *ptr;
  if(start==NULL)
        printf("CIRCULAR DOUBLE LINKED LIST IS EMPTY");
  else
  { ptr=start;
      printf("START -> %p | %d [%p] | %p",ptr->prev,ptr->info,ptr,ptr->next);
      while(ptr->next!=start)
      {
          ptr=ptr->next;
          printf(" <=> ");
          printf(" %p | %d [%p] | %p ",ptr->prev,ptr->info,ptr,ptr->next);
      }
      printf("\t-> START");

  } return start;
}
