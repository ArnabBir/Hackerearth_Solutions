#include <iostream>
#include <set>
using namespace std;

int main()
{
    int E, T, X, Y, count;
    
    cin>>T;
    while(T--){
        set<int> s;
        cin>>E;
        for(int i = 0; i < E; ++i){
            cin>>X>>Y;
            s.insert(X);
            s.insert(Y);
        }
        count = 0;
         while (!s.empty()) {
            ++count;
            s.erase(s.begin());
        }
        cout<<count<<endl;
    }
    return 0;
}
