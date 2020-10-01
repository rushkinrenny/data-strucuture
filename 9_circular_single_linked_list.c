/*Implement insertion(at the begging, at specified location, at the end)
& deletion (at the begging, at specified location, at the end) on circular single linked list */
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node* insert_beg(struct node*);
struct node* insert_end(struct node*);
struct node* insert_after(struct node*);
struct node* delet_beg(struct node*);
struct node* delet_end(struct node*);
struct node* delet_at_val(struct node*);
struct node* display(struct node*);
struct node
{
    int info;
    struct node *next;
};
void main(){
    struct node *start=NULL;
  int choice;
  do{
    printf("\t\t\tCIRCULAR SINGLE LINKED LIST IMPLEMENTION\n");
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
    start=display(start);
     printf("\n");system("pause");
     system("cls");
    break;    }
  } while(choice!=8);
}
struct node* insert_beg(struct node* start)
{ struct node *new_node,*ptr;
 int num;
 printf("Enter the data : ");
 scanf("%d",&num);
 new_node=(struct node *)malloc(sizeof(struct node));
 if(start==NULL)
 {
     new_node->info=num;
     start=new_node;
     start->next=start;
     return start;
 }
 else
 {
    ptr=start;
    new_node->info=num;
    while(ptr->next!=start)
        ptr=ptr->next;
     ptr->next=new_node;
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
       while(ptr->next!=start)
           ptr=ptr->next;
           ptr->next=new_node;
           new_node->next=start;
           return start;
   }
}
struct node *insert_after(struct node*start)
{
 struct node *new_node,*ptr;
 int num,val;
 new_node=(struct node *)malloc(sizeof(struct node));
 if(start==NULL)
        printf("linked list is empty");
 else
 {
     printf("Enter the data : ");
     scanf("%d",&num);
     printf("\nEnter the value after which new node is inserted : ");
     scanf("%d",&val);
     new_node->info=num;
     ptr=start;
     while(ptr->next!=start && ptr->info!=val)
     {

         ptr=ptr->next;
     }
     if(ptr->next==start&&ptr->info!=val)
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
    struct node *ptr,*t;
    if(start==NULL)
        printf("UNDERFLOW");

    else{
         ptr=start;
         while(ptr->next!=start)
              ptr=ptr->next;
        if(ptr==start){
            printf("%d is deleted from linked list",start->info);
            start=NULL;
            free(ptr);
        }
        else{
            ptr->next=start->next;
            printf("%d is deleted from linked list",start->info);
            free(start);
            start=ptr->next;
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
      while(ptr->next!=start)
      {
          preptr=ptr;
          ptr=ptr->next;

      }
      preptr->next=ptr->next;
      printf("%d is deleted from linked list",ptr->info);
      free(ptr);
      return start;
  }
}
struct node* delet_at_val(struct node*start)
{
 struct node *ptr,*preptr;
 int val;
 if(start==NULL)
        printf("UNDERFLOW");
 else
 {
     printf("Enter the value which you want to delete : ");
     scanf("%d",&val);
     ptr=start->next;
     preptr=start;
     if(start->info==val){
        printf("\nDeleted %d from Linked List", val);
        ptr=start;
        while(ptr->next!=start)
            ptr=ptr->next;
        if(ptr==start){
            start=NULL;
            free(ptr);
        }
        else{
            preptr=start;
            start=start->next;
            ptr->next=start;
            free(preptr);
        }
     }
     else{
         while(ptr!=start&&ptr->info!=val){
            preptr = ptr;
            ptr=ptr->next;
         }
         if(ptr==start&&ptr->info!=val)
            printf("%d is not found in the list",val);
         else
         {
             preptr->next=ptr->next;
             free(ptr);
             printf("%d is deleted from list",val);
         }
     }
      return start;
 }
}
struct node *display(struct node *start)
{
 struct node *ptr;
 ptr=start;
 if(start==NULL)
    printf("Linked list is empty");
 else{
        printf("\t%d",ptr->info);
        ptr=ptr->next;
        while(ptr!=start)
         {
             printf("\t%d",ptr->info);
             ptr=ptr->next;
         } }
         return start;
}


