#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;

int f(int x)
{
    int res = 0;
    while (x)
    {
        //相当于 &
        //...000000000000001，也就是只看最后一位是不是1，其他位都变成了0，如果最后一位不是1，那么最后一位就不是1
        if (x & 000000001)
            ++res;
        x >>= 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _;
    cin >> _;
    while (_--)
    {
        int x;
        cin >> x;
        cout << f(x) << ' ';
    }
    return 0;
}