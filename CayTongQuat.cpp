#include <iostream>
#define max 100

using namespace std;

// Cấu trúc nút
struct Node {
    int id;
    Node* Next;
};

// Cấu trúc Đỉnh
struct Member {
    string data;
    Node* Child;
};

// Cấu trúc cây
struct Tree {
    Member General[max];
    int size;
};

// Nhập dữ liệu cho cây
void Input(Tree& T) {
    cout << "Nhap so luong cac dinh: ";
    cin >> T.size;
    for (int i = 1; i <= T.size; i++) {
        cout << "Nhap dinh thu " << i <<" (ID = "  << i << ")"<<  " : ";
        cin >> T.General[i].data;
        T.General[i].Child = NULL; // Khởi tạo con trỏ Child bằng NULL
    }
}

// Liên kết các phần tử anh em trong một nút cha
void Add_Child(Node*& Child, int n) {
    Node* p = new Node;
    p->id = n;
    p->Next = NULL;

    if (Child == NULL) {
        Child = p;
    } else {
        Node* q = Child;
        while (q->Next != NULL) {
            q = q->Next;
        }
        q->Next = p;
    }
}

// Nhập ID của các con trong một nút cha, nếu nhập 0 thì kết thúc nhập
void InputChild(Node*& Child, Tree T) {
    int i;
    int k = 0;
    do {
        cout << "Nhap ID con thu " << k+1 << " (nhap 0 de ket thuc): ";
        cin >> i;
        if (i > 0 && i <= T.size) {
            Add_Child(Child, i);
            k++;
        }
        else if (i >= T.size || i < 0) {
        	cout << "ID nhap vao khong hop le, vui long nhap lai!\n" ;
		}
    } while (i != 0 );
}

// Tạo một cây và nhập nút cha, nút con
void CreateTree(Tree& T) {
    Input(T);
    for (int i = 1; i <= T.size; i++) {
        cout << "Nhap cac con cua dinh thu " << i << " (" << T.General[i].data << ") " << " : " << endl;
        InputChild(T.General[i].Child, T);
        cout << "__________________________________________________";
        cout << endl;
    }
}

// In ra các con trong một nút cha
void PrintChild(Node* Child, Tree T) {
    Node* p = Child;
    while (p != NULL) {
        cout << T.General[p->id].data << " ";
        p = p->Next;
    }
}

// In ra cây tổng quát
void PrintTree(Tree T) {
    for (int i = 1; i <= T.size; i++) {
        cout << "Dinh thu " << i << " : " << T.General[i].data << " -- Con cua dinh nay: ";
        PrintChild(T.General[i].Child, T);
        cout << endl;
    }
}

int main() {
	// Khai báo cây có tên T
    Tree T;
    CreateTree(T);
    cout << "Cay tong quat sau khi nhap:\n";
    PrintTree(T);

    return 0;
}
