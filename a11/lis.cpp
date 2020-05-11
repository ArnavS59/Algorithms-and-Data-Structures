#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

void printLIS(vector<int> &arr)
{
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}

void constructPrintLIS(int arr[], int n)
{
    vector<vector<int>> L(n);
    L[0].push_back(arr[0]);
    // start from index 1
    
    for (int i = 1; i < n; i++)
    {
        // do for every j less than i
        for (int j = 0; j < i; j++)
        {
            /* L[i] = {Max(L[j])} + arr[i] 
            where j < i and arr[j] < arr[i] */
            if ((arr[i] > arr[j]) &&
                (L[i].size() < L[j].size()))
                L[i] = L[j];
        }

        // L[i] ends with arr[i]
        L[i].push_back(arr[i]);
    }

    // L[i] now stores increasing sub-sequence of
    // arr[0..i] that ends with arr[i]
    vector<int> max = L[0];

    // LIS will be max of all increasing sub-
    // sequences of arr
    for (vector<int> x : L)
        if (x.size() > max.size())
            max = x;

    // max will contain LIS
    printLIS(max);
}

int main()
{
    int arr[] = {8, 3, 6, 50, 10, 8, 100, 30, 60, 40, 80};
    int n = sizeof(arr) / sizeof(arr[0]);

    constructPrintLIS(arr, n);

    return 0;
}