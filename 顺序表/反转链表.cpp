#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

typedef struct node{
	node *next;
	int val;
	node(){next=NULL;}
};
void reverseLR(node *head,int m, int n){
	node *pre=NULL,*p=head,*q=NULL,*last=NULL;
	
	for(int i=0;i<m-2;i++){
		p=p->next;
	}
	pre=p;//保存L之前的节点
	p=p->next;//第L个节点
	q=p->next;
	last=p;
	for(int i=0;i<n-m;i++){
		pre->next=q;
		q=q->next;
		pre->next->next=p;
		p=pre->next;
	}
	last->next=q;
	
	while(head){
		printf("%d ",head->val);
		head=head->next;
	}
	return ;
}

int main()
{
	int n,l,r,v;
	cin>>n>>l>>r;
	node *head=new node(),*p=head;
	for(int i=1;i<=n;i++){
		cin>>v;
		p->val=v;
		if(i!=n){
			p->next=new node;
			p=p->next;
		}
	}
	reverseLR(head,l,r);
	

	
	return 0;
}

