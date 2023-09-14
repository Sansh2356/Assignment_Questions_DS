#include <algorithm>
using namespace std;
#include <iostream>
class Node {
public:
  Node *next = NULL;
  int val;
  Node(int f) { this->val = f; }
};
class stack {
public:
  int size = 0;
  Node *head = NULL;
  Node *slow = NULL;
  Node *tail = head;
  void push(int f) {
    size++;
    Node *newnode = new Node(f);
    if (head == NULL) {
      head = newnode;
      tail = head;
      return;
    } else {
      head->next = newnode;
      slow = head;
      head = newnode;
    }
  }
  int pop() {
    if (head == NULL || size == 0) {
      return -1;
    }
    size--;
    int a = head->val;
    head = slow;
    slow->next = NULL;
    return a;
  }
  int siz() { return size; }
  void print() {
    Node *temp = tail;
    while (temp != NULL) {
      cout << temp->val << " ";
      temp = temp->next;
    }
    cout << endl;
  }
  void top() {
    if (size == 0) {
      cout << "stack is empty" << endl;
      return;
    }
    cout << head->val << endl;
  }
};
int main() {
  stack s;
  s.push(1);
  s.push(2);
  s.pop();
  s.pop();
  s.pop();
  s.top();
  s.push(3);
  s.push(4);
  s.top();
  s.pop();
  s.top();
}