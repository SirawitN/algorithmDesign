// Matrix Chain Multiplication
#include <iostream>
#include <vector>

using namespace std;
vector<int> A;
vector<vector<int>> table;

void print_table()
{
    for (vector<int> &v : table)
    {
        for (int &i : v)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
}

// ---------------------  Top-down  -----------------------

int mcc(int l, int r)
{
    if (l >= r)
        return 0;          // multiplication cost of a matrix = 0
    if (table[l][r] != -1) // looking up on the table
        return table[l][r];

    int min_cost = INT32_MAX, my_cost;

    for (int i = l; i < r; i++)
    {
        my_cost = mcc(l, i) + mcc(i + 1, r) + A[l] * A[i + 1] * A[r + 1];
        min_cost = min(min_cost, my_cost);
    }

    return min_cost;
}

//  --------------------- Bottom-up  ---------------------------

int mcc_bu(int N)
{
    table.clear();
    table.resize(N, vector<int>(N, 0));
    //for(int i=0;i <= N;i++) table[i][i] = 0;

    int j, min_cost, my_cost;
    for (int g = 1; g < N; g++)
    {
        for (int i = 0; i <= N - g; i++)
        {
            j = i + g;
            min_cost = INT32_MAX;
            for (int k = i; k < j; k++)
            {
                my_cost = table[i][k] + table[k + 1][j] + A[i] * A[k + 1] * A[j + 1];
                min_cost = min(min_cost, my_cost);
            }
            table[i][j] = min_cost;
        }
    }

    return table[0][N - 1];
}

int main()
{
    int N, q;
    cin >> N;

    table.resize(N, vector<int>(N, -1));
    for (int i = 0; i < N; i++)
    {
        cin >> q;
        A.push_back(q);
    }

    cout << mcc(0, N - 2) << " " << mcc_bu(N - 1) << "\n";
}