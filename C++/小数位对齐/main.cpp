#include <iostream>
#include <iomanip>
using namespace std;
int x,i;
int main()
{
    cout<<"Input X"<<endl;
    cin>>x;
    cout<<"Input arrray"<<endl;
    double a[50];
    for(i=0; i<x; ++i)
    {
        cin>>a[i];

    }
    for(i=0; i<x; ++i)
    {
        cout<<setiosflags(ios::fixed)<<setiosflags(ios::right)<<setprecision(3)<<setw(100)<<a[i]<<endl;
    }


    return 0;
}
