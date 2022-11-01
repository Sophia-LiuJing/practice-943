#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

typedef struct node{
	node *next;
	int val;
	node(){next=NULL;}
};

int main()
{
	int n,k,v;
	cin>>n>>k;
	node *head=new node(),*p=head;
	for(int i=1;i<=n;i++){
		cin>>v;
		p->val=v;
		if(i!=n){
			p->next=new node;
			p=p->next;
		}
	}
	p=head;
	k=n-k+1;
	if(k==1){//如果是第一个节点
		node *q=head;
		head=head->next;
		delete q;//删除第一个节点
	}
	p=head;
	int cnt=1;
	while(p){
		printf("%d ",p->val);
		if(cnt==k-1){
			node *q=p->next;
			p->next=q->next;
			delete q;
		}
		p=p->next;
		cnt++;
	}
	delete head;//释放节点，节省空间
	return 0;
}

