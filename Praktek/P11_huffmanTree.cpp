#include <iostream>
#include <string>
using namespace std;

struct HuffmanNode {
    char data;
    int frequency;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char data, int frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

// Fungsi untuk melakukan pencarian dalam pohon Huffman
bool searchHuffmanTree(HuffmanNode* root, char target, string& path) {
    if (root == nullptr) {
        return false;
    }

    if (root->data == target) {
        return true;
    }

    if (searchHuffmanTree(root->left, target, path)) {
        path = '0' + path;
        return true;
    }

    if (searchHuffmanTree(root->right, target, path)) {
        path = '1' + path;
        return true;
    }

    return false;
}

int main() {
    HuffmanNode* root = new HuffmanNode('$', 0); 
    root->left = new HuffmanNode('A', 6);
    root->right = new HuffmanNode('$', 15);
    root->right->left = new HuffmanNode('$', 7);
    root->right->right = new HuffmanNode('M', 8);
    root->right->left->left = new HuffmanNode('I', 3);
    root->right->left->right = new HuffmanNode('T', 4);
    root->right->right->left = new HuffmanNode('U', 4);
    root->right->right->right = new HuffmanNode('D', 4);

    // Pencarian karakter 'M'
    char targetM = 'M';
    string pathM;
    bool foundM = searchHuffmanTree(root, targetM, pathM);

    if (foundM) {
        cout << "Karakter '" << targetM << "' ditemukan dalam pohon Huffman. Path: " << pathM << endl;
    } else {
        cout << "Karakter '" << targetM << "' tidak ditemukan dalam pohon Huffman." << endl;
    }

    // Pencarian karakter 'A'
    char targetH = 'A';
    string pathH;
    bool foundH = searchHuffmanTree(root, targetH, pathH);

    if (foundH) {
        cout << "Karakter '" << targetH << "' ditemukan dalam pohon Huffman. Path: " << pathH << endl;
    } else {
        cout << "Karakter '" << targetH << "' tidak ditemukan dalam pohon Huffman." << endl;
    }
    
    delete root;

    return 0;
}