#include<iostream>
#include<queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class BinaryTree{
    private:
        TreeNode* root;
    public:
        BinaryTree():root(nullptr){}
        void insert(int val);
        void search(int val);
        void height() const;
        void print() const;
        int count() const;
        void remove(int val);
        bool isEmpty() const;
        void deleteDeepest(TreeNode* root, TreeNode* delNode);
};

int BinaryTree::count() const {
    if(isEmpty()) return 0;
    queue<TreeNode*> q;
    q.push(root);
    int count = 0;
    while(!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();
        count++;
        if(cur->left != nullptr) q.push(cur->left);
        if(cur->right != nullptr) q.push(cur->right);
    }
    return count;
}

bool BinaryTree::isEmpty() const{
    return root == nullptr;
}
void BinaryTree::insert(int val){ 
    TreeNode* temp = new TreeNode(val);
    if(isEmpty()) {
        root = temp;
        return;
    } else {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if(cur->left == nullptr) {
                cur->left = temp;
                return;
            } else {
                q.push(cur->left);
            }
            if(cur->right == nullptr) {
                cur->right = temp;
                return;
            } else {
                q.push(cur->right);
            }
        }
    }
}

void BinaryTree::search(int val){
    if(isEmpty()) {
        cout << "The tree is empty\n";
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();
        if(cur->val == val) {
            cout << "Value " << val << " found in the tree\n";
            return;
        }
        if(cur->left != nullptr) q.push(cur->left);
        if(cur->right != nullptr) q.push(cur->right);
    }
}

void BinaryTree::height() const{
    if(isEmpty()) {
        cout << "The tree is empty\n";
        return;
    }
    queue<TreeNode*> q;
    int height = 0;
    q.push(root);
    while(!q.empty()) { 
        int size = q.size();
        for(int i=0; i<size; i++) {
            TreeNode* cur = q.front();
            q.pop();
            if(cur->left != nullptr) q.push(cur->left);
            if(cur->right != nullptr) q.push(cur->right);
        }
        height++;
    }
    cout << "Height of the tree is " << height << "\n";
}

void BinaryTree::print() const{
    if(isEmpty()) {
        cout << "The tree is empty\n";
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();
        cout << cur->val << " ";
        if(cur->left != nullptr) q.push(cur->left);
        if(cur->right != nullptr) q.push(cur->right);
    }
    cout << "\n";
    }

// void BinaryTree::preorder() const {
//     if (root == nullptr) return;
//     stack<TreeNode*> st;
//     st.push(root);

//     while (!st.empty()) {
//         TreeNode* cur = st.top();
//         st.pop();
//         cout << cur->val << " ";

//         // 注意：先右后左，因为栈是后进先出
//         if (cur->right) st.push(cur->right);
//         if (cur->left) st.push(cur->left);
//     }
//     cout << "\n";
// }

// void BinaryTree::inorder() const {
//     stack<TreeNode*> st;
//     TreeNode* cur = root;

//     while (cur != nullptr || !st.empty()) {
//         // 一直往左走到底
//         while (cur != nullptr) {
//             st.push(cur);
//             cur = cur->left;
//         }
//         // 访问栈顶节点
//         cur = st.top();
//         st.pop();
//         cout << cur->val << " ";
//         // 转向右子树
//         cur = cur->right;
//     }
//     cout << "\n";
// }

// void BinaryTree::postorder() const {
//     if (root == nullptr) return;

//     stack<TreeNode*> st1, st2;
//     st1.push(root);

//     while (!st1.empty()) {
//         TreeNode* cur = st1.top();
//         st1.pop();
//         st2.push(cur);

//         if (cur->left) st1.push(cur->left);
//         if (cur->right) st1.push(cur->right);
//     }

//     while (!st2.empty()) {
//         cout << st2.top()->val << " ";
//         st2.pop();
//     }
//     cout << "\n";
// }


void BinaryTree::remove(int key) {
    if (!root) return;

    // 如果树只有一个节点且就是要删的
    if (root->left == nullptr && root->right == nullptr) {
        if (root->val == key) {
            delete root;
            root = nullptr;
        }
        return;
    }

    queue<TreeNode*> q;
    q.push(root);
    TreeNode* target = nullptr;
    TreeNode* last = nullptr;

    // BFS 查找 target 和最后一个节点
    while (!q.empty()) {
        last = q.front();
        q.pop();
        if (last->val == key) target = last;
        if (last->left) q.push(last->left);
        if (last->right) q.push(last->right);
    }

    // 没找到要删的节点
    if (!target) return;

    // 替换数据
    int temp = last->val;
    deleteDeepest(root, last);
    target->val = temp;
}


void BinaryTree::deleteDeepest(TreeNode* root, TreeNode* delNode) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();

        if (node->left) {
            if (node->left == delNode) {
                delete node->left;
                node->left = nullptr;
                return;
            } else q.push(node->left);
        }

        if (node->right) {
            if (node->right == delNode) {
                delete node->right;
                node->right = nullptr;
                return;
            } else q.push(node->right);
        }
    }
}

int main() {
    BinaryTree tree;
    cout << "1. Insert\n2. Search\n3. Count\n4. Height\n5. Print\n6. Remove\n7. Exit\n";
    int choice;
    while (1) {
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                int val;
                cin >> val;
                tree.insert(val);
                break;
            case 2:
                cout << "Enter value to search: ";
                int val1;
                cin >> val1;
                tree.search(val1);
                break;
            case 3:
                cout << "Count: " << tree.count() << "\n";
                break;
            case 4:
                tree.height();
                break;
                case 5:
                tree.print();
                break;
            case 6:
                cout << "Enter value to remove: ";
                int val2;
                cin >> val2;
                tree.remove(val2);
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
}