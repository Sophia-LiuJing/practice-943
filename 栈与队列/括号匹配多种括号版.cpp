#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

typedef struct Stack{
	char data[1000000];
	int top=-1;
}Stack;
int main()
{
	Stack s;
	char tmp[2000000];
	while(scanf("%s",tmp)!=EOF){
		int len=strlen(tmp);
		int flag=0;
		for(int i=0;i<len;i++){
			if(tmp[i]=='(' || tmp[i]=='[' || tmp[i]=='{'){//左括号入栈
				s.top++;
				s.data[s.top]=tmp[i];
			}else{//右括号匹配
				if(tmp[i]==')'&&s.data[s.top]=='(') s.top--;
				else if(tmp[i]==']'&&s.data[s.top]=='[') s.top--;
				else if(tmp[i]=='}'&&s.data[s.top]=='{') s.top--;
				else{
					printf("no\n");
					flag=1;
					break;
				}
			}
		}
		if(s.top==-1)  printf("yes\n");
		else if(flag==0) printf("no\n");
	}
}
