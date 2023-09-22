#ifndef ThiSinh_h
#define ThiSinh_h
#include<iostream>
#include<string>
#include"person.h"
 
using namespace std;

class ThiSinh : public Person {
    private:
    double to;
    public:
    ThiSinh();
    ThiSinh( string name, string address, double to);
    void setto(double to);
    double getto();
    void input();
};
#endif 