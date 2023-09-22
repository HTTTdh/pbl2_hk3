#include "person.h"
#include <iostream>
#include <string.h>

using namespace std;
Person:: Person(){};
Person::Person(string cccd, string name, Date date, string address, int gt)
{
    this->cccd = cccd;
    this->name = name;
    this->date.day = date.day;
    this->date.month = date.month;
    this->date.year = date.year;
    this->address = address;
    this->gt = gt;
}
void Person::setcccd(string cccd)
{
    this->cccd = cccd;
}
string Person::getcccd()
{
    return cccd;
}
void Person::setname(string name)
{
    this->name = name;;
}
string Person::getname()
{
    return name;
}
void Person::setdate(Date date)
{
     this->date.day = date.day;
    this->date.month = date.month;
    this->date.year = date.year;
}
Date Person::getdate()
{
    return date;
}
void Person::setaddress(string address)
{
    this->address =address;
}
string Person::getaddress()
{
    return address;
}
void Person::setgt(int gt)
{
    this->gt=gt;
}
int Person::getgt()
{
    return gt;
}
void Person::nhapthongtin()
{
    cin.ignore(1);
        cout << "nhap ho ten: ";
        cin >> name;
        cout << "nhap so cccd: ";
        cin >> cccd;
        cout << "nhap ngay thang nam sinh: ";
        cin >> date.day >> date.month >> date.year ;
        cout << "nhap dia chi (nhap tinh): ";
        cin >> address;
        cout << "nhap gioi tinh (0: Nam, 1: Nu): ";
        cin >> gt;
}
