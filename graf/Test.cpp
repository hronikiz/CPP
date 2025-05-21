#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const int INF = 1e9;

int main() {
    int n;
    cin >> n;

    // Матрица смежности с индексами от 1
    vector<vector<int>> w(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> w[i][j];

    vector<bool> used(n + 1, false);
    vector<int> minEdge(n + 1, INF);
    vector<int> parent(n + 1, -1);  // parent[i] — откуда пришли в вершину i
    minEdge[1] = 0; // Начинаем с вершины 1

    int total = 0;

    for (int i = 1; i <= n; ++i) {
        int v = -1;
        for (int j = 1; j <= n; ++j)
            if (!used[j] && (v == -1 || minEdge[j] < minEdge[v]))
                v = j;

        used[v] = true;
        total += minEdge[v];

        for (int u = 1; u <= n; ++u) {
            if (!used[u] && w[v][u] && w[v][u] < minEdge[u]) {
                minEdge[u] = w[v][u];
                parent[u] = v;
            }
        }
    }

    cout << "Вес остовного дерева: " << total << endl;
    cout << "Минимальное остовное дерево (рёбра):" << endl;
    for (int i = 2; i <= n; ++i) {
        if (parent[i] != -1)
            cout << parent[i] << " - " << i << " (вес: " << w[i][parent[i]] << ")" << endl;
    }

    return 0;
}
