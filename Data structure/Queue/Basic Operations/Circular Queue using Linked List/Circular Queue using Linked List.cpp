#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class CircularQueue{
    private:
        Node* front;
        Node* rear;
    public:
        CircularQueue(){
            front = NULL;
            rear = NULL;
        }
        void enqueue(int);
        void dequeue();
        void display();
        bool isEmpty();
        bool isFull();
        int peek();
        int count();
};

bool CircularQueue::isEmpty() {
    return (front == rear && rear == nullptr);
}

bool CircularQueue::isFull() {

}
void CircularQueue::enqueue(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = nullptr;
    if(isEmpty()) {
        front = newNode;
        rear = newNode;
        rear->next = front;
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front; 
        cout<<"Enqueued "<<val<<endl;
        return;
}
}

void CircularQueue::dequeue() {
    if(isEmpty()) {
        cout<<"Queue is empty"<<endl;
        return;
    }
    if (front == rear) {
        front == nullptr;
        rear == nullptr;
    } else {
        Node* temp = front;
        front = front->next;
        rear->next = front;
        delete temp;
    }
}

int CircularQueue::peek() {
    if(isEmpty()) {
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    return front->data;
}

int CircularQueue::count() {
    int count = 0;
    if(front == rear && front != nullptr) {
        count = 1;
    } else {
        Node* cur = front;
        do {
            count++;
            cur = cur->next;
        }while(cur != front);
    }
    return count;
}

void CircularQueue::display() {
    Node* cur = front;
    if (isEmpty()) {
        cout<<"Queue is empty"<<endl;
        return;
    } else {
        cout<<"Queue: ";
        do {
            cout << cur->data << " ";
            cur = cur->next;
        } while(cur != front);
        cout << endl;
    }
}

int main() {
    CircularQueue q;
    while(1) {
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. Peek"<<endl;
        cout<<"4. Display"<<endl;
        cout<<"5. Count"<<endl;
        cout<<"6. Exit"<<endl;
        int choice;
        cin>>choice;
        switch(choice) {
            case 1: {
                int val;
                cout<<"Enter value to enqueue: ";
                cin>>val;
                q.enqueue(val);
                break;  

            }
            case 2: {
                q.dequeue();
                break;
            }
            case 3: {
                cout<<"Peek: "<<q.peek()<<endl;
                break;
            }
            case 4: {
                q.display();
                break;
            }
            case 5: {
                cout<<"Count: "<<q.count()<<endl;
                break;
            }
            case 6: {
                exit(0);
            }
            default: {
                cout<<"Invalid choice"<<endl;
            }
    }
}
    return 0;
}   