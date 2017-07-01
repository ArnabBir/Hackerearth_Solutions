#include <iostream>
#include <algorithm>
#include<cstring>
#include <climits>

using namespace std;

int dp[500][500];
int a[500];
bool known[500][500];
int n;


int getDistance(int i, int j){
    if(known[i][j])  return dp[i][j];
    if(i > j) dp[i][j] = 0;
    else if(i == j)   dp[i][j] = 1;
    else if(a[i] == a[j]) dp[i][j] = getDistance( i+1, j-1);
    else{
        int minCost = getDistance(i+1, j)+1;
        for(int k = i+1; k < j; ++k){
            if(a[i] == a[k])
                minCost = min(minCost, getDistance(i+1, k-1) + getDistance(k+1, j));
        }
        dp[i][j] = minCost;
    }
    known[i][j] = true;
    return dp[i][j];
}

int main()
{
    cin>>n;
    memset(dp, 0, sizeof dp);
    memset(known, false, sizeof known);
    for(int i = 0; i < n; ++i)  cin>>a[i];
    cout<<getDistance( 0, n-1);
    
    return 0;
}
