#include <iostream>
using namespace std;

int main()
{
    int T, N, M, count;
    cin>>T;
    while(T--){
    	count = 0;
    	cin>>N>>M;
    	char a[20][20];
    	for(int i = 0; i < N; ++i){
    		for(int j = 0; j < M; ++j){
    			cin>>a[i][j];
    		}
    	}
    	for(int i = N - 1; i >= 0; --i){
    		for(int j = M - 1; j >= 0; --j){
    			if(a[i][j] == '0'){
    				++count;
    				for(int k = 0; k <= i; ++k){
    					for(int l = 0; l <= j; ++l){
    						if(a[k][l] == '1') a[k][l] = '0';
    						else a[k][l] = '1';
    					}
    				}	
    			} 
    			
    		}
    	}
    	
    	cout<<count<<endl;
    }
    return 0;
}
