/*9.3 Latihan Soal 
Berikut ini adalah silsilah keluarga kerjaan Inggris: 
- Elizabeth memiliki anak Charles, Anne, Andrew, dan Edward 
- Charles memiliki anak William dan Harry 
- Anne memiliki anak Peter dan Zara 
- Andrew memiliki anak Beatrice dan Eugene 
- Edward memiliki anak Louise dan James 
- William memiliki anak Geoge, Charlotte, dan Louis 
 
1. Buatlah program untuk mendeklarasikan struktur data yang tepat untuk menyimpan data Silsilah keluarga tersebut jika ingin diimplementasikan menggunakan parent pointer! */


#include <iostream>
#include <string>
using namespace std;

const int maxChild = 5;

struct dataKeluarga {
    string name;
    dataKeluarga *parent;
    dataKeluarga *children[maxChild];
    int numChildren;

    dataKeluarga(const string& childName, dataKeluarga *parentPtr = nullptr)
        : name(childName), parent(parentPtr), numChildren(0) {}
};

int main() {
    // Deklarasi anggota keluarga
    dataKeluarga elizabeth("Elizabeth");
    dataKeluarga charles("Charles", &elizabeth);
    dataKeluarga anne("Anne", &elizabeth);
    dataKeluarga andrew("Andrew", &elizabeth);
    dataKeluarga edward("Edward", &elizabeth);
    dataKeluarga william("William", &charles);
    dataKeluarga harry("Harry", &charles);
    dataKeluarga peter("Peter", &anne);
    dataKeluarga zara("Zara", &anne);
    dataKeluarga beatrice("Beatrice", &andrew);
    dataKeluarga eugene("Eugene", &andrew);
    dataKeluarga louise("Louise", &edward);
    dataKeluarga james("James", &edward);
    dataKeluarga george("George", &william);
    dataKeluarga charlotte("Charlotte", &william);
    dataKeluarga louis("Louis", &william);

    // NOTE: HANYA DEKLARASI STRUKTUR DATA TIDAK MENAMPILKANNYA

    return 0;
}
