#include<bits/stdc++.h>
using namespace std;

#define INSERT_COST 1
#define DELETE_COST 1
#define CHANGE_COST 1

int main() {
    string S, T;
    cin >> S >> T;
    int n = S.size();
    int m = T.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1));

    for(int i=0; i<=n; i++) dp[i][0] = i;

    for(int i=0; i<=m; i++) dp[0][i] = i;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            int D = dp[i-1][j] + DELETE_COST;

            int I = dp[i][j-1] + INSERT_COST;

            int C = dp[i-1][j-1] + (S[i-1] == T[j-1] ? 0 : CHANGE_COST);

            dp[i][j] = min({D, I, C});
        }
    }

    for(vector<int> x: dp) {
        for(int y: x) {
            cout << y << ", ";
        }
        cout << endl;
    }

    cout << dp[n][m] << endl;
}
