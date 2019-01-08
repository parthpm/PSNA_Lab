#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
float quad(float a,float b,float c,float x);
float absu(float f);

int main()
{
    float a,b,c,result;

    cout<<"Enter the coeff of quadratic equations: a,b,c respectively:\n";
    cin>>a>>b>>c;

    float left,right,m;
    int accuracy;
    cout<<"Enter accuracy\n";
    cin>>accuracy;
    float arr=pow(10,-accuracy);



    cout<<"Enter left and right limit respectively:\n";
    cin>>left>>right;
    if(quad(a, b, c,left)<quad( a, b, c,right))
    {
        float temp;
        temp=left;
        left=right;
        right=temp;
    }


    int t=100;

    do
    {
        m=(left+right)/2;
        result=quad(a,b,c,m);
       cout<<m<<"\n";

    if(result>0)
    {
       left=m;
    }
    else
        right=m;

    }while(absu(result-quad(a,b,c,(left+right)/2))<arr);

    cout<<"Answer is :"<<m;





    return 0;
}

float quad(float a,float b,float c,float x)
{
    return (a*x*x + b*x +c);
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
