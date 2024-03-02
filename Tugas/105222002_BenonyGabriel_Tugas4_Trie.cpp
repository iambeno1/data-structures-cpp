/*
Tugas 4: Trie (insert, search & delete)

Nama  : Benony Gabriel
NIM   : 105222002

Pemilik kedai kopi menyimpan data menu agar mudah dicari oleh pelanggan. Berikut data menu yang ingin disimpan:

Café Long Black 
Café Cappuccino 
Café Oat Cappuccino
Café Mocha
Hazelnut Latte
Cinnamon Coffee Latte
Café Espresso
Café Macchiato
Café Latte
Vanilla Latte
Caramel Latte
Café Piccolo
Café Flat White 
Babyccino

1. Buatlah program untuk menyimpan data menu menggunakan trie! 
2. Buatlah program untuk mencari apakah suatu item ada dalam menu! 
3. Buatlah program untuk menghapus menu tertentu dari trie!
Terapkan modular programming dalam mengimplementasikan program

*/

#include <iostream>
#include <vector>
using namespace std;

struct TrieNode {
    char data;
    bool isEndOfWord;
    vector<TrieNode*> children;

    TrieNode(char ch) : data(ch), isEndOfWord(false) {}
};

struct MenuTrie {
    TrieNode* root;

    MenuTrie() : root(new TrieNode('\0')) {}

    void insertMenu(const string& menu) {
        TrieNode* current = root;

        for (char ch : menu) {
            TrieNode* node = nullptr;

            for (TrieNode* child : current->children) {
                if (child->data == ch) {
                    node = child;
                    break;
                }
            }

            if (!node) {
                node = new TrieNode(ch);
                current->children.push_back(node);
            }

            current = node;
        }

        current->isEndOfWord = true;
    }

    bool searchMenu(const string& menu) {
        TrieNode* current = root;

        for (char ch : menu) {
            TrieNode* node = nullptr;

            for (TrieNode* child : current->children) {
                if (child->data == ch) {
                    node = child;
                    break;
                }
            }

            if (!node) {
                return false;
            }

            current = node;
        }

        return current->isEndOfWord;
    }

    void deleteMenu(const string& menu) {
        if (!searchMenu(menu)) {
            cout << "Menu tidak ditemukan.\n" << endl;
            return;
        }

        TrieNode* current = root;
        TrieNode* nodeToDelete = nullptr;
        TrieNode* parent = nullptr;

        for (char ch : menu) {
            nodeToDelete = nullptr;
            for (TrieNode* node : current->children) {
                if (node->data == ch) {
                    nodeToDelete = node;
                    break;
                }
            }

            if (!nodeToDelete) {
                cout << "Node tidak ditemukan.\n" << endl;
                return;
            }

            parent = current;
            current = nodeToDelete;
        }

        current->isEndOfWord = false;

        if (current->children.empty()) {
            for (size_t i = 0; i < parent->children.size(); ++i) {
                if (parent->children[i] == current) {
                    parent->children.erase(parent->children.begin() + i);
                    break;
                }
            }
            delete current;
        }

        cout << "Menu berhasil dihapus.\n" << endl;
    }

    void lihatMenu() {
        lihatMenuHelper(root, "");
        cout << endl;
    }

    void lihatMenuHelper(TrieNode* node, string currentMenu) {
        if (node->isEndOfWord) {
            cout << currentMenu << endl;
        }

        for (TrieNode* child : node->children) {
            lihatMenuHelper(child, currentMenu + child->data);
        }
    }

    void searchAndViewMenu(const string& menu) {
        if (searchMenu(menu)) {
            cout << "Menu " << menu << " ditemukan." << endl;
        } else {
            cout << "Menu " << menu << " tidak ditemukan." << endl;
        }
        cout << endl;
    }
};

int main() {
  system("cls");

  MenuTrie menuTrie;
  int pilihan;
  string searchMenu;
  string deleteMenu;

  // Insert menu
  menuTrie.insertMenu("Cafe Cappuccino");
  menuTrie.insertMenu("Cafe Oat Cappuccino");
  menuTrie.insertMenu("Cafe Mocha");
  menuTrie.insertMenu("Hazelnut Latte");
  menuTrie.insertMenu("Cinnamon Coffee Latte");
  menuTrie.insertMenu("Cafe Espresso");
  menuTrie.insertMenu("Cafe Macchiato");
  menuTrie.insertMenu("Cafe Latte");
  menuTrie.insertMenu("Vanilla Latte");
  menuTrie.insertMenu("Caramel Latte");
  menuTrie.insertMenu("Cafe Piccolo");
  menuTrie.insertMenu("Cafe Flat White");
  menuTrie.insertMenu("Babyccino");

  do{
    cout << "======= Beno's Kafe =======" << endl;
    cout  << "1. Lihat menu\n";
    cout  << "2. Cari menu\n";
    cout  << "3. Hapus menu\n";
    cout  << "0. Exit\n";

    cout << "\nMasukkan pilihan: ";
    cin >> pilihan;

    switch(pilihan){
      case 1: 
        cout << "Lihat menu" << endl;
        menuTrie.lihatMenu();
        system("pause");
        cout << endl;
        break;

      case 2:
        cout << "Cari menu" << endl;
        cin.ignore();
        cout << "\nCari Menu: ";
        getline(cin, searchMenu);
        menuTrie.searchAndViewMenu(searchMenu);
        system("pause");
        cout << endl;
        break;

      case 3:
        cout << "Hapus menu" << endl;
        cin.ignore();
        cout << "\nHapus Menu: ";
        getline(cin, deleteMenu);
        menuTrie.deleteMenu(deleteMenu);
        system("pause");
        cout << endl;
        break;

      case 0:
        cout << "Terima kasih, sampai jumpa" << endl;
        exit(0);
        break;
        
      default:
        cout << "Pilihan tidak valid, coba lagi" << endl;
    }

  }while(true);

  return 0;
}
