#include <iostream>

using namespace std;

int main()
{
    int i=1,n=0;
    while(i<=7)
    {
        while(i<=4)
        {
            while(n!=2*i-1)
            {
                cout<<"*";
                n=n+1;

            }
            cout<<endl;
            i=i+1  ;
            n=0;
        }

        while(4<i&&i<=7)
        {
            while(n!=15-2*i)
            {
                cout<<"*";
                n=n+1;
            }
            cout<<endl;
            i=i+1;
            n=0;
        }

    }
    return 0;
}
