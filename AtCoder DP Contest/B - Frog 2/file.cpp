#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int dp[1000000];


int32_t main(){
	int N, K;
    cin >> N >> K;
    vector<int> H(N);
    for(int i=0;i<N;i++) cin >> H[i];
    dp[0] = 0;
    for(int i = 1; i < N; ++i) {
        int tmp = 1001001001;
        for(int k = 1; k <= min(K, i); ++k) {
            tmp = min(tmp, dp[i-k] + abs(H[i-k] - H[i]));
        }
        dp[i] = tmp;
    }
    cout << dp[N-1] << endl;
}
