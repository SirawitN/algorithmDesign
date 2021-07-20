#include <iostream>
#include <vector>

using namespace std;
vector<vector<vector<int>>> table;

int bc(int i, int color_count, int N, int M, int K)
{
    if (color_count > M || K < 0)
        return 0;
    if (i == N)
    {
        return (K == 0) ? 1 : 0;
    }
    if (table[i][color_count][K] != -1)
        return table[i][color_count][K];

    table[i][color_count][K] = bc(i + 1, color_count + 1, N, M, K) + bc(i + 1, 1, N, M, K - 1);
    return table[i][color_count][K];
}

int main()
{
    int N, M, K;
    cin >> N >> M >> K;

    table.resize(N + 1, vector<vector<int>>(M + 1, vector<int>(K + 1, -1)));
    cout << bc(1, 1, N, M, K);
    return 0;
}