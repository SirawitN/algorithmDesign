#include <iostream>
#include <vector>

using namespace std;

int mssKadane(vector<int> &V)
{
    int N = V.size(), suffix = V[0], mss = V[0];
    for (int i = 1; i < N; i++)
    {
        suffix = max(suffix + V[i], V[i]);
        mss = max(mss, suffix);
    }
    return mss;
}

void pushElement(vector<vector<int>> &A, vector<vector<int>> &diagEl, int r, int c, int N)
{
    vector<int> tmp;
    while (r < N && c < N)
    {
        tmp.push_back(A[r++][c++]);
    }
    diagEl.push_back(tmp);
}

void printVect(vector<vector<int>> &V)
{
    for (vector<int> &v : V)
    {
        for (int &i : v)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int N, n, maxDiagSum;
    vector<vector<int>> A, diagEl;
    cin >> N;

    A.resize(N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> n;
            A[i].push_back(n);
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (i == 0)
        {
            for (int j = 0; j < N; j++)
            {
                pushElement(A, diagEl, i, j, N);
            }
        }
        else
        {
            pushElement(A, diagEl, i, 0, N);
        }
    } // แยกแต่ละ element ออกตามแนวทแยงมุม

    printVect(diagEl);

    for (int i = 0; i < diagEl.size(); i++)
    {
        maxDiagSum = (i == 0) ? mssKadane(diagEl[0]) : max(maxDiagSum, mssKadane(diagEl[i]));
    }
    cout << maxDiagSum;
}