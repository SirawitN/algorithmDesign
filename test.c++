#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void selectionSort(vector<T> &V)
{
    int n = V.size(), maxIdx;
    for (int i = n - 1; i > 0; i--)
    {
        maxIdx = i;
        for (int j = 0; j < i; j++)
        {
            if (V[j] > V[maxIdx])
                maxIdx = j;
        }
        swap(V[maxIdx], V[i]);
    }
}

template <typename T>
void fix_down(vector<T> &V, int idx, int n)
{
    T tmp = V[idx];
    int c;
    while ((c = 2 * idx + 1) < n)
    {
        if (c + 1 < n && V[c + 1] > V[c])
            c++;
        if (V[c] < tmp)
            break;
        V[idx] = V[c];
        idx = c;
    }
    V[idx] = tmp;
}

template <typename T>
void heapSort(vector<T> &V)
{
    int n = V.size();
    for (int idx = n / 2; idx >= 0; idx--)
    {
        fix_down(V, idx, n);
    }

    for (int i = n - 1; i > 0; i--)
    {
        swap(V[0], V[i]);
        fix_down(V, 0, i);
    }
}

template <typename T>
void insertionSort(vector<T> &V)
{
    int n = V.size(), j;
    T tmp;
    for (int i = n - 2; i >= 0; i--)
    {
        tmp = V[i];
        j = i + 1;
        while (j < n && V[j] < tmp)
        {
            V[j - 1] = V[j];
            j++;
        }
        V[j - 1] = tmp;
    }
}

template <typename T>
void shellSort(vector<T> &V)
{
    int n = V.size(), j;
    T tmp;
    vector<int> gaps = {701, 301, 132, 57, 23, 10, 4, 1};
    for (int &g : gaps)
    {
        for (int i = n - 1 - g; i >= 0; i--)
        {
            tmp = V[i];
            j = i + g;
            while (j < n && V[j] < tmp)
            {
                V[j - g] = V[j];
                j += g;
            }
            V[j - g] = tmp;
        }
    }
}

template <typename T>
void merge(vector<T> &V, int start, int mid, int stop, vector<T> &tmp)
{
    int left = start, right = mid + 1;
    for (int i = start; i <= stop; i++)
    {
        if (left > mid)
        {
            tmp[i] = V[right++];
            continue;
        }
        if (right > stop)
        {
            tmp[i] = V[left++];
            continue;
        }
        tmp[i] = (V[left] < V[right]) ? V[left++] : V[right++];
    }
    for (int j = start; j <= stop; j++)
        V[j] = tmp[j];
}

template <typename T>
void mergeSort(vector<int> &V, int start, int stop, vector<T> &tmp)
{
    if (start >= stop)
        return;
    int mid = (start + stop) / 2;
    mergeSort(V, start, mid, tmp);
    mergeSort(V, mid + 1, stop, tmp);
    merge(V, start, mid, stop, tmp);
}

template <typename T>
int partition(vector<T> &V, int start, int stop)
{
    int left = start - 1, right = stop + 1;
    T pivot = V[start];
    while (left < right)
    {
        while (V[++left] < pivot)
        {
        }
        while (V[--right] > pivot)
        {
        }
        if (left < right)
            swap(V[left], V[right]);
    }
    swap(V[start], V[right]);
    return right;
}

template <typename T>
void quickSort(vector<T> &V, int start, int stop)
{
    if (start >= stop)
        return;
    int p = partition(V, start, stop);
    quickSort(V, start, p);
    quickSort(V, p + 1, stop);
}

template <typename T>
void printVector(vector<T> V)
{
    for (int &v : V)
        cout << v << " ";
    cout << "\n";
}

int main()
{
    vector<int> v;
    for (int i = 100; i >= 0; i--)
        v.push_back(i);
    vector<int> tmp(v.size());
    printVector(v);
    //mergeSort(v, 0, v.size() - 1, tmp);
    quickSort(v, 0, v.size() - 1);
    printVector(v);
    return 0;
}