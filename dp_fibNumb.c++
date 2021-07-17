#include <iostream>
#include <vector>

using namespace std;

int fibNumb(int N)
{
    if (N == 0 || N == 1)
        return N;
    int n0 = 0, n1 = 1, n2;
    for (int i = 2; i <= N; i++)
    {
        n2 = n1 + n0;
        n0 = n1;
        n1 = n2;
    }
    return n2;
}

int fibNumb2(int N) // using an array
{
    if (N == 0 || N == 1)
        return N;
    vector<int> tab(3);
    tab[0] = 0;
    tab[1] = 1;

    for (int i = 2; i <= N; i++)
    {
        tab[2] = tab[0] + tab[1];
        tab[0] = tab[1];
        tab[1] = tab[2];
    }
    return tab[2];
}

int main()
{
    int N;
    cin >> N;
    cout << fibNumb(N) << " " << fibNumb2(N);
}