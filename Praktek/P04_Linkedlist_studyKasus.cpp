#include <iostream>
using namespace std;

// PRAKTEK SINGLE LINKED LIST

// Deklarasi node
struct data_mhs{
  string nama;
  int umur;
  data_mhs *next;
};

data_mhs *head, *tail, *cur, *newNode, *del;
string input_nama;
int input_umur, pilihan;

// Create single linked list
void createSingleLinkedlist(string nama, int umur){
  head = new data_mhs();
  head->nama = nama;
  head->umur = umur;
  head->next = NULL;
  tail = head;
}

// Tambah node

// Add first
void addFirst(string nama, int umur){
  newNode = new data_mhs();
  newNode->nama = nama;
  newNode->umur = umur;
  newNode->next = head;
  head = newNode;
}

// Add last
void addLast(string nama, int umur){
  newNode = new data_mhs();
  newNode->nama = nama;
  newNode->umur = umur;
  newNode->next = NULL;
  tail->next = newNode;
  tail = newNode;
}

// Hapus data

// Remove first
void removeFirst(){
  del = head;
  head = head->next;
  delete del;
}

// Remove last
void removeLast(){
  del = tail;
  cur = head;
  while (cur->next != tail){
    cur = cur->next;
  }
  tail = cur;
  tail->next = NULL;
  delete del;
}

// Print single linked list
void printLinkedlist(){
  cur = head;
  cout << "DATA MAHASISWA" << endl;
  cout << "---------------\n" << endl;
  while (cur != NULL){
    cout << "Nama \t: " << cur->nama << endl;
    cout << "Umur \t: " << cur->umur << endl;
    cout << endl;

    cur = cur->next;
  }
}

// Isi data diawal
void isiDataAwal(){
  if (head == NULL){
    cout << "Data belum ada, silakan mengisi data" << endl;
    cin.ignore();
    cout << "Masukan nama\t: ";
    getline(cin, input_nama);
    cout << "Masukan umur\t: ";
    cin >> input_umur;
    createSingleLinkedlist(input_nama, input_umur);
  }else{
    cin.ignore();
    cout << "Masukan nama\t: ";
    getline(cin, input_nama);
    cout << "Masukan umur\t: ";
    cin >> input_umur;
    addFirst(input_nama, input_umur);
  }
}

// Isi data diakhir
void isiDataAkhir(){
  if (head == NULL){
    cout << "Data belum ada, silakan mengisi data" << endl;
    cin.ignore();
    cout << "Masukan nama\t: ";
    getline(cin, input_nama);
    cout << "Masukan umur\t: ";
    cin >> input_umur;
    createSingleLinkedlist(input_nama, input_umur);
  }else{
    cin.ignore();
    cout << "Masukan nama\t: ";
    getline(cin, input_nama);
    cout << "Masukan umur\t: ";
    cin >> input_umur;
    addLast(input_nama, input_umur);
  }
}

// Menu tambah data
void menuTambahData(){
  do{
    cout << "\tTambah data" << endl;
    cout << "\t1. Tambah data diawal" << endl;
    cout << "\t2. Tambah data diakhir" << endl;
    cout << "\t9. Kembali" << endl;
    cout << "\tMasukkan pilihan [1/2/9] : ";
    cin >> pilihan;
    cout << endl;
      switch (pilihan){
        case 1:
          isiDataAwal();
          cout << endl;
          break;
        case 2: 
          isiDataAkhir();
          cout << endl;
          break;
        case 9:
          cout << "\tMenu utama" << endl;
          cout << endl;
          break;
        default:
          cout << "\tPilihan tidak valid, coba lagi!" << endl;
          cout << endl;
          break;
      }
    }while (pilihan != 9);
}

// Menu hapus data
void menuHapusData(){
  do{
    cout << "\tHapus data" << endl;
    cout << "\t1. Hapus data awal" << endl;
    cout << "\t2. Hapus data akhir" << endl;
    cout << "\t9. Kembali" << endl;
    cout << "\tMasukkan pilihan : ";
    cin >> pilihan;
    cout << endl;
      switch (pilihan){
        case 1:
          removeFirst();
          cout << endl;
          break;
        case 2: 
          removeLast();
          cout << endl;
          break;
        case 9:
          cout << "\tMenu utama" << endl;
          cout << endl;
          break;
        default:
          cout << "\tPilihan tidak valid, coba lagi!" << endl;
          cout << endl;
          break;
      }
    }while (pilihan != 9);
}

// Menu utama
void menuUtama(){
  while (true){
    cout << "Data Mahasiswa" << endl;
    cout << "1. Tambah data" << endl;
    cout << "2. Hapus data" << endl;
    cout << "3. Lihat data" << endl;
    cout << "0. Exit" << endl;
    cout << "Masukkan pilihan : ";
    cin >> pilihan;
    cout << endl;

    switch (pilihan){
      case 1:
        menuTambahData();
        break;
      case 2:
        menuHapusData();
        break;
      case 3:
        printLinkedlist();
        break;
      case 0:
        cout << "Exit" << endl;
        return;
      default:
        cout << "Pilihan tidak valid, coba lagi!" << endl;
    }
  }
}

int main(){
  system("cls");

  menuUtama();  


  return 0;
}