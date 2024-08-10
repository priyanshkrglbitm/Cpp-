#include<bits/stdc++.h>
using namespace std;

class Graph{
    int vertices;
    vector<vector<int>>adjList;

    public:
    Graph(int V):vertices(V){
        adjList.resize(vertices);
    }
        void addEdge(int u, int v) {
        // Add vertex v to the list of vertex u
        adjList[u].push_back(v);
        // If it's an undirected graph, add an edge from v to u as well
        adjList[v].push_back(u); // Comment this line for a directed graph
    }

    void printGraph() const {
        for (int i = 0; i < vertices; ++i) {
            std::cout << "Vertex " << i << ": ";
            for (int v : adjList[i]) {
                std::cout << v << " ";
            }
            std::cout << std::endl;
        }
    }

};

int main(){
        Graph graph(5);

    // Add edges to the graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    // Print the adjacency list of the graph
    graph.printGraph();
    return 0;
}