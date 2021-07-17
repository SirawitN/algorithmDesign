#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> table;

int biCoef(int n, int r)
{
    if (r == 0 || r == n)
        return 1;
    if (table[n][r] != -1)
        return table[n][r];

    table[n][r] = biCoef(n - 1, r) + biCoef(n - 1, r - 1);
    return table[n][r];
}

int biCoef2(int n, int r)
{
    for (int i = 0; i <= n; i++)
    {
        table[i][0] = 1;
        table[i][i] = 1;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i && j <= r; j++)
        {
            table[i][j] = table[i - 1][j] + table[i - 1][j - 1];
        }
    }

    return table[n][r];
}

int main()
{
    int n, r;
    cin >> n >> r;

    table.resize(n + 1, vector<int>(r + 1, -1));
    cout << biCoef(n, r) << " " << biCoef2(n, r);

    return 0;
}