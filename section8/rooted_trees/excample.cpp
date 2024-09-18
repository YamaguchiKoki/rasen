include<bits/stdc++.h>
using namespace std;

#define MAX 100005
#define NIL -1

/**
 * 左子右兄弟表現:各接点が以下の三つの情報を持つよう設計された木構造の表現
 * １：接点uの親p
 * ２：接点uの最も左の子l
 * ３：接点uの一つ右の兄弟r
*/
struct Node { int p, l, r}

Node T[MAX];
//D:接点番号に対応したインデックスにそのノードの深さを格納
int n, D[MAX];

void print(int u) {
    int i, c;
    cout << "node " << u << ": ";
    cout << "parent " << T[u].p << ", ";
    cout << "depth " << D[u] << ", ";

    if(T[u].p == NIL) cout << "root ,";
    else if(T[u].l == NIL) cout << "leaf, ";
    else cout << "internal node, ";

    cout << "[";

    for(i = 0; c = T[u].l; c != NIL; i++, c = T[c].r) {
        if(i) cout << ", ";
        cout << c;
    }
    cout << "]" << endl;
}

int rec(int u, int p) {
    D[u] = p;
    //右の兄弟にも同じ深さを設定
    if(T[u].r != NIL) rec(T[u].r, p);
    //最も左の子には自分の深さ+1を設定
    if(T[u].l != NIL) rec(T[u].l, p + 1);
}

int main() {
    int i, j, d, v, c, l, r;
    //接点の個数
    cin >> n;
    //NIL埋め
    for(i = 0; i < n; i++)T[i].p = T[i].l = T[i].r = NIL;

    
    for(i = 0; i < n; i++) {
        //v:接点番号, d:次数
        cin >> v >> d;
        for(j = 0; j < d; j++) {
            //c:子供(d個)
            cin >> c;
            //最初のループで左に格納
            if (j == 0) T[v].l = c;
            //以降のループでは右隣に格納
            else T[l].r = c;
            //階層はそのままで、右に向かって次数回分埋めていきたいから、lの値を直前のcで更新
            l = c;
            //子供の親を自分に
            T[c].p = v;
        }
    }
    for(i = 0; i < n; i++) {
        //ルートノードの接点番号を格納
        if(T[i].p == NIL) r = i;
    }

    rec(r, 0);

    for(i = 0; i < n; i++) print(i);

    return 0;
}