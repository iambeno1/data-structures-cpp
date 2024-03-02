#include <iostream>
#include <cstring>
using namespace std;

const int max_permen = 100;

void pilih_kuning(char* permen, int& size) {
    char tempArray[max_permen];
    int tempIndex = 0;

    for (int i = 0; i < size; ++i) {
        if (strcmp(&permen[i * 10], "kuning") != 0) {
            strcpy(&tempArray[tempIndex * 10], &permen[i * 10]);
            ++tempIndex;
        }
    }

    size = tempIndex;

    for (int i = 0; i < size; ++i) {
        strcpy(&permen[i * 10], &tempArray[i * 10]);
    }
}

void displayArray(const char* candyArray, int size) {
    for (int i = 0; i < size; ++i) {
        cout << &candyArray[i * 10] << " ";
    }

    cout << endl;
}

int main() {
  system("cls");
  char permen[max_permen][10] = {"biru", "kuning", "merah", "kuning", "hijau"};
  int size = 5;

  cout << "Permen sebelum disaring: ";
  displayArray(*permen, size);

  pilih_kuning(*permen, size);

  cout << "Permen setelah disaring: ";
  displayArray(*permen, size);

  return 0;
}