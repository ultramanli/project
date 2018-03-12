#include <iostream>

using namespace std;

int main()
{
    int i,j,x,y,a[100][100];
    cout<<"Please input the ROW that you want(one number is OK and <=100)"<<endl;
    cin>>x;
    if(x>0&&x<=100)
    {
        cout<<"Please input a "<<x<<"*"<<x<<" matrix"<<endl;
        for(i=0; i<x; ++i)
        {
            for(j=0; j<x; ++j)
            {
                cin>>a[i][j];


            }

        }
        for(i=0,j=0,y=0; i<x&&j<x; ++i,++j)
        {
            y=y+a[i][j];
        }
        cout<<endl<<"the plus of diagonal="<<y<<endl;
    }
    else cout<<endl<<"WANING !!!"<<endl<<"Please do as the rule said"<<endl;
    return 0;
}
