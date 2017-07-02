#include <iostream>
#include <vector>
#include <algorithm>
#include<cstring>
#include <climits>
#include <queue>
#include<utility>
using namespace std;

int mat[1000][1000];
bool visited[1000][1000];

int troopSize(int i, int j, int N, int M){
    queue<pair<int, int>> q;
    int ts = 1;
    q.push(make_pair(i, j));
    visited[i][j] = true;
    while(!q.empty()){
        i = q.front().first;
        j = q.front().second;
        q.pop();
        for(int l = i-1; l <= i+1; ++l){
            for(int k = j-1; k <= j+1; ++k){
                if(l == i && k == j){  visited[l][k] = true; continue;}
                if(l < 0 || l >= N || k < 0 || k >= M)  continue;
                if(mat[l][k] && !visited[l][k]){
                    ++ts;
                    q.push(make_pair(l, k));
                    visited[l][k] = true;
                }
            }
        }
    }
    return ts;
}

int main()
{
    int T, N, M;
    cin>>T;
    while(T--){
        cin>>N>>M;
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < M; ++j)
                cin>>mat[i][j];
        vector<int> troopSizes;
        memset(visited, false, sizeof visited);
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < M; ++j){
                if(mat[i][j]){
                    if(!visited[i][j]){
                        troopSizes.push_back(troopSize( i, j, N, M));
                    }
                }
            }
        }
        cout<<troopSizes.size()<<" "<<*max_element(troopSizes.begin(), troopSizes.end())<<endl;
    }
    return 0;
}
