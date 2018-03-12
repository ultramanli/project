#include <iostream>
#include<string>
using namespace std;

int main()
{int i,j;
string a="* * * * *";
   cout<<a<<endl;
    for(i=1; i<=4; ++i)
    {
        for(j=4;j>=5-i; --j)
        {
            cout<<" ";
        }
   cout<<a<<endl;
    }
}
