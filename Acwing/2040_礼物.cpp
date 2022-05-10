#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1010;
struct obj
{
    int p, s;
    bool operator<(const obj &t)
    {
        return p + s < t.p + t.s;
    }
} a[N];
int n, b;
int main()
{
    cin >> n >> b;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].p >> a[i].s;
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) // 遍历，依次对每件礼物使用半折券
    {
        int temp = b, count = 0;
        if (temp >= a[i].p / 2 + a[i].s)
        {
            temp -= a[i].p / 2 + a[i].s;
            count++;
        }
        for (int j = 0; j < n; j++) // 在使用完半折券后再增加其他商品，直至预算用完
            if (j != i && temp >= a[j].p + a[j].s)
            {
                temp -= a[j].p + a[j].s;
                count++;
            }
        res = max(res, count);
    }
    cout << res << endl;
    return 0;
}

// 2022-05-02
// https://www.acwing.com/problem/content/2042/
//