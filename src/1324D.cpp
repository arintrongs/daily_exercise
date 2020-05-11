#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

long long a[200005], b[200005];
long long ab[200005], ba[200005];
int main() {
  long long n;
  long long ans = 0;
  ios::sync_with_stdio(false);

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  for (int i = 0; i < n; i++) {
    ab[i] = a[i] - b[i];
    ba[i] = b[i] - a[i];
  }

  sort(ba, ba + n);

  for (int i = 0; i < n; i++) {
    int l = 0;
    int r = n - 1;
    int m;
    if (ab[i] > 0) ans -= 1;
    while (l <= r) {
      m = (l + r) / 2;
      if (ab[i] > ba[m]) {
        l = m + 1;
      } else if (ab[i] <= ba[m]) {
        r = m - 1;
      }
    }
    ans += r + 1;
    // cout << ab[i] << ' ' << ba[r] << ' ' << r << '\n';
  }
  cout << ans / 2;
  // cout << '\n';
  // for (int i = 0; i < n; i++)
  // {
  //   cout << ba[i] << ' ';
  // }

  return 0;
}