//P1219 DFS标杆题 多条件剪枝
/*
八皇后问题
题目描述
一个如下的 6×6 的跳棋棋盘，
有六个棋子被放置在棋盘上，
使得每行、每列有且只有一个，
每条对角线（包括两条主对角线的所有平行线）
上至多有一个棋子。

第 i 个数字表示在第 i 行的相应位置有一个棋子，如下：

行号 1 2 3 4 5 6

列号 2 4 6 1 3 5

这只是棋子放置的一个解。请编一个程序找出所有棋子放置的解。
并把它们以上面的序列方法输出，解按字典顺序排列。
请输出前 3 个解。最后一行是解的总个数。

输入格式
一行一个正整数 n，表示棋盘是 n×n 大小的。

输出格式
前三行为前三个解，
每个解的两个数字之间用一个空格隔开。
第四行只有一个数字，表示解的总数。

说明/提示
【数据范围】
对于 100% 的数据，6≤n≤13。
*/

#include<iostream>
using namespace std;

const int N = 14;
int ans[N];//放在每下标行的第几个位置

//check数组用来判断这个格子能不能放，
//0行表示第几列，1行表示向左的斜线，2表示向右的斜线
//（因为不难发现，对于每条斜线，
//向左下的斜线横纵坐标之和为定值，向右下的斜线横纵坐标之差为定值）
//当然也可以直接用N*N的数组
int check[3][2*N];//注意要是2*N 因为后面又统计斜线的时候要用到

int cnt = 0;//统计总的方案个数

int n;//要放的皇后个数

void dfs(int line)
{
    if(line > n)
    {
        cnt++;
        if(cnt>3) return;
        for(int i = 1; i <= n; i++)
        {
            cout << ans[i] << ' ';
        }
        cout << endl;
        return;
    }
    for(int i = 1; i <= n; i++)
    {
        if(!check[0][i] && !check[1][line+i] && !check[2][line-i+n])
        {
            ans[line] = i;//标记为放了皇后的
            check[0][i] = 1;//标记为不能放皇后的
            check[1][line+i] = 1;
            check[2][line-i+n] = 1;//加n防止负数
            dfs(line+1);
            //回溯
            ans[line] = 0;
            check[0][i] = 0;
            check[1][line+i] = 0;
            check[2][line-i+n] = 0;
        }
    }
    return;

}

int main()
{
    cin >> n;
    dfs(1);
    cout << cnt;

    return 0;
}