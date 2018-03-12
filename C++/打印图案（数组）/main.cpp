#include <iostream>

using namespace std;
 char a[5]= {'*','*','*','*','*'};
int main()
{
    int i,j;
   char f();
for(i=0;i<5;++i)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(i=1; i<=4; ++i)
    {
        for(j=4;j>=5-i; --j)
        {
            cout<<" ";
        }
   cout<<f()<<endl;
    }

}
char f()
{int i;
    for(i=0;i<5;++i)
    {
        cout<<a[i]<<" ";
    }
}
