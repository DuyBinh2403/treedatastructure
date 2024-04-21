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

// Hàm để duyệt cây theo kiểu trung thứ tự
void inOrderTraversal(TreeNode* root) {
    if (root == NULL) return; // Nếu nút hiện tại là NULL, dừng việc duyệt

    // Duyệt qua nhánh trái
    inOrderTraversal(root->left);
    // In giá trị của nút gốc
    cout << root->value << " ";
    // Duyệt qua nhánh phải
    inOrderTraversal(root->right);
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

    // Duyệt cây theo kiểu trung thứ tự
    cout << "In-order traversal: ";
    inOrderTraversal(root);

    return 0;
}

