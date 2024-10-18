#include<bits/stdc++.h>
using namespace std;

/**
 * @brief フロッグ問題をDPで解く
 * @param h 各床の高さ
 * @param N 床の数
 */
int main() {
    vector<int> h;
    int N;
    cin >> N;
    h.resize(N);
    for(int i=0; i<N; i++) cin >> h[i];

    // DPテーブル
    vector<int> dp(N, 1e9);
    dp[0] = 0;

    for (int i = 1; i < N; i++) {
        if (i == 1) dp[i] = abs(h[i] - h[i - 1]);
        // i番目の足場にたどり着くための最小コストは、i-1番目の足場から来た場合とi-2番目の足場から来た場合の小さい方
        else dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    cout << dp[N - 1] << endl;
}
