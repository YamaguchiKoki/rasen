include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    vactor<int> v;

    cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v.push_back(x);
    }

    //第一引数にソート対象の先頭イテレータ、第二引数に末尾イテレータを渡す
    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    cout << endl;

    return 0;
}