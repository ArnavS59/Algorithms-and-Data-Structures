#include <iostream>
#include <deque>


using namespace std;
class WindGauge
{
private:
deque <int> deq;
int newperiod;
public:
    WindGauge(int period = 12);
    void currentWindSpeed(int speed);
    int highest() const;
    int lowest() const;
    int average() const;
    void dump();
};