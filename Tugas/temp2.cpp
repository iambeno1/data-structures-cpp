#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Struktur data untuk menyimpan informasi menu
struct MenuItem {
    string name;
    double price;
    int stock;
};

// Node untuk tree menu
struct MenuNode {
    string category;
    string subcategory;
    vector<MenuItem> items;
    vector<MenuNode*> children;
};

// Fungsi untuk inisialisasi menu
MenuNode* initializeMenu() {
    // Inisialisasi node root
    MenuNode* menuTree = new MenuNode{"", "", {}, {
        new MenuNode{"Roti dan kue", "Viennoiseries", {{"Croissant", 10.0, 20}, {"Pain au Chocolate", 12.0, 15}, {"Brioche", 15.0, 25}}, {}},
        new MenuNode{"Roti dan kue", "Pastry", {{"Éclair", 18.0, 10}, {"Mille-feuille", 20.0, 12}, {"Tarte Tatin", 25.0, 8}, {"Tarlet", 15.0, 20}}, {}},
        new MenuNode{"Roti dan kue", "Bread", {{"Baguette", 8.0, 30}, {"Sourdough", 10.0, 25}, {"Brioche Long", 15.0, 20}}, {}},
        new MenuNode{"Bun", "", {{"Bagel", 7.0, 15}, {"Burger", 12.0, 20}, {"Hotdog", 9.0, 18}}, {}},
        new MenuNode{"Minuman", "Juice", {{"Apple Juice", 8.0, 30}, {"Orange Juice", 7.0, 25}, {"Strawberry Juice", 9.0, 20}}, {}},
        new MenuNode{"Minuman", "Teh", {{"Earl Grey", 5.0, 25}, {"Chamomile", 4.0, 20}, {"English Breakfast", 6.0, 22}, {"Darjeeling", 5.5, 18}, {"Oolong", 7.0, 15}, {"Matcha", 8.0, 12}, {"Jasmine", 6.5, 20}}, {}},
        new MenuNode{"Minuman", "Kopi", {{"Long black", 9.0, 30}, {"Cappucino", 10.0, 25}, {"Latte", 11.0, 22}, {"Espresso", 8.0, 28}, {"Machiato", 9.5, 20}, {"Piccolo", 10.5, 18}}, {}},
        new MenuNode{"Makanan Utama", "Salad", {{"Caesar Salad", 15.0, 20}, {"Caprese Salad", 14.0, 18}, {"Waldorf Salad", 16.0, 15}, {"Nicoise Salad", 17.0, 12}}, {}},
        new MenuNode{"Makanan Utama", "Sup", {{"Pumpkin Soup", 12.0, 25}, {"Mushroom Soup", 13.0, 22}, {"Corn Soup", 11.0, 28}}, {}},
        new MenuNode{"Makanan Utama", "Sandwich", {{"Club Sandwich", 18.0, 15}, {"Tuna Sandwich", 16.0, 20}}, {}},
        new MenuNode{"Makanan Utama", "Pasta", {{"Gnocchi", 20.0, 12}, {"Aglio Olio", 15.0, 18}, {"Lasagna", 22.0, 15}, {"Fettucine", 16.0, 20}, {"Carbonara", 18.0, 18}}, {}}
    }};

    return menuTree;
}

// Fungsi untuk menambahkan menu
void addMenu(MenuNode* node, const string& category, const string& subcategory, const MenuItem& item) {
    // Mencari node yang sesuai dengan kategori dan subkategori
    if (node != nullptr) {
        if (node->category == category && node->subcategory == subcategory) {
            // Menambahkan item-menu ke dalam vektor items pada node yang sesuai
            node->items.push_back(item);
            cout << "Menu berhasil ditambahkan!\n";
            return;
        }
        // Mencari di anak-anak node
        for (auto& child : node->children) {
            addMenu(child, category, subcategory, item);
        }
    } else {
        cout << "Kategori atau subkategori tidak ditemukan.\n";
    }
}


// Fungsi untuk menampilkan menu rekursif
void displayMenu(MenuNode* node) {
    cout << "Daftar Menu:\n";
    if (node != nullptr) {
        cout << node->category << " - " << node->subcategory << ":\n";
        for (const auto& item : node->items) {
            cout << "  - " << item.name << " (Rp" << item.price << ") - Stok: " << item.stock << "\n";
        }
        for (const auto& child : node->children) {
            displayMenu(child);
        }
    }
}

// Fungsi untuk menambahkan item-menu
void addItem(MenuNode* menuTree) {
    string namaItem, kategori, subKategori;
    float harga;
    int stok;

    cout << "Masukkan nama item menu : ";
    cin >> namaItem;
    cout << "Masukkan harga : ";
    cin >> harga;
    cout << "Masukkan stok : ";
    cin >> stok;
    cout << "Masukkan ke kategori : ";
    cin >> kategori;
    cout << "Masukkan ke subkategori : ";
    cin >> subKategori;

    MenuItem newItemMenu{namaItem, harga, stok};
    addMenu(menuTree, kategori, subKategori, newItemMenu);
}

int main() {
    // Inisialisasi menu menggunakan fungsi initializeMenu
    MenuNode* menuTree = initializeMenu();

    // Contoh penggunaan fungsi addMenu
    MenuItem newMenuItem{"New Item", 18.0, 10};
    addMenu(menuTree, "Roti dan kue", "Viennoiseries", newMenuItem);

    // Menampilkan menu awal
    displayMenu(menuTree);

    // Membersihkan memori
    delete menuTree;

    return 0;
}
