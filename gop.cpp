#include<iostream>
#include<string>
#include<vector>
#include <fstream>

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


class ThiSinh : public Person {
    private:
    double to;
    string sbd;
    double li,ho;
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
        cout << "nhap so bao danh: ";
            getline(cin, sbd);
            cout << "nhap diem toan: ";
            cin >> to;
            cout << "nhap diem ly: ";
            cin >> li;
            cout << "nhap diem hoa: ";
            cin >> ho;
}

void ThiSinh::nhapsbd(){
    cout << "nhap so bao danh: ";
        getline(cin, sbd);
}

void ThiSinh::display()
{
            cout << "tên: " << getname() << endl;
            cout << "cccd: " << getcccd() << endl;
            cout << "ngày sinh: " << getdate().day << "/" << getdate().month << "/" << getdate().year << endl;
            cout << "địa chỉ: " << getaddress() << endl;
            cout << "giới tính: " << getgt() << endl;
}

class node {
public:
    ThiSinh data;
    node* next;
    node();
    node(ThiSinh ts)
    {
        data = ts;
        next = NULL;
            }
        };

class LinkedList{
private:
    node* head;
   public:
       LinkedList() {
           head = NULL;
       }
    void insert(ThiSinh sv) {
          node* newNode = new node(sv);
          if (head == NULL) {
              head = newNode;
          }
          else {
              node* temp = head;
              while (temp->next != NULL) {
                  temp = temp->next;
              }
              temp->next = newNode;
                      }
                  }
    void Delete(ThiSinh sv){
        if(head==NULL){
            return ;
        }
        else{
            node* temp = head ;
            while(temp->data.getcccd() != sv.getcccd() && temp->data.getsbd() != sv.getsbd()){
                temp = temp->next ;
            }
            temp->next = temp->next->next ;
        }
    }

    node* gethead(){
        return head;
    }

    void display() {
            node* temp = head;
            while (temp != NULL) {
                temp->data.display();
                temp = temp->next;
            }
        }
    bool testempty(){
        if(head == NULL){
            cout << "Danh sách rỗng.";
            return true ;
        }
        else{
            return false ;
        }
    }
    };

void insertStudent(LinkedList &ds) {
    ThiSinh ts ;
    cout << "Mời nhập thông tin sinh viên cần thêm vào danh sách :" <<endl;
                ts.input();
                ds.insert(ts);
}

void deleteStudent(LinkedList ds){
    ThiSinh temp ;
    cout << "Mời nhập thông tin sinh viên cần xoá trong danh sách :" <<endl;
    temp.input();
    ds.Delete(temp);
}

void editinfor(LinkedList &ds){
    ThiSinh SV ;
    Date date ;
    string newname;
    Date newdate;
    string newaddress;
    string newcccd ;
    int newgt;
    double newto,newli,newhoa;
    cout <<"mời nhập thông tin hiện tại : "<<endl ;
    SV.input();
    cout << "~ EDIT INFORMATION ~" <<endl;
    int luachon ;
    do{
        cout <<"1.Chỉnh sửa tên. " <<endl;
        cout <<"2.Chỉnh sửa ngày/tháng/năm sinh. " <<endl;
        cout <<"3.Chỉnh sửa địa chỉ. " <<endl;
        cout <<"4.Chỉnh sửa số cccd. " <<endl;
        cout <<"5.Chỉnh sửa giới tính. " <<endl;
        cout <<"6.Chỉnh sửa điểm. " <<endl;
        cout <<"Nhập lựa chọn :";
        cin >> luachon ;
        switch (luachon){
            case 1:
                if(ds.testempty()==true){
                    cout << "Chưa có danh sách thí sinh dự thi.";
                }
                else{
                    node *tam;
                    tam = ds.gethead();
                    while(tam->data.getcccd() != SV.getcccd() && tam->data.getname() != SV.getname() && tam->data.getsbd() != SV.getsbd()){
                        tam = tam->next;
                    }
                    cout <<"Nhập tên mới : " ; cin >> newname;
                    tam->data.setname(newname);
                }
                break;
            case 2:
                if(ds.testempty()==true){
                    cout << "Chưa có danh sách thí sinh dự thi.";
                }
                else{
                    node *tam;
                    tam = ds.gethead();
                    while(tam->data.getcccd() != SV.getcccd() && tam->data.getname() != SV.getname() && tam->data.getsbd() != SV.getsbd()){
                        tam = tam->next;
                    }
                    cout <<"Nhập Ngày/tháng/năm sinh mới : " ; cin >> newdate.day >> newdate.month >> newdate.year;
                    tam->data.setdate(newdate);
                }
                break;
            case 3:

                if(ds.testempty()==true){
                    cout << "Chưa có danh sách thí sinh dự thi.";
                }
                else{
                    node *tam;
                    tam = ds.gethead();
                    while(tam->data.getcccd() != SV.getcccd() && tam->data.getname() != SV.getname() && tam->data.getsbd() != SV.getsbd()){
                        tam = tam->next;
                    }
                    cout <<"Nhập địa chỉ mới : " ; cin >> newaddress ;
                    tam->data.setaddress(newaddress);
                }
                break;
            case 4:
                if(ds.testempty()==true){
                    cout << "Chưa có danh sách thí sinh dự thi.";
                }
                else{
                    node *tam;
                    tam = ds.gethead();
                    while(tam->data.getcccd() != SV.getcccd() && tam->data.getname() != SV.getname() && tam->data.getsbd() != SV.getsbd()){
                        tam = tam->next;
                    }
                    cout <<"Nhập số cccd mới " ; cin >> newcccd;
                    tam->data.setcccd(newcccd);
                }
                break;
            case 5:
                if(ds.testempty()==true){
                    cout << "Chưa có danh sách thí sinh dự thi.";
                }
                else{
                    node *tam;
                    tam = ds.gethead();
                    while(tam->data.getcccd() != SV.getcccd() && tam->data.getname() != SV.getname() && tam->data.getsbd() != SV.getsbd()){
                        tam = tam->next;
                    }
                    cout <<"Nhập giới tính : " ; cin >> newgt;
                    tam->data.setgt(newgt);
                }
                break;
            case 6:
                if(ds.testempty()==true){
                    cout << "Chưa có danh sách thí sinh dự thi.";
                }
                else{
                    node *tam;
                    tam = ds.gethead();
                    while(tam->data.getcccd() != SV.getcccd() && tam->data.getname() != SV.getname() && tam->data.getsbd() != SV.getsbd()){
                        tam = tam->next;
                    }
                    cout <<"Nhập điểm toán mới : " ; cin >> newto;
                    tam->data.setto(newto);
                    cout <<"Nhập điểm lý mới : " ; cin >> newli;
                    tam->data.setli(newli);
                    cout <<"Nhập điểm hoá mới : " ; cin >> newhoa;
                    tam->data.sethoa(newhoa);
                }
                break;
            default:
                cout <<"Lựa chọn" <<luachon <<"của bạn là không hợp lệ!!!" <<endl;
        }
        cout<< "Nhập kí tự 'y' để thoát.";
        getchar();
    }while(getchar() != 'y');
}

void getinfor(LinkedList &ds){
    ThiSinh SV;
    node* thread ;
    thread = ds.gethead();
    cout << "Mời nhập số báo danh của thí sinh cần tìm : ";
    SV.nhapsbd();
    while(thread->data.getsbd() != SV.getsbd()){
        thread = thread -> next;
    }
    thread->data.display();
}

void countryman(LinkedList &ds){
    node* thread ;
    string country;
    thread = ds.gethead();
    cout << "Nhập địa chỉ cần tìm thí sinh cùng quê : ";
    cin >> country ;
    while(thread-> next != NULL){
        if(thread->data.getaddress() == country){
            thread->data.display();
        }
        thread = thread -> next;
    }
}


void samename(LinkedList &ds){
    node* thread ;
    string name;
    thread = ds.gethead();
    cout << "Nhập tên cần tìm thí sinh cùng tên : ";
    cin >> name ;
    while(thread-> next != NULL){
         if(thread->data.getname() == name){
            thread->data.display();
         }
         thread = thread -> next;
     }
}

int main()
{
    LinkedList danhsach;
    int option ;
    do{
        cout << "~- MENU -~" <<endl ;
        cout << "1. Thêm 1 thí sinh vào danh sách." <<endl;
        cout << "2. Xoá 1 thí sinh khỏi danh sách." <<endl;
        cout << "3. Sửa thông tin 1 thí sinh." <<endl;
        cout << "4. Xuất thông tin của một thí sinh." <<endl;
        cout << "5. Tìm các thí sinh có cùng quê." <<endl;
        cout << "6. Tìm các thí sinh có cùng tên." <<endl;
        cout << "Mời nhập lựa chọn :";
        cin >> option ;
        switch(option){
            case 1:
                insertStudent(danhsach);
                break;
            case 2:
                deleteStudent(danhsach);
                break;
            case 3:
                editinfor(danhsach);
                break;
            case 4:
                cout << "Thông tin : "<<endl;
                getinfor (danhsach);
                break;
            case 5:
                countryman(danhsach);
                break;
            case 6:
                samename(danhsach);
                break;
            default:
                cout <<"Lựa chọn" <<option <<"của bạn là không hợp lệ!!!" <<endl;
        }
        cout << "Nhấn enter để thoát. ";
        getchar();

    }while(getchar() != '\n');

}

