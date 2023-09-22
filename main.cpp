#include<iostream>
#include<string.h>
#include"ThiSinh.cpp"
#include"linklist.cpp"
using namespace std;

int main()
{
    LinkedList danhsach;
    ThiSinh ts;
    ts.input();
    danhsach.insert(ts);
    cout << "thong tin: ";
    danhsach.display();
    return 0;
}
