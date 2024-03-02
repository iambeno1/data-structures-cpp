#include <iostream>
#include <cstdlib>
using namespace std;

const int T_S = 20;

struct HashTable {
    int k;
    int v;
};

struct DelNode : HashTable {
    static DelNode en;

    DelNode() : HashTable{-1, -1} {}
};

DelNode DelNode::en;

struct HashMapTable {
    HashTable **ht;

    int HashFunc(int k, int constant, int array_size) {
        return k % (constant * array_size);
    }

    void Insert(int k, int v, int constant, int array_size) {
        int hash_val = HashFunc(k, constant, array_size);
        int init = -1;
        int delindex = -1;
        while (ht[hash_val] != nullptr && ht[hash_val]->k != k) {
            if (init == -1)
                init = hash_val;
            if (ht[hash_val] == &DelNode::en)
                delindex = hash_val;
            hash_val = HashFunc(hash_val + 1, constant, array_size);
        }
        if (ht[hash_val] == nullptr || hash_val == init) {
            if (delindex != -1)
                ht[delindex] = new HashTable{k, v};
            else
                ht[hash_val] = new HashTable{k, v};
        }
        if (init != hash_val && ht[hash_val] != &DelNode::en && ht[hash_val]->k == k) {
            ht[hash_val]->v = v;
        }
    }

    int SearchKey(int k, int constant, int array_size) {
        int hash_val = HashFunc(k, constant, array_size);
        int init = -1;
        while (ht[hash_val] != nullptr && ht[hash_val]->k != k) {
            if (init == -1)
                init = hash_val;
            hash_val = HashFunc(hash_val + 1, constant, array_size);
        }
        if (ht[hash_val] == nullptr || hash_val == init || ht[hash_val] == &DelNode::en)
            return -1;
        else
            return ht[hash_val]->v;
    }

    void Remove(int k, int constant, int array_size) {
        int hash_val = HashFunc(k, constant, array_size);
        int init = -1;
        while (ht[hash_val] != nullptr && ht[hash_val]->k != k) {
            if (init == -1)
                init = hash_val;
            hash_val = HashFunc(hash_val + 1, constant, array_size);
        }
        if (ht[hash_val] != nullptr && hash_val != init && ht[hash_val] != &DelNode::en) {
            delete ht[hash_val];
            ht[hash_val] = &DelNode::en;
        }
    }

    void DisplayHashTable() {
        cout << "Hash Table Contents:\n";
        cout << "Index\tKey\tValue\n";
        for (int i = 0; i < T_S; i++) {
            if (ht[i] == nullptr)
                cout << i << "\tEmpty\tEmpty\n";
            else if (ht[i] == &DelNode::en)
                cout << i << "\tDeleted\tDeleted\n";
            else
                cout << i << "\t" << ht[i]->k << "\t" << ht[i]->v << endl;
        }
    }

    HashMapTable() {
        ht = new HashTable *[T_S];
        for (int i = 0; i < T_S; i++) {
            ht[i] = nullptr;
        }
    }

    ~HashMapTable() {
        delete[] ht;
    }
};

int main() {
    HashMapTable hash;
    int k, v;
    int c;
    while (1) {
        cout << "1. Insert element into the table" << endl;
        cout << "2. Search element from the key" << endl;
        cout << "3. Delete element at a key" << endl;
        cout << "4. Display Hash Table" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> c;
        switch (c) {
            case 1:
                cout << "Enter element to be inserted: ";
                cin >> v;
                cout << "Enter key at which element to be inserted: ";
                cin >> k;
                hash.Insert(k, v, 1, 20);
                break;
            case 2:
                cout << "Enter key of the element to be searched: ";
                cin >> k;
                if (hash.SearchKey(k, 1, 20) == -1) {
                    cout << "No element found at key " << k << endl;
                } else {
                    cout << "Element found at key " << k << ": " << hash.SearchKey(k, 1, 20) << endl;
                }
                break;
            case 3:
                cout << "Enter key of the element to be deleted: ";
                cin >> k;
                hash.Remove(k, 1, 20);
                cout << "Element at key " << k << " deleted." << endl;
                break;
            case 4:
                hash.DisplayHashTable();
                break;
            case 5:
                exit(1);
            default:
                cout << "Invalid Input! Please enter a valid option." << endl;
        }
    }

    return 0;
}
