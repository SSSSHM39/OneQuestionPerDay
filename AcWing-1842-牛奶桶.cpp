#include <iostream>
using namespace std;
int main()
{
    int x, y, m;
    cin >> x >> y >> m;
    int res = 0;
    for (int i = 0; i <= m / x; i++)
    {
        int j = (m - i * x) / y;
        res = max(res, i * x + j * y);
    }
    cout << res << endl;
    return 0;
}

void way2()
{
    int x, y, m;
    cin >> x >> y >> m;
    int res = m; //求M的桶中的最大牛奶量 => 求M桶种最小的剩余量
    for (int i = 0; i <= m / x; i++)
        res = min(res, (m - i * x) % y); //剩余量 = (m - x桶已装) % y
    cout << m - res << endl;
}

// 2022-04-28
// 原题链接：https://www.acwing.com/problem/content/1844/
// 枚举