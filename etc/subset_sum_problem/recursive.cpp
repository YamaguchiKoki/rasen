#include<bits/stdc++.h>
using namespace std;


/**
 * @brief 部分和問題を再帰で解く
 * @param arr 対象の配列
 * @param n arr[n]を選び、sum-arr[n]を求める または arr[n]を選ばず、sumを求める
 * @param sum 求める合計値
 */
bool func(vector<int> &arr, int n, int sum){
    // ベースケース: n=0かつsum=0ならtrue
    if (n == 0) {
        if(sum == 0) return true;
        else return false;
    }

    return func(arr, n-1, sum-arr[n-1]) || func(arr, n-1, sum);
}

int main() {
    int N, W;
    cin >> N >> W;
    vector<int> arr(N);
    for(int i=0; i<N; i++) cin >> arr[i];

    cout << (func(arr, N, W) ? "Yes" : "No") << endl;
    return 0;
}
