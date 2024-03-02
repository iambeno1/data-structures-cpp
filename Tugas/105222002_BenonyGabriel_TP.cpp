#include <iostream>
using namespace std;

// Struktur data untuk node BST
struct Node {
    char key;
    Node* left;
    Node* right;

    Node(char value) : key(value), left(nullptr), right(nullptr) {}
};

// Fungsi untuk menyisipkan node baru ke dalam BST
Node* insert(Node* root, char key) {
    if (root == nullptr) {
        return new Node(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;
}

// Fungsi untuk mencari node selanjutnya dalam metode inorder
Node* getNextItemInorder(Node* root, Node* target) {
    if (target->right != nullptr) {
        Node* current = target->right;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    } else {
        Node* successor = nullptr;
        Node* ancestor = root;
        while (ancestor != target) {
            if (target->key < ancestor->key) {
                successor = ancestor;
                ancestor = ancestor->left;
            } else {
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
}

// Fungsi untuk mencetak nilai node dalam metode inorder
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->key << " ";
        inorderTraversal(root->right);
    }
}

// Fungsi untuk mencetak nilai node dalam metode postorder
void postorderTraversal(Node* root) {
    if (root != nullptr) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->key << " ";
    }
}

// Fungsi untuk mencetak nilai node dalam metode preorder
void preorderTraversal(Node* root) {
    if (root != nullptr) {
        cout << root->key << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

int main() {
  system("cls");
    Node* root = nullptr;

    // Menyisipkan nilai ke dalam BST
    root = insert(root, 'o');
    insert(root, 'a');
    insert(root, 't');
    insert(root, 'c');
    insert(root, 'y');
    insert(root, 'm');
    insert(root, 'x');

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << "\n";

    Node* currentNode = root->left->right;
    Node* nextInorder = getNextItemInorder(root, currentNode);
    if (nextInorder != nullptr) {
        cout << "Next Inorder 'c': " << nextInorder->key << "\n";
    } else {
        cout << "No Next Inorder (end of traversal)\n";
    }

    return 0;
}