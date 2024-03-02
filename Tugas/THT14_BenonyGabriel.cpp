#include <iostream>
#include <vector>

using namespace std;

const int BUCKET_SIZE = 3;
const int TABLE_SIZE = 10;

struct HashNode {
    int key;
    int value;
};

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(vector<vector<HashNode>> &table, int key, int value) {
    int index = hashFunction(key);

    for (int i = 0; i < BUCKET_SIZE; ++i) {
        int currentIndex = (index + i) % TABLE_SIZE;

        if (table[currentIndex].empty()) {
            table[currentIndex].push_back({key, value});
            return;
        }
    }

    cout << "Hash table is full. Unable to insert: (" << key << ", " << value << ")" << endl;
}

void display(const vector<vector<HashNode>> &table) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        cout << "Bucket " << i << ": ";
        for (const HashNode &node : table[i]) {
            cout << "(" << node.key << ", " << node.value << ") ";
        }
        cout << endl;
    }
}

int searchBucket(const vector<vector<HashNode>> &table, int key) {
    int index = hashFunction(key);

    for (int i = 0; i < BUCKET_SIZE; ++i) {
        int currentIndex = (index + i) % TABLE_SIZE;

        if (table[currentIndex].empty()) {
            return -1; // Data tidak ditemukan
        }

        for (const HashNode &node : table[currentIndex]) {
            if (node.key == key) {
                return currentIndex; // Data ditemukan
            }
        }
    }

    return -1; // Data tidak ditemukan
}

int searchChaining(const vector<vector<HashNode>> &table, int key) {
    int index = hashFunction(key);

    if (table[index].empty()) {
        return -1; // Data tidak ditemukan
    }

    for (const HashNode &node : table[index]) {
        if (node.key == key) {
            return index; // Data ditemukan
        }
    }

    return -1; // Data tidak ditemukan
}

int main() {
  system("cls");
    vector<vector<HashNode>> hashTable(TABLE_SIZE, vector<HashNode>());

    int data[] = {66, 47, 87, 90, 126, 140, 145, 153, 177, 285, 393, 395, 467, 566, 620, 735};

    for (int i = 0; i < sizeof(data) / sizeof(data[0]); ++i) {
        insert(hashTable, data[i], i);
    }

    cout << "Representasi Bucket:" << endl;
    display(hashTable);

    cout << "\nRepresentasi Chaining:" << endl;
    for (int i = 0; i < sizeof(data) / sizeof(data[0]); ++i) {
        int bucketIndex = searchBucket(hashTable, data[i]);
        int chainingIndex = searchChaining(hashTable, data[i]);

        cout << "Value " << data[i] << " | Bucket: " << bucketIndex << " | Chaining: " << chainingIndex << endl;
    }

    return 0;
}
