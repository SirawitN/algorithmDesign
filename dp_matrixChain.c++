#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> table;

void print_table()
{
    for (vector<int> &V : table)
    {
        for (int &v : V)
            cout << v << " ";
        cout << "\n";
    }
}

int mcc(vector<int> &A, int start, int stop)
{
    if (start >= stop)
        return 0;
    if (table[start][stop] != -1)
        return table[start][stop];
    int myCost, minCost = INT32_MAX;

    for (int i = start; i < stop; i++)
    {
        myCost = mcc(A, start, i) + mcc(A, i + 1, stop) + A[start] * A[i + 1] * A[stop + 1];
        minCost = min(myCost, minCost);
    }
    table[start][stop] = minCost;
    return table[start][stop];
}

int mcc_bt(vector<int> &A)
{
    int n = A.size();
    vector<vector<int>> tab(n, vector<int>(n, 0));
    int myCost, minCost, j;

    for (int g = 1; g < n; g++)
    {
        for (int i = 0; i < n - g; i++)
        {
            minCost = INT32_MAX;
            j = i + g;
            for (int k = i; k < j; k++) // <<------------------------
            {
                myCost = tab[i][k] + tab[k + 1][j] + A[i] * A[k + 1] * A[j + 1];
                minCost = min(minCost, myCost);
            }
            tab[i][j] = minCost;
        }
    }
    return tab[0][n - 2];
}

int main()
{
    int n, q;
    vector<int> A;
    cin >> n;

    table.resize(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
    {
        cin >> q;
        A.push_back(q);
    }

    cout << mcc(A, 0, n - 2) << " " << mcc_bt(A);
}

/*

4
10 10 10 1
ans = 200

6
10 5 1 5 10 2
ans = 140

*/