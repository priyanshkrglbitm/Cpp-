#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    
    int vertices; // Number of vertices in the graph
    vector<vector<int>> adjMatrix;
    public:
    Graph(int V) : vertices(V) {
        adjMatrix.resize(vertices,vector<int>(vertices, 0));
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // Comment this line for a directed graph
    }

    void printGraph(){
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                std::cout << adjMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {

    Graph graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    graph.printGraph();

    return 0;
}
