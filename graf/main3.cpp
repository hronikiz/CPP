#include <iostream>
#include <vector>
#include <limits>
using namespace std;
const int INF = 1e9;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> w(n, vector<int>(n));
    for (auto& row : w)
        for (auto& val : row)
            cin >> val;

    vector<bool> used(n, false);
    vector<int> minEdge(n, INF);
    vector<int> parent(n, -1);

    minEdge[0] = 0;
    int total = 0;

    for (int i = 0; i < n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j)
            if (!used[j] && (v == -1 || minEdge[j] < minEdge[v]))
                v = j;

        used[v] = true;
        total += minEdge[v];

        for (int u = 0; u < n; ++u)
            if (w[v][u] && !used[u] && w[v][u] < minEdge[u]) {
                minEdge[u] = w[v][u];
                parent[u] = v;
            }
    }

    cout << "Вес остовного дерева: " << total << endl;
    cout << "Ребра в минимальном остовном дереве:\n";
    for (int i = 1; i < n; ++i)
        if (parent[i] != -1)
            cout << parent[i] + 1 << " - " << i + 1 << " (вес " << w[i][parent[i]] << ")\n";

    return 0;
}
