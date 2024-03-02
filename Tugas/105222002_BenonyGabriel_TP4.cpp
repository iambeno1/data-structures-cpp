// Nama : Benony Gabriel
// NIM  : 105222002

#include <iostream>
#include <vector>
#include <string> // Tambahkan header string
using namespace std;

const int jml_mhs = 3;

struct {
    string kodeMatkul;
    int kelas;
    int kredit;
} matkul;

struct {
    int NIM;
    vector<matkul> mataKuliah;
} mahasiswa;

mahasiswa daftar_mhs[jml_mhs];

void Inisialisasi_mhs() {
    daftar_mhs[0].NIM = 1111;
    daftar_mhs[1].NIM = 1234;
    daftar_mhs[2].NIM = 1357;

    // Tambahkan inisialisasi vektor mataKuliah
    for (int i = 0; i < jml_mhs; i++) {
        daftar_mhs[i].mataKuliah.clear();
    }
}

void hitung_mhs(string kodeMatkul, int kelas) {
    int total = 0;
    for (int i = 0; i < jml_mhs; i++) {
        for (int j = 0; j < daftar_mhs[i].mataKuliah.size(); j++) {
            if ((daftar_mhs[i].mataKuliah[j].kodeMatkul == kodeMatkul) && (daftar_mhs[i].mataKuliah[j].kelas == kelas)) {
                total++;
            }
        }
    }
    cout << "Total mahasiswa yang mengambil " << kodeMatkul << " di kelas " << kelas << " adalah: " << total << " mahasiswa." << endl;
}

void tampilkan_mhs_tdk_aktif() {
    for (int i = 0; i < jml_mhs; i++) {
        if (daftar_mhs[i].mataKuliah.empty()) {
            cout << "Mahasiswa dengan NIM " << daftar_mhs[i].NIM << " tidak aktif." << endl;
        }
    }
}

void total_sks() {
    for (int i = 0; i < jml_mhs; i++) {
        cout << "NIM Mahasiswa: " << daftar_mhs[i].NIM << " - ";
        int totalSKS = 0;
        for (int j = 0; j < daftar_mhs[i].mataKuliah.size(); j++) {
            totalSKS += daftar_mhs[i].mataKuliah[j].kredit;
        }
        cout << totalSKS << " SKS" << endl;
    }
}

void add_matkul(int NIM, string kodeMatkul, int kelas, int kredit) {
    for (int i = 0; i < jml_mhs; i++) {
        if (daftar_mhs[i].NIM == NIM) {
            matkul matkuliah;
            matkuliah.kodeMatkul = kodeMatkul;
            matkuliah.kredit = kredit;
            matkuliah.kelas = kelas;
            daftar_mhs[i].mataKuliah.push_back(matkuliah);
            return;
        }
    }
}

void remove_matkul(int NIM, string kodeMatkul) {
    for (int i = 0; i < jml_mhs; i++) {
        for (int j = 0; j < daftar_mhs[i].mataKuliah.size(); j++) {
            if ((daftar_mhs[i].NIM == NIM) && (daftar_mhs[i].mataKuliah[j].kodeMatkul == kodeMatkul)) {
                daftar_mhs[i].mataKuliah.erase(daftar_mhs[i].mataKuliah.begin() + j);
                return;
            }
        }
    }
}

void show_data_mhs() {
    for (int i = 0; i < jml_mhs; i++) {
        cout << "NIM Mahasiswa: " << daftar_mhs[i].NIM << endl;
        for (int j = 0; j < daftar_mhs[i].mataKuliah.size(); j++) {
            cout << daftar_mhs[i].mataKuliah[j].kodeMatkul << " - " << daftar_mhs[i].mataKuliah[j].kelas << " - " << daftar_mhs[i].mataKuliah[j].kredit << endl;
        }
        cout << endl;
    }
}

int main() {
  system("cls");
    Inisialisasi_mhs();
    add_matkul(daftar_mhs[0].NIM, "CIS120", 1, 3);
    add_matkul(daftar_mhs[0].NIM, "HIS001", 2, 4);

    add_matkul(daftar_mhs[2].NIM, "CIS120", 2, 3);

    show_data_mhs();

    cout << "=================================" << endl;

    remove_matkul(daftar_mhs[0].NIM, "CIS120");

    show_data_mhs();

    cout << "=================================" << endl;

    add_matkul(daftar_mhs[0].NIM, "RPL117", 4, 3);
    add_matkul(daftar_mhs[0].NIM, "HTS420", 3, 3);
    add_matkul(daftar_mhs[2].NIM, "HTS420", 3, 3);
    add_matkul(daftar_mhs[2].NIM, "RPL117", 3, 3);

    total_sks();

    cout << "=================================" << endl;

    show_data_mhs();

    cout << "=================================" << endl;

    hitung_mhs("HTS420", 3);

    return 0;
}
