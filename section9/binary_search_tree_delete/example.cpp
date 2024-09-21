include<bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *right. *left, *parent;
};

Node *root, *NIL;

//xを始点とする部分木の最小ノードを返す
Node * treeMinimum(Node *x) {
    while (x->left != NIL) x = x->left;
    return x;
}

Node * find(Node *u, int k) {
    while (u != NIL && k != u->key) {
        if(u.key > k) {
            u = u->left;
        } else {
            u = u->right;
        }
    }
    return u;
}

//xの次に大きいノード（successor）を返す
//右部分木がある場合：その部分木の中の最小ノードを返す
//右部分木がない場合：successorは祖先ノードに存在する。xがその親ノードの左部分木に属する限り遡って探索。根までいくか、その親ノードの右部分木である時点でのノードを返す
Node * treeSuccessor(Node *x) {
    //xに右部分木が存在する場合、その中の最小ノード
    if(x->right != NIL) return treeMinimum(x->right);
    Node *y = x->parent;

    //xより大きいノードは祖先に存在するから根の方向に遡って探索
    while(y != NIL && x == y->right) {
        x = y;
        y = y->parent;
    }

    return y;
}

//TODO:ここから
void treeDelete(Node *z) {
    //削除対象ノード
    Node *y;
    //削除対象の子ノード。削除処理後yの親ノードに接続される
    Node *x;

    if(z->left == NIL || z->right == NIL) y = z;
    else y = treeSuccessor(z);

    if(y->left != NIL) {
        x = y->left;
    } else {
        x = y->right;
    }

    if(x != NIL) {
        x->parent = y->parent;
    }

    if(y->parent == NIL) {
        root = x;
    } else {
        if(y == y->parent->left) {
            y->parent->left = x;
        } else {
            y->parent->right = x;
        }
    }

    if(y != z) {
        z->key = y->key;
    }

    free(y);
}

