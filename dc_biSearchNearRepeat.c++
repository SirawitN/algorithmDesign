#include <iostream>
#include <vector>

using namespace std;

int biSearchNearRep(vector<int> &V, int start, int stop, int x)
{
    if (start >= stop)
        return start;
    if (stop - start == 1)
        return (V[stop] <= x) ? stop : start;
    int mid = (start + stop) / 2;

    if (V[mid] > x)
        return biSearchNearRep(V, start, mid - 1, x);
    return biSearchNearRep(V, mid, stop, x);
}

int main()
{
    int N, M, q;
    vector<int> V, Q;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> q;
        V.push_back(q);
    }
    for (int j = 0; j < M; j++)
    {
        cin >> q;
        Q.push_back(q);
    }

    for (int &q : Q)
    {
        if (q < V[0])
            cout << "-1";
        else
            cout << biSearchNearRep(V, 0, N - 1, q);
        cout << '\n';
    }

    return 0;
}

/*

10 20
3 6 7 7 7 7 7 11 11 11
1 10 3 1 8 4 18 19 6 1 1 5 1 16 1 2 2 17 0 19
-->  -1 6 0 -1 6 0 9 9 1 -1 -1 0 -1 9 -1 -1 -1 9 -1 9

*/