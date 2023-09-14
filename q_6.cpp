#include <iostream>
using namespace std;
class Node {
public:
  int val;
  Node *next;
  Node(int f) { this->val = f; }
};
int len(Node *head) {
  Node *temp = head;
  int a = 0;
  while (temp != NULL) {
    a++;
    temp = temp->next;
  }
  return a;
}
void insert(Node *&head, int f) {
  Node *newnode = new Node(f);
  head->next = newnode;
  head = newnode;
}
pair<Node *, Node *> rec(Node *head) {
  int b = len(head);
  if (b % 2 == 0) {
    b = b / 2;
    Node *temp = head;
    Node *temp2 = temp;
    while (b >= 2) {
      temp = temp->next;
      b--;
    }
    head = temp->next;
    temp->next = NULL;
    return {temp2, head};
  } else {
    b = b / 2;
    Node *temp = head;
    Node *temp2 = temp;
    while (b >= 2) {
      temp = temp->next;
      b--;
    }
    temp = temp->next;
    head = temp->next;
    temp->next = NULL;
    return {temp2, head};
  }
  return {NULL, NULL};
}
void print(Node *head) {
  Node *temp = head;

  while (temp != NULL) {
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << endl;
}
int main() {

    //Code for dry run using an example//
  Node *head = new Node(1);
  Node *tail = head;
  insert(head, 2);
  insert(head, 3);
  insert(head, 4);
  insert(head, 5);
  insert(head, 6);
  insert(head, 7);
  print(tail);
  pair<Node *, Node *> p = rec(tail);
  print(p.first);
  print(p.second);
}