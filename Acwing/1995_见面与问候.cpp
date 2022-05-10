#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1000010;
int n, m;
int a[N], b[N]; // 记录每一单位时间的位置

int main()
{
    scanf("%d%d", &n, &m);
    int t = 0;
    while (n--)
    {
        int l;
        char c;
        scanf("%d %c", &l, &c);
        int v = 1;
        if (c == 'L')
            v = -1;
        while (l--)
        {
            t++;
            a[t] = a[t - 1] + v;
        }
    }
    while (++t < N) // 走完后会停留在原地
        a[t] = a[t - 1];

    t = 0;
    while (m--)
    {
        int l;
        char c;
        scanf("%d %c", &l, &c);
        int v = 1;
        if (c == 'L')
            v = -1;
        while (l--)
        {
            t++;
            b[t] = b[t - 1] + v;
        }
    }
    while (++t < N) // 走完后会停留在原地
        b[t] = b[t - 1];
    int res = 0;
    for (int i = 1; i < N; i++)
        if (a[i] == b[i] && a[i - 1] != b[i - 1])
            res++;
    cout << res << endl;
    return 0;
}

// 2022-05-04
// https://www.acwing.com/problem/content/1997/
// 模拟