#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
vector<vector<int>> tab;

void recMatrix(int r1, int r2, int c1, int c2, int b)
{
    if (r1 == r2 && c1 == c2)
    {
        tab[r1][c1] = b;
        return;
    }
    int midR = (r1 + r2) / 2, midC = (c1 + c2) / 2;

    recMatrix(r1, midR, c1, midC, b);
    recMatrix(r1, midR, midC + 1, c2, b - 1);
    recMatrix(midR + 1, r2, c1, midC, b + 1);
    recMatrix(midR + 1, r2, midC + 1, c2, b);
}

int main()
{
    int a, b, s;
    cin >> a >> b;

    s = pow(2, a);
    tab.resize(s, vector<int>(s));
    recMatrix(0, s - 1, 0, s - 1, b);

    for (vector<int> &V : tab)
    {
        for (int &i : V)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
}