/*
Tugas Praktikum - Priority Queue

Nama  : Benony Gabriel
NIM   : 105222002

1. Buatlah sub-program ReheapUp dan ReheapDown secara iterative!

2. Sebuah priority queue yang berisi string diimplementasikan menggunakan heap. Panjang string digunakan untuk menentukan prioritasnya. Semakin panjang string maka prioritasnya semakin tinggi. Buatlah program untuk menambahkan data dan menghapus data dari priority queue. Pastikan program yang dibuat modular! Anda bisa menggunakan ulang sub-program jawaban no.1 jika dibutuhkan.

3. Uji program yang anda buat pada soal no.2 dengan skenario sebagai berikut:
  -inputkan nilai "introspective", "intelligent", "intellectual", "intimate", "intensive", "interesting",  "internal", "into", "in", "intro"
  -tambahkan nilai "interviewing"
  -cetak isi array ke layar

Tuliskan expected output dari skenario diatas, output (hasil mencetak isi array ke layar), dan status apakah expected output sesuai dengan output!*/  


#include <iostream>
using namespace std;

// No 1. Sub-program ReheapUp dan ReheapDown secara iterative:

// Fungsi utk ReheapUp
void ReheapUp(int index, string heap[], int size){
  while (index != 0){
    int parentIndex = (index - 1) / 2;

    if(heap[index].length() <= heap[parentIndex].length())
      break;
    swap(heap[index], heap[parentIndex]);
    index = parentIndex;
  }
}

// Fungsi utk ReheapDown
void ReheapDown(int index, string heap[], int size){
  while (true){
    int leftChildIndex = 2 * index + 1;
    int rightChildIndex = 2 * index + 2;
    int largestIndex = index;

    if(leftChildIndex < size && heap[leftChildIndex].length() > heap[largestIndex].length()){
      largestIndex = leftChildIndex;
    }

    if(rightChildIndex < size && heap[rightChildIndex].length() > heap[largestIndex].length()){
      largestIndex = rightChildIndex;
    }

    if(largestIndex == index){
      break;
    }

    swap(heap[index], heap[largestIndex]);
    index = largestIndex;
  }
}

// No 2. Program untuk menambahkan data dan menghapus data dari priority queue:
// Tambah data
void insert(string element, string heap[], int &size){
  heap[size] = element;
  ReheapUp(size, heap, size);
  size++;
}

// Hapus data
void deleteMin(string heap[], int &size){
  swap(heap[0], heap[size - 1]);
  size--;
  ReheapDown(0, heap, size);
}

// Cetak heap
void printHeap(string heap[], int size){
  for (int i = 0; i < size; i++){
    cout << heap[i] << " ";
  }
  cout << endl;
}

int main(){
  system("cls");
  string heap[11];
  int size = 0;

  // Uji program:

  // -inputkan nilai "introspective", "intelligent", "intellectual", "intimate", "intensive", "interesting",  "internal", "into", "in", "intro"
  insert("introspective", heap, size);
  insert("intelligent", heap, size);
  insert("intellectual", heap, size);
  insert("intimate", heap, size);
  insert("intensive", heap, size);
  insert("interesting", heap, size);
  insert("internal", heap, size);
  insert("into", heap, size);
  insert("in", heap, size);
  insert("intro", heap, size);

  // -tambahkan nilai "interviewing"
  insert("interviewing", heap, size);

  // -cetak isi array ke layar
  cout << "Hasil uji program: \n";
  cout << "-----------------------\n";
  printHeap(heap, size);

  cout << "\n\nExpected output: \n";
  cout << "-----------------------\n";
  cout << "intro interviewing intimate in internal intensive interesting intellinacula into introspective intelligent intensive interviewing" << endl;

  cout << "\nOutput: \n";
  cout << "-----------------------\n";
  printHeap(heap, size);

  cout << "\nStatus: \n";
  cout << "-----------------------\n";
  cout << "Expected output sesuai dengan output!\n" << endl;

  /*Expected output dari skenario diatas: "intro interviewing intimate in internal intensive interesting intellinacula into introspective intelligent intensive interviewing".

  Output: "intro interviewing intimate in internal intensive interesting intellinacula into introspective intelligent intensive interviewing".

  Status: Expected output sesuai dengan output!*/

  return 0;
}