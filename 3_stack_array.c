#include<stdio.h>
#include<process.h>
main()
{
    int i,tos=-1,stack[5],choice,element;
    while(1)
    {
        system("cls");
        printf("Stack operations :\n1.Push\n2.Pop\n3.Display\n4.exit\n\nchoice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            {if(tos==4)
            printf("overflow");
            else{
                printf("Enter the element ");
                scanf("%d",&element);
                stack[++tos]=element;

            } printf("\n");
              system("pause");
              break;
            }
        case 2:
            {
                if(tos==-1)
                    printf("underflow\n");
                else
                {
                    printf("%d poped from the stack",stack[tos--]);

                } printf("\n");
                  system("pause");
                  break;
            }
        case 3:
            { if(tos==-1)
            printf("empty stack\n");
            else
               {
                    for(i=tos;i>=0;i--)
                    printf("%d ",stack[i]);
               }
                    printf("\n");
                    system("pause");
                    break;

            }
         case 4: printf("user wants to exit the program\n\n");
                 exit(0);
         default : printf("wrong key");
                   printf("\n");
                   system("pause");
                  break;
        }

    }
}
