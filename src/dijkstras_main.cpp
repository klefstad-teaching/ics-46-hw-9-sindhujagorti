#include "dijkstras.h"

using namespace std;

int main(){
    Graph G;
    try {
        file_to_graph("small.txt", G);
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
        return 1;
    }
    int source, destination;
    cout << "Enter source and destination vertices: ";
    cin >> source >> destination;

    vector<int> previous;
    vector<int> distances = dijkstra_shortest_path(G, source, previous);
    vector<int> path = extract_shortest_path(distances, previous, destination);

    print_path(path, distances[destination]);

    return 0;
}