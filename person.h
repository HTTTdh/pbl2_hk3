#ifndef Person_h
#define Person_h
#include<iostream>
#include<string.h>

using namespace std;

class Person {
    protected:
    string name;
    string  address;
    public:
    Person();
    Person(string name,string address) ;
    void setname(string name);
    string getname();   
    void setaddress(string address);
    string getaddress();
   void input();
};
#endif