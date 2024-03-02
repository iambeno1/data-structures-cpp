// Nama : Benony Gabriel
// NIM  : 105222002

// Input: N, O, P, Q, R, S, T, U, V, W, X, Y, Z

// Topik : Tree traversal (utk inorder dan level order)

#include <iostream>
using namespace std;

struct Node{
  char data;
  Node *left;
  Node *right;

  Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node *insertNode (Node *root, int value){
  if(root == nullptr){
    return new Node(value);
  }

  if(value < root->data){
    root->left = insertNode(root->left, value);
  }else{
    root->right = insertNode(root->right, value);
  }

  return root;
}

// Inorder Traversal
void inorderTraversal(Node *root){
  if(root != nullptr){
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
  }
}

// Hitung height tree
int treeHeight(Node *root){
  if(root == nullptr){
    return 0;
  }

  int leftHeight = treeHeight(root->left);
  int rightHeight = treeHeight(root->right);

  return max(leftHeight, rightHeight) + 1;
}

void printLevel(Node *root, int level){
  if(root == nullptr){
    return;
  }

  if(level == 1){
    cout << root->data << " ";
  }else if(level > 1){
    printLevel(root->left, level - 1);
    printLevel(root->right, level - 1);
  }
}

// Leve Order Traversal
void levelOrderTraversal(Node *root){
  int height = treeHeight(root);
  for(int i = 1; i <= height; i++){
    printLevel(root, i);
  }
}

int main(){
  system("cls");

  int pil;

  Node *root = nullptr;
  root = insertNode(root, 'O');
  insertNode(root, 'P');
  insertNode(root, 'Q');
  insertNode(root, 'R');
  insertNode(root, 'S');
  insertNode(root, 'T');
  insertNode(root, 'U');
  insertNode(root, 'V');
  insertNode(root, 'W');
  insertNode(root, 'X');
  insertNode(root, 'Y');
  insertNode(root, 'Z');

  cout << "Data : O, P, Q, R, S, T, U, V, W, X, Y, Z\n" << endl;
  do{
    cout << "Pilihan" << endl;
    cout << "1. Inorder Traversal" << endl;
    cout << "2. Level Order traversal" << endl;
    cout << "3. Bandingkan Keduanya" << endl;
    cout << "0. Exit" << endl;
    cout << "Masukkan pilihan anda : ";
    cin >> pil;

    cout << endl;

    switch (pil){
      case 1:
        cout << "Inorder traversal : ";
        inorderTraversal(root);
        cout << endl << endl;
        break;
      case 2:
        cout << "Level order traversal : ";
        levelOrderTraversal(root);
        cout << endl << endl;
        break;
      case 3: 
        cout << "Inorder traversal : ";
        inorderTraversal(root);
        cout << endl;
        cout << "Level order traversal : ";
        levelOrderTraversal(root);
        cout << endl << endl;
        break;

      case 0:
        cout << "Anda telah keluar dari program" << endl;
        exit(0);
      default:
      cout << "Pilihan tidak valid, coba lagi!\n" << endl;

    }
  }
  while(pil !=0);

  return 0;
}