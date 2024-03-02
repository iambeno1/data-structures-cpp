#include <iostream>
using namespace std;

// Struct : adalah tipe data yang dapat menyimpan sejumlah elemen dengan tipe data berbeda

// Berikut ini adalah berbagai jenis dan cara yang saya praktekkan untuk mengimplementasikan konsep struct (record) dalam berbagai case

void data_ketua(){

  // Deklarasi struct
  struct identitas{
    string nama;
    string nim;
  };

  identitas ketua;
  cout << "Data Ketua PMK " << endl;
  cout << "Nama \t: ";
  getline(cin, ketua.nama);
  cout << "NIM \t: ";
  cin >> ketua.nim;
}

void array_of_struct(){

  struct identitas{
    string nama;
    int umur;
  };

  int jumlah_anggota;
  identitas anggota[jumlah_anggota];

  cout << "INPUT DATA ANGGOTA PMK" << endl;
  cout << "Masukkan Jumlah Anggota : ";
  cin >> jumlah_anggota;

  for (int i = 0; i < jumlah_anggota; i++){
    cout << "Anggota ke-" << i + 1 << " : ";
    cin >> anggota[i].nama;
    getline(cin, anggota[i].nama);
    cout << "Umur : ";
    cin >> anggota[i].umur;
  }

}

int main(){
  system("cls");

  data_ketua();
  cout << endl;

  array_of_struct();
  cout << endl;

  return 0;
}