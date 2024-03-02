/*9.3 Latihan Soal 
Berikut ini adalah silsilah keluarga kerjaan Inggris: 
- Elizabeth memiliki anak Charles, Anne, Andrew, dan Edward 
- Charles memiliki anak William dan Harry 
- Anne memiliki anak Peter dan Zara 
- Andrew memiliki anak Beatrice dan Eugene 
- Edward memiliki anak Louise dan James 
- William memiliki anak Geoge, Charlotte, dan Louis 
 
3. Buatlah program untuk mendeklarasikan struktur data yang tepat untuk menyimpan data silsilah keluarga tersebut menggunakan implementasi list of children! */

#include <iostream>
#include <string>
using namespace std;

struct dataKeluarga {
    string name;
    dataKeluarga *parent;
    dataKeluarga *firstChild;

    dataKeluarga(const string& memberName, dataKeluarga *parentPtr = nullptr)
        : name(memberName), parent(parentPtr), firstChild(nullptr) {}
    
    // Fungsi untuk menambahkan child
    void addChild(dataKeluarga *child) {
        if (firstChild == nullptr) {
            firstChild = child;
        } else {
            dataKeluarga *currentChild = firstChild;
            while (currentChild->nextSibling != nullptr) {
                currentChild = currentChild->nextSibling;
            }
            currentChild->nextSibling = child;
        }
    }

    // Fungsi untuk menampilkan children
    void displayChildren() const {
        dataKeluarga* currentChild = firstChild;
        while (currentChild != nullptr) {
            cout << currentChild->name << " ";
            currentChild = currentChild->nextSibling;
        }
        cout << endl;
    }

    dataKeluarga *nextSibling;
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

    // Menambahkan children ke dalam list
    elizabeth.addChild(&charles);
    elizabeth.addChild(&anne);
    elizabeth.addChild(&andrew);
    elizabeth.addChild(&edward);

    charles.addChild(&william);
    charles.addChild(&harry);

    anne.addChild(&peter);
    anne.addChild(&zara);

    andrew.addChild(&beatrice);
    andrew.addChild(&eugene);

    edward.addChild(&louise);
    edward.addChild(&james);

    william.addChild(&george);
    william.addChild(&charlotte);
    william.addChild(&louis);

    // NOTE: HANYA DEKLARASI STRUKTUR DATA TIDAK MENAMPILKANNYA

    return 0;
}
