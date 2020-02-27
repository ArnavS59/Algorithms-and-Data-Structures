#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>
using namespace std;
int randomNUM()
{
    int rand_num = rand() % 49 + 1;
    return rand_num;
}

int main()
{
    set<int> lott;
    srand(time(NULL));

    while (lott.size() < 6)
    {
        lott.insert(randomNUM());
    }

    set<int>::iterator iter;
    for (iter = lott.begin(); iter != lott.end(); iter++)
    {
        cout << *iter << " ";
    }
    return 0;
}