#include "Access.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <map>

using namespace std;
void Access::activate(unsigned int code,unsigned int level)
{
    mymultimap.insert(pair<int, int>(code, level));
}

void Access::deactivate(unsigned int code)
{
    mymultimap.erase(code);
}

bool Access::isactive(unsigned int code, unsigned int level) const
{
if(mymultimap.find(code)==mymultimap.end()){
        cout << "Code doesn't even exist" << endl;
        return false;
}
else
{
        if (mymultimap.find(code)->second >= level)//sign
        {
            cout << "Access granted" << endl;
            return true;
        }
        else
        {
            cout << "Access level is less" << endl;
            return false;
        }
    
}

}