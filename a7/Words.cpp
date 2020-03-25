#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

int maxwordlength(string * arr, int n)
{
	int max = arr[0].length();
	for (int i = 0; i < n ; i++)
		if (arr[i].length() > max) 
			max = arr[i].length();//this function finds the max length of the array
	return max;
}

void counting_sort(string * arr, int n,int pos)
{
    int C[256] = {0};
	for (int j = 0; j < n; j++)
	{
		int i;
		if (arr[j].length() < pos)// if the word length is is different then
			i=0;
		else
			i=arr[j][pos]+1;// otherwise
		C[i] = C [i] + 1;
	}
	for (int i = 1; i < 256; i++)
		C[i] = C[i] + C[i-1];//cummalative addtion of the number of occurences
	string B[n];
	for (int j = n-1; j >= 0; j--)
	{
		int i;
		if (arr[j].length() < pos)
			i=0;
		else
			i=arr[j][pos]+1;//applying counting sort
		B[C[i]-1] = arr[j];
		C[i]--;//one less same occurence
	}
	for(int i = 0; i < n; i++)
		arr[i] = B[i];//copying it into array
}

void radix_sort(string * arr, int n)
{
	int max = maxwordlength(arr, n);
	for (int i=max-1;i>=0;i--)
		counting_sort(arr,n,i);
}

int main()
{
	string arr[] = { "Arnav", "Abhi" ,"Mahiem" ,"Mickey" ,"Orange","Orangs","Oran" };
	int n=sizeof (arr)/sizeof(arr[0]);
	radix_sort(arr, n);
	for(int i = 0; i < n; i++)
		cout << arr[i]<<" ";
	cout << endl;
}
