#include <iostream>
using namespace std;
class Node {
public:
  int val;
  Node *next;
  Node(int f) {
    this->val = f;
    next = NULL;
  }
};
void insert_at_head(Node *&head, int v) {
  if (head == NULL) {
    Node *newnode = new Node(v);
    head = newnode;
    return;
  }
  Node *newnode = new Node(v);
  head->next = newnode;
  head = newnode;
}
int len(Node *head) {
  int a = 0;
  Node *temp = head;
  while (temp != NULL) {
    temp = temp->next;
    a++;
  }
  return a;
}
int Get_nth(Node *tail, int index) {
  int range = len(tail) - 1;
  if (index > range) {
    return -1;
  } else if (index < 0) {
    return -1;
  } else {
    int a = 0;
    Node *temp = tail;
    while (a != index) {
      temp = temp->next;
      a++;
    }
    return temp->val;
  }
}
int main() {
  Node *head = NULL;
  Node *tail;
  insert_at_head(head, 1);
  tail = head;
  insert_at_head(head, 2);
  insert_at_head(head, 3);
  insert_at_head(head, 4);
  insert_at_head(head, 5);
  int index;
  cin >> index;
  Get_nth(tail, 0);
}