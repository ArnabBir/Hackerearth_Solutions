#include <iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

int main()
{
    int N, sum, mindanger, danger;
    cin>>N;
   	vector<int> v(N);
   	for(int i = 0; i < N; ++i){
   		cin>>v[i];
   	}
   	sort(v.begin(), v.end());
   	mindanger = 0;
	for(int i = 0; i < N-2; ++i){
   		danger = v[i+2] - v[i];
 		if(danger > mindanger) mindanger = danger;
   	}
   	cout<<mindanger<<endl;
    return 0;
}
