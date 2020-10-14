#include<bits/stdc++.h>
using namespace std;
#define ll long long
int dp[1000000];

int f(int *h,int i,int N){
	if(i==N) return 0;
	if(dp[i]!=-1) return dp[i];
	int cost=abs(h[i]-h[i+1])+f(h,i+1,N);
	if(i+2<N){
		cost=min(cost, abs(h[i]-h[i+2]) )+f(h,i+2,N);
	}
	return dp[i]=cost;
}
int32_t main(){
	int N;
	cin>>N;
	int a[N];
	for(int i=0;i<N;i++)
		cin>>a[i];
	memset(dp,-1,sizeof(dp));
	cout<<f(a,0,N)<<endl;
	return 0;
}
