/*
  PRAKTEK KE-4 SINGLE LINKED LIST PART 4
  
  Melakukan penambahan dan penghapusan node :
  - Add first
  - Add last
  - Add after
  - Remove first
  - Remove last
  - Remove after
  - Modify first
  - Modify last
*/

#include <iostream>
using namespace std;

// Deklarasi node
struct data_mhs{
  string nama, nim, prodi;
  int tahunMasuk;
  data_mhs *next;
};

data_mhs *head, *tail, *cur, *newNode, *del;

// Create single linked list
void createSingleLinkedlist(string nama, string nim, string prodi, int tahunMasuk){
  head = new data_mhs();
  head->nama = nama;
  head->nim = nim;
  head->prodi = prodi;
  head->tahunMasuk = tahunMasuk;
  head->next = NULL;
  tail = head;
}

// Add first (menambahkan node diawal)
void addFirst(string nama, string nim, string prodi, int tahunMasuk){
  newNode = new data_mhs();
  newNode->nama = nama;
  newNode->nim = nim;
  newNode->prodi = prodi;
  newNode->tahunMasuk = tahunMasuk;
  newNode->next = head;
  head = newNode;
}

// Add last (menambahkan node diakhir)
void addLast(string nama, string nim, string prodi, int tahunMasuk){
  newNode = new data_mhs();
  newNode->nama = nama;
  newNode->nim = nim;
  newNode->prodi = prodi;
  newNode->tahunMasuk = tahunMasuk;
  newNode->next = NULL;
  tail->next = newNode;
  tail = newNode;
}

void addAfter(string nama, string nim, string prodi, int tahunMasuk, int posisi){
  newNode = new data_mhs();
  newNode->nama = nama;
  newNode->nim = nim;
  newNode->prodi = prodi;
  newNode->tahunMasuk = tahunMasuk;

  // Tranversing
  int nomor = 1;
  cur = head;
  while (nomor < posisi - 1){
    cur = cur->next;
    nomor++;
  }
  newNode->next = cur->next;
  cur->next = newNode;
}

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

  while(cur->next != tail){
    cur = cur->next;
  }
  tail = cur;
  tail->next = NULL;
  delete del;
}

// Modify first 
void changeFirst(string nama, string nim, string prodi, int tahunMasuk){
  head->nama = nama;
  head->nim = nim;
  head->prodi = prodi;
  head->tahunMasuk = tahunMasuk;
}

// Modify last
void changeLast(string nama, string nim, string prodi, int tahunMasuk){
  tail->nama = nama;
  tail->nim = nim;
  tail->prodi = prodi;
  tail->tahunMasuk = tahunMasuk;
}

// Print single linked list
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

  cout << "Single linked list awal" << endl;
  cout << "----------------------------------------" << endl;
  createSingleLinkedlist("Benony Gabriel", "105222002", "Computer Science", 2022);
  printSingleLinkedlist();

  cout << "\n\nAdd first ke single linked list" << endl;
  cout << "----------------------------------------" << endl;
  addFirst("Jhon Doe", "125222012", "Economy", 2021);
  printSingleLinkedlist();

  cout << "\n\nAdd last ke single linked list" << endl;
  cout << "----------------------------------------" << endl;
  addLast("Robert Fox", "123456789", "Management", 2019);
  printSingleLinkedlist();
  
  cout << "\n\nAdd after ke single linked list" << endl;
  cout << "----------------------------------------" << endl;
  addAfter("Obiata", "0999", "cacing", 1999, 2);
  printSingleLinkedlist();

  cout << "\n\nMenghapus node pertama" << endl;
  cout << "----------------------------------------" << endl;
  removeFirst();
  printSingleLinkedlist();
  cout << "Anda telah menghapus node pertama" << endl;

  cout << "\n\nMenghapus node akhir" << endl;
  cout << "----------------------------------------" << endl;
  removeLast();
  printSingleLinkedlist();
  cout << "Anda telah menghapus node akhir" << endl;

  cout << "\n\nAdd first ke single linked list" << endl;
  cout << "----------------------------------------" << endl;
  addFirst("Jhon Doe", "125222012", "Economy", 2020);
  printSingleLinkedlist();

  cout << "\n\nAdd last ke single linked list" << endl;
  cout << "----------------------------------------" << endl;
  addLast("Haekal", "123456789", "Management", 2023);
  printSingleLinkedlist();

  cout << "\n\nModify node awal single linked list" << endl;
  cout << "----------------------------------------" << endl;
  changeFirst("Jhonias Dosriel", "125222012", "Economy", 2021);
  printSingleLinkedlist();

  cout << "\n\nModify node akhir single linked list" << endl;
  cout << "----------------------------------------" << endl;
  changeLast("Haekal Putra", "123456789", "Management", 2022);
  printSingleLinkedlist();


  return 0;
}