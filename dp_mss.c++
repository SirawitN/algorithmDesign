//  Maximum Subarray Sum
#include <iostream>
#include <vector>

using namespace std;
vector<int> A, table;
vector<bool> done;

//-----------------  Top-down  ----------------------------------

int max_suffix(int stop)
{
    if (stop == 0)
        return A[0];
    if (done[stop])
        return table[stop];

    table[stop] = max(A[stop], max_suffix(stop - 1) + A[stop]);
    done[stop] = true;

    return table[stop];
}

int mss(int stop)
{
    if (stop == 0)
        return A[0];
    int r1, r2, r3;

    r1 = mss(stop - 1);
    r2 = A[stop];
    r3 = max_suffix(stop - 1) + A[stop];

    return max(r1, max(r2, r3));
}

// ----------------  Bottom-up  ---------------------------

int mss_bt(int n)
{
    vector<int> max_suf(n);
    max_suf[0] = A[0];
    for (int i = 1; i < n; i++)
    {
        max_suf[i] = max(max_suf[i - 1] + A[i], A[i]);
    }

    int mss = A[0];
    for (int i = 1; i < n; i++)
    {
        mss = max(mss, max(A[i], max_suf[i - 1] + A[i]));
    }
    return mss;
}

int kadane(int n)
{
    int suf = A[0];
    int mss = A[0];
    for (int i = 1; i < n; i++)
    {
        suf = max(A[i], suf + A[i]);
        mss = max(mss, suf);
    }
    return mss;
}

int main()
{
    int n, q;
    cin >> n;

    table.resize(n);
    done.resize(n, false);
    for (int i = 0; i < n; i++)
    {
        cin >> q;
        A.push_back(q);
    }

    cout << "mss = " << mss(n - 1) << " " << mss_bt(n) << " " << kadane(n);

    return 0;
}

/*

4
1 4 2 3
mss = 10 10 10

4
-2 -1 -3 -5
mss = -1 -1 -1

9
2 3 -6 4 -2 3 -5 -4 3
mss = 5 5 5

8
3 -4 1 2 -1 -1 5 -4
mss = 6 6 6

*/