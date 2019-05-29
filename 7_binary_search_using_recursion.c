#include<stdio.h>
int binary_search(int a[],int,int,int);
 void main()
{  int n,i,pos,element;
    printf("         ****Binary search using recursion****\n\nHow many elements would you enter? ");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter the Sorted Array's elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the element which you want to search\nelement = ");
    scanf("%d",&element);
    int lower=0,upper=n-1;
    pos=binary_search(a,lower,upper,element);
    if(pos==-1)
            printf("unsuccessful binary search");
    else
        printf("successful binary search, at %d index",pos);
}
int binary_search(int a[],int l,int u,int x)
{
  int mid;
  if(l>u)
    return -1;
    mid=(l+u)/2;
    if(x==a[mid])
        return mid;
  else if(x<a[mid])
    return binary_search(a,l,mid-1,x);
  else
    return binary_search(a,mid+1,u,x);
}
