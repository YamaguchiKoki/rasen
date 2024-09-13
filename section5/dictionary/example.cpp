#include<bits/stdc++.h>
using namespace std;

#define M 1046257
#define NIL (-1)
#define L 14

char H[M][L];

/**
 * ハッシュ法：挿入・探索・削除がＯ（１）でできる探索技法
 * 
 * 一方向性のある暗号化関数を使ってデータの格納位置を決定する
 * 格納位置について衝突が起こった際の対処法として、オープンアドレス法と、チェイン法がある
 * 以下ではオープンアドレス法の中の、ダブルハッシュを用いた衝突回避を実装している
 * 
 * オープンアドレス法：格納位置について衝突が起こった際、次の格納位置を探すために衝突が発生した格納位置から「ずらす」しかた
 * ダブルハッシュ：増分を二つ目のハッシュ関数を用いて決定する
 * 
*/

int getChar(char ch) {
    if(ch == 'A') return 1;
    else if (ch == 'C') return 2;
    else if (ch == 'G') return 3;
    else if (ch == 'T') return 4;
    else return 0;
}

long long getKey(char str[]) {
    long long sum = 0, p = 1, i;
    //getCharによる文字列→数値変換の結果を受けて、それに５の冪乗数をかけたものを足し合わせ、ハッシュキー生成の元となるキーを生成
    for (i = 0; i < strlen(str); i++) {
        sum += p*(getChar(str[i]));
        p *= 5;
    }
    return sum;
}
//オープンアドレス法におけるダブルハッシュによるキー衝突回避
int h1(int key) {return key % M;}
//増分が0にならないよう1を足す
int h2(int key) {return 1 + (key % (M - 1));}

int find(char str[]) {
    long long key, i, h;
    key = getKey(str);
    
    for (i = 0; ; i++) {
        h = (h1(key) + i * h2(key)) % M;
        if (strcmp(H[h], str) == 0) return 1;
        else if (strlen(H[h]) == 0) return 0;
    }
    return 0;
}

int insert(char str[]) {
    long long key, i, h;
    key = getKey(str);
    for(i = 0; ; i++) {
        //ハッシュ値計算　最初はi=0よりh1のみが使用される。衝突が起こった際はh2を用いて動的にステップ幅を決定
        h = (h1(key) + i * h2(key)) % M;
        //既に挿入文字列が該当インデックスに格納されていた場合、何もしない
        if (strcmp(H[h], str) == 0) return 1;
        //該当インデックスに何も格納されていない場合、挿入
        else if (strlen(H[h]) == 0) {
            strcpy(H[h], str);
            return 0;
        }
        //該当インデックスに挿入文字列とは異なる文字列が挿入されていた場合、次のループへ。ハッシュ値の再計算を行う
    }
    return 0;
}

int main() {
    int i, n, h;
    // str: 操作対象文字列 com: 命令(insert, search)
    char str[L], com[9];
    for (i = 0; i < M; i++) H[i][0] = '\0';
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s %s", com, str);

        //insert
        if (com[0] == 'i') {
            insert(str);
        } else {
            //search
            if (find(str)) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        }
    }
    return 0;
}