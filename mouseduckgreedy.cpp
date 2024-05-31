#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;

// a是种类 w是重量

ll prefix[N], a[N], w[N];

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> w[i];

  // 计算原有鸭子
  ll ess = 0;
  for (int i = 1; i <= n; ++i) ess += a[i] * w[i];

  ll fix = 0, mx = 0;
  // 贪心只是计算fix的方法有所改变
  for (int i = 1; i <= n; ++i) {
    mx = max(0ll, mx + (a[i] ? -1 : 1) * w[i]);
    fix = max(mx, fix);
  }

  cout << ess + fix << '\n';
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int _;
  cin >> _;
  while (_--) solve();

  return 0;
}
