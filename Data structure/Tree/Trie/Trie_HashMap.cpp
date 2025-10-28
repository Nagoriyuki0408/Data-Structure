#include<iostream>
#include<unordered_map>
using namespace std;
struct TrieNode {
    bool isEnd;
    unordered_map<char, TrieNode*> children;//存储字节点的信息
    TrieNode(): isEnd(false) {}
};

/**
 * 步骤1：插入 "cat"
root
 └── 'c'
       └── 'a'
             └── 't' → [isEnd=true]

步骤2：插入 "car"
root
 └── 'c'
       └── 'a'
           ├── 't' → [isEnd=true]
           └── 'r' → [isEnd=true]

步骤3：插入 "dog"
root
 ├── 'c'
 │     └── 'a'
 │         ├── 't'
 │         └── 'r'
 └── 'd'
       └── 'o'
             └── 'g' → [isEnd=true]

 */

class Trie {
    private:
        TrieNode* root;
    public:
        Trie() {
            root = new TrieNode();
        }
        void insert(const string& word);
        bool search(const string& word);
        bool startWith(const string& prefix);
        void remove(const string& word);
        void print();
        ~Trie() {
            delete root;
        }
};

/**
 * 插入单词
 * @param word
 */
void Trie::insert(const string& word) {
    TrieNode* cur = root;
    for (char c : word) {
        if (cur->children.find(c) == cur->children.end()) {
            cur->children[c] = new TrieNode();
        }
        cur = cur->children[c];
    }
    cur->isEnd = true;
}

/**
 * 查询单词
 * @param word
 */
bool Trie::search(const string& word) {
    TrieNode* cur = root;
    for (char c : word) {
        if (cur->children.find(c) == cur->children.end()) {
            return false;
        }
        cur = cur->children[c];
    }
    return cur->isEnd;
}

/**
 * 查询前缀
 * @param prefix
 */
bool Trie::startWith(const string& prefix) {
    TrieNode* cur = root;
    for (char c : prefix) {
        if (cur->children.find(c) == cur->children.end()) {
            return false;
        }
        cur = cur->children[c];
    }
    return true;
}

/**
 * 删除单词
 * @param word
 */
void Trie::remove(const string& word) {
    TrieNode* cur = root;
    for (char c : word) {
        if (cur->children.find(c) == cur->children.end()) {
            return;
        }
        cur = cur->children[c];
    }
    cur->isEnd = false;
}

/**
 * 递归遍历
 * @param node
 * @param path
 */
void dfs(TrieNode* node,string path) {
    if (node->isEnd) {
        cout << path << endl;
    }
    for (auto& entry : node->children) {
        char c = entry.first;
        TrieNode* child = entry.second;
        dfs(child, path + c);
    }
}

/**
 * 遍历

 */
void Trie::print() {
    string path;
    dfs(root, path);
}

int main() {
    Trie trie;
    int choice;
    while (true) { 
        cout << "1.insert" << endl;
        cout << "2.search" << endl;
        cout << "3.startWith" << endl;
        cout << "4.remove" << endl;
        cout << "5.print" << endl;
        cout << "6.exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Move variable declarations outside switch or enclose them in blocks
        switch (choice) {
            case 1: {
                string word;
                cout << "Enter a word: ";
                cin >> word;
                trie.insert(word);
                cout << "Inserted " << word << endl;
                break;
            }
            case 2: {
                string word1;
                cout << "Enter a word: ";
                cin >> word1;
                if (trie.search(word1)) {
                    cout << "Found " << word1 << endl;
                } else {
                    cout << "Not found " << word1 << endl;
                }
                break;
            }
            case 3: {
                string prefix;
                cout << "Enter a prefix: ";
                cin >> prefix;
                if (trie.startWith(prefix)) {
                    cout << "Found prefix " << prefix << endl;
                } else {
                    cout << "Not found prefix " << prefix << endl;
                }
                break;
            }
            case 4: {
                string word2;
                cout << "Enter a word: ";
                cin >> word2;
                trie.remove(word2);
                cout << "Removed " << word2 << endl;
                break;
            }
            case 5:
                cout << "Printing trie..." << endl;
                trie.print();
                break;
            case 6:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }
}