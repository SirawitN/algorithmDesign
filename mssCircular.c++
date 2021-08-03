#include <iostream>
#include <vector>

using namespace std;
vector<int> A, suffix, minSuf;
vector<bool> done, minDone;

int max_suffix(int stop)
{
    if (stop == 0)
        return A[0];
    if (done[stop])
        return suffix[stop];

    suffix[stop] = max(A[stop], A[stop] + max_suffix(stop - 1));
    done[stop] = true;

    return suffix[stop];
}

int mssCirc(int stop)
{
    if (stop == 0)
        return A[0];

    int r1, r2, r3;
    r1 = mssCirc(stop - 1);
    r2 = A[stop];
    r3 = max_suffix(stop - 1) + A[stop];
    return max(r1, max(r2, r3));
}

int minSuffix(int stop)
{
    if (stop == 0)
        return A[0];
    if (minDone[stop])
        return minSuf[stop];

    minSuf[stop] = min(A[stop], A[stop] + minSuffix(stop - 1));
    minDone[stop] = true;

    return minSuf[stop];
}

int minMss(int stop)
{
    if (stop == 0)
        return A[0];
    int r1, r2, r3;

    r1 = minMss(stop - 1);
    r2 = A[stop];
    r3 = A[stop] + minSuffix(stop - 1);
    return min(r1, min(r2, r3));
}

int main()
{
    int N, q, sum = 0, minNeg;
    cin >> N;

    suffix.resize(N);
    minSuf.resize(N);
    done.resize(N, false);
    minDone.resize(N, false);

    for (int i = 0; i < N; i++)
    {
        cin >> q;
        A.push_back(q);
        minNeg = (i == 0) ? q : max(q, minNeg);
        sum += q;
    }

    int ans1 = mssCirc(N - 1), ans2 = sum - minMss(N - 1);

    if (ans2 == 0) // all the numbers are negative, so sum = minMss
        cout << max(ans1, minNeg);
    else
        cout << max(ans1, ans2);
}

// find the minimum contigeous sum to subtract from the summation

/*

10
69 -332 -910 -314 -592 255 -442 -868 -660 671
--> 740

100
-690 -469 -283 -494 -384 -226 -732 -372 -499 -345 -34 -877 -512 -756 -986 -620 -980 -660 -889 -810 -435 -958 -970 -811 -349 -577 -806 -851 -786 -345 -763 -106 -881 -607 -396 -992 -757 -962 -879 -879 -907 -785 -34 -503 -405 -782 -916 -304 -892 -624 -569 -867 -174 -747 -731 -16 -281 -981 -738 -537 -42 -777 -482 -397 -134 -524 -320 -384 -580 -292 -294 -331 -871 -83 -229 -915 -474 -208 -887 -813 -356 -544 -569 -356 -551 -695 -258 -505 -76 -7 -361 -838 -188 -561 -275 -325 -874 -749 -355 -354
--> -7

500
78 11 89 4 34 53 69 34 54 10 55 62 8 61 95 58 22 66 80 48 62 28 39 99 43 74 3 92 29 95 79 96 3 16 13 80 21 100 47 44 50 27 17 49 16 18 98 68 92 80 15 84 25 39 80 5 36 18 78 27 95 12 68 95 68 71 73 50 77 68 35 86 60 84 78 94 0 15 86 96 36 89 25 29 91 29 42 67 35 90 85 18 52 10 62 0 76 35 52 51 94 48 31 27 100 72 2 94 69 62 93 24 39 56 18 71 53 9 27 12 53 69 88 47 74 99 60 46 26 39 80 89 10 44 57 68 15 80 74 41 8 46 61 74 70 73 71 7 43 59 84 59 32 63 59 89 24 35 7 86 28 11 67 47 81 88 78 67 53 1 59 14 20 26 51 41 28 51 66 95 3 92 76 46 52 85 87 23 45 85 80 28 68 91 94 29 32 72 89 37 72 26 21 4 92 95 31 75 69 99 12 27 52 18 17 29 20 61 12 78 18 61 96 20 87 24 14 69 62 43 13 99 95 87 98 65 18 11 72 70 92 52 81 85 96 99 9 40 16 48 14 15 51 17 57 80 1 37 7 80 3 68 13 31 89 87 96 47 82 32 99 12 62 42 14 68 19 23 81 48 89 3 5 11 49 60 17 42 53 67 49 15 26 24 87 27 36 49 54 39 53 43 0 53 27 66 36 100 14 39 59 64 47 18 92 79 26 56 42 35 24 72 18 34 19 70 31 91 71 45 7 74 41 36 26 50 12 14 27 37 33 79 8 22 28 15 24 30 18 7 93 99 78 35 29 82 34 57 73 59 46 64 50 83 63 17 10 1 52 80 83 77 86 94 40 99 87 79 31 73 15 76 65 32 71 22 35 0 4 81 4 62 75 91 91 77 57 61 23 69 63 16 65 41 90 89 12 68 96 43 3 80 61 23 87 68 82 57 52 34 99 0 59 95 54 43 89 57 9 98 52 41 57 100 19 14 59 34 3 41 56 71 63 82 11 68 34 18 96 43 52 78 81 87 78 82 94 65 67 12 14 64 46 21 54 85 58 78 79 20 21 33 68 44 89 61 57 76 2 53 52 76 18 87 94 18 24 35 79 22 4 84 84 23 86 6 24 81 19 6
--> 25697

*/