#include <iostream>

using namespace std;

int main()
{
    int x,y,a,b,c;

    for(x=100; x<1000; x=x+1)
    {
        a=x/100;
        b=(x-100*a)/10;
        c=(x-100*a-10*b);
        y=a*a*a+b*b*b+c*c*c;
        if(x==y)cout<<y<<endl;
    }
    return 0;
}
