#include <iostream>
#include <string>
#include <vector>
#include <fstream>

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
    cout << "\ntên: " << name << endl;
    cout << "cccd: " << cccd << endl;
    cout << "ngày sinh: " << date.day << "/" << date.month << "/" << date.year << endl;
    cout << "địa chỉ: " << address << endl;
    cout << "giới tính: " << gt << endl;
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

void ThiSinh::nhapsbd()
{
    cout << "nhap so bao danh: ";
    getline(cin, sbd);
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

    void display()
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
            cout << "Danh sách rỗng.";
            return true;
        }
        else
        {
            return false;
        }
    }
    void countryman(LinkedList &ds, string country){
    node *temp = head;
    while(temp-> next != NULL){
        if(temp->data.getaddress() == country){
            temp->data.display();
        }
        temp= temp->next;
    }
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
        cout << "1.Chỉnh sửa tên. " << endl;
        cout << "2.Chỉnh sửa ngày/tháng/năm sinh. " << endl;
        cout << "3.Chỉnh sửa địa chỉ. " << endl;
        cout << "4.Chỉnh sửa số cccd. " << endl;
        cout << "5.Chỉnh sửa giới tính. " << endl;
        cout << "6.Chỉnh sửa điểm toán, lý, hóa. " << endl;
        cout << "Nhập lựa chọn: ";
        cin >> luachon;
        while (luachon < 0 || luachon > 6)
        {
            fflush(stdin);
            cout << "Lựa chọn của bạn là không hợp lệ!!! \n Hãy nhập lại: " ;
            cin >> luachon;
        }
        switch (luachon)
        {
        case 1:
            if (ds.testempty())
            {
                cout << "Chưa có danh sách thí sinh dự thi." << endl;
            }
            else
            {
                cout << "Nhập lại tên: ";
                cin.ignore();
                getline(cin, New);
                p->data.setname(New);
            }
            break;
        case 2:
            if (ds.testempty())
            {
                cout << "Chưa có danh sách thí sinh dự thi." << endl;
            }
            else
            {
                cout << "Nhập lại ngày/tháng/năm sinh: " << endl;
                cout << "Nhập ngày: ";
                cin >> date.day;
                cout << "Nhập tháng: ";
                cin >> date.month;
                cout << "Nhập năm: ";
                cin >> date.year;
                p->data.setdate(date);
            }
            break;
        case 3:
            if (ds.testempty())
            {
                cout << "Chưa có danh sách thí sinh dự thi." << endl;
            }
            else
            {
                string newAddress;
                cout << "Nhập địa chỉ mới: ";
                cin.ignore();
                getline(cin, newAddress);
                p->data.setaddress(newAddress);
            }
            break;
        case 4:
            if (ds.testempty())
            {
                cout << "Chưa có danh sách thí sinh dự thi." << endl;
            }
            else
            {
                string newCCCD;
                cout << "Nhập số CCCD mới: ";
                cin.ignore();
                getline(cin, newCCCD);
                p->data.setcccd(newCCCD);
            }
            break;
        case 5:
            if (ds.testempty())
            {
                cout << "Chưa có danh sách thí sinh dự thi." << endl;
            }
            else
            {
                int newgt;
                cout << "Nhập giới tính mới: (0: Nam, 1: Nữ) ";
                cin >> newgt;
                p->data.setgt(newgt);
            }
            break;
        case 6:
            if (ds.testempty())
            {
                cout << "Chưa có danh sách thí sinh dự thi." << endl;
            }
            else
            {
                double newMath, newPhysics, newChemistry;
                cout << "Nhập điểm toán mới: ";
                cin >> newMath;
                cout << "Nhập điểm lý mới: ";
                cin >> newPhysics;
                cout << "Nhập điểm hóa mới: ";
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
        cout << "~- MENU -~" << endl;
        cout << "0. Thoát. "<< endl;
        cout << "1. Thêm 1 thí sinh vào danh sách." << endl;
        cout << "2. Xoá 1 thí sinh khỏi danh sách." << endl;
        cout << "3. Sửa thông tin 1 thí sinh." << endl;
        cout << "4. Xuất thông tin của một thí sinh." << endl;
        cout << "5. Tìm các thí sinh có cùng quê." << endl;
        cout << "6. Tìm kiếm thông tin của một thí sinh." << endl;
        cout << "Mời nhập lựa chọn :";
        cin >> option;

        while (option < 0 || option > 6)
        {
            fflush(stdin);
            cout << "Lựa chọn của bạn là không hợp lệ!!! \n Hãy nhập lại: " ;
            cin >> option;
        }
        switch (option)
        {
        case 0: break;
        case 1:
        {
            ts.input();
            danhsach.insert(ts);
            break;
        }
        case 2:
        {
            cout << "nhap thong tin ban muon xoa" << endl;
            cout << "ten: ";
            getline(cin, name);
            cout << "sbd: ";
            getline(cin, sbd);
            if (danhsach.Delete(sbd, name) == true)
                cout << "da xoa thanh cong\n";
            else
                cout << "xoa khong thanh cong" << endl;
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
            cout << "hãy xuất thông tin để kiểm tra\n";
            break;
        }
        case 4:
        {
            cout << "Thông tin : " << endl;
            danhsach.display();
            break;
        }
        case 5:
        {
            string country;
            cout << "nhập vào tên tỉnh thành ";
            getline(cin, country);
            danhsach.countryman(danhsach, country);

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
            break;
        }
        }
    } while (option != false);
}
