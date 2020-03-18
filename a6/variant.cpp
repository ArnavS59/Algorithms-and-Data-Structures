#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <chrono>
#include <time.h>
#include <fstream>
using namespace std::chrono;
using namespace std;

void maxHeapify(int arr[], int length, int i)
{
    int largest;           
    int left = 2 * i + 1;  //Formula for calculating the left node
    int right = 2 * i + 2; //formula for calculating the right node
    if (left < length && arr[left] > arr[i])
    {
        largest = left;
    }
    else
    {
        largest = i;
    }

    if (right < length && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    { //swapping happening
        swap(arr[i], arr[largest]);
        maxHeapify(arr, length, largest);
    }
}

void buildMaxHeap(int arr[], int length)
{
    int Hsize = length;
    for (int i = length / 2; i >= 0; i--)
    {
        maxHeapify(arr, length, i);
    }
}

void checkup(int arr[], int pos)
{
    int parent = (pos - 1) / 2;
    if (arr[parent] < arr[pos]) //if the given node is greater than the parent node then swap
    {
        swap(arr[pos], arr[parent]);
        checkup(arr, parent); //Keep doing this recursivly till u find the right position upwards
    }
}

int shift_down(int arr[], int length, int i)
{
    int largest = i;      //
    int left = 2 * i + 1; //Formula for calculating the left node
    int right = 2 * i + 2;
    if (left >= length) //base case
        return i;
    if (right >= length)
    {
        swap(arr[i], arr[left]);
        return left;
    }

    if (arr[left] > arr[right]) //find which is greater
    {
        swap(arr[i], arr[left]);
        largest = left; // if left is greater swap
    }
    else
    {
        swap(arr[i], arr[right]);
        largest = right; //right is greater swap
    }
    return shift_down(arr, length, largest);
}

void Heapsort_variant(int arr[], int length)
{
    buildMaxHeap(arr, length);
    for (int i = length - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        int leaf = shift_down(arr, i-1, 0);
        checkup(arr, leaf);
    }
}

int main()
{
    ofstream output;
    output.open("output2.txt");
    srand(time(NULL));
    int size;
        for (size = 0; size <= 100000; size += 500)
        {
            int *arr = new int[size];
            for (int i = 0; i < size; i++)
            {
                int x = rand() % size + 1;
                arr[i] = x;
            }
            auto start1 = std::chrono::steady_clock::now(); //Average case
             Heapsort_variant(arr, size);
            auto finish1 = steady_clock::now();
            double average = duration_cast<microseconds>(finish1 - start1).count();
            output<<size<<" "<<average<<endl;
     }
    return 0;
}
