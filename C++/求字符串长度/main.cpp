#include <iostream>
#include <string.h>
#include <string>
using namespace std;
string a;
int n;
int main()
{
    int &p=n;
    cout<<"Input the string"<<endl;
    cin>>a;
    void f();

    f();
    cout<<p;
    return 0;
}
void f()
{
    n=a.size();
}
