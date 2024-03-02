// PRAKTEK 4 SINGLE LINKEDLIST PART 2

/* Catatan :
  - Linkedlist terbentuk dari node-node
  - Setiap node terdiri dari "data" dan "pointer" ke node selanjutnya
  - Bentuk node :

  +--------------+     +--------------+
  | Data | *next |---->| Data | NULL  |
  +--------------+     +--------------+
        Head                Tail
*/

#include <iostream>
using namespace std;

// Deklarasi node
struct data_mhs{
  string nama; // ini adalah data
  int umur; // ini juga data
  data_mhs *next; // ini pointer ke node selanjutnya
};

int main(){
  system("cls");

  // Inisialisasi node
  data_mhs *mhs1, *mhs2, *mhs3; // artinya membuat 3 buah node
  mhs1 = new data_mhs();
  mhs2 = new data_mhs();
  mhs3 = new data_mhs();

  // Mengisi data pada setiap node
  mhs1->nama = "Benony Gabriel";
  mhs1->umur = 19;
  mhs1->next = mhs2;

  mhs2->nama = "Jhon Doe";  
  mhs2->umur = 23;  
  mhs2->next = mhs3;  

  mhs3->nama = "Robert Fox";  
  mhs3->umur = 21;  
  mhs3->next = NULL;  

  // Print node
  data_mhs *cur; // Disini kita membuat satu variabel pointer yg akan berjalan ke setiap node utk mencetaknya
  cur = mhs1; // Dia akan dimulai dari node pertama yaitu mhs1

  while( cur != NULL){
    cout << "Nama \t: " << cur->nama << endl;
    cout << "Umur \t: " << cur->umur << endl;
    cout << endl;

    cur = cur->next;
  }

  return 0;
}