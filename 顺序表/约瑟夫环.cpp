#include<bits/stdc++.h>
using namespace std;//考察双向链表,这玩意只可意会不可言传,链表是数据结构难点之一吧 
const int N=1e3+10;//不过单向链表也可以完成 
typedef struct st{
	int data;
	struct st *next,*pre;
}*link,ll;
int n,k;
void create(link &L)
{//建立双向链表 
	link head,q,p;
	L=new ll;//头结点(该结点只为简化建表过程) 
	p=L;
	for(int i=1;i<=n;i++)
	{//后插建立双向链表 
		q=new ll;
		q->data=i;
		q->next=NULL;
		p->next=q;
		q->pre=p;
		p=q;
	}
	//首尾连接，形成环路(双向循环链表) 
	q->next=L->next;
	L->next->pre=q;
	
	head=L->next;
	int m=0;
	int x=n,s=1;
	while(1)
	{
		if(x==1)
			break;
		if(s==k)//删除结点	 
		{
			link d=head;
			head->pre->next=head->next;
			head->next->pre=head->pre;
			//cout<<head->data<<" ";
			head=head->next;
			delete d;
			s=1;
			x--;
		}
		else
		{
			head=head->next;
			s++;
		}
	}
	cout<<head->data<<endl;//剩下唯一的一个结点
}
int main()
{
	link L=NULL;
	cin>>n>>k;
	create(L);
	return 0;
}

