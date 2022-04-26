#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 6;
char g[N][N], backup[N][N];
int dx[5] = {-1, 0, 1, 0, 0}, dy[5] = {0, 1, 0, -1, 0};
void turn(int x, int y)
{
    for (int i = 0; i < 5; i++)
    {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || b < 0 || a > 4 || b > 4)
            continue;
        g[a][b] ^= 1;
    }
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        for (int i = 0; i < 5; i++)
            cin >> g[i];
        int res = 7;
        for (int o = 0; o < 32; o++)
        {
            memcpy(backup, g, sizeof g);
            int step = 0;
            for (int i = 0; i < 5; i++)
                if (o >> i & 1)
                {
                    step++;
                    turn(0, i);
                }

            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (g[i][j] == '0')
                    {
                        step++;
                        if (step >= 7)
                            break;
                        turn(i + 1, j);
                    }
                }
            }
            bool dark = false;
            for (int i = 0; i < 5; i++)
            {
                if (g[4][i] == '0')
                {
                    dark = true;
                    break;
                }
            }
            if (!dark)
                res = min(step, res);
            memcpy(g, backup, sizeof g);
        }
        if (res > 6)
            res = -1;
        cout << res << endl;
    }
    return 0;
}

// 2022.04.26
//原题链接 : https://www.acwing.com/problem/content/97/
//递推 位算法