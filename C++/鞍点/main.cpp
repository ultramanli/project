#include <iostream>

using namespace std;

int main()
{
    int a[50][50],b[50][50],c[50][50],x,y,p,q,i,j,m,n,maxi,mini;
    cout<<"Input the array's Row and Colum"<<endl;
    cin>>x>>y;
    cout<<endl<<"Input the all num"<<endl;
    for(i=0; i<x; ++i)
    {
        for(j=0; j<y; ++j)
        {
            cin>>a[i][j];
        }
    }


    for(i=0; i<x; ++i)
    {
        maxi=a[i][0];
        m=i;
        n=0;
        for(j=0; j<y; ++j)
        {
            if(a[i][j]>maxi)
            {
                maxi=a[i][j];
                m=i;
                n=j;
            }

        }
        b[m][n]=a[m][n];
    }




    /*cout<<endl<<"Every rows' biggest sum"<<endl;
    for(i=0; i<x; ++i)
    {
        for(j=0; j<y; ++j)
        {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
*/


    for(j=0; j<y; ++j)
    {
        mini=a[0][j];
        m=0;
        n=j;
        for(i=0; i<x; ++i)
        {
            if(a[i][j]<mini)
            {
                mini=a[i][j];
                m=i;
                n=j;
            }

        }
        c[m][n]=a[m][n];
    }

    cout<<endl;
 /*   cout<<"Every colums' smallest sum"<<endl;

    for(i=0; i<x; ++i)
    {
        for(j=0; j<y; ++j)
        {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }*/
int l=0;
  for(p=0; p<x; ++p)
    {
        for(q=0; q<y; ++q)
        {
            if(c[p][q]==b[p][q]&&c[p][q]!=0)
            {
               l=l+1;
            }


        }
    }
   cout<<endl<<"This array have"<<" "<<l<<" "<<"point"<<endl;
l=0;

    for(p=0; p<x; ++p)
    {
        for(q=0; q<y; ++q)
        {
            if(c[p][q]==b[p][q]&&c[p][q]!=0)
            {l=l+1;
                cout<<endl<<"Point"<<l<<" is "<<a[p][q]<<" "<<"Row="<<p<<" Colum="<<q<<endl;
            }


        }
    }


    return 0;
}

