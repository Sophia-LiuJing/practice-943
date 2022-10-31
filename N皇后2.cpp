#include<iostream>
using namespace std;
const int N = 20;
int n;
bool row[N], col[N], dg[N], udg[N];
char g[N][N];
//遍历到(x,y)坐标
void dfs(int x,int y,int p)
{
    //遍历顺序，一行一行遍历
    if(y == n)
    {
        x++;
        y = 0;
    }
    if(x == n)
    {
        if(p == n) {
            for(int i= 0;i < n;i++) puts(g[i]);
            puts("");
        }
        return ;
    }

    //如果不放棋子
    dfs(x,y+1,p);

    //如果放棋子
    if(!row[x] && !col[y] && !dg[x+y] && !udg[x-y+n])
    {
        g[x][y] = 'Q';
        row[x] = col[y] = dg[x+y] = udg[x-y+n] = true;
        dfs(x,y+1,p+1);
        g[x][y] = '.';
        row[x] = col[y] = dg[x+y] = udg[x-y+n] = false;
    }
    

}

int main()
{
    n = 4;
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            g[i][j] = '.';
        }
    printf("%s\n",g[i]);
    }
    dfs(0,0,0);
}
