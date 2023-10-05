#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdexcept> 
using namespace std;
class Date
{
public:
    int day, month, year;
    int sizedate()
    {
        int m = 6;
        if (day < 10)
            m++;
        else
            m += 2;
        if (month < 10)
            m++;
        else
            m = m + 2;
        return m;
    }
};

class Person
{
protected:
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
Person::Person(string cccd, string name, Date date, string address, int gt) : cccd(cccd), name(name), date(date), address(address), gt(gt){};
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
    cout << "Nhập họ tên: ";
    getline(cin, name);
    cout << "Nhập số cccd: ";
    getline(cin, cccd);
    cout << "Nhập ngày sinh: ";
    cin >> date.day;
    cout << "Nhập tháng sinh: ";
    cin >> date.month;
    cout << "Nhập năm sinh: ";
    cin >> date.year;
    cin.ignore(1);
    cout << "Nhập địa chỉ (chỉ nhập tỉnh): ";
    getline(cin, address);
    cout << "Nhập giới tính (0: Nam, 1: Nữ): ";
    cin >> gt;
}
class ThiSinh : public Person
{
private:
    string sbd;
    float to, li, ho;

public:
    ThiSinh();
    ThiSinh(string cccd, string name, Date date, string address, int gt, string sbd, float to, float li, float ho);
    void setsbd(string sbd);
    string getsbd();
    void setto(float to);
    float getto();
    void setli(float li);
    float getli();
    void sethoa(float hoa);
    float gethoa();
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
ThiSinh::ThiSinh(string cccd, string name, Date date, string address, int gt, string sbd, float to, float li, float ho) : Person(cccd, name, date, address, gt), sbd(sbd), to(to), li(li), ho(ho){};
void ThiSinh::setsbd(string sbd)
{
    this->sbd = sbd;
}
string ThiSinh::getsbd()
{
    return sbd;
}
void ThiSinh::setto(float to)
{
    this->to = to;
}
float ThiSinh::getto()
{
    return to;
}
void ThiSinh::setli(float li)
{
    this->li = li;
}
float ThiSinh::getli()
{
    return li;
}
void ThiSinh::sethoa(float hoa)
{
    this->ho = hoa;
}
float ThiSinh::gethoa()
{
    return ho;
}
void ThiSinh::input()
{
    for (int i = 0; i < 50; i++)
        cout << "-";
    cout << endl;
    nhapthongtin();
    fflush(stdin);
    cout << "Nhập số báo danh: ";
    getline(cin, sbd);
    cout << "Nhập điểm toán: ";
    cin >> to;
    cout << "Nhập điểm lý: ";
    cin >> li;
    cout << "Nhập điểm hóa: ";
    cin >> ho;
    for (int i = 0; i < 50; i++)
        cout << "-";
    cout << endl;
}
void ThiSinh::display()
{
    cout << "|";
    for (int i = 0; i < 153; i++)
        cout << "-";
    cout << "|" << endl;
    cout << "|" << getname() << setw(34 - getname().length()) << "|";
    cout << getcccd() << setw(20 - getcccd().length()) << "|";
    cout << setw(4) << getgt() << setw(4) << "|";
    cout << getdate().day << "/" << getdate().month << "/" << getdate().year << setw(19 - getdate().sizedate()) << "|";
    cout << getaddress() << setw(20 - getaddress().length()) << "|";
    cout << getsbd() << setw(16 - getsbd().length()) << "|";
    cout << setw(7) << getto() << setw(3) << "|";
    cout << setw(5) << getli() << setw(3) << "|";
    cout << setw(6) << gethoa() << setw(3) << "|";
    cout << setw(5) << to + li + ho << setw(5) << "|" << endl;
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
    cout << "+";
    for (int i = 0; i < 153; i++)
        cout << "-";
    cout << "+" << endl;
    cout << "|" << setw(15) << "Tên" << setw(20) << "|";
    cout << setw(10) << "CCCD" << setw(10) << "|";
    cout << setw(5) << "GT" << setw(3) << "|";
    cout << setw(15) << "Ngày Sinh" << setw(5) << "|";
    cout << setw(17) << "Địa Chỉ" << setw(8) << "|";
    cout << setw(8) << "SBD" << setw(8) << "|";
    cout << setw(8) << "Toán" << setw(3) << "|";
    cout << setw(6) << "Lý" << setw(3) << "|";
    cout << setw(7) << "Hóa" << setw(3) << "|";
    cout << setw(9) << "Tổng" << setw(3) << "|" << endl;
    node *temp = head;
        while (temp != NULL)
        {
            temp->data.display();
            temp = temp->next;
        }
    cout << "|";
     for (int i = 0; i < 153; i++)
        cout << "-";
    cout << "|" << endl;
    }
    void docfile();
    void ghifile();
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
    void searchinf()
    {
        string c;
        int lc;
        do
        {
            system("cls");
            cout << "\n\n\t CÁC THÔNG TIN CẦN TÌM\n\n\t+";
            for (int i = 1; i <= 30; ++i)
                cout << "-";
            cout << "+" << endl;
            cout << "\t|   1. Tên                     |\n";
            cout << "\t|" << setw(31) << "|" << endl;
            cout << "\t|   2. Địa chỉ                 |\n ";
            cout << "\t|" << setw(31) << "|" << endl;
            cout << "\t|   3. CCCD                    |\n";
            cout << "\t|" << setw(31) << "|" << endl;
            cout << "\t|   4. SBD                     |\n";
            cout << "\t|" << setw(31) << "|" << endl;
            cout << "\t|   5. Năm sinh                |\n";
            cout << "\t|" << setw(31) << "|" << endl;
            cout << "\t|   6. Giới tính               |\n";
            cout << "\t+";
            for (int i = 1; i <= 30; ++i)
                cout << "-";
            cout << "+" << endl;
            cout << "\nMời nhập lựa chọn :";
            cin >> lc;
            while (lc < 0 || lc > 6)
            {
                fflush(stdin);
                cout << "Lựa chọn của bạn là không hợp lệ!!! \n Hãy nhập lại: ";
                cin >> lc;
            }
            switch (lc)
            {
            case 1:
            {
                fflush(stdin);
                string name;
                node *p = head;
                cout << "nhập tên bạn muốn hiển thị: ";
                getline(cin, name);
                while (p != nullptr)
                {
                    if (p->data.getname().find(name) != string::npos)
                    {
                        p->data.display();
                    }
                    p = p->next;
                }
                system("pause");
                break;
            }
            case 2:
            {
                fflush(stdin);
                string address;
                node *p = head;
                cout << "nhập địa chỉ bạn muốn hiển thị: ";
                getline(cin, address);
                while (p != nullptr)
                {
                    if (p->data.getaddress().find(address) != string::npos)
                    {
                        p->data.display();
                    }
                    p = p->next;
                }
                system("pause");
                break;
            }
            case 3:
            {
                fflush(stdin);
                string cccd;
                node *p = head;
                cout << "nhập những số trong cccd bạn muốn hiển thị: ";
                getline(cin, cccd);
                while (p != nullptr)
                {
                    if (p->data.getcccd().find(cccd) != string::npos)
                    {
                        p->data.display();
                    }
                    p = p->next;
                }
                system("pause");
                break;
            }
            case 4:
            {
                fflush(stdin);
                string sbd;
                node *p = head;
                cout << "nhập những số có trong số báo danh mà bạn muốn hiển thị: ";
                getline(cin, sbd);
                while (p != nullptr)
                {
                    if (p->data.getsbd().find(sbd) != string::npos)
                    {
                        p->data.display();
                    }
                    p = p->next;
                }
                system("pause");
                break;
            }
            case 5:
            {
                fflush(stdin);
                int ns;
                node *p = head;
                cout << "nhập năm sinh bạn muốn hiển thị: ";
                cin >> ns;
                while (p != nullptr)
                {
                    if (p->data.getdate().year == ns)
                    {
                        p->data.display();
                    }
                    p = p->next;
                }
                system("pause");
                break;
            }
            case 6:
            {
                cin.ignore();
                string gt;
                node *p = head;
                cout << "Bạn muốn hiển thị giới tính nào (nam/nữ): ";
                getline(cin, gt);
                for (int i = 0; i < gt.length(); i++)
                {
                    gt[i] = tolower(gt[i]);
                }
                while (p != nullptr)
                {
                    if ((gt == "nam" && p->data.getgt() == 0) || (gt == "nữ" && p->data.getgt() == 1))
                    {
                        p->data.display();
                    }
                    p = p->next;
                }
                system("pause");
                break;
            }
            }
            cout << "bạn có muốn tìm kiếm thông tin tiếp hay không? (y/n) ";
            cin >> c;
        } while (c == "y" || c == "Y");
    }
};
void LinkedList::docfile()
{
    ThiSinh ts;
    ifstream inputFile;
    inputFile.open("dsthisinh.txt", ios::in);
    if (inputFile.is_open())
    {
        string line;
        size_t pos;
        while (getline(inputFile, line))
        {
            pos = line.find(",");
            ts.setname(line.substr(0, pos));
            line.erase(0, pos + 1);

            pos = line.find(",");
            ts.setcccd(line.substr(0, pos));
            line.erase(0, pos + 1);

            pos = line.find(",");
            try {
                ts.setgt(stoi(line.substr(0, pos)));
            }
            catch (const invalid_argument& e) {
                cerr << "Lỗi: " << e.what() << " - Giá trị không hợp lệ: " << line.substr(0, pos) << std::endl;
                // Xử lý lỗi ở đây (ví dụ: gán giá trị mặc định)
                ts.setgt(0); 
            }
            line.erase(0, pos + 1);

            Date d;
            pos = line.find("/");
            d.day = stoi(line.substr(0, pos));
            line.erase(0, pos + 1);
            pos = line.find("/");
            d.month = stoi(line.substr(0, pos));
            line.erase(0, pos + 1);
            pos = line.find(",");
            d.year = stoi(line.substr(0, pos));
            line.erase(0, pos + 1);
            ts.setdate(d);

            pos = line.find(",");
            ts.setaddress(line.substr(0, pos));
            line.erase(0, pos + 1);

            pos = line.find(",");
            ts.setsbd(line.substr(0, pos));
            line.erase(0, pos + 1);

            pos = line.find(",");
            ts.setto(stof(line.substr(0, pos)));
            line.erase(0, pos + 1);

            pos = line.find(",");
            ts.setli(stof(line.substr(0, pos)));
            line.erase(0, pos + 1);

            ts.sethoa(stof(line));
            insert(ts);
        }

        inputFile.close();
    }
    else {
        cout << "Không thể mở file." << endl;
    }
}
void LinkedList::ghifile(){
    ofstream outputFile;
    outputFile.open("dsthisinh.txt", ios::out);
    if (outputFile.is_open())
    {
        node* current = head; 
        while (current != NULL)
        {
            outputFile << current->data.getname() << "," << current->data.getcccd() << "," << current->data.getgt() << ","
                       << current->data.getdate().day << "/" << current->data.getdate().month << "/" << current->data.getdate().year
                       << "," << current->data.getaddress() << "," << current->data.getsbd() << "," << current->data.getto()
                       << "," << current->data.getli() << "," << current->data.gethoa() << endl;
            
            current = current->next; 
        }
        outputFile.close();
    }
    else {
        cout << "Không thể mở file." << endl;
    }
}


void editinfor(LinkedList &ds, string sbd, string name)
{
    node *p = ds.search(sbd, name);
    string New;
    int d;
    string c;
    Date date;
    int luachon;
    do
    {
        system("cls");
        cout << "\n\n\t CÁC THÔNG TIN CẦN SỬA\n\n\t+";
        for (int i = 1; i <= 30; ++i)
            cout << "-";
        cout << "+" << endl;
        cout << "\t|   1. Tên                     |\n";
        cout << "\t|" << setw(31) << "|" << endl;
        cout << "\t|   2. Ngày/tháng/năm sinh     |\n ";
        cout << "\t|" << setw(31) << "|" << endl;
        cout << "\t|   3. Địa chỉ                 |\n";
        cout << "\t|" << setw(31) << "|" << endl;
        cout << "\t|   4. CCCD                    |\n";
        cout << "\t|" << setw(31) << "|" << endl;
        cout << "\t|   5. Giới tính               |\n";
        cout << "\t|" << setw(31) << "|" << endl;
        cout << "\t|   6. Điểm                    |\n";
        cout << "\t+";
        for (int i = 1; i <= 30; ++i)
            cout << "-";
        cout << "+" << endl;
        cout << "\nMời nhập lựa chọn :";
        cin >> luachon;
        while (luachon < 0 || luachon > 6)
        {
            fflush(stdin);
            cout << "Lựa chọn của bạn là không hợp lệ!!! \n Hãy nhập lại: ";
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
                float newMath, newPhysics, newChemistry;
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
        cout << "bạn có muốn tìm kiếm thông tin tiếp hay không?(y/n)";
        cin >> c;
    } while (c == "y" || c == "Y");
}

int main()
{
    LinkedList danhsach;
    ThiSinh ts;
    string sbd;
    string name;
    int option;
    danhsach.docfile();
    do
    {
        system("cls");
        cout << "\t~- QUẢN LÝ ĐIỂM THI CỦA CÁC THÍ SINH VÀO MỘT TRƯỜNG ĐẠI HỌC -~" << endl;
        for (int i = 1; i <= 100; ++i)
            cout << "-";
        cout << "\n\n\t\t DANH SÁCH CÁC THAO TÁC\n\n\t+";
        for (int i = 1; i <= 50; ++i)
            cout << "-";
        cout << "+" << endl;
        cout << "\t|   0. Thoát.                                      |\n";
        cout << "\t|" << setw(51) << "|" << endl;
        cout << "\t|   1. Thêm 1 thí sinh vào danh sách.              |\n";
        cout << "\t|" << setw(51) << "|" << endl;
        cout << "\t|   2. Xoá 1 thí sinh khỏi danh sách.              |\n ";
        cout << "\t|" << setw(51) << "|" << endl;
        cout << "\t|   3. Sửa thông tin 1 thí sinh.                   |\n";
        cout << "\t|" << setw(51) << "|" << endl;
        cout << "\t|   4. Xuất thông tin của một thí sinh.            |\n";
        cout << "\t|" << setw(51) << "|" << endl;
        cout << "\t|   5. Tìm kiếm các thông tin liên quan.           |\n";
        cout << "\t|" << setw(51) << "|" << endl;
        cout << "\t|   6. Tìm kiếm thông tin của một thí sinh.        |\n";
        cout << "\t+";
        for (int i = 1; i <= 50; ++i)
            cout << "-";
        cout << "+" << endl;
        cout << "\nMời nhập lựa chọn : ";
        cin >> option;

        while (option < 0 || option > 6)
        {
            fflush(stdin);
            cout << "Lựa chọn của bạn là không hợp lệ!!! \n Hãy nhập lại: ";
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
            danhsach.ghifile();
            cout << "Đã thêm thành công\n";
            system("pause");
            break;
        }
        case 2:
        {
            for (int i = 0; i < 50; i++)
                cout << "-";
            cout << endl;
            cout << "Bạn muốn xóa thông tin của ai:" << endl;
            fflush(stdin);
            cout << "Tên: ";
            getline(cin, name);
            cout << "sbd: ";
            getline(cin, sbd);
            if (danhsach.search(sbd, name) != NULL)
            {
                if (danhsach.Delete(sbd, name) == true)
                    cout << "Đã xóa thành công\n";
                else
                    cout << "Không xóa được thông tin này" << endl;
            }
            else
                cout << "Không tìm thấy thông tin cần xóa" << endl;
            system("pause");
            break;
        }
        case 3:
        {
            for (int i = 0; i < 50; i++)
                cout << "-";
            cout << endl;
            cout << "Bạn muốn sửa thông tin của ai:" << endl;
            fflush(stdin);
            cout << "Tên: ";
            getline(cin, name);
            cout << "sbd: ";
            getline(cin, sbd);
            if (danhsach.search(sbd, name) != NULL)
            {
                editinfor(danhsach, sbd, name);
                cout << "Đã cập nhật thông tin\n";
            }
            else
                cout << "Không tìm thấy thông tin cần sửa" << endl;
            system("pause");
            break;
        }
        case 4:
        {
            danhsach.xuat();
            system("pause");
            break;
        }
        case 5:
        {
            for (int i = 0; i < 50; i++)
                cout << "-";
            cout << endl;
            cout << "Bạn muốn tìm kiếm thông qua thông tin gì?" << endl;
            danhsach.searchinf();
            system("pause");
            break;
        }
        case 6:
        {
            for (int i = 0; i < 50; i++)
                cout << "-";
            cout << endl;
            node *temp;
            fflush(stdin);
            cout << "Nhập sbd: ";
            getline(cin, sbd);
            cout << "Nhập tên: ";
            getline(cin, name);
            temp = danhsach.search(sbd, name);
            if (temp == NULL)
                cout << "Không tìm thấy thông tin\n";
            else
                ts.display();
            system("pause");
            break;
        }
        }
    } while (option != false);
}
