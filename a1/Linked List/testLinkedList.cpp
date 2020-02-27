#include <cstring>
#include <iostream>
#include <list>
#include "linked_list.h"

using namespace std;


int main()
{
    double_list<int> list1;
    cout<<"Just pushed 4 elements into list"<<endl;
    list1.push_front(1);
    list1.push_end(2);
    list1.push_front(5);
    list1.push_front(3);
     cout<<"Number of elements are currently"<<endl;
   cout<< list1.numElem()<<endl;
    list1.pop_front();
    list1.pop_front();
    cout<<"Just popped two elements"<<endl;
    cout<<"Number of elements are currently"<<endl;
   cout<< list1.numElem()<<endl;//number of elems remaining 
    cout<<"Returning the first element"<<endl;
    cout<<list1.return_first()<<endl;
    cout<<"Returning the last element"<<endl;
    cout<<list1.return_last()<<endl;

        return 0;
}