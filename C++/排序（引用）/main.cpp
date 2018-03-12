#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int f(int &,int &,int &);
    f(a,b,c);
    cout<<a<<" "<<b<<" "<<c;
    return (0);
}
int f(int &x,int &y,int &z)
{
    int p,q,r;
    if(y>x&&y>z)
    {
        p=x;
        x=y;
        y=p;
        if(z>x)
        {
            p=y;
            y=z;
            z=p;
        }

    }
    if(x>y&&x>z)
    {
        if(z>y)
        {
            p=y;
            y=z;
            z=p;
        }



    }
    if(z>x&&z>y)
    {
        p=x;
        x=z;
        z=p;
        if(z>y)
        {
            p=z;
            z=y;
            y=p;
        }
    }
}
