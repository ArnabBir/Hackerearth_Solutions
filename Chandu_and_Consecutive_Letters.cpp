#include <iostream>
#include<string>
#include<cstring>
#include<vector>

using namespace std;

int main()
{
    int T;
    string s;
    cin>>T;
    while(T--){
    	cin>>s;
    	if(s[0] == '\0'){
    		cout<<endl;
    		continue;
    	}
    	vector<char> result;
    	int pos = 0;
    	result.push_back(s[0]);
    	while(s[pos++ + 1] != '\0'){
    		if(s[pos-1] != s[pos]){
    			result.push_back(s[pos]);
    		}
    	}
    	for(vector<char>::iterator itr= result.begin(); itr != result.end(); ++itr){
    		cout<<*itr;
    	}
    	cout<<endl;
    }
    return 0;
}
