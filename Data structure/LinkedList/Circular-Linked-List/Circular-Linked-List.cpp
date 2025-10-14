#include<iostream>
#include<vector>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int a) {
        val = a;
        next = nullptr;
    }
};

class CircularLinkedList {
    private:
    Node* head;
    Node* tail;
    int size;
    public:
    CircularLinkedList(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    CircularLinkedList(Node* head, Node* tail,int size){
        this->head = head;
        this->tail = tail;
        this->size = size;
    }
    ~CircularLinkedList();
    public:
    void InsertNodeFirst(int val);
    void InsertNodeLast(int val);
    void InsertAtPos(int pos, int val);
    void DeleteNodeFirst();
    void DeleteNodeLast();
    void DeleteNodeAtPosition(int pos);
    void ReverseList();
    void UpdateList(int pos, int val);
    int CountList();
    void DisplayList();
};

CircularLinkedList::~CircularLinkedList(){
    Node* temp = head;
    while(temp != nullptr){
        Node* next = temp -> next;
        delete temp;
        temp = next;
    }
}

void CircularLinkedList:: InsertNodeFirst(int val){
    Node* newNode = new Node(val);
    if (tail == nullptr) {
        tail = newNode;
    } else {
        newNode -> next = tail -> next;
    }
    tail -> next = newNode;
    size++;
}
void CircularLinkedList::InsertNodeLast(int val){
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
    }else {
        tail -> next = newNode;
        tail = newNode;
    }
    tail -> next = head;
}
void CircularLinkedList::InsertAtPos(int pos, int val) {
    Node* newNode = new Node(val);
    if(pos == 0) InsertNodeFirst(val);
        else if(pos > 0 && pos < size) {
            Node* temp = head;
            for(int i = 0; i < pos; i++) {
                temp = temp -> next;
            }
            newNode -> next =temp -> next;
            temp -> next = newNode;
            size ++;
        }
}

void CircularLinkedList::DeleteNodeFirst() {
    if(size == 0) {
        return;
    } else if(size > 0) {
        Node* temp = head;
        head = head -> next;
        delete temp;
        size--;
    }
}

void CircularLinkedList::DeleteNodeLast() {
    if (size == 0) {
        return;
    } else if (size > 0) {
        Node* temp = head;
        for(int i=0; i<size-1; i++) {
            temp = temp -> next;
        }
        delete temp ->next;
        size --;
    }
}

void CircularLinkedList::DeleteNodeAtPosition(int pos) {
    if(pos == 0) {
        DeleteNodeFirst();
    } else if(pos == size -1){
        DeleteNodeLast();
    } else if(pos > 0 && pos < size) {
        Node* temp = head;
        for(int i = 0; i < pos -1; i++){
            temp = temp -> next;
        }
        Node* toDelete = temp -> next;
        temp -> next = toDelete -> next;
        delete toDelete;
        size --;
    }
}

void CircularLinkedList::ReverseList() {
    if (head == tail) {
        return;
    }
    Node* temp = head;
    Node* newNode = new Node(head->val);
    vector<int> data;
    for(int i = 0; i < size; i++) {
        data.push_back(temp -> val);
        temp = temp -> next;
        DeleteNodeFirst();
    }
    for(int i = 0; i < size; i++) {
        newNode -> val = data[size - i -1];
        newNode = newNode -> next;
        head = newNode;
    }
}

void CircularLinkedList::UpdateList(int pos, int val) {
    Node* temp = head;
    if (pos >= 0 && pos < size) {
        temp -> val = val;
    } else {
        cout<<"Invalid position";
    }
}

int CircularLinkedList::CountList() {
    return size;
}

void CircularLinkedList::DisplayList() {
    Node* temp = head;
    for(int i = 0; i < size; i++) {
        cout << temp -> val << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main() {
    cout<<"Circular Linked List"<<endl;
    int ch = -1;
    CircularLinkedList list;
    cout<<"Please enter your choice"<<endl;
    cin>>ch;
    switch(ch){
        case 1:
            cout<<"Enter the value to insert at the beginning"<<endl;
            int val;
            cin>>val;
            list.InsertNodeFirst(val);
            break;
        case 2:
            cout<<"Enter the value to insert at the end"<<endl;
            cin>>val;
            list.InsertNodeLast(val);
            break;
        case 3:
            cout<<"Enter the value to insert at a specific position"<<endl;
            int pos;
            cin>>pos;
            cout<<"Enter the value"<<endl;
            cin>>val;
            list.InsertAtPos(pos, val);
            break;
        case 4:
            list.DeleteNodeFirst();
            break;
        case 5:
            list.DeleteNodeLast();
            break;
        case 6:
            cout<<"Enter the position to delete"<<endl;
            cin>>pos;
            list.DeleteNodeAtPosition(pos);
            break;
        case 7:
            list.ReverseList();
            break;
        case 8:
            cout<<"Enter the position to update"<<endl;
            cin>>pos;
            cout<<"Enter the new value"<<endl;
            cin>>val;
            list.UpdateList(pos, val);
            break;
        case 9:
            cout<<"The size of the list is "<<list.CountList()<<endl;
            break;
        case 10:
            list.DisplayList();
            break;
        default:
            cout<<"Invalid choice"<<endl;
            break;
    }
}
