#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int main(){
string word;
vector<string> vecwords(0);

while(word!="END"){
getline(cin,word);
vecwords.push_back(word);
 }
 vecwords.pop_back();//popping the last element which is END
 
 cout<<"Before doing anything our vector is"<<endl;
for (int i=0; i<vecwords.size();i++){
     cout<<vecwords[i]<<" ";
 }

cout<<endl;
 cout<<"After swaping the second at the fifth element"<<endl;

 if(vecwords.size()>=4){
     string temp;
temp=vecwords.at(1);
vecwords.at(1)=vecwords.at(4);
vecwords.at(4)=temp;
 }
 else
 {
     cout<<"second and fith elements do not exist"<<endl;
 }
 for (int i=0; i<vecwords.size();i++){
     cout<<vecwords[i]<<" ";
 }
 
int size=vecwords.size();

cout<<endl;
vecwords[vecwords.size()-1]="???";
cout<<"After changing the last element to ??? and adding the semicolons and printing with index operator"<<endl;
for (int i=0; i<vecwords.size();i++){
    cout<<vecwords[i];
    if(i!=size-1) 
    cout<<',';
}

  vector<string>::iterator siter;

cout<<endl;
cout<<"After putting the semicolons and printing with iterator"<<endl;
for ( siter = vecwords.begin() ; siter!= vecwords.end(); ++siter ) 
 {
  cout << *siter;
  if (siter!=vecwords.end()-1) cout << ';';
 }

cout<<endl;
cout<<"After reversing the vector object is"<<endl;
 vector<string>::iterator reviter;
for ( reviter = vecwords.end()-1 ; reviter!= vecwords.begin();--reviter ) 
{
  cout << *reviter;
  if (reviter!=vecwords.begin()) cout <<' ';
  }
    return 0;
}
