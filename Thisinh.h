#ifndef ThiSinh_h
#define ThiSinh_h
#include<iostream>
#include<string>
#include"person.h"
 
using namespace std;

class ThiSinh : public Person {
    private:
    string sbd;
    double to,li,ho;
    public:
    ThiSinh();
    ThiSinh(string cccd, string name, Date date, string address, int gt, string sbd, double to, double li, double ho);
    void setsbd(string sbd);
    string getsbd();
    void setto(double to);
    double getto();
    void setli(double li);
    double getli();
    void sethoa(double hoa);
    double gethoa();
    void input();
    void display();
};
#endif   
