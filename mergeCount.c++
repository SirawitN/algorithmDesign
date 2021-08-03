#include <iostream>
#include <vector>

using namespace std;
int k;

bool mergeCount(vector<int> &A, int start, int stop)
{
    //cout << start << " " << stop << "\n";
    if (stop - start == 1 || k == 0) //เนื่องจากเป็น [start,stop), stop-start==1 = เหลือเพียง 1 element
        return true;
    if (stop - start == 2) // have 2 elements
    {
        swap(A[start], A[stop - 1]);
        k -= 2;
        return true;
    }

    int mid = (start + stop) / 2;
    swap(A[mid - 1], A[mid]); // การสลับ sorted array 1 ครั้ง = เพิ่มจำนวนครั้งการเรียก mergeCount 2 ครั้ง
    k -= 2;
    return mergeCount(A, start, mid) && mergeCount(A, mid, stop);
}

void printVec(vector<int> &V)
{
    for (int &v : V)
        cout << v << " ";
    cout << "\n";
    return;
}

int main()
{
    int N;
    cin >> N >> k;

    vector<int> A;
    for (int i = 0; i < N; i++)
    {
        A.push_back(i + 1);
    }

    k -= 1;
    bool success = mergeCount(A, 0, N) && k == 0;

    if (success)
        printVec(A);
    else
        cout << "-1";
}

/*

10 5
1 3 2 4 6 5 7 8 9 10

100 15
2 4 1 3 5 7 6 8 9 10 11 13 12 14 15 16 17 18 19 20 21 22 23 24 26 25 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 51 50 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100

100 31
2 4 1 5 7 3 8 10 6 11 13 9 12 14 15 16 17 19 18 20 21 22 23 24 26 25 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 51 50 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100

D&C เพียวๆไม่ติด T เพราะงานจริงน้อย
*/