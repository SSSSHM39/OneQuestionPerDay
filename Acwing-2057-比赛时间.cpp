#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int d, h, m;

int main()
{
    cin >> d >> h >> m;
    if (d < 11 || d == 11 && h < 11 || d == 11 && h == 11 && m < 11)
        puts("-1");
    else
    {
        int res = 0;
        res = (d - 11) * 24 * 60 + (h - 11) * 60 + (m - 11);
        cout << res << endl;
    }
    return 0;
}

// 2022-05-02
// https://www.acwing.com/problem/content/2059/
//
// 怎么这么水（）