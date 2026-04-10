//最长回文子序列
//其实就是求正反串的最长公共子序列
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

const int N = 1005;
int dp[N][N];
map<char, int> mp;
int a[N];
char c;
int n = 0;
int rk = 0;

int main()
{
    while (cin >> c)
    {
        if (mp.find(c) == mp.end())
        {
            mp[c] = rk++;
        }
        a[n++] = mp[c];
    }
    // 也就是原串 和 逆串 的 LCS
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i-1] == a[n - j])   // 对应逆序
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout <<dp[n][n];
}