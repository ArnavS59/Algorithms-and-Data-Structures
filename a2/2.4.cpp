#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main()
{

    vector<int> vec;

    for (int i = 1; i <= 30; i++)
    {
        vec.push_back(i);
    }

    vec.push_back(5);

    reverse(vec.begin(), vec.end());
    cout << "After reversing the vector" << endl;
    vector<int>::iterator iter;
    for (iter = vec.begin(); iter != vec.end(); iter++)
        cout << *iter << " ";
    cout << endl;
    cout << endl;
    cout << "After replacing the values of the vector" << endl;
    replace(vec.begin(), vec.end(), 5, 129);
    for (iter = vec.begin(); iter != vec.end(); iter++)
        cout << *iter << " ";

    return 0;
}
