#include <iostream>
#include<string>
#include <vector>
using namespace std;



/// @brief 
class memory{

  vector<string> cells[256];
  public: 
  string getcell( string address);
  void setcell(string address, string value);
  void clear();
  void size();

};