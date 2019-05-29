#include<stdio.h>
#include<process.h>
void main()
{
    int i,choice=0,size,a[10],choice2,element,loc,updated,temp,min,j,max;
    printf("Enter the size of array(max 10) = ");
    scanf("%d",&size);
    updated=size;
    if(size!=0)
    printf("Enter the elements\n");
    for(i=0;i<size;i++)
        scanf("%d",&a[i]);
  while(choice!=6)
  {
      printf("\n\noperations are :\n1.Traverse\n2.Insert\n3.delete\n4.linear search\n5.selection sort\n6.exit\n\nselect choice : ");
      scanf("%d",&choice);
      switch(choice)
      {
      case 1:
        { printf("Traverse :\n");
            if(size==0)
                printf("array is empty\n");
            else
            { printf("Elements of array : ");
                for(i=0;i<size;i++)
                    printf(" %d ",a[i]);
            } printf("\n");
             system("pause");
             system("cls");
             break;
        }
      case 2:
        {if(size==10)
         printf("\noverflow\n");
         else {
            printf("\n\nInsertion done at :\n1.Beginning\n2.Location\n3.End\noption : ");
            scanf("%d",&choice2);
            switch(choice2)
            {
             case 1:
                {for(i=size-1;i>=0;i--)
                  a[i+1]=a[i];
                  printf("Enter the element ");
                  scanf("%d",&element);
                  a[0]=element;
                  size++;
                  break;
                }
                case 2:
                {   printf("Enter the location : ");
                    scanf("%d",&loc);
                    if(loc>size)
                        printf("cannot insert element here...");
                    else
                    {
                    for(i=size-1;i>=loc;i--)
                    a[i+1]=a[i];
                    printf("Enter the element : ");
                    scanf("%d",&element);
                    a[loc]=element;
                    size++;
                    break;
                    }
                }break;
                case 3:
                    {
                        printf("Enter the element : ");
                        scanf("%d",&element);
                        a[size]=element;
                        size++;
                        break;
                    }
    }
    }
    }
             if(updated<size)
            { printf("\narray updated...\n");
             for(i=0;i<size;i++)
             printf(" %d ",a[i]);
             }
             printf("\n");system("pause");
             system("cls");
             break;
        case 3:
            {
                 if(size==0)
                 printf("underflow\n");
                 else
                 {
                     printf("Deletion done at :\n1.beginning\n2.Location\n3.End\noption : ");
                     scanf("%d",&choice2);
                     switch(choice2)
                     {
                     case 1:
                        { printf("\n%d deleted from the array\n",a[0]);
                          for(i=0;i<size;i++)
                           a[i]=a[i+1];
                        }
                          size--;
                        break;
                     case 2:
                        {
                          printf("Enter the location : ");
                          scanf("%d",&loc);
                          if(loc>size)
                            printf("can't be delete");
                          else{ printf("\n%d deleted from the array\n",a[loc]);
                            for(i=loc;i<size-1;i++)
                                a[i]=a[i+1];
                                size--;
                                break;
                          }
                        }
                     case 3:
                        {
                            printf("%d deleted from the array",a[size-1]);
                            size--;
                            break;
                        }
                     }
                 }
            }
            if(updated>size)
           { printf("array updated...");
            for(i=0;i<size;i++)
             printf(" %d ",a[i]);
           }
            printf("\n");system("pause");
             system("cls");
             break;
      case 4:
        { int flag=0;
          if(size==0)
          printf("array is empty");
         else{
          printf("Enter the element which you wanna search in array : ");
          scanf("%d",&element);
          for(i=0;i<size;i++)
          if(a[i]==element)
        {
         flag=i+1;
         break;
        }
         if(flag>0)
          printf("\nsuccessful linear search at location %d\n",i);
         else
          printf("\nunsuccessful linear search\n");
            }
        } printf("\n");system("pause");system("cls");break;
      case 5:
        {
            if(size==0)
            printf("\narray is empty..\n");
            else{
                printf("Seletion sort in :\n1.ascending order\n2.descending order\nchoice : ");
                scanf("%d",&choice2);
                switch(choice2){
            case 1:
                {
                    for(i=0;i<size;i++)
                    { min=i;
                     for(j=i+1;j<size;j++)
                     {
                         if(a[min]>a[j])
                            min=j;
                     }
                     if(min!=i)
                     {
                         temp=a[i];
                         a[i]=a[min];
                         a[min]=temp;

                     }

                   }
             for(i=0;i<size;i++)
             printf(" %d ",a[i]);
             printf("\n");
             system("pause");
             system("cls");
        } break;
            case 2:
                {
                    for(i=0;i<size;i++)
                    { max=i;
                     for(j=i+1;j<size;j++)
                     {
                         if(a[max]<a[j])
                            max=j;
                     }
                     if(max!=i)
                     {
                         temp=a[i];
                         a[i]=a[max];
                         a[max]=temp;

                     }

            }
             for(i=0;i<size;i++)
             printf(" %d ",a[i]);
        } printf("\n");
        system("pause");
             system("cls");
             }break;
        case 6: printf("user wants to exit program\n\n");
        system("pause");
        exit(0);
        default : printf("Enter wrong key"); break;
  }

}
}
}
}

