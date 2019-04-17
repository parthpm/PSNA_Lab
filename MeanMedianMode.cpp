#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n,interval;
    cout<<"Enter the no of data you want to enter:"<<endl;
    cin>>n;
    float *f=new float[n]; //frequency
    float *x=new float[n];  //xi
    float *lower=new float[n]; //// lower value
    float *cf=new float[n];  //cf

    cout<<"Enter the lower limit of base class"<<endl;
    cin>>lower[0];
    cout<<"Enter the interval "<<endl;
    cin>>interval;

    x[0]=(lower[0]+interval)/2;

    for(int i=1;i<n;i++)
    {
        lower[i]=lower[i-1]+interval;
        x[i]=(lower[i-1]+lower[i])/2;
    }


    cout<<"Enter frequency "<<endl;
    cf[0]=f[0];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter f"<<i+1<<endl;
        cin>>f[i];
        if(i!=0)
        cf[i]=cf[i-1]+f[i];
    }


    float mean=0;
    for(int i=0;i<n;i++)
    {
        mean+=x[i]*f[i];
    }
    mean/=cf[n-1];
    cout<<"Mean is "<<mean<<endl;


    float f0,f2;
    int ind=0;

    float f1=*max_element(f,f+n);
    for(int i=0;i<n;i++)
    {
        if(f[i]==f1)
        {   ind=i;
            f0=f[i-1];
            f2=f[i+1];
        }
    }

    cout<<"Mode is: "<<lower[ind]+(f1-f0)/(2*f1-f0-f2)*interval<<endl;

    //for median class
    float cumf=0,freq=0,low=0;
    for(int i=0;i<n;i++)
    {
        if(cf[i]>cf[n-1]/2)
        {
            cumf=cf[i-1];
            freq=f[i];
            low=lower[i];
            break;

        }
    }

    cout<<"Median is: "<<low+(cf[n-1]-cumf)/freq*interval;






return 0;
}
