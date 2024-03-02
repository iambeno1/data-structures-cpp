#include <iostream>
#include <vector>
using namespace std;

int main(){

  vector<int> dynamicArray; // Array dinamis menggunakan std vector

  // Inisialisasi elemen-elemen array
  for(int i = 0; i < 3; i++){
    dynamicArray.push_back(i * 10);
  }

  // Menampilkan elemen-elemen array
  cout << "Array dinamis awal ukuran " << dynamicArray.capacity() << " : ";
  for(int i = 0; i < dynamicArray.size(); i++){
    cout << dynamicArray[i] << " ";
  }
  cout << endl;

  // Perubahan ukuran : menambah elemen baru
  dynamicArray.push_back(30);
  dynamicArray.push_back(40);

  // Menampilkan elemen-elemen array yang telah diubah ukurannya
  cout << "Array dinamis yang telah diubah ukurannya " << dynamicArray.capacity() << ": ";
  for(int i = 0; i < dynamicArray.size(); i++){
    cout << dynamicArray[i] << " ";
  }
  cout << endl;

  return 0;
}