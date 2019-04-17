#include<stdio.h>
using namespace std;

int main()
{
    int n,i,j;
    float xp,yp,num,den;

    printf("Enter No. of Data Records: ");
    scanf("%d",&n);

    float x[n],y[n];

    printf("Enter x[i] and y[i]:\n");

    for(i=0;i<n;i++)            //Taking values of xi and yi
    {
        printf("x[%d]= ",i);
        scanf("%f",&x[i]);

        printf("y[%d]= ",i);
        scanf("%f",&y[i]);
    }

    printf("\nEnter x: ");
    scanf("%f",&xp);

    for(i=0;i<n;i++)
    {
        num=1;
        den=1;

        for(j=0;j<n;j++)
        {
            if(i!=j)
            {
                num=num*(xp-x[j]);
                den=den*(x[i]-x[j]);
            }
        }

        yp=yp+((num/den)*y[i]);
    }

    printf("\nThe Value of y[p] for x[p]=%.2f is : %.6f\n",xp,yp);
}
