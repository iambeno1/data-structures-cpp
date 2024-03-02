// PART 1 BELAJAR SINGLE LINKED LIST

#include <iostream>
using namespace std;

// Deklarasi single linked list
struct node{
  int data;
  node *next;
};

int main(){
  system("cls");
  // inisialisasi single linked list
  node *node1, *node2, *node3, *node4, *node5;

  node1 = new node();
  node2 = new node();
  node3 = new node();
  node4 = new node();
  node5 = new node();

  // Pengisian node
  node1->data = 10;
  node1->next = node2;

  node2->data = 20;
  node2->next = node3;

  node3->data = 30;
  node3->next = node4;

  node4->data = 40;
  node4->next = node5;

  node5->data = 50;
  node5->next = NULL;

  // Print node
  node *cur;
  cur = node1;
  int i = 1;

  while (cur != NULL){
    cout << "Node" << i << " = " << cur->data << endl;
    i++;
    cur = cur->next;
  }
  
  return 0;
}