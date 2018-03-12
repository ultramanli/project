#include <iostream>
using namespace std;
int main()
{
    int a[20];
    int i,j,x;
    cout<<"please cin 20 number"<<endl;
    for(i=1; i<21; ++i)
    {
        cin>>a[i];
    }
    cout<<endl;
    for(i=1; i<=19; ++i)
    {
        for(j=1; j<=20-i; ++j)
        {
            if(a[j]<a[j+1])
            {
                x=a[j];
                a[j]=a[j+1];
                a[j+1]=x;
            }
        }
    }
    for(i=1;i<=20;++i)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
