#include <iostream>
#include <vector>

using namespace std;

vector<int> &matrixMult(const vector<int> &V, const vector<int> &W, int K)
{
    vector<int> ans;
    int v1 = V[0], v2 = V[1], v3 = V[2], v4 = V[3];
    int w1 = W[0], w2 = W[1], w3 = W[2], w4 = W[3];

    ans.push_back((v1 * w1 + v2 * w3) % K);
    ans.push_back((v1 * w2 + v2 * w4) % K);
    ans.push_back((v3 * w1 + v4 * w3) % K);
    ans.push_back((v3 * w2 + v4 * w2) % K);

    return ans;
}

vector<int> &
matrixMod(vector<int> A, int N, int K)
{
    cout << N << "\n";
    if (N == 1)
    {
        for (int &a : A)
        {
            cout << a << " ";
            a %= K;
        }
        return A;
    }

    int n = N / 2;
    vector<int> tmp = matrixMod(A, n, K);
    vector<int> ans = matrixMult(tmp, tmp, K);

    if (N % 2 == 0)
        return ans;
    for (int &a : A)
        a %= K;
    return matrixMult(ans, A, K);
}

int main()
{
    int N, K, q;
    vector<int> A, ans;
    cin >> N >> K;

    for (int i = 0; i < 4; i++)
    {
        cin >> q;
        A.push_back(q);
    }

    ans = matrixMod(A, N, K);
    cout << "s = " << ans.size() << "\n";
    for (int &a : ans)
        cout << a << " ";
    return 0;
}