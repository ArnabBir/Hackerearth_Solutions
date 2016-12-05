#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int T, N, sum;
    cin>>T;
    while(T--){
    	cin>>N;
    	vector<int> v(N);
    	vector<int> isOdd(N);
    	for(int i = 0; i < N; ++i){
    		cin>>v[i];
    		isOdd[i] = v[i] % 2;
    	}
    	if(accumulate(isOdd.begin(), isOdd.end(), 0) % 2) cout<<"No"<<endl;
    	else cout<<"Yes"<<endl;
    }
    return 0;
}
