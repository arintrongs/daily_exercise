#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    double n, k;
    cin >> n >> k;
    int ans = ceil(k / (n - 1) * n);
    cout << ans - 1 << '\n';
  }
  return 0;
}