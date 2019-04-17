#include<iostream>
#include<stdio.h>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;

int main()
{   int n,i,j;
    float A[20][20],x[20]={0};
    printf("\nEnter the size of matrix: ");
    scanf("%d",&n);
    printf("\nEnter the elements of augmented matrix row-wise:\n");
    for(i=1; i<=n; i++)
    {
        label:
        float sum=0;
        for(j=1; j<=(n+1); j++)
        {
            printf(" A[%d][%d]:", i,j);
            scanf("%f",&A[i][j]);
            if(i!=j && j!=n+1) //For Convergent Criteria
            sum+=abs(A[i][j]);
        }
        if(abs(A[i][i])<=sum)
        {
            cout<<"Enter again\n";
            goto label;
        }

    }

    int iter;
    cout<<"Enter iteration\n";
    cin>>iter;
   // float ac=pow(10,-accuracy);

   // cout<<"\n"<<arr;
    for(int k=1;k<=iter;k++)
    {
    cout<<"Iteration :"<<k;

    for(i=n; i>=1; i--)
    {
        float sum=0;

        for(int j=1; j<=n; j++)
        {
            if(i!=j)
            sum=sum+A[i][j]*x[j];
        }
        x[i]=(A[i][n+1]-sum)/A[i][i];

    }
            for(i=1; i<=n; i++)
    {
        cout<<" x"<<i<<"="<<x[i]<<"\t";
       // printf("\nx%d=%.(accuracy)f\t",i,x[i]); /* x1, x2, x3 are the required solutions*/
    }
    cout<<"\n";

    }

        for(i=1; i<=n; i++)
    {
        cout<<"\nx"<<i<<"="<<x[i]<<"\t";
       // printf("\nx%d=%.(accuracy)f\t",i,x[i]); /* x1, x2, x3 are the required solutions*/
    }

    return 0;
}
