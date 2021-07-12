#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void selectionSort(vector<T> &v)
{
    for (int i = v.size() - 1; i > 0; i--)
    {
        int maxIdx = i;
        for (int j = 0; j < i; j++)
        {
            if (v[j] > v[maxIdx])
                maxIdx = j;
        }
        swap(v[i], v[maxIdx]);
    }
} // big theta n**2

// ----------------------------------------------------------------

template <typename T>
void fix_down(vector<T> &v, int idx, int &n)
{
    T tmp = v[idx];
    int c;
    while ((c = 2 * idx + 1) < n)
    {
        if (c + 1 < n && v[c] < v[c + 1])
            c++;
        if (v[c] < tmp)
            break;
        v[idx] = v[c];
        idx = c;
    }
    v[idx] = tmp;
}

template <typename T>
void heapSort(vector<T> &v)
{
    int n = v.size();
    for (int i = n / 2; i >= 0; i--)
        fix_down(v, i, n);
    for (int j = n - 1; j > 0; j--)
    {
        swap(v[0], v[j]);
        fix_down(v, 0, j);
    }
} // O(nlg(n))

//---------------------------------------------------------

template <typename T>
void insertionSort(vector<T> &v)
{
    for (int i = v.size() - 2; i >= 0; i--)
    {
        T tmp = v[i];
        int j = i + 1;
        for (; j < v.size(); j++)
        {
            if (tmp < v[j])
                break;
            v[j - 1] = v[j];
        }
        v[j - 1] = tmp;
    }
} // O(n**2)

//---------------------------------------------------------------

template <typename T>
void shellSort(vector<T> &v)
{
    int n = v.size();
    vector<int> gaps = {701, 301, 132, 57, 23, 10, 4, 1};
    for (int &g : gaps)
    {
        for (int i = n - 1 - g; i >= 0; i--)
        {
            T tmp = v[i];
            int j = i + g;
            for (; j < n; j += g)
            {
                if (tmp < v[j])
                    break;
                v[j - g] = v[j];
            }
            v[j - g] = tmp;
        }
    }
} // time complexity is vary, depends on g in gaps

//------------------------------------------------------------------

template <typename T>
void merge(vector<T> &v, int &start, int &mid, int &stop, vector<T> &tmp)
{
    int left = start, right = mid + 1;
    for (int i = start; i <= stop; i++)
    {
        if (left > mid)
        {
            tmp[i] = v[right++];
            continue;
        }
        if (right > stop)
        {
            tmp[i] = v[left++];
            continue;
        }
        tmp[i] = (v[left] < v[right]) ? v[left++] : v[right++];
    }
    for (int j = start; j <= stop; j++)
        v[j] = tmp[j];
}

template <typename T>
void mergeSort(vector<T> &v, int start, int stop, vector<T> &tmp)
{
    if (start >= stop)
        return;
    int mid = (start + stop) / 2;
    mergeSort(v, start, mid, tmp);
    mergeSort(v, mid + 1, stop, tmp);
    merge(v, start, mid, stop, tmp);
} // big theta nlg(n)

//-------------------------------------------------------------------------------

template <typename T>
int partition(vector<T> &v, int start, int stop)
{
    T pivot = v[start];
    int left = start - 1, right = stop + 1;
    while (left < right)
    {
        while (v[++left] < pivot)
        {
        }
        while (v[--right] > pivot)
        {
        }
        if (left < right)
            swap(v[left], v[right]);
    }
    return right;
}

template <typename T>
void quickSort(vector<T> &v, int start, int stop)
{
    if (start >= stop)
        return;
    int p = partition(v, start, stop);
    quickSort(v, start, p);
    quickSort(v, p + 1, stop);
} //  worst case is O(n**2), average case is big theta nlg(n)

//------------------------------------------------------------

int main()
{
    vector<int> v;
    for (int i = 100; i >= 0; i--)
        v.push_back(i);
    vector<int> tmp(v.size());
    for (int &a : v)
        cout << a << " ";
    cout << "\n--------------------------------\n";
    quickSort(v, 0, v.size() - 1);
    for (int &a : v)
        cout << a << " ";
    return 0;
}