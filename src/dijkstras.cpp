#include "dijkstras.h"
#include <queue>

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous){
    int n = G.numVertices;
    vector<int> distances (n, INF);
    previous.assign(n, -1);

    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    distances[source] = 0;
    pq.push({0, source});
    
    while(!pq.empty()){
        int dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (dist > distances[u]) continue;

        for (const Edge& e : G[u]){
            int v = e.dst;
            int weight = e.weight;

            if (distances[u] + weight < distances[v]){
                distances[v] = distances[u] + weight;
                previous[v] = u;
                pq.push({distances[v], v});
            }

        }
    }
    return distances;
}
vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination){
    vector<int> path;
    if (distances[destination] == INF) {return path;}
    for (int v = destination; v != -1; v = previous[v]){
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}
void print_path(const vector<int>& v, int total){
    if (v.empty()) {
        cout << "No path found" << endl;
        return;
    }
    cout << "Shortest Path: ";
    for (size_t i = 0; i < v.size(); ++i){
        cout << v[i];
        if (i != v.size() - 1){ cout << " ->"; }
        cout << "/nTotal Cost: " << total << endl;
    }
}