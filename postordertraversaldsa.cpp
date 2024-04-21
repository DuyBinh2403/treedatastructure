#include <iostream>
using namespace std;

// Định nghĩa cấu trúc của một nút trong cây
struct TreeNode {
    int value;         // Giá trị của nút
    TreeNode* left;    // Con trỏ đến nút con bên trái
    TreeNode* right;   // Con trỏ đến nút con bên phải

    // Constructor để tạo mới một nút với giá trị cho trước
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

// Hàm để duyệt cây theo kiểu hậu thứ tự
void postOrderTraversal(TreeNode* root) {
    if (root == NULL) return; // Nếu nút hiện tại là NULL, dừng việc duyệt

    // Duyệt qua nhánh trái
    postOrderTraversal(root->left);
    // Duyệt qua nhánh phải
    postOrderTraversal(root->right);
    // In giá trị của nút gốc
    cout << root->value << " ";
}

int main() {
    // Tạo cây nhị phân mẫu
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Duyệt cây theo kiểu hậu thứ tự
    cout << "Post-order traversal: ";
    postOrderTraversal(root);

    return 0;
}





