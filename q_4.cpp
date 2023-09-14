#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int middle(stack<int> &s1) {
  int size = s1.size();
  int a = size / 2;
  vector<int> del;
  while (a > 0) {
    del.push_back(s1.top());
    s1.pop();
    a--;
  }
  int mid = s1.top();
  s1.pop();
  for (auto i : del) {
    cout << i << " ";
    s1.push(i);
  }
  cout << endl;
  return mid;
}
int main() {
  stack<int> s1;
  s1.push(1);
  s1.push(2);
  s1.push(3);
  s1.push(4);
  s1.push(5);
  cout << middle(s1) << " " << s1.size() << endl;
}