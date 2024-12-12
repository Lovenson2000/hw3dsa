#include <iostream>
#include <vector>
using namespace std;

void DFSUtil(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &result)
{
    visited[node] = true;
    result.push_back(node);

    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            DFSUtil(neighbor, adj, visited, result);
        }
    }
}

vector<int> DFS(vector<vector<int>> &adj, int start)
{
    vector<int> result;
    vector<bool> visited(adj.size(), false);
    DFSUtil(start, adj, visited, result);
    return result;
}

int main()
{
    vector<vector<int>> adj = {{1, 2}, {0, 2}, {0, 1, 3, 4}, {2}, {2}};
    vector<int> traversal = DFS(adj, 0);

    for (int node : traversal)
        cout << node << " ";
    cout << endl;
    return 0;
}