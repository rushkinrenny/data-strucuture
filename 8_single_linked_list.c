/*Implement insertion(at the begging, at specified location, at the end)
& deletion (at the begging, at specified location, at the end) on single linked list */
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node* insert_beg(struct node*);
struct node* insert_end(struct node*);
struct node* insert_after(struct node*);
struct node* delet_beg(struct node*);
struct node* delet_end(struct node*);
struct node* delet_at_val(struct node*);
display(struct node*);
struct node
{
    int info;
    struct node *next;
};
struct node *start=NULL;
void main()
{  int choice;
  do{
    printf("\t\t\tSINGLE LINKED LIST IMPLEMENTION\n");
    printf("****MAIN MENU****\n");
    printf("1.Insertion at begging\n2.Insertion at end\n3.Insertion after node\n");
    printf("4.Deletion at begging\n5.Deletion at end\n6.Deletion at value\n");
    printf("7.Display list\n8.Exit\n\nEnter your choice : ");
    scanf("%d",&choice);
    switch(choice){
case 1:
    start=insert_beg(start);
     printf("\n");system("pause");
     system("cls");
    break;
case 2:
    start=insert_end(start);
    printf("\n");system("pause");
    system("cls");
    break;
case 3:
    start=insert_after(start);
    printf("\n");system("pause");
    system("cls");
    break;
case 4:
    start=delet_beg(start);
    printf("\n");system("pause");
    system("cls");
    break;
case 5:
    start=delet_end(start);
    printf("\n");system("pause");
    system("cls");
    break;
case 6:
    start=delet_at_val(start);
    printf("\n");system("pause");
    system("cls");
    break;


case 7:
    display(start);
     printf("\n");system("pause");
     system("cls");
    break;

    }
  } while(choice!=8);
}
struct node* insert_beg(struct node* start)
{ struct node *new_node;
 int num;
 printf("Enter the data : ");
 scanf("%d",&num);
 new_node=(struct node *)malloc(sizeof(struct node));
 if(start==NULL)
 {
     new_node->info=num;
     new_node->next=NULL;
     start=new_node;
     return start;
 }
 else
 {
     new_node->info=num;
     new_node->next=start;
     start=new_node;
     return start;
 }
}
struct node* insert_end(struct node *start)
{ struct node *ptr,*new_node;
 ptr=start;
 new_node=(struct node*)malloc(sizeof(struct node));
 if(start==NULL)
  printf("Linked list is empty");
 else
   { int num;
       ptr=start;
       printf("Enter the data : ");
       scanf("%d",&num);
       new_node->info=num;
       new_node->next=NULL;
       while(ptr->next!=NULL)
           ptr=ptr->next;
           ptr->next=new_node;
           return start;
   }
}
struct node *insert_after(struct node*start)
{
 struct node *new_node,*ptr;
 int num,val;
 if(start==NULL)
        printf("linked list is empty");
 else
 {
     printf("Enter the data : ");
     scanf("%d",&num);
     printf("\nEnter the value after which new node is inserted : ");
     scanf("%d",&val);
     new_node=(struct node *)malloc(sizeof(struct node));
     new_node->info=num;
     ptr=start;
     while(ptr!=NULL && ptr->info!=val)
     {

         ptr=ptr->next;
     }
     if(ptr==NULL)
        printf("\n%d is not found in Linked list....",val);
     else{
        new_node->next=ptr->next;
        ptr->next=new_node;
     }
     return start;
 }
}
struct node* delet_beg(struct node*start)
{
    struct node *ptr;
    if(start==NULL)
        printf("UNDERFLOW");
    else{
        ptr=start;
        if(ptr->next==NULL&&ptr==start)
        {
            printf("%d is deleted from linked list",ptr->info);
            free(ptr);
            start=NULL;
        }
        else{
        start=start->next;
        printf("%d is deleted from linked list",ptr->info);
        free(ptr);
        }
    }
    return start;
}
struct node* delet_end(struct node*start)
{
  struct node *ptr,*preptr;
  int val,num;
  if(start==NULL)
        printf("UNDERFLOW");
  else
  {
      ptr=start;
      preptr=ptr;
      while(ptr->next!=NULL)
      {
          preptr=ptr;
          ptr=ptr->next;

      }
      if(ptr==start&&ptr->next==NULL)
      {
          printf("%d is deleted from linked list",ptr->info);
          free(ptr);
          start=NULL;
      }
      else{
      preptr->next=NULL;
      printf("%d is deleted from linked list",ptr->info);
      free(ptr);
      }
  }
        return start;
}
struct node* delet_at_val(struct node *start)
{
 struct node *ptr,*preptr;
 int val;
 if(start==NULL)
        printf("UNDERFLOW");
 else
 {
     printf("Enter the value which you want to delete : ");
     scanf("%d",&val);
     ptr=start;
     preptr=NULL;
     while(ptr!=NULL && ptr->info!=val)
     {
         preptr=ptr;
         ptr=ptr->next;

     }
     if(ptr==NULL)
     {
         printf("%d is not found",val);
     }
     else{
        printf("%d is deleted from he Linked List", val);
        if(preptr == NULL){
            start = ptr->next;
            free(ptr);
        }
        else{
            preptr = ptr->next;
            free(ptr);
        }
     }
     return start;
 }
}
display(struct node *start)
{
 struct node *ptr;
 ptr=start;
 if(start==NULL)
    printf("Linked list is empty");
 else
        while(ptr!=NULL)
         {
             printf("\t%d",ptr->info);
             ptr=ptr->next;
         }

}
