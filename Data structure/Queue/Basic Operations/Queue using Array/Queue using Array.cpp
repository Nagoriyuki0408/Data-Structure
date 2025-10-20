#include<iostream>
using namespace std;

class QueueinArray {
    private:
    int front;
    int rear;
    int size = 0;
    int arr[100];
    public:
    QueueinArray() {
        front = 0;
        rear = 0;
    }
    bool empty();
    int count();
    void enqueue(int val);
    void dequeue();
    void display() const;
    void peek() const;
};

bool QueueinArray::empty() {
    return front == rear;
}

int QueueinArray::count() {
    if(empty()) {
        return 0;
    } else {
        return rear - front;
    }
}

void QueueinArray::enqueue(int val) {
    arr[rear] = val;
    rear++;
}

void QueueinArray::dequeue() {
    front++;
}

void QueueinArray::display() const {
    for(int i = front; i < rear; i++) {
        cout << arr[i] << " ";
    }
}

void QueueinArray::peek() const {
    cout << arr[front] << endl;
}


int main() {
    QueueinArray qa;
    while(true) {
        int choice;
        cout << "Enter your choice: " << endl;
        cout << "1. enqueue()" << endl;
        cout << "2. dequeue()" << endl;
        cout << "3. peek()" << endl;
        cout << "4. display()" << endl;
        cout << "5. count()" << endl;
        cout << "6. empty()" << endl;
        cout << "7. exit()" << endl;
        cin >> choice;

        switch(choice) {
            case 1: {
                cout << "Enter the value to be inserted: " << endl;
                int val;
                cin >> val;
                qa.enqueue(val);
                break;
            }
            case 2:
                qa.dequeue();
                break;
            case 3:
                qa.peek();
                break;
            case 4:
                qa.display();
                break;
            case 5:
                cout << qa.count() << endl;
                break;
            case 6:
                if(qa.empty()) {
                    cout << "Queue is empty" << endl;
                } else {
                    cout << "Queue is not empty" << endl;
                }
                break;
            case 7:
                return 0;

            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    }
}
