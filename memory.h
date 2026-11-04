#include <iostream>
#include<string>
#include <vector>
using namespace std;



/// @brief 
class memory{

  vector<string> cells;
  public: 
  string getcell( string address);
  void setcell(string address, string value);
  void clear();
  void size();

};
