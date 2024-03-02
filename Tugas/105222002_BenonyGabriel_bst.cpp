// Nama : Benony Gabriel
// NIM  : 105222002
#include <iostream>
using namespace std;

// Membuat struktur Node untuk Binary Search Tree
struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int value) : data(value), left(nullptr), right(nullptr){}
};

// Fungsi untuk memasukkan elemen baru ke dalam BST secara iteratif
void insert(Node *& root, int value){
    Node *newNode = new Node(value);

    if (root == nullptr){
        root = newNode;
        return;
    }

    Node * current = root;
    while (true){
        if (value < current->data){
            if (current->left == nullptr){
                current->left = newNode;
                return;
            }
            current = current->left;
        } else if (value > current->data){
            if (current->right == nullptr){
                current->right = newNode;
                return;
            }
            current = current->right;
        } else {
            // Jika nilai sudah ada dalam BST, tidak perlu dimasukkan kembali
            delete newNode; // Hapus node yg tidak digunakan
            return;
        }
    }
}

// Fungsi utk mencari elemen pada BST secara iteratif
bool retrieve(Node *root, int value){
    Node *current = root;
    while (current != nullptr){
        if (value < current->data){
            current = current->left;
        } else if (value > current->data){
            current = current->right;
        } else {
            return true; // Nilai ditemukan
        }
    }
    return false; // Nilai tidak ditemukan
}

// Fungsi utk mencari node dengan nilai terkecil dalam BST
Node *findMin(Node *node){
    while (node->left != nullptr){
        node = node->left;
    }
    return node;
}

// Fungsi untuk menghapus elemen pada BST secara iteratif
void deleteNode(Node *&root, int value){
    if (root == nullptr){
        return;
    }

    Node *current = root;
    Node *parent = nullptr;

    // Mencari node yang akan dihapus dan node parent nya
    while (current != nullptr && current->data != value){
        parent = current;
        if (value < current->data){
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (current == nullptr){
        return; // Nilai tidak ditemukan
    }

    // Kasus 1: Node yg akan dihapus adalah leaf (tidak punya anak)
    if (current->left == nullptr && current->right == nullptr){
        if (current == root){
            root = nullptr;
        } else if (parent->left == current){
            parent->left = nullptr;
        } else {
            parent->right = nullptr;
        }
        delete current;
    }
    // Kasus 2: Node yang aka dihapus memiliki satu child
    else if (current->left == nullptr){
        Node *temp = current->right;
        if (current == root){
            root == temp;
        } else if (parent->left == current){
            parent->left = temp;
        } else {
            parent->right = temp;
        }
        delete current;
    } else if (current->right == nullptr){
        Node *temp = current->left;
        if (current == root){
            root = temp;
        } else if (parent->left == current){
            parent->left = temp;
        } else {
            parent->right = temp;
        }
        delete current;
    }
    // Kasus 3: Node yang akan dihapus memiliki dua child
    else {
        Node *temp = findMin(current->right);
        current->data = temp->data;
        deleteNode(current->right, temp->data);
    }
}

// Fungsi untuk mencetak BST secara inorder
void inorderTraversal(Node *root){
    if (root != nullptr){
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main(){
    system("cls");

    Node *root = nullptr;
    int data, search;

    // insert beberapa elemen ke dalam BST
    cout << "Masukkan 7 buah bilangan integer ke dalam BST " << endl;
    for (int i = 0; i < 7; i++){
        cout << "Elemen ke-" << i + 1 << " : ";
        cin >> data;
        insert(root, data);
    }

    // Cetak BST secara inorder
    cout << "BST setelah insert : ";
    inorderTraversal(root);
    cout << endl;

    // Retrieve: Cari nilai balam BST
    cout << "Masukkan nilai yang ingin dicari : ";
    cin >> search;
    if (retrieve(root, search)){
        cout << "Nilai " << search << " ditemukan dalam BST." << endl;
    } else {
        cout << "Nilai " << search << " tidak ditemukan dalam BST." << endl;
    }

    // Delete: Hapus nilai search dari BST
    deleteNode(root, search);

    // Cetak BST setelah delete
    cout << "BST setelah delete: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}