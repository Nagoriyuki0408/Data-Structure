#include<iostream>
using namespace std;

# define SIZE 5

class Stack {
    private:
        int Pop;
        int stack[SIZE];
    public:
        Stack() {
            Pop = -1;
        }
        void push(int x);
        void display();
        void pop();
};

void Stack::push(int x) {
    if(this->Pop == SIZE - 1) {
        cout << "Stack Overflow" << endl;
    } else {
        this->stack[++this->Pop] = x;
        cout << "Pushed " << x << endl;
        this->display();
    }
}

void Stack::pop() {
    if(this -> Pop == -1) {
        cout << "Stack Underflow" << endl;
    } else {
        this-> Pop--;
    }
}

void Stack::display() {
    if (this->Pop == -1) {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Pop: " << this->Pop << endl;
    for(int i = this->Pop; i >= 0; i--) {
        cout<< this->stack[i] << " ";
    } 
    cout << "Pop: " << this->Pop << endl;
    cout << endl;
}

int main() {
    Stack st;
    int choice;
    while(true) {
    cout << "Enter your choice;" << endl;
    cout << "1. push" << endl;
    cout << "2. pop"  << endl;
    cout << "3. display" << endl;
    cout << "0. exit" << endl;
    cin >> choice;
    switch(choice) {
        case 1:
            st.push(3);
            break;
        case 2:
            st.pop();
            break;
        case 3:
            st.display();
            break;
        case 0:
            return 0;
    }
    }
}