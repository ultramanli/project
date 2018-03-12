#include<iostream>
#include<iomanip>
#include<windows.h>
using namespace std;
int a[5];
int b;
int main()//没有优化界面的功能体现
{ cout<<"If you can find you birthday in the next number:"<<endl<<"Yes=1 No=0"<<endl;
cout<<"16-31"<<endl;
cin>>a[0];
cout<<"8-15 24-31"<<endl;
cin>>a[1];
cout<<"4-7 12-15 20-23 28-31"<<endl;
cin>>a[2];
cout<<"2 3 6-7 10-11 14-15 18-19 22-23 26-27 31"<<endl;
cin>>a[3];
cout<<"1 3 5 7 9 11 13 15 17 19 21 23 25 27 29 30 31"<<endl;
cin>>a[4];
b=a[4]*1+a[3]*2+a[2]*4+a[1]*8+a[0]*16;
cout<<endl<<"Your day is="<<b<<endl;
}

//下面是界面优化过的(字段宽度、输入检查、结果检查、人机交互)
/*

char a[5]={'y','y','y','y','y'};
int b,i;
bool x;
int main()
{ char check(char c);
cout<<"If you can find you birthday in the next number"<<endl<<"Input :Yes=y No=n"<<endl;

cout<<endl<<setw(11)<<"16 17 18 19"<<endl<<setw(11)<<"20 21 22 23"<<endl<<setw(11)<<"24 25 26 27"<<endl<<setw(11)<<"28 29 30 31"<<endl;
cin>>a[0];
while(check(a[0]))
{
    cout<<"Wrong , please select again"<<endl;
    cin>>a[0];

}

cout<<endl<<setw(11)<<"8  9  10 11"<<endl<<setw(11)<<"12 13 14 15"<<endl<<setw(11)<<"24 25 26 27"<<endl<<setw(11)<<"28 29 30 31"<<endl;
cin>>a[1];
while(check(a[1]))
{
    cout<<"Wrong , please select again"<<endl;
    cin>>a[1];

}

cout<<endl<<setw(11)<<"4  5  6  7 "<<endl<<setw(11)<<"12 13 14 15"<<endl<<setw(11)<<"20 21 22 23"<<endl<<setw(11)<<"28 29 30 31"<<endl;
cin>>a[2];
while(check(a[2]))
{
    cout<<"Wrong , please select again"<<endl;
    cin>>a[2];

}

cout<<endl<<setw(11)<<"2  3  6  7 "<<endl<<setw(11)<<"10 11 14 15"<<endl<<setw(11)<<"18 19 22 23"<<endl<<"26 27 31"<<endl;
cin>>a[3];
while(check(a[3]))
{
    cout<<"Wrong , please select again"<<endl;
    cin>>a[3];

}

cout<<endl<<setw(11)<<"1  3  5  7 "<<endl<<setw(11)<<"9  11 13 15"<<endl<<setw(11)<<"17 19 21 23"<<endl<<setw(11)<<"25 27 29 30 31"<<endl;
cin>>a[4];
while(check(a[4]))
{
    cout<<"Wrong , please select again"<<endl;
    cin>>a[4];

}

for(i=0;i<5;++i)//Y、N转换为1、0
{
    if(a[i]=='y'||a[i]=='Y'){a[i]=1;}
    else {a[i]=0;}
}

b=a[4]*1+a[3]*2+a[2]*4+a[1]*8+a[0]*16;
if(b==0){cout<<endl<<"You have never been born ,My God..."<<endl<<endl;}//排除00000的情况
else {cout<<endl<<endl<<"Your day is="<<b<<endl;}
system("pause");
system("cls");
cout<<"Thanks to use ~"<<endl;
}

char check(char c)//检查输入的正确与否
{
    if(c=='y'||c=='n'||c=='Y'||c=='N')
    {
        x=false;
    }
    else {x=true;
    }
    return x;

}
*/
