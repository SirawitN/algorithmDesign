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