#include<bits/stdc++.h>
using namespace std;
#define ll long long


int f(int *h,int N){
	int dp[N];
	memset(dp,0,sizeof(dp));
	
	dp[0]=h[0];
	dp[1]=abs(h[0]-h[1]);
	dp[2]=abs(h[0]-h[2]);
	for(int i=3;i<N;i++){
		dp[i]=min(
			dp[i-1]+abs(h[i-1]-h[i]),
			dp[i-2]+abs(h[i-2]-h[i])
		);
	}
	return dp[N-1];
}
int32_t main(){
	int N;
	cin>>N;
	int a[N];
	for(int i=0;i<N;i++)
		cin>>a[i];
	
	//cout<<f(a,0,N)<<endl;
	cout<<f(a,N)<<endl;
	return 0;
}
