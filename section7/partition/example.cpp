include<bits/stdc++.h>
using namespace std;

#define MAX 100000
int A[MAX], n;

/**
 * パーティション：ある基準値に対して、それより小さいか大きいかで二分するアルゴリズム
*/

int partition(int p, int r) {
    int x, i, j, t;
    //右端の値を基準値に
    x = A[r];
    i = p -1;

    /**
     * ・p ~ iにx以下の要素を入れる
     * ・i+1 ~ jにxより大きい要素を入れる
     * x以下の要素が見つかると、iをインクリメントした上でA[i]とA[j]をスワップする
     * こうすることで、iを境に二つのグループに分けられる
    */
    for(j = p; j < r; j++) {
        if (A[j] <= x) {
            i++;
            t = A[i]; A[i] =  A[j]; A[j] = t;
        }
    }
    //基準値をp ~ iグルーうの一つ隣に配置することで完成
    t = A[i + 1]; A[i + 1] = A[r]; A[r] = t;
    return i + 1;
}

int main() {
    int i, q;

    scanf("%d", &n);
    for(i = 0; i < n; i++) scanf("%d", &A[i]);

    q = partition(0, n - 1);

    for(i = 0; i < n; i++) {
        if(i) printf(" ");
        if(i == q) printf("[");
        printf("%d", A[i]);
        if(i == q) printf("]");
    }
    printf("\n");
    return 0;
}