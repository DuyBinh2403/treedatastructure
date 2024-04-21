#include <iostream>
#include <stack>
using namespace std;

// Định nghĩa cấu trúc của một nút trong cây
struct TreeNode {
    int value;         // Giá trị của nút
    TreeNode *left;    // Con trỏ đến nút con bên trái
    TreeNode *right;   // Con trỏ đến nút con bên phải

    // Constructor để tạo mới một nút với giá trị cho trước
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

// Hàm để duyệt cây theo kiểu hậu thứ tự sử dụng hai stack
void postOrderTraversalUsingStacks(TreeNode *root) {
    if (root == NULL) return;

    stack<TreeNode*> stack1, stack2;
    stack1.push(root);

    while (!stack1.empty()) {
        TreeNode *node = stack1.top();
        stack1.pop();
        stack2.push(node);

        // Đẩy trái trước rồi đến phải vào stack1
        if (node->left != NULL) {
            stack1.push(node->left);
        }
        if (node->right != NULL) {
            stack1.push(node->right);
        }
    }

    // Khi stack2 được đổ ngược lại, nó sẽ theo thứ tự hậu thứ tự
    while (!stack2.empty()) {
        cout << stack2.top()->value << " ";
        stack2.pop();
    }
}

int main() {
    // Tạo cây nhị phân mẫu
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Duyệt cây theo kiểu hậu thứ tự sử dụng stack
    cout << "Post-order traversal using two stacks: ";
    postOrderTraversalUsingStacks(root);

    return 0;
}
