#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
    private:
    int val;
    Node* next;
    Node* prev;
    public:
    DoublyLinkedList() {
        val = 0;
        next = nullptr;
        prev = nullptr;
    }
    DoublyLinkedList(int a) {
        val = a;
        next = nullptr;
        prev = nullptr;
    }
    DoublyLinkedList(int a, Node* n, Node* p) {
        val = a;
        next = n;
        prev = p;
    }
    void append(Node** head_ref, int new_data) ;
    void printList(Node* node);
    void push(Node** head_ref, int new_data);

};

void push(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->val = new_data;
    new_node->next = *head_ref;
    new_node->prev = nullptr;
    if(*head_ref != nullptr) {
        (*head_ref)->prev = new_node;
    }
    *head_ref = new_node;
}

void append (Node** head_ref, int new_data) {
    Node* new_node =new Node();
    Node* last = *head_ref;
    new_node->val = new_data;
    new_node->next =nullptr;
    if(*head_ref == nullptr) {
        new_node->prev = nullptr;
        *head_ref = new_node;
        return;
    }
    while(last->next != nullptr) {
        last = last -> next;
    }
    last -> next = new_node;
    new_node->prev = last;
    return ;
}

void printList(Node* node) {
    Node* last;
    cout<<"\nTraversal in forward direction \n";
    while(node != nullptr) {
        cout<<" "<<node -> val<<" ";
        last = node;
        node = node -> next;
    }

    cout<<"\nTraversal in reverse direction \n";
    while(last != nullptr) {
        cout<<" "<<last -> val<<" ";
        last = last -> prev;
    }
}

int main() {
    Node* head = nullptr;
    append(&head,6);
    push(&head,5);
    append(&head,7);
    printList(head);
    return 0;
}
