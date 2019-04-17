#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    cout<<"Enter the no of data you want to enter"<<endl;
    int n,i;
    cin>>n;

    double *x=new double[n];
    double *y=new double[n];

    cout<<"Enter "<<n<<"data for x "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
    }
    cout<<"Enter "<<n<<" data for y "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>y[i];
    }

    float suxy,sux,suy,suxx,suyy;
    suxy=0;
    sux=0;
    suy=0;
    suxx=0;
    suyy=0;

    for(int i=0;i<n;i++)
    {
        suxy+=x[i]*y[i];
        sux+=x[i];
        suy+=y[i];
        suxx+=x[i]*x[i];
        suyy+=y[i]*y[i];

    }

    float r=(n*suxy-sux*suy)/(sqrt(n*suxx-sux*sux)*sqrt(n*suyy-suy*suy));
    cout<<"r is "<<r;


}
