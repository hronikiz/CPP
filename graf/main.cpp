#include <iostream>
#include <vector>

class Graph {
private:
    int V; 
    std::vector<std::vector<int>> adj; 

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    bool dfs(int u, std::vector<bool>& visited, std::vector<int>& matching) {
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                if (matching[v] == -1 || dfs(matching[v], visited, matching)) {
                    matching[v] = u;
                    return true;
                }
            }
        }
        return false;
    }

    // Функция для поиска максимального паросочетания
    int maxMatching() {
        std::vector<int> matching(V, -1); // matching[i] = j означает, что вершина i соединена с вершиной j
        int result = 0;

        for (int u = 0; u < V; u++) {
            std::vector<bool> visited(V, false);
            if (dfs(u, visited, matching)) {
                result++;
            }
        }

        return result / 2; // Каждое ребро учтено дважды
    }
};

int main() {
    int V, E;
    std::cout << "Введите количество вершин: ";
    std::cin >> V;
    std::cout << "Введите количество рёбер: ";
    std::cin >> E;

    Graph g(V);

    std::cout << "Введите " << E << " пар вершин (нумерация с 0): " << std::endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        std::cin >> u >> v;
        g.addEdge(u, v);
    }

    std::cout << "Максимальное количество паросочетаний: " << g.maxMatching() << std::endl;

    return 0;
}
