#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

int main()
{
    int N, x, y, strip = 1e9;
    vector<pair<int, int>> C;
    pair<int, int> p1, p2;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        C.push_back(make_pair(x, y));
    }
    sort(C.begin(), C.end());

    for (int i = 0; i < N - 1; i++)
    {
        p1 = C[i];
        for (int j = i + 1; j < i + 8 && j < N; j++)
        {
            p2 = C[j];
            if (p2.first < p1.first + strip)
                strip = min(strip, (int)(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2)));
        }
    }
    cout << strip;
}

/*

10
27163 8085
25293 17036
24695 3280
13808 16873
28688 20544
6290 13106
674 22131
7741 14732
7577 22052
3003 26847
-->  4749277

10
1010 19498
1010 7562
1010 914
990 22925
1010 9356
990 6268
990 7194
990 9088
990 8628
1010 19875
-->  72224

*/