#ifndef Person_h
#define Person_h
#include<iostream>
#include<string.h>

using namespace std;

struct Date {
    int day,month,year;
};

class Person {
    private:
    string cccd;
    string name;
    Date date;
    string  address;
    int gt;
    public:
    Person();
    Person(string cccd, string name, Date date, string address, int gt) ;
    void setcccd(string cccd);
    string getcccd();
    void setname(string name);
    string getname();
    void setdate(Date date);
    Date getdate();
    void setaddress(string address);
    string getaddress();
    void setgt(int gt);
    int getgt();
    void nhapthongtin();
};
#endif
