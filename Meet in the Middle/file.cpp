#include<stdio.h>
#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include<vector>
#include <map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<list>
#include<stack>
#include<queue>
#include<limits.h>
using namespace std;

#define pb push_back
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

int solve(int *a,int sum,int n){
	 if(n<=0 || sum==0)
	 	return 0;
	 if(a[n-1]>sum)
	 	return solve(a,sum,n-1);
	 return std::max(a[n-1]+solve(a,sum-a[n-1],n-1),solve(a,sum,n-1));
}
int solveDP(int *a,int sum,int n){
	int dp[n+1][sum+1];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=sum;j++)
			if(i==0 || j==0)
				dp[i][j]=0;
			else if(a[i-1]>j)
				dp[i][j]=dp[i - 1][j];
			else
				dp[i][j]=max(a[i-1]+dp[i-1][j-a[i-1]],dp[i-1][j]);
	return dp[n][sum];
}
void fileIO(){
	freopen("input.in", "r", stdin);
  	freopen("output.out", "w", stdout);

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int main(){
	fileIO();

	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int Set[n];

		for(int i=0;i<n;i++)
			scanf("%d",&Set[i]);	
		int S;
		scanf("%d",&S);
		//cout<<solve(Set,S,n)<<endl;
		cout<<solveDP(Set,S,n)<<endl;	
	}
	return 0;
}