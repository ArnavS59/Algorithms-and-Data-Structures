#include <iostream>
#include <cstdlib>
#include <set>
#include <algorithm>
#include "Access.h"
using namespace std;

void Access::activate(unsigned int code)
{
    key.insert(code);
}

void Access::deactivate(unsigned int code)
{
    key.erase(code);
}
bool Access::isactive(unsigned int code)
{
    if (key.find(code) == key.end())
    {
        cout << "Access not granted try again" << endl; //it points to the last element of the set if it is not found in the set
        return false;
    }
    else
    {
        cout << "Access granted" << endl;
        return true;
    }
}
