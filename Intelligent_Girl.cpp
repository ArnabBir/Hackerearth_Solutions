#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string S;
    cin>>S;
    int count = 0;
    stack<int> evenCount;
    for(string::iterator it = S.end() - 1; it != S.begin()-1; --it){
        if(((int)(*it))%2 == 0)   ++count;
        evenCount.push(count);
    }
    while(!evenCount.empty()){
        cout<<evenCount.top()<<" ";
        evenCount.pop();
    }
    return 0;
}
