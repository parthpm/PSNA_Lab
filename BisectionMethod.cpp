#include<iostream>
#include<iomanip>
using namespace std;
float quad(float a,float b,float c,float x);

int main()
{
    float a,b,c,result;

    cout<<"Enter the coeff of quadratic equations: a,b,c respectively:\n";
    cin>>a>>b>>c;

    float left,right,m;
    int accuracy;
    cout<<"Enter accuracy\n";
    cin>>accuracy;



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
    while(t--)
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

    }

    cout<<"Answer is :"<<setprecision(accuracy)<<m;





    return 0;
}

float quad(float a,float b,float c,float x)
{
    return (a*x*x + b*x +c);
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
