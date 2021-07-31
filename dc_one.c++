#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> Q = {0, 1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111, 1111111111};

int one(int N)
{
    if (N >= 1 && N <= 11)
    {
        return (N < 7) ? N : N - (2 * (N - 7) + 1);
    } // trivial case

    int idx = upper_bound(Q.begin(), Q.end(), N) - Q.begin(); //search for Qk that is Qk-1 <= abs(N)

    int n = abs(N - Q[idx]);

    if (n < N - Q[idx - 1])
        return idx + one(n); // choose Qk for 1 time
    return idx - 1 + one(N - Q[idx - 1]);
}

int main()
{
    int N;
    cin >> N;

    cout << one(N);

    return 0;
}
