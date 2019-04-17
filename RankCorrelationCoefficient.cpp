//Rank of Correlation Coefficient

#include<stdio.h>

int main()
{
    int i,j,n,sumd2;
    float r,num,den,p;

    printf("Enter the no. of Data: ");
    scanf("%d",&n);

    int a[n][6];

    printf("\nEnter the X Values:\n");

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i][0]);
    }

    printf("\nEnter the Y Values:\n");

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i][1]);
    }

    for(i=0;i<n;i++)
    {
        a[i][2] = a[i][3] = 1;
    }

    for(i=0;i<n;i++)        //assigning ranks to x
    {
        for(j=0;j<n;j++)
        {
            if(a[i][0]<a[j][0])
                a[i][2]+=1;
        }
    }

    for(i=0;i<n;i++)        //assigning ranks to y
    {
        for(j=0;j<n;j++)
        {
            if(a[i][1]<a[j][1])
                a[i][3]+=1;
        }
    }

    for(i=0;i<n;i++)
    {
        a[i][4] = a[i][2] - a[i][3];
        a[i][5] = a[i][4] * a[i][4];
    }

    printf("\nx\ty\tRx\tRy\tD\tD^2\n\n");

    for(i=0;i<n;i++)            //table
    {
        for(j=0;j<6;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }

    sumd2=0;

    for(i=0;i<n;i++)
    {
        sumd2+=a[i][5];
    }

    num = 6*sumd2;
    den = n*(n*n-1);
    p=num/den;

    r = 1 - p;

    printf("Rank of Correlation Coefficient: r = %.2f",r);
    return 0;
}
