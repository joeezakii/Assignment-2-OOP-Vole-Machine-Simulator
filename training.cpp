#include <iostream>
#include <array>
using namespace std;

void prevnext( int x, int &prev, int &next ) {
    prev = x - 1;
    next = x + 1;
}

int main() {
    int c=100,y,z;
    prevnext(c,y,z);
    cout<<"previous="<<y<<", next="<<z<<endl;
    
    
    return 0;
}