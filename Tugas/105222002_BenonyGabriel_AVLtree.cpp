/*
Nama  : Benony Gabriel
NIM : 105222002

Pemilik kedai kopi menyimpan data menu agar mudah dicari oleh pelanggan. Berikut data menu yang ingin disimpan:

Cappuccino
Mocha
Latte
Espresso
Macchiato
Piccolo
Babyccino
buatlah sub-program untuk menambahkan data tersebut ke AVL tree! 
*/

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    int height;
    Node* left;
    Node* right;

    Node(string data) : data(data), height(1), left(nullptr), right(nullptr) {}
};

int height(Node* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

int balanceFactor(Node* node) {
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* insert(Node* root, string data) {
    if (root == nullptr)
        return new Node(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = balanceFactor(root);

    // Left Left Case
    if (balance > 1 && data < root->left->data)
        return rotateRight(root);

    // Right Right Case
    if (balance < -1 && data > root->right->data)
        return rotateLeft(root);

    // Left Right Case
    if (balance > 1 && data > root->left->data) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Right Left Case
    if (balance < -1 && data < root->right->data) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void inOrderTraversal(Node* root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

int main() {
    Node* root = nullptr;

    // Menambahkan data menu ke AVL tree
    root = insert(root, "Cappuccino");
    root = insert(root, "Mocha");
    root = insert(root, "Latte");
    root = insert(root, "Espresso");
    root = insert(root, "Macchiato");
    root = insert(root, "Piccolo");
    root = insert(root, "Babyccino");

    // Menampilkan data menu setelah ditambahkan ke AVL tree
    cout << "Menu setelah ditambahkan ke AVL tree: ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}
