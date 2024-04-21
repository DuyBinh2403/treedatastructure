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

// Hàm để duyệt cây theo kiểu tiền thứ tự sử dụng stack
void preOrderTraversalUsingStack(TreeNode *root) {
    if (root == NULL) return;

    stack<TreeNode*> stk;
    stk.push(root);

    while (!stk.empty()) {
        TreeNode *node = stk.top();
        stk.pop();

        // Xử lý nút hiện tại
        cout << node->value << " ";

        // Đẩy con phải vào stack trước (do stack là LIFO, con trái sẽ được xử lý trước)
        if (node->right != NULL) {
            stk.push(node->right);
        }
        
        // Đẩy con trái vào stack
        if (node->left != NULL) {
            stk.push(node->left);
        }
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

    // Duyệt cây theo kiểu tiền thứ tự sử dụng stack
    cout << "Pre-order traversal using stack: ";
    preOrderTraversalUsingStack(root);

    return 0;
}
