#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    bool flag;
    cin>>T;
    while(T--){
        set<char> charSet;
        string S;
        cin>>S;
        flag = false;
        for(string::iterator it = S.begin(); it != S.end(); ++it){
            if(charSet.find(*it) != charSet.end()) {
                flag = true;
                break;
            }
            else    charSet.insert(*it);
        }
        if(flag)    cout<<"Yes"<<endl;
        else    cout<<"No"<<endl;
    }
    return 0;
}
