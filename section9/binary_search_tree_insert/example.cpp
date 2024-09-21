include<bits/stdc++.h>
using namespace std;
/**
 * 二分探索木：各節点がキーを持ち、任意の節点が以下の条件を満たす
 * 任意の節点xに関して、y:xの左部分木に属する節点 z:xの右部分木に属する節点　であるとして
 * y.key <= x.key && z.key >= x.key
*/

struct Node {
    int key;
    Node *right, *left, *parent;
};

Node *root, *NIL;

//keyをkとするの節点zを挿入する処理
void insert(int k) {
    Node *y = NIL;
    Node *x = root;
    Node *z;

    z = (Node *)malloc(sizeof(Node));
    z->key = k;
    z->left = NIL;
    z->right = NIL;

    //zの挿入位置を探索
    while(x != NIL) {
        y = x;
        if(z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    //whileループを抜けた時のyがzが属するべき部分木の葉であるからそれをzの親とする
    z->parent = y;
    if(y == NIL) {
        root = z;
    } else {
        //yの左右どっちに入るか
        if(z->key < y->key) {
            y->left = z;
        } else {
            y->right = z;
        }
    }
}

//中間順巡回
void inorder(Node *u) {
    if(u == NIL) return;
    inorder(u.left);
    printf("%d", u.key);
    inorder(u->right);
}

//先行順巡回
void preorder(Node *u) {
    if(u == NIL) return;
    printf("%d", u.key);
    preorder(u->left);
    preorder(u->right);
}

int main() {
    int n, i, x;
    //com: 'insert' || 'print'
    string com;

    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        cin >> com;
        if(com == 'insert') {
            scanf("%d", &x);
            insert(x);
        } else if(com == 'print') {
            inorder(root);
            printf("\n");
            inorder(root);
            printf("\n");
        }
    }

    return 0;
}

