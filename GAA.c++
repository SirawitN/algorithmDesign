#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> table = {3};

bool gaa(int N)
{
    if (N <= 3)
        return (N == 1) ? true : false;

    int idx = lower_bound(table.begin(), table.end(), N) - table.begin(); // search for a k that g(k) isn't less than N
    int leftElement = table[idx - 1];                                     // remember length of g(k-1)

    if (N >= leftElement + 1 && N <= leftElement + idx + 3) // if N is in center, g a a a ....k+2 .... a
        return (N == leftElement + 1) ? true : false;       // check if N is a position that continue from the last g(k-1), if yes, it's 'g'
    return gaa(N - leftElement - idx - 3);                  // subtract N by the number of elements from left to center area, recursive
}

int main()
{
    int idx = 1, N;

    // -------------  generate a table of length of all g(k) which is not more than 10^9 ---------------------------
    while (2 * table[idx - 1] + idx + 3 <= 1e9)
    {
        table.push_back(2 * table[idx - 1] + idx + 3);
        idx++;
    }
    // ------------------------------------------------------------------------------------
    cin >> N;

    bool isG = gaa(N);
    if (isG)
        cout << "g";
    else
        cout << "a";
    return 0;
}

/*

Diveide and conquer + Dynamic programing
98 = g
34 = a
63 = a
12087 = a
19909 = g
600023589 = g
600020570 = a
900089820 = g

*/