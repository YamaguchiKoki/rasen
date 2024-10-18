#include<bits/stdc++.h>
using namespace std;

template<class T> void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}

/**
 * @param n 今いる足場
 */
long long solve(int n, vector<int> &h, vector<int> &dp) {
    // すでに計算済みの場合はそのままリターン
    if (dp[n] < 1e9) {
        return dp[n];
    }
    // ベースケース: 足場0のコストは0
    if(n == 0) return 0;

    // 答え
    int res = 1e9;

    // 足場n-1から来た場合
    chmin(res, recursive(n-1, h, dp) + abs(h[n] - h[n-1]));

    if (n > 1) {
        // 足場n-2から来た場合
        chmin(res, recursive(n-2, h, dp) + abs(h[n] - h[n-2]));
    }
    return dp[n] = res;
}

int main() {
    int N;
    cin >> N;
    vector<int> h(N);
    for(int i=0; i<N; i++) cin >> h[i];

    vector<int> dp(N, 1e9);

    int res = solve(N -1 , h, dp);

    return 0;
}
