#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Disk{
	private:
		long int radius;
		long int height;
	public:
		Disk(){radius = 0; height = 0;}
		Disk(long int r, long int h){
			radius = r;
			height = h;
		}

		long int getRadius(){ return radius;}
		long int getHeight(){ return height;}
		~Disk(){}
};

bool compare(Disk a, Disk b)
{
  return ( a.getRadius() > b.getRadius() && a.getHeight() > b.getHeight());
}

int main()
{
    int T, N;
    cin>>T;
    while(T--){
    	cin>>N;
    	long long int radius, height;
    	vector<Disk> D;
    	for(int i = 0; i < N; ++i){
    		cin>>radius>>height;
    		//cout<<radius<<" "<<height<<endl;
    		D.push_back(Disk(radius, height));
    		//cout<<D.at(i).getRadius()<<" "<<D.at(i).getHeight()<<endl;
    	}
    	long long int * dp = new long long int[N];
    	sort(D.begin(), D.end(), compare); // reverse sort
    	dp[0] = D.at(0).getHeight();
    	for(int i = 1; i < N; ++i){
    		dp[i] = D.at(i).getHeight();
    		cout<<"dp[i] = "<<dp[i]<<endl;
    		for(int j = 0; j < i; ++j){
    			if(D.at(i).getRadius() < D.at(j).getRadius() && D.at(j).getHeight() < D.at(j).getHeight()){
    				dp[i] = max(dp[i], dp[j] + D.at(i).getHeight()); 
    			}
    		}
    		dp[i]=max(dp[i],dp[i-1]);
    	}
    	cout<<dp[N-1]<<endl;
    }
    return 0;
}
