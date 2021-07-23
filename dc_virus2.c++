#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool virus(vector<int> &V, int start, int stop)
{
    if (stop - start == 3)
    {
        int left_sum = V[start] + V[start + 1], right_sum = V[stop - 1] + V[stop];
        return abs(left_sum - right_sum) <= 1;
    }

    int mid = (start + stop) / 2, sum_left = 0, sum_right = 0;

    bool subV = virus(V, start, mid) && virus(V, mid + 1, stop);
    for (int i = start; i <= stop; i++)
    {
        if (i <= mid)
            sum_left += V[i];
        else
            sum_right += V[i];
    } // DO NOt forget to check the number of '1' in any sides apart from the sub-array  !!!!
    // Ex : 1 1 1 0 0 1 0 0  &&   0 0 0 1 1 0 0 1
    return subV && abs(sum_left - sum_right) <= 1;
}

int main()
{
    int k, n, q, l;
    vector<vector<int>> A;
    cin >> n >> k;

    l = pow(2, k);
    A.resize(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < l; j++)
        {
            cin >> q;
            A[i].push_back(q);
        }
    }

    for (vector<int> &V : A)
    {
        if (virus(V, 0, l - 1))
            cout << "yes";
        else
            cout << "no";
        cout << "\n";
    }

    return 0;
}

/*

10 4
1 1 0 1 0 1 0 1 0 1 0 1 1 1 0 1
0 0 1 0 0 0 1 1 1 1 1 1 1 1 1 1
1 1 1 0 0 1 0 0 0 0 0 1 1 0 0 1
1 1 0 0 0 1 0 1 1 1 1 0 0 0 1 0
1 1 1 1 0 0 1 1 0 1 0 1 0 1 0 1
1 0 1 0 1 1 1 0 0 1 1 1 1 1 0 1
0 1 0 0 0 1 1 1 0 0 0 0 0 1 0 0
1 1 0 0 1 1 0 1 0 1 0 0 1 0 1 0
1 0 1 0 1 1 0 0 1 0 0 0 1 0 1 0
0 1 0 0 1 1 0 0 0 1 0 1 1 1 0 1

yes
no
no
no
no
yes
no
no
no
no
*/