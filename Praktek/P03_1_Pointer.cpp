/*
  Pengenalan pointer
  Pointer adalah sebuah variabel yang menunjuk ke suatu alamat lokasi memori dari suatu variabel atau objek lainnya;

  Kegunaan pointer:
    - Akses memori secara langsung
    - Pengiriman alamat sebagai argumen fungsi
    - Untuk mengulang elemen di larik atau struktur data lainnya 
  
  Deklarasi Pointer:
  Pointer dideklarasikan sama seperti deklarasi variabel pada umumnya yaitu typedata variablename, namun ada penambahan satu simbol lagi yaitu simbol * (bintang/asterisk)
  
    Contoh deklarasi pointer:
    - int *angka;
    - double *ipk;
    - float  *derajat;
    - char *predikat;
    - string *nama;
*/ 

#include <iostream>
using namespace std;

int main()
{
    int bil_1 = 10;
    int bil_2 = 5;

    int *addr_1 = &bil_1;
    int *addr_2 = &bil_2;

    cout << "*addr_1 = " << *addr_1 << endl;
    cout << "&addr_1 = " << &addr_1 << endl;
    cout << "addr_1 = " << addr_1 << endl;
}
