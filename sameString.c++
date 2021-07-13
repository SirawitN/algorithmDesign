#include <iostream>

using namespace std;

bool sameString(string A, string B)
{
    if (A.length() == 1)
        return A == B;

    int mid = A.length() / 2;
    string A1 = A.substr(0, mid), A2 = A.substr(mid, mid);
    string B1 = B.substr(0, mid), B2 = B.substr(mid, mid);

    return (sameString(A1, B1) && sameString(A2, B2)) || (sameString(A1, B2) && sameString(A2, B1));
}

int main()
{
    string text1, text2;
    cin >> text1 >> text2;

    if (sameString(text1, text2))
        cout << "YES";
    else
        cout << "NO";
}