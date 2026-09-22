#include <iostream>
#include <string>
using namespace std;

class Clients_vodafone{
    string name, package;
    int id;
    int line_number;
    float bill;
    public:
    Clients_vodafone(string n, string p, int i, int l, float b){
        name = n;
        package = p;
        id = i;
        line_number = l;
        bill = b;
    }
    void details(){
        cout << "Name: " << name << endl;
        cout << "Package: " << package << endl;
        cout << "ID: " << id << endl;
        cout << "Line Number: " << line_number << endl;
        cout << "Bill: " << bill << endl;
    }

};


