#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> Edge;

int findMST(int V, vector<vector<Edge>> &adj)
{
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    vector<bool> inMST(V, false);
    int mstCost = 0, edgesUsed = 0;

    pq.push({0, 0});

    while (!pq.empty() && edgesUsed < V - 1)
    {
        auto [weight, node] = pq.top();
        pq.pop();

        if (inMST[node])
            continue;

        inMST[node] = true;
        mstCost += weight;
        ++edgesUsed;

        for (auto &[neighbor, edgeWeight] : adj[node])
        {
            if (!inMST[neighbor])
            {
                pq.push({edgeWeight, neighbor});
            }
        }
    }
    return mstCost;
}

int main()
{
    int V = 3;
    vector<vector<Edge>> adj(V);
    adj[0] = {{1, 5}, {2, 1}};
    adj[1] = {{0, 5}, {2, 3}};
    adj[2] = {{0, 1}, {1, 3}};

    cout << "Minimum Spanning Tree Cost: " << findMST(V, adj) << endl;
    return 0;
}