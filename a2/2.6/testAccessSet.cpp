#include <iostream>
#include <cstdlib>
#include <set>
#include <algorithm>
#include "Access.h"
using namespace std;

int main()
{
    Access a;
    a.activate(1234);
    a.activate(9999);
    a.activate(9879);
    cout << "Please Enter the code" << endl;
    unsigned int input;

    while (cin >> input)
    {
        if (a.isactive(input) == true)
        {

            break;
        }
    }
    a.deactivate(input);
    a.deactivate(9999);
    a.activate(1111);
    while (cin >> input)
    {
        if (a.isactive(input) == true)
        {

            break;
        }
    }

    return 0;
}