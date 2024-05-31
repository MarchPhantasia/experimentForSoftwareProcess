#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 9;
// 全局数组自动初始化为0
ll a[N], prefix[N], diff[N];

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, p, q;
  cin >> n >> p >> q;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) diff[i] = a[i] - a[i - 1];
  while (p--) {
    int l, r;
    ll x;
    cin >> l >> r >> x;
    diff[l] += x, diff[r + 1] -= x;
  }
  // 更新a
  for (int i = 1; i <= n; ++i) a[i] = a[i - 1] + diff[i];
  // prefix
  for (int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + a[i];
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << prefix[r] - prefix[l - 1] << '\n';
  }
  return 0;
}