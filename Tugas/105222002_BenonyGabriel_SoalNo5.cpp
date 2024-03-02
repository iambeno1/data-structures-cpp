#include <iostream>
using namespace std;

struct
{
    float ipk;
    string jurusan;
    string alamat[4];
}mahasiswa;

typedef struct
{
    string nama_kelas;
    string hari;
    string waktu;
}jadwal;

int main()
{
    kelas jadwal_kelas[5];
    jadwal_kelas[0].nama_kelas = "Probsat";
    jadwal_kelas[0].hari = "senin";
    jadwal_kelas[0].waktu = "12:00";

    jadwal_kelas[1].nama_kelas = "Alin";
    jadwal_kelas[1].hari = "selasa";
    jadwal_kelas[1].waktu = "08:00";

    jadwal_kelas[2].nama_kelas = "ASD";
    jadwal_kelas[2].hari = "senin";
    jadwal_kelas[2].waktu = "17:00";

    jadwal_kelas[3].nama_kelas = "Basdat";
    jadwal_kelas[3].hari = "senin";
    jadwal_kelas[3].waktu = "10:00";

    jadwal_kelas[4].nama_kelas = "Dasar Pemrograman";
    jadwal_kelas[4].hari = "rabu";
    jadwal_kelas[4].waktu = "12:00";

    for (int i = 0; i <= 4; i++)
    {
        if (jadwal_kelas[i].hari == "senin")
        {
            cout << jadwal_kelas[i].nama_kelas << endl;
            cout << jadwal_kelas[i].waktu << endl;
            cout << endl;
        }
    }
    return 0;
}

