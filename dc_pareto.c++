#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int, int>> A;

int pareto(int idx, int Y)
{
    if (idx == -1)
        return 0; // out of index : no point left to check

    pair<int, int> p = A[idx];
    if (p.second > Y)
        return 1 + pareto(idx - 1, p.second);
    return 0 + pareto(idx - 1, Y);
} //big theta N

int main()
{
    int N, x, y;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        A.push_back(make_pair(x, y));
    }
    sort(A.begin(), A.end());

    cout << 1 + pareto(N - 2, A[N - 1].second);
    return 0;
}