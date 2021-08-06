#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> table;
vector<int> C;

int biggerBB(int idx, bool rent)
{
    if (idx < 0)
        return 0;
    if (idx == 0)
        return (rent) ? C[0] : 0;
    if (table[(rent) ? 1 : 0][idx] != -1)
        return table[(rent) ? 1 : 0][idx];

    if (rent)
        table[1][idx] = C[idx] + max(biggerBB(idx - 3, true), biggerBB(idx - 3, false));
    else
        table[0][idx] = max(biggerBB(idx - 1, true), biggerBB(idx - 1, false));

    return table[(rent) ? 1 : 0][idx];
}

int main()
{
    int N, c;
    cin >> N;

    table.resize(2, vector<int>(N, -1));
    for (int i = 0; i < N; i++)
    {
        cin >> c;
        C.push_back(c);
    }

    int maxCust = max(biggerBB(N - 1, false), biggerBB(N - 1, true));
    cout << maxCust;
    return 0;
}

/*

5
298 184 591 927 475 = 1225

10
159 580 430 497 840 599 998 105 510 578 = 2232

20
874 377 929 450 129 372 970 326 324 691 199 162 469 130 875 668 713 230 52 306 = 4473

50
236 817 194 714 274 623 159 155 520 588 205 821 388 943 187 621 926 145 190 137 708 11 803 194 925 164 267 501 606 406 669 532 424 945 624 435 728 601 388 360 244 993 995 440 851 860 368 516 382 946 = 11534

100
472 911 807 744 389 211 999 620 966 355 571 684 189 890 385 620 861 631 55 510 136 752 132 274 811 730 710 786 362 819 388 991 92 394 924 672 738 98 479 847 859 694 656 25 739 630 605 279 297 249 423 747 730 414 773 113 30 537 432 151 250 411 908 694 948 344 701 943 91 217 926 205 1000 117 311 194 605 3 917 233 376 428 166 754 912 691 680 948 397 382 363 427 518 901 389 649 181 963 49 897 = 22374

*/