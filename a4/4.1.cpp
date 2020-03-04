#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <chrono>
#include <fstream>
#include <time.h>
#include <algorithm>
using namespace std::chrono;
using namespace std;
void insertion_sort(int arr[], int l, int r)
{
    for (int i = l; i <= r; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while ((j >= l) && (arr[j] > key))
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int temp[], int l, int m, int r)
{
    int i = l;
    int j = m + 1;
    int k = l;
    while ((i <= m) && (j <= r))
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (j <= r)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }

    while (i <= m)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }

    for (i = l; i <= r; i++)
        arr[i] = temp[i];
}

void merge_sort(int arr[], int temp[], int l, int r, int k)
{
    if (l < r)
    {
        if ((r - l) <= k)
            insertion_sort(arr, l, r);
        else
        {
            int m = (l + r) / 2;
            merge_sort(arr, temp, l, m, k);
            merge_sort(arr, temp, m + 1, r, k);
            merge(arr, temp, l, m, r);
        }
    }
}

int main()
{
    ofstream output;
    output.open("output.txt");
    srand(time(NULL));
    int size=1000;
    int k = 0;
    for (k = 0; k <= 1000; k += 10)
    {
        int *arr = new int[size];
        int *arr2 = new int[size];
        int *arr3 = new int[size];
        for (int i = 0; i < size; i++)
        {
            int x = rand() % size + 1;
            arr[i] = x;
            arr2[i] = i;
            arr3[i] = size-i;
        }
        int *temp = new int[size];

        auto start1 = std::chrono::steady_clock::now(); //Average case
        merge_sort(arr, temp, 0, size - 1, k);
        auto finish1 = steady_clock::now();
        double average = duration_cast<microseconds>(finish1 - start1).count();
        
        delete[] arr;

        sort(arr2, arr2 + size);
        auto start2 = std::chrono::steady_clock::now(); //best case
        merge_sort(arr2, temp, 0, size - 1, k);
        auto finish2 = steady_clock::now();
        double best = duration_cast<microseconds>(finish2 - start2).count();
        
        delete[] arr2;

        auto start3 = std::chrono::steady_clock::now(); //worst case
        merge_sort(arr3, temp, 0, size - 1, k);
        auto finish3 = steady_clock::now();
        double worst = duration_cast<microseconds>(finish3 - start3).count();
        
        delete[] arr3;

        cout << k << " " << best << " " << average << " " << worst << endl;

        output << k << " " << best << " " << average << " " << worst << endl;
    }
    output.close();
    return 0;
}