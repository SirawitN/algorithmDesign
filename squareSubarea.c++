#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
vector<vector<int>> table;

bool hasZero(int r, int c, int k)
{
    for (int i = r; i <= r + k - 1; i++)
    {
        for (int j = c; j <= c + k - 1; j++)
        {
            //cout << i << " " << j << " " << table[i][j] << "\n";
            if (table[i][j] == 0)
                return false;
        }
    }
    return true;
}

int main()
{
    int R, C, K;
    char q;
    cin >> R >> C;
    K = min(R, C);

    table.resize(R);
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> q;
            table[i].push_back((int)q - 48);
        }
    }

    bool found = false;
    while (K != 1 && !found)
    {
        for (int r = 0; r < R && r + K - 1 < R && !found; r++)
        {
            for (int c = 0; c < C && c + K - 1 < C && !found; c++)
            {
                found = hasZero(r, c, K);
            }
                }
        if (!found)
            K--;
    }

    cout << K;
}

/*

O(NM) ได้ 60/100

5 5
11111
11111
10011
11100
10110 = 2

10 10
1110101001
0111100111
1000010000
0000101010
1001010110
1010000111
1101110100
0011111100
0111000110
1010011011 = 2
*/