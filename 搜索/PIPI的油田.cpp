#include<iostream>
#include<cstring>
using namespace std;

const int N = 100;
int n,m,ans; 
char s[N][N];
int dx[]={-1,1,0,0,-1,1,-1,1}; //上，下，左，右，左上，右下，右上，左下这八个方向 
int dy[]={0,0,-1,1,-1,1,1,-1};
int x1,y1;

// dfs遍历，不需要回溯 
void dfs(int x,int y){
	s[x][y] = '*';	//走过的格子变为 '*' 
	for(int i=0;i<8;i++){
		x1=x+dx[i],y1=y+dy[i];
		if(x1>=0 && x1<n && y1>=0 && y1<m && s[x1][y1]=='@')
			dfs(x1,y1);
	}
}

int main(){
	while(~scanf("%d %d",&n,&m) && n && m){
		ans = 0;
		for(int i=0;i<n;i++){
			scanf("%s",s[i]);
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(s[i][j]=='@'){
					dfs(i,j);
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

