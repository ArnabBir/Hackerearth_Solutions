#include <bits/stdc++.h>

using namespace std;

int main(){
    
    string s, love = "love";
    cin>>s;
    int count = 0;
    bool flag = false;
    
    for(int i = 0; i < s.length(); ++i){
        
        if(s[i] == love[count]) ++count;
        if(count >= 4){
            flag = true;
            break;
        }
    }
    
    if(flag)    cout<<"I love you, too!"<<endl;
    else    cout<<"Let us breakup!"<<endl;
    
    return 0;
}
