#include <iostream>
#include <string>

using namespace std;

struct passenger_t {
    string name;
    string seat_number;
    string flight_number;
    string departure_date;
    string departure_time;
};

// Fungsi untuk mencetak informasi penumpang
void displayPassengerInfo(const passenger_t &passenger) {
    cout << "Data Penumpang:" << endl;
    cout << "Nama: " << passenger.name << endl;
    cout << "Nomor Kursi: " << passenger.seat_number << endl;
    cout << "Nomor Penerbangan: " << passenger.flight_number << endl;
    cout << "Tanggal Keberangkatan: " << passenger.departure_date << endl;
    cout << "Waktu Keberangkatan: " << passenger.departure_time << endl;
}

// Fungsi untuk menghapus penumpang berdasarkan nama
passenger_t* removePassengerByName(const string &name, passenger_t* passengers, int &num_passengers) {
    int found_index = -1;

    // Cari penumpang dengan nama yang sesuai
    for (int i = 0; i < num_passengers; ++i) {
        if (passengers[i].name == name) {
            found_index = i;
            break;
        }
    }

    // Jika penumpang ditemukan, hapus penumpang dengan menggeser elemen array
    if (found_index != -1) {
        for (int i = found_index; i < num_passengers - 1; ++i) {
            passengers[i] = passengers[i + 1];
        }
        num_passengers--;  // Kurangi jumlah penumpang
        passengers = (passenger_t*)realloc(passengers, num_passengers * sizeof(passenger_t));  // Perbaharui memori
    }

    return passengers;
}

int main() {
    const int initial_num_passengers = 4;  // Termasuk penumpang baru sebelumnya
    int num_passengers = initial_num_passengers;

    // Alokasi array dinamis untuk menyimpan penumpang
    passenger_t *passengers = new passenger_t[num_passengers];

    // Mengisi data penumpang awal
    passengers[0] = {"John Doe", "1A", "AB123", "12/08/23", "14:30:00"};
    passengers[1] = {"Jane Doe", "1B", "AB123", "12/08/23", "14:30:00"};
    passengers[2] = {"John Kennedy", "5D", "AB123", "12/08/23", "14:30:00"};
    passengers[3] = {"Jacky Kennedy", "5F", "AB123", "12/08/23", "14:30:00"};

    // Menampilkan data penumpang sebelum penghapusan
    cout << "Data Penumpang sebelum penghapusan:" << endl;
    for (int i = 0; i < num_passengers; ++i) {
        displayPassengerInfo(passengers[i]);
        cout << endl;
    }

    // Penumpang Jacky Doe membatalkan penerbangannya
    passengers = removePassengerByName("Jacky Doe", passengers, num_passengers);

    // Menampilkan data penumpang setelah penghapusan
    cout << "\nData Penumpang setelah penghapusan:" << endl;
    for (int i = 0; i < num_passengers; ++i) {
        displayPassengerInfo(passengers[i]);
        cout << endl;
    }

    // Membersihkan memori yang dialokasikan
    delete[] passengers;

    return 0;
}

