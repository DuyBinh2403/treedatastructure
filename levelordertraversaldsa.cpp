#include <iostream>
#include <queue>
using namespace std;

// Định nghĩa cấu trúc của một nút trong cây
struct TreeNode {
    int value;         // Giá trị của nút
    TreeNode *left;    // Con trỏ đến nút con bên trái
    TreeNode *right;   // Con trỏ đến nút con bên phải

    // Constructor để tạo mới một nút với giá trị cho trước
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

// Hàm để duyệt cây theo chiều rộng (level order)
void levelOrderTraversal(TreeNode *root) {
    if (root == NULL) return;

    queue<TreeNode*> q;
    q.push(root); // Bắt đầu từ nút gốc

    while (!q.empty()) {
        TreeNode *current = q.front();
        q.pop();

        // In giá trị của nút hiện tại
        cout << current->value << " ";

        // Nếu có nút con bên trái, thêm vào hàng đợi
        if (current->left != NULL) {
            q.push(current->left);
        }
        // Nếu có nút con bên phải, thêm vào hàng đợi
        if (current->right != NULL) {
            q.push(current->right);
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

    // Duyệt cây theo chiều rộng
    cout << "Level-order traversal: ";
    levelOrderTraversal(root);

    return 0;
}





