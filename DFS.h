#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric> //For accumulate operation
#include <list>
using namespace std;

class Graph{
public:
    void DFS(int entryPoint);

    Graph(int N);

    void addEdge(int from, int to);

private:
    void DFSUtil(int v , bool visited[]);
    list<int> *adj;
    int N;
};

Graph::Graph(int N){
    this->adj = new list<int>[N];
    this->N = N;
}


void Graph::addEdge(int from , int to){
    this->adj[from].push_back(to);
}

void Graph::DFS(int s){
    bool *visited = new bool[N];
    for(int i = 0; i < N ; i++)
    {
        visited[i] = false;
    }

    DFSUtil(s, visited);
}

void Graph::DFSUtil(int v, bool visited[]){

    visited[v] = true;
    cout << v << " ";

    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); i++){
        if(!visited[*i])
            DFSUtil(*i, visited);
    }
}

int main()
{
     Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.DFS(2);

    return 0;
}

