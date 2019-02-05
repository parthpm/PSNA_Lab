#include<iostream>
#include<math.h>
#define df 0.0000001
using namespace std;
double compute(int a[],int deg,double value);
double absu(double f);
double df1(int a[],int deg,double value);
double df2(int a[],int deg,double value);

int main()
{
    double result;
    int degree;

    cout<<"Enter the degree of the eqn\n";
    cin>>degree;

    int a[degree+1];
    int temp=degree;

    while(temp>=0)
    {   cout<<"Enter the coeff of x^ "<<temp<<endl;
        cin>>a[temp];
        temp--;
    }


    double x0=0,x1=0,prev=0;
    do
    {
         cout<<"Enter the value of initial guess(x0)\n";
        cin>>x0;

    }while(absu(compute(a,degree,x0)*df2(a,degree,x0))>absu(df1(a,degree,x0)*df1(a,degree,x0)));



    do
    {
        x1=x0-compute(a,degree,x0)/df1(a,degree,x0);
        prev=x0;
        x0=x1;

    }while(absu(x1-prev)>0.0000001);
    cout<<"Answer is: "<<x1;


    return 0;
}

double compute(int a[],int deg,double value)
{
    int temp=deg;
    double result=0;
    while(temp>=0)
    {
        result+=a[temp]*pow(value,temp);
        temp--;
    }

    return result;
}

double df1(int a[],int deg,double value)
{
    double result=(compute(a,deg,value+df)-compute(a,deg,value))/df;
    return result;

}

double df2(int a[],int deg,double value)
{
   double result=(df1(a,deg,value+df)-df1(a,deg,value))/df;
    return result;

}



double absu(double f)
{
    if(f>0)
    {
        return f;
    }
    else
    {
        return -f;
    }
}

