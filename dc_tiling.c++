#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, pair<int, int>> ans;
typedef const pair<int, int> point;

vector<ans> V;

void tiling(int x1, int x2, int y1, int y2, point &p)
{
    //cout << x1 << " " << x2 << " " << y1 << " " << y2 << '\n';
    if (x2 - x1 == 1 && y2 - y1 == 1) // floor size 2*2
    {
        int tile;
        if (p.first == x1 && p.second == y1)
            tile = 0;
        else if (p.first == x2 && p.second == y1)
            tile = 1;
        else if (p.first == x1 && p.second == y2)
            tile = 2;
        else
            tile = 3;
        V.push_back(make_pair(tile, make_pair(x1, y1)));
        return;
    }

    int midX = (x1 + x2) / 2, midY = (y1 + y2) / 2, x = p.first, y = p.second;

    /*
    
    | q1 | q2 |
    | -- | -- |
    | q3 | q4 |  every block of a tile is a new hole in a sub area

*/

    if (x <= midX && y <= midY) // the hole is in Q1
    {
        V.push_back(make_pair(0, make_pair(midX, midY))); //add a tile model0 to V
        tiling(x1, midX, y1, midY, p);
        tiling(midX + 1, x2, y1, midY, make_pair(midX + 1, midY));
        tiling(x1, midX, midY + 1, y2, make_pair(midX, midY + 1));
        tiling(midX + 1, x2, midY + 1, y2, make_pair(midX + 1, midY + 1));
    }
    else if (x > midX && y <= midY) // the hole is in Q2
    {
        V.push_back(make_pair(1, make_pair(midX, midY))); //add a tile model1 to V
        tiling(x1, midX, y1, midY, make_pair(midX, midY));
        tiling(midX + 1, x2, y1, midY, p);
        tiling(x1, midX, midY + 1, y2, make_pair(midX, midY + 1));
        tiling(midX + 1, x2, midY + 1, y2, make_pair(midX + 1, midY + 1));
    }
    else if (x <= midX && y > midY) // the hole is in Q3
    {
        V.push_back(make_pair(2, make_pair(midX, midY))); //add a tile model2 to V
        tiling(x1, midX, y1, midY, make_pair(midX, midY));
        tiling(midX + 1, x2, y1, midY, make_pair(midX + 1, midY));
        tiling(x1, midX, midY + 1, y2, p);
        tiling(midX + 1, x2, midY + 1, y2, make_pair(midX + 1, midY + 1));
    }
    else // the hole is in Q4
    {
        V.push_back(make_pair(3, make_pair(midX, midY))); //add a tile model3 to V
        tiling(x1, midX, y1, midY, make_pair(midX, midY));
        tiling(midX + 1, x2, y1, midY, make_pair(midX + 1, midY));
        tiling(x1, midX, midY + 1, y2, make_pair(midX, midY + 1));
        tiling(midX + 1, x2, midY + 1, y2, p);
    }
}

int main()
{
    int L, x, y;
    cin >> L >> x >> y;

    tiling(0, L - 1, 0, L - 1, make_pair(x, y));

    cout << V.size() << "\n";
    for (ans &a : V)
    {
        cout << a.first << " " << a.second.first << " " << a.second.second << "\n";
    }

    return 0;
}

/*

4 1 2
ans 
5
2 1 1
2 2 0
0 2 2
1 0 2
3 0 0  order isn't matter

*/