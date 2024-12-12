
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> BFS(vector<vector<int>> &adj, int start)
{
    vector<int> result;
    vector<bool> visited(adj.size(), false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return result;
}

int main()
{
    vector<vector<int>> adj = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
    vector<int> traversal = BFS(adj, 0);

    for (int node : traversal)
        cout << node << " ";
    cout << endl;
    return 0;
}