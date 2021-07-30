#include <iostream>
#include <math.h>

using namespace std;

int numb1(int pL, int idx, int pR, int leftB, int rightB, int N, int H)
{
    if (H == 0) // reached the root of a tree
    {
        return (idx >= leftB && idx <= rightB) ? N : 0;
    }
    if (pL >= leftB && pR <= rightB)
        return N; //if all possible leaf's of a node are in the bound, no need to divide it to '0' and '1'
    if (pL > rightB || pR < leftB)
        return 0; // leafs of a node are out of bound

    int offset = pow(2, H - 1);
    return ((idx >= leftB && idx <= rightB) ? N % 2 : 0) + numb1(pL, idx - offset, idx, leftB, rightB, N / 2, H - 1) + numb1(idx, idx + offset, pR, leftB, rightB, N / 2, H - 1);
}

int main()
{
    int N, l, r, H, mid, numbLeaf;
    cin >> N >> l >> r;

    H = (int)(log2(N));
    mid = pow(2, H);
    numbLeaf = pow(2, H + 1) - 1;

    cout << numb1(0, mid, numbLeaf, l, r, N, H);
    return 0;
}