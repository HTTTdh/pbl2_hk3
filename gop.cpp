#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

struct Date
{
    int day, month, year;
};

class Person
{
private:
    string cccd;
    string name;
    Date date;
    string address;
    int gt;

public:
    Person();
    Person(string cccd, string name, Date date, string address, int gt);
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
    void hienthi();
};

Person::Person()
{
    cccd = "";
    name = "";
    date.day = 0;
    date.month = 0;
    date.year = 0;
    address = "";
    gt = 0;
}
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
    this->name = name;
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
    this->address = address;
}
string Person::getaddress()
{
    return address;
}

void Person::setgt(int gt)
{
    this->gt = gt;
}
int Person::getgt()
{
    return gt;
}

void Person::nhapthongtin()
{
    fflush(stdin);
    cout << "nhap ho ten: ";
    getline(cin, name);
    cout << "nhap so cccd: ";
    getline(cin, cccd);
    cout << "nhap ngay: ";
    cin >> date.day;
    cout << "nhap thang: ";
    cin >> date.month;
    cout << "nhap nam: ";
    cin >> date.year;
    cin.ignore(1);
    cout << "nhap dia chi (nhap tinh): ";
    getline(cin, address);
    cout << "nhap gioi tinh (0: Nam, 1: Nu): ";
    cin >> gt;
}
void Person::hienthi()
{
    cout << "\ntÃªn: " << name << endl;
    cout << "cccd: " << cccd << endl;
    cout << "ngÃ y sinh: " << date.day << "/" << date.month << "/" << date.year << endl;
    cout << "Ä‘á»‹a chá»‰: " << address << endl;
    cout << "giá»›i tÃ­nh: " << gt << endl;
}

class ThiSinh : public Person
{
private:
    double to;
    string sbd;
    double li, ho;

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
    void nhapsbd();
    void display();
};

ThiSinh::ThiSinh() : Person()
{
    to = 0;
    sbd = "";
    li = 0;
    ho = 0;
}
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
    nhapthongtin();
    fflush(stdin);
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
    hienthi();
    cout << "so bao danh: " << sbd << endl;
    cout << "diem toan: " << to << endl;
    cout << "diem ly: " << li << endl;
    cout << "diem hoa: " << ho << endl;
}

class node
{
public:
    ThiSinh data;
    node *next;
    node();
    node(ThiSinh ts)
    {
        data = ts;
        next = NULL;
    }
};

class LinkedList
{
private:
    node *head;

public:
    LinkedList()
    {
        head = NULL;
    }
    void insert(ThiSinh sv)
    {
        node *newNode = new node(sv);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    node *search(string sbd, string name)
    {
        node *temp = head;
        while (temp->data.getsbd() != sbd)
            temp = temp->next;
        if (temp->data.getname() == name)
            return temp;
        else
            return NULL;
    }
    bool Delete(string sbd, string name)
    {
        node *p = search(sbd, name);
        if (p != NULL)
        {
            node *pre;
            node *temp = head;
            while (p->data.getsbd() != temp->data.getsbd())
            {
                pre = temp;
                temp = temp->next;
            }
            pre->next = temp->next;
            delete (temp);
            return true;
        }
        else
            return false;
    }

    void xuat()
    {
        node *temp = head;
        while (temp != NULL)
        {
            temp->data.display();
            temp = temp->next;
        }
    }
    bool testempty()
    {
        if (head == NULL)
        {
            cout << "Danh sÃ¡ch rá»—ng.";
            return true;
        }
        else
        {
            return false;
        }
    }
    void searchinf()
    {
        int lc;
        do
        {
        system("cls");
        cout << "\n\n\t CÃC THÃ”NG TIN\n\n\t+";
        for (int i = 1; i <= 30; ++i)
            cout << "-";
            cout << "+" << endl;
        cout << "\t|   1. TÃªn              |\n" ;
        cout << "\t|" << setw(30) << "|" << endl;
        cout << "\t|   2. Äá»‹a chá»‰          |\n ";
        cout << "\t|" << setw(30) << "|" << endl;
        cout << "\t|   3. CCCD             |\n" ;
        cout << "\t|" << setw(30) << "|" << endl;
        cout << "\t|   4. SBD              |\n" ;
        cout << "\t|" << setw(30) << "|" << endl;
        cout << "\t|   5. NÄƒm sinh         |\n" ;
        cout << "\t|" << setw(30) << "|" << endl;
        cout << "\t|   6. Giá»›i tÃ­nh        |\n" ;
        cout << "\t+";
        for (int i = 1; i <= 30; ++i)
            cout << "-";
            cout << "+" << endl;
        cout << "\nMá»i nháº­p lá»±a chá»n :";
        cin >> lc;

        while (lc < 0 || lc > 6)
        {
            fflush(stdin);
            cout << "Lá»±a chá»n cá»§a báº¡n lÃ  khÃ´ng há»£p lá»‡!!! \n HÃ£y nháº­p láº¡i: ";
            cin >> lc;
        }
        switch (lc)
        {
        case 1:
           { 
            fflush(stdin);
            string name;
            node *p = head;
            cout << "nháº­p tÃªn báº¡n muá»‘n hiá»ƒn thá»‹: ";
            getline(cin, name);
            while (p->data.getname().find(name) > p->data.getname().length())
            {
                p->data.display();
                p=p->next;
            }
            system("pause");
            break;
            }
        }
        }while (lc!=false);
    }
};

void editinfor(LinkedList &ds, string sbd, string name)
{
    node *p = ds.search(sbd, name);
    string New;
    int d;
    Date date;
    cout << "~ EDIT INFORMATION ~" << endl;
    int luachon;
    do
    {
        cout << "1.Chá»‰nh sá»­a tÃªn. " << endl;
        cout << "2.Chá»‰nh sá»­a ngÃ y/thÃ¡ng/nÄƒm sinh. " << endl;
        cout << "3.Chá»‰nh sá»­a Ä‘á»‹a chá»‰. " << endl;
        cout << "4.Chá»‰nh sá»­a sá»‘ cccd. " << endl;
        cout << "5.Chá»‰nh sá»­a giá»›i tÃ­nh. " << endl;
        cout << "6.Chá»‰nh sá»­a Ä‘iá»ƒm toÃ¡n, lÃ½, hÃ³a. " << endl;
        cout << "Nháº­p lá»±a chá»n: ";
        cin >> luachon;
        while (luachon < 0 || luachon > 6)
        {
            fflush(stdin);
            cout << "Lá»±a chá»n cá»§a báº¡n lÃ  khÃ´ng há»£p lá»‡!!! \n HÃ£y nháº­p láº¡i: ";
            cin >> luachon;
        }
        switch (luachon)
        {
        case 1:
            if (ds.testempty())
            {
                cout << "ChÆ°a cÃ³ danh sÃ¡ch thÃ­ sinh dá»± thi." << endl;
            }
            else
            {
                cout << "Nháº­p láº¡i tÃªn: ";
                cin.ignore();
                getline(cin, New);
                p->data.setname(New);
            }
            break;
        case 2:
            if (ds.testempty())
            {
                cout << "ChÆ°a cÃ³ danh sÃ¡ch thÃ­ sinh dá»± thi." << endl;
            }
            else
            {
                cout << "Nháº­p láº¡i ngÃ y/thÃ¡ng/nÄƒm sinh: " << endl;
                cout << "Nháº­p ngÃ y: ";
                cin >> date.day;
                cout << "Nháº­p thÃ¡ng: ";
                cin >> date.month;
                cout << "Nháº­p nÄƒm: ";
                cin >> date.year;
                p->data.setdate(date);
            }
            break;
        case 3:
            if (ds.testempty())
            {
                cout << "ChÆ°a cÃ³ danh sÃ¡ch thÃ­ sinh dá»± thi." << endl;
            }
            else
            {
                string newAddress;
                cout << "Nháº­p Ä‘á»‹a chá»‰ má»›i: ";
                cin.ignore();
                getline(cin, newAddress);
                p->data.setaddress(newAddress);
            }
            break;
        case 4:
            if (ds.testempty())
            {
                cout << "ChÆ°a cÃ³ danh sÃ¡ch thÃ­ sinh dá»± thi." << endl;
            }
            else
            {
                string newCCCD;
                cout << "Nháº­p sá»‘ CCCD má»›i: ";
                cin.ignore();
                getline(cin, newCCCD);
                p->data.setcccd(newCCCD);
            }
            break;
        case 5:
            if (ds.testempty())
            {
                cout << "ChÆ°a cÃ³ danh sÃ¡ch thÃ­ sinh dá»± thi." << endl;
            }
            else
            {
                int newgt;
                cout << "Nháº­p giá»›i tÃ­nh má»›i: (0: Nam, 1: Ná»¯) ";
                cin >> newgt;
                p->data.setgt(newgt);
            }
            break;
        case 6:
            if (ds.testempty())
            {
                cout << "ChÆ°a cÃ³ danh sÃ¡ch thÃ­ sinh dá»± thi." << endl;
            }
            else
            {
                double newMath, newPhysics, newChemistry;
                cout << "Nháº­p Ä‘iá»ƒm toÃ¡n má»›i: ";
                cin >> newMath;
                cout << "Nháº­p Ä‘iá»ƒm lÃ½ má»›i: ";
                cin >> newPhysics;
                cout << "Nháº­p Ä‘iá»ƒm hÃ³a má»›i: ";
                cin >> newChemistry;
                p->data.setto(newMath);
                p->data.setli(newPhysics);
                p->data.sethoa(newChemistry);
            }
            break;
        }
    } while (luachon != false);
}

int main()
{
    LinkedList danhsach;
    ThiSinh ts;
    string sbd;
    string name;
    int option;
    do
    {
        system("cls");
        cout << "\t~- QUáº¢N LÃ ÄIá»‚M THI Cá»¦A CÃC THÃ SINH VÃ€O Má»˜T TRÆ¯á»œNG Äáº I Há»ŒC -~" << endl;
        for (int i = 1; i <= 100; ++i)
            cout << "-";
        cout << "\n\n\t\t DANH SÃCH CÃC THAO TÃC\n\n\t+";
        for (int i = 1; i <= 50; ++i)
            cout << "-";
            cout << "+" << endl;
        cout << "\t|   0. ThoÃ¡t.                                      |\n" ;
        cout << "\t|" << setw(51) << "|" << endl;
        cout << "\t|   1. ThÃªm 1 thÃ­ sinh vÃ o danh sÃ¡ch.              |\n" ;
        cout << "\t|" << setw(51) << "|" << endl;
        cout << "\t|   2. XoÃ¡ 1 thÃ­ sinh khá»i danh sÃ¡ch.              |\n ";
        cout << "\t|" << setw(51) << "|" << endl;
        cout << "\t|   3. Sá»­a thÃ´ng tin 1 thÃ­ sinh.                   |\n" ;
        cout << "\t|" << setw(51) << "|" << endl;
        cout << "\t|   4. Xuáº¥t thÃ´ng tin cá»§a má»™t thÃ­ sinh.            |\n" ;
        cout << "\t|" << setw(51) << "|" << endl;
        cout << "\t|   5. TÃ¬m kiáº¿m cÃ¡c thÃ´ng tin liÃªn quan.           |\n" ;
        cout << "\t|" << setw(51) << "|" << endl;
        cout << "\t|   6. TÃ¬m kiáº¿m thÃ´ng tin cá»§a má»™t thÃ­ sinh.        |\n" ;
        cout << "\t+";
        for (int i = 1; i <= 50; ++i)
            cout << "-";
            cout << "+" << endl;
        cout << "\nMá»i nháº­p lá»±a chá»n :";
        cin >> option;

        while (option < 0 || option > 6)
        {
            fflush(stdin);
            cout << "Lá»±a chá»n cá»§a báº¡n lÃ  khÃ´ng há»£p lá»‡!!! \n HÃ£y nháº­p láº¡i: ";
            cin >> option;
        }
        switch (option)
        {
        case 0:
            break;
        case 1:
        {
            ts.input();
            danhsach.insert(ts);
            system("pause");
            break;
        }
        case 2:
        {
            cout << "nhap thong tin ban muon xoa" << endl;
            fflush(stdin);
            cout << "ten: ";
            getline(cin, name);
            cout << "sbd: ";
            getline(cin, sbd);
            if (danhsach.Delete(sbd, name) == true)
                cout << "da xoa thanh cong\n";
            else
                cout << "xoa khong thanh cong" << endl;
            system("pause");
            break;
        }
        case 3:
        {
            cout << "nhap thong tin ban muon sua" << endl;
            fflush(stdin);
            cout << "ten: ";
            getline(cin, name);
            cout << "sbd: ";
            getline(cin, sbd);
            editinfor(danhsach, sbd, name);
            cout << "hÃ£y xuáº¥t thÃ´ng tin Ä‘á»ƒ kiá»ƒm tra\n";
            system("pause");
            break;
        }
        case 4:
        {
            cout << "ThÃ´ng tin : " << endl;
            danhsach.xuat();
            system("pause");
            break;
        }
        case 5:
        {
            cout << "Báº¡n muá»‘n tÃ¬m kiáº¿m thÃ´ng qua thÃ´ng tin gÃ¬?" << endl;
            danhsach.searchinf();
            system("pause");
            break;
        }
        case 6:
        {
            node *temp;
            fflush(stdin);
            cout << "nhap sbd: ";
            getline(cin, sbd);
            cout << "nhap ten: ";
            getline(cin, name);
            temp = danhsach.search(sbd, name);
            if (temp == NULL)
                cout << "khong tim thay thong tin\n";
            else
                ts.display();
            system("pause");
            break;
        }
        }
    } while (option != false);
}
