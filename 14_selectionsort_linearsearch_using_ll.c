#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
    int info;
    struct node *next;
};
struct node *start=NULL;
struct node *create_ll(struct node *start);
linearsearch(struct node *start);
display(struct node *start);
selectionsort(struct node *start);
void main()
{
    int choice;
    printf("CREATING LINKED LIST :\n");
    start=create_ll(start);
    display(start);
    system("pause");
    system("cls");

    do
    {
        printf("\n\t\t***MAIN MENU****");
        printf("\n1.LINEAR SEARCH\n2.SELECTION SORT\n3.DISPLAY\n4.EXIT\nCHOICE : ");
        scanf("%d",&choice);
        switch(choice)
        { case 1:
            linearsearch(start);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 2:
            selectionsort(start);
            printf("AFTER SELCTION SORT, LINKED LIST BECOME : \n");
            display(start);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 3:
            display(start);
            printf("\n");
            system("pause");
            system("cls");
            break;
        }

    }while(choice!=4);
}
struct node *create_ll(struct node *start)
{int val;
 struct node *new_node,*ptr=start;
 char ans;
 printf("Do you want to enter the element ? (y or n) ");
    scanf(" %c",&ans);
    while(ans=='y'||ans=='Y')
    {
        new_node =(struct node*)malloc(sizeof(struct node));
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
        printf("Do you want to enter the element ? (y or n) ");
       scanf(" %c",&ans);

    }return start;

}
display(struct node *start)
{
    struct node *ptr=start;
    if(ptr==NULL)
        printf("\nLINKED LIST IS EMPTY\n\n");
    else{printf("LINKED LIST :\n");
    printf("start ->");
    while(ptr!=NULL)
    {
        printf(" %d [%p] | %p -> ",ptr->info,ptr,ptr->next);
        ptr=ptr->next;
    } printf("NULL\n\n");
    }
}
linearsearch(struct node *start)
{
    int num;
    struct node *ptr;
    ptr=start;
    if(ptr==NULL)
        printf("LINKED LIST IS EMPTY\n");
    else{
    printf("Enter the value which You want to search : ");
    scanf("%d",&num);
    while(ptr->info!=num&&ptr->next!=NULL)
        ptr=ptr->next;
    if(ptr->next==NULL&&ptr->info!=num)
        printf("%d is not found in the linked list",num);
        else{
            printf("%d is found at address %p ",num,ptr);
        }
    }

}
selectionsort(struct node *start)
{
 struct node *i,*j;
 int temp;
 if(start==NULL)
    printf("LINKED LIST IS EMPTY");
 else{
    for(i=start;i!=NULL;i=i->next){
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
