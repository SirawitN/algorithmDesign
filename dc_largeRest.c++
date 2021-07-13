#include <iostream>
#include <vector>

using namespace std;
vector<long long> C, Q;

long long largeRest(long long startT, long long stopT, long long q)
{
    if (startT > stopT) //terminating condition
        return startT;
    long long mid = (startT + stopT) / 2, numOfCust = C.size();

    for (long long &c : C)
    {
        numOfCust += mid / c;
    }

    if (numOfCust < q)
        return largeRest(mid + 1, stopT, q);
    return largeRest(startT, mid - 1, q);
} // use binary search concept to calculate the number of customers at each duration of time

int main()
{
    int N, A;
    long long q;
    cin >> N >> A;

    for (int i = 0; i < N; i++)
    {
        cin >> q;
        C.push_back(q);
    }
    for (int i = 0; i < A; i++)
    {
        cin >> q;
        Q.push_back(q);
    }

    for (long long &q : Q)
    {
        cout << largeRest(0, 1e12, q); // 1e12 is the maximum value of customers
        cout << "\n";
    }
    return 0;
}

/*  

3 10
340 572 448
6 1 1 1 6 8 8 4 6 4
-->  572 0 0 0 572 896 896 340 572 340

3 10
833 24 9
867 331 658 847 417 997 556 870 582 102
--> 5616 2136 4257 5490 2691 6462 3600 5640 3768 648

*/