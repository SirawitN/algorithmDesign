#include <iostream>
#include <vector>

using namespace std;
vector<int> V = {0, 1}; // เป็นเวกเตอร์ที่มีค่าในแต่ละ idx เป็นตำแหน่ง xi เริ่มต้นของแต่ละ idx
                        // เช่น V[1] = 1 คือ ค่า 1 เริ่มต้นที่ x1, V[4] = 6 คือ ค่า 4 เริ่มต้นที่ x6

int biSearchNear(int start, int stop, int x)
{
    if (start == stop)
        return start;
    if (stop - start == 1)
        return (V[stop] <= x) ? stop : start;

    int mid = (start + stop) / 2;
    if (V[mid] > x)
        return biSearchNear(start, mid - 1, x);
    return biSearchNear(mid, stop, x);
} // return a index that has value not greater than x

void selfDesc(int maxQ)
{
    int i = 1, offset, j = 1; // i = ค่าของ xi ที่เป็นตำแหน่งเริ่มต้นของค่า j
    while (i < maxQ)          //เริ่มต้นนั้น V มีข้อมูล 0,1 นั่นคือค่าที่ต้องหาต่อไปคือ ตำแหน่งเริ่มต้นของ j=2 จึงต้องหาว่า j=1 มีค่า xi เริ่มต้นเท่าไร
                              // j จึงเท่ากับ 1 และทำให้ i = 1
    {
        offset = biSearchNear(0, V.size() - 1, j);
        i += offset;
        j++;
        V.push_back(i);
    }
}

int main()
{
    int N, q, maxQ;
    vector<int> Q;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> q;
        Q.push_back(q);
        maxQ = (i == 0) ? q : max(q, maxQ);
    }

    selfDesc(maxQ);

    for (int &q : Q)
    {
        cout << biSearchNear(0, V.size() - 1, q) << "\n";
    }
} // O(nlg(n))