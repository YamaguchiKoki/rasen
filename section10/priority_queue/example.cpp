include<bits/stdc++.h>
using namespace std;

#define MAX 200000
#define INFTY (1 << 30)

int H, A[MAX+1];

//i番目のノードをシフトダウン
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

int extract() {
    int maxv;
    if(H < 1) return -INFTY;
    maxv = A[1];
    //末尾ノードをルートに持っていき、ノード数を１減らす
    A[1] = A[H--];
    //heap propertyが壊れた可能性があるので、根から葉方向にシフトダウン
    maxHeapify(1);
    return maxv;
}

void increaseKey(int i, int key) {
    if(key < A[i]) return;
    A[i] = key;

    //シフトアップ
    while(i > 1 && A[i / 2] < A[i]) {
        swap(A[i], A[i / 2]);
        i = i / 2;
    }
}

void insert(int key) {
    H++:
    A[H] = -INFTY;
    increaseKey(H, key);
}

int main() {
    int key;
    char com[10];

    while(1) {
        scanf("%s", com);
        if(com[0] == 'e' && com[1] == 'n') break;
        if(com[0] == 'i') {
            scanf("%d", &key);
            insert(key);
        } else {
            printf("%d\n", extract());
        }
    }

    return 0;
}