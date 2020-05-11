#include <iostream>
#include <cstdio>

using namespace std;

unsigned long long fac[200005], inv_fac[200005];
unsigned long long mod = 998244353;
unsigned long long ans = 0;
unsigned long long mypow(unsigned long long n, unsigned long long m)
{
  unsigned long long p;

  if (m == 0)
  {
    return 1;
  }
  p = mypow(n, m / 2) % mod;
  if (m % 2 == 0)
  {
    return (p * p) % mod;
  }
  else
  {
    return (n * (p * p % mod)) % mod;
  }
}
int main()
{
  ios::sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m;

  unsigned long long ans = 0;

  fac[1] = 1;
  fac[0] = 1;

  // unsigned long long inv_div;
  // inv_div = mypow(2, mod - 2);

  for (int i = 0; i < 200005; i++)
  {
    // cout << i << '\n';
    if (i > 0)
    {
      fac[i] = (i * fac[i - 1]) % mod;
    }
    inv_fac[i] = mypow(fac[i], mod - 2);
  }
  long long select_members, perm_members, put_peek;
  for (int i = n - 1; i <= m; i++)
  {
    select_members = (((fac[i - 1] * inv_fac[i - 1 - (n - 2)]) % mod) * inv_fac[n - 2]) % mod;
    put_peek = (((select_members * mypow(2, n - 3)) % mod) * (n - 2)) % mod;
    ans = (ans + put_peek) % mod;
  }
  cout << ans % mod << '\n';

  return 0;
}