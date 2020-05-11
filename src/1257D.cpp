#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct hero
{
  int atk;
  int endurance;
  // hero(int a, int e)
  // {
  //   atk = a;
  //   endurance = e;
  // }
} heroes[200005];
int ans2[200005];
int monsters[200005];
int mx[200005];
int anss[200005];
bool cmp(hero a, hero b)
{
  if (a.atk == b.atk)
    return a.endurance < b.endurance;
  return a.atk < b.atk;
}
int main()
{
  std::ios::sync_with_stdio(false);
  int t;
  cin >> t;
  int temp;
  temp = t;
  while (t--)
  {
    int m, n;

    int atk, endr;
    int mx_mon2 = 0, mx_hero2 = 0;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
      cin >> monsters[i];
      mx_mon2 = max(monsters[i], mx_mon2);
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      cin >> atk >> endr;
      heroes[i].atk = atk;
      heroes[i].endurance = endr;
      mx_hero2 = max(mx_hero2, heroes[i].atk);
    }
    sort(heroes, heroes + n, cmp);
    // for (int i = 0; i < n; i++)
    // {
    //   cout << "heroes : " << heroes[i].atk << ' ' << heroes[i].endurance << '\n';
    // }
    int mxx = 0;
    for (int i = n - 1; i >= 0; i--)
    {
      mxx = max(mxx, heroes[i].endurance);
      mx[i] = mxx;
    }

    int start = 0, end = 0, mx_mon = 0, ans = 0, endurance;
    bool possible = true;
    if (mx_mon2 > mx_hero2)
    {
      possible = false;
    }
    if (possible)
    {
      int l, r, mid;
      while (end < m)
      {
        // cout << end << ' ' << m << '\n';
        mx_mon = max(mx_mon, monsters[end]);
        endurance = end - start + 1;
        l = 0;
        r = n - 1;

        while (l <= r)
        {
          mid = (l + r) / 2;

          if (heroes[mid].atk >= mx_mon)
          {
            r = mid - 1;
          }
          else if (heroes[mid].atk < mx_mon)
          {
            // cout << "HERE : " << l << ' ' << mid << ' ' << r << '\n';
            l = mid + 1;
          }
          else
          {
            break;
          }
        }

        if (heroes[l].atk >= mx_mon and mx[l] >= endurance)
        {
          end += 1;
          if (end == m)
          {
            ans += 1;
          }
        }
        else
        {
          start = end;
          ans += 1;
          mx_mon = monsters[start];
        }
      }
    }
    if (possible)
    {
      // cout << "POSSIBLE : " << temp << ' ' << t << ' ' << ans << '\n';
      anss[temp - t - 1] = ans;
    }
    else
    {
      // cout << "IMMMPOSSIBLE : " << temp << ' ' << t << ' ' << ans << '\n';
      anss[temp - t - 1] = -1;
    }
  }
  for (int i = 0; i < temp; i++)
  {
    cout << anss[i] << '\n';
  }
  return 0;
}