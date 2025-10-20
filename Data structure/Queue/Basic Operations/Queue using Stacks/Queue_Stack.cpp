#include<iostream>
#include<stack>
using namespace std;

class Queue{
    private:
        stack<int> s1;
        stack<int> s2;
    public:
        Queue() {
        };
        bool isEmpty() const;
        int count() const;
        void enqueue(int val);
        void dequeue();
        void display() const;
        void peek() const;
        ~Queue() {
        };
};

bool Queue::isEmpty() const {
    return s1.empty();
}
int Queue::count() const {
    return s1.size();
}
void Queue::enqueue(int val) {
    s1.push(val);
}
void Queue::dequeue() {
    if(isEmpty()) {
        cout << "Queue is Empty" << endl;
        return;
    }
    while(!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
    }
    s2.pop();
    while(!s2.empty()) {
        s1.push(s2.top());
        s2.pop();
    }
}
void Queue::display() const {
    stack<int> temp = s1;
    stack<int> rev;
    while(!temp.empty()) {
        rev.push(temp.top());
        temp.pop();
    }
    while(!rev.empty()) {
        cout << rev.top() << " ";
        rev.pop();
    }
}
void Queue::peek() const {
    if(isEmpty()) {
        cout << "Queue is Empty" << endl;
        return;
    }
    stack<int> temp = s1;
    stack<int> rev;
    while(!temp.empty()) {
        rev.push(temp.top());   
        temp.pop();
    }
    cout << rev.top() << endl;
}

int main() { 
    Queue q;
    while(true) {
        cout << "Enter your choice:"
    << "\n1. Enqueue"
    << "\n2. Dequeue"
    << "\n3. Peek"
    << "\n4. Count"
    << "\n5. Display"
    << "\n6. Exit"
    << "\nEnter your choice: ";
    int choice;
    cin >> choice;
    switch(choice) {
        case 1:
            cout << "Enter the value to be inserted: ";
            int val;
            cin >> val;
            q.enqueue(val);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            cout << q.count() << endl;
            break;
        case 5:
            q.display();
            cout << endl;
            break;
        case 6:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
            break;
    }
    }
}