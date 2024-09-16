include<bits/stdc++.h>
using namespace std;

#define MAX 2000001
#define VMAX 100000

/**
 * 計数ソート
*/

int main() {
    unsigned short *A, *B;

    int C[VMAX + 1];
    int n, i, j;
    scanf("%d", &n);

    //メモリ効率化のために動的にメモリを確保している
    //C++の場合std::vector<unsigned short> A(n + 1);の方がいい
    A = malloc(sizeof(short) * n + 1);
    B = malloc(sizeof(short) * n + 1);

    for(i = 0; i < VMAX; i++) C[i] = 0;

    for(i = 0; i < n; i++) {
        scanf("%hu", &A[i + 1]);
        C[A[i + 1]]++;
    }

    for(i = 1; i <= VMAX; i++) C[i] = C[i] + C[i - 1];

    for(j = 1; j <= n; j++) {
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }

    for(i = 1; i <= n; i++) {
        if(i > 1) printf(" ");
        printf("%d", B[i]);
    }
    printf("\n");

    return 0;
}