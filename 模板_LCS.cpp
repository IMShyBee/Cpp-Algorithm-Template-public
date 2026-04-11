//p1439 LCS 最长公共子序列
/*
题目描述
给出 1,2,…,n 的两个排列P1和P2，
求它们的最长公共子序列。

输入格式
第一行是一个数 n。
接下来两行，每行为 n 个数，
为自然数 1,2,…,n 的一个排列。

输出格式
一个数，即最长公共子序列的长度。
*/


//总结：LCS想要时间优化，只能用映射转化成LIS问题，然后求最长上升/不上升/下降/不下降子序列即可  用贪心加二分可以优化到nlogn复杂度
#include<iostream>
using namespace std;

int n;
const int N = 1e5 +5;
int dp[N];
int p1[N];
int p2[N];


int main()
{
    cin >> n;
    int num;
    //把p1序列与1.2.3...n序列形成映射，这样p1就可以看成1-n递增的序列，然后转化为lis问题即可
    for(int i = 1; i <= n; i++)
    {
        cin >> num;
        p1[num] = i;
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> num;
        p2[i] = p1[num];//按规则映射
    }
    int len = 0;
    for(int i = 1; i <= n; i++)
    {

        //--------------------------套用LIS模板---------------------------------------
        if(p2[i] > dp[len])
        {
            len++;
            dp[len] = p2[i];
        }
        else
        {
            int l = 1;
            int r = len;
            while(l < r)
            {
                int mid = (l + r) / 2;
                if(dp[mid] >= p2[i]) r = mid;//因为要插入恰好大于的那个数的右边 即mid的右边 l=mid+1 所以需要的下标是l
                else l = mid + 1; 
            }
            dp[l] = p2[i];
        }
        //--------------------------套用LIS模板---------------------------------------
    }
    cout << len;
    return 0;
}







//int dp[2][N];
//int main()
// {
//     cin >> n;
//     for(int i = 1; i <= n; i++) cin >> p1[i];
//     for(int i = 1; i <= n; i++) cin >> p2[i];
    
//     //用flag空间优化
//     int flag = 1;
//     for(int i = 1; i <= n; i++)
//     {
//         flag = !flag;
//         for(int j = 1; j <= n; j++)
//         {
//             if(p1[i] == p2[j])
//             {
//                 dp[flag][j] = dp[!flag][j-1] + 1;
//             }
//             else
//             {
//                 dp[flag][j] = max(dp[!flag][j],dp[flag][j-1]);
//             }
//         }
//     }
//     cout << dp[flag][n];
//     return 0;
// } 