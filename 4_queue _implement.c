#include<stdio.h>
#define max 10
int q[max],front=-1,rear=-1,val;
void enqueue(void);
int dequeue(void);
int peek(void);
void display(void);
int main()
{
    int q[max],choice;
    do{
    printf("\n\t\t***Queue Implement***");
    printf("\n1.enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\nChoice : ");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        enqueue();
        printf("\n");system("pause");
        system("cls");

        break;
    case 2:
        val=dequeue();
        if(val!=-1)
         printf("\n%d deleted from queue",val);
         printf("\n");system("pause");
         system("cls");
         break;
    case 3:
         val=peek();
         if(val!=-1)
         printf("%d is first in the queue",val);
         printf("\n");system("pause");
         system("cls");
         break;
    case 4:
         display();
         printf("\n");system("pause");
         system("cls");
         break;
    }
    } while(choice!=5);

    return 0;
}
void enqueue(void)
{ int element;
 printf("Enter the element to be inserted in the queue = ");
 scanf("%d",&element);
    if(rear==max-1)
        printf("\nOVERFLOW\n");
    else if(front==-1&&rear==-1)
        front=rear=0;
    else
        rear=rear+1;
        q[rear]=element;


}
int dequeue(void)
{ int val;
    if(front==-1||front>rear)
    {
        printf("\nUNDERFLOW\n");
        return -1;
    }
    else
    {
        val = q[front];
        front++;
        if(front>rear)
            front=rear=-1;
            return val;
    }
}
int peek(void)
{
    if(front==-1||front>rear)
    {
        printf("\nQueue is empty\n");
        return -1;
    }
    else
    {
        return q[front];
    }


}
void display(void)
{   int i;
    printf("\n");
    if(front==-1||front>rear)
        printf("\nQueue is empty");
    else
    {
        for(i=front;i<=rear;i++)
            printf("\t%d",q[i]);
    }

}
