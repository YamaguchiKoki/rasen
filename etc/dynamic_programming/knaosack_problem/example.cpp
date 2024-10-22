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

    // i, wをカラムにもち、各セルにはi迄の商品の中からwを超えないよう選んだ場合の価値の最大値が入る構造の二次元テーブルを想像したらわかる
    // dp[i][w]の推移のしかたは以下
    // i番目の商品を選ばない場合: 価値に変化はないのでdp[i][w] = dp[i-1][w]
    // i番目の商品を選ぶ場合:　重さがweight[i]増えるので,ひとつ前の状態=dp[i-1][w - weight[i]] これにvalue[i]を足せばいい

    // 全探索したら各商品選ぶか選ばないかでO(2^n)
    // dpテーブルを使うことでO(nW)で解ける
    for (int i = 0; i < n; i++) {
        for (int w = 0; w <= W; w++) {
            if (w >= weight[i]) {
                dp[i+1][w] = max(dp[i][w - weight[i]] + value[i], dp[i][w]);
            } else {
                dp[i+1][w] = dp[i][w];
            }
        }
    }
    cout << dp[n][W] << endl;
}
