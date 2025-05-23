#include <iostream>
#include <vector>
using namespace std;

const int N = 101;
vector<int> graph[N];
int color[N];

bool isSafe(int v, int c) {
    for (int u : graph[v]) {
        if (color[u] == c) return false;
    }
    return true;
}

bool graphColoring(int v, int n, int maxColors) {
    if (v > n) return true;

    for (int c = 1; c <= maxColors; c++) {
        if (isSafe(v, c)) {
            color[v] = c;
            if (graphColoring(v + 1, n, maxColors))
                return true;
            color[v] = 0;
        }
    }
    return false;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if (graphColoring(1, n, k)) {
        for (int i = 1; i <= n; i++) {
            cout << "Вершина " << i << " -> Цвет " << color[i] << "\n";
        }
    } else {
        cout << "Раскраска невозможна с " << k << " цветами.\n";
    }

    return 0;
}
