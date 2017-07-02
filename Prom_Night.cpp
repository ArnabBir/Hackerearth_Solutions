#include <iostream>
#include <algorithm>
using namespace std;

bool calculatePossibility(int * boysHeight, int * girlsHeight, int M, int N){
    if(M > N)   return false;
    sort(boysHeight, boysHeight + M);
    sort(girlsHeight, girlsHeight + N);
    bool isPossible = true;
    for(int i = 0; i < M; ++i){
        if(girlsHeight[i] >= boysHeight[i]){
            isPossible = false;
            break;
        }
    }
    return isPossible;
}

int main()
{
    int T, N, M;
    cin>>T;
    while(T--){
        cin>>M>>N;
        int boysHeight[M], girlsHeight[N];
        for(int i = 0; i < M; ++i)  cin>>boysHeight[i];
        for(int i = 0; i < N; ++i)  cin>>girlsHeight[i];
        if(calculatePossibility(boysHeight, girlsHeight, M, N)) cout<<"YES"<<endl;
        else    cout<<"NO"<<endl;
    }
    return 0;
}
