#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int> vectOp(vector<int> &V, int start, int mid, bool addit)
{
    vector<int> res;
    int left = start, right = mid, n = V.size();
    ;
    for (int i = 0; i < n / 2; i++)
    {
        if (addit)
            res.push_back(V[left++] + V[right++]);
        else
            res.push_back(V[left++] - V[right++]);
    }
    return res;
}

vector<int> hanamard(vector<int> &V, int k)
{
    if (k == 0)
    {
        return V;
    }

    int n = V.size();

    vector<int> head = vectOp(V, 0, n / 2, true);
    vector<int> tail = vectOp(V, 0, n / 2, false);

    vector<int> ans1 = hanamard(head, k - 1);
    vector<int> ans2 = hanamard(tail, k - 1);
    ans1.insert(ans1.end(), ans2.begin(), ans2.end());
    return ans1;
}

int main()
{
    int N, q, k;
    vector<int> V, ans;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> q;
        V.push_back(q);
    }
    k = (int)log2(N);

    ans = hanamard(V, k);

    for (int &a : ans)
        cout << a << " ";

    return 0;
}

/*

64
7 -5 -3 -7 -9 7 1 1 0 6 5 -1 8 9 -1 5 7 5 -4 -9 -1 -8 1 2 1 5 -8 2 6 -3 0 9 -1 1 6 9 6 -4 2 9 -2 8 9 -1 -1 5 4 -2 -1 7 -5 1 -1 -3 -4 2 -6 9 1 7 -5 -7 -5 -5
-->  61 -47 19 -1 25 -15 59 -61 -43 33 -9 43 -11 45 59 35 81 29 -21 -57 -43 77 -69 27 -19 -23 -53 55 5 -11 -9 31 -5 31 65 29 -77 67 61 29 -73 35 9 -83 51 35 33 49 -45 -41 29 -31 19 27 -31 33 -21 -17 25 -19 -33 31 25 49

128
-3 4 6 -1 -8 9 5 -7 -9 7 8 6 -3 -2 4 -9 3 9 -3 -8 -4 3 7 -6 3 4 3 -5 7 -5 5 8 -7 -4 6 5 -9 0 0 9 -3 1 4 8 0 9 2 7 -7 -8 1 7 5 -7 -4 9 6 9 -2 -4 -3 -3 6 -3 -6 3 -8 4 2 -6 0 -9 7 -8 -3 2 -3 -4 0 9 -5 2 7 -9 2 6 -2 -6 -5 -6 -8 -6 -8 -5 5 7 -4 -9 -8 -2 -6 3 -9 -1 0 -4 -2 4 2 -8 4 3 8 6 9 4 4 7 -5 -9 3 -3 0 5 -9 -6 4 8
-->  -4 -32 -108 -56 12 -12 36 12 -66 -30 110 -94 26 18 -150 2 -40 -88 -84 12 8 -20 -100 64 -94 -38 -42 -2 -34 10 114 30 -42 62 78 -138 -26 -62 54 -14 36 20 84 -124 24 -68 48 52 34 22 6 10 130 -70 -34 38 56 12 -4 64 -36 -60 -56 -32 120 -20 -32 -124 16 -32 0 -48 -42 -22 -170 90 -62 66 106 42 64 -56 -60 -164 48 68 -100 16 102 86 58 -38 42 70 6 -30 38 46 70 -82 78 -14 -2 34 8 -24 128 -64 -4 88 52 112 -114 10 -6 -58 -34 -26 -38 -14 24 -28 -44 80 -76 124 -48 -24

*/