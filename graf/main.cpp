#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, m;
    cout << "Введите количество вершин и рёбер: ";
    cin >> n >> m;

    vector<pair<int, int>> edges(m);
    cout << "Введите рёбра:\n";
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }

    set<int> used;
    vector<pair<int, int>> matching;

    for (auto [u, v] : edges) {
        if (used.count(u) == 0 && used.count(v) == 0) {
            matching.emplace_back(u, v);
            used.insert(u);
            used.insert(v);
        }
    }

    cout << "Максимальное паросочетание:\n";
    for (auto [u, v] : matching) {
        cout << u << " - " << v << "\n";
    }

    return 0;
}
