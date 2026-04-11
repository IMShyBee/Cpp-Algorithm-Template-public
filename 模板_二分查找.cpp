//p2249
/*
输入 n 个不超过 1e9的单调不减的
（就是后面的数字不小于前面的数字）
非负整数a1,a2,…,an，
然后进行 m 次询问。对于每次询问，给出一个整数 q，
要求输出这个数字在序列中第一次出现的编号，如果没有找到的话输出 −1 。
输入格式
第一行 2 个整数 n 和 m，表示数字个数和询问次数。
第二行 n 个整数，表示这些待查询的数字。
第三行 m 个整数，表示询问这些数字的编号，从 1 开始编号。

输出格式
输出一行，m 个整数，以空格隔开，表示答案。
*/
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

const int N = 1e6 + 5;
ll a[N];
int n, m;
ll num;

//二分查找
// ll bin(ll x)
// {
//     int l = 1, r = n;
//     while(l < r)
//     {
//         int mid = (l + r) / 2;
//         if(a[mid] >= x) r = mid;
//         else l = mid + 1;
//     }

//     if(a[l] == x) return l;
//     else return -1;
// }


int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++)
    {
        cin >> num;
        // //-------老实写法---------
        // ll l = 1, r = n;//最好就是左右都是闭区间，r = n改成和 r = n + 1也能过 但是可能会出问题
        // while(l < r)
        // {
        //     ll mid = (l + r) / 2;
        //     if(a[mid] < num) l = mid +1;//不能写成  l = mid; 因为现在mid = (l+r)/2 是向下取整，那么就可能出现l 一直等于 mid并且小于r的情况
        //     else r = mid; 
        // }
        // if(a[l] == num) cout << l << ' ';
        // else cout << -1 << ' ';


        //-------模板写法---------
        /*
        用 STL 自带的二分函数——upper_bound和lower_bound。
        这两个函数的作用是二分查找一个数在数组中出现的位置。
        区别是 upper 返回第一个大于搜索数的位置，
        而 lower 是第一个大于等于的数的位置。
        显然这道题用的是 lower
        函数的用法：
        lower_bound(a.begin(),a.end(),x) 
        返回第一个大于等于 x 的数的地址。
        而由于是地址，在最后要 −a（也就是减去地址）。
        */ 
        ll ans = lower_bound(a+1, a+1+n,num) - a;
        if(num != a[ans]) cout << -1 << ' ';
        else cout << ans << ' ';
    }
    return 0;
}