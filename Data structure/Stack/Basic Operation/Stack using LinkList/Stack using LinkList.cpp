#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class Stack{
    private:
        Node* top;
        Node* bottom;
        void displayReverseHelper(Node* node) {
        if (node == nullptr) return;
        displayReverseHelper(node->next);
        cout << node->data << " ";
        }
    public:
        Stack() {
            top = nullptr;
            bottom = nullptr;
        }
        void display() {
        displayReverseHelper(bottom); 
        }
        void push(int data);
        void pop();
        bool isEmpty();
        int peek();
        int count();
        void updateValue(int pos, int value);
};

void Stack::push(int data) {
    Node* temp = new Node();
    temp->data = data;
    if(isEmpty()) {
        this->top = temp;
        this->bottom = temp;
        return;
    } else{
        top->next = temp;
        top = temp;
    }
}

bool Stack::isEmpty() {
    return top == nullptr;
}

void Stack::pop() {
    Node* temp = new Node();
    while(temp->next != top) {
        temp = temp->next;
    }
    top = temp;
    delete temp->next;
}

//singltlinkedlist with the problem of reverse display

int Stack::peek() {
    return top->data;
}

int Stack::count() {
    Node* temp = bottom;
    int count = 0;
    while(temp->next != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void Stack::updateValue(int pos, int value) {
    Node* temp = bottom;
    for(int i = 1; i = pos; i++) {
        temp = temp->next;
    }
    temp->data = value;
}

int main() {
    Stack s;
    int choice;
    while(true) { 
        cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Display" << endl;
    cout << "4. Is Empty" << endl;
    cout << "5. Peek" << endl;
    cout << "6. Count" << endl;
    cout << "7. Update Value" << endl;
    cout << "8. Exit" << endl;
    cout << "Enter your choice:" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1: cout << "Enter the value:" << endl;
            int value;
            cin >> value;
            s.push(value);
            break;
    case 2: s.pop();
            break;
    case 3: s.display();
            break;
    case 4: if(s.isEmpty()) {
                cout << "Stack is empty" << endl;
            } else {
                cout << "Stack is not empty" << endl;
            }                       
            break;
    case 5: cout << "The top element is:" << s.peek() << endl;
            break;
    case 6: cout << "The number of elements in the stack is:" << s.count() << endl;
            break;
    case 7: int pos, newValue;
            cout << "Enter the position and new value:" << endl;
            cin >> pos >> newValue;
            s.updateValue(pos, newValue);
            break;
    case 8: exit(0);
    default:
        break;
    }
    }
}

