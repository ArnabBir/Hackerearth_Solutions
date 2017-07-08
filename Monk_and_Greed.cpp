#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>

using namespace std;

vector<pair<int, pair<int, int>>> edges;
int parent[100000];
int A[100000];

int root(int x){
    if(parent[x] < 0)  return x;
    return (parent[x] = root(parent[x]));
}

void union_(int u, int v){
    if(root(u) == root(v))  return;
    if(parent[v] < parent[u]) swap(u, v);
    parent[u] += parent[v];
    A[u] += A[v];
    parent[v] = u;
}

int main()
{
    int N, M, U, V, W;
    cin>>N>>M;
    for(int i = 0; i < N; ++i)  cin>>A[i];
    for(int i = 0; i < M; ++i){
        cin>>U>>V>>W;
        edges.push_back(make_pair(W, make_pair(U, V)));
    }
    cin>>U>>V;
    sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());
    memset(parent, -1, sizeof parent);
    for(int i = 0; i < (int)edges.size(); ++i){
        U = edges[i].second.first;
        V = edges[i].second.second;
        W = edges[i].first;
        union_(U, V);
        if(root(U)==root(V)){
			for(int j=i+1; j < (int)edges.size(); ++j){
				if(edges[j].first != W)break;
				union_(edges[j].second.first,edges[j].second.second);
			}
			U = root(U);
			cout<<W<<" "<<A[U];
			break;
		}
    }
    
    return 0;
}
