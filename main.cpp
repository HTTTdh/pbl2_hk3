#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdexcept> 
#include"person.h"
#include"Thisinh.h"
#include"linklist.h"
using namespace std;

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
