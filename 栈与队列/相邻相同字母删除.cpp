#include<bits/stdc++.h>
using namespace std;
const int N=1e+5+10;
char a[N];
char s[N]={0};
int top=-1;
int len=0;
int k=0;
void dfs()
{
	s[++top]=a[k++];//入栈
	if(s[top]==s[top-1])//判断
		top-=2;//刚入栈的字符与其相邻的字符相同,他们就抵消了
	//代码描述就是,栈顶指针向下移两个单位
	if(k<=len)//未到字符串尾部,继续递归
		dfs();
}
int main()
{//abbac
	cin>>a;
	len=strlen(a)-1;
	dfs();//递归
	for(int i=0;i<=top;i++)
		cout<<s[i];
	return 0;
}

