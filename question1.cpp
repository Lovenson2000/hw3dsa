// Lovenson BEAUCICOT
// 1123557
// 12/12/2024
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> createAdjacencyList(int V, vector<pair<int, int>> &edges)
{
    vector<vector<int>> adj(V);
    for (auto &edge : edges)
    {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }
    return adj;
}

int main()
{
    int V = 5;
    vector<pair<int, int>> edges = {{0, 1}, {0, 4}, {4, 1}, {4, 3}, {1, 3}, {1, 2}, {3, 2}};
    vector<vector<int>> adj = createAdjacencyList(V, edges);

    for (int i = 0; i < V; ++i)
    {
        cout << i << ": ";
        for (int j : adj[i])
            cout << j << " ";
        cout << endl;
    }
    return 0;
}