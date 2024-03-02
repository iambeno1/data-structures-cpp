// Membuat linkedlist menggunakan fungsi(void)

#include <iostream>
using namespace std;

struct data_mhs{
  string nama, nim, prodi;
  int tahunMasuk;
  data_mhs *next;
};

data_mhs *head, *tail, *cur;

void createSingleLinkedlist(string nama, string nim, string prodi, int tahunMasuk){
  head = new data_mhs();
  head->nama = nama;
  head->nim = nim;
  head->prodi = prodi;
  head->tahunMasuk = tahunMasuk;
  head->next = NULL;
  tail = head;
}

void printSingleLinkedlist(){
  cur = head;
  while (cur != NULL){
    cout << "Nama \t: " << cur->nama << endl;
    cout << "NIM \t: " << cur->nim << endl;
    cout << "Prodi \t: " << cur->prodi << endl;
    cout << "Tahun Masuk : " << cur->tahunMasuk << endl;
    cout << endl;

    cur = cur->next;
  }
}

int main(){
  system("cls");

  createSingleLinkedlist("Benony Gabriel", "105222002", "Computer Science", 2022);
  printSingleLinkedlist();

  return 0;
}