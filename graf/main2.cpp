#include <iostream>
#include <vector>

using namespace std;

void dfs(int v, vector<vector<int>>& graph, vector<bool>& visited) {
    cout << "Посетили вершину: " << v << endl;
    visited[v] = true;

    for (int u : graph[v]) {
        if (!visited[u]) {
            dfs(u, graph, visited); 
        }
    }
}

int main() {
    int n, m;
    cout << "Введите количество вершин и рёбер: ";
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    cout << "Введите рёбра:\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); 
    }

    vector<bool> visited(n + 1, false);
    cout << "Обход в глубину с вершины 1:\n";
    dfs(1, graph, visited);

    return 0;
}
