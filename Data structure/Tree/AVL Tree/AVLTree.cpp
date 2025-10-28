#include<iostream>
#include<queue>
using namespace std;
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    int height;
    TreeNode(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
        this->height = 1;
    }
};

class AVLtree {
    private:
    TreeNode* root;
    public:
    AVLtree() {
        root = nullptr;
        cout << "AVL Tree" << endl;
        display();
    }
    bool isEmpty();
    void insert(int data);
    void remove(int data);
    void display();
    int height(TreeNode* node);
    int balanceFactor(TreeNode* node);
    TreeNode* rightRotate(TreeNode* node);
    TreeNode* leftRotate(TreeNode* node);
    TreeNode* balance(TreeNode* node);
    TreeNode* minValueNode(TreeNode* node);
};

/**
 * Check if tree is empty
 */
bool AVLtree::isEmpty() {
    return (root == nullptr);
}


/**
 * Get height of tree
 * @param node
 */
int AVLtree::height(TreeNode* node) {
    int height = 0;
    if(root == nullptr) {
        return height;
    }
    queue<TreeNode*> q;
    q.push(root);
    int size = q.size();
    while(size > 0) {
        height++;
        for(int i = 0; i < size; i++) {
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left != nullptr) {
                q.push(temp->left);
            }
            if(temp->right != nullptr) {
                q.push(temp->right);
            }
        }
        if(q.front() == node) break;
        size = q.size();    
    }
    return height;
}

/**
 * Get balance factor of tree
 * @param node
 */
int AVLtree::balanceFactor(TreeNode* node) {
    if(node == nullptr) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

/**
 * Right rotate
 * @param node
 */
TreeNode* AVLtree::rightRotate(TreeNode* node) {
    TreeNode* y = node;
    TreeNode* x = node->left;
    y->left = x->right;
    x->right = y;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return x;
}

/**
 * left rotate
 * @param node
 */
TreeNode* AVLtree::leftRotate(TreeNode* node) {
    TreeNode* y = node;
    TreeNode* x = node->right;
    y->right = x->left;
    x->left = y;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return x;
}

/**
 * Balance tree
 * @param node

 */
TreeNode* AVLtree::balance(TreeNode* node) { 
    int balance = balanceFactor(node);
    if(balance > 1) { 
        if(balanceFactor(node->left) > 0) {
            node = rightRotate(node);
        } else {
            node = leftRotate(node);
        }
    }
    if(balance < -1) { 
        if(balanceFactor(node->right) < 0) {
            node = leftRotate(node);
        } else {
            node = rightRotate(node);
        }
    }

    return node;
}

/**
 * Insert node
 * @param data
 */
void AVLtree::insert(int data) {
    TreeNode* node = new TreeNode(data);
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();
        if(data < cur->data) {
            if(cur->left == nullptr) {
                cur->left = node;
                return;
            } else {
                q.push(cur->left);
            }   
        } else {
            if(cur->right == nullptr) {
                cur->right = node;
                return;
            } else {
                q.push(cur->right);
            }
        }
    }
    root = balance(root);
}

/**
 * Remove node
 * @param data

 */
void AVLtree::remove(int data) { 
    if (root == nullptr) return;

    TreeNode* toDelete = nullptr;
    TreeNode* last = nullptr;
    TreeNode* parentOfLast = nullptr;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();

        // 记录要删除的节点
        if (cur->data == data) toDelete = cur;

        // BFS 一直走到最后一个节点
        if (cur->left) {
            parentOfLast = cur;
            q.push(cur->left);
        }
        if (cur->right) {
            parentOfLast = cur;
            q.push(cur->right);
        }

        last = cur;  // 每次更新，结束时即为最后节点
    }

    // 如果没找到目标值
    if (toDelete == nullptr) return;

    // 用最后节点值替换
    toDelete->data = last->data;

    // 删除最后节点（根据 parentOfLast 来判断左右）
    if (parentOfLast) {
        if (parentOfLast->right == last)
            parentOfLast->right = nullptr;
        else
            parentOfLast->left = nullptr;
    } else {
        // 特殊情况：整棵树只有一个节点
        root = nullptr;
    }

    delete last;
}

/**
 * Display tree
 */
void AVLtree::display() {
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();
        cout << cur->data << " ";
        if(cur->left != nullptr) {
            q.push(cur->left);
        }
        if(cur->right != nullptr) {
            q.push(cur->right);
        }
    }
}
 
int main() { 
    AVLtree tree;

    while(true) { 
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "1. Insert" << endl;
        cout << "2. Remove" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        switch(choice) {
            case 1:
                cout << "Enter data: ";
                int data;
                cin >> data;
                tree.insert(data);
                break;
            case 2:
                cout << "Enter data: ";
                int data2;
                cin >> data2;
                tree.remove(data2);
                break;
            case 3:
                tree.display();
                cout << endl;
                break;
                case 4:
                return 0;
        }
    }
}