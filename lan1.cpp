#include <iostream>
#include <string>
using namespace std;

class People {
protected:
    string name;
    string address;
public:
    People() {
        
    }
    People(string n, string add) {
        name = n;
        address = add;
    }
    void input()
    {
        fflush(stdin);
        cout << "ten: ";
        getline(cin,name);
        cout << "dia chỉ: " ;
        getline(cin,address);
    }
};

class SinhVien : public People {
private:
    string masv;
public:
    SinhVien(){

    }
    SinhVien(string n, string add, string msv) : People(n, add) {
        masv = msv;
    }
    void nhap()
    {
        input();
        fflush(stdin);
        cout<< "ma sinh vien: ";
        getline(cin, masv);
    }
    void display() {
        cout << "Tên: " << name << endl;
        cout << "Địa chỉ: " << address << endl;
        cout << "Mã sinh viên: " << masv << endl;
    }
};

class Node {
public:
    SinhVien data;
    Node* next;
    Node();
    Node(SinhVien sv) {
        data = sv;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = NULL;
    }

    void insert(SinhVien sv) {
        Node* newNode = new Node(sv);
        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            temp->data.display();
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList danhSachSinhVien;

    SinhVien sv1;
    sv1.nhap();
    danhSachSinhVien.insert(sv1);
    danhSachSinhVien.display();

    return 0;
}
