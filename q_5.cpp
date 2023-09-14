#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
//TC O(N) and SC O(k+n)
using namespace std;
void reverse_k(queue<int> &q, int k) {

  int size = q.size();
  vector<int> v;
  stack<int> s1;
  while (k--) {
    s1.push(q.front());
    q.pop();
  }
  while (q.empty() != true) {
    v.push_back(q.front());
    q.pop();
  }
  int c = 0;
  while (q.size() < size) {
    if (s1.empty() != true) {
      q.push(s1.top());
      s1.pop();
      continue;
    } else {
      q.push(v[c]);
      c++;
    }
  }
}
int main() {
  queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);
  int k = 3;
  reverse_k(q, k);
  while (q.empty() != true) {
    cout << q.front() << " ";
    q.pop();
  }
  cout << endl;
}