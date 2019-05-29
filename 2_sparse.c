#include<stdio.h>
main()
{
    int r,c,i,j,choice,nonzero=0;
    printf("Enter the row and column\n");
    scanf("%d%d",&r,&c);
    int a[r][c];
    printf("\nEnter the elements of array :\n");
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
    {
        scanf("%d",&a[i][j]);
        if(a[i][j]!=0)

            nonzero++;
    }
    if(r*c/4<nonzero)
        printf("\nGiver array is not sparse array\n");
    else
    { printf("\nGiven array is sparse array\n");
        int sparse[nonzero+1][3], k=1;
    sparse[0][0] = r;
    sparse[0][1] = c;
    sparse[0][2] = nonzero;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(a[i][j]!=0){
                sparse[k][0]=i;
                sparse[k][1]=j;
                sparse[k][2]=a[i][j];
                k++;
            }
        }
    }
    printf("Matrix Triplet form : \n");
    for(i=0;i<=nonzero;i++){
        for(j=0;j<3;j++){
            printf("%3d ", sparse[i][j]);
        }
        printf("\n");
    }


    }
    printf("\nGiven array :\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++)
        {
            printf("%3d",a[i][j]);
        } printf("\n");
    }


}
