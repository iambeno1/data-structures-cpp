/*=================================================================
TUGAS BESAR MATA KULIAH STRUKTUR DATA DAN ALGORITMA

OLEH KELOMPOK 6:
1. Benony Gabriel                 NIM: 105222002
2. Faris Farhan                   NIM: 105222013
3. Sheva Haya Milano              NIM: 105222036
4. Muhammad Rizqi Ferdhinandito   NIM: 105222041
5. Arshanda Geulis Nawajaputri    NIM: 105222045


=================================================================
OTOMATISASI PROSES PENJUALAN UPEREAST KAFE
- Manajemen Pengelolaan Menu dan Harga
- Manajemen Pengelolaan Bahan Baku

version: 1.0.1
=================================================================*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Struktur data untuk item menu
struct itemMenu{
    string namaMenu;
    int harga;
    int stok;
};

struct Event{
    string name;
    vector<string> categories; // Kategori yang terkait dengan event ini
};

const int TABLE_SIZE = 500; // ukuran hash table untuk bahan baku

struct BahanBaku{
    string nama;
    int harga;
    int stok;

    BahanBaku(const string& n, int h, int s) : nama(n), harga(h), stok(s) {}
};

struct HashNode{
    BahanBaku bahan;
    HashNode* next;

    HashNode(const BahanBaku& b) : bahan(b), next(nullptr) {}
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
vector<Event> events;
HashNode* HashTable[TABLE_SIZE] = { nullptr };

// Inisialisasi data menu awal
menuNode* dataMenu(){
  // inisialisasi node root
    menuTree = new menuNode{"", "", {}, {
        new menuNode{"Roti dan kue", "Viennoiseries", {{"Croissant", 10000, 20}, {"Pain au Chocolate", 12000, 25}, {"Brioche", 15000, 25}}, {}},
        new menuNode{"Roti dan kue", "Pastry", {{"Eclair", 18000, 10}, {"Mille-feuille", 20000, 12}, {"Tarte Tatin", 25000, 8}, {"Tarlet", 15000, 20}}, {}},
        new menuNode{"Roti dan kue", "Bread", {{"Baguette", 8000, 30}, {"Sourdough", 10000, 25}, {"Brioche Long", 15000, 20}}, {}},
        new menuNode{"Roti dan kue", "Bun", {{"Bagel", 7000, 15}, {"Burger", 12000, 20}, {"Hotdog", 9000, 18}}, {}},
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

// Inisialisasi data event awal
vector<Event> initEvents() {
    return {
        {"Breakfast", {"Sandwich", "Bread", "Bun", "Minuman"}},
        {"Brunch", {"Sandwich", "Bread", "Bun", "Salad", "Sup", "Minuman"}},
        {"Lunch", {"Makanan Utama", "Pastry", "Minuman"}},
        {"Morning Coffe/Tea time/Afternoon Coffe", {"Minuman", "Viennoiseries", "Pastry"}},
        {"Dinner", {"Makanan Utama", "Pastry", "Minuman"}}
    };
}

// Fungsi hash sederhana utk bahan baku
int hashFunction(const string& key) {
    int hash = 0;
    for (char ch : key) {
        hash += ch;
    }
    return hash % TABLE_SIZE;
}

// Fungsi untuk menambahkan bahan baku ke dalam hashtable
void tambahBahanBaku(HashNode* HashTable[], const BahanBaku& bahan) {
    int index = hashFunction(bahan.nama);
    HashNode* current = HashTable[index];

    // Cek apakah bahan baku dengan nama yang sama sudah ada
    while (current != nullptr) {
        if (current->bahan.nama == bahan.nama) {
            // Jika ada, perbarui stok dan harga
            current->bahan.stok = bahan.stok;
            current->bahan.harga = bahan.harga;
            return;
        }
        current = current->next;
    }

    // Jika bahan baku belum ada, tambahkan ke dalam hashtable
    HashNode* newNode = new HashNode(bahan);
    newNode->next = HashTable[index];
    HashTable[index] = newNode;
}

// Fungsi untuk menambahkan bahan baku ke dalam hashtable
void tambahBahanBakuByParams(HashNode* HashTable[], const string& nama, int harga, int stok) {
    BahanBaku newBahan(nama, harga, stok);
    tambahBahanBaku(HashTable, newBahan);
}


// menambahkan bahan baku ke dalam hashtable
void addBahanBaku(HashNode* HashTable[]) {
    string nama;
    int harga, stok;

    cin.ignore();
    cout << "Masukkan nama bahan baku: ";
    getline(cin, nama);

    cout << "Masukkan harga bahan baku: ";
    cin >> harga;

    cout << "Masukkan stok bahan baku: ";
    cin >> stok;

    cin.ignore();  // Membersihkan newline dari buffer

    tambahBahanBakuByParams(HashTable, nama, harga, stok);

    cout << "Bahan baku berhasil ditambahkan ke dalam hashtable." << endl;
}

// Fungsi untuk inisialisasi dan menambahkan bahan baku ke dalam hash table (bahan baku awal)
void inisialisasiBahanBaku(HashNode* HashTable[]) {
    // Menambahkan bahan baku awal
    tambahBahanBakuByParams (HashTable, "Tepung", 5000.0, 100);
    tambahBahanBakuByParams (HashTable, "Terigu", 5000.0, 500);
    tambahBahanBakuByParams (HashTable, "Gula", 3000.0, 500);
    tambahBahanBakuByParams (HashTable, "Susu", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Ragi", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Garam", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Mentega", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Air", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Cokelat", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Telur", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Biji wijen", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Roti burger", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Daging ham", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Keju", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Salada", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Tomat", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Saus", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Margarin", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Roti hotdog", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Sosis", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Buah apel", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Es batu", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Buah jeruk", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Buah Strawberry", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Bungan chamomile", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Daun teh english", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Teh", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Daun teh darjeling", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Teh olong", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Matcha powder", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Teh jasmine", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Madu", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Kopi bubuk", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Busa susu", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Sirup gula", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Sirup karamel", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Susu steamed", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Selada romaine", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Selada", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Roti tawar", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Dressing caesar", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Mayones", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Minyak Zaitun", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Parmesan", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Lemon", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Bawang putih", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Lada hitam", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Daun basil", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Balzamic glaze", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Stalk saleri", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Kacang walnut", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Kismis", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Kentang", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Kacang hijau", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Olive hitam", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Ikan tuna", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Bawang merah", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Cuka", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Labu kuning", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Santan", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Kaldu ayam", 10000.0, 50);
    tambahBahanBakuByParams (HashTable, "Bubuk kunyit", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Jamur shitake", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Bawang bombay", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Jagung pipil", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Daging ayam", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Wortel", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Buncis", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Daun Bawang", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Bacon", 10000.0, 500);
    tambahBahanBakuByParams (HashTable, "Spageti", 10000.0, 5);
    tambahBahanBakuByParams (HashTable, "Cabe merah", 10000.0, 50);
    tambahBahanBakuByParams (HashTable, "Peterseli cincang", 10000.0, 500);
}

// Fungsi untuk menampilkan semua bahan baku
void tampilkanSemuaBahanBaku(HashNode* table[]) {
    cout << "========== Daftar Bahan Baku ==========\n";
    for (int i = 0; i < TABLE_SIZE; ++i) {
        HashNode* current = table[i];
        while (current != nullptr) {
            cout << current->bahan.nama << " - Harga: " << current->bahan.harga
                 << " - Stok: " << current->bahan.stok << "\n";
            current = current->next;
        }
    }
}

// Fungsi untuk mencari bahan baku dalam hashtable berdasarkan nama
BahanBaku* findBahanBaku(const string& nama, HashNode* HashTable[]) {
    int index = hashFunction(nama);
    HashNode* current = HashTable[index];

    while (current != nullptr) {
        if (current->bahan.nama == nama) {
            return &current->bahan;
        }
        current = current->next;
    }

    return nullptr;
}

// Melakukan pencarian bahan baku
void cariBahanBaku_cari(){
    string namaBahanDicari;

    cin.ignore();
    cout << "Masukkan nama bahan baku yang ingin dicari: ";
    getline(cin, namaBahanDicari);

    BahanBaku* hasilPencarian = findBahanBaku(namaBahanDicari, HashTable);

    if (hasilPencarian != nullptr) {
        cout << "Bahan baku ditemukan: " << hasilPencarian->nama << " - Harga: Rp" << hasilPencarian->harga << " - Stok: " << hasilPencarian->stok << endl;
    } else {
        cout << "Bahan baku dengan nama '" << namaBahanDicari << "' tidak ditemukan." << endl;
    }
}

// Fungsi untuk mengupdate harga bahan baku
void updateHargaBahanBaku(HashNode* HashTable[], const string& nama, int newHarga) {
    BahanBaku* bahan = findBahanBaku(nama, HashTable);

    if (bahan != nullptr) {
        bahan->harga = newHarga;
        cout << "Harga bahan baku '" << nama << "' berhasil diupdate menjadi Rp" << newHarga << "." << endl;
    } else {
        cout << "Bahan baku dengan nama '" << nama << "' tidak ditemukan." << endl;
    }
}

// Fungsi untuk mengupdate jumlah stok bahan baku
void updateStokBahanBaku(HashNode* HashTable[], const string& nama, int newStok) {
    BahanBaku* bahan = findBahanBaku(nama, HashTable);

    if (bahan != nullptr) {
        bahan->stok = newStok;
        cout << "Jumlah stok bahan baku '" << nama << "' berhasil diupdate menjadi " << newStok << "." << endl;
    } else {
        cout << "Bahan baku dengan nama '" << nama << "' tidak ditemukan." << endl;
    }
}

// Fungsi untuk mengecek stok bahan baku dan memberikan Notifikasi jika stok kurang dari 10 
void cekStokBahanBaku(HashNode* HashTable[]) {
    bool adaBahanKurang = false;

    for (int i = 0; i < TABLE_SIZE; ++i) {
        HashNode* current = HashTable[i];
        while (current != nullptr) {
            if (current->bahan.stok < 10) {
                cout << "\n========== NOTIFIKASI ==========\n";
                adaBahanKurang = true;
                cout << "Bahan baku '" << current->bahan.nama << "' stoknya kurang dari 10. Stok sekarang: " << current->bahan.stok << "\n";
            }
            current = current->next;
        }
    }
}

// ----------Start fungsi fitur----------
    string namaItem, kategori, subKategori, namaEvent, kategoriEvent;
    int harga, stok;

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
    int harga;
    int stok;
    cin.ignore();
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

// Menambahkan kategori baru beserta subkategori, item, harga, dan stok
void addCategory(menuNode* node) {
    int newPrice;
    int newStock;

    cout << "Masukkan kategori baru: ";
    cin.ignore();
    getline(cin, kategori);

    cout << "Masukkan subkategori baru: ";
    getline(cin, subKategori);

    menuNode* newCategoryNode = new menuNode{kategori, subKategori, {}, {}};

    cout << "Masukkan nama item baru: ";
    getline(cin, namaItem);

    cout << "Masukkan harga item baru: ";
    cin >> newPrice;

    cout << "Masukkan stok item baru: ";
    cin >> newStock;

    itemMenu newItemMenu{namaItem, newPrice, newStock};
    newCategoryNode->items.push_back(newItemMenu);

    // Menambahkan node baru ke dalam children node
    node->children.push_back(newCategoryNode);

    cout << "Kategori, subkategori, item, harga, dan stok berhasil ditambahkan!\n";
}

// Menambahkan subkategori dan item ke dalam kategori yang sudah ada
void addSubcategory(menuNode* node) {
    int newPrice;
    int newStock;

    cout << "Masukkan kategori yang sudah ada: ";
    cin.ignore();
    getline(cin, kategori);

    // Cari kategori yang sesuai
    for (auto& child : node->children) {
        if (child->kategori == kategori) {
            cout << "Masukkan subkategori baru: ";
            getline(cin, subKategori);

            menuNode* newSubcategoryNode = new menuNode{kategori, subKategori, {}, {}};

            cout << "Masukkan nama item baru: ";
            getline(cin, namaItem);

            cout << "Masukkan harga item baru: ";
            cin >> newPrice;

            cout << "Masukkan stok item baru: ";
            cin >> newStock;

            itemMenu newItemMenu{namaItem, newPrice, newStock};
            newSubcategoryNode->items.push_back(newItemMenu);

            // Menambahkan node baru ke dalam children node
            child->children.push_back(newSubcategoryNode);

            cout << "Subkategori, item, harga, dan stok berhasil ditambahkan!\n";
            return;
        }
    }

    cout << "Kategori tidak ditemukan!\n";
}

// Fungsi untuk menambahkan kategori atau subkategori ke dalam event
void tambahKategoriSubkategoriEvent(vector<Event>& events, menuNode* node) {
    cin.ignore();
    string namaKategori;
    cout << "Masukkan nama kategori/subkategori yang ingin ditambahkan: ";
    getline(cin, namaKategori);

    // Cek apakah kategori atau subkategori sudah ada pada menu kafe
    bool kategoriExist = false;
    for (const auto& child : node->children) {
        if (child->kategori == namaKategori || child->subKategori == namaKategori) {
            kategoriExist = true;
            break;
        }
    }

    if (kategoriExist) {
        // Pilih event yang ingin ditambahkan kategori atau subkategori
        cout << "Pilih event yang ingin ditambahkan kategori (1-" << events.size() << "):\n";
        for (size_t i = 0; i < events.size(); ++i) {
            cout << i + 1 << ". " << events[i].name << "\n";
        }

        size_t selectedEvent;
        do {
            cout << "Masukkan nomor event (1-" << events.size() << "): ";
            cin >> selectedEvent;
        } while (selectedEvent < 1 || selectedEvent > events.size());

        // Tambahkan kategori atau subkategori ke dalam event yang dipilih
        events[selectedEvent - 1].categories.push_back(namaKategori);
        cout << "Kategori/subkategori berhasil ditambahkan ke dalam event " << events[selectedEvent - 1].name << "!\n";
    } else {
        cout << "Kategori tidak ditemukan dalam menu kafe. Tidak dapat menambahkan ke dalam event.\n";
    }
}

void deleteCategory(menuNode* node, const string& category) {
    auto it = node->children.begin();
    while (it != node->children.end()) {
        if ((*it)->kategori == category) {
            // Hapus node dan maju ke iterator berikutnya
            delete *it;
            it = node->children.erase(it);
        } else {
            // Pemanggilan rekursif pada anak-anak node
            deleteCategory(*it, category);
            ++it;
        }
    }
}

void deleteSubCategory(menuNode* node, const string& category, const string& subCategory) {
    for (auto it = node->children.begin(); it != node->children.end(); ++it) {
        if ((*it)->kategori == category && (*it)->subKategori == subCategory) {
            delete *it;  // Hapus node
            node->children.erase(it);
            cout << "Sub kategori " << subCategory << " dan semua item di dalamnya berhasil dihapus!\n";
            return;
        } else {
            deleteSubCategory(*it, category, subCategory);  // Pemanggilan rekursif
        }
    }

    cout << "Sub kategori tidak ditemukan!\n";
}

void deleteSubCategory_del(){

    cout << "\nHapus sub kategori dan semua item di dalamnya" << endl;
    cin.ignore();
    cout << "Masukkan kategori: ";
    getline(cin, kategori);
    cout << "Masukkan sub kategori yang ingin dihapus beserta semua isinya: ";
    getline(cin, subKategori);
    deleteSubCategory(menuTree, kategori, subKategori);
}

void deleteItemMenu(menuNode* node) {

    cout << "Masukkan kategori: ";
    cin.ignore();
    getline(cin, kategori);

    cout << "Masukkan subkategori: ";
    getline(cin, subKategori);

    cout << "Masukkan nama item: ";
    getline(cin, namaItem);

    // Pemanggilan fungsi deleteItem
    deleteItem(node, kategori, subKategori, namaItem);
}


// Fungsi untuk mencari indeks event berdasarkan nama event
int cariIndeksEvent(const vector<Event>& events, const string& namaEvent) {
    for (int i = 0; i < events.size(); ++i) {
        if (events[i].name == namaEvent) {
            return i;
        }
    }
    return -1;  // Return -1 jika event tidak ditemukan
}

// Fungsi untuk menghapus kategori dari suatu event
void hapusKategoriEvent(vector<Event>& events, const string& namaEvent, const string& kategori) {
    int indeksEvent = cariIndeksEvent(events, namaEvent);

    if (indeksEvent != -1) {
        vector<string>& kategoriEvent = events[indeksEvent].categories;
        bool kategoriDitemukan = false;

        // Cari indeks kategori dalam vector kategoriEvent
        int indeksKategori = 0;
        for (indeksKategori = 0; indeksKategori < kategoriEvent.size(); ++indeksKategori) {
            if (kategoriEvent[indeksKategori] == kategori) {
                kategoriDitemukan = true;
                break;
            }
        }

        if (kategoriDitemukan) {
            // Hapus kategori dari vector kategoriEvent
            kategoriEvent.erase(kategoriEvent.begin() + indeksKategori);
            cout << "Kategori '" << kategori << "' berhasil dihapus dari event '" << namaEvent << "'." << endl;
        } else {
            cout << "Kategori '" << kategori << "' tidak ditemukan pada event '" << namaEvent << "'." << endl;
        }
    } else {
        cout << "Event '" << namaEvent << "' tidak ditemukan." << endl;
    }
}

void hapusItemEvent_del(){
    cin.ignore();
    cout << "Masukkan event: ";
    getline(cin, namaEvent);
    cout << "Masukkan nama item event yang ingin dihapus: ";
    getline(cin, kategoriEvent);
    hapusKategoriEvent(events, namaEvent, kategoriEvent);
}

// Fungsi untuk mencari item menu berdasarkan nama
itemMenu* cariItemMenu(menuNode* node, const string& namaMenu, string& kategori, string& subKategori) {
    if (node != nullptr) {
        // Cek apakah item ada di node saat ini
        for (auto& item : node->items) {
            if (item.namaMenu == namaMenu) {
                kategori = node->kategori;
                subKategori = node->subKategori;
                return &item;
            }
        }

        // Rekursi ke anak-anak node saat ini
        for (auto& child : node->children) {
            itemMenu* foundItem = cariItemMenu(child, namaMenu, kategori, subKategori);
            if (foundItem != nullptr) {
                return foundItem;
            }
        }
    }

    return nullptr;
}

// Fungsi untuk menampilkan informasi lengkap item menu berdasarkan nama
void tampilkanInfoItemMenu(menuNode* node, const string& namaMenu) {
    string kategori, subKategori;
    itemMenu* foundItem = cariItemMenu(node, namaMenu, kategori, subKategori);

    if (foundItem != nullptr) {
        cout << "----- Informasi Item Menu -----\n";
        cout << "Nama: " << namaMenu << endl;
        cout << "Kategori: " << kategori << " - " << subKategori << endl;
        cout << "Harga: Rp" << foundItem->harga << endl;
        cout << "Stok: " << foundItem->stok << endl;
    } else {
        cout << "Item menu dengan nama " << namaMenu << " tidak ditemukan.\n";
    }
}

void cariItemMenu_Cari(){
    cin.ignore();
    cout << "\nMasukan nama item yang dicari: ";
    getline(cin, namaItem);
    tampilkanInfoItemMenu(menuTree, namaItem);
}

// Fungsi untuk memperbarui harga item menu berdasarkan nama
void updateHargaItemMenu(menuNode* node, const string& namaMenu, int hargaBaru) {
    if (node != nullptr) {
        // Cek apakah item ada di node saat ini
        for (auto& item : node->items) {
            if (item.namaMenu == namaMenu) {
                item.harga = hargaBaru;
                cout << "Harga item menu " << namaMenu << " berhasil diperbarui menjadi Rp" << hargaBaru << ".\n";
                return;
            }
        }

        // Rekursi ke anak-anak node saat ini
        for (auto& child : node->children) {
            updateHargaItemMenu(child, namaMenu, hargaBaru);
        }
    }
}

// Fungsi untuk memperbarui stok item menu berdasarkan nama
void updateStokItemMenu(menuNode* node, const string& namaMenu, int stokBaru) {
    if (node != nullptr) {
        // Cek apakah item ada di node saat ini
        for (auto& item : node->items) {
            if (item.namaMenu == namaMenu) {
                item.stok = stokBaru;
                cout << "Stok item menu " << namaMenu << " berhasil diperbarui menjadi " << stokBaru << ".\n";
                return;
            }
        }

        // Rekursi ke anak-anak node saat ini
        for (auto& child : node->children) {
            updateStokItemMenu(child, namaMenu, stokBaru);
        }
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

// Fungsi untuk menampilkan menu berdasarkan event
void lihatMenuByEvent(const vector<Event>& events, menuNode* node) {
    cout << "\n----- Daftar Menu Berdasarkan Waktu atau Event -----\n";
    for (const auto& event : events) {
        cout << "Event: " << event.name << "\n";

        for (const auto& categoryName : event.categories) {
            // Cari kategori yang sesuai
            for (auto& child : node->children) {
                if (child->kategori == categoryName || child->subKategori == categoryName) {
                    cout << "Kategori: " << child->kategori << " - " << child->subKategori << "\n";

                    for (const auto& item : child->items) {
                        cout << " - " << item.namaMenu << " (Rp" << item.harga << ") - Stok: " << item.stok << "\n";
                    }
                }
            }
        }

        cout << "\n";
    }
}

// ==========START FITUR==========
// Keterangan revisi: Tambah fungsi untuk mencari menu dalam struktur data menuTree untuk melakukan pesan menu

// Fungsi untuk mencari menu dalam struktur data menuTree
menuNode* cariMenu(menuNode* node, const string& namaMenu) {
    if (node == nullptr) {
        return nullptr; // Jika node kosong, kembalikan nullptr
    }
    if (node->items.size() > 0) {
        // Jika node merupakan leaf (tidak memiliki children), cari menu di dalamnya
        for (const auto& item : node->items) {
            if (item.namaMenu == namaMenu) {
                return node; // Jika menu ditemukan, kembalikan node yang menyimpan menu
            }
        }
    }
    // Telusuri semua children
    for (menuNode* child : node->children) {
        menuNode* found = cariMenu(child, namaMenu);
        if (found != nullptr) {
            return found; // Jika menu ditemukan pada salah satu children, kembalikan node yang menyimpan menu
        }
    }
    return nullptr; // Jika menu tidak ditemukan, kembalikan nullptr
}

// Fungsi untuk mencari indeks menu dalam vektor itemMenu
int cariIndexMenu(menuNode* node, const string& namaMenu) {
    if (node == nullptr) {
        return -1; // Jika node kosong, kembalikan -1
    }
    if (node->items.size() > 0) {
        // Telusuri semua item menu di dalam node
        for (size_t i = 0; i < node->items.size(); ++i) {
            if (node->items[i].namaMenu == namaMenu) {
                return i; // Jika menu ditemukan, kembalikan indeksnya
            }
        }
    }
    return -1; // Jika menu tidak ditemukan, kembalikan -1
}

void pesanMenu() {
    cout << "Daftar Menu:\n";
    // Tampilkan daftar menu
    lihatMenu(menuTree);

    string namaMenu;
    int jumlah;

    cout << "Masukkan nama menu yang ingin dipesan: ";
    cin.ignore();
    getline(cin, namaMenu);
    cout << "Masukkan jumlah yang ingin dipesan: ";
    cin >> jumlah;

    // Cari menu dalam struktur data menuTree
    menuNode* currentMenu = cariMenu(menuTree, namaMenu);
    if (currentMenu != nullptr) {
        // Cek stok menu
        int index = cariIndexMenu(currentMenu, namaMenu);
        if (index != -1) {
            if (currentMenu->items[index].stok >= jumlah) {
                // Pesanan dapat diproses
                currentMenu->items[index].stok -= jumlah;
                cout << "Pesanan berhasil!\n";
            } else {
                // Stok tidak mencukupi
                cout << "Maaf, stok tidak mencukupi untuk pesanan ini.\n";
            }
        } else {
            // Menu tidak ditemukan
            cout << "Menu tidak ditemukan.\n";
        }
    } else {
        // Menu tidak ditemukan
        cout << "Menu tidak ditemukan.\n";
    }
}

// ==========END REVISI==========

// -----------Start Fitur Menu----------------
int pilihan;

void fiturTambahMenu_pil(int input){
    switch(input){
        case 1: 
            cout << "\tTambah Kategori" << endl;
            cout << "\tTambah kategori, subkategori, item, harga, dan stok" << endl;
            addCategory(menuTree);
            system("pause");
            cout << endl;
            break;

        case 2: 
            cout << "\tTambah sub kategori" << endl;
            cout << "\tTambah subkategori, item, harga, dan stok" << endl;
            addSubcategory(menuTree);
            system("pause");
            cout << endl;
            break;

        case 3:
            cout << "\tTambah item" << endl;
            addItem(menuTree);
            system("pause");
            cout << endl;
            break;

        case 4:
            cout << "\tTambah kategori/subkategori ke menu event" << endl;
            // Menambahkan kategori baru pada semua event
            tambahKategoriSubkategoriEvent(events, menuTree);
            system("pause");
            cout << endl;
            break;

        case 9:
            break;

        default:
            cout << "\n\tPilihan tidak tersedia, coba lagi" << endl;
            break;
    }
}

void fiturHapusMenu_pil(int input){
    switch(input){
        case 1: 
            cout << "\tHapus Kategori" << endl;
            cin.ignore();
            cout << "\tMasukkan nama kategori yang ingin dihapus: ";
            getline(cin, kategori);
            deleteCategory(menuTree, kategori);
            system("pause");
            cout << endl;
            break;

        case 2: 
            cout << "\tHapus sub kategori" << endl;
            cout << "\tHapus subkategori, item, harga, dan stok" << endl;
            deleteSubCategory_del();
            system("pause");
            cout << endl;
            break;

        case 3:
            cout << "\tHapus item" << endl;
            deleteItemMenu(menuTree);
            system("pause");
            cout << endl;
            break;

        case 4:
            cout << "\tHapus item event" << endl;
            hapusItemEvent_del();
            system("pause");
            cout << endl;
            break;
        
        case 9:
            break;

        default:
            cout << "\n\tPilihan tidak tersedia, coba lagi" << endl;
            break;
    }
}

void fiturLihatMenu_pil(int input){
    switch(input){
        case 1: 
            cout << "\t~Semua menu~" << endl;
            lihatMenu(menuTree);
            cout << "\n" <<endl;
            system("pause");
            cout << endl;
            break;

        case 2: 
            cout << "\t~Menu Event~" << endl;
            lihatMenuByEvent(events, menuTree);
            system("pause");
            cout << endl;
            break;
        
        case 3: 
            cout << "\t~Cari Menu~" << endl;
            cariItemMenu_Cari();
            system("pause");
            cout << endl;
            break;

        case 9:
            break;

        default:
            cout << "\n\tPilihan tidak tersedia, coba lagi" << endl;
        break;
    }
}

void fiturBahanBaku_pil(int input){
    switch(input){
        case 1: 
            cout << "\tSemua Bahan Baku" << endl;
            // Menampilkan semua bahan baku
            tampilkanSemuaBahanBaku(HashTable);
            system("pause");
            cout << endl;
            break;

        case 2: 
            cout << "\tTambah Bahan Baku" << endl;
            addBahanBaku(HashTable);
            system("pause");
            cout << endl;
            break;

        case 3:
            cout << "\tUpdate Harga Bahan Baku" << endl;
            cin.ignore();
            cout << "Masukkan nama bahan baku: ";
            getline(cin, namaItem);
            cout << "Masukkan harga baru: ";
            cin >> harga;
            updateHargaBahanBaku(HashTable, namaItem, harga);
            system("pause");
            cout << endl;
            break;

        case 4:
            cout << "\tUpdate Stok Bahan Baku" << endl;
            cin.ignore();
            cout << "Masukkan nama bahan baku: ";
            getline(cin, namaItem);
            cout << "Masukkan jumlah stok baru: ";
            cin >> stok;
            updateStokBahanBaku(HashTable, namaItem, stok);
            system("pause");
            cout << endl;
            break;

        case 5:
            cout << "\tCari Bahan Baku" << endl;
            cariBahanBaku_cari();
            system("pause");
            break;

        case 9:
            break;

        default:
            cout << "\n\tPilihan tidak tersedia, coba lagi" << endl;
            break;
    }
}

void fiturUpdateMenu_pil(int input){
    switch(input){
        case 1:
            cout << "\tUpdate Harga Menu\n";
            cin.ignore();
            cout << "Masukkan nama item: ";
            getline(cin, namaItem);
            cout << "Masukkan harga baru: ";
            cin >> harga;
            updateHargaItemMenu(menuTree, namaItem, harga);
            system("pause");
            cout << endl;
            break;

        case 2:
            cout << "\tUpdate Stok Menu\n";
            cin.ignore();
            cout  << "Masukkan nama item: ";
            getline(cin, namaItem);
            cout << "Masukkan jumlah stok baru: ";
            cin >> stok;
            updateStokItemMenu(menuTree, namaItem, stok);
            system("pause");
            cout << endl;
            break;

        case 3:
            cout << "\tCari Menu\n";
            cariItemMenu_Cari();
            break;

        case 9:
            break;

        default:
            cout << "Pilihan tidak valid, coba lagi!" << endl;
            break;
    }
}

void fiturTambahMenu(){
    do{
        cout << "\n-----Tambah Menu-----" << endl;
        cout << "\t1. Tambah kategori" << endl;
        cout << "\t2. Tambah sub kategori" << endl;
        cout << "\t3. Tambah item menu" << endl;
        cout << "\t4. Tambah kategori/subkategori ke menu event" << endl;
        cout << "\t9. Back" << endl;
        cout << "\tMasukkan pilihan: ";
        cin >> pilihan;
        fiturTambahMenu_pil(pilihan);
    }while(pilihan != 9);
}

void fiturHapusMenu(){
    do{
        cout << "\n-----Hapus Menu-----" << endl;
        cout << "\t1. Hapus kategori" << endl;
        cout << "\t2. Hapus sub kategori" << endl;
        cout << "\t3. Hapus item menu" << endl;
        cout << "\t4. Hapus item event" << endl;
        cout << "\t9. Back" << endl;
        cout << "\tMasukkan pilihan: ";
        cin >> pilihan;
        fiturHapusMenu_pil(pilihan);
    }while(pilihan != 9);
}

void fiturBahanBaku(){
    do{
        cout << "\n-----Kelola Bahan Baku-----" << endl;
        cout << "\t1. Lihat semua bahan baku" << endl;
        cout << "\t2. Tambah bahan baku" << endl;
        cout << "\t3. Update harga" << endl;
        cout << "\t4. Update stok" << endl;
        cout << "\t5. Cari bahan baku" << endl;
        cout << "\t9. Back" << endl;
        cout << "\tMasukkan pilihan: ";
        cin >> pilihan;
        fiturBahanBaku_pil(pilihan);
    }while(pilihan != 9);
}

void fiturLihatMenu(){
    do{
        cout << "\n-----Lihat Menu-----" << endl;
        cout << "\t1. Semua menu\n";
        cout << "\t2. Menu event\n";
        cout << "\t3. Cari menu\n";
        cout << "\t9. Kembali\n";
        cout << "\tMasukkan pilihan: ";
        cin >> pilihan;
        fiturLihatMenu_pil(pilihan);
    }while(pilihan != 9);
}

void fiturUpdateMenu(){
    do{
        cout << "\n-----Update Menu-----" << endl;
        cout << "\t1. Update harga menu\n";
        cout << "\t2. Update stok menu\n";
        cout << "\t3. Cari menu\n";
        cout << "\t9. Kembali\n";
        cout << "\tMasukkan pilihan: ";
        cin >> pilihan;
        fiturUpdateMenu_pil(pilihan);
    }while(pilihan != 9);
}

void kelolaMenuDanHarga(){
    do{
        cout << "\n-----Kelola Menu dan Harga-----" << endl;
        cout << "1. Lihat menu\n";
        cout << "2. Tambah menu\n";
        cout << "3. Hapus menu\n";
        cout << "4. Update menu\n";
        cout << "9. Kembali\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

    switch(pilihan){
        case 1: 
            // cout << "-----Lihat Menu-----" << endl;
            fiturLihatMenu();
            cout << endl;
            break;

        case 2:
            // cout << "-----Tambah Menu-----" << endl;
            fiturTambahMenu();
            cout << endl;
            break;

        case 3:
            // cout << "-----Hapus Menu-----" << endl;
            fiturHapusMenu();
            cout << endl;
            break;

        case 4: 
            // cout << "-----Update Menu-----" << endl;
            fiturUpdateMenu();
            cout << endl;
            break;

        case 9: 
            break;

        default:
            cout << "Pilihan tidak tersedia, coba lagi!" << endl;
        }

    }while(pilihan != 9);
}

void menuUtama_pil(int input){
    switch(input){
        case 1: 
            // cout << "\n-----Kelola Menu dan Harga-----" << endl;
            kelolaMenuDanHarga();
            system("pause");
            cout << endl;
            break;

        case 2:
            cin.ignore();
            // cout << "\n-----Kelola Bahan Baku-----" << endl;
            fiturBahanBaku();
            system("pause");
            cout << endl;
            break;

        // ==========START REVISI==========
        // Keterangan revisi: Menambahkan fitur pesan menu
        case 3:
            cout << "\n-----Pesan Menu-----" << endl;
            pesanMenu();
            cout << endl;
            break;
        // ==========END REVISI==========

        case 0:
            cekStokBahanBaku(HashTable);
            cout << "\nTerima kasih, sampai jumpa!\n" << endl;
            exit(0);
            cout << endl;
            break;

        default:
            cout << "\nPilihan tidak tersedia, coba lagi!\n" << endl;
            break;
    }
}

int main(){
    // system("cls");

    menuTree = dataMenu();
    events = initEvents();

    // Inisialisasi bahan baku
    inisialisasiBahanBaku(HashTable);

    // Tampilan utama
    do{
        cout << "===============WELCOME===============" << endl;
        cout << "1. Kelola menu dan harga\n";
        cout << "2. Kelola bahan baku\n";
        // ==========START REVISI==========
        // Keterangan revisi: Menambahkan fitur pesan menu
        cout << "3. Pesan menu\n";
        cout << "0. Tutup\n";
        cout << "Masukkan pilihan [1/2/3/0] : ";
        // ==========END REVISI==========
        cin >> pilihan;
        menuUtama_pil(pilihan);
    } while(true);

    return 0;
}
