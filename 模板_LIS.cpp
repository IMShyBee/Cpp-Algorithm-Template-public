//p1020 lis模板 最长上升子序列

/*

题目描述
某国为了防御敌国的导弹袭击，发展出一种导弹拦截系统。但是这种导弹拦截系统有一个缺陷：
虽然它的第一发炮弹能够到达任意的高度，但是以后每一发炮弹都不能高于前一发的高度。
某天，雷达捕捉到敌国的导弹来袭。
由于该系统还在试用阶段，所以只有一套系统，因此有可能不能拦截所有的导弹。

输入导弹依次飞来的高度，计算这套系统最多能拦截多少导弹，
如果要拦截所有导弹最少要配备多少套这种导弹拦截系统。

输入格式
一行，若干个整数，中间由空格隔开。

输出格式
两行，每行一个整数，第一个数字表示这套系统最多能拦截多少导弹，
第二个数字表示如果要拦截所有导弹最少要配备多少套这种导弹拦截系统。

*/
#include<iostream>
#include<cstring>//用于初始化元素最大，最长上升时需要
using namespace std;

const int N = 1e5 +5;
int a[N];
int dp[N]; // 本题用以记录最长不上升子序列长度
int longest = 0;//记录最长不上升子序列长度
//本题询问的需要多少个系统其实就是求最长上升子序列的长度
int Quantity[N];//本题用以记录最长上升子序列长度
int max_Quantity = 0;//记录最长上升子序列长度
//以下优化
int down[N];//记录最长不上升子序列
int up[N];//记录最长上升子序列


int main()
{
    
    // int num;
    // int pos = 0;//记录填入位置
    // int tail_pos = 0;//记录尾部数组的位置
    
    //以下为暴力dp 时间复杂度为o(n**2)----------------------------------------
    // while(cin >> num)
    // {
    //     dp[pos] = 1;
    //     Quantity[pos] = 1;
    //     a[pos] = num;
    //     for(int i = 0; i < pos; i++)
    //     {
    //         if(a[pos] <= a[i]) dp[pos] = max(dp[pos],dp[i]+1);
    //         if(a[pos] > a[i]) Quantity[pos] = max(Quantity[pos],Quantity[i]+1);
    //     }
    //     longest = max(longest, dp[pos]);
    //     max_Quantity = max(max_Quantity,Quantity[pos]);
    //     pos++;
    // }
    //    cout << longest << endl;
    //    cout << max_Quantity << endl;


    //以下为优化------------------------------------------------

    int index = 0;
    while(cin >> a[index]) index++;

    // 把数组全部设为 无穷大
    memset(down, 0x3f, sizeof(down));
    
    int len1 = 0;
    int len2 = 0;
    for(int i = 0; i < index; i++)
    {
        //求最长不上升子序列
        if(a[i] <= down[len1])
        {
            len1++;
            down[len1] = a[i];
        }
        else
        {
            int l = 1;
            int r = len1;
            while(l < r)
            {
                int mid = (l + r) / 2;
                if(down[mid] < a[i]) r = mid; /*注意点：最长不上升序列的二分判断这行不等号没有等号
                                                原因：要放到恰大于等于自己的那个数的右边，来构成不上升序列*/
                else l = mid + 1; 
            }
            down[l] = a[i];//因为要插入恰好不大于的那个数的右边，即mid的右边 l=mid+1  所以需要的下标是l
        }
        //求最长上升子序列
        if(a[i] > up[len2])
        {
            len2++;
            up[len2] = a[i];
        }
        else
        {
            int l = 1;
            int r = len2;
            while(l < r)
            {
                int mid = (l + r) / 2;
                if(up[mid] >= a[i]) r = mid;//因为要插入恰好大于的那个数的右边 即mid的右边 l=mid+1 所以需要的下标是l
                else l = mid + 1; 
            }
            up[l] = a[i];
        }
    }

    //看看能不能用algorithm库优化二分查找，lower_bound upper_bound.......


    cout << len1 << endl;
    cout << len2 << endl;

    return 0;
}