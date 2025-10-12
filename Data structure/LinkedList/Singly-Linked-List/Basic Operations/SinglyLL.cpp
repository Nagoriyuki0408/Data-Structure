#include<iostream>
#include<malloc.h>
#include<bits/stdc++.h>
using namespace std;

class Node {
    public :
    int val;
    Node *next;
};

Node *start =NULL, *temp,*node,*ptr;

int IsEmpty(){
    if(start == NULL) return 1;
        else return 0;
}

int CountNodes(){
    int n = 0;
    temp = start;
    while(temp != NULL){
        n++;
        temp = temp -> next;
    }
    return n;
}

int SearchNode() {
    int n;
    cout<<"Enter value:";
    cin>>n;
    int c = 1, flag =0;
    temp = start;
    while(temp != NULL) {
        if (temp-> val == n) {
            flag =1;
            break;
        }
        temp = temp->next;
    }
    if(flag==1) return temp->val;
        else return -1;
}

void CreateList(){
    temp = new Node();
    cout<<"Enter the value of the first node:";
    cin>>temp->val;
    temp->next =nullptr;
    if (start == nullptr) {
        start = temp;
        node = temp;
    } else {
        node -> next =temp;
        node =temp;
    }
}

void DisplayList() {
    temp = start;
    while(temp != nullptr){
        cout << temp->val<<endl;
        temp = temp->next;
    }
    cout<<endl;
}

void InsertBeg() {
    temp = new Node();
    cout<<"Enter the value of the first node:";
    cin>>temp->val;
    temp ->next =start;
    start = temp;
}

void InsertEnd() {
    if (IsEmpty()){
        CreateList();
    } else {
        temp = new Node();
        cin>>temp->val;
        ptr = start;
        while(ptr->next != nullptr) {
            ptr = ptr->next;
        }
        ptr->next=temp;
        temp->next = nullptr;
    }
}

void InsertAfter () {
    int m;
    cout<<"Enter value:";
    cin>>m;
    temp = start;
    cout<<"Enter position:";
    int n;
    cin>>n;
    if(n == 1) {
        if (IsEmpty()){
            CreateList();
        } else {
            InsertBeg();
        }
    } else {
        if(n > 0 && n<=CountNodes()) {
            int c =1;
            while(c != n) {
                temp = temp-> next;
                c++;
            }
            ptr = new Node();
            ptr->val = m;
            ptr ->next = temp->next;
            temp ->next =ptr;
        } else {
            cout <<"\n Invalid Position!!\n";
        }
    }
}

void InsertBefore () {
    int n;
    cout<<"Enter the Element before you want to Insert:";
    cin>>n;
    if(SearchNode()) {
        temp = start;
        while(temp -> next ->val != n) {
            temp = temp -> next;
        }
        ptr = new Node();
        cout<<"Enter value:";
        cin>> ptr->val;
        ptr -> next = temp -> next;
        temp-> next = ptr;

    } else {
        cout <<"\nElement not found!!\n";
    }
}

void DeleteFirst() {
    if (IsEmpty()) {
        cout <<"List is empty!!\n";
    } else {
        temp = start;
        start = start -> next;
        delete temp;
    }
}

void DeleteLast() {
    if (IsEmpty()) {
        cout<<"List is empty!!\n";
    } else {
        temp =start;
        ptr = start;
        while (temp -> next -> next != nullptr) {
            temp =temp -> next;
        }
        ptr = temp -> next;
        temp -> next = nullptr;
        delete ptr;
    }
}

void DeleteAtIndex() {
    int n;
    cout << "\nEnter the index to be deleted: ";
    cin >> n;
    if (n == 1) {
        DeleteFirst();
    } else if( n > 1 && n < CountNodes()) {
        temp = start;
        int c = 0;
        while(c < n - 2) {
            temp = temp -> next;
        }
        ptr = temp -> next;
        temp -> next = ptr -> next;
        delete ptr;
    } else if (n == CountNodes()) {
        DeleteLast();
    }
}

void DeleteByValue() {
    int n;
    cout << "\nEnter the value to be deleted: ";
    cin >> n;
    int result = SearchNode();
    if(result < CountNodes() && result > 0) {
        temp = start;
        while (temp -> next -> next-> val != result) {
            temp = temp -> next;
        }
        ptr = temp -> next;
        temp -> next = ptr ->next;
        delete ptr;
    } else if (result == CountNodes()) {
        DeleteLast();
    } else if (result == 0) {
        DeleteFirst();
    } else {
        cout <<"\nElement not found!!\n";
    }
}

void UpdateNode() {
    int n, m;
    cout << "\nEnter the value to be updated: ";
    cin >> n;
    cout << "\nEnter the new value: ";
    cin >> m;
    temp = start;
    while (temp ->val == n && temp -> next != nullptr) {
        temp = temp -> next;
    }
    temp -> val = m;
}

int main() {
    int ch;
    do {
        cout<<"\n\t-:M E N U:- \n ===================\n";
        cout<<"1...Create List." << endl;
        cout<<"2...DisplayList." << endl;
        cout<<"3...Insert at beginning." << endl;
        cout<<"4...Insert at end." << endl;
        cout<<"5...Insert after a specific node." << endl;
        cout<<"6...Insert before a specific node." << endl;
        cout<<"7...Search an element." << endl;
        cout<<"8...Delete first element." << endl;
        cout<<"9...Delete last element." << endl;
        cout<<"10...Delete element at a specific index." << endl;
        cout<<"11...Update element with a specific value." << endl;
        cout<<"0...Exit." << endl;
        cout<<"\nEnter your choice:";
        cin>>ch;
        switch (ch) {
            case 1:
                CreateList();
                break;
            case 2:
                DisplayList();
                break;
            case 3:
                InsertBeg();
                break;
            case 4:
                InsertEnd();
                break;
            case 5:
                InsertAfter();
                break;
            case 6:
                InsertBefore();
                break;
            case 7:
                SearchNode();
                break;
            case 8:
                DeleteFirst();
                break;
            case 9:
                DeleteLast();
                break;
            case 10:
                DeleteAtIndex();
                break;
            case 11:
                UpdateNode();
                break;
            case 0:
                cout<<"\nExiting...";
                break;
            default:
                cout<<"\nInvalid choice!!";
                break;
        }
    } while (ch != 0);
    return 0;
}
