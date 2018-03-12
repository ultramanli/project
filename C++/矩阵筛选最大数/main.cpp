#include <iostream>

using namespace std;

int main()
{int a[3][4]={{7,10,15,31},{16,19,74,12},{13,48,94,54}};
int i,j,row,colum,max;
max=a[0][0];
for(i=0;i<3;++i)
{
    for(j=0;j<4;++j)
    {
        if(a[i][j]>max)
        {
            max=a[i][j];
        row=i+1;
        colum=j+1;
        }
    }
}
cout<<"max="<<max<<",row="<<row<<",colum"<<colum<<endl;
return 0;
}
