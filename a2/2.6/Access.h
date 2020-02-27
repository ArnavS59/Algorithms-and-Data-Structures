#include <iostream>
#include <cstdlib>
#include <set>
#include <algorithm>
using namespace std;

class Access
{
private:
    set<unsigned int> key;

public:
    void activate(unsigned int code);
    void deactivate(unsigned int code);
    bool isactive(unsigned int code);
};