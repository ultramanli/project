#include <iostream>
//#include<cmath
#include<stdio.h>
using namespace std;

int main()
{
    char a;
   int sum=0;
   cout<<"输入一句话，用空格隔开单词，用.结束:";
    while((a=getchar())!='.')
    {

        if(a==32)sum++;


    }
cout<<"共有"<<sum+1<<"个单词";
   // cout<<"字母数"<<b<<endl;
    //cout<<"空格数"<<c<<endl;
   // cout<<"数字数"<<d<<endl;
    //cout<<"其他字符"<<e;
    return 0;
}

