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
  // 属鼠变鸭鸭是+ 鸭鸭变属鼠是-
  for (int i = 1; i <= n; ++i)
    prefix[i] = prefix[i - 1] + (a[i] ? -1 : 1) * w[i];

  // 计算原有鸭子
  ll ess = 0;
  for (int i = 1; i <= n; ++i) ess += a[i] * w[i];

  // minPre 表示min(prefix[j]) 1<= j < i Fix就是ess要加的区间偏移量
  ll minPre = 0, Fix = 0;
  for (int i = 1; i <= n; ++i) {
    // Fix要比min多一项 先算Fix
    Fix = max(Fix, prefix[i] - minPre);
    minPre = min(minPre, prefix[i]);
  }
  cout << ess + Fix << '\n';
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int _;
  cin >> _;
  while (_--) solve();

  return 0;
}
