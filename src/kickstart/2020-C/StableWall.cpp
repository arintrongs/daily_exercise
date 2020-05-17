#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>

using namespace std;

int parent[30];
bool visited[30];

int find(int p) {
  if (parent[p] == -1) {
    return p;
  }

  return parent[p] = find(parent[p]);
}

void findTopo(char p, stack<char> &ans, map<char, set<char> > &deps) {
  visited[p - 'A'] = true;

  for (auto elem : deps[p]) {
    if (!visited[elem - 'A']) {
      findTopo(elem, ans, deps);
    }
  }
  ans.push(p);
}

bool findLoop(char p, bool fvisited[], bool recTrack[],
              map<char, set<char> > &deps) {
  if (!fvisited[p - 'A']) {
    fvisited[p - 'A'] = true;
    recTrack[p - 'A'] = true;

    for (auto elem : deps[p]) {
      // cout << "KEY " << p << " : " << elem << '\n';
      if (!fvisited[elem - 'A'] and findLoop(elem, fvisited, recTrack, deps)) {
        return true;
      } else if (recTrack[elem - 'A']) {
        return true;
      }
    }
  }
  recTrack[p - 'A'] = false;
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  int t, temp;
  cin >> t;
  temp = 0;
  while (temp < t) {
    int r, c;
    map<char, set<char> > deps;

    vector<string> wall;
    stack<char> ans;
    stack<char> s;
    bool fvisited[30];
    bool recTrack[30];

    for (int i = 0; i < 30; i++) {
      parent[i] = -1;
      visited[i] = false;
      fvisited[i] = false;
      recTrack[i] = false;
    }

    cin >> r >> c;

    for (int i = 0; i < r; i++) {
      string temp;
      cin >> temp;

      wall.push_back(temp);
    }

    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (!deps.count(wall[i][j])) {
          deps[wall[i][j]] = set<char>();
        }

        if (i + 1 < r and wall[i + 1][j] != wall[i][j]) {
          deps[wall[i + 1][j]].insert(wall[i][j]);
        }
      }
    }

    bool loop = false;

    for (const auto &myPair : deps) {
      char key = myPair.first;
      set<char> value = myPair.second;

      loop = findLoop(key, fvisited, recTrack, deps);

      // for (auto elem : value) {
      //   cout << elem << ' ';
      // auto pA = find(key - 'A');
      // auto pB = find(elem - 'A');

      // if (pA != pB) {
      //   parent[key - 'A'] = pB;
      // } else {
      //   loop = true;
      // }
      // }
      // cout << '\n';
      if (loop) {
        break;
      }
    }
    // cout << "LOOP : " << loop << '\n';
    if (!loop) {
      for (const auto &myPair : deps) {
        char key = myPair.first;
        set<char> value = myPair.second;

        // cout << "VISITED : " << key << ' ' << visited[key - 'A'] << '\n';
        if (!visited[key - 'A']) {
          visited[key - 'A'] = true;
          findTopo(key, ans, deps);
        }
      }
    }
    cout << "Case #" << temp + 1 << ": ";
    if (loop) {
      cout << "-1";
    } else {
      while (not ans.empty()) {
        cout << ans.top();
        ans.pop();
      }
    }
    cout << '\n';

    temp++;
  }
  return 0;
}