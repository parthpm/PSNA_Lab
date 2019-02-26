#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
float compute(int a[],int deg,float value);
float absu(float f);


int main()
{
    float result;
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

    float left,right,m;
    int accuracy;
    cout<<"Enter accuracy\n";
    cin>>accuracy;
    float arr=pow(10,-accuracy);
    cout<<"\n"<<arr;


    do
    {
            cout<<"Enter left and right limit respectively:\n";
      cin>>left>>right;
    }while(compute(a,degree,left)*compute(a,degree,right)>=0);

    if(compute(a,degree,left)>compute(a,degree,right))
    {
        float temp;
        temp=left;
        left=right;
        right=temp;
    }

    float temp1;

    do
    {
        m=(left+right)/2;
        result=compute(a,degree,m);
      // cout<<" M is:"<<m<<"\n";

    if(result>0)
    {
       right=m;
    }
    else
        left=m;
    temp1=compute(a,degree,(right+left)/2);
    cout<<"Temp is:" <<m<<endl;

    }while(absu(result-temp1)>arr);

    cout<<"Answer is :"<<m;





    return 0;
}

float compute(int a[],int deg,float value)
{
    int temp=deg;
    float result=0;
    while(temp>=0)
    {
        result+=a[temp]*pow(value,temp);
        temp--;
    }

    return result;
}

float absu(float f)
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

/*float compute(float left,float right,float a,float b,float c,float x)
{
    float m=(left+right)/2
    float result=quad(a,b,c,x);

    if(result>0)
    {
       right=m;
    }
    else
        left=m;

    return m;



}*/
