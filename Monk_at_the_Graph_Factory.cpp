#include <iostream>
using namespace std;

int main()
{
    int N, degreeSum = 0;
    cin>>N;
    int degree[N];
    for(int i = 0; i < N; ++i){
        cin>>degree[i];
        degreeSum += degree[i];
    }
    if(degreeSum / 2 == N - 1)  cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
