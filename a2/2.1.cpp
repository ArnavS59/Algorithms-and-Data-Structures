#include <iostream>
#include <cstring>
#include <list>
#include <vector>
#include <fstream>

using namespace std;

int main(){

list <int>list_a;
list <int>list_b;
int x;
cin>>x;
while(x>0){
list_a.push_back(x);
list_b.push_front(x);
cin>>x;
}

// list_a.pop_back();//removing the negative number 
// list_b.pop_front();

list <int >:: iterator iter; 
cout<<"Printing out list A from iterator"<<endl;
for(iter=list_a.begin();iter!=list_a.end();iter++){
    cout<<*iter<<" ";
}
cout<<endl;
ofstream output;

cout<<"Just printed out list b in output.txt file"<<endl; 
output.open("output.txt");
for(iter=list_b.begin();iter!=list_b.end();iter++){
output<<*iter<<" ";
}
    
cout<<endl;

cout<<"Moving the first element of list A into the last position"<<endl;
list_a.splice(list_a.end(),list_a,list_a.begin());
cout<<endl;
cout<<"List A with a coma"<<endl;
for(iter=list_a.begin();iter!=list_a.end();iter++){
cout<<*iter;
if(*iter !=list_a.back()){
     cout<<",";
     
 }
}

cout<<endl;

cout<<"Moving the first element of list B into the last position"<<endl;
list_b.splice(list_b.end(),list_b,list_b.begin());

for(iter=list_b.begin();iter!=list_b.end();iter++){
cout<<*iter;
if(*iter !=list_b.back()){
     cout<<",";
     
 }
}

cout<<endl;

list_a.sort();
list_b.sort();
list_a.merge(list_b);

cout<<"Printing the two merged list together"<<endl;
for(iter=list_a.begin();iter!=list_a.end();iter++){
cout<<*iter<<" ";
}

    return 0;
}