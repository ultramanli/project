#include <iostream>
#include<stdlib.h>
using namespace std;
int x,y,i,j;
int a[6][6]= {{48,48,3,48,48,48},{3,48,48,48,48,48},{48,48,48,48,3,48},{48,3,48,48,48,48},{48,48,3,48,3,48},{3,48,3,48,3,48}};
char b[6][6]= {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'};

int main()
{

    for(i=0; i<6; ++i)
    {
        for(j=0; j<6; ++j)
        {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"It time to do something ..."<<endl;
    cin>>x>>y;
    system("cls");
    b[y-1][x-1]=a[y-1][x-1];
    if(a[y-1][x-1]==3)
    {
        for(i=0; i<6; ++i)
        {
            for(j=0; j<6; ++j)
            {
                b[i][j]=a[i][j];
                cout<<b[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl<<"BOOM~~ShaKaLaKa!!!!!!!"<<endl;


    }

    else
    {
        for(i=0; i<6; ++i)
        {
            for(j=0; j<6; ++j)
            {

                cout<<b[i][j]<<" ";
            }
            cout<<endl;
        }
    system("cls");
void f();
f(); }


}

void f()
{
     for(i=0; i<6; ++i)
    {
        for(j=0; j<6; ++j)
        {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"It time to do something ..."<<endl;
    cin>>x>>y;
    system("cls");
    b[y-1][x-1]=a[y-1][x-1];
    if(a[y-1][x-1]==3)
    {
        for(i=0; i<6; ++i)
        {
            for(j=0; j<6; ++j)
            {
                b[i][j]=a[i][j];
                cout<<b[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl<<"BOOM~~ShaKaLaKa!!!!!!!"<<endl;


    }

    else
    {
        for(i=0; i<6; ++i)
        {
            for(j=0; j<6; ++j)
            {

                cout<<b[i][j]<<" ";
            }
            cout<<endl;
        }
    system("cls");
f(); }


}
