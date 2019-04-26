#include <stdio.h>
#include <limits.h>
using namespace std;

int V;

int minDistance(int dist[], int sptSet[]){
    int min = INT_MAX , min_index;

    for(int v =0 ;v < V; v++){
        if(dist[v] <= min && sptSet[v] == false ){
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;

}

int main(){
    V = 9;

    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };




    return 0;
}
