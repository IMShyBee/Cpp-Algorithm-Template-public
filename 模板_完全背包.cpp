/*
LiYuxiang 是个天资聪颖的孩子，他的梦想是成为世界上最伟大的医师。为此，他想拜附近最有威望的医师为师。医师为了判断他的资质，给他出了一个难题。医师把他带到一个到处都是草药的山洞里对他说：“孩子，这个山洞里有一些不同种类的草药，采每一种都需要一些时间，每一种也有它自身的价值。我会给你一段时间，在这段时间里，你可以采到一些草药。如果你是一个聪明的孩子，你应该可以让采到的草药的总价值最大。”

如果你是 LiYuxiang，你能完成这个任务吗？

此题和原题的不同点：

1. 每种草药可以无限制地疯狂采摘。

2. 药的种类眼花缭乱，采药时间好长好长啊！师傅等得菊花都谢了！

输入格式
输入第一行有两个整数，分别代表总共能够用来采药的时间t和代表山洞里的草药的数目 m。

第2到第(m+1)行，每行两个整数，第 (i+1) 行的整数 ai,bi分别表示采摘第 i 种草药的时间和该草药的价值。

说明/提示
数据规模与约定
对于 30% 的数据，保证 m≤1e3。
对于 100% 的数据，保证 1≤m≤1e4,1≤t≤1e7,且1≤m×t≤1e7,1≤ai,bi≤1e4。

*/



#include<iostream>
using namespace std;
typedef long long ll;

ll t;//时间（即背包容量）
int m;//草药数目（即物品数目）
const int N = 1e4 + 5;
const ll T = 1e7 + 5;
int cost[N];//不能用time 会和std::time 冲突
int value[N];
ll dp[T]; // 数据量大要用ll

int main()
{
    cin >> t >> m;
    for(int i = 1; i <= m; i++) cin >> cost[i] >> value[i];

    for(int i = 1; i <= m; i++)
    {
        for(int j = cost[i]; j <= t; j++)
        {
            dp[j] = max(dp[j],dp[j-cost[i]]+value[i]);
        }
    }
    cout << dp[t];

    return 0;
}





/*
p2842
题目描述
某国有 n 种纸币，
每种纸币面额为ai并且有无限张，
现在要凑出 w 的金额，
试问最少用多少张纸币可以凑出来？
（保证可以凑出对应金额）

输入格式
第一行两个整数 n,w，分别表示纸币的种数和要凑出的金额。
第二行一行 n 个以空格隔开的整数a1,a2,a3,…an
依次表示这 n 种纸币的面额

输出格式
一行一个整数，表示最少使用的纸币张数。
#include<iostream>
#include<cstring>
using namespace std;

int n, w;
const int N = 1e3+5;
const int W = 1e4+5;
int a[N];
int dp[W];//最少要dp[i]张才能凑出金额i

int main()
{
    cin >> n >> w;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    memset(dp,0x3f,sizeof(dp));
    dp[0] = 0;

    //for (每种纸币 i)
    //for (j 从 a[i] 到 w)
    //    dp[j] = min(dp[j], dp[j - a[i]] + 1);

    for(int i = 1; i <= n; i++)//对于前i张纸币
    {
        for(int j = a[i]; j <= w; j++)
        {
            dp[j] = min(dp[j], dp[j-a[i]] + 1);
        }
    }
    cout << dp[w];
    return 0;
}

题目描述
你有 n 种面额互不相同的纸币，第 i 种纸币的面额为ai
​并且有无限张，现在你需要支付 w 的金额，
求问有多少种方式可以支付面额 w，答案对 1e9+7 取模。
注意在这里，同样的纸币组合如果支付顺序不同，
会被视作不同的方式。
例如支付 3 元，
使用一张面值 1 的纸币和一张面值 2 的纸币
会产生两种方式（1+2 和 2+1）。

输入格式
第一行两个正整数 n,w，分别表示纸币的种数和要凑出的金额。
第二行一行 n 个以空格隔开的正整数a1,a2,…an依次表示这 n 种纸币的面额。

输出格式
一行一个整数，表示支付方式的数量。

其实本题就是遍历的顺序不同  从而使原本的结果从组合变成了排列
不过，注意状态转移方程也有所不同

#include<iostream>
using namespace std;

int n, w;
const int N = 1e3 + 5;
const int W = 1e4 + 5;
int a[N];
int dp[W];
const int mod = 1e9 + 7;

int main()
{
    cin >> n >> w;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    dp[0] = 1;
    for(int i = 1; i <= w; i++)
    {
    //对于每个面额的纸币都进行遍历，
    //每次金额增加，都是一次完全的遍历，
    //这样最后求出来的就是排列，也就是所有方案数
        for(int j = 1; j <= n; j++)
        {
            //不过，注意状态转移方程也有所不同
            if(i >= a[j])
            dp[i] = (dp[i] + dp[i-a[j]]) % mod;
        }
    }

    cout << dp[w] % mod;
    return 0;
}
*/