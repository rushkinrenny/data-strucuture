#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
    int info;
    struct node *next;
};
struct node *start1=NULL;
struct node *start2=NULL;
struct node *start=NULL;
struct node *create1_ll(struct node *start1);
struct node *create2_ll(struct node *start2);
selectionsort1(struct node *start1);
selectionsort2(struct node *start2);
display1(struct node *start1);
display2(struct node *start2);
display(struct node *start);
struct node *merge(struct node *start1,struct node *start2);
void main()
{
    printf("CREATING SORTED LINKED LIST 1\n");
    start1=create1_ll(start1);
    selectionsort1(start1);
    display1(start1);
    printf("\n\nCREATING SORTED LINKED LIST 2\n");
    start2=create2_ll(start2);
    selectionsort2(start2);
    display2(start2);
    printf("\n\nMERGED SORTED LIKED LIST BECOME :\n\n");
    start=merge(start1,start2);
    display(start);
}
struct node *create1_ll(struct node *start1)
{
 int val;
 char ans;
 struct node *new_node,*ptr;
 printf("DO YOU WANT TO ENTER THE ELEMENT OF LINKED LIST 1 (Y or N)? ");
 scanf(" %c",&ans);
 while(ans=='y'||ans=='Y')
 {
    new_node=(struct node *)malloc(sizeof(struct node));
    printf("Enter the element : ");
    scanf("%d",&val);
    new_node->info=val;
    new_node->next=NULL;
    if(start1==NULL)
        start1=new_node;
    else
    {
        ptr=start1;
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=new_node;
    }printf("DO YOU WANT TO ENTER THE ELEMENT OF LINKED LIST 1 (Y or N)? ");
    scanf(" %c",&ans);



 } return start1;
}
struct node *create2_ll(struct node *start2)
{
 int val;
 char ans;
 struct node *new_node,*ptr;
 printf("DO YOU WANT TO ENTER THE ELEMENT OF LINKED LIST 2 (Y or N)? ");
 scanf(" %c",&ans);
 while(ans=='y'||ans=='Y')
 {
    new_node=(struct node *)malloc(sizeof(struct node));
    printf("Enter the element : ");
    scanf("%d",&val);
    new_node->info=val;
    new_node->next=NULL;
    if(start2==NULL)
        start2=new_node;
    else
    {
        ptr=start2;
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=new_node;
    }printf("DO YOU WANT TO ENTER THE ELEMENT OF LINKED LIST 2 (Y or N)? ");
    scanf(" %c",&ans);
 } return start2;
}
selectionsort1(struct node *start1)
{
 struct node *i,*j;
 int temp;
 if(start1==NULL)
    ;
 else{
    for(i=start1;i!=NULL;i=i->next){
        for(j=i->next;j!=NULL;j=j->next){
            if(j->info<i->info)
            {
                temp=i->info;
                i->info=j->info;
                j->info=temp;
            }
        }
    }
 }
}
selectionsort2(struct node *start2)
{
 struct node *i,*j;
 int temp;
 if(start2==NULL)
    ;
 else{
    for(i=start2;i!=NULL;i=i->next){
        for(j=i->next;j!=NULL;j=j->next){
            if(j->info<i->info)
            {
                temp=i->info;
                i->info=j->info;
                j->info=temp;
            }
        }
    }
 }
}
display1(struct node *start1)
{
    struct node *ptr=start1;
    if(ptr==NULL)
        printf("\nLINKED LIST IS EMPTY\n\n");
    else{printf("SORTED LINKED LIST 1 :\n");
    printf("start1 ->");
    while(ptr!=NULL)
    {
        printf(" %d [%p] | %p -> ",ptr->info,ptr,ptr->next);
        ptr=ptr->next;
    } printf("NULL\n\n");
    }
}
display(struct node *start)
{
    struct node *ptr=start;
    if(ptr==NULL)
        printf("\nLINKED LIST IS EMPTY\n\n");
    else{
    printf("start ->");
    while(ptr!=NULL)
    {
        printf(" %d [%p] | %p -> ",ptr->info,ptr,ptr->next);
        ptr=ptr->next;
    } printf("NULL\n\n");
    }
}
display2(struct node *start2)
{
    struct node *ptr=start2;
    if(ptr==NULL)
        printf("\nLINKED LIST IS EMPTY\n\n");
    else{printf("SORTED LINKED LIST 2 :\n");
    printf("start2 ->");
    while(ptr!=NULL)
    {
        printf(" %d [%p] | %p -> ",ptr->info,ptr,ptr->next);
        ptr=ptr->next;
    } printf("NULL\n\n");
    }
}
struct node *merge(struct node *start1,struct node *start2)
{
    struct node *i=start1,*j=start2,*ptr=start;
    if(start1==NULL)
        return start2;
    if(start2==NULL)
        return start1;
    if(i==NULL&&j==NULL)
        printf("LINKED LIST IS EMPTY");
    else{
        while(i!=NULL&&j!=NULL)
        {
            if(i->info<j->info)
            {
                if(ptr==NULL)
                {
                   start= ptr=i;
                    i=i->next;
                }
                else{
                    ptr->next=i;
                    ptr=ptr->next;
                    i=i->next;
                }
            }
          else
            {
                if(ptr==NULL)
                {
                   start = ptr=j;

                    j=j->next;
                }
                else{
                    ptr->next=j;
                    ptr=ptr->next;
                    j=j->next;
                }
            }
        }
        if(i==NULL&&j!=NULL)
            {
              ptr->next=j;
            }

        else{
              ptr->next=i;
            }
        }
     return start;
}



