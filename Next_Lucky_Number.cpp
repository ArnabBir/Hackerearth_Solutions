#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int T, i;
    char N[101];
    bool carry;
    cin>>T;
    while(T--){
        vector<char> NLN;
        cin>>N;
        i = 0;
        while(N[++i] != '\0');
        carry = false;
        while(i-- > 0){
            if(int(N[i]) < (48+5) && int(N[i]) > (48+3) ){
                NLN.push_back('5');
            }
            else if(int(N[i]) > (48+5)){
                NLN.push_back('3');
                carry = true;
            }
            else{
                NLN.push_back('3');
            }
        }
        reverse(NLN.begin(), NLN.end());
        if(carry && int(N[0]) > int(NLN[0])) cout<<"3";
        for(vector<char>::iterator itr = NLN.begin(); itr != NLN.end(); ++itr){
            cout<<*itr;
        }
        cout<<endl;
    }
    return 0;
}
