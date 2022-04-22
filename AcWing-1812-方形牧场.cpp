#include <iostream>
using namespace std;
#define x first
#define y second
typedef pair<int, int> P; //存放点坐标

P a[4];

int main()
{
    for (int i = 0; i < 4; i++)
        cin >> a[i].x >> a[i].y;
    int l = abs(max(a[1].x, a[3].x) - min(a[0].x, a[2].x)); //计算长的最大值
    int d = abs(max(a[1].y, a[3].y) - min(a[0].y, a[2].y)); //计算宽的最大值
    int m = max(l, d);                                      //比较得出正方形边长
    cout << m * m << endl;
    return 0;
}
