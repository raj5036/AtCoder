#include<stdio.h>
#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <cstdio>
#include<vector>
#include<unordered_map>
#include<set>
#include<list>
#include<stack>
#include<queue>
using namespace std;

#define pb push_back
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

ll solve(int *wt,int *val,int N,int W){
	 if(N==0 || W==0)
	 	return 0;
	 if(wt[N-1]>W)
	 	return solve(wt,val,N-1,W);

	 return std::max(
	 		val[N-1]+solve(wt,val,N-1,W-wt[N-1]),
	 		solve(wt,val,N-1,W)
	 	);
}
ll solveDP(int *wt,int *val,int N,int W){
	ll dp[N+1][W+1];
	memset(dp,0,sizeof(dp));

	for(int i=0;i<=N;i++)
		for(int j=0;j<=W;j++)
			if(i==0 || j==0)
				dp[i][j]=0;
			else if (wt[i - 1] <= j) 
                    dp[i][j] = max( 
                        val[i - 1] + dp[i - 1][j - wt[i - 1]], 
                        dp[i - 1][j]); 
             else
                 dp[i][j] = dp[i - 1][j];
	return dp[N][W];
}
void fileIO(){
	freopen("input.in", "r", stdin);
  	freopen("output.out", "w", stdout);
}
int main(){
	//fileIO();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N,W;
	scanf("%d%d",&N,&W);
	int wt[N],val[N];
	
	for(int i=0;i<N;i++){
		scanf("%d",&wt[i]);
		scanf("%d",&val[i]);
	}

	//cout<<solve(wt,val,N,W)<<endl;	
	cout<<solveDP(wt,val,N,W)<<endl;
	return 0;
}