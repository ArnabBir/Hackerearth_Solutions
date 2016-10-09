    #include <iostream>
    #include<bits/stdc++.h>
    using namespace std;
    #define inf 1000000007
    long long int dp[100001];
     
    int main()
    {
    	long long int i,j,n,t;
    	cin>>t;
    	while(t--)
    	{
    		cin>>n;
    		pair<long long int,long long int >a[n+1];
    		for(i=1;i<=n;i++)
    		{
    			cin>>a[i].first;
    			cin>>a[i].second;
    		}
    		sort(a+1,a+n+1);
    		reverse(a+1,a+n+1);
    		//dp[1]=a[1].second;
    		for(i=1;i<=n;i++)
    		{
    			dp[i]=a[i].second;
    			for(j=1;j<i;j++)
    			{
    				if(a[i].first<a[j].first && a[i].second<a[j].second)
    				dp[i]=max(dp[i],dp[j]+a[i].second);
    			}
    			dp[i]=max(dp[i],dp[i-1]);
    		}
    		cout<<dp[n]<<endl;
    	}
    	return 0;
    }
