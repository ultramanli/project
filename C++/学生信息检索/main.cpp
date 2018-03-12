#include <iostream>
#include<string>
#include<stdlib.h>
using namespace std;
string name[10],num[10],sex[10],age[10],eng[10],math[10],find_name;
int n;
int main()
{
    int input();
    int look();
    int a,x;
    cout<<"Please input the number of student"<<endl;
    cin>>n;
    system("cls");
    cout<<endl<<"Please choose what you want"<<endl<<"1=add the information"<<endl<<"2=search the information that you want"<<endl<<"3=quit"<<endl<<endl;

    cin>>a;
    system("cls");
    while(a!=3)
    {



        switch (a)
        {
        case 1:


            cout<<"Pleace input the information of students"<<endl<<endl;
            input();
            cout<<endl<<"Please choose what you want"<<endl<<"1=add the information"<<endl<<"2=search the information that you want"<<endl<<"3=quit"<<endl<<endl;
            cin>>a;
            break;

        case 2:

system("cls");
            cout<<"please input the information that you want"<<endl;
            cin>>find_name;

            look();
            cout<<endl<<"Please choose what you want"<<endl<<"1=add the information"<<endl<<"2=search the information that you want"<<endl<<"3=quit"<<endl<<endl;
            cin>>a;
            break;

        }
    }
if(a==3){cout<<endl<<"Thanks to use!!!";}
    return 0;
}

int input()
{
    int i;
    for(i=0; i<n; i++)
    {system("cls");
        cout<<"in put the Name  Number Sex Age Eng Math of No."<<i+1<<endl;
        cin>>name[i]>>num[i]>>sex[i]>>age[i]>>eng[i]>>math[i];
system("cls");
    }

}

int look()
{
    int i;
    bool x=false;
    for(i=0; i<n; i++)
    {
        if(name[i]==find_name)
        {
            system("cls");
            cout<<"name is "<<name[i]<<endl<<"num is "<<num[i]<<endl<<"sex is "<<sex[i]<<endl<<"age is "<<age[i]<<endl<<"eng is "<<eng[i]<<endl<<"math is "<<math[i]<<endl;
            x=true;
        }
    }
    if(x==false){
            system("cls");
            cout<<endl<<"Nobody but you~"<<endl;


}}
