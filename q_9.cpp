#include <algorithm>
#include <iostream>
using namespace std;
class Node {
public:
  int val;
  Node *next;
  Node *prev;
  Node(int f) {
    this->val = f;
    this->next = NULL;
    this->prev = NULL;
  }
};
void insert_at_head(Node *&head, int v) {
  if (head == NULL) {
    Node *newnode = new Node(v);
    head = newnode;
    return;
  } else {
    Node *newnode = new Node(v);
    newnode->prev = head;
    head->next = newnode;
    head = newnode;
  }
}
void print(Node *head) {
  Node *temp = head;
  while (temp != NULL) {
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << endl;
}
int len(Node *head) {
  Node *temp = head;
  int l = 0;
  while (temp != NULL) {
    temp = temp->next;
    l++;
  }
  return l;
}
bool is_palindrome(Node *head, Node *tail) {
  Node *temp1 = head;
  Node *temp2 = tail;
  while (temp1 != temp2) {
    if (temp1->val != temp2->val) {
      return false;
    }
    temp1 = temp1->prev;
    temp2 = temp2->next;
  }
  return true;
}
int main() {
  Node *head = NULL;
  Node *tail;
  insert_at_head(head, 1);
  tail = head;
  insert_at_head(head, 2);
  insert_at_head(head, 2);
  insert_at_head(head, 1);
  print(tail);
  is_palindrome(head, tail);
  cout << is_palindrome(head, tail) << endl;
}