
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
//for stack
struct stack
{
    int info;
    struct stack *next;
};
struct stack *top=NULL;
struct stack* push(struct stack *top);
struct stack* pop(struct stack *top);
struct stack* display_stack(struct stack *top);
//for queue
struct queue
{
    int info;
    struct queue *next;
};
struct queue *front=NULL;
struct queue *rear=NULL;
struct queue* enqueue(struct queue *rear);
struct queue* dequeue(struct queue *front);
struct queue* display_queue(struct queue *front);
int choice2;
void main()
{ int choice;
    do{ system("cls");
        printf("\t\t***STACK AND QUEUE IMPLEMENT USING LINKED LIST***");
        printf("\nMAIN MENU\n1.STACK\n2.QUEUE\n3.EXIT\nCHOICE : ");
        scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        system("cls");
    do{ printf("***STACK IMPLEMENT***");
        printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\nCHOICE :");
        scanf("%d",&choice2);
        switch(choice2)
        {
        case 1:
            top=push(top);
            printf("\n");
            system("pause");
            system("cls");break;
        case 2:
            top=pop(top);
            printf("\n");
            system("pause");
            system("cls");break;
        case 3:
            top=display_stack(top);
            printf("\n");
            system("pause");
            system("cls");break;
        }

    }while(choice2!=4);
 case 2:
     { system("cls");
     do
      { printf("***QUEUE IMPLEMENT***");
        printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\nCHOICE :");
        scanf("%d",&choice2);
        switch(choice2)
        {
        case 1:
            rear=enqueue(rear);
            printf("\n");
            system("pause");
            system("cls");break;
        case 2:
            front=dequeue(front);
            printf("\n");
            system("pause");
            system("cls");break;
        case 3:
            front=display_queue(front);
            printf("\n");
            system("pause");
            system("cls");break;


        }

      }while(choice2!=4);

     }

    }

}while(choice!=3);
}
struct stack *push(struct stack *top)
{ struct stack *new_node;
int val;
new_node=(struct stack *)malloc(sizeof(struct stack));
printf("Enter the value : ");
scanf("%d",&val);
new_node->info=val;
    if(top==NULL)
    {
       new_node->next=NULL;
       top=new_node;
    }
    else{
      new_node->next=top;
      top=new_node;

    }return top;
}

struct stack *pop(struct stack *top)
{ struct stack *ptr;
ptr=top;
    if(top==NULL)
        printf("UNDERFLOW");
    else{
        if(top->next==NULL)
        {
            printf("%d is popped from stack",top->info);
            free(ptr);
            top=NULL;
        }
        else
        {
            printf("%d is popped from stack",top->info);
            top=top->next;
            free(ptr);
        }
    } return top;
}
struct stack *display_stack(struct stack *top)
{ struct stack *ptr;
ptr=top;
    if(top==NULL)
        printf("STACK IS EMPTY");
    else
    { printf("TOP\t->");
        printf("\t%d\t",ptr->info);
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
            printf("->\t%d\t",ptr->info);
        }
        printf("->\tNULL");
    }return top;
}
struct queue *enqueue(struct queue *rear)
{struct queue *new_node;
 int val;
 printf("Enter the value : ");
 scanf("%d",&val);
 new_node=(struct queue *)malloc(sizeof(struct queue));
 new_node->info=val;
 new_node->next=NULL;
 if(rear==NULL&&front==NULL)
 {
     front=rear=new_node;
     return rear;
 }
 rear->next=new_node;
 rear=new_node;
 return rear;
}
struct queue *dequeue(struct queue *front)
{
 struct queue *ptr;
 if(front==NULL&&rear==NULL)
        printf("UNDERFLOW");
 else
 {ptr=front;
     if(front==rear)
     {
         printf("%d is dequeue from queue...",ptr->info);
         front=rear=NULL;
         free(ptr);
     }
     else{
        front=front->next;
        printf("%d is dequeue is from queue...",ptr->info);
        free(ptr);
     }
 }return front;
}
struct queue *display_queue(struct queue *front)
{ struct queue *ptr;
ptr=front;
 if(ptr==NULL)
        printf("QUEUE IS EMPTY");
 else
 { printf("FRONT\t->");
     printf("\t%d\t->",ptr->info);
 while(ptr!=rear)
 {
   ptr=ptr->next;
   printf("\t%d\t->",ptr->info);
 }printf("\tREAR");
 }return front;
}
