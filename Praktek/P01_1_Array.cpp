#include <iostream>
using namespace std;

// Array : adalah tipe data yang dapat menyimpan sejumlah elemen yang bertipe data sama

// Berikut ini adalah berbagai jenis dan cara yang saya praktekkan untuk mengimplementasikan konsep array dalam berbagai case

void array1(){

  // Deklarasi array
  string mahasiswa[5]; 

  // Inisialisasi array cara 1:
  mahasiswa[0] = "Beno";
  mahasiswa[1] = "Felix";
  mahasiswa[2] = "Humam";

  // Deklarasi + inisialisasi array:
  string prodi[3] = {"Ilmu Komputer", "Manajemen", "Ekonomi"};

  // Mengakses elemen array:
  for (int i = 0; i < 5; i++){
    cout << prodi[i] << " ";
  }
  cout << endl;
  cout << "Data Mahasiswa" << endl;
  cout << "Nama \t: " << mahasiswa[0] << endl;
  cout << "Prodi \t: " << prodi[0] << endl;
}

void array2(){

  // Membuat array 2D
  // Array 2D itu konsepnya sama dengan matriks yang dimana memiliki baris dan kolom

  int no_urut[3][2] = {
    {1, 2},
    {3, 4},
    {5, 6}
  };

  // Mengakses elemen array 2D:
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 2; j++){
      cout << no_urut[i][j] << " ";
    }
    cout << endl;
  }

  string matkul[4][3] = {
    {"Kode", "Nama Matkkul", "Pengajar"},
    {"52001", "Probstat", "Ade Irawan"},
    {"52002", "Alin", "M. Zaky A"},
    {"52003", "ASD", "Meredita"}
  };

  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 3; j++){
      cout << matkul[i][j] << " \t";
    }
    cout << endl;
  }
}

void array3(){

  int id[] =  {1, 2, 3, 4};
  cout << id[3] << endl;

  cout <<  "ID : ";
  for (int i =  0; i < 4; i++){
    cout << id[i] << " ";
  }
  cout << "\n" << endl;

  char abjad[2][3] = {
    {'a', 'b', 'c'},
    {'d', 'e', 'f'}
  };

  for(int i =  0; i < 2; i++){
    for (int j = 0; j < 3; j++){
      cout << abjad[i][j] << " ";
    }
    cout << endl;
  }
}

void array4(){
  // string anggota[];
  string anggota[] = {"Beno"};
}

void  array5(){
  float ipk[4] = {3.02, 3.7, 2.8};
  ipk[3] = {3.5};

  cout << ipk[3] << endl;

  for (int i = 0; i < 4; i++){
    cout << ipk[i] << " ";
  }
}

void array6(){
  string nama[5] = {"Abri", "Ridho", "Haekal"};
  string hobi[5] = {"Gym", "Suka Desain", "Futsal"};

  cout << "Nama \t: " << nama[1] << endl;
  cout << "Hobi \t: " << hobi[1] << endl;
}


int main(){
  system("cls");
  array1();
  cout << endl;

  array2();
  cout << endl;

  array3();
  cout << endl;

  array5();
  cout << endl;

  array6();
  cout << endl;

  return 0;
}