//p1048
#include<iostream>
using namespace std;

int t, m;//m为物品数量 t为重量
const int N = 1005;
const int M = 105;
int a[M][2];//0存储物品重量  1存储物品价值
int dp[M][N];
int dp_1[N];

int main()
{
    cin >> t >> m;
    for(int i = 0; i < m; i++) cin >> a[i+1][0] >> a[i+1][1];
    // for(int i = 1; i <= m; i++)
    // {
    //     for(int j = 1; j <= t; j++)
    //     {
    //         if(j >= a[i][0])
    //         {
    //             dp[i][j] = max(dp[i-1][j],dp[i-1][j-a[i][0]]+a[i][1]);
    //         }
    //         else
    //         {
    //             dp[i][j] = dp[i-1][j];
    //         }
    //     }
    // }
    // cout << dp[m][t];


    //以下为一维滚动数组优化
    for(int i = 1; i <= m; i++)
    {
        for(int j = t; j >= a[i][0]; j--) // 注意必须反向遍历，否则会覆盖上一层未使用的值
        {
            dp_1[j] = max(dp_1[j],dp_1[j-a[i][0]]+a[i][1]);
        }
    }
    cout << dp_1[t];
    return 0;
}