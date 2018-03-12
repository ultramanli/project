 #include <iostream>

using namespace std;

int main()
{
    int a[50],b[51],i,j,t,x,y;
    cout<<"Input the sum of you array"<<endl;
    cin>>x;
   cout<<endl<<"Input the all num"<<endl;
   for(i=0;i<x;++i)
    {
        cin>>a[i];
    }
    for(i=0;i<x-1;++i)
    {
        for(j=0;j<x-i-1;++j)
        {
            if(a[j+1]>a[j])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
   cout<<endl;
    for(i=0;i<x;++i)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl<<"Now you can input an another number"<<endl;
    cin>>y;
    cout<<endl;
    for(i=0;i<x;++i)
    {b[i]=a[i];}
    b[x]=y;
    for(i=0;i<x;++i)
    {
        for(j=0;j<x-i;++j)
        {
            if(b[j+1]>b[j])
            {
                t=b[j];
                b[j]=b[j+1];
                b[j+1]=t;

            }
        }
    }
for(i=0;i<x+1;++i)
{
    cout<<b[i]<<" ";
}
    return 0;
}
