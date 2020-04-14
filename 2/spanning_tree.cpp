#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <optional>
using namespace std;

struct Edge
{
    int a = 0;
    int b = 0;
    int w = 0; // weight
};

using Graf = vector<Edge>;
using Matrix = vector<vector<int>>;
int INF = INT32_MAX;

class Dsu
{
public:
    explicit Dsu(size_t n) noexcept // in constructor create n disjoint union
    {
        m_pool.resize(n);
        for (size_t i = 0; i < n; ++i)
        {
            m_pool[i].first = i;
            m_pool[i].second = 1;
        }
    }

    int find_leader(int i) noexcept // define union by leader
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

    void union_set(int a, int b) noexcept // union small class to big class
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

void kruskal(Graf g) noexcept // need copy graf, cos need sort it
{
    sort(g.begin(), g.end(), [](const auto &a, const auto &b) { // small to big sorting
        return a.w < b.w;
    });

    Dsu dsu(g.size()); // in begin all verties in own class
    Graf st;

    for (const auto &i : g)
    {
        if (dsu.find_leader(i.a) != dsu.find_leader(i.b)) // check equals class of a and b
        {
            st.push_back(i);
            dsu.union_set(i.a, i.b);
        }
    }

    for (const auto i : st) // deduce spanning tree
    {
        cout << i.a + 1 << " " << i.b + 1 << " " << i.w << endl;
    }
}

void prima(const Matrix &m)
{
    size_t n = m.size();
    vector<bool> used(n, false);          // control used verties in spanning tree
    vector<int> min_edge(n, INF);         // min weight from i
    vector<optional<int>> select_edge(n); // end of small edge
    min_edge[0] = 0;

    for (size_t i = 0; i < n; ++i)
    {
        optional<int> v;
        for (size_t j = 0; j < n; ++j)
        {
            if (!used[j] && (!v || min_edge[j] < min_edge[*v])) // find min v
            {
                v = j;
            }
        }

        used[*v] = true;
        if (select_edge[*v])
        {
            cout << *v + 1 << " " << *select_edge[*v] + 1 << " " << m[*v][*select_edge[*v]] << endl;
        }

        for (size_t j = 0; j < n; ++j) // update min edge
        {
            if (m[*v][j] < min_edge[j])
            {
                min_edge[j] = m[*v][j];
                select_edge[j] = *v;
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    Graf g(m);

    for (size_t i = 0; i < m; ++i)
    {
        cin >> g[i].a >> g[i].b >> g[i].w;
        --g[i].a;
        --g[i].b;
    }

    cout << "spanning tree by kruskal" << endl;
    kruskal(g); // m log n

    Matrix matrix(n);
    for (auto &i : matrix)
    {
        i.resize(n, INF);
    }

    for (const auto &i : g)
    {
        matrix[i.a][i.b] = i.w;
        matrix[i.b][i.a] = i.w;
    }

    cout << "spanning tree by prima" << endl;
    prima(matrix); // n^2

    return 0;
}