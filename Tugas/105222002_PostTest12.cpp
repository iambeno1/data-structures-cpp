// Nama : Benony Gabriel
// NIM  : 105222002
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

// Fungsi untuk membangun pohon Huffman dari string
HuffmanNode* buildHuffmanTree(const string& str) {
    // Menghitung frekuensi setiap karakter dalam string
    int frequency[256] = {0};
    for (char ch : str) {
        frequency[ch]++;
    }

    // Membuat array dari HuffmanNode
    HuffmanNode* nodes[256];
    for (int i = 0; i < 256; ++i) {
        if (frequency[i] > 0) {
            nodes[i] = new HuffmanNode(static_cast<char>(i), frequency[i]);
        } else {
            nodes[i] = nullptr;
        }
    }

    // Membangun pohon Huffman
    while (true) {
        int firstMinIndex = -1;
        int secondMinIndex = -1;

        // Mencari dua frekuensi terkecil
        for (int i = 0; i < 256; ++i) {
            if (nodes[i] != nullptr) {
                if (firstMinIndex == -1 || nodes[i]->frequency < nodes[firstMinIndex]->frequency) {
                    secondMinIndex = firstMinIndex;
                    firstMinIndex = i;
                } else if (secondMinIndex == -1 || nodes[i]->frequency < nodes[secondMinIndex]->frequency) {
                    secondMinIndex = i;
                }
            }
        }

        // Jika hanya satu node yang tersisa, itulah root pohon Huffman
        if (secondMinIndex == -1) {
            return nodes[firstMinIndex];
        }

        // Membuat internal node dengan dua child
        HuffmanNode* internalNode = new HuffmanNode('$', nodes[firstMinIndex]->frequency + nodes[secondMinIndex]->frequency);
        internalNode->left = nodes[firstMinIndex];
        internalNode->right = nodes[secondMinIndex];

        // Menandai posisi yang sudah digunakan
        nodes[firstMinIndex] = internalNode;
        nodes[secondMinIndex] = nullptr;
    }
}

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
  system("cls");
    // String yang digunakan
    string inputString = "MATEMATIKAITUMUDAH";

    // Membangun pohon Huffman
    HuffmanNode* root = buildHuffmanTree(inputString);

    // Menampilkan path untuk setiap karakter dalam string
    for (char ch : inputString) {
        string path;
        if (searchHuffmanTree(root, ch, path)) {
            cout << "Karakter '" << ch << "' ditemukan dalam pohon Huffman. Path: " << path << endl;
        } else {
            cout << "Karakter '" << ch << "' tidak ditemukan dalam pohon Huffman." << endl;
        }
    }

    // Membersihkan memori
    delete root;

    return 0;
}
