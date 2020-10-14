#include<bits/stdc++.h>
#include<string>
#include<algorithm>
using namespace std;

int dp[4000][4000];

int lcs(string a,string b,int m,int n){
	if(m==0 || n==0)
		return 0;
	if(a[m-1]==b[n-1])
		return lcs(a,b,m-1,n-1)+1;
	else
		return max(
			lcs(a,b,m-1,n),
			lcs(a,b,m,n-1)
		);
}
int DP(string a,string b,int m,int n){
			
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(i==0 || j==0)
				dp[i][j]=0;
			else if(a[i-1]==b[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				
	return dp[m][n];
}
string getLCS(string a,string b,int m,int n){
	if(m==0 || n==0)
		return "";
	if(a[m-1]==b[n-1])
		return getLCS(a,b,m-1,n-1)+a[m-1];
		
	if(dp[m-1][n]>dp[m][n-1])
		return getLCS(a,b,m-1,n);
	else
		return getLCS(a,b,m,n-1);
}
int32_t main(){
	string a,b;
	cin>>a>>b;
	//cout<<lcs(a,b,a.length(),b.length())<<endl;
	int m=a.length(),n=b.length();
	
	for(int i=0;i<=m;i++)
		for(int j=0;j<=n;j++)
			dp[i][j]=0;
	DP(a,b,m,n);
	cout<<getLCS(a,b,m,n)<<endl;
	return 0;
}
