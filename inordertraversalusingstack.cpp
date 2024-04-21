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

// Hàm để duyệt cây theo kiểu trung thứ tự sử dụng stack
void inOrderTraversalUsingStack(TreeNode *root) {
    stack<TreeNode*> stk;
    TreeNode *current = root;

    while (current != NULL || !stk.empty()) {
        // Đi sâu vào nhánh trái nhất có thể
        while (current != NULL) {
            stk.push(current);
            current = current->left;
        }

        // Khi đã đến lá trái nhất, bắt đầu xử lý nút
        current = stk.top();
        stk.pop();

        // In giá trị của nút
        cout << current->value << " ";

        // Chuyển sang nhánh phải
        current = current->right;
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

    // Duyệt cây theo kiểu trung thứ tự sử dụng stack
    cout << "In-order traversal using stack: ";
    inOrderTraversalUsingStack(root);

    return 0;
}
