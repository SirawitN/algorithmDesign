#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> P;
    int N, K, p, tmp, bound;
    cin >> N >> K;
    bound = 2 * K + 1;

    for (int i = 0; i < N; i++)
    {
        cin >> p;
        if (i <= K)
            P.push_back(p);
        else
        {
            for (int j = 1; j <= bound && i - j >= 0; j++) // find the minimum in range[i-1, i-(2k+1)]
            {
                tmp = (j == 1) ? P[i - 1] : min(tmp, P[i - j]);
            }
            P.push_back(p + tmp); // push into the array
        }
    }

    for (int i = 0; i <= K && N - 1 - i >= 0; i++) // find the minimum from the tail to N-1-K
    {
        tmp = (i == 0) ? P[N - 1] : min(tmp, P[N - 1 - i]);
    }
    cout << tmp;

    return 0;
}

/*
มองปัญหาเป็นการเลือกจำนวนที่น้อยที่สุดในช่วง 2*k+1 นับจาก index ที่กำลังพิจารณา เพราะพื้นที่ไม่จำเป็นต้อง intersect กัน ขอแค่ครอบคลุม N ช่อง

10 3
260 241 865 354 3 626 225 335 243 405 = 466

10 5
636 397 930 233 180 727 990 415 511 73 = 180

10 7
300 531 415 981 34 482 629 412 300 369 = 34

20 3
128 219 95 974 403 925 274 841 717 44 559 886 997 940 172 908 621 872 481 571 = 760

20 1
1 387 794 443 84 152 770 281 461 901 224 762 82 427 546 128 32 470 104 253 = 1290

*/