#include <iostream>
using namespace std;

int tree[] = {10, 15, 20, 25, 30, 5};  // Tambahkan tanda koma di sini
int sizeTree = sizeof(tree) / sizeof(tree[0]);

void heapify(int tree[], int size, int max) {
    int maxTree = max;
    int left = 2 * max + 1;
    int right = 2 * max + 2;

    if (left < size && tree[left] > tree[maxTree]) {
        maxTree = left;
    }

    if (right < size && tree[right] > tree[maxTree]) {
        maxTree = right;
    }

    if (maxTree != max) {
        int temp = tree[max];
        tree[max] = tree[maxTree];
        tree[maxTree] = temp;

        heapify(tree, size, maxTree);
    }
}

void heapSort(int tree[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(tree, size, i);
    }

    for (int i = size - 1; i > 0; i--) {
        int temp = tree[0];
        tree[0] = tree[i];
        tree[i] = temp;

        heapify(tree, i, 0);
    }
}

int main() {
  system("cls");
    cout << "Original array: ";
    for (int i = 0; i < sizeTree; i++) {
        cout << tree[i] << " ";
    }

    heapSort(tree, sizeTree);

    cout << "\nSorted array (in ascending order): ";
    for (int i = 0; i < sizeTree; i++) {
        cout << tree[i] << " ";
    }

    return 0;
}