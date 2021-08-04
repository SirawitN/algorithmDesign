#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> table, A;

int numbTri(int row, int col)
{
    if (row == 1)
        return A[1][0];
    if (table[row][col] != -1)
        return table[row][col];

    if (col >= row - 1) //กรณีตัวปัจจุบันอยู่ชิดขอบขวาในแต่ละชั้น
        table[row][col] = A[row][col] + numbTri(row - 1, col - 1);
    else if (col == 0) // กรณีตัวปัจจุบันอยู่ชิดขอบซ้ายในแต่ละชั้น
        table[row][col] = A[row][col] + numbTri(row - 1, col);
    else
        table[row][col] = A[row][col] + max(numbTri(row - 1, col - 1), numbTri(row - 1, col));

    return table[row][col];
}

int main()
{
    int N, q;
    cin >> N;

    A.resize(N + 1);
    table.resize(N + 1, vector<int>(N, -1));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cin >> q;
            A[i].push_back(q);
        }
    }

    int maxSum = numbTri(N, N - 1);
    for (int i = 0; i < N - 1; i++)
    {
        maxSum = max(maxSum, numbTri(N, i));
    }

    cout << maxSum;
    return 0;
}
/*
ทำ DP แบบ top-down จะเร็วกว่า bottom-up เพราะมี patch ซ้ำกัน สามารถใช้look-up table ตอบได้เลย

2
10
20 30
--> 40

5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
--> 30

3
579
262 408
769 467 361
--> 1610

6
297
889 254
406 184 205
834 14 744 10
991 574 674 676 513
478 224 89 549 823 559
--> 3895

10
421
861 837
39 509 953
256 842 454 806
753 583 741 412 650
904 252 976 348 433 256
363 917 423 598 414 53 547
588 948 326 301 443 863 832 31
432 821 93 17 402 644 723 947 167
117 304 168 3 135 183 694 672 553 778
--> 6921
*/