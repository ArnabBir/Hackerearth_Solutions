#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

void DFS(vector<int> * adj, bool * visited, int i, int * childCount,int * parent){
    visited[i] = true;
    for(int j = 0; j < childCount[i]; ++j){
        if(!visited[adj[i][j]]){
            parent[adj[i][j]] = i;
            DFS(adj, visited, adj[i][j], childCount, parent);
        }
    }
}

int main()
{
    int N, M, X, Y;
    cin>>N>>M;
    vector<int> adj[N];
    bool visited[N];
    int childCount[N], parent[N];
    memset(childCount, 0, sizeof childCount);
    memset(parent, -1, sizeof parent);
    memset(visited, false, sizeof visited);
    for(int i = 0; i < M; ++i){
        cin>>X>>Y;
        adj[X-1].push_back(Y-1);
    }
    
    bool isMasterNode[N];
    int masterIndex = -1;
    memset(isMasterNode, true, sizeof isMasterNode);
    for(int i = 0; i < N; ++i){
        childCount[i] = adj[i].size();
        //cout<<"child = "<<childCount[i]<<endl;
        for(int j = 0; j < childCount[i]; ++j){
            isMasterNode[adj[i][j]] = false;
        }
    }
    for(int i = 0; i < N; ++i){
        if(isMasterNode[i]){ 
            masterIndex = i;
            break;
        }
    }
    //cout<<masterIndex<<endl;
    if(masterIndex != -1)   DFS(adj, visited, masterIndex, childCount, parent);
    for(int i = 0; i < N; ++i){    
        if(!visited[i])
            DFS(adj, visited, i, childCount, parent);
    }
    int countHappy = 0;
    for(int i = 1; i < N; ++i){
        if(childCount[i] > childCount[parent[i]])   ++countHappy;
    }
    cout<<countHappy;
    return 0;
}
