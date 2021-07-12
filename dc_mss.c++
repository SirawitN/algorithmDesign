#include <iostream>
#include <vector>

using namespace std;
vector<int> V = {0}, S = {0};

int get_sum(int a, int b)
{
    return S[b] - S[a - 1];
}

int mss(int start, int stop)
{
    if (start >= stop)
        return V[start];
    int mid = (start + stop) / 2, r1, r2, r3, max_left, max_right;

    r1 = mss(start, mid);
    r2 = mss(mid + 1, stop);

    max_left = get_sum(mid, mid);
    max_right = get_sum(mid + 1, mid + 1);

    for (int i = start; i < mid; i++)
    {
        max_left = max(max_left, get_sum(i, mid));
    }
    for (int i = mid + 2; i <= stop; i++)
    {
        max_right = max(max_right, get_sum(mid + 1, i));
    }
    r3 = max_left + max_right;
    return max(r1, max(r2, r3));
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int N, q;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> q;
        V.push_back(q);
    }

    for (int j = 1; j <= N; j++)
    {
        S.push_back(S[j - 1] + V[j]);
    }

    cout << mss(1, N);
}

/*  test cases

15
1 2 -1 5 3 -8 -2 4 3 -4 -5 7 -1 -2 4  : 10

20
-5 2 -5 6 -8 1 2 3 1 -6 4 1 5 -2 3 -8 2 -4 2 1  : 12

20
-1 2 -3 2 2 -5 -3 8 1 -3 -11 2 -3 4 5 -6 4 1 3 8  : 19

20
-3 1 -3 2 -3 -3 3 -3 4 -3 5 -3 9 -3 8 -3 7 -3 6 -3 : 24

20
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 : -1

*/