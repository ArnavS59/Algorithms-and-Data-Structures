#include <iostream>
#include <cstring>
#include <ctime>
#include <chrono>
#include <fstream>
#include <algorithm>
using namespace std;
using namespace std::chrono;

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(int arr[], int size)
{
    int j;
    int min_index;

    for (int i = 0; i < size - 1; i++)
    {
        min_index = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        Swap(&arr[min_index], &arr[i]);
    }
}

int main()
{
    ofstream output;
    output.open("Output.txt");
    int size;
    srand(time(NULL));
    for (size = 0; size <= 1000; size += 10)
    {

        int *arr = new int[size];
        int *arr2 = new int[size];
        int *arr3 = new int[size];

        //Randomizing the 3 arrays for the best, worst, and average case
        for (int i = 0; i < size; i++)
        {
            int x = rand() % size + 1;
            arr[i] = x;
            arr2[i] = x;
            arr3[i] = x;
        }
        //FOR THE WORST CASE
        arr[0] = size; //first element becomes the size, i.e last element

        auto start = high_resolution_clock::now();
        SelectionSort(arr, size);
        auto stop = high_resolution_clock::now();
        auto worst = duration_cast<microseconds>(stop - start);

        //FOR THE BEST CASE

        sort(arr2, arr2 + size);

        auto start2 = high_resolution_clock::now();
        SelectionSort(arr2, size);
        auto stop2 = high_resolution_clock::now();
        auto best = duration_cast<microseconds>(stop2 - start2);

        //FOR THE AVERAGE CASE

        auto start3 = high_resolution_clock::now();
        SelectionSort(arr3, size);
        auto stop3 = high_resolution_clock::now();
        auto avg = duration_cast<microseconds>(stop3 - start3);
        cout << size << " " << worst.count() << " " << avg.count() << " " << best.count() << endl;
        output << size << " " << worst.count() << " " << avg.count() << " " << best.count() << endl;
    }
}
