#include <iostream>

using namespace std;
int a,b,c,n;
int main()

{
    cout<<"请输入三个数字"<<endl;
    cin>>a>>b>>c;
    int fac();
    fac();

    cout<<endl<<"三个数字的阶乘的和="<<n;
}

int fac()
{
    int m,x,y,z;
    for(m=1,x=1; m<=a; ++m)
    {
        x=x*m;
    }
   for(m=1,y=1; m<=b; ++m)
    {
        y=y*m;
    }
    for(m=1,z=1; m<=c; ++m)
    {
        z=z*m;
    }
    n=x+y+z;
    return(n);
}
