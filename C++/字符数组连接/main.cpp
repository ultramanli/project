#include <iostream>
#include <string.h>
using namespace std;

int main()
{



    char a[11]="CLASS",b[]="BASE";
    strcat(a,b);
    cout<<a<<endl<<endl;//方法2


    string c="CLASS",d="BASE";
    c=c+d;
    cout<<c<<endl;//方法3
    return 0;
}
