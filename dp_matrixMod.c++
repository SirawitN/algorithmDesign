#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
unordered_map<int, vector<int>> table;

vector<int> matMult(vector<int> &W, vector<int> &V, int K)
{
    int w1 = W[0], w2 = W[1], w3 = W[2], w4 = W[3];
    int v1 = V[0], v2 = V[1], v3 = V[2], v4 = V[3];
    vector<int> res;

    res.push_back(((w1 * v1) % K + (w2 * v3) % K) % K);
    res.push_back(((w1 * v2) % K + (w2 * v4) % K) % K);
    res.push_back(((w3 * v1) % K + (w4 * v3) % K) % K);
    res.push_back(((w3 * v2) % K + (w4 * v4) % K) % K);

    return res;
}

vector<int> &matMod(vector<int> V, int N, int K)
{
    if (table[N].size() != 0)
        return table[N];
    if (N == 1)
    {
        for (int &v : V)
            v %= K;
        table[1] = V;
        return table[1];
    }

    int M = N / 2;
    vector<int> tmp = matMod(V, M, K);

    tmp = matMult(tmp, tmp, K);

    if (N % 2 != 0)
    {
        for (int &v : V)
            v %= K;
        tmp = matMult(tmp, V, K);
    }
    table[N] = tmp;
    return table[N];
}

int main()
{
    int N, K, q;
    vector<int> V, ans;
    cin >> N >> K;

    for (int i = 0; i < 4; i++)
    {
        cin >> q;
        V.push_back(q);
    }

    ans = matMod(V, N, K);
    for (int &i : ans)
    {
        cout << i << " ";
    }

    return 0;
}

/*

3 5
2 9 1 3  --> 1 2 3 4

2 10000
2 9 8 3  -->  76 45 40 81

2 100
2 3 3 3  -->  13 15 15 18

42 7
2 9 8 8  -->  3 3 5 5

1000 1000
2 3 8 3  -->  376 875 0 1

10000000 121
2 9 8 12  -->  23 110 44 78

80000000 726
32 9 8 3  -->  364 429 220 111

100000000 4625
2 9 8 4  -->  483 1711 1007 1891

199888777 337
2 5 8 3  --> 276 152 41 239

999888777 189
2 9 1 3  -->  8 63 91 99

*/