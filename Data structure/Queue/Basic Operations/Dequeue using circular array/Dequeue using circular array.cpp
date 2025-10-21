#include<iostream>
using namespace std;
class Queue {
    private:
        int front, rear, size;
        int *Q;
    public:
        Queue(int size) {
            front = rear = -1;
            this->size = size;
            Q = new int[size];
        }
        bool isEmpty() const;
        int count() const;
        void enqueue(int val);
        void dequeue();
        void display() const;
        void peek() const;
        ~Queue() {
            delete []Q;
        }
};

bool Queue::isEmpty() const {
    return (front == rear);
}
int Queue::count() const {
    return (rear - front);
}
void Queue::enqueue(int val) {
    if((rear + 1) % size == front) {
        cout << "Queue is Full" << endl;
        return;
    }
    rear = (rear + 1) % size;
    Q[rear] = val;
}
void Queue::dequeue() {
    if(isEmpty()) {
        cout << "Queue is Empty" << endl;
        return;
    }
    front = (front + 1) % size;
}
void Queue::display() const {
    if(isEmpty()) {
        cout << "Queue is Empty" << endl;
        return;
    }
    for(int i = (front + 1) % size; i != (rear + 1) % size; i = (i + 1) % size) {
        cout << Q[i] << " ";
    }
}
void Queue::peek() const {
    if(isEmpty()) {
        cout << "Queue is Empty" << endl;       
        return;
    }
    cout << Q[(front + 1) % size] << endl;
}   

int main() { 
    int size;
    cout << "Enter size of Queue: ";
    cin >> size;
    Queue q(size);
    int choice, val;
    while(1) {
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Count" << endl;
        cout << "5. Peek" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter value to be inserted: ";
                cin >> val;
                q.enqueue(val);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Number of elements in Queue: " << q.count() << endl;
                break;
            case 5:
                q.peek();
                break;
            case 6:
                exit(0);
            default:
                cout << "Invalid Choice" << endl;
        }
    }

}