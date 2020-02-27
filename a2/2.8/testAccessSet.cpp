#include <iostream>
#include <cstdlib>
#include <fstream>
#include <map>
#include "Access.h"
using namespace std;

int main()
{
    Access a;
    a.activate(1234, 1);
    a.activate(9999, 5);
    a.activate(9876, 9);
cout<<"Please Enter the code"<<endl;
unsigned int code;
while(cin>>code){
    if(a.isactive(code, 5)==true){

        break;
    }
}
a.deactivate(code);
a.deactivate(9999);
a.activate(9999,8);
a.activate(1111,7);

while(cin>>code){
    if(a.isactive(code, 7)==true){
        break;
    }
}



    return 0;
}