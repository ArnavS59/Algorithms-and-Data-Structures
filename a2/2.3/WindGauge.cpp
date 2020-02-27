#include "WindGauge.h"
#include <iostream>
#include <cstring>
#include <deque>
#include <algorithm>
#include <numeric>    


using namespace std;

WindGauge::WindGauge(int period) {
newperiod=period;
}


void WindGauge::currentWindSpeed(int speed){
deq.push_back(speed);
if(deq.size()>newperiod){
    deq.pop_front();
}
}

int WindGauge::highest()const{
return *max_element(deq.begin(),deq.end());
}

int WindGauge::lowest() const{
return *min_element(deq.begin(),deq.end());
}

int WindGauge::average() const{
    // int total=0;
    // int i=0;
    // for(i=0; i<deq.size();i++){
    //     total=total+deq[i];
    // }
    // return total/i;
    float a=accumulate(deq.begin(),deq.end(),0);
    return a/deq.size();
   
}

void WindGauge::dump(){
    cout<<"The highest wind speed is "<<highest()<<endl;
    cout<<"The lowest wind speed is "<<lowest()<<endl;
    cout<<"The average wind speed is "<<average()<<endl;
}



