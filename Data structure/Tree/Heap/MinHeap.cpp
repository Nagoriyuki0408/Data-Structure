#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class MinHeap {
    private:
    vector<int> heap;
    int size;
    int capacity;
    int left(int i) {
        return 2*i + 1;
    }
    int right(int i) {
        return 2*i + 2;
    }

    int parent(int i) {
        return (i-1)/2;
    }
    void heapify(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if(i< size && heap[l] < heap[smallest]) {
            smallest = l;
        }
        if(i< size && heap[r] < heap[smallest]) {
            smallest = r;
        }
        if(smallest != i) {
            std::swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }
    public:
    MinHeap(int cap) {
        heap.resize(cap);
        size = 0;
        capacity = cap;
    }
    void insert(int val);
    int getMin();
    int extractMin();
    void decreaseKey(int i, int new_val);
    void deleteKey(int i);
    void printHeap();
};

/**
 * Inserts a new element into the heap
 * @param val the value to be inserted
 */
void MinHeap::insert(int val) {
    if(size == capacity) {
        cout<<"Heap is full"<<endl;
        return;
    }
    size++;
    int i = size - 1;
    heap[i] = val;
    while(i != 0 && heap[parent(i)] > heap[i]) {
        std::swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}
/**
 * Returns the minimum element in the heap
 * @return the minimum element
 */
int MinHeap::getMin() {
    if(size == 0) {
        return -1; 
    return heap[0];
}
}

/**
 * Decreases the value of the element at index i to new_val
 * @param i the index of the element to be decreased
 * @param new_val the new value of the element
 */
int MinHeap::extractMin() {
    if(size == 0) {
        return -1;
    }
    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapify(0);
    return root;
}

void MinHeap::decreaseKey(int i, int new_val) {
    heap[i] = new_val;
    while(i != 0 && heap[parent(i)] > heap[i]) {
        std::swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

/**
 * Deletes the element at index i from the heap
 * @param i the index of the element to be deleted
 */
void MinHeap::deleteKey(int i) {
    decreaseKey(i, INT_MIN);
    extractMin();
}

/**
 * Prints the heap
 */
void MinHeap::printHeap() {
    for(int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() { 
    MinHeap h(11);

    
    while(1) { 
    cout <<"1. Insert\n"
    <<"2. Extract Min\n"
    <<"3. Get Min\n"
    <<"4. Decrease Key\n"
    <<"5. Delete Key\n"
    <<"7. Print Heap\n"
    <<"6. Exit\n";
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;    
    switch(choice) {
        case 1:
            int val;
            cout << "Enter value to be inserted: ";
            cin >> val;
            h.insert(val);
            break;
        case 2:
            cout << h.extractMin() << " extracted\n";
            break;
        case 3:
            cout << "Minimum element is " << h.getMin() << endl;
            break;
        case 4:
            int i, new_val;
            cout << "Enter index and new value: ";
            cin >> i >> new_val;
            h.decreaseKey(i, new_val);
            break;
        case 5:
            int j;
            cout << "Enter index to be deleted: ";
            cin >> j;
            h.deleteKey(j);
            break;
            case 6:
            return 0;
            case 7:
            h.printHeap();
            break;
    }
    }

}