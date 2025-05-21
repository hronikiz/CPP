#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const int INF = 1e9;

int main() {
    int n;
    cout << "Введите количество вершин: ";
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(n));
    cout << "Введите матрицу смежности (0 если нет ребра, иначе вес):\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> cost[i][j];

    vector<int> minEdge(n, INF);
    vector<bool> used(n, false);
    minEdge[0] = 0;
    int totalWeight = 0;

    for (int i = 0; i < n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j)
            if (!used[j] && (v == -1 || minEdge[j] < minEdge[v]))
                v = j;

        used[v] = true;
        totalWeight += minEdge[v];

        for (int to = 0; to < n; ++to)
            if (cost[v][to] != 0 && cost[v][to] < minEdge[to])
                minEdge[to] = cost[v][to];
    }

    cout << "Вес минимального остовного дерева: " << totalWeight << endl;

    return 0;
}
