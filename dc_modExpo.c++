#include <iostream>

using namespace std;

//  from (a*b) mod k = [(a mod k)*(b mod k)] mod k

int modExpo(int a, int n, int k)
{
    if (n == 1)
        return a % k; //  terminating condition
    int m = n / 2;
    int tmp = modExpo(a, m, k);
    if (n % 2 == 0)
    { // n is even
        return (tmp * tmp) % k;
    }
    else
    {
        tmp = (tmp * tmp) % k;
        return (tmp * (a % k)) % k;
    }
}

int main()
{
    int a, n, k;
    cin >> a >> n >> k;
    cout << modExpo(a, n, k);
}

/*   test cases
    2 5 100			: 32
    2 6 7			: 1
    10 2 7			: 2
    23 4 100		: 41
    293 1 100		: 93
    223 5000000 100		: 1
    1923 2000000000 8101	: 454
    2832 2000000000 1007	: 1
    7262 2000000000 3919	: 767
    5281 2000000000 1103	: 629
*/