#include <iostream>
using namespace std;

const int N = 50010;
char a[N];
int l[N], r[N];

int main()
{
    int left = 0, right = 0;
    cin >> a;
    for (int i = 0; a[i]; i++)
    {
        if (a[i] == a[i + 1] && a[i] == '(')
            l[left++] = i; //记录左腿出现位置
        if (a[i] == a[i + 1] && a[i] == ')')
            r[right++] = i; //记录右腿出现位置
    }
    int res = 0;
    for (int i = 0; i < left; i++)
        for (int j = 0; j < right; j++) //找到最短的牛
            if (l[i] < r[j])
            {
                res += right - j;
                break;
            }
    cout << res << endl;
    return 0;
}

// 2022.04.25
//原题链接 : https://www.acwing.com/problem/content/description/2005/
//枚举