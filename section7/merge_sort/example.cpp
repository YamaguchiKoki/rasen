#include<bits/stdc++.h>
using namespace std;

#define MAX 500000
#define SENTINEL 2000000000

int L[MAX/2+2], R[MAX/2+2];
int cnt;

/**
 * マージソート：配列を要素数一になるまでに分割し、整列しながら統合していくアルゴリズム
 * 分割操作はlog2n, 統合操作はO(n)より全体の計算量はO(nlogn)
*/

void merge(int A[], int n, int left, int mid, int right) {
    //左半分の要素数
    int n1 = mid - left;
    //右半分の要素数
    int n2 = right -mid;

    //左半分の部分配列作成
    for(int i = 0; i < n1; i++) L[i] = A[left + i];
    //右半分の部分配列作成
    for(int i = 0; i < n2; i++) R[i] = A[mid + i];
    //番兵法により教会チェックを省略
    L[n1] = R[n2] = SENTINEL;
    int i = 0;, j = 0;
    for(int k = left; k < right; k++) {
        cnt++;
        if(L[i] <= R[j]) {
            //後置インクリメント
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
        }
    }
}

void mergeSort(int A[], int n, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(A, n, left, mid);
        mergeSort(A, n, mid, right);
        merge(A, n, left, mid, right);
    }
}

int main() {
    int A[MAX], n, i;
    cnt = 0;

    cin >> n;
    for(i = 0; i < n; i++) cin >> A[i];

    //配列はデフォルトで参照渡し
    mergeSort(A, n, 0, n);

    for(i = 0; i < n; i++) {
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << cnt << endl;

    return 0;
}