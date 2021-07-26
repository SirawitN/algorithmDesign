//#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;
vector<int> t, g;

int tile(int N);
int tileWithL_Shape(int N)
{
    if (N == 0 || N == 1)
        return (N == 0) ? 0 : 1;
    if (g[N] != -1)
        return g[N];

    g[N] = tile(N - 1) + tileWithL_Shape(N - 1);

    return g[N];
}

int tile(int N)
{
    if (N == 1 || N == 2)
        return N;
    if (t[N] != -1)
        return t[N];

    t[N] = tile(N - 1) + tile(N - 2) + tileWithL_Shape(N - 2);

    return t[N];
}

int main()
{
    int N;
    cin >> N;

    t.resize(N + 1, -1);
    g.resize(N + 1, -1);
    cout << tile(N);

    return 0;
}