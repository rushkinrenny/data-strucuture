#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
  int info;
  struct node *next;
};
struct node *start=NULL;
struct node *create_sll(struct node *start);
 node_num(struct node *start);
struct node *rev_sll(struct node *start);
int count=0;
void main()
{
    int choice;
    printf("CREATING LINKED LIST :\n");
    start=create_sll(start);
    do
    { int num;
    system("cls");
        printf("***COUNT THE NODES AND REVERSE SINGLE LINKED LIST***");
        printf("\n1.NUMBER OF NODES\n2.REVERSE SINGLE LINKED LIST\n3.EXIT\nCHOICE : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            node_num(start);
            printf("\n");
            system("pause");
            system("cls");break;

        case 2:
            start=rev_sll(start);
            printf("\n");
            system("pause");
            system("cls");break;
        case 3:
            printf("HAVE A NICE DAY, BYE\n");
            system("pause");
            break;
        default :
            printf("ARE YOU OK..? TRY AGAIN\n");
            system("pause");
            break;
        }
    }while(choice!=3);
}
struct node *create_sll(struct node *start)
{
  struct node *new_node,*ptr,*temp;
  int val;
  char ans;
  printf("Do you want to enter the element? Enter Y or N : ");
  scanf(" %c",&ans);
  while(ans=='y'||ans=='Y')
  { new_node=(struct node *)malloc(sizeof(struct node));
      printf("Enter the element : ");
      scanf("%d",&val);
      new_node->info=val;
      new_node->next=NULL;
      if(start==NULL)
          start=new_node;
      else
      {
          ptr=start;
          while(ptr->next!=NULL)
            ptr=ptr->next;
          ptr->next=new_node;
      }
       printf("Do you want to enter the element? Enter Y or N : ");
      scanf(" %c",&ans);
  } temp=start;
  if(start==NULL);
  else{
      printf("LINKED LIST IS UPDATED...\n");
      printf("START ->");
      while(temp!=NULL)
      {
          printf(" %d [%p] | %p -> ",temp->info,temp,temp->next);
          temp=temp->next;
      } printf("NULL\n");
  } system("pause");
return start;
}
struct node *rev_sll(struct node *start)
{
 struct node *next,*prev,*ptr,*temp;
 prev=NULL;
 ptr=start;
 if(start==NULL)
    printf("LINKED LIST IS EMPTY");
 else{
   while(ptr!=NULL)
 {
     next=ptr->next;
     ptr->next=prev;
     prev=ptr;
     ptr=next;
 }
 start=prev;
 temp=start;
 printf("AFTER REVERSE LINKED LIST IS :\n");
      printf("START\t->");
      while(temp!=NULL)
      {
          printf(" %d [%p] | %p -> ",temp->info,temp,temp->next);
          temp=temp->next;
      } printf("NULL\n");
}return start;
}
node_num(struct node *start)
{
 struct node *ptr;
 int count=0;
 ptr=start;
 if(ptr==NULL)
    printf("THERE IS NO ANY NODE...");
 else{
 while(ptr!=NULL)
 { ptr=ptr->next;
     count++;
 }
 printf("NUMBER OF NODES IS %d",count);

}
}
