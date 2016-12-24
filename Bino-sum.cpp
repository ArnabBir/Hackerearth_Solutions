#include <iostream>
using namespace std;

long long int dp[1001][1001] = {1}; 
bool flag[1001][1001] = {false};

long long int F(int N, int P){
    if(flag[N][P] == true)  return dp[N][P];
    
    flag[N][P] = true;
    if(P > N / 2)  P = N - P;
    long long output = 1;
    for(int i = 1; i <= P; ++i) {
        output *= N - P + i;
        output /= i;
        //output %= 1000000007;
    }
    output %= 1000000007;
    flag[N][P] = true;
    dp[N][P] = output;
    dp[N][N-P] = output;
    //cout<<"OP = " <<output<<endl;
    return output;
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
            result += F(N,i) % 1000000007;
        }
        cout<<result<<endl;
    }
    return 0;
}
