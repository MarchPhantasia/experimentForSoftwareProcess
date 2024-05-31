#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// signed = signed int
// main的返回值必须是int类型，如果define int long long
// main的返回值int会被修改 所以就改成了signed main() {}

// 写题时1.确定N的大小，不要使用define 拒绝defin N (1e5 + 114514)
const int N = 1e5 + 9;

// 写题时2.开数组，全局数组自动初始化为0
int a[N]，prefix[N];

int main() {
  // 关闭同步流
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  // main函数内部使用栈空间，数组不会初始化(栈空间一般2M - 4M)
  int b[N];
  int n;
  cin >> n;
  // 写题时3.输入 一般会单独写一个函数来输入
  //  拒绝写成下面的形式
  //  for(int i = 1; i <= n; ++ i) {
  //  cin >> a[i];
  //  prefix[i] = prefix[i-1] + a[i];
  // }
  // 建议写成下面的形式
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) prefix[i] = prefix[i - 1] + a[i];

  // 数组初始化打印测试
  for (int i = 1; i <= 10; ++i) {
    cout << a[i] << ' ' << b[i] << '\n';
  }

  // 1.scanf 和 printf
  // 格式化输入、 输出
  // input 15:20 scanf("%d:%d, &a, &b")
  // output 1.00002 printf("%0.51f", x)
  // 不能取消同步流
  // 不取消同步流 输入a一个b 就会出现一个答案，
  // 取消同步流之后
  // 输入a，b答案不会立刻出现，不停的输入a，b。等到输入endfile标识
  // 所有答案会一并出现

  // 2.cin cout
  // 简洁，在取消同步流的情况下，一般会比scanf更快
  // 不取消同步流cout会相当慢
  // 取消同步流一定需要写完整
  // 注意不要使用cout << endl; 改用 cout << '\n'
  // endl: '\n',强制刷新缓冲区(相对比较慢的操作)
  cout << N * 2 << " " << 2 * N;
  return 0;
}