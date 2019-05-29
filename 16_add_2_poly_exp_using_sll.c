#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
struct node
{
    int exp,coef;
    struct node *next;
};
struct node *expression(struct node *start1);
display(struct node *start1);
struct node *start1=NULL;
struct node *start2=NULL;
struct node *start3=NULL;
struct node *addpoly(struct node *start1,struct node *start2);
void main()
{
 printf("POLYNOMIAL EXPRESSION 1\n");
 start1=expression(start1);
 printf("FIRST EXPRESSION IS :\n");
 display(start1);
 printf("\n\nPOLYNOMIAL EXPRESSION 2\n");
 start2=expression(start2);
 printf("SECOND EXPRESSION IS :\n");
 display(start2);
 printf("\n\nADDITION OF POLYNOMIAL EXPRESSION :\n");
 start3=addpoly(start1,start2);
 display(start3);

}
struct node *expression(struct node *start)
{ int power,coefficient;
char ans;
  struct node *new_node,*ptr1;
  new_node=(struct node *)malloc(sizeof(struct node));
 printf("ENTER THE POWER OF X = ");
 scanf("%d",&power);
 new_node->exp=power;
 printf("ENTER THE COEFFICENT OF X^%d = ",power);
 scanf("%d",&coefficient);
 new_node->coef=coefficient;
 new_node->next=NULL;
 start=new_node;
 ptr1=start;
 printf("DO YOU WANT ADD MORE ? (Y or N) ");
 scanf(" %c",&ans);
 while(ans=='y'||ans=='Y')
 {
     while(ptr1->next!=NULL)
        ptr1=ptr1->next;
      new_node=(struct node *)malloc(sizeof(struct node));
   printf("ENTER THE POWER OF X = ");
   scanf("%d",&power);
   new_node->exp=power;
   printf("ENTER THE COEFFICENT OF X^%d = ",power);
   scanf("%d",&coefficient);
   new_node->coef=coefficient;
   new_node->next=NULL;
   ptr1->next=new_node;
   printf("DO YOU WANT ADD MORE ? (Y or N) ");
   scanf(" %c",&ans);
 } return start;
}
display(struct node *start)
{ struct node *ptr;
    ptr=start;
    if(ptr->coef<0)
        printf(" -");
    while(ptr->next!=NULL)
    {
        printf("%dX^%d ",abs(ptr->coef),ptr->exp);
    ptr=ptr->next;
        if(ptr->coef>=0)
            printf("+");
        else
            printf("-");

    } printf("%dX^%d ",abs(ptr->coef),ptr->exp);
}
struct node *addpoly(struct node *start1,struct node *start2)
{
    struct node *ptr1=start1,*ptr2=start2,*ptr,*new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    while(start3 == NULL){
        if(ptr1->exp>ptr2->exp ){
                if(ptr1->coef==0)
                    ptr1 = ptr1->next;
        else {
                new_node->coef=ptr1->coef;
                new_node->exp=ptr1->exp;
                new_node->next=NULL;
                ptr1=ptr1->next;
                start3=new_node;
                ptr=start3;
        }
        }
            else if(ptr1->exp<ptr2->exp)
            { if(ptr2->coef==0)
                ptr2 = ptr2->next;
              else{
                new_node->coef=ptr2->coef;
                new_node->exp=ptr2->exp;
                new_node->next=NULL;
                ptr2=ptr2->next;
                start3=new_node;
                ptr=start3;
            }
            }
            else
            {  new_node->coef=ptr1->coef+ptr2->coef;
            if(new_node->coef==0){
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            else{
               new_node->exp=ptr1->exp;
               new_node->next=NULL;
               ptr1=ptr1->next;
               ptr2=ptr2->next;
               start3=new_node;
               ptr=start3;
            }
            }
    }

    while(ptr1!=NULL &&ptr2!=NULL)
    { new_node=(struct node *)malloc(sizeof(struct node));
        if(ptr1->exp >ptr2->exp )
        {   if(ptr1->coef==0)
                ptr1 = ptr1->next;
           else{
            new_node->coef=ptr1->coef;
            new_node->exp=ptr1->exp;
            new_node->next=NULL;
            ptr->next=new_node;
            ptr=ptr->next;
            ptr1=ptr1->next;
        }
        }
        else if(ptr1->exp<ptr2->exp)
        { if(ptr2->coef==0)
            ptr2 = ptr2->next;
        else{
            new_node->coef=ptr2->coef;
            new_node->exp=ptr2->exp;
            new_node->next=NULL;
            ptr->next=new_node;
            ptr=ptr->next;
            ptr2=ptr2->next;
        }
        }
        else
        {
           new_node->coef=ptr1->coef+ptr2->coef;
           if(new_node->coef==0){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
           }
           else{
           new_node->exp=ptr1->exp;
           new_node->next=NULL;
           ptr->next=new_node;
           ptr=ptr->next;
           ptr1=ptr1->next;
           ptr2=ptr2->next;
        }
        }
    }
    if(ptr1!=NULL&&ptr2==NULL)
        new_node->next=ptr1;
    else
        new_node->next=ptr2;
    return start3;
}
