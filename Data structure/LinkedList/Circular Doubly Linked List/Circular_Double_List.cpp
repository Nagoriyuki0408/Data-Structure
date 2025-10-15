#include<iostream>

using namespace std;

struct Node {
    Node* next;
    Node* prev;
    int data;
};

class CircularDoubleList {
    private:
    Node* head;
    int size;
    public:
    CircularDoubleList() {
        head = nullptr;
        size = 0;
    }
    void append(int data);
    void insertAtBegin(int data);
    void insertAfter(int new_node_data, int prev_node_data);
    void display() const;
    void findSize() const;
    void ReverseList(Node **Head);
};

void CircularDoubleList::insertAtBegin(int data) {
    Node* temp = new Node();
    if(this->head == nullptr) {
        this->head=temp;
        this->head->next = this->head;
        this->head->prev = this->head;
    } else {
        Node* cur = this->head;
        while(cur->next != this->head) {
            cur = cur -> next;
        }
        temp->next = this->head;
        temp->prev = cur;
        cur->next = temp;
        this->head->prev = temp;
        this->head = temp;
    }
    temp -> data = data;
    size++;
}

void CircularDoubleList::append(int data) {
    Node* temp = new Node();
    temp -> data = data;
    if(this->head == nullptr) {
        this->head=temp;
        this->head->next = this->head;
        this->head->prev = this->head;
        
    } else {
        Node* cur = this->head;
        while(cur->next != this->head) {
            cur = cur -> next;
        }
        cur->next = temp;
        temp->prev = cur;
        temp->next = this->head;
        this->head->prev = temp;
    }
    size++;
    cout<<"The size of this list is:"<<size<<endl;
}

void CircularDoubleList::insertAfter( int new_node_data, int prev_node_data) {
    Node* temp = new Node();
    temp -> data = new_node_data;
    Node* cur = this->head;
    while(cur->data != prev_node_data) {
        cur = cur -> next;
        if(cur == this->head) return;
    }
    temp->next = cur->next;
    cur->next = temp;
    temp->prev = cur;
    temp->next->prev = temp;
    size++;
}

void CircularDoubleList::display() const {
    if (head == nullptr) {
        return;
    }
    Node* cur = head;
    do {
        cout << cur->data << " ";
        cur = cur->next;    // ✅ 别忘了移动！
    } while (cur != head);   // ✅ 回到起点停止
    cout << endl;
}


void CircularDoubleList::findSize() const {
    cout<<"The size of this list is:"<<this->size<<endl;
}

void CircularDoubleList::ReverseList(Node **head) {
    Node* start = *head;

}
int main() {
    CircularDoubleList list;
    int choice;
    while (true) {
        cout << "\n=== Circular Doubly Linked List Menu ===\n";
        cout << "1. append (尾插)\n";
        cout << "2. insertAtBegin (头插)\n";
        cout << "3. insertAfter (在指定值后插入)\n";
        cout << "4. display (显示链表)\n";
        cout << "5. findSize (显示长度)\n";
        cout << "0. exit\n";
        cout << "请选择: ";
        cin>>choice;
        if (choice == 0) {
            cout << "退出，bye~\n";
            break;
        }

        int x, y;
        switch (choice) {
            case 1:
                cout << "输入要追加的整数: ";
                cin >> x;
                list.append(x);
                cout << "已追加 " << x << "\n";
                break;
            case 2:
                cout << "输入要头插的整数: ";
                cin >> x;
                list.insertAtBegin(x);
                cout << "已头插 " << x << "\n";
                break;
            case 3:
                cout << "输入要插入的新值: ";
                cin >> x;
                cout << "输入要插入的位置（在该值之后）: ";
                cin >> y;
                list.insertAfter(x, y);
                cout << "尝试在值 " << y << " 后插入 " << x << "（若未找到该值则不插入）\n";
                break;
            case 4:
                list.display();
                break;
            case 5:
                list.findSize();
                break;
            default:
                cout << "无效选项。\n";
        }
    }

    return 0;
}
