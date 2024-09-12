#include<bits/stdc++.h>
using namespace std;

bool search(int n, int A[], int key) {
    int left = 0;
    int right = n - 1;
    bool flg = false;

    while (left < right) {
        int mid = (left + right) / 2;
        if (A[mid] == key) {
            flg = true;
            break;
        } else if (A[mid] > key) {
            //keyがあるとすれば左側
            right = mid;
        } else {
            //右側
            left = mid + 1;
        }
    }
    return flg;
}

int main() {
    int i, n, q, A[10000+1], key, sum = 0;

    scanf("%d", &n);
    for (i = 0; i <n; i++) scanf("%d", &A[i]);

    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        scanf("%d", &key);
        if (search(n, A, key)) sum ++;
    }

    printf("%d\n", sum);
}