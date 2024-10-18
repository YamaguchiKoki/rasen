#include<bits/stdc++.h>
using namespace std;

double calc_dist(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
    int N;
    cin >> N;

    // 点が1つ以下の場合は距離が計算できない
    if (N <= 1) {
        cout << "Not enough points to calculate distance." << endl;
        return 0;
    }

    vector<double> x(N), y(N);
    for (int i = 0; i < N; i++) cin >> x[i] >> y[i];

    double min_dist = numeric_limits<double>::max();  // 初期値として最大値を使用
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            double dist_i_j = calc_dist(x[i], y[i], x[j], y[j]);

            if (dist_i_j < min_dist) {
                min_dist = dist_i_j;
            }
        }
    }
    cout.precision(6);
    cout << fixed << min_dist << endl;
}
