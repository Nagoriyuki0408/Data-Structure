#include<iostream>
#include<queue>
using namespace std;


struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data) {
        this->data = data;
        left = right = nullptr;
    }
};
// │ + MyTreeSet()                           │
// │ + insert(value : T) : void              │
// │ + remove(value : T) : void              │
// │ + contains(value : T) : bool            │
// │ + getMin() : T                          │
// │ + getMax() : T                          │
// │ + isEmpty() : bool                      │
// │ + getSize() : int                       │
// │ + inorder() : void    
class TreeSet {
    private:
        TreeNode* root;
        int size;
    public:
        TreeSet() {
            root = nullptr;
            size = 0;
        }
        void insert(int val);
        void remove(int val);
        bool contains(int val);
        int getMin();
        int getMax();
        bool isEmpty();
        int getSize();
        void inorder();
        TreeNode* findLast();
        TreeNode* search(int val);
};

bool TreeSet::isEmpty() {
    return root == nullptr;
}

/**
 * @brief 向TreeSet中插入元素
 * @param val 要插入的元素
 */
void TreeSet::insert(int val) {
    TreeNode* newNode = new TreeNode(val);
    if(isEmpty()) {
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        if(temp->left == nullptr) {
            temp->left = newNode;
            this->size++;
        } else {
            q.push(temp->left);
        }
        if(temp->right == nullptr) {
            temp->right = newNode;
        } else {
            q.push(temp->right);
            this->size++;
        }
    }
}

/**
 * @brief 清理掉某个特定的元素
 * @param val要清理掉的元素的值
 */
 void TreeSet::remove(int val) {
    if(isEmpty()) {
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        if(temp->data == val) {
            TreeNode*curr = findLast();
            std::swap(curr->data, temp->data);
            delete curr;
        }
        if(temp->left != nullptr) q.push(temp->left);
        if(temp->right !=nullptr) q.push(temp->right);
    }
 }

 /**
  * @brief 找到一个二叉树的最后一个节点,并返回
  */
TreeNode* TreeSet::findLast() {
    if (isEmpty()) {
        return nullptr;
    }
    std::queue<TreeNode*> q;
    q.push(root);
    TreeNode* last = nullptr;
    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        last = temp;                      // 记录此时访问的节点指针
        if (temp->left)  q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
    return last;
}

 /**
  * @brief  搜索一个元素并返回对应的结点
  * @param val 要搜索的节点的值
  */
TreeNode* TreeSet::search(int val) {
    if (isEmpty()) {
        return nullptr;  // 返回空指针表示没有找到／树空
    }
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        if (temp->data == val) {
            return temp;
        }
        if (temp->left)  q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
    return nullptr; // 遍历完了也没找到，仍返回 nullptr
}

 /**
  * @brief  返回一个树集合的大小
  */
int TreeSet::getSize(){
    return this->size;
}


/**
 * @brief 检查是否包含val
 * @param val,要检查的元素
 */

bool TreeSet::contains(int val){
    if(isEmpty()) return false;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        if(temp->data == val) {
            return true;
        }
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    return false;
}

/**
 * @brief 获取最小值
 */
int TreeSet::getMin() {
        if(isEmpty()) return 0;
    queue<TreeNode*> q;
    q.push(root);
    int Min = 0;
    while(!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        Min = std::min(Min,temp->data);
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    return Min;
}

/**
 * @brief 获取最大值
 */
int TreeSet::getMax() {
    if(isEmpty()) return 0;
    queue<TreeNode*> q;
    q.push(root);
    int Max = 0;
    while(!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        Max = std::max(Max,temp->data);
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    return Max;
}

/**
 * @brief 中序遍历
 */
void TreeSet::inorder() {
    if(isEmpty()) return;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        cout << temp->data <<endl;
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}

int main() {
    TreeSet ts;

    while(true) { 
    cout << "1.insert" << endl;
    cout << "2.remove" << endl;
    cout << "3.contains" << endl;
    cout << "4.getMin" << endl;
    cout << "5.getMax" << endl;
    cout << "6.isEmpty" << endl;
    cout << "7.getSize" << endl;
    cout << "8.inorder" << endl;
    cout << "9.exit" << endl;
    int choice;
    cout << "请选择：";
    cin >> choice;
    switch(choice) {
        case 1: {
            int val;
            cout << "请输入要插入的元素：";
            cin >> val;
            ts.insert(val);
            break;
        }
        case 2: {
            int val;
            cout << "请输入要删除的元素：";
            cin >> val;
            ts.remove(val);
            break;
        }
        case 3: {
            int val;
            cout << "请输入要查找的元素：";
            cin >> val;
            cout << ts.contains(val) << endl;
            break;
        }
        case 4: {
            cout << ts.getMin() << endl;
            break;
        }
        case 5: {
            cout << ts.getMax() << endl;
            break;
        }
        case 6: {
            cout << ts.isEmpty() << endl;
            break;
        }
        case 7: {
            cout << ts.getSize() << endl;
            break;
        }
        case 8: {
            ts.inorder();
            break;
        }
        case 9: {
            return 0;
        }
        default: {
            cout << "输入错误" << endl;
            break;
        }
    }
    }
}