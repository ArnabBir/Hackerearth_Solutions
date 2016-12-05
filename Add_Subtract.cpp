#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int T, N, K, target, mincost, cost;
    cin>>T;
    while(T--){
    	cin>>N>>K;
    	vector<int> v(N);
    	for(int i = 0; i < N; ++i){
    		cin>>v[i];
    	}
    	sort(v.begin(), v.end());
    	target = v[0];
    	mincost = 2147483647;
    	while(target <= v[N-1]){
    		for(int i = 0; i <= N - K; ++i){
    			cost = 0;
    			for(int j = i; j < i + K; ++j){
    				cost += (((v[j] - target) > 0) ? 5*(v[j] - target) : 3*(target - v[j]));
    			}
    			if(cost < mincost) mincost = cost;
    		}
    		++target;
    	}
       	cout<<mincost<<endl;
    }
    return 0;
}
