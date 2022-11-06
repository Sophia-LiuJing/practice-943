#include<bits/stdc++.h>
using namespace std;
map<int,int>s1,s2,s3;
int main()
{
	int a,b,c,x;
	cin>>a>>b>>c;//1<=a,b,c<=1e5; 
	int max1=0;
	//三个数组元素的范围不确定,题上没说范围,用数组标记运行错误
	//数组元素中肯定有大于int的,所以用数组就为爆栈
	//STL set或map标记(1e5的数据范围,每个元素查找次数不会超过17次) 
	for(int i=0;i<a;i++)
	{
		cin>>x;
		s1[x]++;//标记 
		max1=max(max1,x);//找到最大值 
	}
	for(int i=0;i<b;i++)
	{
		cin>>x;
		s2[x]++;
		max1=max(max1,x);
	}
	for(int i=0;i<c;i++)
	{
		cin>>x;
		s3[x]++;
		max1=max(max1,x);
	}
	for(int i=0;i<=max1;i++)
		if(s3.count(i)&&s1.count(i)&&s2.count(i))//查看是否在三个容器同时出现 
			cout<<i<<" ";
	return 0;
}

