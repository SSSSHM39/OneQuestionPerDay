#include <iostream>
using namespace std;
int a[3], b[3]; //存放农夫密码&制造商密码
int n;          //拨盘大小

int inRange() //单独计算每种密码的可解锁密码
{
    int res = 1;
    for (int i = 0; i < 3; i++)
        res *= min(n, 5); //如果拨盘小于5，则接近数字范围为拨盘大小的值
    return res;
}

int both() //去重
{
    if (n <= 5)
        return n * n * n; //如果拨盘不大于5，则两组密码的可解锁密码完全重复

    int res = 1;
    for (int i = 0; i < 3; i++)
    {
        int d = abs(a[i] - b[i]); //计算两组密码的各位上的差值
        res *= max(0, 5 - d) + max(0, 5 - (n - d));
        /*
        前者表示直接相接，后者表示头尾相接
        如果差值大于等于5则不会出现重复答案， res * 0 == 0
        */
    }
    return res;
}

int main()
{
    cin >> n;
    for (int i = 0; i < 3; i++)
        cin >> a[i];
    for (int i = 0; i < 3; i++)
        cin >> b[i];

    cout << inRange() * 2 - both() << endl;
    return 0;
}

//原题链接 : https://www.acwing.com/problem/content/description/1353/
//枚举 组合计数 容斥原理