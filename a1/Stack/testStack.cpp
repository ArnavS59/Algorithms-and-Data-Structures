
#include <iostream>
#include "Stack.h"

using namespace std;

int main(){



Stack<int> intstack(10);

 for (int i = 0; i <=9; i++){
  		 intstack.push(i);
           
 }
 cout<<endl;
    cout<<"Just pushed 10 elements into the stack"<<endl;
    cout<<"The total number of enteries are currently"<<endl;
    cout<<intstack.getNumEnteries();
    cout<<endl;
     cout<<"last element from the back function is:"<<endl;
    cout<<intstack.back();
    cout<<endl;
    int out;

    intstack.pop(out);
    cout<<"popping out this element:"<<out<<endl;
    intstack.pop(out);
    cout<<endl;
    cout<<"popping out this element:"<<out<<endl;
    cout<<endl;
    cout<<"popping out this element:"<<out<<endl;
    intstack.pop(out);
    cout<<endl;
    cout<<"popping out this element:"<<out<<endl;
    intstack.pop(out);
    cout<<endl;
    cout<<"popping out this element:"<<out<<endl;
    intstack.pop(out);
    cout<<endl;
    cout<<"popping out this element:"<<out<<endl;
    intstack.pop(out);
    cout<<endl;
    cout<<"popping out this element:"<<out<<endl;
    intstack.pop(out);
    cout<<endl;
    cout<<"popping out this element:"<<out<<endl;
    intstack.pop(out);
    cout<<endl;
    cout<<"popping out this element:"<<out<<endl;
    intstack.pop(out);
    cout<<endl;
    cout<<"popping out this element:"<<out<<endl;
    intstack.pop(out);
    cout<<endl;
    cout<<"popping out this element:"<<out<<endl;
    intstack.pop(out);
    cout<<endl;
     cout<<"The total number of enteries are currently"<<endl;
    cout<<intstack.getNumEnteries();
  
    
   

return 0;

}