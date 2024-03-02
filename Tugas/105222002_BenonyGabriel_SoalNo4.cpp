#include <iostream>
using namespace std;

struct{
    int nim;
    string nama;
    float ipk;
}mahasiswa;

int main()
{
    mahasiswa mhs[3];
    mhs[0].nim = 12345;
    mhs[0].nama = "Jhon Doe";
    mhs[0].ipk = 3.85;

    mhs[1].nim = 12346;
    mhs[1].nama = "Jane";
    mhs[1].ipk = 2.4;

    mhs[2].nim = 12347;
    mhs[2].nama = "Martin";
    mhs[2].ipk = 3.0;

    // Menambahkan nilai IPK semua mahasiswa dengan 0.2
    for (int i = 0; i < 3; i++) {
        mhs[i].ipk += 0.2;

        // Jika hasil penambahan lebih dari 4.0, buatlah IPK menjadi 4.0
        if (mhs[i].ipk > 4.0) {
            mhs[i].ipk = 4.0;
        }
    }

    // Menampilkan mahasiswa yang memiliki IPK di bawah 3.0
    cout << "Mahasiswa yang memiliki IPK di bawah 3.0:" << endl;
    for (int i = 0; i < 3; i++) {
        if (mhs[i].ipk < 3.0) {
            cout << "NIM: " << mhs[i].nim << endl;
            cout << "Nama: " << mhs[i].nama << endl;
            cout << "IPK: " << mhs[i].ipk << endl;
            cout << endl;
        }
    }

    return 0;
}

