#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <windows.h>
using namespace std;
int x;
int main()
{
    system("color 07");
    cout<<"What do you want to do ?"<<endl<<endl;
    cout<<"1=Plus +"<<endl<<"2=Minus -"<<endl<<"3=Multiply *"<<endl<<"4=Division /"<<endl<<"5=Quit"<<endl<<endl;
    cin>>x;
    while(x>0&&x<5)
    {
        system("color 07");
        switch (x)
        {
        case 1:
            int f1();
            f1();
            system("pause");
            system("cls");
            cout<<"What do you want to do ?"<<endl;
            cout<<"1=Plus +"<<endl<<"2=Minus -"<<endl<<"3=Multiply *"<<endl<<"4=Division /"<<endl<<"5=Quit"<<endl<<endl;
            cin>>x;
            break;

        case 2:
            int f2();
            f2();
            system("pause");
            system("cls");
            cout<<"What do you want to do ?"<<endl;
            cout<<"1=Plus +"<<endl<<"2=Minus -"<<endl<<"3=Multiply *"<<endl<<"4=Division /"<<endl<<"5=Quit"<<endl<<endl;
            cin>>x;
            break;
        case 3:
            int f3();
            f3();
            system("pause");
            system("cls");
            cout<<"What do you want to do ?"<<endl;
            cout<<"1=Plus +"<<endl<<"2=Minus -"<<endl<<"3=Multiply *"<<endl<<"4=Division /"<<endl<<"5=Quit"<<endl<<endl;
            cin>>x;
            break;
        case 4:
            int f4();
            f4();
            system("pause");
            system("cls");
            cout<<"What do you want to do ?"<<endl;
            cout<<"1=Plus +"<<endl<<"2=Minus -"<<endl<<"3=Multiply *"<<endl<<"4=Division /"<<endl<<"5=Quit"<<endl<<endl;
            cin>>x;
            break;
        }
    }
    if(x<1||x>5)
    {
        system("cls");
        cout<<"Choose again ,please"<<endl<<endl;
        int f();
        f();
    }
    if(x=5)
    {
        system("cls");
        cout<<"Thanks to use!"<<endl<<endl;
    }
    system("pause");
}

int f()
{
    system("color 07");
    cout<<"What do you want to do ?"<<endl;
    cout<<"1=Plus +"<<endl<<"2=Minus -"<<endl<<"3=Multiply *"<<endl<<"4=Division /"<<endl<<"5=Quit"<<endl<<endl;
    cin>>x;
    while(x>0&&x<5)
    {
        system("color 07");
        switch (x)
        {
        case 1:
            int f1();
            f1();
            system("pause");
            system("cls");
            cout<<"What do you want to do ?"<<endl;
            cout<<"1=Plus +"<<endl<<"2=Minus -"<<endl<<"3=Multiply *"<<endl<<"4=Division /"<<endl<<"5=Quit"<<endl<<endl;
            cin>>x;
            break;

        case 2:
            int f2();
            f2();
            system("pause");
            system("cls");
            cout<<"What do you want to do ?"<<endl;
            cout<<"1=Plus +"<<endl<<"2=Minus -"<<endl<<"3=Multiply *"<<endl<<"4=Division /"<<endl<<"5=Quit"<<endl<<endl;
            cin>>x;
            break;
        case 3:
            int f3();
            f3();
            system("pause");
            system("cls");
            cout<<"What do you want to do ?"<<endl;
            cout<<"1=Plus +"<<endl<<"2=Minus -"<<endl<<"3=Multiply *"<<endl<<"4=Division /"<<endl<<"5=Quit"<<endl<<endl;
            cin>>x;
            break;
        case 4:
            int f4();
            f4();
            system("pause");
            system("cls");
            cout<<"What do you want to do ?"<<endl;
            cout<<"1=Plus +"<<endl<<"2=Minus -"<<endl<<"3=Multiply *"<<endl<<"4=Division /"<<endl<<"5=Quit"<<endl<<endl;
            cin>>x;
            break;
        }
    }

    if(x<1||x>5)
    {
        system("cls");
        cout<<"Choose again ,please"<<endl<<endl;
        int f();
        f();
    }
    if(x=5)
    {
        system("cls");
        cout<<"Thanks to use!"<<endl<<endl;
    }


    system("pause");
}



int f1()
{
    int a,b,c,i,n,m=0;
    cout<<"Input the how much exercise that you want"<<endl;
    cin>>n;
    cout<<endl;
    for(i=0; i<n; ++i)
    {
        srand(time(NULL));
        a=rand()%21;
        b=rand()%21;
        cout<<a<<"+"<<b<<"=";
        cin>>c;
        if(c==a+b)
        {
            m=m+1;
            cout<<"Good boy!"<<endl<<endl;
            system("pause");
        }
        else
        {
            cout<<"NO NO NO!"<<endl<<endl;
            system("pause");
        }

    }
    m=(m*100)/n
      ;
    cout<<endl<<"ATTETION!"<<"You score is="<<m<<endl<<endl;
    if(m==100)
    {
        system("cls");

        cout<<"Congratulation !!"<<endl<<endl<<"Jiang Ying you get 100!!!"<<endl<<endl<<endl<<char(3)<<char(3)<<char(3)<<char(3)<<char(3)<<"     "<<char(3)<<setw(6)<<char(3)<<char(3)<<char(3)<<char(3)<<setw(2)<<char(3)<<setw(6)<<char(3)<<" "<<char(3)<<char(3)<<char(3)<<char(3)<<char(3)<<"     "<<char(3)<<"     "
            <<char(3)<<" "<<char(3)<<char(3)<<char(3)<<char(3)<<"  "<<char(3)<<"    "<<char(3)<<endl;
        Sleep(1000);cout<<"  "<<char(3)<<setw(8)<<char(3)<<setw(5)<<char(3)<<setw(5)<<char(3)<<setw(2)<<char(3)<<setw(4)<<char(3)<<"  "<<char(3)<<"          "<<char(3)<<"   "<<char(3)<<" "<<char(3)<<"    "
            <<char(3)<<" "<<char(3)<<"    "<<char(3)<<endl;
        Sleep(1000);cout<<"  "<<char(3)<<setw(8)<<char(3)<<setw(5)<<char(3)<<setw(5)<<char(3)<<setw(2)<<char(3)<<setw(4)<<char(3)<<"  "<<char(3)<<char(3)<<char(3)<<char(3)<<"         "<<char(3)<<"   "<<char(3)<<"    "
            <<char(3)<<" "<<char(3)<<"    "<<char(3)<<endl;
       Sleep(1000); cout<<"  "<<char(3)<<setw(8)<<char(3)<<setw(5)<<char(3)<<setw(5)<<char(3)<<setw(2)<<char(3)<<setw(4)<<char(3)<<"  "<<char(3)<<"            "<<char(3)<<"   "<<char(3)<<"    "<<char(3)<<" "<<char(3)<<"    "<<char(3)<<endl;
        Sleep(1000);cout<<char(3)<<char(3)<<char(3)<<char(3)<<char(3)<<"     "<<char(3)<<char(3)<<char(3)<<char(3)<<char(3)<<setw(2)<<char(3)<<char(3)<<char(3)<<char(3)<<setw(5)<<char(3)<<"    "<<char(3)<<char(3)<<char(3)<<char(3)<<char(3)<<"        "
            <<char(3)<<"    "<<char(3)<<char(3)<<char(3)<<char(3)<<"   "<<char(3)<<char(3)<<char(3)<<char(3)<<endl;
        system("pause");
        system("color 07");
    }
    return 0;
}

int f2()
{
    int a,b,c,i,n,m=0;
    cout<<"Input the how much exercise that you want"<<endl;
    cin>>n;
    cout<<endl;
    for(i=0; i<n; ++i)
    {
        srand(time(NULL));
        a=rand()%21;
        b=rand()%21;
        cout<<a<<"-"<<b<<"=";
        cin>>c;
        if(c==a-b)
        {
            m=m+1;
            cout<<"Good boy!"<<endl<<endl;
            system("pause");
        }
        else
        {
            cout<<"NO NO NO!"<<endl<<endl;
            system("pause");
        }
    }
    m=(m*100)/n;
    cout<<endl<<"ATTETION!"<<"You score is="<<m<<endl<<endl;
    if(m==100)
    {
        system("cls");

        cout<<"Congratulation !!"<<endl<<endl<<"Jiang Ying you get 100!!!"<<endl<<endl<<endl<<char(3)<<char(3)<<char(3)<<char(3)<<char(3)<<"     "<<char(3)<<setw(6)<<char(3)<<char(3)<<char(3)<<char(3)<<setw(2)<<char(3)<<setw(6)<<char(3)<<" "<<char(3)<<char(3)<<char(3)<<char(3)<<char(3)<<"     "<<char(3)<<"     "
            <<char(3)<<" "<<char(3)<<char(3)<<char(3)<<char(3)<<"  "<<char(3)<<"    "<<char(3)<<endl;
        Sleep(1000);cout<<"  "<<char(3)<<setw(8)<<char(3)<<setw(5)<<char(3)<<setw(5)<<char(3)<<setw(2)<<char(3)<<setw(4)<<char(3)<<"  "<<char(3)<<"          "<<char(3)<<"   "<<char(3)<<" "<<char(3)<<"    "
            <<char(3)<<" "<<char(3)<<"    "<<char(3)<<endl;
        Sleep(1000);cout<<"  "<<char(3)<<setw(8)<<char(3)<<setw(5)<<char(3)<<setw(5)<<char(3)<<setw(2)<<char(3)<<setw(4)<<char(3)<<"  "<<char(3)<<char(3)<<char(3)<<char(3)<<"         "<<char(3)<<"   "<<char(3)<<"    "
            <<char(3)<<" "<<char(3)<<"    "<<char(3)<<endl;
       Sleep(1000); cout<<"  "<<char(3)<<setw(8)<<char(3)<<setw(5)<<char(3)<<setw(5)<<char(3)<<setw(2)<<char(3)<<setw(4)<<char(3)<<"  "<<char(3)<<"            "<<char(3)<<"   "<<char(3)<<"    "<<char(3)<<" "<<char(3)<<"    "<<char(3)<<endl;
        Sleep(1000);cout<<char(3)<<char(3)<<char(3)<<char(3)<<char(3)<<"     "<<char(3)<<char(3)<<char(3)<<char(3)<<char(3)<<setw(2)<<char(3)<<char(3)<<char(3)<<char(3)<<setw(5)<<char(3)<<"    "<<char(3)<<char(3)<<char(3)<<char(3)<<char(3)<<"        "
            <<char(3)<<"    "<<char(3)<<char(3)<<char(3)<<char(3)<<"   "<<char(3)<<char(3)<<char(3)<<char(3)<<endl;
        system("pause");
        system("color 07");
    }
    return 0;


}
int f3()
{
    int a,b,c,i,n,m=0;
    cout<<"Input the how much exercise that you want"<<endl;//¡Á,¡Â
    cin>>n;
    cout<<endl;
    for(i=0; i<n; ++i)
    {
        srand(time(NULL));
        a=rand()%21;
        b=rand()%21;
        cout<<a<<"¡Á"<<b<<"=";
        cin>>c;
        if(c==a*b)
        {
            m=m+1;
            cout<<"Good boy!"<<endl<<endl;
            system("pause");
        }
        else
        {
            cout<<"NO NO NO!"<<endl<<endl;
            system("pause");
        }


    }
    m=(m*100)/n;
    cout<<endl<<"ATTETION!"<<"You score is="<<m<<endl<<endl;
    if(m==100)
    {
        system("cls");

        cout<<"Congratulation !!"<<endl<<endl<<"Jiang Ying you get 100!!!"<<endl<<endl<<endl<<char(3)<<char(3)<<char(3)<<char(3)<<char(3)<<"     "<<char(3)<<setw(6)<<char(3)<<char(3)<<char(3)<<char(3)<<setw(2)<<char(3)<<setw(6)<<char(3)<<" "<<char(3)<<char(3)<<char(3)<<char(3)<<char(3)<<"     "<<char(3)<<"     "
            <<char(3)<<" "<<char(3)<<char(3)<<char(3)<<char(3)<<"  "<<char(3)<<"    "<<char(3)<<endl;
        Sleep(1000);cout<<"  "<<char(3)<<setw(8)<<char(3)<<setw(5)<<char(3)<<setw(5)<<char(3)<<setw(2)<<char(3)<<setw(4)<<char(3)<<"  "<<char(3)<<"          "<<char(3)<<"   "<<char(3)<<" "<<char(3)<<"    "
            <<char(3)<<" "<<char(3)<<"    "<<char(3)<<endl;
        Sleep(1000);cout<<"  "<<char(3)<<setw(8)<<char(3)<<setw(5)<<char(3)<<setw(5)<<char(3)<<setw(2)<<char(3)<<setw(4)<<char(3)<<"  "<<char(3)<<char(3)<<char(3)<<char(3)<<"         "<<char(3)<<"   "<<char(3)<<"    "
            <<char(3)<<" "<<char(3)<<"    "<<char(3)<<endl;
       Sleep(1000); cout<<"  "<<char(3)<<setw(8)<<char(3)<<setw(5)<<char(3)<<setw(5)<<char(3)<<setw(2)<<char(3)<<setw(4)<<char(3)<<"  "<<char(3)<<"            "<<char(3)<<"   "<<char(3)<<"    "<<char(3)<<" "<<char(3)<<"    "<<char(3)<<endl;
        Sleep(1000);cout<<char(3)<<char(3)<<char(3)<<char(3)<<char(3)<<"     "<<char(3)<<char(3)<<char(3)<<char(3)<<char(3)<<setw(2)<<char(3)<<char(3)<<char(3)<<char(3)<<setw(5)<<char(3)<<"    "<<char(3)<<char(3)<<char(3)<<char(3)<<char(3)<<"        "
            <<char(3)<<"    "<<char(3)<<char(3)<<char(3)<<char(3)<<"   "<<char(3)<<char(3)<<char(3)<<char(3)<<endl;
        system("pause");
        system("color 07");
    }
    return 0;
}
void f4()
{

    int a,b,c,d,i,n,m=0;
    cout<<"Input the how much exercise that you want"<<endl;
    cin>>n;
    cout<<endl;
    for(i=0; i<n; ++i)
    {
        srand(time(NULL));
        a=rand()%21;
        b=rand()%21;
        while(b==0)
        {
            b=rand()%21;
            if(b!=0)break;

        }
        if(b!=0)
        {

            cout<<a<<"¡Â"<<b<<"=";
            if(a%b!=0)
            {
                cin>>c;
                cout<<"remainder=";

                cin>>d;
                if(c==a/b&&d==a%b)
                {
                    m=m+1;
                    cout<<"Good boy!"<<endl<<endl;
                    system("pause");
                }
                else
                {
                    m=m;
                    cout<<"NO NO NO!"<<endl<<endl;
                    system("pause");
                }
            }
            else
            {
                cin>>c;
                if(c==a/b)
                {
                    m=m+1;
                    cout<<"Good boy!"<<endl<<endl;
                    system("pause");
                }
                else
                {
                    m=m;
                    cout<<"NO NO NO!"<<endl<<endl;
                    system("pause");
                }
            }
        }
    }
    m=(m*100)/n;
    cout<<endl<<"ATTETION!"<<"You score is="<<m<<endl<<endl;
   if(m==100)
    {
        system("cls");

        cout<<"Congratulation !!"<<endl<<endl<<"Jiang Ying you get 100!!!"<<endl<<endl<<endl<<char(3)<<char(3)<<char(3)<<char(3)<<char(3)<<"     "<<char(3)<<setw(6)<<char(3)<<char(3)<<char(3)<<char(3)<<setw(2)<<char(3)<<setw(6)<<char(3)<<" "<<char(3)<<char(3)<<char(3)<<char(3)<<char(3)<<"     "<<char(3)<<"     "
            <<char(3)<<" "<<char(3)<<char(3)<<char(3)<<char(3)<<"  "<<char(3)<<"    "<<char(3)<<endl;
        Sleep(1000);cout<<"  "<<char(3)<<setw(8)<<char(3)<<setw(5)<<char(3)<<setw(5)<<char(3)<<setw(2)<<char(3)<<setw(4)<<char(3)<<"  "<<char(3)<<"          "<<char(3)<<"   "<<char(3)<<" "<<char(3)<<"    "
            <<char(3)<<" "<<char(3)<<"    "<<char(3)<<endl;
        Sleep(1000);cout<<"  "<<char(3)<<setw(8)<<char(3)<<setw(5)<<char(3)<<setw(5)<<char(3)<<setw(2)<<char(3)<<setw(4)<<char(3)<<"  "<<char(3)<<char(3)<<char(3)<<char(3)<<"         "<<char(3)<<"   "<<char(3)<<"    "
            <<char(3)<<" "<<char(3)<<"    "<<char(3)<<endl;
       Sleep(1000); cout<<"  "<<char(3)<<setw(8)<<char(3)<<setw(5)<<char(3)<<setw(5)<<char(3)<<setw(2)<<char(3)<<setw(4)<<char(3)<<"  "<<char(3)<<"            "<<char(3)<<"   "<<char(3)<<"    "<<char(3)<<" "<<char(3)<<"    "<<char(3)<<endl;
        Sleep(1000);cout<<char(3)<<char(3)<<char(3)<<char(3)<<char(3)<<"     "<<char(3)<<char(3)<<char(3)<<char(3)<<char(3)<<setw(2)<<char(3)<<char(3)<<char(3)<<char(3)<<setw(5)<<char(3)<<"    "<<char(3)<<char(3)<<char(3)<<char(3)<<char(3)<<"        "
            <<char(3)<<"    "<<char(3)<<char(3)<<char(3)<<char(3)<<"   "<<char(3)<<char(3)<<char(3)<<char(3)<<endl;
        system("pause");
        system("color 07");
    }
}
