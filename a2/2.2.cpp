#include <iostream>
#include <cstring>
#include <fstream>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{

    deque<float> deq;
    int x;
    while (cin >> x)
    {
        if (x == 0)
            break;
        else if (x > 0)
            deq.push_back(x);
        else
            deq.push_front(x);
    }
    cout << "Deque A" << endl;
    for (int i = 0; i < deq.size(); i++)
    {
        cout << deq[i] << " ";
    }
    cout << endl;

    deque<float>::iterator iter;

    iter = deq.begin();
    while (*iter < 0 && iter < deq.end())
    {
        iter++;
    }
    deq.insert(iter, 0);
    cout << "Deque A with semi colons" << endl;
    for (int i = 0; i < deq.size(); i++)
    {

        cout << deq[i];
        if (i != deq.size() - 1)
            cout << ";";
    }
    cout << endl;
    return 0;
}