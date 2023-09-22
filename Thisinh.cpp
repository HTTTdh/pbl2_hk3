#include <iostream>
#include <string.h>
#include "ThiSinh.h"

using namespace std;
ThiSinh::ThiSinh(string cccd, string name, Date date, string address, int gt, string sbd, double to, double li, double ho) : Person(cccd, name, date, address, gt)
{
    this->sbd = sbd;
    this->to = to;
    this->li = li;
    this->ho = ho;
}
void ThiSinh::setsbd(string sbd)
{
    this->sbd = sbd;
}
string ThiSinh::getsbd()
{
    return sbd;
}
void ThiSinh::setto(double to)
{
    this->to = to;
}
double ThiSinh::getto()
{
    return to;
}
void ThiSinh::setli(double li)
{
    this->li = li;
}
double ThiSinh::getli()
{
    return li;
}
void ThiSinh::sethoa(double hoa)
{
    this->ho = hoa;
}
double ThiSinh::gethoa()
{
    return ho;
}
void ThiSinh::input()
{
    cout << "nhap so bao danh: ";
    getline(cin, sbd);
    cout << "nhap diem toan: ";
    cin >> to;
    cout << "nhap diem ly: ";
    cin >> li;
    cout << "nhap diem hoa: ";
    cin >> ho;
}

void ThiSinh::display()
{
    cout << "tên: " << getname() << endl;
    cout << "cccd: " << getcccd() << endl;
    cout << "ngày sinh: " << getdate().day << "/" << getdate().month << "/" << getdate().year << endl;
    cout << "địa chỉ: " << getaddress() << endl;
    cout << "giới tính: " << getgt() << endl;
}
