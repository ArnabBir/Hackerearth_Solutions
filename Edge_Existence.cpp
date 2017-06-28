#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int N, M, A, B, Q;
    cin>>N>>M;
    
    int AdjMat[N][N];
    memset(AdjMat, 0, sizeof AdjMat);
    
    for(int i = 0; i < N; ++i){
        AdjMat[i][i] = 1;
    }
    
    for(int i = 0; i < M; ++i){
        cin>>A>>B;
        AdjMat[A-1][B-1] = AdjMat[B-1][A-1] = 1;
    }
    
    cin>>Q;
    for(int i = 0; i < Q; ++i){
        cin>>A>>B;
        if(AdjMat[A-1][B-1] == 1)   cout<<"YES"<<endl;
        else   cout<<"NO"<<endl;
    }
    
    return 0;
}
