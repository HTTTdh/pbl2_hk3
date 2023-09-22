#include <iostream>
#include <string.h>
#include "Thisinh.h"

using namespace std;
ThiSinh::ThiSinh()
{
}
ThiSinh::ThiSinh(string name, string address, double to) : Person(name, address)
{
    this->to = to;
}
void ThiSinh::setto(double to)
{
    this->to = to;
}
double ThiSinh::getto()
{
    return to;
}
void ThiSinh::input()
{
    fflush(stdin);
    cout << "nhap diem: ";
    cin >> to;
}
