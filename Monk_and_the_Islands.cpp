#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

void BFS(vector<int> * adj, bool * visited, int * depth, int i){
    queue<int> q;
    q.push(i);
    visited[i] = true;
    while(!q.empty()){
        i = q.front();
        q.pop();
        for(int j = 0; j < (int)adj[i].size(); ++j){
            if(!visited[adj[i][j]]){
                depth[adj[i][j]] = depth[i] + 1;
                q.push(adj[i][j]);
                visited[adj[i][j]] = true;
            }
        }
    }
}

int main()
{
    int T, N, M, X, Y;
    cin>>T;
    while(T--){
        cin>>N>>M;
        vector<int> adj[N];
        bool visited[N];
        int depth[N];
        memset(visited, false, sizeof visited);
        memset(depth, 0, sizeof depth);
        for(int i = 0; i < M; ++i){
            cin>>X>>Y;
            adj[X-1].push_back(Y-1);
            adj[Y-1].push_back(X-1);
        }
        for(int i = 0; i < N; ++i){
            if(!visited[i]){
                BFS(adj, visited, depth, i);
            }
        }
        cout<<depth[N-1]<<endl;
    }
    return 0;
}
