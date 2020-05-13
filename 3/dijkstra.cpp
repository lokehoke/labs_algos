#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int INF = 1e9;

int main()
{
    int n = 8;
    int s = 0;
    vector<vector<pair<int, int>>> g(n);
    g[0].push_back({1, 18});
    g[0].push_back({3, 4});
    g[0].push_back({6, 9});
    g[0].push_back({7, 22});

    g[1].push_back({0, 18});
    g[1].push_back({2, 1});
    g[1].push_back({4, 3});
    g[1].push_back({7, 1});

    g[2].push_back({1, 1});
    g[2].push_back({4, 13});

    g[3].push_back({0, 4});
    g[3].push_back({5, 5});
    g[3].push_back({6, 7});

    g[4].push_back({1, 3});
    g[4].push_back({2, 13});
    g[4].push_back({6, 2});
    g[4].push_back({7, 9});

    g[5].push_back({3, 5});
    g[5].push_back({6, 5});

    g[6].push_back({5, 5});
    g[6].push_back({3, 7});
    g[6].push_back({0, 9});
    g[6].push_back({4, 2});
    g[6].push_back({7, 10});

    g[7].push_back({6, 10});
    g[7].push_back({0, 22});
    g[7].push_back({1, 1});
    g[7].push_back({4, 9});

    vector<int> d(n, INF);
    vector<int> p(n);
    vector<char> u(n);
    d[s] = 0;
    for (int i = 0; i < n; ++i)
    {
        int v = -1;
        for (int j = 0; j < n; ++j)
        {
            if (!u[j] && (v == -1 || d[j] < d[v]))
            {
                v = j;
            }
        }

        if (d[v] == INF)
        {
            break;
        }
        u[v] = true;

        for (size_t j = 0; j < g[v].size(); ++j)
        {
            int to = g[v][j].first;
            int len = g[v][j].second;
            if (d[v] + len < d[to])
            {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }

    vector<int> path;
    for (int v = 7; v != s; v = p[v])
    {
        path.push_back(v);
    }

    path.push_back(s);
    reverse(path.begin(), path.end());

    for (auto i : path)
    {
        cout << i << " ";
    }

    cout << endl
         << d[7] << endl;
}