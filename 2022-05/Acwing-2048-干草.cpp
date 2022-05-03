#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 10010;
int a[N];
int n;
int main()
{
    int sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    int avg = sum / n;
    int res = 0;
    for (int i = 0; i < n; i++)
        res += abs(a[i] - avg);
    cout << res / 2 << endl; // 移入移出1份甘草会记录2次
    return 0;
}

// 2022-05-02
// https://www.acwing.com/problem/content/2050/
//
// 怎么这么水（）