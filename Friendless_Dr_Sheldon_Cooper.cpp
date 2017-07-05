#include <iostream>


using namespace std;


int main()
{
    int t, a, b, m, n;
    cin>>t;
    while(t--){
        cin>>a>>b;
        for(int i = 0; i < b; ++i){
            cin>>m>>n;
        }
        cout<<a-1<<endl;
    }
    return 0;
}
