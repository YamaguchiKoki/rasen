#include<bits/stdc++.h>
using namespace std;

int n, W;
weight[110], value[110];

int dp[110][10010];

int main() {
    cin n >> W;
    for (int i=0; i<n; i++) {
        cin >> weight[i] >> value[i];
    }
    for (int w = 0; w <= W; w++) {
        dp[0][w] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int w = 0; w <= W; w++) {
            if (w >= weight[i]) {
                dp[i+1][w] = max(dp[i][w - weight[i]] + value[i], dp[i][w]);
            } else {
                dp[i+1][w] = dp[i][w];
            }
        }
    }
}
