#include<bits/stdc++.h>
using namespace std;

/**
 * 配列Aの数字を組み合わせて、Mの要素を作れるかどうかを判別するプログラム
*/

int n, A[50];

int solve(int i, int m) {
    //ベースケース:つくれた
    if (m == 0) return 1;
    //ベースケース：つくれなかった
    if (i >= n) return 0;

    //再帰呼び出し。左側はA[i]を使わなかった場合、右側は使った場合
    int res = solve(i + 1, m) || solve(i + 1, m - A[i]);
    return res;
}

int main() {
    int q, M, i;

    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &A[i]);
    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        scanf("%d", &M);
        if(solve(0, M)) printf("yes\n");
        else printf("no\n");
    }

    return 0;
}