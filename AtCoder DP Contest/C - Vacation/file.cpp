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

void fileIO(){
	freopen("input.in", "r", stdin);
  	freopen("output.out", "w", stdout);

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int main(){
	//fileIO();

	int n;
	scanf("%d",&n);
	int ar[n+1][3]={0};
	//memset(a,0,sizeof(a));

	
	for(int i=1;i<=n;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		ar[i][0]=a+max(ar[i-1][1],ar[i-1][2]);
		ar[i][1]=b+max(ar[i-1][2],ar[i-1][0]);
		ar[i][2]=c+max(ar[i-1][1],ar[i-1][0]);
	}
	
	cout<<max(max(ar[n][0],ar[n][1]),ar[n][2])<<endl;
	return 0;
}