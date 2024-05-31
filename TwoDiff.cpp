#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 9;

int a[N][N], prefix[N][N], diff[N][N];

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  // 输入数组
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) cin >> a[i][j];
  // choice1:修改全为0的差分数组 获得真正的差分数组
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      diff[i][j] += a[i][j];
      diff[i + 1][j] -= a[i][j];
      diff[i][j + 1] -= a[i][j];
      diff[i + 1][j + 1] += a[i][j];
    }
  // choice2:通过反算直接求得差分数组的值
  // for (int i = 1; i <= n; ++i) {
  // for (int j = 1; j <= m; ++j) {
  // diff[i][j] = a[i][j] - a[i - 1][j] - a[i][j - 1] + a[i - 1][j - 1];
  // }
  // }

  // 修改差分数组
  while (q--) {
    int x1, y1, x2, y2, c;
    cin >> x1 >> y1 >> x2 >> y2 >> c;
    diff[x1][y1] += c;
    diff[x1][y2 + 1] -= c;
    diff[x2 + 1][y1] -= c;
    diff[x2 + 1][y2 + 1] += c;
  }

  // 计算原数组
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + diff[i][j];

  // 打印数组
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; j++) cout << a[i][j] << ' ';
    cout << '\n';
  }
  return 0;
}