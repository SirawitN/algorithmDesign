#include <iostream>
#include <vector>

using namespace std;
vector<int> A = {0}, suf = {0};

int get_sum(int start, int stop)
{
    return suf[stop] - suf[start - 1];
}

int mss(int start, int stop, int w)
{
    if (start == stop)
        return A[start];

    int mid, r1, r2, r3, max_left, max_right, getSum;
    mid = (start + stop) / 2;
    int idx_left = mid, idx_right = mid + 1;

    r1 = mss(start, mid, w);
    r2 = mss(mid + 1, stop, w);

    max_left = A[mid];
    max_right = A[mid + 1];
    for (int i = mid - 1; i >= start && mid - i < w - 1; i--)
    {
        getSum = get_sum(i, mid);
        if (getSum > max_left)
        {
            max_left = getSum;
            idx_left = i;
        }
    }
    for (int j = mid + 2; j <= stop && j - idx_left < w; j++)
    {
        getSum = get_sum(mid + 1, j);
        if (getSum > max_right)
        {
            max_right = getSum;
            idx_right = j;
        }
    }
    r3 = (idx_right - idx_left < w) ? max_left + max_right : -1001;

    //cout << "left, right = " << max_left << " " << max_right << "\n";
    //cout << "start = " << start << " stop = " << stop << " (i,j) = " << idx_left << " " << idx_right << " ";
    //cout << "r1 = " << r1 << " r2 = " << r2 << " r3 = " << r3 << "\n";

    return max(r1, max(r2, r3));
}

int main()
{
    int n, w, q;
    cin >> n >> w;

    for (int i = 1; i <= n; i++)
    {
        cin >> q;
        A.push_back(q);
        suf.push_back(suf[i - 1] + q);
    }

    cout << mss(1, n, w);
}

// ใช้ D&C ได้ไม่ติด T ใน grader : O(nlg(n))

/*

5 3
-10 -2 -3 -4 -5
--> -2

10 4 
1 4 2 -3 5 -7 3 9 2 -7
--> 14

*/