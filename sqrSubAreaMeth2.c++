#include <iostream>
#include <math.h>
#include <vector>

using namespace std;
vector<vector<int>> prefixTab, A;

void prefixCal(int R, int C)
{
    prefixTab[0][0] = A[0][0];
    for (int j = 1; j < C; j++)
    {
        prefixTab[0][j] = prefixTab[0][j - 1] + A[0][j];
    }

    for (int i = 1; i < R; i++)
    {
        prefixTab[i][0] = prefixTab[i - 1][0] + A[i][0];
        for (int j = 1; j < C; j++)
        {
            prefixTab[i][j] = prefixTab[i - 1][j] + prefixTab[i][j - 1] - prefixTab[i - 1][j - 1] + A[i][j];
        }
    }
} // pre-calculate all prefix sums.

void printTable(vector<vector<int>> &T)
{
    for (vector<int> &V : T)
    {
        for (int &v : V)
        {
            cout << v << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int R, C, K, S, p1, p2, p3, p4;
    char q;
    cin >> R >> C;
    K = min(R, C);

    A.resize(R);
    prefixTab.resize(R, vector<int>(C));
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> q;
            A[i].push_back((int)q - 48); //ascii code ของตัวเลขเริ่มที่ 48 (ของ 0)
        }
    }

    prefixCal(R, C);
    //printTable(prefixTab);

    bool found = false;
    while (K != 1 && !found)
    {
        S = pow(K, 2);
        for (int r = 0; r < R && r + K - 1 < R && !found; r++)
        {
            for (int c = 0; c < C && c + K - 1 < C && !found; c++)
            {
                p1 = prefixTab[r + K - 1][c + K - 1];
                p2 = (r - 1 < 0) ? 0 : prefixTab[r - 1][c + K - 1];
                p3 = (c - 1 < 0) ? 0 : prefixTab[r + K - 1][c - 1];
                p4 = (c - 1 < 0 || r - 1 < 0) ? 0 : prefixTab[r - 1][c - 1];
                found = (p1 - p2 - p3 + p4 == S);
            }
        }
        if (!found)
            K--;
    }

    cout << K;

    return 0;
}

/*
ที่มาสูตรการคำนวณจากข้อ quick sum

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
