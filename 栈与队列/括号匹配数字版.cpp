#include<iostream>
#include<cstring>
using namespace std;


//定义栈
#define maxSize 100100;
typedef struct Stack
{
    int data[100100];
    int top=-1;
}Stack;


int main(void)
{
    Stack s;
    char ls[100100];
    int index[100100];

    while(scanf("%s",&ls)!=EOF){
        int len=strlen(ls); //括号序列的长度
        memset(index,0,sizeof(index));
        for(int i=0;i<len;i++){
            if(ls[i]=='('){ //左括号入栈
                s.data[++s.top]=i+1;
            }else{ //右括号
                int j=s.data[s.top--];
                index[j]=i+1;
            }
        }
        for(int i=0;i<len;i++){
            if(index[i]!=0){
                printf("%d %d\n",i,index[i]);
            }
        }
    }
    
    return 0;
}