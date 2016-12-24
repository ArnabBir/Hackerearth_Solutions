#include <iostream>
#include<string>
#include<algorithm>
#include<typeinfo>

using namespace std;

int main()
{
    string S,s1,s2;
    cin>>S;
    int count = 0;
    int N = S.length();
    for(int i = 0; i <= N; ++i){
        for(int j = i + 1; j <= N; ++j){
            s1 = S.substr(i,j-i);
            s2 = s1;
            reverse(s2.begin(), s2.end());
            if(s1 == s2)    ++count;
        }
    }
    cout<<count<<endl;
    return 0;
}
