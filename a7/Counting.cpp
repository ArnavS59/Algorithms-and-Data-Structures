#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void counting_sort(int A[], int B[], int n, int k)
{
	int C[k];

	for (int i = 0; i < k; i++)
	{
		C[i] = 0;	// Initializing the count array eith 0's
	}
	for (int j = 0; j < n; j++)
	{
		C[A[j]] = C[A[j]] + 1;	// counting the number of occurences the value at
		// index corresponds to the the number of occurences
		// at that index
	}

	for (int i = 1; i < k; i++)
	{
		C[i] += C[i - 1];	// cumilativly adding such that we find the last position
		// of that element, the last position that the element
		// can appear is  at ...... number of elements are less
		// than equal to me..
	}

	for (int j = n; j >= 1; j--)
	{
		B[C[A[j]]] = A[j];
		C[A[j]] = C[A[j]] - 1;	// Reducing the occurence, needed for repitions, 		// cuz now after inserting there are -1 numbers less
		// than equal to that number
	}
}

int main()
{
	int A[7] = { 9, 1, 6, 7, 6, 2, 1 };
	int B[7];	// Output array
	int Range = 9;
	cout << "Unsorted array is" << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << A[i];
	}
	counting_sort(A, B, 7, Range);
	cout << endl;
	cout << "After sorting we get" << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << B[i];
	}
	return 0;
}