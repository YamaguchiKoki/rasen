#include<bits/stdc++.h>
using namespace std;

/**
 * 問題： https://atcoder.jp/contests/abc023/tasks/abc023_d
 *
 * 高橋君は最近、射撃にハマっている。
 * 高橋君はN 個の風船すべてを射撃で割り、得られる得点をできるだけ小さくする競技に参加している。
 * 風船には1 からN までの番号が付けられていて、風船i(1≦i≦N) は競技開始時に高度Hiのところにあり、
 * 1 秒経過するにつれて高度がSiだけ増加する。
 * 高橋君は競技開始時に1 個風船を割ることができ、そこから1 秒ごとに1 個の風船を割ることができる。どの順番で風船を割るのかは高橋君が自由に決定できる。
 * どの風船についても、その風船を割ることによるペナルティが発生する。ペナルティはその風船が割られたときの高度と等しい整数値となる。高橋君が最終的に得る得点は
 * N 個の風船のペナルティのうちの最大値となる。
 * 高橋君が得ることのできる得点として考えられる最小値を求めよ。
 */

/**
 * 方針： ペナルティの最大値をできるだけ小さくしたい→ペナルティの最大値を仮定して、それで割り切れるかを調べる→行けるならペナルティの最大値を下げる無理ならあげるを二分探索で繰り返す->最初の仮定は取りうるペナの最大値
 */
int main() {
    int N;
    cin >> N;
    vector<long long> H(N), S(N);
    for(int i = 0; i < N; i++) cin >> H[i] >> S[i];
    /**
     * @param M: ペナルティの上限→全ての風船について最後に割った時のペナルティを調べて一番でかいの
     */
    long long M = 0;
    for(int i = 0; i < N; i++) M = max(M, H[i] + S[i] * (N - 1));

    long long left = 0, right = M;

    while(right - left > 1) {
        // 仮定するペナルティの値
        long long mid = (left + right) / 2;
        // その仮定の下で全ての風船を割ることができるかどうか
        bool ok = true;
        /**
         * @param limit: 各風船について、ペナルティがmid以下になるような制限時間
         */
        vector<long long> limit(N, 0);

        for(int i = 0; i < N; i++) {
            if(mid < H[i]) {
                ok = false;
            } else {
                // mid = H[i] + S[i] * limit[i] となるようなlimit[i]を求める->limit[i]=仮定したペナルティのもとで,i番目の風船を割るための制限時間
                limit[i] = (mid - H[i]) / S[i];
            }
        }
        sort(limit.begin(), limit.end());
        // 早く破らないといけない順に調べて、仮定したペナルティのもとで全ての風船を割ることができるかどうか
        for(int i = 0; i < N; i++) {
            if(limit[i] < i) {
                ok = false;
            }
        }

        // 割れたら上限下げる
        if(ok) right = mid;
        else left = mid;
    }
    cout << right << endl;
}
