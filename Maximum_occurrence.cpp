#include <iostream>
#include<map>
#include <string>
#include<climits>
#include <algorithm>

using namespace std;

int main()
{
    string S;
    map<char, int> charCount; 
    getline(cin, S);
    for(string::iterator it = S.begin(); it != S.end(); ++it){
        if(charCount.find(*it) != charCount.end()){
            ++charCount[*it];
        }
        else    charCount[*it] = 1;
    }
    
    int minChar = INT_MAX, maxCount = -1; 
    for(auto& i : charCount){
            if(maxCount < i.second){ maxCount = i.second; minChar = i.first;}
            if(maxCount == i.second){
                minChar = min((int)minChar, (int)i.first);
            }
    }
    
    cout<<(char)minChar<<" "<<maxCount<<endl;
    
    return 0;
}
