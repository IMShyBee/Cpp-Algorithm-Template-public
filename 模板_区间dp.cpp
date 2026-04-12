//洛谷p1880 区间dp
/*
题目描述
在一个圆形操场的四周摆放 N 堆石子，现要将石子有次序地合并成一堆，
规定每次只能选相邻的 2 堆合并成新的一堆，并将新的一堆的石子数，记为该次合并的得分。

试设计出一个算法，计算出将 N 堆石子合并成 1 堆的最小得分和最大得分。

输入格式
数据的第 1 行是正整数 N，表示有 N 堆石子。

第 2 行有 N 个整数，第 i 个整数 ai
表示第 i 堆石子的个数。

输出格式
输出共 2 行，第 1 行为最小得分，第 2 行为最大得分。

说明/提示
1≤N≤100，0≤ai≤20。
*/
#include<iostream>
#include<cstring>
using namespace std;

int n;
const int N = 205;//需要注意的是  此题为圆环  所以实际上的N是原本的两倍（n在循环时同理）
int a[N];
int pre[N];
//dp[i][j] 表示从第i堆到第j堆合并为一堆的最小（大）代价
int dp_min[N][N];
int dp_max[N][N];

int main()
{
    cin >> n;
    memset(dp_min, 0x3f3f3f3f,sizeof(dp_min));
    //注意定义完无穷大后要把单个堆的合并得分清零，不然再计算两个堆合并时用到一个堆的零得分就会变成无穷大从而出错
    for(int i = 1; i <= 2*n; i++)
        dp_min[i][i] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i+n] = a[i];
    }
    for(int i = 1; i <= 2*n; i++)
        pre[i] = pre[i-1] + a[i];

    //区间dp
    for(int len = 2; len <= n; len++)//表示合并的区间长度
        for(int i = 1; i + len -1 <= 2 * n; i++)//i表示从第几个堆开始合并
        {
            int j = i + len - 1;//j表示合并到第几个堆
            for(int k = i; k < j; k++)//循环k，表示区间中的区间dp最优解
            {
                //最优解就是之前情况下的最优解，和现在这种合并法的最优解  的最优
                //dp_min[i][j]就是从i-j的之前的合并方法最优    把他和 i-k和k+1到j的两堆的合并情况的得分对比  取最优
                dp_min[i][j] = min(dp_min[i][j],dp_min[i][k]+dp_min[k+1][j]+pre[j] - pre[i-1]);
                dp_max[i][j] = max(dp_max[i][j],dp_max[i][k]+dp_max[k+1][j]+pre[j] - pre[i-1]);
            }
        }

    int ans_min = 0x3f3f3f3f;
    int ans_max = 0;
    //尤其要注意，此题为环，需要看一个n长度中的最优得分
    for(int i = 1; i <= 2*n; i++)
    {
        ans_min = min(ans_min, dp_min[i][i+n-1]);
        ans_max = max(ans_max, dp_max[i][i+n-1]);
    }
    cout << ans_min << endl;
    cout << ans_max << endl;

    return 0;
}