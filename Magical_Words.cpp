#include <iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

long long int sq[1000] = {0};
bool isCalculated[1000] = {false};

map<string, long long int> strPalin;

long long int square(int x){
    if(isCalculated[x]) return sq[x];
    else{
        isCalculated[x] = true;
        return sq[x] = x * x;
        }
}

long long int PalinSquare(string word, int j, int i){
    string str = word.substr(j,i - j + 1);
    if(i==j) return 1;
    if (strPalin.find(str) != strPalin.end()) return strPalin[str];
    for(int k = 0; k <= (i - j)/2 + 1; ++k){
        if(word[j+k] != word[i-k]) return 0;
    }
    return strPalin[str] = square(i - j + 1);
}

int main()
{
    int T, i;
    long long int score;
    cin>>T;
    string word;
    while(T--){
        cin>>word;
        score = 0;
        i = 0;
        for(string::iterator it = word.begin(); it != word.end(); ++it, ++i){
            for(int j = 0; j <= i; ++j){
                score += PalinSquare(word, j, i);
            }
        }
        cout<<score<<endl;
    }
    return 0;
}
