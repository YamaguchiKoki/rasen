// // include<bits/stdc++.h>
// #include <iostream>
// #include <vector>
// using namespace std;

// /**
//  * @brief ビット全探索の例
//  */
// int main() {
//     int N, W;
//     cin >> N >> W;
//     vector<int> a(N);
//     for (int i = 0; i < N; i++) cin >> a[i];

//     bool exist = false;
//     // 1 << N は 1をNビット左にシフトするので、2^N になる
//     for (int bit = 0; bit < (1 << N); bit++) {
//         int sum = 0;
//         for (int i = 0; i < N; i++) {
//             // bit の i 番目のフラグが立っているかどうか &はビット演算子。ビットごとの論理積をとる
//             if (bit & (1 << i)) {
//                 sum += a[i];
//             }
//         }
//         if (sum == W) {
//             exist = true;
//         }
//     }
// }
