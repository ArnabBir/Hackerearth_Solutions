#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int T, N, X;
    cin>>T;
    while(T--){
    	cin>>N>>X;
    	vector<int> v(N);
    	for(int i = 0; i < N; ++i){
    		cin>>v[i];
    	}
    	sort(v.begin(), v.end());
    	int vol = 0, itr = 0;
    	while(vol < X){
    		vol += v[itr++];
    	}
    	cout<<itr-1<<endl;
    }
    return 0;
}
