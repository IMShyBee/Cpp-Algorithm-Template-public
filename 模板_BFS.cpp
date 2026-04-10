//P1443 BFS
/*
题目描述
有一个 n×m 的棋盘，
在某个点 (x,y) 上有一个马，
要求你计算出马到达棋盘上任意一个点最少要走几步。

输入格式
输入只有一行四个整数，分别为 n,m,x,y。

输出格式
一个 n×m 的矩阵，
代表马到达某个点最少要走几步（不能到达则输出 −1）。

说明/提示
数据规模与约定
对于全部的测试点，保证 1≤x≤n≤400，1≤y≤m≤400。
*/

#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int n, m, x, y;

int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

const int N = 505;
int step[N][N];
bool board[N][N];//定义的全局数组自动初始化为全0，0表示未被访问过

queue<pair<int, int>> q;

int main()
{
    cin >> n >> m >> x >> y;
    memset(step, -1, sizeof(step));
    q.push(pair<int, int>(x,y));
    board[q.front().first][q.front().second] = 1; 
    step[x][y] = 0;
    while(!q.empty())
    {
        //取出这一个节点的数据，并弹出
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();
        //对于这一个节点，把与之相连的所有没有访问的合法节点都加入
        for(int i = 0; i < 8; i++)
        {
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && !board[nx][ny])
            {
                board[nx][ny] = 1;
                step[nx][ny] = step[xx][yy] + 1;//子节点的步数等于父节点加一
                q.push({nx,ny});//入队
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cout << step[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}