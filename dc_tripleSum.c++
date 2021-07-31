#include <iostream>
#include <vector>

using namespace std;
vector<int> A;

bool biSearch(int start, int stop, int x)
{
    if (start > stop)
        return false;
    int mid = (start + stop) / 2;

    if (A[mid] == x)
        return true;
    if (A[mid] > x)
        return biSearch(start, mid - 1, x);
    return biSearch(mid + 1, stop, x);
}

int main()
{
    bool found = false;
    int N, M, q, diff;
    vector<int> Q;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> q;
        A.push_back(q);
    }
    for (int i = 0; i < M; i++)
    {
        cin >> q;
        Q.push_back(q);
    }

    for (int &q : Q)
    {
        found = false;
        for (int i = 0; i < N - 2 && !found; i++)
        {
            // if (A[i] > q)
            //     break;    because the numbers can be negative, this condition isn't correct
            for (int j = i + 1; j < N - 1 && !found; j++)
            {
                diff = q - A[i] - A[j];
                found = biSearch(j + 1, N - 1, diff);
            }
        }
        if (found)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
} // O(MN^2(log(N)))