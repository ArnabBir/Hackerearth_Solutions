#include <iostream>
using namespace std;

int main()
{
    int N, Q;
    cin>>N;
    int soldierPower[N], bishuPower[Q];
    for(int i = 0; i < N; ++i)  cin>>soldierPower[i];
    cin>>Q;
    for(int i = 0; i < Q; ++i)  cin>>bishuPower[i];
    for(int i = 0; i < Q; ++i){
        int power = 0, count = 0;
        for(int j = 0; j < N; ++j){
            if(bishuPower[i] >= soldierPower[j]){
                power += soldierPower[j];
                count++;
            }
        }
        cout<<count<<" "<<power<<endl;
    }
    return 0;
}
