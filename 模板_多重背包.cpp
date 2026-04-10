/*

题目描述
终于，破解了千年的难题。小 FF 找到了王室的宝物室，里面堆满了无数价值连城的宝物。
这下小 FF 可发财了，嘎嘎。但是这里的宝物实在是太多了，小 FF 的采集车似乎装不下那么多宝物。看来小 FF 只能含泪舍弃其中的一部分宝物了。
小 FF 对洞穴里的宝物进行了整理，他发现每样宝物都有一件或者多件。他粗略估算了下每样宝物的价值，之后开始了宝物筛选工作：

小 FF 有一个最大载重为 W 的采集车，
洞穴里总共有 n 种宝物，
每种宝物的价值为vi,重量为wi,每种宝物有mi件。

小 FF 希望在采集车不超载的前提下，选择一些宝物装进采集车，使得它们的价值和最大。
输入格式
第一行为两个整数 n 和 W，分别表示宝物种数和采集车的最大载重。
接下来 n 行每行三个整数vi,wi,mi.

输出格式
输出仅一个整数，表示在采集车不超载的情况下收集的宝物的最大价值。



说明/提示

对于 100% 的数据，1≤mi，∑mi≤1e5
 ，0≤W≤4×1e4，1≤n≤100，1≤wi，vi≤1000。
*/


#include<iostream>
using namespace std;

int n, m;//n表示物品数量 m表示背包容量
const int N = 105;
const int M = 4 * 1e4 + 5;
//未优化的全局变量
// int value[N];//每种物品的单件价值
// int weight[N];//每种物品的单件质量
// int num[N];//每种物品的数量

//二进制优化的全局变量定义
const int NEW_N = 1e4 + 5;
int value[NEW_N];
int weight[NEW_N];
int num[NEW_N];
int dp[M];




int main()
{
    cin >> n >> m;
    // for(int i = 1; i <= n; i++) cin >> value[i] >> weight[i] >> num[i];

    // for(int i = 1; i <= n; i++)
    // {
    //     for(int j = 1; j <= num[i]; j++)
    //     {
    //         for(int k = m; k >= weight[i]; k--)//注意是递减
    //         {
    //             dp[k] = max(dp[k],dp[k-weight[i]]+value[i]);
    //         }
    //     }
    // }
    // cout << dp[m];



    //以下是二进制优化减小时间复杂度
    int pos = 0;//控制插入位置，顺便统计处理后的物品的数量
    int vi,wi,mi;//分别存储价值，重量，数量
    for(int i = 1; i <= n; i++)
    {
        int k = 1;//用来用作二进制的权重
        cin >> vi >> wi >> mi;
        while(mi >= k)
        {
            //把k个物品捆绑起来当作一个物品
            pos++;
            value[pos] = vi * k;
            weight[pos] = wi * k;
            mi -= k;
            k *= 2;
        }
        // 如果剩下的物品有且不足以捆成k个 就捆成一捆
        if(mi)
        {
            pos++;
            value[pos] = vi * mi;
            weight[pos] = wi * mi; 
        }
    }

    //处理完毕，接下来就是01背包问题
    for(int i = 1; i <= pos; i++)
    {
        for(int j = m; j >= weight[i]; j--) //注意是递减
        {
            dp[j] = max(dp[j],dp[j-weight[i]]+value[i]);
        }
    }


    cout << dp[m];
    return 0;
}