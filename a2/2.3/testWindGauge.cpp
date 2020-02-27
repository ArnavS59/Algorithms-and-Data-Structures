#include "WindGauge.h"
#include <iostream>
  
using namespace std;


int main()
{
WindGauge a;
a.currentWindSpeed(15);
a.currentWindSpeed(16);
a.currentWindSpeed(12);
a.currentWindSpeed(15);
a.currentWindSpeed(15);
a.dump();
cout<<endl;
cout<<"After addding new values"<<endl;

a.currentWindSpeed(16);
a.currentWindSpeed(17);
a.currentWindSpeed(16);
a.currentWindSpeed(16);
a.currentWindSpeed(20);
a.currentWindSpeed(17);
a.currentWindSpeed(16);
a.currentWindSpeed(15);
a.currentWindSpeed(16);
a.currentWindSpeed(20);
a.dump();

return 0;




}