#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 6;
char g[N][N], backup[N][N];                             //记录开光状态，backup做备份
int dx[5] = {-1, 0, 1, 0, 0}, dy[5] = {0, 1, 0, -1, 0}; //位移
void turn(int x, int y)                                 //改变开关状态
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
        for (int i = 0; i < 5; i++) //输入开关状态
            cin >> g[i];
        int res = 7;                 //记录改变次数，大于6输出-1
        for (int o = 0; o < 32; o++) //改变第一行开关状态，有2^5（32）种改变方式
        {
            memcpy(backup, g, sizeof g); //拷贝备份
            int step = 0;                //记录真实改变次数
            for (int i = 0; i < 5; i++)
                if (o >> i & 1) //通过二进制位运算来判断是否改变当前开关
                {
                    step++;
                    turn(0, i);
                }

            for (int i = 0; i < 4; i++) //根据上一行的开关状态来判断是否改变当前行开关
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
            for (int i = 0; i < 5; i++) //根据题目性质，只需判断最后一行开关是否全亮即可判断所有开关
            {
                if (g[4][i] == '0')
                {
                    dark = true;
                    break;
                }
            }
            if (!dark)
                res = min(step, res);
            memcpy(g, backup, sizeof g); //恢复现场
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