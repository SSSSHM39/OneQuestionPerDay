#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 210, INF = 1e8;
struct mirror //存放镜子的位置&朝向
{
    int x, y;
    char c;
} q[N];
int n;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0}; //方向偏移量，确定位移方向

void turn(char &c) //翻转镜子
{
    if (c == '/')
        c = '\\';
    else
        c = '/';
}

bool check() //判断是否能到达终点
{
    int d = 1, k = 0;                     // d记录位移方向，k记录当前位置
    for (int i = 0; i < (n + 1) * 2; i++) //遍历，如果每一块镜子的两面都走过一次，那么无法到达
    {
        int id = -1, len = INF;          // -1：初始位置，len防止位移量超出边界
        for (int j = 1; j <= n + 1; j++) //遍历是否能到达下一块镜子
        {
            if (j == k) //跳过自己
                continue;
            if (q[k].x + abs(q[k].x - q[j].x) * dx[d] != q[j].x) //跳过不在同一x线上的镜子
                continue;
            if (q[k].y + abs(q[k].y - q[j].y) * dy[d] != q[j].y) //跳过不在同一y线上的镜子
                continue;

            int t = abs(q[k].x - q[j].x) + abs(q[k].y - q[j].y);
            if (t < len)
                len = t, id = j;
        }
        if (id == -1) //如果位置未发生改变则false
            return false;
        if (id == n + 1) //如果到达的点即终点则true
            return true;
        k = id;             //走到下一块镜子
        if (q[id].c == '/') //根据镜子朝向改变位移方向
            d ^= 1;
        else
            d ^= 3;
    }
    return false; //如果遍历完所有的镜子还未到达终点则false
}

int main()
{
    cin >> n;
    cin >> q[n + 1].x >> q[n + 1].y; //用n+1存放终点位置
    for (int i = 1; i <= n; i++)
        cin >> q[i].x >> q[i].y >> q[i].c;
    if (check()) //判断是否不需要翻转镜子即可到达终点
        puts("0");
    else
    {
        for (int i = 1; i <= n; i++) //枚举翻转每一块镜子
        {
            turn(q[i].c);
            if (check())
            {
                cout << i << endl;
                return 0;
            }
            turn(q[i].c); //恢复现场
        }
        puts("-1");
    }
    return 0;
}

// 2022-04-29
// 原题链接：https://www.acwing.com/problem/content/1988/
// 枚举 模拟