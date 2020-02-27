#include <iostream>
#include <cstdlib>
#include <fstream>
#include <map>
using namespace std;
class Access
{
private:
    multimap<int, int> mymultimap;

public:
    void activate(unsigned int code, unsigned int level);
    void deactivate(unsigned int code);
    bool isactive(unsigned int code, unsigned int level) const;
};
