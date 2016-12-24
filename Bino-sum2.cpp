#include <iostream>
using namespace std;

long long int dp[1001][1001] = {1}; 
bool flag[1001][1001] = {false};

long long int F(int N, int P){
    if(flag[N][P] == true)  return dp[N][P];
    
    if(P == 0){
        flag[N][P] = true;
        flag[N][N-P] = true;
        dp[N][N-P] = dp[N][P] = 1;
        return dp[N][P] = 1;
    }
    if(N == 1){
        flag[N][P] = true;
        flag[N][N-P] = true;
        dp[N][N-P] = dp[N][P] = 1;
        return dp[N][P];
    }
    if(P == 1){
        flag[N][P] = true;
        flag[N][N-P] = true;
        dp[N][N-P] = dp[N][P] = N;
        return dp[N][P];
    }
    
    if(P > N / 2)  P = N - P;
    dp[N][P] = (F(N-1,P-1) % 1000000007 + F(N-1,P) % 1000000007) % 1000000007;    
    flag[N][P] = true;
    flag[N][N-P] = true;
    dp[N][N-P] = dp[N][P];
    return dp[N][P];
}

int main()
{
    int T, N, P;
    cin>>T;
    long long int result;
    while(T--){
        result = 0;
        cin>>N>>P;
        for(int i = 0; i <= P; ++i){
            result = (result + F(N,i)) % 1000000007;
        }
        cout<<result<<endl;
    }
    return 0;
}
