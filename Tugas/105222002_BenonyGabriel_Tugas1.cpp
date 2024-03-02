#include <iostream>
using namespace std;

const int capacity = 5;

typedef struct {
    string nama_kopi[capacity] = {"Kopi Bajawa", "Kopi Catimor", "Kopi Gayo", "Kopi Mocha", "Kopi Kona"};
    string merek_kopi[capacity] = {"Nescafe", "Luwak", "Torabika", "ABC", "Gilus Mix"};
    float rating_kopi[capacity] = {5.0, 4.8, 4.9, 4.7, 4.5};
    int harga_perGram[capacity] = {3000, 1000, 2000, 1500, 500};
    string status_kopi[capacity] = {"Lokal", "Lokal", "Import", "Lokal", "Import"};
    string tanggal_beli[capacity] = {"12/04/2023", "30/06/2023", "19/10/2023", "25/08/2023", "01/08/2023"};
    int berat_kopi[capacity] = {9000, 7000, 8000, 6000, 800};

}stok_kopi;

void tampilkan_data(stok_kopi s) {
    cout << "\nData stok bubuk kopi:\n";
    cout << "\nNo.\tNama Kopi\tMerek\t\tRating\tHarga/Gram\tStatus\tTanggal Pembelian\tBerat (gram)\n";
    for (int i = 0; i < capacity; i++) {
        cout << i+1 << "\t" << s.nama_kopi[i] << "\t" << s.merek_kopi[i] << "\t" << s.rating_kopi[i] << "\t" << s.harga_perGram[i] << "\t\t" << s.status_kopi[i] << "\t" << s.tanggal_beli[i] << "\t\t" << s.berat_kopi[i] << endl;
    }
}

void bubble_sort(stok_kopi &s) {
    int n = 5;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s.tanggal_beli[j] > s.tanggal_beli[j + 1]) {
                string temp_nama_kopi = s.nama_kopi[j];
                s.nama_kopi[j] = s.nama_kopi[j + 1];
                s.nama_kopi[j + 1] = temp_nama_kopi;

                string temp_merek_kopi = s.merek_kopi[j];
                s.merek_kopi[j] = s.merek_kopi[j + 1];
                s.merek_kopi[j + 1] = temp_merek_kopi;

                float temp_rating_kopi = s.rating_kopi[j];
                s.rating_kopi[j] = s.rating_kopi[j + 1];
                s.rating_kopi[j + 1] = temp_rating_kopi;

                int temp_harga_perGram = s.harga_perGram[j];
                s.harga_perGram[j] = s.harga_perGram[j + 1];
                s.harga_perGram[j + 1] = temp_harga_perGram;

                string temp_status_kopi = s.status_kopi[j];
                s.status_kopi[j] = s.status_kopi[j + 1];
                s.status_kopi[j + 1] = temp_status_kopi;

                int temp_berat_kopi = s.berat_kopi[j];
                s.berat_kopi[j] = s.berat_kopi[j + 1];
                s.berat_kopi[j + 1] = temp_berat_kopi;
            }
        }
    }
}

void cari_data_terbanyak(stok_kopi s) {
    int max_berat = -1;
    int index_max_berat = -1;
    for (int i = 0; i < 5; i++) {
        if (s.berat_kopi[i] > max_berat) {
            max_berat = s.berat_kopi[i];
            index_max_berat = i;
        }
    }
    cout << "\nData stok bubuk kopi dengan berat terbanyak:\n";
    cout << "\nNama Kopi\tMerek\t\tBerat (gram)\n";
    cout << s.nama_kopi[index_max_berat] << "\t" << s.merek_kopi[index_max_berat] << "\t" << s.berat_kopi[index_max_berat] << endl;
}

void displayMenu() {
    cout << "===SELAMAT DATANG DI COFFEE-SHOP===" << endl;
    cout << "1. Lihat daftar stok" << endl;
    cout << "2. Urutkan per tanggal" << endl;
    cout << "3. Lihat Stok Terbanyak" << endl;
    cout << "4. Tambah Stok" << endl;
    cout << "5. Jual" << endl;
    cout << "0. Exit" << endl;
    cout << "Masukkan pilihan anda : ";
}

int main()
{

  int pilihan;
  pilihan = -1;
  stok_kopi s;

    while (pilihan != 0) {
        displayMenu();
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkan_data(s);
                cout << endl;
                break;

            case 2:
                bubble_sort(s);
                cout << "\nData stok bubuk kopi setelah diurutkan berdasarkan tanggal pembelian:\n";
                tampilkan_data(s);
                cout << endl;
                break;

            case 3:
                cari_data_terbanyak(s);
                cout << endl;
                break;

            case 4:
                cout << "on progress" << endl;
                cout << endl;
                break;

            case 5:
                cout << "on progress" << endl;
                cout << endl;
                break;

            case 0:
                cout << "Terima kasih! Keluar dari program." << endl;
                break;

            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
        }
    }

    return 0;
}

