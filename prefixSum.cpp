#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 9;
// 全局数组自动初始化为0
ll a[N], prefix[N];

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int m;
  cin >> m;
  while (m--) {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) prefix[i] = prefix[i - 1] + a[i];
    while (q--) {
      int l, r;
      cin >> l >> r;
      cout << prefix[r] - prefix[l - 1] << '\n';
    }
  }
  return 0;
}
//