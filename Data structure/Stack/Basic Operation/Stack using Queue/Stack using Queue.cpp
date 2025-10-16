#include<iostream>
#include<queue>
#include<stack>
using namespace std;


class Stack{
    private:
        queue<int> q1, q2;
    public:
        void push(int data);
        void pop();
        bool isEmpty();
        int peek();
        void top() const;
        int count() const;
        void display() const;
};

void Stack::push(int data) {
    q2.push(data);
    while(!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
    }
    swap(q1, q2);
}

void Stack::pop() {
    if(isEmpty()) {
        cout << "Stack is empty" << endl;
        return;
    }
    q1.pop();
}

bool Stack::isEmpty() {
    return q1.empty();
}

int Stack::peek() {
    if(isEmpty()) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return q1.front();
}

int Stack::count() const {
    return q1.size();
}

void Stack::display() const {
    if (q1.empty()) {
        cout << "Stack is empty" << endl;
        return;
    }

    // 不能改变 q1，所以拷贝一个临时队列遍历，再用辅助栈反转顺序
    queue<int> temp = q1;
    stack<int> rev;
    while (!temp.empty()) {
        rev.push(temp.front());
        temp.pop();
    }

    cout << "Stack elements (top -> bottom): ";
    while (!rev.empty()) {
        cout << rev.top() << " ";
        rev.pop();
    }
    cout << endl;
}
int main() { 
    Stack s;
    int choice;
    while(true) { 
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Count" << endl;
        cout << "5. Display" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1: {
                int data;
                cout << "Enter data to push: ";
                cin >> data;
                s.push(data);
                break;
            }
            case 2: {
                s.pop();
                break;
            }
            case 3: {
                cout << "Top element is: " << s.peek() << endl;
                break;
            }
            case 4: {
                cout << "Number of elements in stack: " << s.count() << endl;
                break;
            }
            case 5: {
                s.display();
                break;
            }
            case 6: {
                exit(0);
            }
            default: {
                cout << "Invalid choice" << endl;
            }
        }
    }
    return 0;
}
