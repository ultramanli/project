#include <iostream>

using namespace std;

int main()
{int a[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
int i,j,row,colum,max;
int maxl(int x,int max);
max=a[0][0];
for(i=0;i<3;++i)
{
    for(j=0;j<4;++j)
        {
            max=maxl(a[i][j],max);//¸³Öµ
            if(max==a[i][j])
            {
                row=i;
                colum=j;
            }
        }
}

cout<<"max="<<max<<",row="<<row+1<<",colum="<<colum+1<<endl;
return 0;



}
int maxl(int x,int max)
{if(x>max)return x;
else return max;

}
