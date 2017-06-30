#include <iostream>
#include <cstring>
#include <cmath>
#include <climits>
#include<cstdio>
using namespace std;



int getMinWeight(int * weight, bool * nodeSet, int N){
    int minimum = INT_MAX, minimumIndex = -1;
    for(int i = 0; i < N; ++i){
        if(nodeSet[i] == false && weight[i] < minimum){
            minimum = weight[i];
            minimumIndex = i;
        }
    }
    return minimumIndex;
}

void getPrim(int N, int opMat[N][N]){
    
    int weight[N], parent[N];
    bool nodeSet[N];
    int  A[N][N];
    
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            A[i][j] = A[j][i] = abs(i - j);
    
    memset(weight, INT_MAX, sizeof weight);
    memset(nodeSet, false, sizeof nodeSet);
    memset(A, INT_MAX, sizeof A);
    
    weight[0] = 0;
    parent[0] = -1;
    
    for(int i = 0; i < N-1; ++i){
        int MinIndex = getMinWeight(weight, nodeSet, N);
        nodeSet[MinIndex] = true;
        for(int j = 0; j < N; ++j){
            if(A[MinIndex][j] > 0 && nodeSet[j] == false && A[MinIndex][j] < weight[j]){
                weight[j] = A[MinIndex][j];
                parent[j] = MinIndex;
            }
        }
    }
    
    for(int i = 1; i < N; ++i){
        opMat[parent[i]][i] = opMat[i][parent[i]] = 1;
    }
}

int main()
{
    int N, M;
    int T, u, v;
    cin>>T;
    while(T--){
        
        cin>>N>>M;
        
        int inpMat[N][N], opMat[N][N], deltaMat[N][N];
        
        memset(inpMat, 0, sizeof inpMat);
        memset(opMat, 0, sizeof opMat);
        
        for(int i = 0; i < M; ++i){
            cin>>u>>v;
            inpMat[u-1][v-1] = inpMat[v-1][u-1] = 1;
        }
        
        getPrim(N, opMat);
        
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
                deltaMat[i][j] = inpMat[i][j] ^ opMat[i][j];
                
        int result = 0;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j <= i; ++j){
                if(deltaMat[i][j] == 1){
                    result += abs(i-j);
                }
            }
        }
        cout<<result<<endl;
    }
    return 0;
}
