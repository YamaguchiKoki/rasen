#include<bits/stdc++.h>
using namespace std;

/**
 * @brief メモ化用のDPテーブルを定義
 * dp[n][sum] が -1 の場合はまだ計算されていない
 * 0 なら false、1 なら true
 */
vector<vector<int>> dp;

/**
 * @brief 部分和問題をメモ化再帰で解く
 * @param arr 対象の配列
 * @param n arr[n]を選び、sum-arr[n]を求める または arr[n]を選ばず、sumを求める
 * @param sum 求める合計値
 */
bool func(vector<int> &arr, int n, int sum){
    // ベースケース: n=0かつsum=0ならtrue
    if (n == 0) {
        return sum == 0;
    }

    // すでに計算済みかどうかをチェック
    if (dp[n][sum] != -1) {
        return dp[n][sum];
    }

    // arr[n-1]を選ぶか選ばないかの2通りの選択肢
    bool res = false;

    // arr[n-1]を選ぶ場合（sumがarr[n-1]以上でないと選べない）
    if (sum >= arr[n-1]) {
        res = func(arr, n-1, sum - arr[n-1]);
    }

    // arr[n-1]を選ばない場合
    res = res || func(arr, n-1, sum);

    // 結果をメモ化
    dp[n][sum] = res;
    return res;
}

int main() {
    int N, W;
    cin >> N >> W;
    vector<int> arr(N);
    for(int i = 0; i < N; i++) cin >> arr[i];

    // dpテーブルを初期化（未計算状態を -1 とする）
    dp.resize(N + 1, vector<int>(W + 1, -1));

    cout << (func(arr, N, W) ? "Yes" : "No") << endl;
    return 0;
}

