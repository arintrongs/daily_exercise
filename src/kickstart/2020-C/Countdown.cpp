#include <iostream>

using namespace std;

int in[202000];
int ans[200] = {0};
int main() {
  ios::sync_with_stdio(0);
  int t;
  int temp = 0;
  cin >> t;
  while (temp < t) {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      cin >> in[i];
    }
    int countDown = k;

    for (int i = 0; i < n; i++) {
      if (in[i] != countDown) {
        countDown = k;
      }
      if (in[i] == countDown) {
        countDown--;
        if (countDown == 0) {
          ans[temp]++;
        }
      }
    }
    temp++;
  }
  for (int i = 0; i < t; i++) {
    cout << "Case #" << i + 1 << ": " << ans[i] << '\n';
  }
  return 0;
}