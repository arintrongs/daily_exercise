#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

struct cdata
{
    double v;
    double sum;
    int idx;
};

bool cmp(cdata a, cdata b)
{
    if (a.v == b.v)
    {
        return a.sum > b.sum;
    }
    return a.v < b.v;
}

int main()
{
    ios::sync_with_stdio(0);
    int t, temp;
    cin >> t;
    temp = t;
    vector<long long> ans;
    while (t--)
    {
        int s, n;
        long long x;
        int cnt;
        long long cost = 0;
        bool bought[1100] = {0};
        int arr[1100] = {0};
        priority_queue<pair<long long, int>> pq;
        cin >> s >> n;
        cnt = n;
        for (int i = 1; i <= s; i++)
        {
            cin >> x;
            pq.push(make_pair(-x, i));
            arr[i] = x;
        }

        while (cnt > 0 and !pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            int idx = top.second;
            if (!bought[idx])
            {
                bought[top.second] = true;
                // cout << top.first << ' ' << idx << '\n';
                cnt--;
                cost += -top.first;
                if (arr[idx - 1] > arr[idx + 1] and !bought[idx - 1])
                {
                    cnt--;
                    bought[idx - 1] = true;
                }
                else if (arr[idx + 1] >= arr[idx - 1] and !bought[idx + 1])
                {
                    cnt--;
                    bought[idx + 1] = true;
                }
                else if (arr[idx - 1] > arr[idx + 1] and bought[idx - 1] and !bought[idx + 1])
                {
                    cnt--;
                    bought[idx + 1] = true;
                }
                else if (arr[idx + 1] >= arr[idx - 1] and bought[idx + 1] and !bought[idx - 1])
                {
                    cnt--;
                    bought[idx - 1] = true;
                }
            }
        }
        ans.push_back(cost);
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "Case " << i + 1 << ": " << ans[i] << '\n';
    }
    return 0;
}