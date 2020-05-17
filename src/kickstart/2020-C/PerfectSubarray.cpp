// This is SAWA code.

#include <cmath>
#include <iostream>

using namespace std;

int arr[100100] = {0};
int main() {
  ios::sync_with_stdio(0);

  int t, temp;
  temp = 0;
  cin >> t;

  while (temp < t) {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      cin >> arr[i];
      arr[i] = arr[i] + arr[i - 1];
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= n - i; j++) {
        double sum = (double)arr[j + i] - arr[j];
        double sq = sqrt(sum);
        double p = pow(floor(sq), 2);
        // cout << "Out : " << sq << ' ' << p << ' ' << sum << '\n';
        if (p == sum) {
          ans++;
        }
      }
    }
    cout << "Case #" << temp + 1 << ": " << ans << '\n';
    temp++;
  }
  return 0;
}