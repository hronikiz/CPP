#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i)
        cin >> edges[i].first >> edges[i].second;

    set<int> used;
    vector<pair<int, int>> matching;
    for (auto [u, v] : edges) {
        if (!used.count(u) && !used.count(v)) {
            matching.push_back({u, v});
            used.insert(u);
            used.insert(v);
        }
    }

    cout << "Максимальное паросочетание:\n";
    for (auto [u, v] : matching)
        cout << u << " - " << v << endl;

    return 0;
}
