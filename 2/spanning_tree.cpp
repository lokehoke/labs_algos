#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

struct Edge
{
    int a = 0;
    int b = 0;
    int w = 0;
};

using Graf = vector<Edge>;

class Dsu
{
public:
    explicit Dsu(size_t n) noexcept
    {
        m_pool.resize(n);
        for (size_t i = 0; i < n; ++i)
        {
            m_pool[i].first = i;
            m_pool[i].second = 1;
        }
    }

    int find_leader(int i) noexcept
    {
        if (m_pool[i].first == i)
        {
            return i;
        }
        else
        {
            return m_pool[i].first = find_leader(m_pool[i].first); // shrink of path
        }
    }

    void union_set(int a, int b) noexcept
    {
        a = find_leader(a);
        b = find_leader(b);

        if (a != b)
        {
            if (m_pool[a].second < m_pool[b].second)
            {
                swap(a, b);
            }

            m_pool[b].first = a;
            m_pool[a].second += m_pool[b].second;
        }
    }

private:
    vector<pair<int, int>> m_pool;
};

void kruskal(Graf g) noexcept
{
    sort(g.begin(), g.end(), [](const auto &a, const auto &b) {
        return a.w < b.w;
    });

    Dsu dsu(g.size());
    Graf st;

    for (const auto &i : g)
    {
        if (dsu.find_leader(i.a) != dsu.find_leader(i.b))
        {
            st.push_back(i);
            dsu.union_set(i.a, i.b);
        }
    }

    for (const auto i : st)
    {
        cout << i.a + 1 << " " << i.b + 1 << " " << i.w << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    Graf g(n);

    for (size_t i = 0; i < n; ++i)
    {
        cin >> g[i].a >> g[i].b >> g[i].w;
        --g[i].a;
        --g[i].b;
    }

    kruskal(g);

    return 0;
}