#include<iostream>
#include"Thisinh.cpp"

using namespace std;

class node {
    public:
    ThiSinh data;
    node* next;

    node(ThiSinh sv)
    {
        data = sv;
        next = NULL;
    }
};

class linklist {
    private:
    node *head;
    public:
    linklist()
    {
        head = NULL;
    }
    void insert(ThiSinh sv)
    {
        node* p =new node(sv);
        if (head==NULL) head = p;
        else
        {
            node *temp= head;
            while (temp->next !=NULL) 
            {
                temp= temp->next;
            }
            temp->next = p;
        }
    }
    
};