
#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric> //For accumulate operation
#include <list>
using namespace std;


class Graph{
public:
    void BFS(int entryPoint);

    Graph(int N);

    void addEdge(int from, int to);

private:
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

void Graph::BFS(int s){

    bool* visited = new bool[N];
    for(int i = 0 ; i < N ; i++)
    {
            visited[i] = false;
    }

    list<int> queue;
    queue.push_back(s);
    visited[s] = true;

    list<int>::iterator i;

    while(!queue.empty()){

        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        for ( i = adj[s].begin(); i < adj[s].end(); i++){

            if(!visited[*i]){
                visited[*i] = true;
                queue.push_back(*i);
            }
        }

    }

}

int main2()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

   g.BFS(2);


    return 0;
}
