#include <cstring>
#include <iostream>
#include <vector>
using namespace std;


int main(){
string word;
vector<string> vecwords(0);

do
{
getline(cin,word);//reading
vecwords.push_back(word);
} while (word!="END");

vecwords.pop_back();//popping out the last element from the vector which is our END

cout<<"Printing from the index operator"<<endl;
for (int i=0; i<vecwords.size();i++){
    cout<<vecwords[i]<<" ";
}


vector<string>::iterator siter;//declaring iterator
cout<<endl;
cout<<"Printing from the corresponding iterator"<<endl;
for ( siter = vecwords.begin() ; siter!= vecwords.end(); ++siter ) 
{
 cout << *siter;
 if (siter!=vecwords.end()-1) cout << ',';//last comma shoudnt be there
 }
    return 0;
}
