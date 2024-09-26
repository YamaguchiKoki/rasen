include<bits/stdc++.h>
using namespace std;
#define MAX 100000

int H, A[MAX + 1];

//問題：ノード数Hと各ノードの値を受け取りmaxヒープを作る
void maxHeapify(int i) {
    int l, r, largest;
    l = 2 * i;
    r = 2 * i + 1;

    if(A[l] <= H && A[l] > A[i]) {
        largest = l;
    } else {
        largest = i;
    }

    if(A[r] <= H && A[r] > A[largest]) largest = r;

    if(largest != i) {
        swap(A[i], A[largest]);
        maxHeapify(largest);
    }
}

int main() {
    cin >> H;

    for(int i = 0; i <= H; i++) cin >> A[i];

    //完全ニ分木の場合、インデックスH/2 + 1以降のノードは子供を持たない。左の子がi * 2で求められることから明らか
    for(int i = H / 2; i >= 1; i--) maxHeapify(i);

    for(int i = 1; i <= H; i++) {
        cout << " " << A[i];
    }
    cout << endl;

    return 0;
}