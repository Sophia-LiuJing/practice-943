#include<iostream>
#include<cstring>
using namespace std;

struct point
{
	int x,y,root;
};
//定义队列
typedef struct queue
{
    point data[100];
    int top=-1;
	
}queue;

//迷宫
int maze[5][5]={
    0,1,0,0,0,
    0,1,0,1,0,
    0,0,0,0,0,
    0,1,1,1,0,
    0,0,0,1,0,
};
queue s;
bool bol[5][5];
int come(int x,int y){
	//判断是否越界
	if(x<0||x>4) return 0;
	if(y<0||y>4) return 0;
	//判断是否可以走
	if(maze[x][y]==1) return 0;
	return 1;
}
void print(){
	for(int i=0;i<=s.top;i++){
		printf("(%d, %d)\n",s.data[i].x,s.data[i].y);
	}
}
void bfs(int x,int y){
	if(bol[x][y]) return ;
	if(x==4&&y==4){
		s.top++;
		s.data[s.top].x=x;
		s.data[s.top].y=y;
		print();
		exit(0);
	}
    if(come(x,y)==1){
		
		s.top++;
		s.data[s.top].x=x;
		s.data[s.top].y=y;
		bol[x][y]=true;
		bfs(x,y+1);
		bfs(x+1,y);
		bfs(x,y-1);
		bfs(x-1,y);
		s.top--;
		bol[x][y]=false;
	}else return ;
	
}

int main(void)
{
    memset(bol,false,sizeof(bol));
    bfs(0,0);
    return 0;
}
