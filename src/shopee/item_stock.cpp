#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> v[100100];

struct cdata
{

    int type;
    long long qty;
    long long stock;
    int parent;
};

cdata nodes[100100];
void update_down(int p)
{
    cdata node = nodes[p];
    if (node.type == 1)
    {
        nodes[p].stock = nodes[node.parent].stock / node.qty;
    }
    for (int i = 0; i < v[p].size(); i++)
    {
        update_down(v[p][i]);
    }
}

void update_up(int p, long long sum)
{
    if (nodes[p].type == 2)
    {
        nodes[p].stock -= sum;

        update_down(p);
    }
    else
    {
        update_up(nodes[p].parent, sum * nodes[p].qty);
    }
}
int main()
{
    ios::sync_with_stdio(0);

    int n, m;
    int type;
    int p, qty, s;
    cin >> n >> m;

    nodes[1].type = 2;
    nodes[1].qty = 1;
    nodes[1].stock = m;
    nodes[1].parent = 0;
    for (int i = 2; i <= n; i++)
    {
        cin >> type;
        if (type == 1)
        {
            cin >> p >> qty;
            v[p].push_back(i);

            nodes[i].type = type;
            nodes[i].qty = qty;
            nodes[i].stock = nodes[p].stock / qty;
            nodes[i].parent = p;
        }
        else
        {
            cin >> p >> qty >> s;
            v[p].push_back(i);
            nodes[i].type = type;
            nodes[i].qty = qty;
            nodes[i].stock = s;
            nodes[i].parent = p;

            update_up(p, qty * s);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << nodes[i].stock << '\n';
    }
    return 0;
}