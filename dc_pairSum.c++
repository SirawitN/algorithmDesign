#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    int N, M, q, diff;
    bool found;
    map<int, int> A;
    vector<int> Q;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> q;
        A[q]++;
    }
    for (int i = 0; i < M; i++)
    {
        cin >> q;
        Q.push_back(q);
    }

    for (int &q : Q)
    {
        found = false;
        for (pair<const int, int> &k : A)
        {
            if (k.first > q)
            {
                break;
            }
            diff = q - k.first;
            if (diff != k.first)
            {
                if (A.find(diff) != A.end())
                {
                    found = true;
                    break;
                }
            }
            else
            {
                if (A[diff] > 1)
                {
                    found = true;
                    break;
                }
            }
        }
        if (found)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
} // O(MNlog(N))