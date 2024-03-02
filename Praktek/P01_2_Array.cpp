#include <iostream>
using namespace std;

// Latihan array dari studi kasus


void kasus1(){

  // STUDI KASUS 1: Program untuk cari elemen array tertinggi dan ukuran array ditentukan oleh user

  int size;
  int data[size];
  cout << "Masukkan ukuran array : ";
  cin >> size;

  // Input data
  cout << "Input angka " << endl;
  for (int i = 0; i < size; i++){
    cout << "Angka ke-" << i+1 << " : ";
    cin >> data[i];
  }

  int nilai_Terbesar = data[0]; // kita gunakan indeks ke-0 utk dijadikan pembanding pada looping
  int posisi_Index = 0;
  for (int j = 1; j < size; j++){
    if (data[j] > nilai_Terbesar){
      nilai_Terbesar = data[j]; // disetiap iterasi, setiap elemen akan di bandingkan dengan indeks ke-0 dan apabila lebih besar maka nilai terbesar akan terus di update sampai looping selesai
      posisi_Index = j;
    }
  }
  cout << "Nilai terbesar adalah : " << nilai_Terbesar << endl;
  cout << "Berada pada index ke- : " << posisi_Index << endl;
}

void kasus2(){
  // STUDI KASUS 2: Program untuk membalikkan kata
  string kata;
  cout << "Membalik kata" << endl;
  cout << "Masukkan sebuah kata : ";
  cin >> kata;

  int panjang = kata.length();
  char temp[panjang + 1]; // Menambahkan 1 untuk karakter null terminator '\0'

  for (int i = 0; i < panjang; i++){
    temp[i] = kata[panjang - 1 - i];
  }

  temp[panjang] = '\0'; // Menambahkan karakter null terminator di akhir array
  cout << "Kata setelah dibalik : " << temp << endl;
}

int main(){
  system("cls");

  // kasus1();
  cout << endl;

  kasus2();
  cout << endl;

  return 0;
}