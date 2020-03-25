#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;

void Bucketsort(vector < int > & arr, int power) {
  if (power == 0) {
    return; //base condition
  } else {
    vector < int > bucket[10];
    for (int i = 0; i < arr.size(); i++) {
      int pos = (arr[i] / power) % 10; //inserting elements into the buckets
      bucket[pos].push_back(arr[i]);
    }
    for (int i = 0; i < 10; i++) {
      if (bucket[i].size() > 1) { //if a bucket has more than one element then we move to the right and check the second digit by calling recursivly
        Bucketsort(bucket[i], power / 10);
      }
    }
    //concatenation
    int index = 0;
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < bucket[i].size(); j++) {
        arr[index++] = bucket[i][j];
      }
    }
  }
}

void Radixsort(vector < int > & arr) {
  int maxnum = arr[0];
  for (int i = 1; i < arr.size(); i++) {
    if (arr[0] < arr[i]) {
      maxnum = arr[i];
    }
  }
  int power = 1;
  while (maxnum / power >= 10) { //starting from max number to find the highest power 
    power = power * 10;
  }

  Bucketsort(arr, power);
}

int main() {
  int n;
  cout << "Enter the size of array" << endl;
  cin >> n;
  vector < int > arr(n);
  cout << "Enter the values: " << endl;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  Radixsort(arr);
  cout << "Sorted array is: " << endl;
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}