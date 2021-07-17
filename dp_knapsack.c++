// 0-1 knapsack
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> table;
vector<int> V = {0}, W = {0};

int knapsack(int a, int b)
{
    if (a == 0 || b == 0)
        return 0;
    if (W[a] > b)
        return knapsack(a - 1, b);
    if (table[a][b] != -1)
        return table[a][b];

    table[a][b] = max(knapsack(a - 1, b - W[a]) + V[a], knapsack(a - 1, b));
    return table[a][b];
}

int knapsack_bt(int a, int b)
{
    for (int i = 0; i <= a; i++)
        table[i][0] = 0;
    for (int i = 0; i <= b; i++)
        table[0][i] = 0;

    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (W[i] > j)
            {
                table[i][j] = table[i - 1][j];
                continue;
            }
            table[i][j] = max(table[i - 1][j - W[i]] + V[i], table[i - 1][j]);
        }
    }
    return table[a][b];
}

vector<int> knapsack_tracking(int a, int b)
{
    int max_value = table[a][b], i = a, bag = b;
    vector<int> answer;
    while (i != 0)
    {
        if (table[i - 1][bag - W[i]] + V[i] == max_value)
        {
            answer.push_back(i);
            max_value -= V[i];
            bag -= W[i];
        }
        i--;
    }
    return answer;
}

int main()
{
    int a, b, q, max_value; // a is the number of items, b is capacity of the bag
    vector<int> item_list;

    cin >> a >> b;
    table.resize(a + 1, vector<int>(b + 1, -1));

    for (int i = 0; i < a; i++)
    {
        cin >> q;
        V.push_back(q);
    }
    for (int i = 0; i < a; i++)
    {
        cin >> q;
        W.push_back(q);
    }

    max_value = knapsack_bt(a, b);
    item_list = knapsack_tracking(a, b);
    cout << max_value << "\nThe order of taken items is ";
    for (vector<int>::reverse_iterator it = item_list.rbegin(); it != item_list.rend(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}