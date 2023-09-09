#include <iostream>
#include <map>
#include <list>
#include <utility>
using namespace std;

class Graph {
    map<int, list<pair<int, int>>> mp;

public:
    Graph() {
        cout << "Graph initialized" << endl;
    }

    void add_edge(int u, int v, int w, bool directed) {
        mp[u].push_back({v, w});
        if (!directed) {
            mp[v].push_back({u, w});
        }
    }

    void print() {
        for (auto i : mp) {
            cout << i.first << "->";
            for (auto j : i.second) {
                cout << "(" << j.first << "," << j.second << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g;
    int n, e;
    cout << "Enter the number of nodes in the graph: ";
    cin >> n;
    cout << "Enter the number of edges in the graph: ";
    cin >> e;

    for (int i = 0; i < e; i++) {
        int u, v, w;
        cout << "Enter edge " << i + 1 << " (u v w): ";
        cin >> u >> v >> w;
        g.add_edge(u, v, w, true);
    }
    g.print();
    return 0;
}
