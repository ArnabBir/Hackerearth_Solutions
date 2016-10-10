#include <iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;


vector<int> getPrime(int N){
	vector<int> count;
	if(N >= 2) count.push_back(2);
	for (int i=3; i < N; ++i) {
		if(i % 2 == 0) continue;
        for (int j =3 ; j*j <= i; j += 2){
            if (i % j == 0) break;
        }
        count.push_back(i);
    }
    return count;
}
            
long long int getMaxpoints(int * A, int N, vector<int> count){
	int temp_count = 1;
	long long int max = A[0];
	long long int * dp = new long long int[N];
	dp[0] = A[0];
	for(int i = 1; i < N; ++i){
		dp[i] = dp[i - 1] + A[i];
		++temp_count;
		if(dp[i] > max && find(count.begin(), count.end(), temp_count) != count.end()) max = dp[i];
	}
	return max;
}

int main()
{
    int N;
    cin>>N;
    int * point = new int[N];
    for(int i = 0; i < N; ++i){
    	cin>>point[i];
    }
	vector<int> count = getPrime(N);
    cout<<getMaxpoints(point, N, count)<<endl;
    return 0;
}
