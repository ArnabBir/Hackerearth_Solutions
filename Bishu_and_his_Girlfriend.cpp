#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
using namespace std;

void DFS(vector<int> * adj, bool * visited, int * distance, int i){
    visited[i] = true;
    for(int j = 0; j < (int) adj[i].size(); ++j){
        if(visited[adj[i][j]] == false){
            distance[adj[i][j]] = distance[i] + 1;
            DFS(adj, visited, distance, adj[i][j]);
        }
    }
}

int main()
{
    int N, Q, u, v;
    cin>>N;
    int distance[N];
    memset(distance, 0, sizeof distance);
    vector<int> adj[N];
    bool visited[N];
    memset(visited, false, sizeof visited);
    for(int i = 0; i < N-1; ++i){
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    cin>>Q;
    int posQ[Q];
    for(int i = 0; i < Q; ++i){  
        cin>>posQ[i];
        --posQ[i];
    }
    for(int i = 0; i < N; ++i){
        if(visited[i] == false){
            DFS(adj, visited, distance, i);
        }
    }
    int minDistIndex = -1, minDist = INT_MAX;
    for(int i = 0; i < Q; ++i){
        if(minDist > distance[posQ[i]]){
            minDist = distance[posQ[i]];
            minDistIndex = posQ[i];
        }
    }
    cout<<minDistIndex+1<<endl;
    return 0;
}
