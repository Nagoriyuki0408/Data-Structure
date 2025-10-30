#include<iostream>
#include<vector>
using namespace std;

template <typename K, typename V>
struct MapNode {
    K Key;
    V Value;
    MapNode<K,V> *next;
    MapNode(K key, V value) {
        Key = key;
        Value = value;
        next = nullptr;
    }
};


class MyHashMap {
    private:
    vector<MapNode<int, int>*> head;
    int size;
    int buckets;
    int hash(int key) {
        return key % buckets;
    }
    public:
    MyHashMap(int buckets) {
        this->buckets = buckets;
        this->size = 0;
    }
    
    void insert(int key, int value);
    int getValue(int key);
    void remove(int key);
    bool containsKey(int key);
    void rehash();
    int loadFactor();   
};

/**
 * @brief Inserts a key-value pair into the hash map.
 * 
 * @param key The key to be inserted.
 * @param value The value to be inserted.

 */
void MyHashMap::insert(int key, int value) {
    int index = hash(key);
    MapNode<int,int>* temp = new MapNode<int,int>(key, value);
    //TODO : Implement the insert function
    MapNode<int,int>* curr = head[index];
    while(curr != nullptr) {
        if(curr->next == nullptr) {
            curr->next = temp;
            rehash();
            return;
        }
        curr = curr->next;
    }
}

/** 
 * @brief Returns the value associated with the given key.
 * @param key The key whose value is to be returned.
 */
void MyHashMap::remove(int key) {
    int index = hash(key);
    MapNode<int,int>* curr = head[index];
    MapNode<int,int>* prev = NULL;
    while(curr != NULL) {
        if(curr->Key == key) {
            if(prev == NULL) {
                head[index] = curr->next;
            } else {
                prev->next = curr->next;
            }
            delete curr;
        }
    }

}

/**
 * @brief Returns true if the hash map contains the given key.
 * @param key The key to be checked.
 */
int MyHashMap::getValue(int key) {
    int index = hash(key);
    MapNode<int,int>* curr = head[index];
    while(curr != nullptr) {
        if(curr->Key == key) {
            return curr->Value;
        }
        curr = curr->next;
    }
    return -1;
}

/** 
 * @brief Returns true if the hash map contains the given key.
 */
int MyHashMap::loadFactor() {
    return size/buckets;
}

/**
 * @brief Returns true if the hash map contains the given key.
 * @param key The key to be checked.
 */
bool MyHashMap::containsKey(int key) {
  int index = hash(key);
  MapNode<int,int>* curr = head[index];
  while(curr != nullptr) {
  	if(curr->Key == key) {
	return true;
	}
	curr = curr->next;
  }
  return false;
}

/**
 * @brief Rehashes the hash map.

 */
void MyHashMap::rehash() {
    if(loadFactor() > 0.7) {
        vector<MapNode<int,int>*> oldHead = head;
        this->buckets *= 2;
        head = vector<MapNode<int,int>*>(buckets);
        for(int i = 0; i < oldHead.size(); i++) { 
        MapNode<int,int>* curr = oldHead[i];
        while(curr != nullptr) {
            int index = hash(curr->Key);
            MapNode<int,int>* temp = curr;
            curr = curr->next;
            temp->next = head[index];
            head[index] = temp;
        }
        }
    } else {
        return;
    }
}

int main(){
    MyHashMap m(5);
    while(1) {
        cout << "1. Insert\n2. Get\n3. Remove\n4. Contains Key\n5. Rehash\n6. Load Factor\n7. Exit\n";
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                int key, value;
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> value;
                m.insert(key, value);
                break;
            case 2:
                cout << "Enter key: ";
                cin >> key;
                cout << m.getValue(key) << endl;
                break;
                case 3:
                cout << "Enter key: ";
                cin >> key;
                m.remove(key);
                break;
                case 4:
                cout << "Enter key: ";
                cin >> key;
                cout << m.containsKey(key) << endl;
                break;
                case 5:
                m.rehash();
                break;
                case 6:
                cout << m.loadFactor() << endl;
                break;
                case 7:
                return 0;
        }
    }
}