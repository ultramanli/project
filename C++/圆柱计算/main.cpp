#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    int r,h;
    float l,s1,s2,v1,v2;
    double P=3.1415926;
    cout<<"请输入 半径 和 高"<<endl;
    cin>>r>>h;
    l=2*(P*r);
    s1=P*(P*r*r);
    s2=4*(P*r*r);
    v1=4*(P*r*r*r)/3;
    v2=s1*h;
    cout<<"周长"<<l<<endl;
    cout<<"圆的面积"<<s1<<endl;
    cout<<"球的表面积"<<s2<<endl;
    cout<<"球的体积"<<v1<<endl;
    cout<<"圆柱的体积"<<v2<<endl;
    return 0;
}
