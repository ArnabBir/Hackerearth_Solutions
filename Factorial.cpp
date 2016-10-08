#include <iostream>
#include<cmath>
#include<algorithm>
using namespace std;

long long int * factResult;
long long int modulo = pow(10 , 9) + 7;

void factorial(int N){
    for(int i = 2; i <= N; ++i){
    	factResult[i] = (i * factResult[i - 1]) % modulo;
    }
    
}

int main()
{
    int T;
    cin>>T;
    int  N[T];
    for(int i = 0; i < T; ++i){
    	cin>>N[i];
    }
    int max = * max_element(N, N + T);
    //cout<<"max = "<<max<<endl;
    factResult = new long long int [max];
    factResult[0] = 1;
    factResult[1] = 1;
    factorial(max);
    
    for(int i = 0; i < T; ++i){
    	cout<<factResult[N[i]]<<endl;
    }
    return 0;
}
