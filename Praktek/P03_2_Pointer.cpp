#include <iostream>
using namespace std;

struct mataKuliah{
  string nama;
  char nilai;
  int sks;
};
void cetak_matkul(mataKuliah *mk);

int main(){
  system("cls");

  mataKuliah matkul;
  matkul.nama = "Kalkullus";
  matkul.nilai = 'A';
  matkul.sks = 3;

  cetak_matkul(&matkul);

  return 0;
}

void cetak_matkul(mataKuliah *mk){
  cout << "Nama \t: " << mk->nama << endl;
  cout << "Nilai\t: " << mk->nilai << endl;
  cout << "SKS\t: " << mk->sks << endl;
}