#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Struktur data untuk item menu
struct itemMenu{
  string namaMenu;
  float harga;
  int stok;
};
 

// Tree untuk menyimpan data menu
struct menuNode{
  string kategori;
  string subKategori;
  vector<itemMenu> items;
  vector<menuNode*> children;
};

// Buat variabel global
menuNode* menuTree;

// Inisialisasi menu
menuNode* dataMenu(){
  // inisialisasi node root
  menuTree = new menuNode{"", "", {},{
  new menuNode{"Roti dan kue", "Viennoiseries", {{"Croissant", 10000, 20}, {"Pain au Chocolate", 12000, 25}, {"Brioche", 15000, 25}}, {}},
  new menuNode{"Roti dan kue", "Pastry", {{"Éclair", 18000, 10}, {"Mille-feuille", 20000, 12}, {"Tarte Tatin", 25000, 8}, {"Tarlet", 15000, 20}}, {}},
  new menuNode{"Roti dan kue", "Bread", {{"Baguette", 8000, 30}, {"Sourdough", 10000, 25}, {"Brioche Long", 15000, 20}}, {}},
  new menuNode{"Bun", "", {{"Bagel", 7000, 15}, {"Burger", 12000, 20}, {"Hotdog", 9000, 18}}, {}},
  new menuNode{"Minuman", "Juice", {{"Apple Juice", 8000, 30}, {"Orange Juice", 7000, 25}, {"Strawberry Juice", 9000, 20}}, {}},
  new menuNode{"Minuman", "Teh", {{"Earl Grey", 5000, 25}, {"Chamomile", 4000, 20}, {"English Breakfast", 6000, 22}, {"Darjeeling", 5500, 18}, {"Oolong", 7000, 15}, {"Matcha", 8000, 12}, {"Jasmine", 6500, 20}}, {}},
  new menuNode{"Minuman", "Kopi", {{"Long black", 9000, 30}, {"Cappucino", 10000, 25}, {"Latte", 11000, 22}, {"Espresso", 8000, 28}, {"Machiato", 9500, 20}, {"Piccolo", 10500, 18}}, {}},
  new menuNode{"Makanan Utama", "Salad", {{"Caesar Salad", 15000, 20}, {"Caprese Salad", 14000, 18}, {"Waldorf Salad", 16000, 15}, {"Nicoise Salad", 17000, 12}}, {}},
  new menuNode{"Makanan Utama", "Sup", {{"Pumpkin Soup", 12000, 25}, {"Mushroom Soup", 13000, 22}, {"Corn Soup", 11000, 28}}, {}},
  new menuNode{"Makanan Utama", "Sandwich", {{"Club Sandwich", 18000, 15}, {"Tuna Sandwich", 16000, 20}}, {}},
  new menuNode{"Makanan Utama", "Pasta", {{"Gnocchi", 20000, 12}, {"Aglio Olio", 15000, 18}, {"Lasagna", 22000, 15}, {"Fettucine", 16000, 20}, {"Carbonara", 18000, 18}}, {}}
  }};

  return menuTree;
}

// Menambahkan menu baru
void addMenu(menuNode* node, const string& kategori, const string& subKategori, const itemMenu& item){
  // mencari node yang sesuai  dengan kategori dan subkategori
  if(node != nullptr){
    if(node->kategori == kategori && node->subKategori == subKategori){
      // menambahkan item menu kedalam vektor items pada node yg sesuai
      node->items.push_back(item);
      cout << "Menu berhasil ditambahkan!\n";
      return;
    }
    // Mencari di anak-anak node
    for(auto& child : node->children){
      addMenu(child, kategori, subKategori, item);
    }
  }else{
    cout << "Kategori atau subkategori tidak ditemukan!\n";
  }
}

// isi data menu yg mau ditambahkan
void addItem(menuNode* menuTree) {
    string namaItem, kategori, subKategori;
    float harga;
    int stok;
    cout << "Masukkan nama item menu : ";
    getline(cin, namaItem);
    cout << "Masukkan harga : ";
    cin >> harga;
    cin.ignore();
    cout << "Masukkan stok : ";
    cin >> stok;
    cin.ignore();
    cout << "Masukkan ke kategori : ";
    getline(cin, kategori);
    cout << "Masukkan ke subkategori : ";
    getline(cin, subKategori);

    itemMenu newItemMenu{namaItem, harga, stok};
    addMenu(menuTree, kategori, subKategori, newItemMenu);
}

// hapus item menu
void deleteItem(menuNode* node, const string& kategori, const string& subKategori, const string& namaMenu){
  for(auto it = node->items.begin(); it != node->items.end(); ++it){
    if(it->namaMenu == namaMenu){
      // hapus item
      node->items.erase(it);

      // hapus harga
      cout << "Item " << namaMenu << "berhasil dihapus" << endl;
      return;
    }
  }

  // cari di node children
  for(auto& child : node->children){
    deleteItem(child, kategori, subKategori, namaMenu);
  }
}

// menampilkan menu
void lihatMenu(menuNode* node){
  cout << "Daftar Menu" << endl;
  if(node != nullptr){
    cout << node->kategori << " - " << node->subKategori << ": \n";
    for(const auto& item : node->items){
      cout << " - " << item.namaMenu << " (Rp" << item.harga << ") - Stok : " << item.stok << endl;
    }
    for(const auto& child : node->children){
      lihatMenu(child);
    }
  }

}

void menuUtama(){
  int pilihan;
  cout << "===============WELCOME===============" << endl;
  do{
    cout << "1. Lihat daftar menu\n";
    cout << "2. Kelola menu\n";
    cout << "3. Kelola harga\n";
    cout << "4. Tambah stok\n";
    cout << "0. Tutup\n";
    cout << "Masukkan pilihan [1/2/3/4/0] : ";
    cin >> pilihan;
    switch(pilihan){
      case 1:
        cout << "Ini lihat daftar menu" << endl;
        break;
      case 2:
        cout << "Kelola menu\n";
        cout << "1. Kategori menu\n";
        cout << "2. Event menu\n";
        cout << "9. kembali\n";
        cout << "Masukkan pilihan [1/2/9] : ";
        cin >> pilihan;
        switch(pilihan){
          case 1:
            cout << "Kategori Menu" << endl;
            cout << "1. Lihat semua kategori\n";
            cout << "2. Tambah kategori\n";
            cout << "3. Hapus kategori\n";
            cout << "4. Reset kategori\n";
            cout << "5. Edit\n";
            cout << "9. Kembali\n";
            cout << "0. Menu utama\n";
            cout << "Masukkan pilihan [1/2/3/4/5/9] : ";
            cin >> pilihan;
            switch(pilihan){
              case 1:
                cout << "Ini lihat semua kategori" << endl;
                break;
              case 2: 
                cout << "Ini tambah kategori" << endl;
                break;
              case 3:
                cout << "Hapus kategori" << endl;
                break;
              case 4:
                cout << "Reset kategori" << endl;
                break;
              case 9:
                cout << "Kembali" << endl;
                break;
              case 0:
                cout << "Menu utama" << endl;
                break;
              default:
                cout << "Pilihan tidak valid" << endl;
            }

        }
      
    }

  }while(true);
}

int main(){
  system("cls");
  // inisialisasi menu menggunkan fungsi dataMenu()
  menuNode* menuTree = dataMenu();

  // tampilkan menu
  lihatMenu(menuTree);

  // tambah menu
  addItem(menuTree);
  lihatMenu(menuTree);

  // bersihkan memori
  delete menuTree;

  return 0;
}