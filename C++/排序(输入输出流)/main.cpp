#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
int a[10],b[10],c[20];
int main()
{
    int i,j,t;
    cout<<"It's time to input 20 nums,Step 1"<<endl;
    fstream outfile;
    outfile.open("f1.dat",ios::out);
    for(i=0; i<10; ++i)
    {
        cin>>a[i];
        outfile<<a[i]<<" ";
    }
    outfile.close();

    outfile.open("f2.dat",ios::out);

    for(i=0; i<10; ++i)
    {
        cin>>b[i];
        outfile<<b[i]<<" ";
    }

    outfile.close();
    fstream infile;

    cout<<"Now we are in Step 2"<<endl;
    system("pause");

    infile.open("f1.dat",ios::in);
    for(i=0; i<10; ++i)
    {
        infile>>a[i];
    }
    infile.close();

    outfile.open("f2.dat",ios::out);
    for(i=0; i<10; ++i)
    {

        c[i]=b[i];
    }
    for(i=10; i<20; ++i)
    {
        outfile<<a[i];
        c[i]=a[i-10];
    }


    cout<<"Now we are in Step 3"<<endl;
    system("pause");

    for(i=0; i<19; ++i)
{
    for(j=0;j<19-i;++j)
    {if(c[j+1]<c[j])
    {
        t=c[j];
        c[j]=c[j+1];
        c[j+1]=t;
    }

    }
}

outfile.close();
outfile.open("f2.dat",ios::out);
cout<<"GO GO GO"<<endl;
system("pause");
for(i=0;i<20;++i)
{
    outfile<<c[i];
    cout<<c[i]<<" ";
}
outfile.close();

        return 0;



}
