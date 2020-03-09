#include <iostream>
#include <cstdlib>
#include <math.h>
#include <chrono>
#include <fstream>
#include <ctime>
using namespace std::chrono;
using namespace std;

int naive(int n)
{
    if (n < 2)
    {
        return n;
    }
    else
    {
        return naive(n - 1) + naive(n - 2);
    }
}

int bottomup(int nelem)
{
    int* arr = new int[nelem];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i < nelem; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[nelem];
}

int closedform(int n)
{
    return round(pow(((1 + sqrt(5)) / 2), n) / sqrt(5)); 
}

int matrixmulti(int n)
{
    int arr[2][2];
    arr[0][0] = 0;
    arr[0][1] = 1;
    arr[1][0] = 1;
    arr[1][1] = 1;
    int temp[2][1];
    temp[0][0] = 0;
    temp[1][0] = 1;
    int temp1;
    int temp2;
    for (int i = 1; i <= n; i++)
    {
        temp1 = temp[0][0];
        temp2 = temp[1][0];
        temp[0][0] = (arr[0][0] * temp1) + (arr[0][1] * temp2);
        temp[1][0] = (arr[1][0] * temp1) + (arr[1][1] * temp2);
    }
    return temp[0][0];
}

int main()
{
    ofstream out1;
    out1.open("naive.txt");
    ofstream out2;
    out2.open("bottom.txt");
    ofstream out3;
    out3.open("closed.txt");
    ofstream out4;
    out4.open("matrix.txt");
    double time1;
    long long int element = 1;
    clock_t begin, end;
    do
    {
        begin = clock(); //naive
        naive(element);
        end = clock();
        time1 = (double)(end - begin) / CLOCKS_PER_SEC;
        out1 << element << " " << time1 << endl;
        element += element + element / 2;
    } while (time1 < 1);

    out1.close();

   element =1; //bottom up
    do
    {
        begin = clock();
        bottomup(element);
        end = clock();
        time1 = (double)(end - begin) / CLOCKS_PER_SEC;
        out2<<element<<" "<<time1<< endl; 
        element += element + element/2;
    } while (time1 < 1);

    out2.close();
    element = 1;

    do //closed form
    {
        begin = clock();
        closedform(element);
        end = clock();
        time1 = (double)(end - begin) / CLOCKS_PER_SEC;
        out3 <<element<<" "<<time1 << endl;
        element+=element+element/2;
    } while (time1 < 1);
   out3.close();

    element = 1;

    do                  //matrix
    {
        begin = clock();
        matrixmulti(element);
        end = clock();
        time1 = (double)(end - begin) / CLOCKS_PER_SEC;
        out4<<element<<" "<<time1<<endl;
        element+=element+element/2;
    } while (time1 < 1);
    out4.close();
}
//Note: If your run the programm you will be stuck for a very long time cuz, closed form will take a very long time, therfore the values were taken by running one method at one time by commenting.