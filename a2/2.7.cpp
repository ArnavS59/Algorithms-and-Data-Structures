
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <map>
using namespace std;

int main()
{
  ifstream input;
  map<string, string> mymap;
  input.open("data.txt");
  string name;
  string bdate;
  while (!input.eof())
  {
    getline(input, name);
    getline(input, bdate);
    mymap.insert(pair<string, string>(name, bdate));
  }

  map<string, string>::iterator it;

  for (it = mymap.begin(); it != mymap.end(); it++)
  {
    cout << it->first << " " << it->second << endl;
  }
  string newname;
  cout << "Enter a name" << endl;
  getline(cin, newname);

  if (mymap.find(newname) == mymap.end())
  {
    cout << "Name not found!" << endl;
  }
  else
  {
    cout << "Name found" << endl;
    cout << mymap.find(newname)->second;
  }

  return 0;
}
