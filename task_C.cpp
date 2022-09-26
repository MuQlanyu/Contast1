#include <iostream>
#include <stack>

using std::cin;
using std::cout;

const int kMaxn = 1e6 + 101;

int Num(std::stack<long long>& st) {
  if (st.empty()) {
    return -1;
  }
  return st.top();
}

int arr[kMaxn];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::stack<long long> s;
  long long n, ans = 0, t;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  for (long long i = 0; i < n; ++i) {
    while (!s.empty() && arr[s.top()] >= arr[i]) {
      t = s.top();
      s.pop();
      ans =
          (ans >= (i - Num(s) - 1) * arr[t] ? ans : (i - Num(s) - 1) * arr[t]);
    }
    s.push(i);
  }
  while (s.size() > 1) {
    t = s.top();
    s.pop();
    ans = (ans >= (n - Num(s) - 1) * arr[t] ? ans : (n - Num(s) - 1) * arr[t]);
  }
  ans = ans >= arr[s.top()] * n ? ans : arr[s.top()] * n;
  cout << ans;
}
