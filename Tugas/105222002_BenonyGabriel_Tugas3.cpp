#include <iostream>
#include <vector> // untuk akses dynamic array
#include <string>
using namespace std;

/*
STRUKTUR ORGANISASI KEDAI KOPI KENANGAN SENJA

                          Store_Manager
                               |
                        Assistant_Manager
                               |
                           Supervisor
                               |
              +----------------------------------+
              |                |                 |
            Barista          Waiter       Kitchen_Steward
*/

// Deklarasi struktur data
struct DataPegawai {
    string name;
    string position;
    string supervisor;
};

struct Pegawai {
    DataPegawai storeManager, assistantManager;
    vector<DataPegawai> supervisors;
    vector<DataPegawai> baristas;
    vector<DataPegawai> waiters;
    vector<DataPegawai> kitchenStewards;
};

struct Shift {
    string time;
    string supervisor;
    vector<DataPegawai> baristas;
    vector<DataPegawai> waiters;
    vector<DataPegawai> kitchenStewards;
};

// Deklarasi variabel golbal "kedaiKopi"
Pegawai kedaiKopi;

void strukturOrganisasi(Pegawai& kedaiKopi) {
    // Menampilkan struktur organisasi
    cout << "Struktur Organisasi Kedai Kopi" << endl;
    cout << "-------------------------------" << endl;
    cout << "Store Manager \t  : " << kedaiKopi.storeManager.name << endl;
    cout << "Assistant Manager : " << kedaiKopi.assistantManager.name << endl;

    cout << "Supervisors \t  :";
    for (const auto& supervisor : kedaiKopi.supervisors) {
        cout << " " << supervisor.name;
    }
    cout << endl;

    cout << "Baristas \t  :";
    for (const auto& barista : kedaiKopi.baristas) {
        cout << " " << barista.name;
    }
    cout << endl;

    cout << "Waiters \t  :";
    for (const auto& waiter : kedaiKopi.waiters) {
        cout << " " << waiter.name;
    }
    cout << endl;

    cout << "Kitchen Stewards  :";
    for (const auto& kitchenSteward : kedaiKopi.kitchenStewards) {
        cout << " " << kitchenSteward.name;
    }
    cout << "\n" << endl;
}

void isiDataOrganisasi(){
    // Mengisi data pegawai
    kedaiKopi.storeManager = {"Beno", "Store Manager"};
    kedaiKopi.assistantManager = {"Sholihin", "Assistant Manager"};

    kedaiKopi.supervisors.push_back({"Aditya", "Supervisor"});
    kedaiKopi.supervisors.push_back({"Bella", "Supervisor"});
    kedaiKopi.supervisors.push_back({"Candra", "Supervisor"});
    kedaiKopi.supervisors.push_back({"Yudha", "Supervisor"});

    kedaiKopi.baristas.push_back({"Dian", "Barista"});
    kedaiKopi.baristas.push_back({"Erlangga", "Barista"});
    kedaiKopi.baristas.push_back({"Jasmine", "Barista"});
    kedaiKopi.baristas.push_back({"Kurnia", "Barista"});
    kedaiKopi.baristas.push_back({"Liana", "Barista"});

    kedaiKopi.waiters.push_back({"Farida", "Waiter"});
    kedaiKopi.waiters.push_back({"Guntur", "Waiter"});
    kedaiKopi.waiters.push_back({"Mochamad", "Waiter"});
    kedaiKopi.waiters.push_back({"Nadia", "Waiter"});
    kedaiKopi.waiters.push_back({"Okta", "Waiter"});

    kedaiKopi.kitchenStewards.push_back({"Hana", "Kitchen Steward"});
    kedaiKopi.kitchenStewards.push_back({"Irfan", "Kitchen Steward"});
    kedaiKopi.kitchenStewards.push_back({"Putra", "Kitchen Steward"});
    kedaiKopi.kitchenStewards.push_back({"Rizki", "Kitchen Steward"});
    kedaiKopi.kitchenStewards.push_back({"Sari", "Kitchen Steward"});
}

void aturShift(Shift& shift, const string& position, const vector<string>& personnel) {
    if (position == "Supervisor") {
        shift.supervisor = personnel[0];
    } else if (position == "Barista") {
        for (const auto& person : personnel) {
            DataPegawai barista;
            barista.name = person;
            barista.position = position;
            barista.supervisor = shift.supervisor;
            shift.baristas.push_back(barista);
        }
    } else if (position == "Waiter") {
        for (const auto& person : personnel) {
            DataPegawai waiter;
            waiter.name = person;
            waiter.position = position;
            waiter.supervisor = shift.supervisor;
            shift.waiters.push_back(waiter);
        }
    } else if (position == "Kitchen Steward") {
        for (const auto& person : personnel) {
            DataPegawai kitchenSteward;
            kitchenSteward.name = person;
            kitchenSteward.position = position;
            kitchenSteward.supervisor = shift.supervisor;
            shift.kitchenStewards.push_back(kitchenSteward);
        }
    }
}

void lihatShift(const Shift& shift) {
    cout << "Shift Time: " << shift.time << "\n";
    cout << "Supervisor: " << shift.supervisor << "\n";

    cout << "Baristas:\n";
    for (const auto& barista : shift.baristas) {
        cout << "  - " << barista.name << endl;
    }

    cout << "Waiters:\n";
    for (const auto& waiter : shift.waiters) {
        cout << "  - " << waiter.name << endl;
    }

    cout << "Kitchen Stewards:\n";
    for (const auto& kitchenSteward : shift.kitchenStewards) {
        cout << "  - " << kitchenSteward.name << endl;
    }

    cout << "\n";
}

void shift(){
    vector<Shift> schedule;

    // Menyusun Jadwal Shift
    Shift morningShift;
    morningShift.time = "Pagi (7-11)";
    schedule.push_back(morningShift);

    Shift afternoonShift;
    afternoonShift.time = "Siang (11-15)";
    schedule.push_back(afternoonShift);

    Shift eveningShift;
    eveningShift.time = "Sore (16-19)";
    schedule.push_back(eveningShift);

    Shift nightShift;
    nightShift.time = "Malam (20-22)";
    schedule.push_back(nightShift);

    // Mengatur Personel untuk Setiap Shift
    aturShift(schedule[0], "Supervisor", {"Aditya"});
    aturShift(schedule[0], "Barista", {"Dian", "Erlangga", "Jasmine"});
    aturShift(schedule[0], "Waiter", {"Farida"});
    aturShift(schedule[0], "Kitchen Steward", {"Rizki"});

    aturShift(schedule[1], "Supervisor", {"Bella"});
    aturShift(schedule[1], "Barista", {"Kurnia", "Liana"});
    aturShift(schedule[1], "Waiter", {"Nadia", "Okta"});
    aturShift(schedule[1], "Kitchen Steward", {"Putra"});

    aturShift(schedule[2], "Supervisor", {"Candra"});
    aturShift(schedule[2], "Barista", {"Dian", "Erlangga"});
    aturShift(schedule[2], "Waiter", {"Guntur", "Mochammad"});
    aturShift(schedule[2], "Kitchen Steward", {"Sari", "Putra"});

    aturShift(schedule[3], "Supervisor", {"Yudha"});
    aturShift(schedule[3], "Barista", {"Okta", "Jasmine", "Liana"});
    aturShift(schedule[3], "Waiter", {"Guntur", "Mochammad"});
    aturShift(schedule[3], "Kitchen Steward", {"Hana", "Irfan"});

    // Menampilkan Jadwal Shift dan Personel
    for (const auto& shift : schedule) {
        lihatShift(shift);
    }

}


int main() {
    system("cls");

    int pilihan;

    do{
        cout << "KEDAI KOPI KENANGAN SENJA" << endl;
        cout << "-------------------------" << endl;
        cout << "1. Lihat struktur organisasi" << endl;
        cout << "2. Lihat daftar shift" << endl;
        cout << "0. Exit \n" << endl;
        cout << "Masukkan pilihan anda : ";
        cin >> pilihan;
        cout << endl;

        switch(pilihan){
            case 1:
                isiDataOrganisasi();
                strukturOrganisasi(kedaiKopi);
                break;
            case 2: 
                shift();
                break;
            case 0:
                cout << "Berhasil keluar\n" << endl;
                exit(1);
                break;
            default:
                cout << "Pilihan tidak valid, coba lagi\n" << endl;
        }

    }while(true);

    return 0;
}