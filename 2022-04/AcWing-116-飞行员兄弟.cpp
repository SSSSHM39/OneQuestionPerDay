#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

const int N = 5;
char g[N][N], backup[N][N];

#define x first
#define y second
typedef pair<int, int> PII;

int get(int i, int j)
{
    return 4 * i + j;
}

void turn_one(int x, int y)
{
    if (g[x][y] == '+')
        g[x][y] = '-';
    else
        g[x][y] = '+';
}

void turn_all(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        turn_one(i, y);
        turn_one(x, i);
    }
    turn_one(x, y);
}

int main()
{
    for (int i = 0; i < 4; i++)
        cin >> g[i];
    vector<PII> res;
    for (int op = 0; op < 1 << 16; op++)
    {
        vector<PII> temp;
        memcpy(backup, g, sizeof g); //备份
        //进行操作
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if (op >> get(i, j) & 1)
                {
                    temp.push_back({i, j});
                    turn_all(i, j);
                }
        //判断
        bool all_open = true;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if (g[i][j] == '+')
                {
                    all_open = false;
                    break;
                }
        if (all_open == true)
            if (res.empty() || temp.size() < res.size())
                res = temp;
        memcpy(g, backup, sizeof g); //还原
    }
    cout << res.size() << endl;
    for (auto i : res)
        cout << i.x + 1 << ' ' << i.y + 1 << endl;
    return 0;
}

// 2022-04-28
// 原题链接：https://www.acwing.com/problem/content/118/
// 枚举 位运算