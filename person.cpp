#include "person.h"
#include <iostream>
#include <string.h>

using namespace std;
Person:: Person(){};
Person::Person( string name, string address)
{
    this->name = name;
    this->address = address;
}
void Person::setname(string name)
{
    this->name = name;;
}
string Person::getname()
{
    return name;
}
void Person::setaddress(string address)
{
    this->address =address;
}
string Person::getaddress()
{
    return address;
}
void Person:: input()
{
    fflush(stdin);
    cout << "ten: ";
    getline(cin, name);
    cout << "dia chi: ";
    getline(cin, address);
}