// Nama : Benony Gabriel
// NIM  : 105222002
// PRIORITY QEUEU | HEAP
#include <iostream>
#include <string>
using namespace std;

struct Item {
    string name;
    int priority;
    string code;

    // Default constructor
    Item() : name(""), priority(0), code("") {}

    // Parameterized constructor
    Item(string n, int p, string c) : name(n), priority(p), code(c) {}
};

const int MAX_SIZE = 100;

void swap(Item& a, Item& b) {
    Item temp = a;
    a = b;
    b = temp;
}

void heapifyUp(Item heap[], int size, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index].priority > heap[parent].priority) {
            cout << "\nswap" << std::endl;
            cout << "index: " << heap[index].name << endl;
            cout << "parent: " << heap[parent].name << endl << endl;
            swap(heap[index], heap[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

void heapifyDown(Item heap[], int size, int index) {
    while (2 * index + 1 < size) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < size && heap[leftChild].priority > heap[largest].priority) {
            largest = leftChild;
        }

        if (rightChild < size && heap[rightChild].priority > heap[largest].priority) {
            largest = rightChild;
        }

        if (largest != index) {
            cout << "Swap" << endl;
            cout << "index: " << heap[index].name << endl;
            cout << "parent: " << heap[largest].name << endl << endl;
            swap(heap[index], heap[largest]);
            index = largest;
        } else {
            break;
        }
    }
}

void enqueue(Item heap[], int& size, Item value) {
    if (size < MAX_SIZE) {
        heap[size++] = value;
        heapifyUp(heap, size, size - 1);
    } else {
        std::cerr << "Priority queue is full.\n";
    }
}

void dequeue(Item heap[], int& size) {
    if (size > 0) {
        heap[0] = heap[--size];
        heapifyDown(heap, size, 0);
    } else {
        std::cerr << "Priority queue is empty.\n";
    }
}

bool isEmpty(int size) {
    return size == 0;
}

int main() {
  system("cls");
    Item priorityQueue[MAX_SIZE];
    int size = 0;

    // Enqueue items with their priorities
    enqueue(priorityQueue, size, Item("CPU", 4, "C321"));
    enqueue(priorityQueue, size, Item("Keyboard", 3, "K123"));
    enqueue(priorityQueue, size, Item("Mouse", 2, "M789"));
    enqueue(priorityQueue, size, Item("Monitor", 1, "M456"));

    cout << "Heapify down" << endl;
    while (!isEmpty(size)) {
        std::cout << "Name: " << priorityQueue[0].name << ", Priority: " << priorityQueue[0].priority
                  << ", Code: " << priorityQueue[0].code << endl;
        dequeue(priorityQueue, size);
    }

    return 0;
}