#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

int main()
{
    string S, comment;
    while(getline(cin, S)){
        comment = "";
        if (S == "^D") break;
        size_t it = S.find("//");
        if(it != string::npos){
            comment = S.substr(it, S.length());
            S.erase(S.begin() + it, S.end());
        }
        if(S.find("->") != string::npos)
            S.replace(S.find("->"), 2,  ".");
        cout<<S<<comment<<endl;
    }
    return 0;
}
