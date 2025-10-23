#include<iostream>
#include<queue>
#include<stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
    private:
    TreeNode* root;
    public:
    BinarySearchTree() {
        root = nullptr;
    }
    bool empty() const;
    void insert(int val);
    void remove(int val);
    bool search(int val);
    void print() const;
    void printPre(TreeNode* node) const;
    void printIn(TreeNode*) const;
    void printPost(TreeNode*) const;
};

/**
 * 判断树是否为空
 * @return 树为空返回 true，否则返回 false
 */
bool BinarySearchTree::empty() const {
    return root == nullptr;
}

/**
 * 插入
 * @param val 插入的值
 * 特点就是插入的数比根节点小，则插入到根节点的左子树，否则插入到根节点的右子树
 */
void BinarySearchTree::insert(int val) {
    TreeNode* node = new TreeNode(val);
    if(empty()) {
        root = node;
        return;
    }
    //每层都需要比较一次
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();
        if(val < cur->val) {
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
}

/**
 * 删除
 * @param val 删除的值
 * 用目标节点的最大子节点替换目标节点，然后删除最大子节点
 */
void BinarySearchTree::remove(int val) {
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
        if (cur->val == val) toDelete = cur;

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
    toDelete->val = last->val;

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
 * 查找
 * @param val 查找的值
 * @return 找到返回 true，否则返回 false
 */
bool BinarySearchTree::search(int val) {
    TreeNode* node = root;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();
        if(cur->val == val) {
            return true;
        }
        if(cur->left != nullptr) q.push(cur->left);
        if(cur->right != nullptr) q.push(cur->right);
    } 
}

/**
 * 打印
 */
// void BinarySearchTree::print() const {
//     if(empty()) {
//         cout << "Tree is empty." << endl;
//         return;
//     }
//     stack<TreeNode*> st;
//     st.push(root);
//     while(!st.empty()) {
//         TreeNode* cur = st.top();
//         st.pop();
//         cout << cur->val << " ";
//         if(cur->right != nullptr) st.push(cur->right);
//         if(cur->left != nullptr) st.push(cur->left);
//     }
//     cout << endl;
// }

/**
 * 前序遍历
 */
void BinarySearchTree::print() const {
    if (empty()) {
        cout << "Tree is empty." << endl;
        return;
    }
    printPre(root);
    // printIn(root);
    //中序遍历
    // printPost(root);
    //后序遍历
    cout << endl;
}
/**
 * 前序遍历辅助函数
 * @param node 当前节点
 */
void BinarySearchTree::printPre(TreeNode* node) const {
    if (node == nullptr) return;
    cout << node->val << " ";
    printPre(node->left);
    printPre(node->right);
}

/**
 * 后序遍历辅助函数
 * @param node 当前节点
 */
void BinarySearchTree::printPost(TreeNode* node) const {
    if (node == nullptr) return;
    printPost(node->left);
    printPost(node->right);
    cout << node->val << " ";
}
/**
 * 中序遍历辅助函数
 * @param node 当前节点
 */
void BinarySearchTree::printIn(TreeNode* node) const {
    if (node == nullptr) return;
    printIn(node->left);
    cout << node->val << " ";
    printIn(node->right);
}

int main() { 
    BinarySearchTree bst;
    cout << "Enter your choice:"
            << "\n1. Insert"
            << "\n2. Remove"
            << "\n3. Search"
            << "\n4. Print"
            << "\n5. Exit" << endl;
    int choice, val;
    while (true) {
        cout << "Choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                bst.insert(val);
                break;
            case 2:
                cout << "Enter value to remove: ";
                cin >> val;
                bst.remove(val);
                break;
            case 3:
                cout << "Enter value to search: ";  
                cin >> val;
                if (bst.search(val)) {
                    cout << val << " found in the tree." << endl;
                } else {
                    cout << val << " not found in the tree." << endl;
                }
                break;
            case 4:
                bst.print();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice." << endl;
}
}
}