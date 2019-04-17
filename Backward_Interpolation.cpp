#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
double Iteration2(int a,double **p,double pl,int data,int i)
{
   int j=0;
    double temp=1;
        if(i==1)
        {
                return p[data-1][i];
        }
        for(j=data;j>a+1;j--)
        {
                temp=temp*(pl+data-j)/(data-j+1);

        }
        return temp*p[data-i][i];
}
int main()
{   double **p,x,p1;
    int i,j,data;
    printf("Enter the no. of data available:");
    scanf("%d",&data);
    //double table[data][data];
    p=(double**)malloc(sizeof(double)*data);
    for(i=0;i<data;i++)
    p[i]=(double*)malloc(sizeof(double)*(data+1));
    for(i=0;i<data;i++)
    {   printf("Enter value of x%d and f(x%d):\n",i,i);
        for(j=0;j<2;j++)
        {
            scanf("%lf",&p[i][j]);
        }
    }
    for(i=2;i<=data;i++)
    {   for(j=0;j<data-i+1;j++)
        {   p[j][i]=p[j+1][i-1]-p[j][i-1];
            //printf("%lf\n",p[j][i]);
        }
    }
    printf("y");
    for(i=1;i<data;i++)
    printf("      d%dy",i);
    printf("\n");
    for(i=0;i<data;i++)
    {   for(j=1;j<data+1-i;j++)
        printf("%lf\t",p[i][j]);
        printf("\n");
    }
    printf("enter the value of x:");
    scanf("%lf",&x);
    double sum=0;

    p1=(x-p[data-1][0])/(p[1][0]-p[0][0]);
    for(i=1;i<=data;i++)
    {
        sum=sum+Iteration2(data-i,p,p1,data,i);
    }
    printf("value of f(%lf)=%lf",x,sum);
    return 0;
}
