#include <algorithm>
#include <iostream>
using namespace std;
/*
Q)-
What is a sparse matrix. Find out the ways to store sparse matrix. Write a
program to implement the following operations on a Sparse Matrix, assuming the
matrix is represented using a triplet. (a) Transpose of a matrix. (b) Addition
of two matrices. (c) Multiplication of two matrices. ex-:                  0 0 3
0 4 0 0 5 7 0 0 0 0 0 0 0 2 6 0 0 (GFG example)
*/





// Sparse matrix is special matrix containing mostly elements as zero
// advantage will be that space storage of only the non zero elements and the
// time of traversal also reduces if a suitable data structure can be made
// travering only the non-zero values Repersentation can be done in the form of
// array or with the help of linked list

class Node {
public:
  int val;
  int col, row;
  Node *next;
  Node(int f) {
    this->val = f;
    this->next = NULL;
  }
};
bool search(Node *n1, Node *n2) {
  Node *temp = n2;
  while (temp != NULL) {
    if (temp->row == n1->row && temp->col == n1->col) {
      return true;
    }
    temp = temp->next;
  }
  return false;
}
class sm {
private:
  Node *head = NULL;
  Node *tail = NULL;

public:
  void insert(int r, int c, int v) {
    if (head == NULL) {
      Node *newnode = new Node(v);
      newnode->row = r;
      newnode->col = c;
      head = newnode;
      tail = head;
      return;
    } else {
      Node *newnode = new Node(v);
      newnode->row = r;
      newnode->col = c;
      head->next = newnode;
      head = newnode;
      return;
    }
    return;
  }
  void print() {
    Node *temp = tail;
    while (temp != NULL) {
      cout << temp->row << " ";
      temp = temp->next;
    }
    cout << endl;
    temp = tail;
    while (temp != NULL) {
      cout << temp->col << " ";
      temp = temp->next;
    }
    cout << endl;
    temp = tail;
    while (temp != NULL) {
      cout << temp->val << " ";
      temp = temp->next;
    }
    cout << endl;
  }
  void transpose() {
    Node *temp = tail;
    while (temp != NULL) {
      int b = temp->row;
      temp->row = temp->col;
      temp->col = b;
    }
  }
  sm add(sm s) {
    sm addn;
    Node *temp1 = tail;
    Node *temp2 = s.tail;
    while (temp1 != NULL) {
      if (search(temp1, temp2) == true) {
        addn.insert(temp1->row, temp1->col, temp1->val + temp2->val);
      } else {
        addn.insert(temp1->row, temp1->col, temp1->val);
      }
      temp1 = temp1->next;
    }
    temp1 = tail;
    while (temp2 != NULL) {
      if (search(temp2, temp1) == false) {
        addn.insert(temp2->row, temp2->col, temp2->val);
      }
      temp2 = temp2->next;
    }
    return addn;
  }
};
int main() {
  sm a;
  sm b;
  a.insert(1, 2, 10);
  a.insert(1, 4, 12);
  a.insert(3, 3, 5);
  a.insert(4, 1, 15);
  a.insert(4, 2, 12);
  b.insert(1, 3, 8);
  b.insert(2, 4, 23);
  b.insert(3, 3, 9);
  b.insert(4, 1, 20);
  b.insert(4, 2, 25);
  // a.print();
  // b.print();
  sm c = a.add(b);
  c.print();
}