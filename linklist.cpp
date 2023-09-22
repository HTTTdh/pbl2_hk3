#include<iostream>
#include"Thisinh.cpp"

using namespace std;

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

    
    void display() {
        node* temp = head;
        while (temp != NULL) {
            temp->data.display();
            temp = temp->next;
        }
    }
};
