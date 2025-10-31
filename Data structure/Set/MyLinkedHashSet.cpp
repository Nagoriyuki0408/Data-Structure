#include<iostream>
using namespace std;

template<typename T>
struct Node {
    T data;
    Node* next;
    Node(T val) {
        data = val;
        next = nullptr;
    }
    Node() {
        next = nullptr;
    }
};

class MyLinkedHashSet {
    private:
        int size;
        Node<int>* root;
    public:
        MyLinkedHashSet(int size) {
            this->size = size;
            root = nullptr;
        }
        MyLinkedHashSet() {
            size = 0;
            root = nullptr;
        }
        void insert(int val);
        bool search(int val);
        void remove(int val);
        void print();
        bool isEmpty();
        bool isExist(int val);

        ~MyLinkedHashSet() {
            delete root;
        }
};

/**
 * @brief Returns true if this set contains the specified element.
 * @param val The value to be checked.
 * @return True if the set contains the specified element, false otherwise.
 */
bool MyLinkedHashSet::isEmpty() {
    return root == nullptr;
}

/** 
 * @brief Inserts a value into the set.
 * @param val The value to be inserted.
 */
void MyLinkedHashSet::insert(int val) {
    Node<int>* cur = this->root;
    Node<int>* temp = new Node<int>(val);
    if(isEmpty()) {
        root = temp;
        this->size++;
        return;
    }
    if(isExist(val)) {
        return;
    }
    while(cur->next != nullptr) {
        cur = cur->next;
        
    }
    cur->next = temp;
    this->size++;
    return;
}

/**
 * @brief Removes a value from the set.
 * @param val The value to be removed.
 */
bool MyLinkedHashSet::search(int val) {
    if(isEmpty()) {
        return false;
    }
    Node<int>* cur = this->root;
    while(cur != nullptr) {
        if(cur->data == val) {
            return true;
        }
        cur = cur->next;
    }
    return false;
}

/**
 * @brief Removes a value from the set.
 * @param val The value to be removed.
 */
void MyLinkedHashSet::remove(int val) {
    if(isEmpty()) {
        return ;
    }
    Node<int>* cur = this->root;
    while(cur->next->data != val ) {
        cur = cur->next;
    }
    Node<int>* temp = cur->next;
    if(cur->next->next == nullptr) {
        cur->next = nullptr;
        delete temp;
        this->size--;
    } else {
        cur->next = temp->next;
        delete temp;
        this->size--;
    }
}

/**
 * @brief Prints all the values in the set.
 */
void MyLinkedHashSet::print() {
    Node<int>* cur = this->root;
    while(cur != nullptr) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;

}

/**
 * @brief Checks if a value exists in the set.
 * @param val The value to be checked.
 */
bool MyLinkedHashSet::isExist(int val) {
    if(search(val)) {
        cout << "The value " << val << " exists in the set." << endl;
        return true;
    } else {
        cout << "The value " << val << " does not exist in the set." << endl;
        return false;
    }
}

int main() { 
    MyLinkedHashSet set(10);
    while(1) {
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Remove" << endl;
        cout << "4. Print" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter the value to be inserted: ";
                int val;
                cin >> val;
                set.insert(val);
                break;
            case 2:
                cout << "Enter the value to be searched: ";
                cin >> val;
                set.isExist(val);
                break;
            case 3:
                cout << "Enter the value to be removed: ";
                cin >> val;
                set.remove(val);
                break;
                case 4:
                set.print();
                break;
                case 5:
                cout << "Exiting..." << endl;
                return 0;
                default:
                cout << "Invalid choice" << endl;
                break;
        }
    }
}