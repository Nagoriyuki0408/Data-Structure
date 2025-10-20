#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class Queue{
    private:
    Node* front;
    Node* rear;

    public:
    Queue() {
        front = rear = nullptr;
    }

    bool isEmpty() const;
    int count();
    void enqueue(int val);
    void dequeue();
    void display() const;
    void peek() const;
};

bool Queue::isEmpty() const{
    return front == rear && front == nullptr;
}

int Queue::count() {
    Node* cur = rear;
    int count = 0;
    while(cur!=nullptr) {
        cur = cur-> next;
        count++;
    }
    return count;
}

void Queue::enqueue(int val) {
    if(isEmpty()) {
        front = rear = new Node();
        front->data = val;
        return;
    }
    Node* temp = new Node();
    temp->data = val;
    temp->next = rear;
    rear = temp;
}

void Queue::dequeue() {
    if(isEmpty()) {
        cout << "Queue is Empty" << endl;
        return;
    } else if (count() == 1) {
        delete front;
        front = rear = nullptr;
        return;
    }
    Node* temp = rear;
    while(temp->next != front) {
        temp = temp->next;
    }
    Node* cur = front;
    front = temp;
    delete cur;
}

void Queue::display() const {
    Node* cur = rear;
    while(cur != nullptr) {
        cout << cur->data << " ";
        cur = cur->next;
    }
}

void Queue::peek() const {
    cout << front->data << endl;
}

int main() {
    Queue q;
    while(true) {
        cout << "Enter your choice: " << endl;
    cout << "1. enqueue()" << endl;
    cout << "2. dequeue()" << endl;
    cout << "3. peek()" << endl;
    cout << "4. display()" << endl; 
    cout << "5. count()" << endl;
    cout << "6. isEmpty()" << endl;
    cout << "7. exit()" << endl;
    int choice;
    cin >> choice;
    switch(choice) {
        case 1: {   
            cout << "Enter the value to be inserted: " << endl; 
            int val;
            cin >> val;
            q.enqueue(val);
            break;
            }
        case 2:
            q.dequeue();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            q.display();
            break;
        case 5:
            cout << q.count() << endl;
            break;
        case 6:
            if(q.isEmpty()) {
                cout << "Queue is empty" << endl;
            } else {
                cout << "Queue is not empty" << endl;
                break;
            }   
        case 7:
            exit(0);
            default:
            cout << "Invalid Choice" << endl;
    }   
    }
}
