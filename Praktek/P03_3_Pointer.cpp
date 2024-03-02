#include <iostream>
using namespace std;

int main(){
  system("cls");
  int a = 10;
  int b = 5;

  cout << "Nilai Awal" << endl;
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;

  int *a_ptr, *b_ptr;
  a_ptr = &a;
  b_ptr = &b;

  cout << "Alamat variabel" << endl;
  cout << "\na_ptr = " << a_ptr << endl;
  cout << "b_ptr = " << b_ptr << endl;

  cout << "\nTampilkan Nilai" << endl;
  cout << "*a_ptr \t: " << *a_ptr << endl;
  cout << "*b_ptr \t: " << *b_ptr << endl;

  cout << "\nMelakukan Operasi Aritmatika" << endl;
  cout << "Penjumlahan \t: " << *a_ptr + *b_ptr << endl;
  cout << "Pengurangan \t: " << *a_ptr - *b_ptr << endl;
  cout << "Perkalian \t: " << *a_ptr * *b_ptr << endl;
  cout << "Pembagian \t: " << *a_ptr / *b_ptr << endl;

  return 0;
}